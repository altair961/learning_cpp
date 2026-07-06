cmake_minimum_required(VERSION 3.5)

project(ch3_tt1_currency_converter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch3_tt1_currency_converter main.cpp)

include(GNUInstallDirs)
install(TARGETS ch3_tt1_currency_converter
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
