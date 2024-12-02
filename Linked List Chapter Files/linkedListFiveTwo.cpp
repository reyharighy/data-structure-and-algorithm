#include <string>
#include <iostream>
#include "implementations.hpp"

namespace LinkedListChapter {
    namespace StackDemo {
        void display(Implementations::Stack<std::string> stack) {
            auto clone = stack;
            size_t size = clone.length();
            if (size == 0) {
                std::cout << "(kosong)\n";
            }
            else {
                for (int i = 0; i < size; i++) {
                    std::cout << clone.pop();
                    if (i < size - 1) {
                        std::cout << "; ";
                    }
                }
                std::cout << "\n";
            }
        }

        int demo() {
            std::cout << "Stack Demo\n";
            std::cout << "Masukkan ukuran maks.: ";
            size_t sizeInput;
            std::cin >> sizeInput;
            auto stack = Implementations::Stack<std::string>(sizeInput);
            while(true) {
                std::cout << "Anggota stack: ";
                display(stack);
                std::cout << "[(1) Tambah | (2) Ambil | (0) Keluar] ";
                int input;
                std::cin >> input;
                switch (input) {
                    case 1: {
                        std::cout << "Masukkan data: ";
                        std::cin.ignore();
                        std::string data;
                        std::getline(std::cin, data);
                        try {
                            stack.push(data);
                        }
                        catch (const std::out_of_range& e) {
                            std::cout << "Stack penuh." << "\n";
                        }
                        break;
                    }
                    case 2:
                        try {
                            std::cout << stack.pop() << " diambil.\n";
                        }
                        catch (const std::out_of_range& e) {
                            std::cout << "Stack kosong." << "\n";
                        }
                        break;
                    case 0:
                        return 0;
                        break;
                }
            }
        }
    }
}