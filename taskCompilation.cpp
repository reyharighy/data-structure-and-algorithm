/*
    File ini berguna sebagai API untuk tiap subprogram yang ada di tiap chapter sehingga memudahkan proses penjelajahan dalam melakukan 
    pengoperasian baik di dalam subprogram maupun antarmuka chapter.
*/

#include "Program Interface Files/programInterface.hpp"
#include "Custom Utility Files/customUtility.hpp"
#include "Stack Chapter Files/stackChapter.hpp"
#include "Queue Chapter Files/queueChapter.hpp"
#include "Sort Chapter Files/sortChapter.hpp"
#include "Sort Chapter (Advanced) Files/advancedSortChapter.hpp"

/*--------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Objek "StackChapter" berperan sebagai derived class dari base "Program" dan menjalankan program khusus yang ada di Chapter 
    Tumpukan (Stack).
--------------------------------------------------------------------------------------------------------------------------------------*/

class StackChapter: public Program {
private:
    const short chapterID {1};
    std::string invalidIntInput;
    std::map<const short, Program*> stackProgramDictionary { // Seluruh objek subProgram dari Chapter Tumpukan (Stack)
        {1, new StackOneOne},
        {2, new StackOneTwo},
        {3, new StackOneThree},
        {4, new StackOneFour}
    };

public:
    void start() override { // Menjalankan metode polymorphism dari kontrak virtual void start()
        while (true) {
            bool flag {subProgramSelection(&chapterID, &invalidIntInput, &stackProgramDictionary)}; // Akses ke fungsi PART 2 dari "programInterface.hpp"
            if (flag) {break;}
        }
    }

    ~StackChapter() { // Desctructor untuk mencegah memory leaks
        for (std::pair<const short, Program*>& pair : stackProgramDictionary) { // Menghapus seluruh objek subProgram dari dictionary
            delete pair.second;
        }
    }
};

/*--------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
--------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Objek "QueueChapter" berperan sebagai derived class dari base "Program" dan menjalankan program khusus yang ada di Chapter 
    Antrian (Queue).
--------------------------------------------------------------------------------------------------------------------------------------*/

class QueueChapter: public Program {
private:
    const short chapterID {2};
    std::string invalidIntInput;
    std::map<const short, Program*> queueProgramDictionary { // Seluruh objek subProgram dari Chapter Antrian (Queue)
        {1, new QueueTwoOne},
        {2, new QueueTwoTwo},
        {3, new QueueTwoThree},
        {4, new QueueTwoFour}
    };

public:
    void start() override { // Menjalankan metode polymorphism dari kontrak virtual void start()
        while (true) {
            bool flag {subProgramSelection(&chapterID, &invalidIntInput, &queueProgramDictionary)}; // Akses ke fungsi PART 2 dari "programInterface.hpp"
            if (flag) {break;}
        }
    }

    ~QueueChapter() { // Desctructor untuk mencegah memory leaks
        for (std::pair<const short, Program*>& pair : queueProgramDictionary) { // Menghapus seluruh objek subProgram dari dictionary
            delete pair.second;
        }
    }
};

/*--------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
--------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Objek "LinkedListChapter" berperan sebagai derived class dari base "Program" dan menjalankan program khusus yang ada di 
    Chapter Senarai Berantai (Linked List).
--------------------------------------------------------------------------------------------------------------------------------------*/

class LinkedListChapter: public Program {
private:
    const short chapterID {3};
    std::string invalidIntInput;
    std::map<const short, Program*> linkedListProgramDictionary { // Seluruh objek subProgram dari Chapter Senarai Berantai (Linked List)

    };

public:
    void start() override { // Menjalankan metode polymorphism dari kontrak virtual void start()
        while (true) {
            bool flag {subProgramSelection(&chapterID, &invalidIntInput, &linkedListProgramDictionary)}; // Akses ke fungsi PART 2 dari "programInterface.hpp"
            if (flag) {break;}
        }
    }

    ~LinkedListChapter() { // Desctructor untuk mencegah memory leaks
        for (std::pair<const short, Program*>& pair : linkedListProgramDictionary) { // Menghapus seluruh objek subProgram dari dictionary
            delete pair.second;
        }
    }
};

/*--------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
--------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Objek "SortChapter" berperan sebagai derived class dari base "Program" dan menjalankan program khusus yang ada di 
    Chapter Pengurutan Data (Sort).
--------------------------------------------------------------------------------------------------------------------------------------*/

