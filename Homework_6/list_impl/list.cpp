#include "list.hpp"
#include <iostream>
int main() {
    List<int> lis;
    for(int i = 0; i < 6; ++i) {
        lis.push_back(i);
    }
    //lis.insert(3,7);
    //lis.pop_front();
    //lis.erase(2);
    //lis.push_front(3);
    lis.push_back(7);
    for(auto i = lis.begin(); i != lis.end(); ++i) {
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
    std:: cout << lis.front() << ' ' << lis.back() << std::endl;
}