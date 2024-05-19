/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "stackChapter.hpp" untuk tugas dengan nama
    Implementasi Tumpukan dengan Array Terbatas.
*/

#include "stackChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneTwo::menuInterface() {
    std::cout << "\nJumlah maksimal tumpukan = " << (isCapacitySet ? std::to_string(capacity) : "<Belum ditentukan>")
              << "\nJumlah kapasitas tumpukan tersisa = " << (isCapacitySet ? std::to_string(capacity - filledCapacity) : "<Tidak terdefinisi>")
              << "\n\nPilih menu untuk pengoperasian tumpukan:\n  1. Tentukan kapasitas tumpukan\n  2. Penambahan data baru pada tumpukan"
              << "\n  3. Pengosongan isi tumpukan\n  4. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyimpan data ke dalam tipe data collections yang disertai dengan beberapa skenario error
    handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneTwo::push() {
    if (isCapacitySet) {
        std::cout << "Masukkan data baru pada tumpukan => ";
        std::string theData {titleCase()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

        if (filledCapacity == capacity) { // Data baru tidak dapat ditambahkan jika kapasitas sudah penuh
            std::cout << "<Tumpukan sudah penuh. " << '"' << theData << '"' << " tidak dimasukan>";
        } else if (theData.empty()) { // Data baru tidak valid jika input kosong
            std::cout << "<Tidak ada data baru yang dimasukan>";
        } else {
            stackPointer[filledCapacity] = theData;
            filledCapacity++;
            std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "flush" bertujuan untuk mengeluarkan data tersimpan di dalam tipe data collections sesuai dengan algoritma yang
    ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneTwo::flush() {
    if (isCapacitySet) { // Kapasitas harus ditentukan sebelum melakukan proses pengeluaran
        if (filledCapacity) {
            std::cout << "\nIsi tumpukan:\n";

            for (size_t i = filledCapacity; i > 0; --i) {
                std::cout << stackPointer[i - 1] << std::endl;
                stackPointer[i - 1].clear();
            }

            filledCapacity = 0;
        } else {
            std::cout << "<Tumpukan tidak menyimpan data>";
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneTwo::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 4) {
            if (menuChosen == 1) {
                setCapacityValue(&isCapacitySet, &capacity, &filledCapacity, &invalidIntInput, &stackPointer); // Akses ke fungsi PART 6 dari "customUtility.hpp" 
            } else if (menuChosen == 2) {
                push();
            } else if (menuChosen == 3) {
                flush();
            } else {
                break;
            }

            std::cout << (isCapacitySet ? "" : "<Kapasitas tumpukan belum ditentukan>");
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }

        outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

StackOneTwo::~StackOneTwo() { // Destructor untuk mencegah memory leaks
    delete[] stackPointer;
}
