/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Urutan Tingkat Lanjut (Advanced Sort). Setiap objek 
    kelas yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef SORT_CHAPTER_ADVANCED
#define SORT_CHAPTER_ADVANCED

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"
#include <vector>
#include <string>

template<typename T>
std::ostream& operator<<(std::ostream& output, const std::vector<T>& array);

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan In Place Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveOne: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {};
    std::vector<std::string> arrayString, arrayStringClone {};
    void inPlaceSort(std::vector<long>& array, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        for (int i = array.size() - 1; i >= 0; i--) {
            int k = i;
            for (int j = 0; j < i; j++) {
                if ((ascending && array[j] > array[k]) || (!ascending && array[j] < array[k])) {
                    k = j;
                }
            }
            if (i != k) {
                std::swap(array[i], array[k]);
                std::cout << array << " => " << array[i] << " bertukar dengan " << array[k] << std::endl;
            }
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void inPlaceSortString(std::vector<std::string>& arrayString, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        for (int i = arrayString.size() - 1; i >= 0; i--) {
            int k = i;
            for (int j = 0; j < i; j++) {
                if ((ascending && arrayString[j] > arrayString[k]) || (!ascending && arrayString[j] < arrayString[k])) {
                    k = j;
                }
            }
            if (i != k) {
                std::swap(arrayString[i], arrayString[k]);
                std::cout << arrayString << " => " << arrayString[i] << " bertukar dengan " << arrayString[k] << std::endl;
            }
        }
        std::cout << "Data setelah diurutkan: " << arrayString << std::endl;
    }
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Shell Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveTwo: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {};
    std::vector<std::string> arrayString, arrayStringClone {};
    void shellSort(std::vector<long>& array, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        int gap = 1;
        while (gap < array.size() / 3) {
            gap = 3 * gap + 1; // Menghitung nilai awal gap sesuai dengan rumus 3h + 1
        }
        while (gap > 0) {
            for (int i = gap; i < array.size(); i++) {
                int j = array[i];
                int k = i;
                bool swap = false;
                while (k >= gap && ((ascending && array[k - gap] > j) || (!ascending && array[k - gap] < j))) {
                    std::swap(array[k], array[k - gap]);
                    k -= gap;
                    swap = true;
                }
                if (gap == 1) {
                    std::cout << "gap = " << gap << " : ";
                    for (int a = 0; a < array.size(); a++) {
                        std::cout << array[a];
                        if (a < array.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << array[k] << " pindah ke depan " << array[k + gap];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "gap = " << gap << " : ";
                    for (int a = 0; a < array.size(); a++) {
                        std::cout << array[a];
                        if (a < array.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << array[k + gap] << " bertukar dengan " << array[k];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                }
            }
            gap /= 3;
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }
    
    void shellSortString(std::vector<std::string>& arrayString, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        for (int i = 1; i < arrayString.size(); i++) {
            std::string k = arrayString[i];
            int j = i - 1;

            while (j >= 0 && ((ascending && k < arrayString[j]) || (!ascending && k > arrayString[j]))) {
                arrayString[j + 1] = arrayString[j];
                j--;
            } 
            arrayString[j + 1] = k;
            std::cout << arrayString << " => " << k << " ke posisi " << j+2 << std::endl;
        }
        std::cout << "Data setelah diurutkan: " << arrayString << std::endl;
    }
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Merge Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveThree: public Program {
private:
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Quick Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveFour: public Program {
private:
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif