#!/bin/bash
SCRIPT_DIR=$(dirname "$0")
source "${SCRIPT_DIR}/../bin/activate"
cmake --build "${SCRIPT_DIR}/../build" "$@"
