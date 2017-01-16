find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(.)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Test/UnitTests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/midi)
aux_source_directory(Util TEST_SRC_LIST)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Weffc++")
endif()

include(CTest)
enable_testing()
foreach(TEST ${TEST_SRC_LIST})
  get_filename_component(TEST_NAME ${TEST} NAME_WE)
  get_filename_component(TEST_DIR ${TEST} DIRECTORY)
  string(REGEX REPLACE "/" "_" TEST_DIR ${TEST_DIR})
  set(TEST_UNIQUE_NAME "${TEST_DIR}_${TEST_NAME}")
  add_executable(${TEST_UNIQUE_NAME} ${TEST})
  target_link_libraries(${TEST_UNIQUE_NAME} ${GTEST_LIBRARIES} pthread)
  add_test(${TEST_UNIQUE_NAME} ${PROJECT_BINARY_DIR}/Tests/UnitTests/${TEST_UNIQUE_NAME})
endforeach()

