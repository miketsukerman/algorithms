add_executable(add_binary add-binary.cpp)

target_compile_features(add_binary PRIVATE cxx_std_23)

target_link_libraries(add_binary PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(add_binary)
