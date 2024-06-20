/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "stackChapter.hpp" untuk tugas dengan nama
    Implementasi Tumpukan dengan Array Dinamis.
*/

#include "stackChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneThree::menuInterface() {
    std::cout << "\nJumlah data di dalam tumpukan = " << (filledNumber ? std::to_string(filledNumber) : "0")
              << "\n\nPilih menu untuk pengoperasian tumpukan:\n  1. Penambahan data baru pada tumpukan"
              << "\n  2. Pengosongan isi tumpukan\n  3. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyimpan data ke dalam tipe data collections yang disertai dengan skenario error handling 
    sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneThree::push() {
    std::cout << "Masukkan data baru pada tumpukan => ";
    std::string theData {titleCase()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"
    
    if (theData.empty()) { // Jika data yang dimasukkan kosong
        std::cout << "<Tidak ada data baru yang dimasukan>";
    } else {
        stack.push_back(theData); // Menambahkan data ke dalam tumpukan
        filledNumber++; // Menambahkan jumlah data yang ada di dalam tumpukan
        std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "flush" bertujuan untuk mengeluarkan data tersimpan di dalam tipe data collections sesuai dengan algoritma yang
    ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneThree::flush() {
    std::cout << "\nIsi tumpukan:\n";

    while (!stack.empty()) { // Mengeluarkan data dari tumpukan
        std::cout << stack.back() << std::endl;
        stack.pop_back();
    }

    filledNumber = 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneThree::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 3) {
            if (menuChosen == 1) {
                push(); // Akses ke fungsi PART 2 dari "stackOneThree.cpp"
            } else if (menuChosen == 2) {
                flush(); // Akses ke fungsi PART 3 dari "stackOneThree.cpp"
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
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/