class SortChapter: public Program {
private:
    const short chapterID {4};
    std::string invalidIntInput;
    std::map<const short, Program*> sortProgramDictionary { // Seluruh objek subProgram dari Chapter Pengurutan Data (Sort)
        {1, new SortFourOne},
        {2, new SortFourTwo},
        {3, new SortFourThree},
        {4, new SortFourFour}
    };

public:
    void start() override { // Menjalankan metode polymorphism dari kontrak virtual void start()
        while (true) {
            bool flag {subProgramSelection(&chapterID, &invalidIntInput, &sortProgramDictionary)}; // Akses ke fungsi PART 2 dari "programInterface.hpp"
            if (flag) {break;}
        }
    }

    ~SortChapter() { // Desctructor untuk mencegah memory leaks
        for (std::pair<const short, Program*>& pair : sortProgramDictionary) { // Menghapus seluruh objek subProgram dari dictionary
            delete pair.second;
        }
    }
};

/*--------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
--------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Objek "SortChapter(Advanced)" berperan sebagai derived class dari base "Program" dan menjalankan program khusus yang ada di 
    Chapter Pengurutan Data Tingkat Lanjut.
--------------------------------------------------------------------------------------------------------------------------------------*/

class SortChapterAdvanced: public Program {
private:
    const short chapterID {5};
    std::string invalidIntInput;
    std::map<const short, Program*> sortProgramDictionary { // Seluruh objek subProgram dari Chapter Pengurutan Data Tingkat Lanjut
        {1, new SortFiveOne},
        {2, new SortFiveTwo},
        {3, new SortFiveThree}
    };

public:
    void start() override { // Menjalankan metode polymorphism dari kontrak virtual void start()
        while (true) {
            bool flag {subProgramSelection(&chapterID, &invalidIntInput, &sortProgramDictionary)}; // Akses ke fungsi PART 2 dari "programInterface.hpp"
            if (flag) {break;}
        }
    }

    ~SortChapterAdvanced() { // Desctructor untuk mencegah memory leaks
        for (std::pair<const short, Program*>& pair : sortProgramDictionary) { // Menghapus seluruh objek subProgram dari dictionary
            delete pair.second;
        }
    }
};

/*--------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 5.
--------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------
    PART 6: Fungsi "chapterSelection" menjadi gerbang untuk melihat seluruh subprogram yang ada di dalam tiap chapter.
--------------------------------------------------------------------------------------------------------------------------------------*/

void chapterSelection(short menuChosen) {
    Program* chapter = nullptr; // Inisialisasi pointer objek kelas Program
    
    if (menuChosen == 1) {
        chapter = new StackChapter(); // Membuat objek kelas StackChapter
    } else if (menuChosen == 2) {
        chapter = new QueueChapter(); // Membuat objek kelas QueueChapter
    } else if (menuChosen == 3) {
        chapter = new LinkedListChapter(); // Membuat objek kelas LinkedListChapter
    } else if (menuChosen == 4) {
        chapter = new SortChapter(); // Membuat objek kelas SortChapter
    } else if (menuChosen == 5) {
        chapter = new SortChapterAdvanced(); // Membuat objek kelas SortChapterAdvanced
    }
    chapter->start(); // Menjalankan metode polymorphism dari kontrak virtual void start()
    delete chapter; // Mencegah memory leaks
}

/*--------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 6.
--------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------------------------
    PART 7: Eksekusi "taskCompilation.cpp".
--------------------------------------------------------------------------------------------------------------------------------------*/

int main() {
    std::string invalidIntInput;

    while (true) {
        std::cout << "\nProgram Dinamis Struktur Data dan Algoritma" // Standard output untuk pilihan menu
                  << "\n  1. Tumpukan (Stack)"
                  << "\n  2. Antrian (Queue)"
                  << "\n  3. Senarai Berantai (Linked List)"
                  << "\n  4. Urutan (Sort)"
                  << "\n  5. Urutan Tingkat Lanjut (Advanced Sort)"
                  << "\n  6. Selesai\n\nSilahkan masukkan angka pilihan menu => ";
        
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 5) { // Jika input di dalam jangkauan yang diminta
            chapterSelection(menuChosen);
        } else if (menuChosen == 6) { // Mengakhiri program
            std::cout << "*** SELESAI ***";
            break;
        } else { // Jika input di luar jangkauan yang diminta
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
            outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
        }
    }

    return 0;
}

/*--------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 7.
--------------------------------------------------------------------------------------------------------------------------------------*/
