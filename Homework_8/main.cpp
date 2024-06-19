#include "String.hpp"

int main() {
    String str = "hello";
    String str_ = str;
    str_.print();
    str.print();
    str_.append(", it's a beautiful day");
    //str_.append(", world");
    //str_.print();
    //str.print();
    std::cout << str.length() << std::endl;
    std::cout << str_.length() << std::endl;
    str.memalloc();
    str_.memalloc();
    std::cout << str.is_empty() << std::endl;
}