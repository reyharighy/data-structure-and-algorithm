#include "customutils.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <charconv>

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

void outputBuffer() {
    std::cout << "\nTekan Enter untuk melanjutkan => ";

    std::string buffer;
    std::getline(std::cin, buffer);
    std::cin.clear();
}

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