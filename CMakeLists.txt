cmake_minimum_required(VERSION 3.20)
project(sfml_test)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML REQUIRED system window graphics)


add_executable(sfml_test main.cpp src/Game.cpp src/Game.h src/Vec.cpp src/Vec.h src/Ball.cpp src/Ball.h src/Polygon.cpp src/Polygon.h)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window)
