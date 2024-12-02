/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "linkedListChapter.hpp" untuk tugas dengan nama
    Implementasi linked list untuk membalik string.
*/

#include "linkedListChapter.hpp" 

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Implementasi linked list untuk membalik string 
----------------------------------------------------------------------------------------------------------------------------------------*/

void reverseString(std::string str) {
    std::stringstream ss(str);
    std::string line;

    while (std::getline(ss, line)) {
        int length = line.length();
        LinkedList<char> reversedLetters;

        for (int i = 0; i < length; i++) {
            reversedLetters.add(0, line[i]);
        }

        for (int i = 0; i < length; i++) {
            std::cout << reversedLetters.get(i);
        }
        std::cout << "\n";
    }
}

void linkedListThreeOne::start() {
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
    
    std::cout << "Data yang dibalik: " << std::endl;
    reverseString(input);
    std::cout << "===" << "\n";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/