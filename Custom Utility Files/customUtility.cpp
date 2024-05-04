/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "customUtility.hpp".
*/

#include "customUtility.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "normalizeInput" membaca standard input dari pengguna, menggabungkan tiap kata yang terpisah oleh whitespace menjadi 
    sebuah string dengan sebuah spasi di antara tiap kata, dan mengembalikan hasilnya dalam bentuk string terstruktur tanpa trailing space.
----------------------------------------------------------------------------------------------------------------------------------------*/

std::string normalizeInput() {
    std::string input;
    std::getline(std::cin, input);

    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 1.1: Membagi standard input menjadi beberapa pecahan kata dan memasukkannya ke variabel "normalInput" sehingga standard
        input menjadi lebih terstruktur dan memudahkan proses pengoperasian atau manipulasi lanjutan.
    ------------------------------------------------------------------------------------------------------------------------------------*/
    
    std::istringstream iss(input);
    std::string fragment;
    std::string normalInput;

    while (iss >> fragment) { // Proses pemasukan tiap fragment ke dalam variabel "normalInput"
        normalInput += fragment + " ";
    }

    return normalInput.substr(0, normalInput.length() - 1); // Meniadakan spasi terakhir

    /*------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPRE FOR PART 1.1.
    ------------------------------------------------------------------------------------------------------------------------------------*/
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "inputIntValidator" memvalidasi output dari fungsi "normalizedInput" dengan ekspektasi berupa karakter numerik saja. 
    Digunakan untuk berbagai proses lanjutan dengan antisipasi kesalahan input dari pengguna baik disengaja maupun tidak.
----------------------------------------------------------------------------------------------------------------------------------------*/

long inputIntValidator(std::string* invalidIntInputPointer) {
    long inputInt;
    std::string inputString {normalizeInput()};
    
    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 2.1: Mengonversi tiap karakter di dalam standard input secara berurut.
    ------------------------------------------------------------------------------------------------------------------------------------*/
    
    auto [pointer, errorCode] = std::from_chars( // pointer menyimpan karakter pertama non-numerik yang ditemukan
        inputString.data(),                      // errorCode akan bernilai nol jika tidak ada hasil konversi yang gagal
        inputString.data() + inputString.size(),
        inputInt
    );

    /*------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 2.1.
    ------------------------------------------------------------------------------------------------------------------------------------*/

    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 2.2: Jika hasil konversi dari PART 2.1. tidak ada karakter non-numerik, maka data pembalikan adalah karakter numerik yang 
        akan digunakan untuk proses selanjutnya yang memerlukan tipe data numerik.
    ------------------------------------------------------------------------------------------------------------------------------------*/
    
    if (errorCode == std::errc{} && pointer == inputString.data() + inputString.size()) {
        *invalidIntInputPointer = inputString;
        return inputInt;
    }

    /*------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 2.2.
    ------------------------------------------------------------------------------------------------------------------------------------*/

    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 2.3: Jika ada karakter non-numerik, maka data pembalikan akan memberitahukan bahwa standar input pengguna tidak valid.
        Proses selanjutnya akan terjadi melibatkan fungsi PART 4 dan 6, yaitu "invalidMenuChosen" dan "setCapacityValue".
    ------------------------------------------------------------------------------------------------------------------------------------*/
    
    std::cin.clear();
    *invalidIntInputPointer = inputString;
    return false;

    /*------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 2.3.
    ------------------------------------------------------------------------------------------------------------------------------------*/
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "outputBuffer" memberikan jeda dari eksekusi program setelah pengguna memasukkan input ke dalam standard input. 
    Tujuannya adalah untuk memberikan informasi terkait eksekusi yang baru saja dijalankan oleh program sebelum menuju tahapan selanjutnya, 
    seperti input tidak valid, penambahan data, pengurangan data, penampilan data, dan lain-lain.
----------------------------------------------------------------------------------------------------------------------------------------*/

void outputBuffer() {
    std::cout << "\nTekan Enter untuk melanjutkan => ";

    std::string buffer;
    std::getline(std::cin, buffer);
    std::cin.clear();
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "invalidMenuChosen" menginformasikan kepada pengguna terkait input yang tidak valid ketika mengoperasikan program. 
    Berisi serangkaian skenario yang mungkin saja terjadi ketika standard input menerima input yang salah baik secara sengaja maupun 
    tidak disengaja. Input yang dimaksud adalah data pembalikan dari fungsi PART 2, yaitu "inputIntValidator".
----------------------------------------------------------------------------------------------------------------------------------------*/

void invalidMenuChosen(short* menuChosenPointer, std::string* invalidIntInputPointer) {
    std::string_view invalidInput {*invalidIntInputPointer};

    if (*menuChosenPointer == false && invalidInput != "0" && !invalidInput.empty()) {
        std::cout << "<Input " << '"' << invalidInput << '"' << " tidak valid>";
    } else if (invalidInput.empty()) { // Input yang dimasukkan tidak boleh kosong
        std::cout << "<Input menu yang diminta tidak boleh kosong>";
    } else { // Error handling khusus untuk input numerik di luar dari jangkauan yang diminta
        std::cout << "<Input " << '"' << invalidInput << '"' << " di luar pilihan menu>";
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Fungsi "titleCase" bertujuan untuk mengubah output dari fungsi "normalizedInput" dengan mengikuti struktur atau format Title.
    Digunakan untuk membuat tiap kata diawali huruf kapital dan selain daripada itu akan menjadi huruf kecil.
----------------------------------------------------------------------------------------------------------------------------------------*/

std::string titleCase() {
    std::string theData {normalizeInput()};

    theData[0] = std::toupper(theData[0]); // Mengubah hurup pertama dari standard input menjadi kapital

    for (size_t i = 1; i < theData.length(); ++i) {
        theData[i] = (std::isspace(theData[i - 1]) && std::isalpha(theData[i])) ? std::toupper(theData[i]) : std::tolower(theData[i]);
    }

    return theData;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 6: Fungsi "setCapacityValue" digunakan pada beberapa program yang berurusan dengan tipe data collections dengan kapasitas terbatas 
    atau ditentukan nilainya. Selain itu, dicantumkan pula beberapa skenario untuk pencegahan error ketika pengguna ingin melakukan 
    konfigurasi terhadap kapasitas dari data collections.  
----------------------------------------------------------------------------------------------------------------------------------------*/

void setCapacityValue(bool* isCapacitySetPointer, int* capacityPointer, int* filledCapacityPointer, std::string* invalidIntInputPointer, std::string** collectionPointer) {
    std::cout << "Silakan masukan jumlah kapasitas => ";
    int newCapacity {inputIntValidator(&*invalidIntInputPointer)};

    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 6.1: Jika data pembalikan dari fungsi PART 2 ("inputIntValidator") bernilai valid, maka data tersebut akan digunakan untuk
        memanipulasi nilai kapasitas dari tipe data collection yang akan dimanipulasi.
    ------------------------------------------------------------------------------------------------------------------------------------*/

    if ((newCapacity || (*invalidIntInputPointer == "0" ? true : false)) && (newCapacity >= *filledCapacityPointer)) {
        std::string* preservedStack = new std::string[newCapacity];

        if (*collectionPointer != nullptr) { // Menentukan kapasitas baru jika kapasitas sudah ditentukan sebelumnya
            for (size_t i = 0; i < *filledCapacityPointer; i++) {
                preservedStack[i] = (*collectionPointer)[i];
            }

            delete[] *collectionPointer; // Mencegah memory leaks
        }

        *collectionPointer = preservedStack;
        *capacityPointer = newCapacity;
        *isCapacitySetPointer = true;
        std::cout << "<Kapasitas berhasil ditentukan sebanyak " << '"' << newCapacity << '"' << ">";

    /*------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 6.1.
    ------------------------------------------------------------------------------------------------------------------------------------*/

    /*------------------------------------------------------------------------------------------------------------------------------------
        PART 6.2: Jika data pembalikan dari fungsi PART 2 ("inputIntValidator") tidak valid, maka data tersebut akan digunakan untuk
        menginformasikan kepada pengguna mengenai skenario kesalahan yang terjadi.
    ------------------------------------------------------------------------------------------------------------------------------------*/

    } else if (invalidIntInputPointer->empty()) {
        std::cout << "<Jumlah kapasitas yang diminta tidak boleh kosong>";
    } else if (newCapacity < 0) {
        std::cout << "<Kapasitas baru tidak dapat bernilai negatif>";
    } else if ((newCapacity - *filledCapacityPointer) < 0) {
        std::cout << "<Kapasitas baru tidak dapat menampung " << *filledCapacityPointer << " data yang sudah ada>";
    } else {
        std::cout << "<Kapasitas tidak dapat ditentukan sebanyak " << '"' << *invalidIntInputPointer << '"' << ">";
    }

    /*------------------------------------------------------------------------------------------------------------------------------------
        END OF SCOPE FOR PART 6.2.
    ------------------------------------------------------------------------------------------------------------------------------------*/
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 6.
----------------------------------------------------------------------------------------------------------------------------------------*/
