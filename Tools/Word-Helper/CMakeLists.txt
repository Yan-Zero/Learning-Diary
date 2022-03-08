cmake_minimum_required(VERSION 3.0.0)
project(WordHelper VERSION 0.1.0)

include(CTest)
enable_testing()

set(
  SOURCES
    src/main.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

# target_include_directories(${PROJECT_NAME}
#   PRIVATE 
#     ${PROJECT_SOURCE_DIR}/include
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

execute_process(
  COMMAND copy "${EXECUTABLE_OUTPUT_PATH}/{PROJECT_NAME}.exe" "${PROJECT_SOURCE_DIR}/../{PROJECT_NAME}.exe"
)