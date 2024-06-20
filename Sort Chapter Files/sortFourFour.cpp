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
    std::cout << "\nPilih menu untuk pengoperasian pada binary search tree (BST):\n"
              << "  1. Masukkan data baru\n  2. Lihat Program-program lain\n\nMasukkan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam BST.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::push() {
    std::cout << "Masukkan data baru (gunakan spasi untuk menambah data selanjutnya) => \n";
    std::string theData {normalizeInput()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

    std::string tempStr; // Variabel sementara untuk menampung data yang akan dimasukkan ke dalam tree.
    if(!theData.empty()) {
        for (char checkDigit : theData) { // Iterasi untuk mengecek setiap karakter yang dimasukkan oleh user.
            if (std::isdigit(checkDigit)) { // Jika karakter yang dimasukkan adalah angka, maka tambahkan ke dalam variabel sementara.
                tempStr += checkDigit;
            } else if (!tempStr.empty()) { // Jika karakter yang dimasukkan bukan angka, maka masukkan data yang ada di variabel sementara ke dalam tree.
                tree.insert(std::stol(tempStr));
                tempStr.clear();
            }
        }
        if (!tempStr.empty()) { // Jika masih ada data yang tersisa di variabel sementara, maka masukkan data tersebut ke dalam tree.
            tree.insert(std::stol(tempStr));
            print(); // Akses ke fungsi PART 7 dari "sortFourFour.hpp"
            pre(); // Akses ke fungsi PART 3 dari "sortFourFour.hpp"
            in(); // Akses ke fungsi PART 4 dari "sortFourFour.hpp"
            post(); // Akses ke fungsi PART 5 dari "sortFourFour.hpp"
            del(); // Akses ke fungsi PART 6 dari "sortFourFour.hpp"
        }
    } else { // Jika data yang dimasukkan kosong, maka tampilkan pesan kesalahan.
        std::cout << "<Data yang dimasukan tidak boleh kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "pre" bertujuan untuk mengurutkan data sesuai Pre-order pada Pohon Biner.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::pre() {
    std::cout << "Data hasil urut (Pre-order) : ";
    tree.preOrder();
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "in" bertujuan untuk mengurutkan data sesuai In-order pada Pohon Biner.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::in() {
    std::cout << "Data hasil urut (In-order) : ";
    tree.inOrder();
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Fungsi "post" bertujuan untuk mengurutkan data sesuai Post-order pada Pohon Biner.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::post() {
    std::cout << "Data hasil urut (Post-order) : ";
    tree.postOrder();
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 6: Fungsi "del" bertujuan untuk menghapus seluruh data pada tree.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::del() {
    tree.deleteAll();
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 6.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 7: Fungsi "del" bertujuan untuk menghapus seluruh data pada tree.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::print() {
    tree.printLevelOrder();
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 7.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 8: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 2) {
            if (menuChosen == 1) {
                push(); // Akses ke fungsi PART 2 dari "sortFourFour.hpp"
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
    END OF SCOPE PART 8.
----------------------------------------------------------------------------------------------------------------------------------------*/
