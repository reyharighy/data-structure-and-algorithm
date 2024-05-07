#include <string>
#include <iostream>
#include "implementations.hpp"

namespace LinkedListChapter {
    namespace StackDemo {
        void demo() {
            int max;
            std::cout << "===Stack Demo===" << "\n";
            std::cout << "Masukkan jml. anggota maksimum: "; 
            std::cin >> max;
            Implementations::Stack<std::string> stack = Implementations::Stack<std::string>(max);

            std::cin.ignore();
            for (int i{0}; i < max; i++) {
                std::string input;

                std::cout << "Masukkan data ke-" << i + 1 << ": ";
                std::getline(std::cin, input);
                stack.push(input);
            }
            std::cout << "======";
            std::cout << "Tampilan data (atas-ke-bawah): " << "\n";
            while(!stack.isEmpty()) {
                std::cout << stack.pop() << "\n"; 
            }
            std::cout << "======" << "\n";
        }
    }
}