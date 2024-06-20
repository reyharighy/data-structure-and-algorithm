/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "stackChapter.hpp" untuk tugas dengan nama
    Implementasi Antrian dengan Array Terbatas dan Proses Penyisipan Data.
*/

#include "queueChapter.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Fungsi "menuInterface" bertujuan untuk menampilkan daftar proses pengoperasian atau manipulasi yang bisa dilakukan
    terhadap data dalam lingkup dari program yang ditentukan.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoTwo::menuInterface() {
    std::cout << "\nKapasitas antrian = " << (isCapacitySet ? std::to_string(capacity) : "<Belum ditentukan>")
              << "\nAntrian terisi = " << (isCapacitySet ? std::to_string(filledCapacity) : "<Tidak terdefinisi>")
              << "\n\nPilih menu untuk pengoperasian pada antrian:\n"
              << "  1. Tentukan kapasitas antrian\n"
              << "  2. Masukkan data baru ke dalam antrian\n  3. Menghapus data di dalam antrian\n"
              << "  4. Tampilkan data di dalam antrian\n  5. Lihat Program-program lain\n\nMasukan angka pilihan menu => ";
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Fungsi "push" bertujuan untuk menyisipkan data baru ke dalam tipe data collections sesuai urutan abjad yang disertai dengan 
    beberapa skenario error handling sesuai dengan prasyarat yang ditentukan di dalam program.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoTwo::push() {
    if (isCapacitySet) { // Kapasitas harus ditentukan dahulu sebelum penambahan data
        std::cout << "Masukkan data baru pada antrian => ";
        std::string theData {titleCase()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"

        if (filledCapacity == capacity) { // Data baru tidak dapat ditambahkan jika kapasitas sudah penuh
            std::cout << "<Antrian sudah penuh. " << '"' << theData << '"' << " tidak dimasukan>";
        } else if (theData.empty()) { // Data baru tidak valid jika input kosong
            std::cout << "<Data yang dimasukan tidak boleh kosong>";
        } else {
            bool isLast {true}; // Menentukan apakah data yang dimasukkan merupakan data terakhir di dalam antrian

            for (size_t i = 0; i < filledCapacity; i++) { // Menyisipkan data baru sesuai urutan abjad
                if ((theData.compare(arrayPointer[i]) < 0)) {
                    for (size_t j = filledCapacity; j > i; j--) { // Menggeser data ke kanan untuk menyisipkan data baru
                        arrayPointer[j] = arrayPointer[j - 1];
                    }

                    arrayPointer[i] = theData;
                    isLast = false; // Data yang dimasukkan bukan merupakan data terakhir
                    break;
                }
            }

            if (isLast) { // Data yang dimasukkan merupakan data terakhir di dalam antrian
                arrayPointer[filledCapacity] = theData;
            }

            filledCapacity++; // Menambahkan jumlah data yang ada di dalam antrian
            std::cout << "<Data " << '"' << theData << '"' << " berhasil ditambahkan>";
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Fungsi "pop" bertujuan untuk mengeluarkan sebuah data di dalam tipe data collections.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoTwo::pop() {
    if (isCapacitySet) { // Kapasitas harus ditentukan dahulu sebelum penambahan data
        if (filledCapacity) { // Jika ada data, maka proses pengeluaran data dilanjutkan
            std::cout << "Masukkan data yang ingin dikeluarkan => ";
            std::string theData {titleCase()}; // Akses ke fungsi PART 5 dari "customUtility.hpp"
            bool theDataExisted {false}; // Menentukan apakah data yang diminta ada di dalam antrian
            bool isLast; // Menentukan apakah data yang diminta merupakan data terakhir di dalam antrian

            for (size_t i = 0; i < filledCapacity; i++) { // Mengeluarkan data yang diminta dari antrian
                if (theData == arrayPointer[i]) { // Data yang diminta ditemukan
                    isLast = (i == (filledCapacity - 1)) ? true : false; // Cek jika kata yang diminta merupakan data terakhir di dalam antrian

                    if (isLast) { // Langsung hapus data jika kata yang diminta merupakan data terakhir di dalam antrian
                        arrayPointer[i].clear();
                    } else { // Geser data ke kiri untuk menghapus data yang diminta jika bukan terakhir
                        for (size_t j = i; j < filledCapacity - 1; j++) {
                            arrayPointer[j] = arrayPointer[j + 1];
                        }

                        arrayPointer[filledCapacity - 1].clear(); // Hapus data terakhir yang sudah digeser
                    }

                    filledCapacity--; // Mengurangi jumlah data yang ada di dalam antrian
                    theDataExisted = true; // Data yang diminta ada di dalam antrian
                    break;
                }
            }

        /*--------------------------------------------------------------------------------------------------------------------------------
            PART 3.1: Umpan balik kepada pengguna apakah proses pengeluaran berhasil atau tidak yang disertai dengan berbagai skenario.
        --------------------------------------------------------------------------------------------------------------------------------*/

            if (theDataExisted) { // Data yang diminta berhasil dikeluarkan dari antrian
                std::cout << "<Data " << '"' << theData << '"' << " berhasil dikeluarkan dari antrian>";
            } else if (theData.empty()) { // Data yang diminta kosong
                std::cout << "<Data yang diminta tidak boleh kosong>";
            } else { // Data yang diminta tidak ada di dalam antrian
                std::cout << "<Data " << '"' << theData << '"' << " tidak ada di dalam antrian>";
            }
        } else { // Tidak ada data yang bisa dikeluarkan jika antrian kosong
            std::cout << "<Antrian tidak menyimpan data>";
        }

        /*--------------------------------------------------------------------------------------------------------------------------------
            END OF SCOPE FOR PART 3.1.
        --------------------------------------------------------------------------------------------------------------------------------*/
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Fungsi "display" bertujuan untuk menampilkan seluruh data tersimpan di dalam tipe data collections ke standard output.
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoTwo::display() {
    if (isCapacitySet) { // Kapasitas harus ditentukan sebelum melakukan proses penampilkan
        if (filledCapacity) { // Jika ada data, maka proses penampilan data dilanjutkan
            std::cout << "\nIsi antrian:\n";
            
            for (size_t i = 0; i < filledCapacity; i++) { // Menampilkan data yang ada di dalam antrian
                std::cout << arrayPointer[i];

                if (i != (filledCapacity - 1)) { // Jika data yang ditampilkan bukan merupakan data terakhir, maka tambahkan pemisah
                    std::cout << " - ";
                }
            }

            std::cout << std::endl;
        } else {
            std::cout << "<Antrian tidak menyimpan data>";
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 5: Fungsi "start" adalah implementasi metode polymorphism untuk menjalankan program sesuai dengan logis yang ditampilkan
    oleh standard output dari "menuInterface".
----------------------------------------------------------------------------------------------------------------------------------------*/

void QueueTwoTwo::start() {
    while (true) {
        menuInterface();
        short menuChosen {short(inputIntValidator(&invalidIntInput))}; // Akses ke fungsi PART 2 dari "customUtility.hpp"

        if (menuChosen >= 1 && menuChosen <= 5) {
            if (menuChosen == 1) {
                setCapacityValue(&isCapacitySet, &capacity, &filledCapacity, &invalidIntInput, &arrayPointer); // Akses ke fungsi PART 6 dari "customUtility.hpp" 
            } else if (menuChosen == 2) {
                push(); // Akses ke fungsi PART 2 dari "queueTwoTwo.cpp"
            } else if (menuChosen == 3) {
                pop(); // Akses ke fungsi PART 3 dari "queueTwoTwo.cpp" 
            } else if (menuChosen == 4) {
                display(); // Akses ke fungsi PART 4 dari "queueTwoTwo.cpp"
            } else {
                break;
            }

            std::cout << (isCapacitySet ? "" : "<Kapasitas antrian belum ditentukan>");
        } else {
            invalidMenuChosen(&menuChosen, &invalidIntInput); // Akses ke fungsi PART 4 dari "customUtility.hpp"
        }

        outputBuffer(); // Akses ke fungsi PART 3 dari "customUtility.hpp"
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 5.
----------------------------------------------------------------------------------------------------------------------------------------*/

QueueTwoTwo::~QueueTwoTwo() { // Destructor untuk mencegah memory leaks
    delete[] arrayPointer;
}
