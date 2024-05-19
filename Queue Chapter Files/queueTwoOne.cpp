/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "stackChapter.hpp" untuk tugas dengan nama
    Implementasi Antrian dengan Array Terbatas.
*/

#include "queueChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoOne::menuInterface() {
    std::cout << "\nKapasitas antrian = " << (isCapacitySet ? std::to_string(capacity) : "<Belum ditentukan>")
              << "\nAntrian terisi = " << (isCapacitySet ? std::to_string(filledCapacity) : "<Tidak terdefinisi>")
              << "\n\nPilih menu untuk pengoperasian pada antrian:\n"
              << "  1. Tentukan kapasitas antrian\n  2. Masukkan data baru ke dalam antrian\n  3. Kosongkan antrian\n"
              << "  4. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyimpan data ke dalam tipe data collections yang disertai dengan beberapa skenario error
    handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoOne::push() {
    if (isCapacitySet) { // Kapasitas harus ditentukan dahulu sebelum penambahan data
        std::cout << "Masukkan data baru pada antrian => ";
        std::string theData {titleCase()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

        if (theData.empty()) { // Data baru tidak valid jika input kosong
            std::cout << "<Data yang dimasukan tidak boleh kosong>";
        } else if (filledCapacity == capacity) { // Data baru tidak dapat ditambahkan jika kapasitas sudah penuh
            std::cout << "<Antrian sudah penuh. " << '"' << theData << '"' << " tidak dimasukkan>";
        } else {
            arrayPointer[filledCapacity] = theData;
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

void QueueTwoOne::flush() {
    if (isCapacitySet) { // Kapasitas harus ditentukan dahulu sebelum menampilkan data
        if (filledCapacity) { // Jika ada data, maka proses penampilan data dilanjutkan
            std::cout << "\nIsi antrian:\n";

            for (size_t i = 0; i < filledCapacity; i++) {
                std::cout << arrayPointer[i];

                if (i < filledCapacity) {
                    std::cout << std::endl;
                }

                arrayPointer[i].clear();
            }

            filledCapacity = 0;
        } else {
            std::cout << "<Antrian tidak menyimpan data>";
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

void QueueTwoOne::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 4) {
            if (menuChosen == 1) {
                setCapacityValue(&isCapacitySet, &capacity, &filledCapacity, &invalidIntInput, &arrayPointer); // Akses ke fungsi PART 6 dari "customUtility.hpp" 
            } else if (menuChosen == 2) {
                push();
            } else if (menuChosen == 3) {
                flush();
            } else {
                break;
            }

            std::cout << (isCapacitySet ? "" : "<Kapasitas antrian belum ditentukan>");
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }

        outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

QueueTwoOne::~QueueTwoOne() { // Destructor untuk mencegah memory leaks
    delete[] arrayPointer;
}
