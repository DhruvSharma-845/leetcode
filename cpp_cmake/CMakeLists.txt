add_executable(leetcode_ut 
    tests/hello_test.cpp
    tests/valid_parentheses.cpp
    tests/partition_array_three_parts_equal_sum.cpp
)
target_include_directories(leetcode_ut PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(
    leetcode_ut
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(leetcode_ut)