cmake_minimum_required(VERSION 3.19)
project(practicode-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Test framework
add_subdirectory(thirdparty/googletest)

# Concurrency, condition_variable
add_executable(condition_variable_1 condition_variable/task_1.cpp)

add_executable(condition_variable_2 condition_variable/task_2.cpp)

add_executable(condition_variable_3 condition_variable/task_3.cpp)

add_executable(condition_variable_4 condition_variable/task_4.cpp)

# Algorithms, sorting
add_executable(sorting_1 sorting/task_1.cpp)

add_executable(sorting_2 sorting/task_2.cpp)

add_executable(sorting_3 sorting/task_3.cpp)

# Chrono library
add_executable(chrono_1 chrono/task_1.cpp)

# Dependencies setup
set(TARGETS
      condition_variable_1
      condition_variable_2
      condition_variable_3
      condition_variable_4
      sorting_1
      sorting_2
      sorting_3
      chrono_1
)

foreach(TARGET ${TARGETS})
  target_link_libraries(${TARGET} PUBLIC gtest)
endforeach()

if(UNIX)
  foreach(TARGET ${TARGETS})
    target_link_libraries(${TARGET} PUBLIC pthread)
  endforeach()
endif()
