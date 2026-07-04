cmake_minimum_required(VERSION 3.5)

project(ch2_ex9_text_to_digit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch2_ex9_text_to_digit main.cpp)

include(GNUInstallDirs)
install(TARGETS ch2_ex9_text_to_digit
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
