//
// Created by Maksim Kuznetsov on 31.03.2025.
//
#include <iostream>
#include <memory>

class Data {
public:
    int value;
    Data(int v) : value(v) { std::cout << "Data created" << std::endl; }
    ~Data() { std::cout << "Data destroyed" << std::endl; }
};

int main() {
    auto gg1 = std::make_shared<Data>(100);
    std::cout << "Use count: " << gg1.use_count() << std::endl; // видим что только 1 владелец
    auto gg2 = gg1;
    std::cout << "Use count: " << gg1.use_count() << std::endl; // видим 2 владельца
    return 0;
}