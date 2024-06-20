/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "linkedListChapter.hpp" untuk tugas dengan nama
    Implementasi linked list untuk membuat antrian.
*/

#include "linkedListChapter.hpp" 

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Implementasi linked list untuk membuat antrian
----------------------------------------------------------------------------------------------------------------------------------------*/

void display(Queue<std::string> q) {
    auto output = q;
    if (output.isEmpty()) {
        std::cout << "(kosong)";
    }
    while (!output.isEmpty()) {
        std::cout << output.dequeue() << "; ";
    }
}

void linkedListThreeThree::start() {
    std::cout << "Queue Demo\n"
              << "Masukkan ukuran maks.: ";
    short sizeInput {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
    auto q{Queue<std::string>(sizeInput)};

    while (true) {
        std::cout << "Anggota antrian: ";
        display(q);
        std::cout << std::endl << "[(1) Tambah | (2) Ambil | (9) Keluar]" 
                  << std::endl << "Pilihan: ";
        
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
                if (!q.isFull()) {
                    q.enqueue(data);
                    std::cout << "Data " << '"' << data << '"' << " ditambahkan.\n";
                } else {
                    std::cout << "Queue penuh." << "\n";
                }
            }
        } else if (menuChosen == 2) {
            if (!q.isEmpty()) {
                std::cout << q.dequeue() << " diambil.\n";
            } else {
                std::cout << "Queue kosong." << "\n";
            }
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }
    }
}   

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/