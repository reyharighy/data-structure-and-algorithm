/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "programInterface.hpp".
*/

#include "programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "taskList" dari objek Program bertujuan untuk memberikan daftar subprogram kepada pengguna di tiap chapter.
------------------------------------------------------------------------------------------------------------------------------------*/

short Program::taskList(const short* chapterID) {
    short taskCount;
    std::map<short, std::string>* taskNameSelected {nullptr};

    /*----------------------------------------------------------------------------------------------------
        PART 1.1: Prompt collections pada standard output untuk tiap chapter.
    ----------------------------------------------------------------------------------------------------*/

    std::cout << "\nKompilasi Tugas Struktur Data ";

    if (*chapterID == 1) {
        taskNameSelected = new std::map<short, std::string> { // Chapter Tumpukan (Stack)
            {0, "Tumpukan (Stack):"},
            {1, "Konversi Bilangan Biner ke Bilangan Basis Lain"},
            {2, "Implementasi Tumpukan dengan Array Terbatas"},
            {3, "Implementasi Tumpukan dengan Array Dinamis"},
            {4, "Implementasi Tumpukan untuk Pembalikan String"}
        };
    } else if (*chapterID == 2) {
        taskNameSelected = new std::map<short, std::string> { // Chapter Antrian (Queue)
            {0, "Antrian (Queue):"},
            {1, "Implementasi Antrian dengan Array Terbatas"},
            {2, "Implementasi Antrian dengan Array Terbatas dan Proses Penyisipan Data"},
            {3, "Implementasi Antrian dengan Array Dinamis dan Proses Penyisipan Data"},
            {4, "Implementasi linked list untuk mencari data"}
        };
    } else if (*chapterID == 3) {
        taskNameSelected = new std::map<short, std::string> { // Chapter Senarai Berantai (Linked List)
            {0, "Senarai Berantai (Linked List):"}
            // Future Notes: Belum terdefinisikan
        };
    } else if (*chapterID == 4) {
        taskNameSelected = new std::map<short, std::string> { // Chapter Urutan (Sort)
            {0, "Urutan (Sort):"},
            {1, "Mengurutkan Data Menggunakan Bubble Sort"},
            {2, "Mengurutkan Data Menggunakan Insertion Sort"},
            {3, "Mengurutkan Data Menggunakan Selection Sort"},
            {4, "Pre-order, In-order, dan Post-order Traversal pada Pohon Biner"}
        };
    } else if (*chapterID == 5) {
        taskNameSelected = new std::map<short, std::string> { // Chapter Urutan Tingkat Lanjut (Advanced Sort)
            {0, "Urutan Tingkat Lanjut (Advanced Sort):"},
            {1, "Mengurutkan Data Menggunakan In Place Sort"},
            {2, "Mengurutkan Data Menggunakan Shell Sort"},
            {3, "Mengurutkan Data Menggunakan Merge Sort"},
            {4, "Mengurutkan Data Menggunakan Quick Sort"}
        };
    }

    /*----------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 1.1.
    ----------------------------------------------------------------------------------------------------*/

    taskCount = taskNameSelected->size() - 1; // Menghitung jumlah tugas di dalam suatu chapter

    /*----------------------------------------------------------------------------------------------------
        PART 1.2: Menampilkan daftar seluruh subprogram dari chapter yang dijelajahi.
    ----------------------------------------------------------------------------------------------------*/
    
    for (size_t i = 0; i <= taskCount; i++) { // standard output untuk seluruh subProgram dari suatu chapter
        if (i == 0) {
            std::cout << (*taskNameSelected)[i];
        } else {
            std::cout << "\n " << std::to_string(i) << ". " << (*taskNameSelected)[i];
        }
    }

    std::cout << "\n " << std::to_string(taskCount + 1) // standard output untuk keluar dari suatu chapter
              << ". Lihat Program-program pada Bab lain"
              << "\n\nSilahkan masukkan angka pilihan menu => ";

    /*----------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 1.2.
    ----------------------------------------------------------------------------------------------------*/

    delete taskNameSelected; // Mencegah memory leaks

    return taskCount;
}

/*----------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "subProgramSelection" dari objek Program bertujuan untuk menjalankan salah satu program yang tersedia di suatu 
            chapter. Disertai dengan error handling untuk standard input pengguna yang tidak valid. Dengan kata lain, bagian ini 
            sebagai implementasi dari apa yang ditampilkan pada standard output fungsi "taskList" dari objek Program.
----------------------------------------------------------------------------------------------------------------------------------*/

bool Program::subProgramSelection(const short* chapterID, std::string* invalidIntInput, std::map<const short, Program*>* subProgramDictionary) {
    short taskCount {taskList(&*chapterID)};
    short programChosen {short(inputIntValidator(&*invalidIntInput))}; // Mengambil hasil validasi dari fungsi PART 2 dari "customUtility.hpp"
    
    if (programChosen >= 1 && programChosen <= taskCount) { // Jangkauan pilihan seluruh subProgram di dalam suatu chapter
        ((*subProgramDictionary)[programChosen])->start();
    } else if (programChosen == (taskCount + 1)) { // Keluar dari suatu chapter
        return true;
    } else { // Jika standard input tidak valid
        invalidMenuChosen(&programChosen, &*invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
    }

    return false;
}

/*----------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
------------------------------------------------------------------------------------------------------------------------------------*/
