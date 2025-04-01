//
// Created by Maksim Kuznetsov on 31.03.2025.
//

#include <iostream>

int main() {
  for (int i = 0; i < 100; i += 1) {
    int* gg = new int[100]; // Утечка памяти, нет delete
  }
  return 0;
}