//
// Created by Maksim Kuznetsov on 31.03.2025.
//
#include <iostream>

int main() {
    for (int i = 0; i < 10; ++i) {
        auto gg = std::make_unique<int[]>(1000); // Автоматическое удаление
    }
    return 0;
}