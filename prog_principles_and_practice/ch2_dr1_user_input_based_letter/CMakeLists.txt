cmake_minimum_required(VERSION 3.5)

project(ch2_dr1_user_input_based_letter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch2_dr1_user_input_based_letter main.cpp)

include(GNUInstallDirs)
install(TARGETS ch2_dr1_user_input_based_letter
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
