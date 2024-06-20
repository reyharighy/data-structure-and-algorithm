/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Hash. Setiap objek 
    kelas yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef HASH_CHAPTER
#define HAsH_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas pencarian data menggunakan algoritma pencarian linear dan binary search.
----------------------------------------------------------------------------------------------------------------------------------------*/

class hashSixOne: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    void linearSearch(const std::vector<long>& array, int target) {
        int position = -1;
        for (int index = 0; index < array.size(); ++index) {
            if (array[index] == target) {
                position = index;
                break;
            }
        }
        if (position != -1) {
            std::cout << "Linear Search: Target found at position " << position+1 << std::endl;
        } else {
            std::cout << "Linear Search: Target not found." << std::endl;
        }
    }

    void binarySearch(const std::vector<long>& array, int target) {
        int low = 0;
        int high = array.size() - 1;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (target > array[mid]) {
                low = mid + 1;
            } else if (target < array[mid]) {
                high = mid - 1;
            } else {
                std::cout << "Binary Search: Target found at position " << mid+1 << std::endl;
                return;
            }
        }
        std::cout << "Binary Search: Target not found." << std::endl;
    }
    void search(std::vector<long> array, int target) {
        bool sorted = true;
        for (int i = 1; i < array.size(); ++i) {
            if (array[i - 1] > array[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            binarySearch(array, target);
        } else {
            linearSearch(array, target);
        }
    }

    void menuInterface();
    void search();
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
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas pencarian data menggunakan algoritma pencarian linear dan binary search.
----------------------------------------------------------------------------------------------------------------------------------------*/

class hashSixTwo: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    int linearSearch(std::vector<long> array, int size, int target) {
        int position = -1;
        int index = 0;
        while (index < size) {
            if (array[index] == target) {
                position = index;
                break;
            }
            index++;
        }
        return position;
    };

    int binarySearch(std::vector<long> array, int size, int target) {
        int low = 0;
        int high = size - 1;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (target > array[mid]) {
                low = mid + 1;
            } else if (target < array[mid]) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    };

    int search(std::vector<long> array, int size, int target) {
        bool sorted = true;
        for (int i = 1; i < size; ++i) {
            if (array[i - 1] > array[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return binarySearch(array, size, target);
        } else {
            return linearSearch(array, size, target);
        }
    };

    void menuInterface();
    void search();
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
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas pencarian data menggunakan algoritma pencarian linear dan binary search.
----------------------------------------------------------------------------------------------------------------------------------------*/

class hashSixThree: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    int linearSearch(std::vector<long> array, int size, int target) {
        int position = -1;
        int index = 0;
        while (index < size) {
            if (array[index] == target) {
                position = index;
                break;
            }
            index++;
        }
        return position;
    };

    int binarySearch(std::vector<long> array, int size, int target) {
        int low = 0;
        int high = size - 1;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (target > array[mid]) {
                low = mid + 1;
            } else if (target < array[mid]) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    };

    int search(std::vector<long> array, int size, int target) {
        bool sorted = true;
        for (int i = 1; i < size; ++i) {
            if (array[i - 1] > array[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return binarySearch(array, size, target);
        } else {
            return linearSearch(array, size, target);
        }
    };

    void menuInterface();
    void search();
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
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas pencarian data menggunakan algoritma pencarian linear dan binary search.
----------------------------------------------------------------------------------------------------------------------------------------*/

class hashSixFour: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    int linearSearch(std::vector<long> array, int size, int target) {
        int position = -1;
        int index = 0;
        while (index < size) {
            if (array[index] == target) {
                position = index;
                break;
            }
            index++;
        }
        return position;
    };

    int binarySearch(std::vector<long> array, int size, int target) {
        int low = 0;
        int high = size - 1;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (target > array[mid]) {
                low = mid + 1;
            } else if (target < array[mid]) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    };

    int search(std::vector<long> array, int size, int target) {
        bool sorted = true;
        for (int i = 1; i < size; ++i) {
            if (array[i - 1] > array[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return binarySearch(array, size, target);
        } else {
            return linearSearch(array, size, target);
        }
    };

    void menuInterface();
    void search();
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