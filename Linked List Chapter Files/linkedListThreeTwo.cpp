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
    std::cout << "Stack Demo\n";
    std::cout << "Masukkan ukuran maks.: ";
    size_t sizeInput;
    std::cin >> sizeInput;
    auto stack = Stack<std::string>();
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
                break;
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/