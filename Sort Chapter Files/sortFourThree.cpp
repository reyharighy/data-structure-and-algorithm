/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "sortChapter.hpp" untuk tugas dengan nama
    mengurutkan data menggunakan Selection Sort. 
*/

#include "sortChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourThree::menuInterface() {
    std::cout << "\nPilih menu untuk pengoperasian pada sort:\n"
              << "  1. Masukkan data baru\n  2. Urutkan data\n"  
              << "  3. Lihat Program-program lain\n\nMasukkan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam tipe data collections sesuai urutan abjad yang disertai dengan 
    beberapa skenario error handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourThree::push() {
    std::cout << "Masukkan data baru (gunakan spasi untuk menambah data selanjutnya) => ";
    std::string theData {normalizeInput()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

    std::string tempStr;
    for (char checkDigit : theData) {
        if (std::isdigit(checkDigit)) {
            tempStr += checkDigit;
        } else if (!tempStr.empty()) {
            array.push_back(std::stol(tempStr));
            tempStr.clear();
        }
    }

    if (!tempStr.empty()) {
        array.push_back(std::stol(tempStr));
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "sort" bertujuan untuk mengurutkan semua data menggunakan teknik pengurutan Selection Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourThree::sort() {
    if (array.size()) {
        arrayCopy = array;
        std::cout << array << std::endl;
        for (size_t i = 0; i < array.size(); i++) {
            int elem = i;
            for (size_t j = i + 1; j < array.size(); j++) {
                if (array[j] > array[elem]) {
                    elem = j;
                }
            }
            if (i != elem) {
                std::swap(array[i], array[elem]);
                std::cout << array[i] << " : " << array << std::endl;
            }
        }
        std::cout << std::endl << "Data berhasil diurutkan" << std::endl << "Data awal : " 
                  << arrayCopy << std::endl << "Data hasil urut : " << array << std::endl;
    } else {
        std::cout << "<Data kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourThree::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 3) {
            if (menuChosen == 1) {
                push();
            } else if (menuChosen == 2) {
                sort();
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
    END OF SCOPE PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/
