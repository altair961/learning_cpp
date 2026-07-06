cmake_minimum_required(VERSION 3.5)

project(ch3_tt2_currency_converter_switch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch3_tt2_currency_converter_switch main.cpp)

include(GNUInstallDirs)
install(TARGETS ch3_tt2_currency_converter_switch
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
