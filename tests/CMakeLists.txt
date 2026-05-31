add_executable(test_suite
    test_suite.cpp
)

# Ensure tests can include project headers
target_include_directories(test_suite PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(test_suite PRIVATE utils)

add_test(NAME unit_tests COMMAND test_suite)
