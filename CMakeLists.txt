cmake_minimum_required(VERSION 3.16.3)
project(cpp_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(ft_vector)

add_executable(cpp_containers
        ft_vector/ft_algorithm.hpp
        ft_vector/ft_iterator_utils.hpp
        ft_vector/ft_type_traits.hpp
        ft_vector/ft_vector.hpp
        ft_vector/ft_vector_iterator.hpp
        ft_vector/ft_vector_reverse_iterator.hpp
        main.cpp)
