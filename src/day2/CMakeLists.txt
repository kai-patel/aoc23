find_package(Boost COMPONENTS algorithm REQUIRED)

add_executable(
    day2
    main.cpp
    )

target_include_directories(
    day2
    PRIVATE
    "${PROJECT_SOURCE_DIR}/utils/include"
    Boost
    )

target_link_libraries(
    day2
    PRIVATE
    utils
    )
