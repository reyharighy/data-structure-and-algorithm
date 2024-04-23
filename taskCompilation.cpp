#include "mainProgram.hpp"
#include "Custom Utility Files/customutils.hpp"
#include "Stack Chapter Files/stackOneOne.hpp"
#include "Stack Chapter Files/stackOneTwo.hpp"
#include "Stack Chapter Files/stackOneThree.hpp"
#include "Stack Chapter Files/stackOneFour.hpp"
#include "Queue Chapter Files/queueTwoOne.hpp"
#include "Queue Chapter Files/queueTwoTwo.hpp"
#include "Queue Chapter Files/queueTwoThree.hpp"

class StackChapter: public Program {
private:
    std::string invalidIntInput;
    short taskID {1};

public:
    void start() override {
        while (true) {
            std::cout << "\nKompilasi Tugas Struktur Data Stack (Tumpukan):";
            short indexList {Program::taskList(taskID, 1, 4)};
            short programChosen {short(inputIntValidator(&invalidIntInput))};
            std::map<short, Program*> stackProgramDictionary {
                {1, new StackOneOne()},
                {2, new StackOneTwo()},
                {3, new StackOneThree()},
                {4, new StackOneFour()}
            };

            if (programChosen >= 1 && programChosen <= indexList) {
                Program* subProgram = nullptr;
                subProgram = stackProgramDictionary[programChosen];
                subProgram->start();
                delete subProgram;
            } else if (programChosen == (indexList + 1)) {
                break;
            } else {
                invalidMenuChosen(&programChosen, &invalidIntInput);
                outputBuffer();
            }
        }
    }
};

class QueueChapter: public Program {
private:
    std::string invalidIntInput;
    short taskID {2};
    std::map<short, Program*> queueProgramDictionary {
        {1, new QueueTwoOne()},
        {2, new QueueTwoTwo()},
        {3, new QueueTwoThree()}
    };

public:
    void start() override {
        while (true) {
            std::cout << "\nKompilasi Tugas Struktur Data Queue (Antrian):";
            short indexList {Program::taskList(taskID, 1, 3)};
            short programChosen {short(inputIntValidator(&invalidIntInput))};

            if (programChosen >= 1 && programChosen <= indexList) {
                Program* subProgram = nullptr;
                subProgram = queueProgramDictionary[programChosen];
                subProgram->start();
                delete subProgram;
            } else if (programChosen == (indexList + 1)) {
                break;
            } else {
                invalidMenuChosen(&programChosen, &invalidIntInput);
                outputBuffer();
            }
        }
    }
};

class LinkedListChapter: public Program {
private:
    std::string invalidIntInput;
    short taskID {2};
    short anotherTaskID {3};

public:
    void start() override {
        while (true) {
            std::cout << "\nKompilasi Tugas Struktur Data Linked List (Senarai Berantai):";
            short indexList {Program::taskList(taskID, 4, 4, anotherTaskID, 1, 6)};
            short programChosen {short(inputIntValidator(&invalidIntInput))};

            if (programChosen >= 1 && programChosen <= indexList) {
                break;
            } else if (programChosen == (indexList + 1)) {
                break;
            } else {
                invalidMenuChosen(&programChosen, &invalidIntInput);
                outputBuffer();
            }
        }
    }
};

void selectedChapter(short menuChosen) {
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

int main() {
    std::string invalidIntInput;

    while (true) {
        std::cout << "\nProgram Dinamis Struktur Data dan Algoritma"
                  << "\n  1. Stack (Tumpukan)"
                  << "\n  2. Queue (Antrian)"
                  << "\n  3. Linked List (Senarai Berantai)"
                  << "\n  4. Selesai\n\nSilahkan masukan angka pilihan menu => ";
        
        short menuChosen {short(inputIntValidator(&invalidIntInput))};

        if (menuChosen >= 1 && menuChosen <= 3) {
            selectedChapter(menuChosen);
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