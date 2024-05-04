#ifndef STACKONETWO_H
#define STACKONETWO_H

#include "../mainProgram.hpp"
#include "../Custom Utility Files/customutils.hpp"
#include <charconv>
#include <vector>

class StackOneTwo: public Program {
private:
    bool isCapacitySet {false};
    int capacity {0};
    int filledCapacity {0};
    std::string invalidIntInput;
    std::string* stackPointer = nullptr;

    void menuInterface() {
        std::cout << "\nJumlah maksimal tumpukan = " << (isCapacitySet ? std::to_string(capacity) : "<Belum ditentukan>")
                  << "\nJumlah kapasitas tumpukan tersisa = " << (isCapacitySet ? std::to_string(capacity - filledCapacity) : "<Tidak terdefinisi>")
                  << "\n\nPilih menu untuk pengoperasian tumpukan:\n  1. Tentukan kapasitas tumpukan\n  2. Penambahan data baru pada tumpukan"
                  << "\n  3. Pengosongan isi tumpukan\n  4. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
    }

    bool push(bool flag = false) {
        if (isCapacitySet) {
            std::cout << "Masukan data baru pada tumpukan => ";
            std::string theData {titleCase()};

            if (filledCapacity == capacity) {
               std::cout << "<Tumpukan sudah penuh. " << '"' << theData << '"' << " tidak dimasukan>";
            } else if (theData.empty()) {
                std::cout << "<Tidak ada data baru yang dimasukan>";
            } else {
                stackPointer[filledCapacity] = theData;
                filledCapacity++;
                std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
            }

            flag = true;
        }

        return flag;
    }

    bool flush(bool flag = false) {
        if (isCapacitySet) {
            if (filledCapacity) {
                std::cout << "\nIsi tumpukan:\n";

                for (size_t i = filledCapacity; i > 0; --i) {
                    std::cout << stackPointer[i - 1];

                    if (i > 1) {
                        std::cout << std::endl;
                    }

                    stackPointer[i - 1].clear();
                }

                filledCapacity = 0;
            } else {
                std::cout << "<Tumpukan tidak menyimpan data>";
            }

            flag = true;
        }

        return flag;
    }

public:
    void start() override {
        while (true) {
            bool isSet {true};
            menuInterface();
            short menuChosen {short(inputIntValidator(&invalidIntInput))};

            if (menuChosen >= 1 && menuChosen <= 4) {
                if (menuChosen == 1) {
                    setCapacityValue(&isCapacitySet, &capacity, &filledCapacity, &invalidIntInput, &stackPointer);
                } else if (menuChosen == 2) {
                    isSet = push();
                } else if (menuChosen == 3) {
                    isSet = flush();
                } else {
                    break;
                }

                std::cout << (isSet ? "" : "<Kapasitas tumpukan belum ditentukan>");
            } else {
                invalidMenuChosen(&menuChosen, &invalidIntInput);
            }

            outputBuffer();
        }
    }

    ~StackOneTwo() {
        delete[] stackPointer;
    }
};

#endif