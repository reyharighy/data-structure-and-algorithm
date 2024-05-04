#ifndef STACKONEONE_H
#define STACKONEONE_H

#include "../mainProgram.hpp"
#include "../Custom Utility Files/customutils.hpp"
#include <charconv>
#include <vector>
#include <map>

class StackOneOne: public Program {
private:
    std::string invalidIntInput;
    long decimalValue;
    bool isDecimalSet {false};
    std::vector<short> stack {};
    std::map<short, std::string> hexadecimalAlpha {{10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}};

    void menuInterface() {
        std::cout << "\nBilangan Desimal = " << (isDecimalSet ? std::to_string(decimalValue) : "<Belum ditentukan>")
                  << "\n\nPilih basis bilangan untuk konversi bilangan desimal di atas:\n"
                  << "  1. Tentukan Bilangan Desimal Baru\n  2. Konversi ke Bilangan Biner\n" 
                  << "  3. Konversi ke Bilangan Oktal\n  4. Konversi ke Bilangan Heksadesimal\n" 
                  << "  5. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
    }

    void setDecimalValue() {
        while (true) {
            std::cout << "Silakan masukan bilangan desimal => ";

            
            long newDecimal {inputIntValidator(&invalidIntInput)};

            if (newDecimal || (invalidIntInput == "0" ? true : false)) {
                decimalValue = newDecimal;
                std::cout << "<Bilangan desimal berhasil ditentukan menjadi " << '"' << std::to_string(newDecimal) << '"' << ">";
                break;
            } else if (invalidIntInput.empty()) {
                std::cout << "<Tidak ada bilangan desimal yang dimasukan>";
            } else {
                std::cout << "<Input " << '"' << invalidIntInput << '"' << " bukan bilangan desimal>";
            }
        }

        isDecimalSet = true;
    }

    void calculateConversion(short denominator) {
        std::string resultPrompt = denominator == 2 ? "\nBilangan Biner = 0b" : denominator == 8 ? "\nBilangan Oktal = 0o" : "\nBilangan Heksadesimal = 0x";

        if (isDecimalSet) {
            if (decimalValue) {
                long divisionFloor = decimalValue;

                while (true) {
                    short remainder = divisionFloor % denominator;
                    divisionFloor = divisionFloor / denominator;

                    stack.push_back(remainder);

                    if (divisionFloor == 0) {
                        std::cout << "Bilangan Desimal = " << decimalValue << resultPrompt;

                        while (!stack.empty()) {
                            if (denominator != 16) {
                                std::cout << stack.back();    
                            } else {
                                if (stack.back() > 9) {
                                    std::cout << hexadecimalAlpha[stack.back()];
                                } else {
                                    std::cout << stack.back();
                                }
                            }
                            
                            stack.pop_back();
                        }
                        break;
                    }
                }
            } else {
                std::cout << "Bilangan Desimal = 0" << resultPrompt << "0";
            }
        } else {
            std::cout << "<Bilangan desimal belum ditentukan>";
        }
    }

public:
    void start() override {
        while (true) {
            menuInterface();
            short menuChosen {short(inputIntValidator(&invalidIntInput))};

            if (menuChosen >= 1 && menuChosen <= 5) {
                if (menuChosen == 1) {
                    setDecimalValue();
                } else if (menuChosen == 2) {
                    calculateConversion(2);
                } else if (menuChosen == 3) {
                    calculateConversion(8);
                } else if (menuChosen == 4) {
                    calculateConversion(16);
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