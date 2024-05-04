#ifndef QUEUETWOTWO_H
#define QUEUETWOTWO_H

#include "../mainProgram.hpp"
#include "../Custom Utility Files/customutils.hpp"

class QueueTwoTwo: public Program {
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
                  << "  1. Tentukan kapasitas antrian\n"
                  << "  2. Masukan data baru ke dalam antrian\n  3. Menghapus data di dalam antrian\n"
                  << "  4. Tampilkan data di dalam antrian\n  5. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
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
                bool isLast {true};

                for (size_t i = 0; i < filledCapacity; i++) {
                    if ((theData.compare(arrayPointer[i]) < 0)) {
                        for (size_t j = filledCapacity; j > i; j--) {
                            arrayPointer[j] = arrayPointer[j-1];
                        }

                        arrayPointer[i] = theData;
                        isLast = false;
                        break;
                    }
                }

                if (isLast) {
                    arrayPointer[filledCapacity] = theData;
                }

                filledCapacity++;
                std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
            }
            
            flag = true;
        }

        return flag;
    }

    bool pop(bool flag = false) {
        if (isCapacitySet) {

            flag = true;
        }

        return flag;
    }

    bool display(bool flag = false) {
        if (isCapacitySet) {
            std::cout << "\nIsi antrian:\n";

            for (size_t i = 0; i < filledCapacity; i++) {
                std::cout << arrayPointer[i];

                if (i != (filledCapacity - 1)) {
                    std::cout << " - ";
                }
            }

            std::cout << std::endl;
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

            if (menuChosen >= 1 && menuChosen <= 5) {
                if (menuChosen == 1) {
                    setCapacityValue(&isCapacitySet, &capacity, &filledCapacity, &invalidIntInput, &arrayPointer);
                } else if (menuChosen == 2) {
                    isSet = push();
                } else if (menuChosen == 3) {
                    isSet = pop();
                } else if (menuChosen == 4) {
                    isSet = display();
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

    ~QueueTwoTwo() {
        delete[] arrayPointer;
    }
};

#endif