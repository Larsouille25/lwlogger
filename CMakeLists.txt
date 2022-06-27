cmake_minimum_required(VERSION 3.0.0)

#Config the project
project(lwlogger VERSION 1.1.0)
set(LIBRARY_OUTPUT_PATH lib/${CMAKE_BUILD_TYPE})


include_directories(include)

#Add sources to the source_files var
file(
        GLOB_RECURSE
        source_files
        src/*
        include/*
)


add_library(
        lwlogger
        SHARED
        ${source_files}
)

