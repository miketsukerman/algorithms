add_executable(add_two_numbers main.cpp)

target_compile_features(add_two_numbers PRIVATE cxx_std_23)

target_link_libraries(add_two_numbers PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(add_two_numbers)
