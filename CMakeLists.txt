cmake_minimum_required(VERSION 3.16.3)
project(cpp_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(ft_vector)

add_executable(cpp_containers
        ft_tester/tester_headers.hpp
        ft_tester/tester_stack.cpp
        ft_tester/tester_vector.cpp
        ft_tester/tester_map.cpp
        ft_tester/tester_set.cpp

        ft_vector/ft_algorithm.hpp
        ft_vector/ft_iterator_utils.hpp
        ft_vector/ft_type_traits.hpp
        ft_vector/ft_vector.hpp
        ft_vector/ft_vector_iterator.hpp
        ft_vector/ft_vector_reverse_iterator.hpp

        ft_stack/ft_stack.hpp

        ft_map/ft_bidirectional_iterator.hpp
        ft_map/ft_rev_bidir_iter.hpp
        ft_map/ft_less.hpp
        ft_map/ft_map.hpp
        ft_map/ft_pair.hpp
        ft_map/ft_node.hpp

        ft_set/ft_set.hpp
        ft_set/ft_set_iterator.hpp

        main.cpp)
