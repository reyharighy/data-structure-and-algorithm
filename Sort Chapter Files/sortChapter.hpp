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
#include <sstream>
#include <iostream>

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
    std::vector<long> array, arrayCopy {};
    void menuInterface();
    void sort();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~SortFourOne(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
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
    std::vector<long> array, arrayCopy {};
    void menuInterface();
    void sort();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~SortFourTwo(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
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
    std::vector<long> array, arrayCopy {};
    void menuInterface();
    void sort();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~SortFourThree(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif