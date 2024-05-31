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

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam tipe data collections sesuai urutan abjad yang disertai dengan 
    beberapa skenario error handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::push() {
    std::cout << "\nPilih tipe data yang ingin dimasukkan:\n"
              << "  1. Integer\n  2. String\n\nMasukkan angka pilihan => ";
    short pushChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

    switch(pushChosen) {
        case 1: {
            std::cout << "Masukkan data baru (gunakan spasi untuk menambah data selanjutnya) => \n";
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
            break;
        }
        case 2: {
            std::cout << "Masukkan data baru (enter untuk menambah data selanjutnya dan enter 2x untuk selesai) => \n";
            std::string line;
            while (std::getline(std::cin, line)) {
                if (line.empty()) {
                    break;
                }
                arrayString.push_back(line);
            }
            break;
        }
        default:
            std::cout << "Pilihan tidak valid.";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "preview" bertujuan untuk melihat semua data dalam array
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::preview() {
    std::cout << "\nPilih preview data yang ingin dilihat:\n"
              << "  1. Data integer\n  2. Data string  \n\nMasukkan angka pilihan => ";
    short previewChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
        
        switch(previewChosen) {
        case 1:
            if (array.size()) {
                std::cout << "Data saat ini : " << array << std::endl;
            } else {
                std::cout << "<Data kosong>";
            }
            break;
        case 2:
            if (arrayString.size()) {
                std::cout << "Data saat ini : " << arrayString << std::endl;
            } else {
                std::cout << "<Data kosong>";
            }
            break;

        default:
            invalidMenuChosen(&previewChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "sort" bertujuan untuk mengurutkan semua data menggunakan teknik pengurutan Bubble Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFourOne::sort() {
    if (array.size() || arrayString.size()) {
        std::cout << "\nPilih urutan pengoperasian pada sort:\n"
                  << "  1. Pengurutan naik Integer (Ascending)\n  2. Pengurutan turun Integer (Descending)\n"
                  << "  3. Pengurutan naik String (Ascending)\n  4. Pengurutan turun String (Descending)  \n\nMasukkan angka urutan pilihan => ";
        short sortChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
        
        switch(sortChosen) {
        case 1:
            if (!array.size()) {
                std::cout << "<Data kosong>";
                break;
            }
            bubbleSort(array, true);
            
            break;
        case 2:
            if (!array.size()) {
                std::cout << "<Data kosong>";
                break;
            }
            bubbleSort(array, false);
            break;
        case 3:
            if (!arrayString.size()) {
                std::cout << "<Data kosong>";
                break;
            }
            bubbleSortString(arrayString, true);
            break;
        case 4:
            if (!arrayString.size()) {
                std::cout << "<Data kosong>";
                break;
            }
            bubbleSortString(arrayString, false);
            break;
        default:
            invalidMenuChosen(&sortChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }
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
    std::cout << "\nPilih data yang ingin dihapus:\n"
              << "  1. Data integer\n  2. Data string  \n\nMasukkan angka pilihan => ";
    short delChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"
        
        switch(delChosen) {
        case 1:
            array.clear(); // Menghapus semua data dari array
            break;
        case 2:
            arrayString.clear(); // Menghapus semua data dari arrayString
            break;

        default:
            invalidMenuChosen(&delChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }
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
                arrayString.clear();
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
