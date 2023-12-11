find_package(Boost COMPONENTS program_options REQUIRED)

add_library(
    utils
    STATIC
    ArgParse.cpp
    StringUtils.cpp
    )

target_include_directories(
    utils
    PUBLIC
    "${PROJECT_SOURCE_DIR}/utils/include"
    Boost
    )

target_link_libraries(
    utils
    PUBLIC
    Boost::program_options
    )
