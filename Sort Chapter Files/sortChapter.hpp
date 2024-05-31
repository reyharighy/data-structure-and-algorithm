/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Urutan (Sort). Setiap objek kelas 
    yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef SORT_CHAPTER
#define SORT_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (const auto& el : vec)
    {
        os << el << ' ';
    }
    return os;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Bubble Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourOne: public Program {
private:
    bool isDataExist {false};
    std::string invalidIntInput;
    std::vector<long> array {};
    std::vector<std::string> arrayString {};
    void bubbleSort(std::vector<long>& array, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        bool swapped;
        for (int i = 0; i < array.size() - 1; i++) {
            swapped = false;
            for (int j = 0; j < array.size() - i - 1; j++) {
                if ((ascending && array[j] > array[j + 1]) || (!ascending && array[j] < array[j + 1])) {
                    std::cout << "Menukarkan " << array[j] << " dengan " << array[j + 1] << std::endl;
                    std::swap(array[j], array[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
            std::cout << "Array saat ini: " << array << std::endl;
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void bubbleSortString(std::vector<std::string>& arrayString, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        bool swapped;
        for (int i = 0; i < arrayString.size() - 1; i++) {
            swapped = false;
            for (int j = 0; j < arrayString.size() - i - 1; j++) {
                if ((ascending && arrayString[j] > arrayString[j + 1]) || (!ascending && arrayString[j] < arrayString[j + 1])) {
                    std::cout << "Menukarkan " << arrayString[j] << " dengan " << arrayString[j + 1] << std::endl;
                    std::swap(arrayString[j], arrayString[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
            std::cout << "Array saat ini: " << arrayString << std::endl;
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
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Insertion Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourTwo: public Program {
private:
    bool isDataExist {false};
    std::string invalidIntInput;
    std::vector<long> array {};
    std::vector<std::string> arrayString {};
    void insertionSort(std::vector<long>& array, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        for (int i = 1; i < array.size(); i++) {
            long k = array[i];
            int j = i - 1;

            while (j >= 0 && ((ascending && k < array[j]) || (!ascending && k > array[j]))) {
                array[j + 1] = array[j];
                j--;
            } 
            array[j + 1] = k;
            std::cout << array << ": " << k << " ke posisi " << j + 1 << std::endl;
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void insertionSortString(std::vector<std::string>& arrayString, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        for (int i = 1; i < arrayString.size(); i++) {
            std::string k = arrayString[i];
            int j = i - 1;

            while (j >= 0 && ((ascending && k < arrayString[j]) || (!ascending && k > arrayString[j]))) {
                arrayString[j + 1] = arrayString[j];
                j--;
            } 
            arrayString[j + 1] = k;
            std::cout << arrayString << ": " << k << " dipindahkan ke posisi " << j + 1 << std::endl;
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
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Selection Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourThree: public Program {
private:
    bool isDataExist {false};
    std::string invalidIntInput;
    std::vector<long> array {};
    std::vector<std::string> arrayString {};
    void selectionSort(std::vector<long>& array, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        for (int i = 0; i < array.size(); i++) {
            int k = i;
            for (int j = i + 1; j < array.size(); j++) {
                if ((ascending && array[j] < array[k]) || (!ascending && array[j] > array[k])) {
                    k = j;
                }
            }
            if (i != k) {
                std::swap(array[i], array[k]);
                std::cout << array << ": " << "Menukarkan " << array[i] << " dengan " << array[k] << std::endl;
            }
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void selectionSortString(std::vector<std::string>& arrayString, bool ascending) {
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        for (int i = 0; i < arrayString.size(); i++) {
            int k = i;
            for (int j = i + 1; j < arrayString.size(); j++) {
                if ((ascending && arrayString[j] < arrayString[k]) || (!ascending && arrayString[j] > arrayString[k])) {
                    k = j;
                }
            }
            if (i != k) {
                std::swap(arrayString[i], arrayString[k]);
                std::cout << arrayString << ": " << "Menukarkan " << arrayString[i] << " dengan " << arrayString[k] << std::endl;
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
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/
#endif