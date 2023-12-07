find_package(Boost COMPONENTS program_options REQUIRED)

add_library(
    utils
    STATIC
    ArgParse.cpp
    )

target_include_directories(
    utils
    PUBLIC
    Boost
    )

target_link_libraries(
    utils
    PUBLIC
    Boost::program_options
    )
