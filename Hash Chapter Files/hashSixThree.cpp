/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "hashChapter.hpp" untuk tugas dengan nama
    Penanganan Tabrakan Hash dengan cara Pembentukan Rantai.
*/

#include "hashChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void hashSixThree::menuInterface() {
    std::cout << "\nPilih menu untuk pengoperasian pada Pembentukan Rantai:\n"
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

void hashSixThree::push() {
    std::cout << "Masukkan kunci => "; 
    long key = long(inputIntValidator(&invalidIntInput));
    if (key) {
        std::cout << "Masukkan data => "; 
        std::string theData = normalizeInput();
        if (!theData.empty()) {
            table.insert(key, theData);
            std::cout << "Data " << key << " berhasil ditambahkan\n";
        }
    } else {
        std::cout << "<Data yang dimasukan tidak boleh kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "preview" bertujuan untuk melihat semua data dalam tabel
----------------------------------------------------------------------------------------------------------------------------------------*/

void hashSixThree::preview() {
    if (table.size()) {
        std::cout << "Data saat ini : \n";
        table.display();
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

void hashSixThree::search() {
    std::cout << "Masukkan data yang ingin dicari: \n"; 
    long theData {long(inputIntValidator(&invalidIntInput))};
    
    if (table.size()) {
        table.search(theData);
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

void hashSixThree::del() {
    if (table.size()) {
        table.clear(); // Menghapus semua data dari tabel
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

void hashSixThree::start() {
    std::cout << "Masukkan ukuran tabel => "; 
    int tabelSize = int(inputIntValidator(&invalidIntInput));
    table = HashTable(tabelSize);
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 5) {
            if (menuChosen == 1) {
                push(); // Akses ke fungsi PART 2 dari "hashSixThree.hpp"
            } else if (menuChosen == 2) {
                preview(); // Akses ke fungsi PART 3 dari "hashSixThree.hpp"
            } else if (menuChosen == 3) {
                search(); // Akses ke fungsi PART 4 dari "hashSixThree.hpp"
            } else if (menuChosen == 4) {
                del(); // Akses ke fungsi PART 5 dari "hashSixThree.hpp"
            } else {
                table.clear(); // Menghapus semua data dari tabel
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
