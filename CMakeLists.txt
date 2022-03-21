cmake_minimum_required(VERSION 3.21)
project(SnakeGTK VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES main.cpp src/App.cpp include/App.h src/MainMenu.cpp include/MainMenu.h src/MainProcess.cpp include/MainProcess.h src/Game.cpp include/Game.h src/Grid.cpp include/Grid.h src/Tile.cpp include/Tile.h src/Snake.cpp include/Snake.h src/SnakeTile.cpp include/SnakeTile.h include/Direction.h src/SnakeBase.cpp include/SnakeBase.h)
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

