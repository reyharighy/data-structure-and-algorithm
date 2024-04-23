#ifndef QUEUETWOTHREE_H
#define QUEUETWOTHREE_H

#include "../mainProgram.hpp"
#include "../Custom Utility Files/customutils.hpp"
#include <vector>

class QueueTwoThree: public Program {
private:
    int filledNumber {0};
    std::string invalidIntInput;
    std::vector<std::string> array {};

    void menuInterface() {
        std::cout << "\nJumlah data di dalam antrian = " << (filledNumber ? std::to_string(filledNumber) : "0")
                  << "\n\nPilih menu untuk pengoperasian pada antrian:\n"
                  << "  1. Masukan data baru ke dalam antrian\n  2. Menghapus data di dalam antrian\n"
                  << "  3. Tampilkan data di dalam antrian\n  4. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
    }

    void push() {
        std::cout << "Masukan data baru pada tumpukan => ";
        std::string theData {titleCase()};

        if (theData.empty()) {
            std::cout << "<Tidak ada data baru yang dimasukan>";
        } else {
            bool isLast {true};

            for (size_t i = 0; i < array.size(); i++) {
                if (theData.compare(array[i]) < 0) {
                    array.push_back(array[array.size() - 1]);

                    for (size_t j = array.size() - 1; j > i; j--) {
                        array[j] = array[j-1];
                    }

                    array[i] = theData;
                    isLast = false;
                    break;
                }
            }

            if (isLast) {
                array.push_back(theData);
            }

            filledNumber++;
            std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
        }
    }

    void display() {
        std::cout << "\nIsi antrian:\n";

        for (size_t i = 0; i < filledNumber; i++) {
            std::cout << array[i];

            if (i != (filledNumber - 1)) {
                std::cout << " - ";
            }
        }

        std::cout << std::endl;
    }

public:
    void start() {
        while (true) {
            menuInterface();
            short menuChosen {short(inputIntValidator(&invalidIntInput))};

            if (menuChosen >= 1 && menuChosen <= 4) {
                if (menuChosen == 1) {
                    push();
                } else if (menuChosen == 2) {
                    
                } else if (menuChosen == 3) {
                    display();
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