add_executable(add_two_numbers main.cpp)

set_property(TARGET add_two_numbers PROPERTY CXX_STANDARD 23)

target_link_libraries(add_two_numbers PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(add_two_numbers)
