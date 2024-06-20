/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "linkedListChapter.hpp" untuk tugas dengan nama
    Implementasi linked list ganda.
*/

#include "linkedListChapter.hpp" 

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Implementasi linked list ganda
----------------------------------------------------------------------------------------------------------------------------------------*/

void linkedListThreeFive::start() {
    auto list = DoublyLinkedList<std::string>();
    while(true) {
        std::cout << "Doubly Linked List\n";
        std::cout << "[(1) Tambah | (2) Hapus | (3) Output Maju | (4) Output Mundur | (0) Keluar] ";
        int input{};
        std::cin >> input;
        switch (input) {
            case 1: {
                std::cout << "Masukkan data: ";
                std::string dataInput;
                std::cin.ignore();
                std::getline(std::cin, dataInput);
                list.add(dataInput);
                break;
            }
            case 2: {
                std::cout << "Masukkan urutan data yang ingin dihapus\n(mulai dari 1): ";
                int indexInput;
                std::cin.ignore();
                std::cin >> indexInput;
                try {
                    list.remove(indexInput - 1);
                }
                catch (const std::exception& e) {
                    std::cout << "Indeks tidak ditemukan.\n";
                }
                break;
            }
            case 3:
                list.forwardTraverseDemo();
                break;
            case 4:
                list.reverseTraverseDemo();
                break;
            case 0: {
                break;
            }
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/