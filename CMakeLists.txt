cmake_minimum_required(VERSION 4.0)
project(Todolistesamebyzine)

set(CMAKE_CXX_STANDARD 14)
include(FetchContent)


FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Abilita il testing
enable_testing()


add_executable(Todolistesamebyzine
        Attivita.cpp
        Attivita.h
        Lista.cpp
        Lista.h
        main.cpp

)
add_executable(run_tests
        test_lista.cpp
        test_attivita.cpp
        Lista.cpp
        Attivita.cpp

)

# Collega la libreria core E la libreria di Google Test
target_link_libraries(run_tests PRIVATE
        GTest::gtest_main
)

# Integrazione con CTest
include(GoogleTest)
gtest_discover_tests(run_tests)