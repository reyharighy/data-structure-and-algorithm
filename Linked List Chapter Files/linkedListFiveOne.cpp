#include "linkedlist.hpp"
#include <string>
#include <iostream>

namespace LinkedListChapter {
    namespace ReverseString {
        void reverseString(std::string str) {
            int length = str.length();
            LinkedListImplementation::LinkedList<char> reversedLetters;

            for (int i = 0; i < length; i++) {
                reversedLetters.add(0, str[i]);
            }

            for (int i = 0; i < length; i++) {
                std::cout << reversedLetters.get(i);
            }
            std::cout << "\n";
        };

        void demo() {
            std::cout << "===Pembalikan String===" << "\n";
            std::string input;
            std::string line;
            int emptyLineCount = 0;
            std::cout << "Masukkan data (Masukkan dua baris kosong berturut-turut untuk selesai): \n";
            while (std::getline(std::cin, line)) {
                if (line.empty()) {
                    emptyLineCount++;
                    if (emptyLineCount == 2) {
                        break;
                    }
                } else {
                    emptyLineCount = 0;
                }
                input += line + '\n';
            }
            
            std::cout << "Data yang dibalik: ";
            reverseString(input);
            std::cout << "===" << "\n";
        }
    }
}