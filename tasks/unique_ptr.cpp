//
// Created by Maksim Kuznetsov on 31.03.2025.
//
#include <iostream>
#include <memory>
#include <fstream>

class File {
    std::unique_ptr<std::fstream> file;
public:
        explicit File(const std::string& filename) {
        file = std::make_unique<std::fstream>(filename, std::ios::out);
        if (!file->is_open()) throw std::runtime_error("Cannot open file");
    }
    ~File() { if (file) file->close(); } // Деструктор автоматически закрывает файл
    void write(const std::string& data) { *file << data; } // Метод для записи данных в файл
};

int main() {
    for (int i = 0; i < 10; i += 1) {
        auto gg = std::make_unique<int>(1000); // Автоматическое удаление
    }
    // example
    File fh("test.txt");
    fh.write("RAII example");
    return 0;
}