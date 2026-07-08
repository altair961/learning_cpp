cmake_minimum_required(VERSION 3.5)

project(ch3_dr4_language_features LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch3_dr4_language_features main.cpp)

include(GNUInstallDirs)
install(TARGETS ch3_dr4_language_features
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
