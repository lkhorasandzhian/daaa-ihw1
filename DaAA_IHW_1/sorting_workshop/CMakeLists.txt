cmake_minimum_required(VERSION 3.24)
project(sorting_workshop)

set(CMAKE_CXX_STANDARD 17)

add_executable(sorting_workshop
        main.cpp
        library/sorting_algorithms.cpp
        library/sorting_algorithms.h
        library/test.cpp
        library/test.h
        library/array_generator.cpp
        library/array_generator.h
        library/result_file_recorder.cpp
        library/result_file_recorder.h
        library/elementary_counter.cpp
        library/elementary_counter.h
        )
