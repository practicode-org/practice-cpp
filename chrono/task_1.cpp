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
#include <numeric>
#include <ratio>
#include <thread>
#include <cmath>
#include <future>

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
                       MeasureUnits& average,
                       MeasureUnits& mean,
                       MeasureUnits& frequent)
        : minDuration(min),
          maxDuration(max),
          averageDuration(average),
          meanDuration(mean),
          frequentDuration(frequent) {}

    template <typename Duration>
    void dump(std::ostream& os = std::cout) const {
        constexpr char* suffix = []() constexpr {
            constexpr char* secondsSuffix = "s\0";
            constexpr char* microSuffix = "ms\0";
            constexpr char* nanoSuffix = "ns\0";
            constexpr char* milliSuffix = "mcs\0";
            constexpr char* emptySuffix = "\0";

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
        }
        ();

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
    bool enableMin;
    bool enableMax;
    bool enableAverage;
    bool enableMean;
    bool enableFrequent;

    BenchmarkParams() = default;
    explicit BenchmarkParams(int32_t count,
                             bool min = false,
                             bool max = false,
                             bool average = false,
                             bool mean = false,
                             bool frequent = false)
        : executionsCount(count),
          enableMin(min),
          enableMax(max),
          enableAverage(average),
          enableMean(mean),
          enableFrequent(frequent) {}
};

template <typename Func>
class FunctionBenchmark {
public:
    explicit FunctionBenchmark(Func&& exec) : m_exec(exec) {}

    void setExec(Func&& exec) { m_exec = std::move(exec); }

    [[nodiscard]] Func exec() const { return m_exec; }

    [[nodiscard]] ExecutionStatistic run(const BenchmarkParams& param = BenchmarkParams()) const {
        const auto sample = generateSample(param.executionsCount);

        auto minMeasurement = param.enableMin ? minSample(sample) : MeasureUnits();
        auto maxMeasurement = param.enableMax ? maxSample(sample) : MeasureUnits();
        MeasureUnits average = param.enableAverage ? averageSample(sample) : MeasureUnits();
        MeasureUnits mean = param.enableMean ? meanSample(sample) : MeasureUnits();
        MeasureUnits frequent = param.enableFrequent ? frequentSample(sample) : MeasureUnits();

        ExecutionStatistic statistic(minMeasurement, maxMeasurement, average, mean, frequent);
        return statistic;
    }

private:
    [[nodiscard]] MeasureUnits frequentSample(const std::vector<MeasureUnits>& sample) const { return MeasureUnits(); }

    [[nodiscard]] MeasureUnits meanSample(const std::vector<MeasureUnits>& sample) const
    {
        const auto average = averageSample(sample);

        double sampleSum = 0.0;
        for (auto& val : sample)
        {
            sampleSum += std::pow(val.count() - average.count(), 2);
        }
        MeasureUnits mean = MeasureUnits(std::sqrt(sampleSum / static_cast<double>(sample.size())));

        return mean;
    }

    [[nodiscard]] MeasureUnits averageSample(const std::vector<MeasureUnits>& sample) const {
        MeasureUnits accumulator{};
        for (auto& val : sample) {
            accumulator += val;
        }
        return accumulator / sample.size();
    }

    [[nodiscard]] MeasureUnits minSample(const std::vector<MeasureUnits>& sample) const {
        return *std::min_element(sample.begin(), sample.end());
    }

    [[nodiscard]] MeasureUnits maxSample(const std::vector<MeasureUnits>& sample) const {
        return *std::max_element(sample.begin(), sample.end());
    }

    [[nodiscard]] std::vector<MeasureUnits> generateSample(int32_t sampleSize) const {
        std::vector<MeasureUnits> sample(sampleSize);
        for (int64_t sampleIndex = 0; sampleIndex < sampleSize; ++sampleIndex) {
            sample.at(sampleIndex) = std::move(measureExecution(m_exec));
        }
        return std::move(sample);
    }

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
    BenchmarkParams params(callCount, true, true, true, true, true);

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
