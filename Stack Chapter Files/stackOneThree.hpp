#ifndef STACKONETHREE_H
#define STACKONETHREE_H

#include "../mainProgram.hpp"
#include "../Custom Utility Files/customutils.hpp"
#include <vector>
#include <charconv>

class StackOneThree: public Program {
private:
    int filledNumber {0};
    std::string invalidIntInput;
    std::vector<std::string> stack {};

    void menuInterface() {
        std::cout << "\nJumlah data di dalam tumpukan = " << (filledNumber ? std::to_string(filledNumber) : "0")
                  << "\n\nPilih menu untuk pengoperasian tumpukan:\n  1. Penambahan data baru pada tumpukan"
                  << "\n  2. Pengosongan isi tumpukan\n  3. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
    }

    void push() {
        std::cout << "Masukan data baru pada tumpukan => ";
        std::string theData {titleCase()};
        
        if (theData.empty()) {
            std::cout << "<Tidak ada data baru yang dimasukan>";
        } else {
            stack.push_back(theData);
            filledNumber++;
            std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
        }
    }

    void flush() {
        std::cout << "\nIsi tumpukan:\n";

        while (!stack.empty()) {
            std::cout << stack.back();
            stack.pop_back();

            if (!stack.empty()) {
                std::cout << std::endl;
            }
        }

        filledNumber = 0;
    }

public:
    void start() {
        while (true) {
            menuInterface();
            short menuChosen {short(inputIntValidator(&invalidIntInput))};

            if (menuChosen >= 1 && menuChosen <= 3) {
                if (menuChosen == 1) {
                    push();
                } else if (menuChosen == 2) {
                    flush();
                } else {
                    break;
                }
            } else {
                invalidMenuChosen(&menuChosen, &invalidIntInput);
            }

            outputBuffer();
        }
    }
};

#endif