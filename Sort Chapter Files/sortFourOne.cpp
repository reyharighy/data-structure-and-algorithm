/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "sortChapter.hpp" untuk tugas dengan nama
    mengurutkan data menggunakan Bubble Sort. 
*/

#include "sortChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::menuInterface() {
    std::cout << "\nPilih menu untuk pengoperasian pada bubble sort:\n"
              << "  1. Masukkan data baru\n  2. Lihat data\n  3. Urutkan data\n"  
              << "  4. Hapus semua data\n  5. Lihat Program-program lain\n\nMasukkan angka pilihan menu => ";
}

void SortFourOne::menuInterfaceSort() {
    std::cout << "\nPilih urutan pengoperasian pada sort:\n"
              << "  1. Pengurutan naik (Ascending)\n  2. Pengurutan turun (Descending)  \n\nMasukkan angka urutan pilihan => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam tipe data collections sesuai urutan abjad yang disertai dengan 
    beberapa skenario error handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::push() {
    std::cout << "Masukkan data baru (gunakan spasi untuk menambah data selanjutnya) => ";
    std::string theData {normalizeInput()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

    std::string tempStr;
    if(!theData.empty()) {
        for (char checkDigit : theData) {
            if (std::isdigit(checkDigit)) {
                tempStr += checkDigit;
            } else if (!tempStr.empty()) {
                array.push_back(std::stol(tempStr));
                tempStr.clear();
            }
        }
    } else {
        std::cout << "<Data yang dimasukan tidak boleh kosong>";
    }

    if (!tempStr.empty()) {
        array.push_back(std::stol(tempStr));
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "preview" bertujuan untuk melihat semua data dalam array
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::preview() {
    if(array.size()) {
        std::cout << "Data saat ini : " << array << std::endl;
    } else {
        std::cout << "<Data kosong>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "sort" bertujuan untuk mengurutkan semua data menggunakan teknik pengurutan Bubble Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::sort() {
    if(array.size()) {
        arrayCopy = array;
        menuInterfaceSort();
        short sortChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
        
        switch(sortChosen) {
        case 1:
            std::cout << std::endl << "Pengurutan naik" << std::endl  << array << std::endl;

            for (size_t outerLoop = 0; outerLoop < array.size(); outerLoop++) {
                for (size_t innerLoop = 0; innerLoop < array.size() - 1; innerLoop++) {
                    if (array[innerLoop] > array[innerLoop + 1]) {
                        std::swap(array[innerLoop], array[innerLoop + 1]);
                        std::cout << array <<  " : " << array[innerLoop + 1] << " > " << array[innerLoop] << std::endl;
                    }
                }
            }

            break;

        case 2:
            std::cout << std::endl << "Pengurutan turun" << std::endl  << array << std::endl;

            for (size_t outerLoop = 0; outerLoop < array.size(); outerLoop++) {
                for (size_t innerLoop = 0; innerLoop < array.size() - 1; innerLoop++) {
                    if (array[innerLoop] < array[innerLoop + 1]) {
                        std::swap(array[innerLoop], array[innerLoop + 1]);
                        std::cout << array <<  " : " << array[innerLoop + 1] << " < " << array[innerLoop] << std::endl;
                    }
                }
            }

            break;

        default:
            invalidMenuChosen(&sortChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }
        
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
    PART 5: Fungsi "del" bertujuan untuk menghapus semua data dalam array
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::del() {
    array.clear(); // Menghapus semua data dari stack
    std::cout << "Semua data berhasil dihapus" << std::endl;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 6: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 5) {
            if (menuChosen == 1) {
                push();
            } else if (menuChosen == 2) {
                preview();
            } else if (menuChosen == 3) {
                sort();
            } else if (menuChosen == 4) {
                del();
            } else {
                array.clear();
                arrayCopy.clear();
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
