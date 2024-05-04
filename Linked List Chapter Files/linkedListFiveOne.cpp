#include "linkedlist.hpp"
#include <string>
#include <iostream>

namespace LinkedListChapter {
    namespace ReverseString {
        void reverseString(std::string str) {
            int length = str.length();
            LinkedList::LinkedList<char> reversedLetters;

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
            std::cout << "Masukkan data: ";
            std::getline(std::cin, input);
            std::getline(std::cin, input);

            std::cout << "Input: " << input << "\n";
            std::cout << "Data yang dibalik: " << "\n";
            std::cout << "===";
            reverseString(input);
        }; 
    }
}