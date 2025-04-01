//
// Created by Maksim Kuznetsov on 31.03.2025.
//
#include <iostream>
#include <memory>

class Data {
public:
    int value;
    explicit Data(int v) : value(v) { std::cout << "Data created" << std::endl; }
    Data() : value(0) { std::cout << "Data created" << std::endl; }
    ~Data() { std::cout << "Data destroyed" << std::endl; }
    };

int main() {
    std::weak_ptr<Data> weak;
    auto shared = std::make_shared<Data>(100);
    std::cout << "Before weak: " << shared.use_count() << std::endl;
    weak = shared; // добавляем weak
    std::cout << "After weak: " << shared.use_count() << std::endl;
    if (auto nw = weak.lock()) { // пытаемся поднять weak до shared
        std::cout << "Data is alive. Use count: " << nw.use_count() << std::endl;
    }
    std::cout << "After weak.lock(): " << shared.use_count() << std::endl;
    if (weak.expired()) { // если количество ссылок 0, то вернёт True
        std::cout << "Data is dead" << std::endl;
    }
    return 0;
}