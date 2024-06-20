/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "linkedListChapter.hpp" untuk tugas dengan nama
    Implementasi linked list untuk membuat stack.
*/

#include "linkedListChapter.hpp" 

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Implementasi linked list untuk membuat stack
----------------------------------------------------------------------------------------------------------------------------------------*/

void display(Stack<std::string> stack) {
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

void linkedListThreeTwo::start() {
    std::cout << "Stack Demo\n"
              << "Masukkan ukuran maks.: ";
    short sizeInput {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
    auto stack = Stack<std::string>(sizeInput);
    while(true) {
        std::cout << std::endl << "Anggota stack: ";
        display(stack);
        std::cout << std::endl << "[(1) Tambah | (2) Ambil | (9) Keluar] \n" 
                  << "Pilihan: ";
        
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
        if (menuChosen == 9) {
            break;
        } else if (menuChosen == 1) {
            std::cout << "Masukkan data: ";
            std::string data;
            std::getline(std::cin, data);
            if (data.empty()) {
                std::cout << "<Tidak ada data yang dimasukkan>\n";
            } else {
                if (!stack.isFull()) {
                    stack.push(data);
                    std::cout << "Data " << '"' << data << '"' << " ditambahkan.\n";
                } else {
                    std::cout << "Stack penuh." << "\n";
                }
            }
        } else if (menuChosen == 2) {
            if (!stack.isEmpty()) {
                std::cout << stack.pop() << " diambil.\n";
            } else {
                std::cout << "Stack kosong." << "\n";
            }
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/