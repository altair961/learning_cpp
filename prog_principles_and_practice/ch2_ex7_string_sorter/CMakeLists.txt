cmake_minimum_required(VERSION 3.5)

project(ch2_ex7_string_sorter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch2_ex7_string_sorter main.cpp)

include(GNUInstallDirs)
install(TARGETS ch2_ex7_string_sorter
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
