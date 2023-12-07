add_executable(
    day1
    main.cpp
    )

target_include_directories(
    day1
    PRIVATE
    "${PROJECT_SOURCE_DIR}/utils/include"
    )

target_link_libraries(
    day1
    PRIVATE
    utils
    )
