cmake_minimum_required(VERSION 3.1.0)

project(wol-qt)

add_subdirectory(linet)

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
               src/wol.h
               src/history.cpp
               src/ArpWorker.cpp
               src/customArpTable.cpp
               src/TextAlteringButton.cpp
               )

add_executable(wol
               src/cli.main.c
               )

target_include_directories(wol-qt
                           PRIVATE
                           ui src)

target_link_libraries(wol-qt Qt5::Widgets linet pthread)
target_link_libraries(wol linet)

add_subdirectory(tests)

install(TARGETS wol
        RUNTIME DESTINATION /usr/bin)
install(TARGETS wol-qt
        RUNTIME DESTINATION /usr/bin)