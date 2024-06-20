/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "linkedListChapter.hpp" untuk tugas dengan nama
    Implementasi linked list untuk membuat data terurut.
*/

#include "linkedListChapter.hpp" 

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Implementasi linked list untuk membuat data terurut
----------------------------------------------------------------------------------------------------------------------------------------*/

void display(OrderedLinkedList<std::string> orderedList) {
    std::cout << "======\n";
    size_t length = orderedList.length();
    if (length == 0) {
        std::cout << "List Kosong" << "\n";
    }
    else {
        std::cout << "Isi: ";
        for (int i = 0; i < length; ++i) {
            std::cout << orderedList.get(i);
            if (i != length - 1) {
                std::cout << "; ";
            }
        };
        std::cout << "\n";
    }
}

void linkedListThreeFour::start() {
    OrderedLinkedList<std::string> orderedList = OrderedLinkedList<std::string>();
    std::cout << "Ordered Linked List Demo\n";

    while (true) {
        display(orderedList);
        std::cout << "[(1) Tambah | (2) Ambil | (3) Hapus | (9) Keluar] \n" 
                  << "Pilihan: ";

        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
        if (menuChosen == 9) {
            break;
        } else if (menuChosen == 1) {
            std::cout << "Masukkan data: ";
            std::string dataInput;
            std::getline(std::cin, dataInput);
            orderedList.add(dataInput);
        } else if (menuChosen == 2) {
            std::cout << "Masukkan urutan data yang ingin di-output (mulai dari 1): ";
            int dataInput{};
            std::cin >> dataInput;
            std::cout << "Data yang di-output: " << orderedList.get(dataInput - 1) << "\n";
        } else if (menuChosen == 3) {
            std::cout << "Masukkan urutan data yang ingin dihapus (mulai dari 1): ";
            int dataInput{};
            std::cin >> dataInput;
            orderedList.remove(dataInput - 1);
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/