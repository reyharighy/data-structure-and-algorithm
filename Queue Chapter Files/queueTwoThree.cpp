/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "stackChapter.hpp" untuk tugas dengan nama
    Implementasi Antrian dengan Array Dinamis dan Proses Penyisipan Data.
*/

#include "queueChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoThree::menuInterface() {
    std::cout << "\nJumlah data di dalam antrian = " << (filledNumber ? std::to_string(filledNumber) : "0")
              << "\n\nPilih menu untuk pengoperasian pada antrian:\n"
              << "  1. Masukan data baru ke dalam antrian\n  2. Menghapus data di dalam antrian\n"
              << "  3. Tampilkan data di dalam antrian\n  4. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam tipe data collections sesuai urutan abjad yang disertai dengan 
    beberapa skenario error handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoThree::push() {
    std::cout << "Masukan data baru pada tumpukan => ";
    std::string theData {titleCase()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

    if (theData.empty()) { // Data baru tidak valid jika input kosong
        std::cout << "<Tidak ada data baru yang dimasukan>";
    } else {
        bool isLast {true};

        for (size_t i = 0; i < array.size(); i++) {
            if (theData.compare(array[i]) < 0) {
                if (array.size() == 1) {
                    array.push_back(array[i]);
                } else {
                    array.push_back(array[array.size() - 1]);

                    for (size_t j = array.size() - 1; j > i; j--) {
                        array[j] = array[j - 1];
                    }
                }

                array[i] = theData;
                isLast = false;
                break;
            }
        }

        if (isLast) {
            array.push_back(theData);
        }

        filledNumber++;
        std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "pop" bertujuan untuk mengeluarkan sebuah data di dalam tipe data collections.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoThree::pop() {
    if (array.size()) {
        std::cout << "Masukkan data yang ingin dikeluarkan => ";
        std::string theData {titleCase()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"
        bool theDataExisted {false};
        bool isLast;

        for (size_t i = 0; i < array.size(); i++) {
            if (theData == array[i]) {
                isLast = (i == (array.size() - 1)) ? true : false;

                if (isLast) {
                    array.pop_back();
                } else {
                    for (size_t j = i; j < array.size() - 1; j++) {
                        array[j] = array[j + 1];
                    }

                    array.pop_back();
                }

                filledNumber--;
                theDataExisted = true;
                break;
            }
        }

    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 3.1: Umpan balik kepada pengguna apakah proses pengeluaran berhasil atau tidak yang disertai dengan berbagai skenario.
    ------------------------------------------------------------------------------------------------------------------------------------*/

        if (theDataExisted) {
            std::cout << "<Data " << '"' << theData << '"' << " berhasil dikeluarkan dari antrian>";
        } else if (theData.empty()) {
            std::cout << "<Data yang diminta tidak boleh kosong>";
        } else {
            std::cout << "<Data " << '"' << theData << '"' << " tidak ada di dalam antrian>";
        }
    } else {
        std::cout << "<Antrian tidak menyimpan data>";
    }

    /*------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 3.1.
    ------------------------------------------------------------------------------------------------------------------------------------*/
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "display" bertujuan untuk menampilkan seluruh data tersimpan di dalam tipe data collections ke standard output.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoThree::display() {
    if (array.size()) {
        std::cout << "\nIsi antrian:\n";

        for (size_t i = 0; i < filledNumber; i++) {
            std::cout << array[i];

            if (i != (filledNumber - 1)) {
                std::cout << " - ";
            }
        }

        std::cout << std::endl;
    } else {
        std::cout << "<Antrian tidak menyimpan data>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoThree::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 4) {
            if (menuChosen == 1) {
                push();
            } else if (menuChosen == 2) {
                pop();
            } else if (menuChosen == 3) {
                display();
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
    END OF SCOPE PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/
