cmake_minimum_required(VERSION 3.16)

project(QTCalculator LANGUAGES C CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(QTCalculator
  src/main.cpp
  src/headers/main_window.h
  src/headers/calculator_panel.h
  src/sources/calculator_panel.cpp
  src/sources/main_window.cpp
  src/headers/round_button.h
  src/sources/round_button.cpp
  res.qrc
  src/headers/button_info.h
  src/headers/screen_panel.h
  src/sources/screen_panel.cpp
  src/sources/button_info.cpp
  src/headers/tinyexpr.h
  src/sources/tinyexpr.c
)
target_link_libraries(QTCalculator PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Widgets
)
target_link_libraries(QTCalculator PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# 可选：明确 tinyexpr.c 按 C 编译（避免 CMake 误判）
set_source_files_properties(src/sources/tinyexpr.c PROPERTIES LANGUAGE C)

include(GNUInstallDirs)
install(TARGETS QTCalculator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
