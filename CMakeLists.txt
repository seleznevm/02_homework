cmake_minimum_required(VERSION 3.10)
project(ip_filter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ip_filter ip_filter.cpp)

# install target for release packaging
install(TARGETS ip_filter DESTINATION bin)
install(FILES ip_filter.tsv DESTINATION share/ip_filter)
