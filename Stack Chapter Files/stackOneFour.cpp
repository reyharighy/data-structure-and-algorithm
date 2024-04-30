/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "stackChapter.hpp" untuk tugas dengan nama
    Implementasi Tumpukan untuk Pembalikan String.
*/

#include "stackChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneFour::menuInterface() {
    std::cout << "\nPilih menu untuk pengoperasian tumpukan:\n  1. Masukkan string baru"
              << "\n  2. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "getReversedInput" bertujuan untuk membalikkan urutan karakter yang dimasukkan ke dalam variabel collections. 
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneFour::getReversedInput() {
    std::cout << "Masukan string yang ingin dibalik => ";

    std::string inputString;
    std::getline(std::cin, inputString);

    std::cout << "\nString Awal = " << '"' << inputString << '"' << "\nString Pembalikan = " << '"';

    for (char ch : inputString) { // Memasukkan tiap karakter secara berurutan dari awal hingga akhir
        stack.push_back(ch);
    }

    while (!stack.empty()) {
        std::cout << stack.back(); // Mengeluarkan tiap karakter dari urutan terakhir yang disimpan
        stack.pop_back();
    }

    std::cout << '"' << std::endl;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneFour::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 2) {
            if (menuChosen == 1) {
                getReversedInput();
            } else {
                break;
            }
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }

        outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
    }
    
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/
