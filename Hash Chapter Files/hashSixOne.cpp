/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "hashChapter.hpp" untuk tugas dengan nama
    pencarian data menggunakan algoritma pencarian linear dan binary search.
*/

#include "hashChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void hashSixOne::menuInterface() {
    std::cout << "\nPilih menu untuk pengoperasian pada pencarian data:\n"
              << "  1. Masukkan data baru\n  2. Lihat data\n  3. Cari data\n"  
              << "  4. Hapus semua data\n  5. Lihat Program-program lain\n\nMasukkan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam tipe data collections sesuai urutan abjad yang disertai dengan 
    beberapa skenario error handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void hashSixOne::push() {
    std::cout << "Masukkan data baru (gunakan spasi untuk menambah data selanjutnya) => \n"; 
    std::string theData {normalizeInput()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

    std::string tempStr;
    if(!theData.empty()) {
        for (char checkDigit : theData) { // Iterasi untuk mengecek setiap karakter yang dimasukkan oleh user.
            if (std::isdigit(checkDigit)) { // Jika karakter yang dimasukkan adalah angka, maka tambahkan ke dalam variabel sementara.
                tempStr += checkDigit;
            } else if (!tempStr.empty()) { // Jika karakter yang dimasukkan bukan angka, maka masukkan data yang ada di variabel sementara ke dalam array.
                array.push_back(std::stol(tempStr));
                tempStr.clear();
            }
        }
        if (!tempStr.empty()) { // Jika masih ada data yang tersisa di variabel sementara, maka masukkan data tersebut ke dalam array.
            array.push_back(std::stol(tempStr));
        }
    } else {
        std::cout << "<Data yang dimasukan tidak boleh kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "preview" bertujuan untuk melihat semua data dalam array
----------------------------------------------------------------------------------------------------------------------------------------*/

void hashSixOne::preview() {
    if (array.size()) {
        std::cout << "Data saat ini : " << array << std::endl; // Menampilkan data array
    } else { 
        std::cout << "<Data kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "search" bertujuan untuk mencari data.
----------------------------------------------------------------------------------------------------------------------------------------*/

void hashSixOne::search() {
    std::cout << "Masukkan data yang ingin dicari: \n"; 
    long theData {long(inputIntValidator(&invalidIntInput))};
    
    if (array.size()) {
        search(array, theData);
    } else { 
        std::cout << "<Data kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Fungsi "del" bertujuan untuk menghapus semua data dalam array
----------------------------------------------------------------------------------------------------------------------------------------*/

void hashSixOne::del() {
    if (array.size()) {
        array.clear(); // Menghapus semua data dari array
        std::cout << "<Data berhasil dihapus>" << std::endl;
    } else { 
        std::cout << "<Data sudah kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 6: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void hashSixOne::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 5) {
            if (menuChosen == 1) {
                push(); // Akses ke fungsi PART 2 dari "sortFiveOne.hpp"
            } else if (menuChosen == 2) {
                preview(); // Akses ke fungsi PART 3 dari "sortFiveOne.hpp"
            } else if (menuChosen == 3) {
                search(); // Akses ke fungsi PART 4 dari "sortFiveOne.hpp"
            } else if (menuChosen == 4) {
                del(); // Akses ke fungsi PART 5 dari "sortFiveOne.hpp"
            } else {
                array.clear(); // Menghapus semua data dari array
                break;
            }
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }

        outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE PART 6.
----------------------------------------------------------------------------------------------------------------------------------------*/
