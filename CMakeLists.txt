cmake_minimum_required(VERSION 3.21)
project(SnakeGTK VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp src/App.cpp src/App.h src/MainMenu.cpp src/MainMenu.h src/MainProcess.cpp src/MainProcess.h src/Game.cpp src/Game.h src/Grid.cpp src/Grid.h src/Tile.cpp src/Tile.h src/Snake.cpp src/Snake.h src/SnakeTile.cpp src/SnakeTile.h src/Direction.h src/SnakeBase.cpp src/SnakeBase.h src/Coordinates.h src/BaseGrid.h src/BaseGrid.cpp src/BaseGrid.cpp src/BaseGrid.h src/Apple.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


target_include_directories(${PROJECT_NAME} PRIVATE
        include
        )
#set(CMAKE_CXX_COMPILER g++)

find_package(PkgConfig)
pkg_check_modules(GTKMM IMPORTED_TARGET gtkmm-3.0)



include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC PkgConfig::GTKMM)

