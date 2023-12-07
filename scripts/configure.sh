#!/bin/bash

set -x
SCRIPT_DIR=$(dirname "$0")
source "${SCRIPT_DIR}/../bin/activate"

mkdir -p "${SCRIPT_DIR}/../build"
conan install . --output-folder="${SCRIPT_DIR}/../build" --build=missing
cmake -S "${SCRIPT_DIR}/.." -B "${SCRIPT_DIR}/../build" -DCMAKE_TOOLCHAIN_FILE="${SCRIPT_DIR}/../build/conan_toolchain.cmake" -G "Ninja" -D CMAKE_CXX_COMPILER="/usr/bin/clang++" -DCMAKE_BUILD_TYPE=Release "$@"
