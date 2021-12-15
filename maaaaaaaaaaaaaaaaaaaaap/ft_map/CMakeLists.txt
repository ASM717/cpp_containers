cmake_minimum_required(VERSION 3.16)
project(ft_map)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ft_map
        ft_map.hpp
        ft_pair.hpp
        ft_bidirectional_iterator.hpp
        map.cpp)
