cmake_minimum_required(VERSION 3.0.0)
project(Remember-Helper VERSION 0.1.0)

include(CTest)
enable_testing()

set(LIBS_DIRS "${PROJECT_SOURCE_DIR}/../../Libs")

set(
  SOURCES
    src/main.cpp
    src/context.cpp
    src/http_and_mp3.cpp
    src/push_system_toast.cpp
    src/push_system_cli.cpp
    src/wintoastlib.cpp
)

# if you want to use the cli, you delete the following line
# add_definitions(-D_USE_TOAST)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(
  ${LIBS_DIRS}/include
  ${PROJECT_SOURCE_DIR}/include
)

find_library(dy_lib yaml-cpp.lib ${LIBS_DIRS}/MSVC)

target_link_libraries(${PROJECT_NAME} ${dy_lib})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

