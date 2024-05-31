/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "sortChapter.hpp" untuk tugas dengan nama
    Pre-order, In-order, dan Post-order Traversal pada Pohon Biner. 
*/

#include "sortChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::menuInterface() {
    std::cout << "\nPilih menu untuk pengoperasian pada sort:\n"
              << "  1. Masukkan data baru\n  2. Cari data secara Pre-order\n  3. Cari data secara In-order\n"  
              << "  4. Cari data secara Post-order  5. Lihat Program-program lain\n\nMasukkan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam tipe data collections sesuai urutan abjad yang disertai dengan 
    beberapa skenario error handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::push() {
    std::cout << "Masukkan data baru (gunakan spasi untuk menambah data selanjutnya) => ";
    std::string theData {normalizeInput()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

    std::istringstream iss(theData);
    std::string num;
    while (iss >> num) {
        array.push_back(std::stol(num));
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "pre" bertujuan untuk mencari data yang diinginkan menggunakan teknik pencarian Pre-order pada Pohon Biner.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::pre() {
    if (array.size()) {
        arrayCopy = array;
        std::cout << array << std::endl;
        
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
    PART 4: Fungsi "in" bertujuan untuk mencari data yang diinginkan menggunakan teknik pencarian In-order pada Pohon Biner.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::in() {
    if (array.size()) {
        arrayCopy = array;
        std::cout << array << std::endl;
        
        std::cout << std::endl << "Data berhasil diurutkan" << std::endl << "Data awal : " 
                  << arrayCopy << std::endl << "Data hasil urut : " << array << std::endl;
    } else {
        std::cout << "<Data kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Fungsi "post" bertujuan untuk mencari data yang diinginkan menggunakan teknik pencarian Post-order pada Pohon Biner.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::post() {
    if (array.size()) {
        arrayCopy = array;
        std::cout << array << std::endl;
        
        std::cout << std::endl << "Data berhasil diurutkan" << std::endl << "Data awal : " 
                  << arrayCopy << std::endl << "Data hasil urut : " << array << std::endl;
    } else {
        std::cout << "<Data kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 6: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
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
