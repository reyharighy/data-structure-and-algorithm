/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "stackChapter.hpp" untuk tugas dengan nama
    Implementasi linked list untuk mencari data.
*/

#include "queueChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoFour::menuInterface() {
    std::cout << "\nJumlah data di dalam list = " << (filledNumber ? std::to_string(filledNumber) : "0")
              << "\n\nPilih menu untuk pengoperasian pada linked list:\n"
              << "  1. Masukan data baru ke dalam list\n  2. Menghapus data di dalam list\n"
              << "  3. Tampilkan data di dalam list\n  4. Cari data di dalam list\n"
              << "  5. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data dan kode nama data baru ke dalam list dengan linked list.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoFour::push() {
    std::string theDataInput;
    while(true) {
        std::cout << "Masukan nama data baru pada tumpukan => ";
        theDataInput = normalizeInput(); // Akses ke fungsi PART 1 dari "customUtility.hpp"
        if(theDataInput.empty()){ // Dataa tidak valid jika input kosong
            std::cout << "<Tidak ada data baru yang dimasukan>";
        } else {
            break;
        } 
    }

    std::string dataCodenameInput;
    while (true) {
        std::cout << "Masukan kode nama untuk " << theDataInput << " => ";
        dataCodenameInput = normalizeInput(); // Akses ke fungsi PART 1 dari "customUtility.hpp"
        if(dataCodenameInput.empty()) { // Kode nama tidak valid jika input kosong
            std::cout << "<Kode nama tidak boleh kosong>";
        } else {
            break;
        }
    }
            
    linkedList node(dataCodenameInput, theDataInput);
    if (array.empty()) {
        array.push_back(node);
    } else { // Masukkan data ke dalam array di posisi awal jika array tidak kosong
        array.insert(array.begin(), node);
    }

    filledNumber++;
    std::cout   << std::endl << "<Data " << '"' << theDataInput << '"'
                << " dengan kode nama " << '"' << dataCodenameInput << '"' 
                << " berhasil ditambahkan>" << std::endl;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "pop" bertujuan untuk mengeluarkan data di dalam list.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoFour::pop() {
    if (array.size()) {
        std::cout << "Masukkan kode nama data yang ingin dihapus atau ketik ALL untuk menghapus semua data => ";
        std::string searchInput {normalizeInput()}; // Akses ke fungsi PART 1 dari "customUtility.hpp"
        bool searchExisted {false};

        if(searchInput == "ALL") {
            array.clear();
            filledNumber = 0;
            std::cout << std::endl << "<Seluruh data berhasil dihapus dari list>" << std::endl;
            return;
        }

        for (size_t i = 0; i < array.size(); i++) {
            if (searchInput == array[i].dataCodename || searchInput == array[i].theData) {
                array.erase(array.begin() + i); // Hapus array yang ditunjuk oleh iterator

                filledNumber--;
                searchExisted = true;
            }
        }

    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 3.1: Umpan balik kepada pengguna apakah proses pengeluaran berhasil atau tidak yang disertai dengan berbagai skenario.
    ------------------------------------------------------------------------------------------------------------------------------------*/

        if (searchExisted) {
            std::cout << std::endl << "<Data " << '"' << searchInput << '"' << " berhasil dihapus dari list>" << std::endl;
        } else if (searchInput.empty()) {
            std::cout << std::endl << "<Pencarian tidak boleh kosong>" << std::endl;
        } else {
            std::cout << std::endl << "<Data " << '"' << searchInput << '"' << " tidak ada di dalam list>" << std::endl;
        }
    } else {
        std::cout << std::endl << "<List tidak menyimpan data>" << std::endl;
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

void QueueTwoFour::display() {
    if (array.size()) {
        for (size_t i = 0; i < array.size(); i++) {
            std::cout << array[i].dataCodename << " : " << array[i].theData << std::endl;
        }
    } else {
        std::cout << std::endl << "<List belum menyimpan data>" << std::endl;
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Fungsi "find" bertujuan untuk mencari baik kode nama data atau data itu sendiri dalam array. Jika ditemukan,
    fungsi ini akan mencetak kode nama dan data tersebut.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoFour::find() {
    if (array.size()) {
        std::cout << "Masukkan kode nama data yang ingin dicari => ";
        std::string searchInput {normalizeInput()}; // Akses ke fungsi PART 1 dari "customUtility.hpp"
        bool searchExisted {false};
        std::cout << "Hasil pencarian :" << std::endl;

        for (size_t i = 0; i < array.size(); i++) {
            if (searchInput == array[i].dataCodename || searchInput == array[i].theData) {
                std::cout << array[i].dataCodename << " : " << array[i].theData << std::endl;
                searchExisted = true;
            }
        }
    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 5.1: Umpan balik kepada pengguna apakah proses pencarian berhasil atau tidak yang disertai dengan berbagai skenario.
    ------------------------------------------------------------------------------------------------------------------------------------*/
        if (searchExisted) {
            std::cout << std::endl << "<Data " << '"' << searchInput << '"' << " berhasil ditemukan>" << std::endl;
        } else if (searchInput.empty()) {
            std::cout << std::endl << "<Pencarian tidak boleh kosong>" << std::endl;
        } else {
            std::cout << std::endl << "<Data " << '"' << searchInput << '"' << " tidak ada di dalam list>" << std::endl;
        }
    }
    else {
        std::cout << std::endl << "<List belum menyimpan data>" << std::endl;
    }

    /*------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 5.1.
    ------------------------------------------------------------------------------------------------------------------------------------*/

}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 6: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoFour::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 5) {
            if (menuChosen == 1) {
                push();
            } else if (menuChosen == 2) {
                pop();
            } else if (menuChosen == 3) {
                display();
            } else if (menuChosen == 4) {
                find();
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
    END OF SCOPE PART 6.
----------------------------------------------------------------------------------------------------------------------------------------*/
