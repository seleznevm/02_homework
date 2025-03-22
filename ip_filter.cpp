#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <algorithm>

using IPAddress = std::array<int,  4>;

std::vector<std::string> split(const std::string &str, char delimenter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while(std::getline(ss, token, delimenter)){
        tokens.push_back(token);
    }
    return tokens;
}

IPAddress parse_ip(const std::string& ip_str){
    IPAddress ip{};
    auto parts = split(ip_str, '.');
    for(size_t i=0; i < 4; i++){
        ip[i] = stoi(parts[i]);
    }
    return ip;
}

void print_ip(const IPAddress& ip){
    std::cout << ip[0] << '.' << ip[1] << '.' << ip[2] << '.' << ip[3] << '\n';
}

std::vector<IPAddress> load_ips(const std::string& filename){
    std::vector<IPAddress> ip_pool;
    std::ifstream file(filename);
    std::string line;
    while(std::getline(file, line)){
        auto fields = split(line, '\t');
        ip_pool.push_back(parse_ip(fields[0]));
    }
    return ip_pool;
}

int main(){
    try
    {
        auto ip_pool = load_ips("ip_filter.tsv");
        std::sort(ip_pool.begin(), ip_pool.end(), std::greater<>());

        for(const auto& ip: ip_pool) print_ip(ip);

        std::cout << "Filter by ip[0] == 1" << std::endl;
        for(const auto& ip: ip_pool) {
            if (ip[0] == 1) print_ip(ip);
        }

        std::cout << "Filter by ip[0] == 46 && ip[1] == 70" << std::endl;
        for (const auto& ip: ip_pool) {
            if (ip[0] == 46 && ip[1] == 70) print_ip(ip);
        }

        std::cout << "Filter by any block == 46" << std::endl;
        for (const auto& ip: ip_pool){
            if (std::any_of(ip.begin(), ip.end(), [](int b) {return b == 46;})) print_ip(ip);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}