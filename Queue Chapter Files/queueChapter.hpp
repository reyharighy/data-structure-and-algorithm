/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Antrian (Queue). Setiap objek kelas 
    yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef QUEUE_CHAPTER
#define QUEUE_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"
#include <vector>

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Antrian dengan Array Terbatas.
----------------------------------------------------------------------------------------------------------------------------------------*/

class QueueTwoOne: public Program {
private:
    bool isCapacitySet {false};
    int capacity {0};
    int filledCapacity {0};
    std::string invalidIntInput;
    std::string* arrayPointer = nullptr;
    void menuInterface();
    void push();
    void flush ();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~QueueTwoOne(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Antrian dengan Array Terbatas dan Proses Penyisipan Data.
----------------------------------------------------------------------------------------------------------------------------------------*/

class QueueTwoTwo: public Program {
private:
    bool isCapacitySet {false};
    int capacity {0};
    int filledCapacity {0};
    std::string invalidIntInput;
    std::string* arrayPointer = nullptr;
    void menuInterface();
    void push();
    void pop();
    void display();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~QueueTwoTwo(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas Implementasi Antrian dengan Array Terbatas dan Proses Penyisipan Data.
----------------------------------------------------------------------------------------------------------------------------------------*/

class QueueTwoThree: public Program {
private:
    int filledNumber {0};
    std::string invalidIntInput;
    std::vector<std::string> array {};
    void menuInterface();
    void push();
    void pop();
    void display();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif