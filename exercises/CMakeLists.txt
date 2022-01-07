cmake_minimum_required(VERSION 3.19)
project(practicode-cpp)

add_executable(condition_variable_1 condition_variable/task_1.cpp)

add_executable(condition_variable_2 condition_variable/task_2.cpp)

add_executable(condition_variable_3 condition_variable/task_3.cpp)

add_executable(condition_variable_4 condition_variable/task_4.cpp)

if(UNIX)
  target_link_libraries(condition_variable_1 PUBLIC pthread)
  target_link_libraries(condition_variable_2 PUBLIC pthread)
  target_link_libraries(condition_variable_3 PUBLIC pthread)
  target_link_libraries(condition_variable_4 PUBLIC pthread)
endif()
