cmake_minimum_required(VERSION 3.5)

project(ch5_dr6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch5_dr6 main.cpp)

include(GNUInstallDirs)
install(TARGETS ch5_dr6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
