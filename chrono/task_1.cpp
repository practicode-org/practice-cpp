/*
Task:
- call the `func` function 10000 times, record function runtime durations, and find minimum, maximum, average, mean,
90-th percentile duration.
- print it in microseconds and nanoseconds.

plus: print floating point number of seconds and milliseconds.
*/
#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <ratio>
#include <unordered_map>

using namespace std::chrono_literals;
using secondsF = std::chrono::duration<double, std::ratio<1>>;
using microsecondsF = std::chrono::duration<double, std::micro>;
using millisecondsF = std::chrono::duration<double, std::milli>;
using nanosecondsF = std::chrono::duration<double, std::nano>;

using MeasureUnits = nanosecondsF;

void func() {
    // do not change body of the function
    std::this_thread::sleep_for(0.5ms);
}

struct ExecutionStatistic {
    MeasureUnits minDuration;
    MeasureUnits maxDuration;
    MeasureUnits averageDuration;
    MeasureUnits meanDuration;
    MeasureUnits frequentDuration;

    ExecutionStatistic() : minDuration{}, maxDuration{}, averageDuration{}, meanDuration{}, frequentDuration{} {}

    ExecutionStatistic(MeasureUnits& min,
                       MeasureUnits& max,
                       MeasureUnits & average,
                       MeasureUnits & mean,
                       MeasureUnits & frequent)
        : minDuration(min),
          maxDuration(max),
          averageDuration(average),
          meanDuration(mean),
          frequentDuration(frequent) {}

    template <typename Duration>
    void dump(std::ostream& os = std::cout) const {
        constexpr char * suffix = []() constexpr {
            constexpr char * secondsSuffix = "s\0";
            constexpr char * microSuffix = "ms\0";
            constexpr char * nanoSuffix = "ns\0";
            constexpr char * milliSuffix = "mcs\0";
            constexpr char * emptySuffix = "\0";

            if constexpr (std::is_same_v<typename Duration::period, std::ratio<1>>) {
                return secondsSuffix;
            } else if (std::is_same_v<typename Duration::period, std::micro>) {
                return microSuffix;
            } else if (std::is_same_v<typename Duration::period, std::nano>) {
                return nanoSuffix;
            } else if (std::is_same_v<typename Duration::period, std::milli>) {
                return milliSuffix;
            } else {
                return emptySuffix;
            }
        }();

        os << "Min duration: " << std::chrono::duration_cast<Duration>(minDuration).count() << suffix << std::endl;
        os << "Max duration: " << std::chrono::duration_cast<Duration>(maxDuration).count() << suffix << std::endl;
        os << "Average duration: " << std::chrono::duration_cast<Duration>(averageDuration).count() << suffix
           << std::endl;
        os << "Mean duration: " << std::chrono::duration_cast<Duration>(meanDuration).count() << suffix << std::endl;
        os << "Frequent duration: " << std::chrono::duration_cast<Duration>(frequentDuration).count() << suffix
           << std::endl;
    }
};

struct BenchmarkParams {
    int32_t executionsCount;

    BenchmarkParams() : executionsCount(0) {}
    explicit BenchmarkParams(int32_t count) : executionsCount(count) {}
};

template <typename Func>
class FunctionBenchmark {
public:
    explicit FunctionBenchmark(Func&& exec) : m_exec(exec) {}

    void setExec(Func&& exec) { m_exec = std::move(exec); }

    [[nodiscard]] Func exec() const { return m_exec; }

    [[nodiscard]] ExecutionStatistic run(const BenchmarkParams& param = BenchmarkParams()) const {
        const int32_t executionsCount = param.executionsCount;

        auto minMeasurement = MeasureUnits::max();
        auto maxMeasurement = MeasureUnits::min();
        MeasureUnits measurementsSum = {};
        MeasureUnits average = {};
        MeasureUnits mean = {};
        MeasureUnits frequent = {};

        for (int64_t executionIndex = 0; executionIndex < executionsCount; ++executionIndex) {
            const auto sample = measureExecution(m_exec);

            if (sample < minMeasurement) {
                minMeasurement = sample;
            }

            if (sample > maxMeasurement) {
                maxMeasurement = sample;
            }

            measurementsSum += sample;
        }

        average = measurementsSum / executionsCount;

        ExecutionStatistic statistic(minMeasurement, maxMeasurement, average, mean, frequent);
        return statistic;
    }

private:

    MeasureUnits measureExecution(const Func& exec) const {
        const auto executionStart = std::chrono::system_clock::now();
        std::invoke(exec);
        const auto executionEnd = std::chrono::system_clock::now();
        return std::chrono::duration_cast<MeasureUnits>(executionEnd - executionStart);
    }

    Func m_exec;
};

int main() {
    FunctionBenchmark<std::function<void()>> benchmark(func);

    constexpr int32_t callCount = 10000;
    BenchmarkParams params(callCount);

    const auto benchmarkStatistic = benchmark.run(params);

    std::cout << "##################" << std::endl;
    benchmarkStatistic.dump<nanosecondsF>();
    std::cout << "##################" << std::endl;
    benchmarkStatistic.dump<microsecondsF>();
    std::cout << "##################" << std::endl;
    benchmarkStatistic.dump<millisecondsF>();
    std::cout << "##################" << std::endl;
    std::cout << "##################" << std::endl;
    benchmarkStatistic.dump<secondsF>();
    std::cout << "##################" << std::endl;

    return 0;
}
