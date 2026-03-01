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
  src/headers/widget/calculator_panel.h
  src/sources/widget/calculator_panel.cpp
  src/sources/main_window.cpp
  src/headers/widget/round_button.h
  src/sources/widget/round_button.cpp
  res.qrc
  src/headers/info/button_info.h
  src/headers/widget/screen_panel.h
  src/sources/widget/screen_panel.cpp
  src/sources/info/button_info.cpp
  src/headers/core/tinyexpr.h
  src/sources/core/tinyexpr.c
  src/headers/info/expression_info.h
  src/sources/info/expression_info.cpp
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
