#ifndef STACKONEFOUR_H
#define STACKONEFOUR_H

#include "../mainProgram.hpp"
#include "../Custom Utility Files/customutils.hpp"
#include <vector>
#include <charconv>

class StackOneFour: public Program {
private:
    std::string invalidIntInput;
    std::vector<char> stack {};

    void menuInterface() {
        std::cout << "\nPilih menu untuk pengoperasian tumpukan:\n  1. Masukkan string baru"
                  << "\n  2. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
    }

    void getReversedInput() {
        std::cout << "Masukan string yang ingin dibalik => ";

        std::string inputString;
        std::getline(std::cin, inputString);

        std::cout << "String Awal = " << '"' << inputString << '"' << "\nString Pembalikan = " << '"';

        for (char ch : inputString) {
            stack.push_back(ch);
        }

        while (!stack.empty()) {
            std::cout << stack.back();
            stack.pop_back();
        }

        std::cout << '"';
    }

public:
    void start() {
        while (true) {
            menuInterface();
            short menuChosen {short(inputIntValidator(&invalidIntInput))};

            if (menuChosen >= 1 && menuChosen <= 2) {
                if (menuChosen == 1) {
                    getReversedInput();
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