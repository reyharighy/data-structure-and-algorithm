/*
    File ini berguna sebagai API untuk tiap subprogram yang ada di tiap chapter sehingga memudahkan
    proses penjelajahan dalam melakukan pengoperasian baik di dalam subprogram maupun antarmuka chapter.
*/

#include "Program Interface Files/programInterface.hpp"
#include "Custom Utility Files/customUtility.hpp"
#include "Stack Chapter Files/stackOneOne.hpp"
#include "Stack Chapter Files/stackOneTwo.hpp"
#include "Stack Chapter Files/stackOneThree.hpp"
#include "Stack Chapter Files/stackOneFour.hpp"
#include "Queue Chapter Files/queueTwoOne.hpp"
#include "Queue Chapter Files/queueTwoTwo.hpp"
#include "Queue Chapter Files/queueTwoThree.hpp"

/*-----------------------------------------------------------------------------------------------------------------*/

/*
    Objek "StackChapter" berperan sebagai derived class dari base "Program" dan menjalankan program khusus
    yang ada di Chapter Tumpukan (Stack).
*/

class StackChapter: public Program {
private:
    const short chapterID {1};
    std::string invalidIntInput;
    std::map<const short, Program*> stackProgramDictionary { // Seluruh subprogram dari Chapter Tumpukan (Stack)
        {1, new StackOneOne},
        {2, new StackOneTwo},
        {3, new StackOneThree},
        {4, new StackOneFour}
    };

public:
    void start() override {
        while (true) {
            bool flag {subProgramSelection(&chapterID, &invalidIntInput, &stackProgramDictionary)}; // Mengacu ke "programInterface.hpp"
            if (flag) {break;}
        }
    }

    ~StackChapter() { // desctructor untuk mencegah memory leaks
        for (std::pair<const short, Program*>& pair : stackProgramDictionary) {
            delete pair.second;
        }
    }
};

/*-----------------------------------------------------------------------------------------------------------------*/

/*
    Objek "QueueChapter" berperan sebagai derived class dari base "Program" dan menjalankan program khusus
    yang ada di Chapter Antrian (Queue).
*/

class QueueChapter: public Program {
private:
    const short chapterID {2};
    std::string invalidIntInput;
    std::map<const short, Program*> queueProgramDictionary { // Seluruh subprogram dari Chapter Antrian (Queue)
        {1, new QueueTwoOne()},
        {2, new QueueTwoTwo()},
        {3, new QueueTwoThree()}
    };

public:
    void start() override {
        while (true) {
            bool flag {subProgramSelection(&chapterID, &invalidIntInput, &queueProgramDictionary)}; // Mengacu ke "programInterface.hpp"
            if (flag) {break;}
        }
    }

    ~QueueChapter() { // desctructor untuk mencegah memory leaks
        for (std::pair<const short, Program*>& pair : queueProgramDictionary) {
            delete pair.second;
        }
    }
};

/*-----------------------------------------------------------------------------------------------------------------*/

/*
    Objek "LinkedListChapter" berperan sebagai derived class dari base "Program" dan menjalankan program khusus
    yang ada di Chapter Senarai Berantai (Linked List).
*/

class LinkedListChapter: public Program {
private:
    const short chapterID {3};
    std::string invalidIntInput;
    std::map<const short, Program*> linkedListProgramDictionary { // Seluruh subprogram dari Chapter Senarai Berantai (Linked List)

    };

public:
    void start() override {
        while (true) {
            bool flag {subProgramSelection(&chapterID, &invalidIntInput, &linkedListProgramDictionary)}; // Mengacu ke "programInterface.hpp"
            if (flag) {break;}
        }
    }

    ~LinkedListChapter() { // desctructor untuk mencegah memory leaks
        for (std::pair<const short, Program*>& pair : linkedListProgramDictionary) {
            delete pair.second;
        }
    }
};

/*-----------------------------------------------------------------------------------------------------------------*/

/*
    Fungsi "chapterSelection" menjadi gerbang untuk melihat seluruh subprogram yang ada di dalam tiap chapter.
*/

void chapterSelection(short menuChosen) {
    Program* chapter = nullptr;
    
    if (menuChosen == 1) {
        chapter = new StackChapter();
    } else if (menuChosen == 2) {
        chapter = new QueueChapter();
    } else if (menuChosen == 3) {
        chapter = new LinkedListChapter();
    }

    chapter->start();
    delete chapter;
}

/*-----------------------------------------------------------------------------------------------------------------*/

/*
    INTENDED USAGE FOR THE NEXT METHODS.
*/

/*-----------------------------------------------------------------------------------------------------------------*/

int main() { // Eksekusi "taskCompilation.cpp"
    std::string invalidIntInput;

    while (true) {
        std::cout << "\nProgram Dinamis Struktur Data dan Algoritma"
                  << "\n  1. Tumpukan (Stack)"
                  << "\n  2. Antrian (Queue)"
                  << "\n  3. Senarai Berantai (Linked List)"
                  << "\n  4. Selesai\n\nSilahkan masukan angka pilihan menu => ";
        
        short menuChosen {short(inputIntValidator(&invalidIntInput))};

        if (menuChosen >= 1 && menuChosen <= 3) {
            chapterSelection(menuChosen);
        } else if (menuChosen == 4) {
            std::cout << "*** SELESAI ***";
            break;
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput);
            outputBuffer();
        }
    }

    return 0;
}
