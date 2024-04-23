#ifndef QUEUETWOONE_H
#define QUEUETWOONE_H

#include "../mainProgram.hpp"
#include "../Custom Utility Files/customutils.hpp"

class QueueTwoOne: public Program {
private:
    bool isCapacitySet {false};
    int capacity {0};
    int filledCapacity {0};
    std::string invalidIntInput;
    std::string* arrayPointer = nullptr;

    void menuInterface() {
        std::cout << "\nKapasitas antrian = " << (isCapacitySet ? std::to_string(capacity) : "<Belum ditentukan>")
                  << "\nAntrian terisi = " << (isCapacitySet ? std::to_string(filledCapacity) : "<Tidak terdefinisi>")
                  << "\n\nPilih menu untuk pengoperasian pada antrian:\n"
                  << "  1. Tentukan kapasitas antrian\n  2. Masukan data baru ke dalam antrian\n  3. Kosongkan antrian\n"
                  << "  4. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
    }

    bool push(bool flag = false) {
        if (isCapacitySet) {
            std::cout << "Masukan data baru pada antrian => ";
            std::string theData {titleCase()};

            if (filledCapacity == capacity) {
               std::cout << "<Antrian sudah penuh. " << '"' << theData << '"' << " tidak dimasukan>";
            } else if (theData.empty()) {
                std::cout << "<Tidak ada data baru yang dimasukan>";
            } else {
                arrayPointer[filledCapacity] = theData;
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
                std::cout << "\nIsi antrian:\n";

                for (size_t i = 0; i < filledCapacity; i++) {
                    std::cout << arrayPointer[i];

                    if (i < filledCapacity) {
                        std::cout << std::endl;
                    }

                    arrayPointer[i].clear();
                }

                filledCapacity = 0;
            } else {
                std::cout << "<Antrian tidak menyimpan data>";
            }

            flag = true;
        }

        return flag;
    }

public:
    void start() {
        while (true) {
            bool isSet {true};
            menuInterface();
            short menuChosen {short(inputIntValidator(&invalidIntInput))};

            if (menuChosen >= 1 && menuChosen <= 4) {
                if (menuChosen == 1) {
                    setCapacityValue(&isCapacitySet, &capacity, &filledCapacity, &invalidIntInput, &arrayPointer);
                } else if (menuChosen == 2) {
                    isSet = push();
                } else if (menuChosen == 3) {
                    isSet = flush();
                } else {
                    break;
                }

                std::cout << (isSet ? "" : "<Kapasitas antrian belum ditentukan>");
            } else {
                invalidMenuChosen(&menuChosen, &invalidIntInput);
            }

            outputBuffer();
        }
    }

    ~QueueTwoOne() {
        delete[] arrayPointer;
    }
};

#endif