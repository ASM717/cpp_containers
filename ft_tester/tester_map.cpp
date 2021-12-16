#include "../ft_tester/tester_headers.hpp"

void map_all_test() {
    std::map<std::string, int> std_map;
    std_map["Morpheus"] = 1;
    std_map["Neo"] = 777;
    std_map["Agent Smith"] = 21;
    std_map["Triniti"] = 77;
    std_map["Niobe"] = 0;

    ft::map<std::string, int> ft_map;
    ft_map["Morpheus"] = 1;
    ft_map["Neo"] = 777;
    ft_map["Agent Smith"] = 21;
    ft_map["Triniti"] = 77;
    ft_map["Niobe"] = 0;

    std::cout << "ft:  " << (*ft_map.begin()).first << " " << (*ft_map.begin()).second  << std::endl; 
    std::cout << "std: " << (*std_map.begin()).first << " " <<  (*std_map.begin()).second << std::endl;

    std::cout << "ft:  " << (*(--ft_map.end())).first << " " << (*(--ft_map.end())).second  << std::endl; 
    std::cout << "std: " << (*(--std_map.end())).first << " " << (*(--std_map.end())).second << std::endl;


}