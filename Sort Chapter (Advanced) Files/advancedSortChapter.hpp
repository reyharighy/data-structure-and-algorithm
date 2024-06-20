/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Urutan Tingkat Lanjut (Advanced Sort). Setiap objek 
    kelas yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef SORT_CHAPTER_ADVANCED
#define SORT_CHAPTER_ADVANCED

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan In Place Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveOne: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    std::vector<std::string> arrayString, arrayStringClone {}; // Inisialisasi vector untuk menyimpan data string
    void inPlaceSort(std::vector<long>& array, bool ascending) { // Fungsi untuk mengurutkan data integer secara in-place
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        for (int i = array.size() - 1; i >= 0; i--) {
            int k = i;
            bool swap = false;
            for (int j = 0; j < i; j++) {
                if ((ascending && array[j] > array[k]) || (!ascending && array[j] < array[k])) {
                    k = j;
                    swap = true;
                }
            }
            if (swap) {
                std::swap(array[i], array[k]);
                std::cout << array << " => " << array[i] << " bertukar dengan " << array[k];
            } else {
                std::cout << array << " => Tidak ada pertukaran";
            }
            std::cout << std::endl;
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void inPlaceSortString(std::vector<std::string>& arrayString, bool ascending) { // Fungsi untuk mengurutkan data string secara in-place
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        for (int i = arrayString.size() - 1; i >= 0; i--) {
            int k = i;
            bool swap = false;
            for (int j = 0; j < i; j++) {
                if ((ascending && arrayString[j] > arrayString[k]) || (!ascending && arrayString[j] < arrayString[k])) {
                    k = j;
                    swap = true;
                }
            }
            if (swap) {
                std::swap(arrayString[i], arrayString[k]);
                std::cout << arrayString << " => " << arrayString[i] << " bertukar dengan " << arrayString[k];
            } else {
                std::cout << arrayString << " => Tidak ada pertukaran";
            }
            std::cout << std::endl;
        }
        std::cout << "Data setelah diurutkan: " << arrayString << std::endl;
    }
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Shell Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveTwo: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    std::vector<std::string> arrayString, arrayStringClone {}; // Inisialisasi vector untuk menyimpan data string
    void shellSort(std::vector<long>& array, bool ascending) { // Fungsi untuk mengurutkan data integer menggunakan Shell Sort
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        int gap = 1;
        while (gap < array.size() / 3) {
            gap = 3 * gap + 1; // Menghitung nilai awal gap sesuai dengan rumus 3h + 1
        }
        while (gap > 0) {
            for (int i = gap; i < array.size(); i++) {
                int k = i;
                bool swap = false;
                while (k >= gap && ((ascending && array[k - gap] > array[k]) || (!ascending && array[k - gap] < array[k]))) {
                    std::swap(array[k], array[k - gap]);
                    k -= gap;
                    swap = true;
                }
                if (gap == 1) {
                    std::cout << "gap = " << gap << " : ";
                    for (int j = 0; j < array.size(); j++) {
                        std::cout << array[j];
                        if (j < array.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << array[k] << " pindah ke depan " << array[k + gap];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "gap = " << gap << " : ";
                    for (int j = 0; j < array.size(); j++) {
                        std::cout << array[j];
                        if (j < array.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << array[k + gap] << " bertukar dengan " << array[k];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                }
            }
            gap /= 3;
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }
    
    void shellSortString(std::vector<std::string>& arrayString, bool ascending) { // Fungsi untuk mengurutkan data string menggunakan Shell Sort
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        int gap = 1;
        while (gap < arrayString.size() / 3) {
            gap = 3 * gap + 1; // Menghitung nilai awal gap sesuai dengan rumus 3h + 1
        }
        while (gap > 0) {
            for (int i = gap; i < arrayString.size(); i++) {
                int k = i;
                bool swap = false;
                while (k >= gap && ((ascending && arrayString[k - gap] > arrayString[k]) || (!ascending && arrayString[k - gap] < arrayString[k]))) {
                    std::swap(arrayString[k], arrayString[k - gap]);
                    k -= gap;
                    swap = true;
                }
                if (gap == 1) {
                    std::cout << "gap = " << gap << " : ";
                    for (int j = 0; j < arrayString.size(); j++) {
                        std::cout << arrayString[j];
                        if (j < arrayString.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << arrayString[k] << " pindah ke depan " << arrayString[k + gap];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                } else {
                    std::cout << "gap = " << gap << " : ";
                    for (int j = 0; j < arrayString.size(); j++) {
                        std::cout << arrayString[j];
                        if (j < arrayString.size() - 1) std::cout << " - ";
                    }
                    std::cout << " => ";
                    if (swap) {
                        std::cout << arrayString[k + gap] << " bertukar dengan " << arrayString[k];
                    } else {
                        std::cout << "Tidak ada pertukaran";
                    }
                    std::cout << std::endl;
                }
            }
            gap /= 3;
        }
        std::cout << "Data setelah diurutkan: " << arrayString << std::endl;
    }
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Merge Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveThree: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    std::vector<std::string> arrayString, arrayStringClone {}; // Inisialisasi vector untuk menyimpan data string

    void merge(std::vector<long>& arr, int left, int mid, int right, bool ascending) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<long> L(n1), R(n2);

        std::cout << "Mengambil angka ";

        for (int i = 0; i < n1; ++i) {
            L[i] = arr[left + i];
            std::cout << std::to_string(L[i]) << ", ";
        }
            
        for (int j = 0; j < n2; ++j) {
            R[j] = arr[mid + 1 + j];
            std::cout << std::to_string(R[j]) << ", ";
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (ascending ? (L[i] <= R[j]) : (L[i] >= R[j])) {
                arr[k] = L[i];
                ++i;
            } else {
                arr[k] = R[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            arr[k] = L[i];
            ++i;
            ++k;
        }

        while (j < n2) {
            arr[k] = R[j];
            ++j;
            ++k;
        }

        // Tampilkan langkah-langkah penggabungan
        std::cout << "kemudian diurutkan menjadi: ";
        for (int x = left; x <= right; ++x) {
            std::cout << arr[x];
            if (x < right) std::cout << " - ";
        }
        std::cout << std::endl;
    }

    void mergeSort(std::vector<long>& arr, int left, int right, bool ascending) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid, ascending);
            mergeSort(arr, mid + 1, right, ascending);

            merge(arr, left, mid, right, ascending);
        }
    }

    void mergeString(std::vector<std::string>& arr, int left, int mid, int right, bool ascending) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<std::string> L(n1), R(n2);

        std::cout << "Mengambil karakter/kata ";

        for (int i = 0; i < n1; ++i) {
            L[i] = arr[left + i];
            std::cout << "'" << L[i] << "'" << ", ";
        }
            
        for (int j = 0; j < n2; ++j) {
            R[j] = arr[mid + 1 + j];
            std::cout << "'" << R[j] << "'" << ", ";
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (ascending ? (L[i] <= R[j]) : (L[i] >= R[j])) {
                arr[k] = L[i];
                ++i;
            } else {
                arr[k] = R[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            arr[k] = L[i];
            ++i;
            ++k;
        }

        while (j < n2) {
            arr[k] = R[j];
            ++j;
            ++k;
        }

        // Tampilkan langkah-langkah penggabungan
        std::cout << "kemudian diurutkan menjadi: ";
        for (int x = left; x <= right; ++x) {
            std::cout << arr[x];
            if (x < right) std::cout << " - ";
        }
        std::cout << std::endl;
    }

    void mergeSortString(std::vector<std::string>& arr, int left, int right, bool ascending) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSortString(arr, left, mid, ascending);
            mergeSortString(arr, mid + 1, right, ascending);

            mergeString(arr, left, mid, right, ascending);
        }
    }

    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Quick Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFiveFour: public Program {
private:
    void menuInterface();
    void sort();
    void preview();
    void del();
    void push();
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    std::vector<std::string> arrayString, arrayStringClone {}; // Inisialisasi vector untuk menyimpan data string

    void quickSort(std::vector<long>& arr, int left, int right, bool isAscending) {
        if (left >= right) {
            return;
        }
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            if (isAscending) {
                while (arr[i] < pivot) {
                    i++;
                }
                while (arr[j] > pivot) {
                    j--;
                }
            }
            else {
                while (arr[i] > pivot) {
                    i++;
                }
                while (arr[j] < pivot) {
                    j--;
                }
            }
            

            if (i <= j) {
                std::swap(arr[i], arr[j]);
                
                for (int h = 0; h < arr.size(); h++) {
                    std::cout << arr[h] << " ";
                }
                std::cout << "\n";

                i++;
                j--;
            }
        }

        quickSort(arr, left, j, isAscending);
        quickSort(arr, i, right, isAscending);
    };

    void quickSortString(std::vector<std::string>& arr, int left, int right, bool isAscending) {
        if (left >= right) {
            return;
        }
        std::string pivot = arr[(left + right) / 2];
        int i = left, j = right;

        while (i <= j) {
            if (isAscending) {
                while (arr[i].compare(pivot) < 0) {
                    i++;
                }
                while (arr[j].compare(pivot) > 0) {
                    j--;
                }
            }
            else {
                while (arr[i].compare(pivot) > 0) {
                    i++;
                }
                while (arr[j].compare(pivot) < 0) {
                    j--;
                }
            }
            

            if (i <= j) {
                std::swap(arr[i], arr[j]);
                
                for (int h = 0; h < arr.size(); h++) {
                    std::cout << arr[h] << " ";
                }
                std::cout << "\n";

                i++;
                j--;
            }
        }

        quickSortString(arr, left, j, isAscending);
        quickSortString(arr, i, right, isAscending);
    };
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif