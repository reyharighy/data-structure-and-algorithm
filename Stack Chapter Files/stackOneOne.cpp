/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "stackChapter.hpp" untuk tugas dengan nama
    Konversi Bilangan Biner Bilangan Basis Lain.
*/

#include "stackChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneOne::menuInterface() {
    std::cout << "\nBilangan Desimal = " << (isDecimalSet ? std::to_string(decimalValue) : "<Belum ditentukan>")
              << "\n\nPilih basis bilangan untuk konversi bilangan desimal di atas:\n"
              << "  1. Tentukan Bilangan Desimal Baru\n  2. Konversi ke Bilangan Biner\n" \
              << "  3. Konversi ke Bilangan Oktal\n  4. Konversi ke Bilangan Heksadesimal\n" 
              << "  5. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "setDecimalValue" bertujuan untuk menentukan nilai desimal yang akan dimanipulasi ke basis bilangan lain.
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneOne::setDecimalValue() {
    while (true) {
        std::cout << "Silakan masukkan bilangan desimal => ";
        long newDecimal {inputIntValidator(&invalidIntInput)}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (newDecimal || (invalidIntInput == "0" ? true : false)) { // Jika nilai desimal bernilai valid
            decimalValue = newDecimal;
            std::cout << "<Bilangan desimal berhasil ditentukan menjadi " << '"' << std::to_string(newDecimal) << '"' << ">";
            break;
        } else if (invalidIntInput.empty()) { // Jika tidak ada input, maka nilai desimal tidak valid
            std::cout << "<Tidak ada bilangan desimal yang dimasukan>";
        } else { // Nilai desimal tidak valid
            std::cout << "<Input " << '"' << invalidIntInput << '"' << " bukan bilangan desimal>";
        }
    }

    isDecimalSet = true;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.    
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "calculateConversion" bertujuan untuk melakukan konversi terhadap nilai desimal menjadi bilangan basis lain sesuai
    dengan pilihan yang ditentukan.    
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneOne::calculateConversion(const short denominator) {
    std::string resultPrompt = denominator == 2 ? "\nBilangan Biner = 0b" : denominator == 8 ? "\nBilangan Oktal = 0o" : "\nBilangan Heksadesimal = 0x";

    /*---------------------------------------------------------------------------------------------------------------------------------------
        PART 3.1: Sebelum melakukan konversi, nilai desimal harus ditentukan terlebih dahulu. Jika tidak, maka proses tidak dapat dijalankan.
    ---------------------------------------------------------------------------------------------------------------------------------------*/

    if (isDecimalSet) {
        if (decimalValue) { // Jika nilai yang ditentukan selain nol
            long divisionFloor = decimalValue;

            while (true) { // Proses pembagian secara rekursif hingga tidak ada nilai sisa
                short remainder = divisionFloor % denominator;
                divisionFloor = divisionFloor / denominator;
                
                stack.push_back(remainder);

                if (divisionFloor == 0) { // Jika nilai sisa lebih kecil dari denominator
                    std::cout << "\nBilangan Desimal = " << decimalValue << resultPrompt;

                    while (!stack.empty()) {
                        if (denominator != 16) { // Jika bilangan basis lain yang dituju selain heksadesimal 
                            std::cout << stack.back();
                        } else {
                            if (stack.back() > 9) { // Jika hasil bagi bernilai lebih dari 9 
                                std::cout << hexadecimalAlpha[stack.back()];
                            } else {
                                std::cout << stack.back();
                            }
                        }
                        
                        stack.pop_back();
                    }

                    std::cout << std::endl;
                    break;
                }
            }
        } else {
            std::cout << "Bilangan Desimal = 0" << resultPrompt << "0";
        }
    
    /*---------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 3.1.
    ---------------------------------------------------------------------------------------------------------------------------------------*/

    } else {
        std::cout << "<Bilangan desimal belum ditentukan>";
    }   
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void StackOneOne::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 5) {
            if (menuChosen == 1) {
                setDecimalValue(); // Akses ke fungsi PART 6 dari "customUtility.hpp"
            } else if (menuChosen == 2) {
                calculateConversion(2); // Konversi ke bilangan biner
            } else if (menuChosen == 3) {
                calculateConversion(8); // Konversi ke bilangan oktal
            } else if (menuChosen == 4) {
                calculateConversion(16); // Konversi ke bilangan heksadesimal
            } else {
                break;
            }
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }

        outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/
