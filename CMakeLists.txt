cmake_minimum_required(VERSION 3.16)

project(Reloj VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 6.2 COMPONENTS Quick Widgets REQUIRED)

qt_standard_project_setup()

qt_add_executable(appReloj
    main.cpp
    src/backend.cpp
)

qt_add_qml_module(appReloj
    URI Reloj
    VERSION 1.0
    QML_FILES qml/main.qml
)

target_link_libraries(appReloj
    PRIVATE Qt6::Quick Qt6::Widgets
)
