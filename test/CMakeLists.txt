add_executable(test_template testrunner.cpp)
target_sources(test_template
    PRIVATE
        test1.cpp
)

target_link_libraries(test_template PRIVATE template::template Catch2::Catch2)

include(Catch)
catch_discover_tests(test_template)
