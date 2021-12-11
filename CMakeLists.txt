cmake_minimum_required(VERSION 3.0.0)
project(copycontrol VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 14)

add_executable(game Main.cpp StdRoom.cpp MgcRoom.cpp Building.cpp LckRoom.cpp Room.cpp Player.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
