#include "customUtility.hpp"

/*---------------------------------------------------------------------------------------------------------------------------------*/

/*
    Fungsi "normalizeInput" membaca standard input dari pengguna, menggabungkan tiap kata yang terpisah oleh whitespace menjadi 
    sebuah string dengan sebuah spasi di antara tiap kata, dan mengembalikan hasilnya dalam bentuk string terstruktur tanpa trailing space.
*/

std::string normalizeInput() {
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::string fragment;
    std::string normalInput;

    while (iss >> fragment) {
        normalInput += fragment + " ";
    }

    return normalInput.substr(0, normalInput.length() - 1);
}

/*---------------------------------------------------------------------------------------------------------------------------------*/

/*
    Fungsi "inputIntValidator" memvalidasi output dari fungsi "normalizedInput" yang bernilai karakter numerik. Digunakan untuk proses 
    pemilihan menu saat pengguna menjalankan sebuah program.
*/

long inputIntValidator(std::string* invalidIntInputPointer) {
    long inputInt;
    std::string inputString {normalizeInput()};
    
    auto [pointer, errorCode] = std::from_chars(
        inputString.data(),
        inputString.data() + inputString.size(),
        inputInt
    );

    if (errorCode == std::errc{} && pointer == inputString.data() + inputString.size()) {
        *invalidIntInputPointer = inputString;
        return inputInt;
    }

    std::cin.clear();
    *invalidIntInputPointer = inputString;
    return false;
}

/*---------------------------------------------------------------------------------------------------------------------------------*/

/*
    Fungsi "outputBuffer" memberikan jeda dari eksekusi program setelah pengguna memasukkan input  ke dalam standard input. Tujuannya 
    adalah untuk memberikan informasi terkait eksekusi yang baru saja dijalankan oleh program sebelum menuju tahapan selanjutnya, seperti 
    input tidak valid, penambahan data, pengurangan data, penampilan data, dan lain-lain.
*/

void outputBuffer() {
    std::cout << "\nTekan Enter untuk melanjutkan => ";

    std::string buffer;
    std::getline(std::cin, buffer);
    std::cin.clear();
}

/*---------------------------------------------------------------------------------------------------------------------------------*/

/*
    Fungsi "invalidMenuChosen" menginformasikan kepada pengguna terkait input yang tidak valid ketika mengoperasikan program. Berisi 
    serangkaian skenario yang mungkin saja terjadi ketika standard input menerima input yang salah baik secara sengaja maupun tidak disengaja.
*/

void invalidMenuChosen(short* menuChosenPointer, std::string* invalidIntInputPointer) {
    std::string_view invalidInput {*invalidIntInputPointer};

    if (*menuChosenPointer == false && invalidInput != "0" && !invalidInput.empty()) {
        std::cout << "<Input " << '"' << invalidInput << '"' << " tidak valid>";
    } else if (invalidInput.empty()) {
        std::cout << "<Tidak ada input menu yang dimasukan>";
    } else {
        std::cout << "<Input " << '"' << invalidInput << '"' << " di luar pilihan menu>";
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/

/*
    Fungsi "titleCase" bertujuan untuk mengubah output dari fungsi "normalizedInput" dengan mengikuti struktur atau format Title. 
    Digunakan untuk membuat tiap kata diawali huruf kapital.
*/

std::string titleCase() {
    std::string theData {normalizeInput()};

    theData[0] = std::toupper(theData[0]);

    for (size_t i = 1; i < theData.length(); ++i) {
        if (std::isspace(theData[i - 1]) && std::isalpha(theData[i])) {
            theData[i] = std::toupper(theData[i]);
        } else {
            theData[i] = std::tolower(theData[i]);
        }
    }

    return theData;
}

/*---------------------------------------------------------------------------------------------------------------------------------*/

/*
    Fungsi "setCapacityValue" digunakan pada beberapa program yang berurusan dengan tipe data collections dengan kapasitas terbatas atau 
    ditentukan nilainya. Proses abstraksi perlu dilakukan untuk memudahkan tahap pengembangan selanjutnya. Selain itu, dicantumkan pula
    beberapa skenario untuk pencegahan error ketika pengguna ingin melakukan konfigurasi terhadap kapasitas dari data collections.  
*/

void setCapacityValue(bool* isCapacitySetPointer, int* capacityPointer, int* filledCapacityPointer, std::string* invalidIntInputPointer, std::string** collectionPointer) {
    std::cout << "Silakan masukan jumlah kapasitas => ";
    int newCapacity {inputIntValidator(invalidIntInputPointer)};

    if ((newCapacity || (*invalidIntInputPointer == "0" ? true : false)) && (newCapacity >= *filledCapacityPointer)) {
        std::string* preservedStack = new std::string[newCapacity];

        if (*collectionPointer != nullptr) {
            for (size_t i = 0; i < *filledCapacityPointer; i++) {
                preservedStack[i] = (*collectionPointer)[i];
            }

            delete[] *collectionPointer;
        }

        *collectionPointer = preservedStack;
        *capacityPointer = newCapacity;
        *isCapacitySetPointer = true;
        std::cout << "<Kapasitas berhasil ditentukan sebanyak " << '"' << newCapacity << '"' << ">";
    } else if (invalidIntInputPointer->empty()) {
        std::cout << "<Tidak ada jumlah kapasitas yang dimasukan>";
    } else if (newCapacity < 0) {
        std::cout << "<Kapasitas baru tidak dapat bernilai negatif>";
    } else if ((newCapacity - *filledCapacityPointer) < 0) {
        std::cout << "<Kapasitas baru tidak dapat menampung " << *filledCapacityPointer << " data yang sudah ada>";
    } else {
        std::cout << "<Kapasitas tidak dapat ditentukan sebanyak " << '"' << *invalidIntInputPointer << '"' << ">";
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------*/

/*
    INTENDED USAGE FOR THE NEXT METHODS.
*/
