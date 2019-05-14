cmake_minimum_required(VERSION 3.2.0)
project(AutomatedMovements_Tests)

set(SKETCH_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(SOURCE_DIR ${SKETCH_ROOT}/automatedMovements)
set(TEST_DIR ${SKETCH_ROOT}/test)
set(UT_DIR ${TEST_DIR}/ut)
set(MOCKS_DIR ${TEST_DIR}/mocks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
    -std=c++17 \
    -Wcast-align \
    -pedantic \
    -Wcast-qual \
    -Wconversion \
    -Wdisabled-optimization \
    -Winit-self \
    -Wnon-virtual-dtor \
    -Wold-style-cast \
    -Woverloaded-virtual \
    -Wparentheses \
    -Wredundant-decls \
    -Wshadow \
    -Wsign-promo \
    -Wstrict-aliasing \
    -Wall \
    -Wextra \
    -Werror \
    -pthread \
")

# Download and unpack googletest at configure time
configure_file(test_libs/CMakeLists.txt googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
include_directories("${gtest_SOURCE_DIR}/include"
    "${gmock_SOURCE_DIR}/include")

enable_testing()

# Utility functions
function(configure_test testExecutable)
    # Link against gtest library
    target_link_libraries(${testExecutable} gtest gmock_main)
    # Create test name as the capitalized form of the test executable
    string(TOUPPER ${testExecutable} testName)
    # Add executable to test suite
    add_test(${testName} ${testExecutable} ${GTEST_RUN_FLAGS})
endfunction(configure_test)

# Automated Movement Unit Tests
add_executable(automated_movement_test
    ${UT_DIR}/automatedMovements_test.cpp
)
target_include_directories(automated_movement_test PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/test_libs/gmock-gtest
    ${MOCKS_DIR}
)
configure_test(automated_movement_test)