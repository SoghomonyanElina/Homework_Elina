#include "vect.hpp"
int main() {
    My_Vector<int> V;
    for(size_t i = 0; i < 6; ++i) {
        V.push_back(i);
    }
    //My_Vector<int> V_ = V; //Copy Ctor
    //My_Vector<int> V_(V); //Copy Ctor
    //My_Vector<int> V_;
    //V_ = V; //Copy assignment operator
    //V.push_back(2);
    //V.insert(2,3);
    //V.clear();
    //std::cout << V.size() << std::endl;
    //std::cout << V.empty() << std::endl;
    //V.erase(5);
    //V.push_front(4);
    //V.pop_back();
    //V.pop_front();
    //std::cout << V.front() << ' ' << V.back() << std::endl;
    //std::cout << V[2] << std::endl;
    //V.print();
}