cmake_minimum_required(VERSION 3.1.0)

project(wol-qt)

#add_subdirectory(linet-master)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(wol-qt
  src/main.cpp
  src/mainwindow.cpp
  src/mainwindow.h
  src/mainwindow.ui
  src/wol.cpp
  src/WOL_Gui.pro
  src/wol.h
)

target_include_directories(wol-qt
                           PRIVATE
                           ui)

target_link_libraries(wol-qt Qt5::Widgets linet)
