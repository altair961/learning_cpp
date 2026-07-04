cmake_minimum_required(VERSION 3.5)

project(ch2_ex8_odd_or_even LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ch2_ex8_odd_or_even main.cpp)

include(GNUInstallDirs)
install(TARGETS ch2_ex8_odd_or_even
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
