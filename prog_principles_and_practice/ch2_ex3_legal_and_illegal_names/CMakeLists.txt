cmake_minimum_required(VERSION 3.5)

project(ch2_ex3_legal_and_illegal_names LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch2_ex3_legal_and_illegal_names main.cpp)

include(GNUInstallDirs)
install(TARGETS ch2_ex3_legal_and_illegal_names
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
