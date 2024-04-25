/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "programInterface.hpp".
*/

#include "programInterface.hpp"

/*
    Fungsi "taskList" dari objek Program bertujuan untuk memberikan daftar subprogram kepada pengguna di tiap chapter.
*/

short Program::taskList(const short* chapterID) {
    short taskCount;
    std::map<short, std::string>* taskNameSelected {nullptr};

    /*----------------------------------------------------------------------------------------------------*/

    /*
        Prompt collections pada standard output untuk tiap chapter.
    */

    std::cout << "\nKompilasi Tugas Struktur Data ";

    if (*chapterID == 1) {
        taskNameSelected = new std::map<short, std::string> { // Chapter Tumpukan (Stack)
            {0, "Tumpukan (Stack):"},
            {1, "Konversi Bilangan Biner ke Bilangan Basis lain"},
            {2, "Implementasi Tumpukan dengan Array terbatas"},
            {3, "Implementasi Tumpukan dengan Array dinamis"},
            {4, "Implementasi Tumpukan untuk Pembalikan String"}
        };
    } else if (*chapterID == 2) {
        taskNameSelected = new std::map<short, std::string> { // Chapter Antrian (Queue)
            {0, "Antrian (Queue):"},
            {1, "Implementasi Antrian dengan Array terbatas"},
            {2, "Implementasi Antrian dengan Array terbatas dan Penyisipan"},
            {3, "Implementasi Antrian dengan Array dinamis dan Penyisipan"}
        };
    } else if (*chapterID == 3) {
        taskNameSelected = new std::map<short, std::string> { // Chapter Senarai Berantai (Linked List)
            {0, "Senarai Berantai (Linked List):"}
            // Future Notes: Belum terdefinisikan
        };
    }

    /*----------------------------------------------------------------------------------------------------*/

    taskCount = taskNameSelected->size() - 1;

    /*----------------------------------------------------------------------------------------------------*/

    /*
        Menampilkan daftar seluruh subprogram dari chapter yang dijelajahi 
    */
    
    for (size_t i = 0; i <= taskCount; i++) {
        if (i == 0) {
            std::cout << (*taskNameSelected)[i];
        } else {
            std::cout << "\n " << std::to_string(i) << ". " << (*taskNameSelected)[i];
        }
    }

    std::cout << "\n " << std::to_string(taskCount + 1)
                << ". Lihat Program-program pada Bab lain"
                << "\n\nSilahkan masukan angka pilihan menu => ";

    /*----------------------------------------------------------------------------------------------------*/

    delete taskNameSelected; // Mencegah memory leaks

    return taskCount;
}