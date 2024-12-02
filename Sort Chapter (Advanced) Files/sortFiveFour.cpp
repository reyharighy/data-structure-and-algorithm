/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "sortChapter.hpp" untuk tugas dengan nama
    mengurutkan data menggunakan Shell Sort. 
*/

#include "advancedSortChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFiveFour::menuInterface() {
    std::cout << "\nPilih menu untuk pengoperasian pada quick sort:\n"
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

void SortFiveFour::push() {
    std::cout << "\nPilih jenis data yang ingin dimasukkan:\n"
              << "  1. Data Integer\n  2. Data String\n\nMasukkan angka pilihan => ";
    short pushChosen {short(inputIntValidator(&invalidIntInput))};
    
    if (pushChosen == 1) {
        std::cout << "Masukkan angka integer baru (atau ketik 'done' untuk selesai):\n";
        while (true) {
            std::string input;
            std::cin >> input;
            if (input == "done") break;
            try {
                long value = std::stol(input);
                array.push_back(value);
            } catch (const std::exception&) {
                std::cout << "Input tidak valid. Masukkan angka integer.\n";
            }
        }
    } else if (pushChosen == 2) {
        std::cout << "Masukkan string baru (atau ketik 'done' untuk selesai):\n";
        while (true) {
            std::string input;
            std::cin >> input;
            if (input == "done") break;
            arrayString.push_back(input);
        }
    } else {
        invalidMenuChosen(&pushChosen, &invalidIntInput);
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "preview" bertujuan untuk melihat semua data dalam array
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFiveFour::preview() {
    std::cout << "\nPilih preview data yang ingin dilihat:\n"
              << "  1. Data Integer\n  2. Data String\n\nMasukkan angka pilihan => ";
    short previewChosen {short(inputIntValidator(&invalidIntInput))};
    
    if (previewChosen == 1 || previewChosen == 2) {
        if (previewChosen == 1 && array.size()) {
            std::cout << "Data saat ini : ";
            for (const auto& elem : array) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        } else if (previewChosen == 2 && arrayString.size()) {
            std::cout << "Data saat ini : ";
            for (const auto& elem : arrayString) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "<Data kosong>";
        }
    } else {
        invalidMenuChosen(&previewChosen, &invalidIntInput);
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "sort" bertujuan untuk mengurutkan semua data menggunakan teknik pengurutan Insertion Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFiveFour::sort() {
    std::cout << "\nPilih urutan pengoperasian pada merge sort:\n"
              << "  1. Pengurutan naik Integer (Ascending)\n  2. Pengurutan turun Integer (Descending)\n"
              << "  3. Pengurutan naik String (Ascending)\n  4. Pengurutan turun String (Descending)\n\nMasukkan angka urutan pilihan => ";
    short sortChosen {short(inputIntValidator(&invalidIntInput))};
    
    if (sortChosen >= 1 && sortChosen <= 4) {
        if (sortChosen == 1 && array.size()) {
            arrayClone = array;
            std::cout << "Data sebelum diurutkan: ";
            for (const auto& elem : arrayClone) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
            quickSort(arrayClone, 0, arrayClone.size() - 1, true);
            std::cout << "Data setelah diurutkan: ";
            for (const auto& elem : arrayClone) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        } else if (sortChosen == 2 && array.size()) {
            arrayClone = array;
            std::cout << "Data sebelum diurutkan: ";
            for (const auto& elem : arrayClone) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
            quickSort(arrayClone, 0, arrayClone.size() - 1, false);
            std::cout << "Data setelah diurutkan: ";
            for (const auto& elem : arrayClone) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        } 
        else if (sortChosen == 3 && arrayString.size()) {
            arrayStringClone = arrayString;
            std::cout << "Data sebelum diurutkan: ";
            for (const auto& elem : arrayStringClone) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
            quickSortString(arrayStringClone, 0, arrayStringClone.size() - 1, true);
            std::cout << "Data setelah diurutkan: ";
            for (const auto& elem : arrayStringClone) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        } else if (sortChosen == 4 && arrayString.size()) {
            arrayStringClone = arrayString;
            std::cout << "Data sebelum diurutkan: ";
            for (const auto& elem : arrayStringClone) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
            quickSortString(arrayStringClone, 0, arrayStringClone.size() - 1, false);
            std::cout << "Data setelah diurutkan: ";
            for (const auto& elem : arrayStringClone) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        } 
        else {
            std::cout << "<Data kosong>";
        }
    } else {
        invalidMenuChosen(&sortChosen, &invalidIntInput);
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Fungsi "del" bertujuan untuk menghapus semua data dalam array
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFiveFour::del() {
    std::cout << "\nPilih data yang ingin dihapus:\n"
              << "  1. Data Integer\n  2. Data String\n  3. Semua Data\n\nMasukkan angka pilihan => ";
    short delChosen {short(inputIntValidator(&invalidIntInput))};

    if (delChosen == 1) {
        array.clear();
        std::cout << "Data Integer telah dihapus.\n";
    } else if (delChosen == 2) {
        arrayString.clear();
        std::cout << "Data String telah dihapus.\n";
    } else if (delChosen == 3) {
        array.clear();
        arrayString.clear();
        std::cout << "Semua data telah dihapus.\n";
    } else {
        invalidMenuChosen(&delChosen, &invalidIntInput);
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 6: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void SortFiveFour::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 5) {
            if (menuChosen == 1) {
                push(); // Akses ke fungsi PART 2 dari "sortFiveTwo.hpp"
            } else if (menuChosen == 2) {
                preview(); // Akses ke fungsi PART 3 dari "sortFiveTwo.hpp"
            } else if (menuChosen == 3) {
                sort(); // Akses ke fungsi PART 4 dari "sortFiveTwo.hpp"
            } else if (menuChosen == 4) {
                del(); // Akses ke fungsi PART 5 dari "sortFiveTwo.hpp"
            } else {
                array.clear(); // Menghapus semua data dari array
                arrayString.clear(); // Menghapus semua data dari arrayString
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
