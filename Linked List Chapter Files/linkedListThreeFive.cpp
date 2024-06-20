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
    std::cout << "Doubly Linked List Demo\n";
    
    while(true) {
        std::cout << "[(1) Tambah | (2) Hapus | (3) Output Maju | (4) Output Mundur | (9) Keluar] \n"
                  << "Pilihan: ";

        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
        if (menuChosen == 9) {
            break;
        } else if (menuChosen == 1) {
            std::cout << "Masukkan data: ";
            std::string dataInput;
            std::getline(std::cin, dataInput);
            list.add(dataInput);
        } else if (menuChosen == 2) {
            std::cout << "Masukkan urutan data yang ingin dihapus\n(mulai dari 1): ";
            short indexInput {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
            try {
                list.remove(indexInput - 1);
            }
            catch (const std::exception& e) {
                std::cout << "Indeks tidak ditemukan.\n";
            }
        } else if (menuChosen == 3) {
            list.forwardTraverseDemo();
        } else if (menuChosen == 4) {
            list.reverseTraverseDemo();
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/