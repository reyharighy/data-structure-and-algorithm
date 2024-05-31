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

    std::string tempStr;
    if(!theData.empty()) {
        for (char checkDigit : theData) {
            if (std::isdigit(checkDigit)) {
                tempStr += checkDigit;
            } else if (!tempStr.empty()) {
                tree.insert(std::stol(tempStr));
                tempStr.clear();
            }
        }
    } else {
        std::cout << "<Data yang dimasukan tidak boleh kosong>";
    }

    if (!tempStr.empty()) {
        tree.insert(std::stol(tempStr));
        pre();
        in();
        post();
        del();
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
    PART 7: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourFour::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 2) {
            if (menuChosen == 1) {
                push();
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
    END OF SCOPE PART 7.
----------------------------------------------------------------------------------------------------------------------------------------*/
