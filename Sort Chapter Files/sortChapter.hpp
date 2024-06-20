/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Urutan (Sort). Setiap objek kelas 
    yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef SORT_CHAPTER
#define SORT_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Bubble Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourOne: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    std::vector<std::string> arrayString, arrayStringClone {}; // Inisialisasi vector untuk menyimpan data string
    void bubbleSort(std::vector<long>& array, bool ascending) { // Metode untuk mengurutkan data integer menggunakan Bubble Sort
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        bool swapped;
        for (int i = 0; i < array.size() - 1; i++) {
            swapped = false;
            for (int j = 0; j < array.size() - i - 1; j++) {
                if ((ascending && array[j] > array[j + 1]) || (!ascending && array[j] < array[j + 1])) {
                    std::cout << array << " => " << array[j] << " bertukar dengan " << array[j + 1] << std::endl;
                    std::swap(array[j], array[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void bubbleSortString(std::vector<std::string>& arrayString, bool ascending) { // Metode untuk mengurutkan data string menggunakan Bubble Sort
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        bool swapped;
        for (int i = 0; i < arrayString.size() - 1; i++) {
            swapped = false;
            for (int j = 0; j < arrayString.size() - i - 1; j++) {
                if ((ascending && arrayString[j] > arrayString[j + 1]) || (!ascending && arrayString[j] < arrayString[j + 1])) {
                    std::cout << arrayString << " => " << arrayString[j] << " bertukar dengan " << arrayString[j + 1] << std::endl;
                    std::swap(arrayString[j], arrayString[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
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
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Insertion Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourTwo: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {}; // Inisialisasi vector untuk menyimpan data integer
    std::vector<std::string> arrayString, arrayStringClone {}; // Inisialisasi vector untuk menyimpan data string
    void insertionSort(std::vector<long>& array, bool ascending) { // Metode untuk mengurutkan data integer menggunakan Insertion Sort
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        for (int i = 1; i < array.size(); i++) {
            long k = array[i];
            int j = i - 1;

            while (j >= 0 && ((ascending && k < array[j]) || (!ascending && k > array[j]))) {
                array[j + 1] = array[j];
                j--;
            } 
            array[j + 1] = k;
            std::cout << array << " => " << k << " ke posisi " << j+2 << std::endl;
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void insertionSortString(std::vector<std::string>& arrayString, bool ascending) { // Metode untuk mengurutkan data string menggunakan Insertion Sort
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        for (int i = 1; i < arrayString.size(); i++) {
            std::string k = arrayString[i];
            int j = i - 1;

            while (j >= 0 && ((ascending && k < arrayString[j]) || (!ascending && k > arrayString[j]))) {
                arrayString[j + 1] = arrayString[j];
                j--;
            } 
            arrayString[j + 1] = k;
            std::cout << arrayString << " => " << k << " ke posisi " << j+2 << std::endl;
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
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Selection Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourThree: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {};
    std::vector<std::string> arrayString, arrayStringClone {};
    void selectionSort(std::vector<long>& array, bool ascending) { // Metode untuk mengurutkan data integer menggunakan Selection Sort
        std::cout << "Data sebelum diurutkan: " << array << std::endl;
        for (int i = 0; i < array.size(); i++) {
            int k = i;
            for (int j = i + 1; j < array.size(); j++) {
                if ((ascending && array[k] > array[j]) || (!ascending && array[k] < array[j])) {
                    k = j;
                }
            }
            if (i != k) {
                std::swap(array[i], array[k]);
                std::cout << array << " => " << array[i] << " bertukar dengan " << array[k] << std::endl;
            }
        }
        std::cout << "Data setelah diurutkan: " << array << std::endl;
    }

    void selectionSortString(std::vector<std::string>& arrayString, bool ascending) { // Metode untuk mengurutkan data string menggunakan Selection Sort
        std::cout << "Data sebelum diurutkan: " << arrayString << std::endl;
        for (int i = 0; i < arrayString.size(); i++) { 
            int k = i;
            for (int j = i + 1; j < arrayString.size(); j++) {
                if ((ascending && arrayString[k] > arrayString[j]) || (!ascending && arrayString[k] < arrayString[j])) {
                    k = j;
                }
            }
            if (i != k) {
                std::swap(arrayString[i], arrayString[k]);
                std::cout << arrayString << " => " << arrayString[i] << " bertukar dengan " << arrayString[k] << std::endl;
            }
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
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas Pre-order, In-order, dan Post-order Traversal pada Pohon Biner.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourFour: public Program {
private:
    std::string invalidIntInput;
    class Node { // Deklarasi kelas Node untuk Pohon Biner
    public:
        int data;
        Node *left, *right; // Pointer untuk menunjuk ke Node kiri dan kanan
        Node(int input) : data(input), left(nullptr), right(nullptr) {} // Konstruktor untuk Node
    };

    class BST {
    private:
        Node* root; // Pointer untuk menunjuk ke Node root

        Node* insert(Node* node, int input) { // Metode untuk memasukkan data ke dalam Pohon Biner
            if (node == nullptr) { // Jika Node kosong, maka buat Node baru
                return new Node(input);
            }

            if (input < node->data) { // Jika data yang dimasukkan lebih kecil dari data Node saat ini, maka masukkan ke Node kiri
                node->left = insert(node->left, input);
            } else if (input > node->data) { // Jika data yang dimasukkan lebih besar dari data Node saat ini, maka masukkan ke Node kanan
                node->right = insert(node->right, input);
            }

            return node;
        }

        void preOrder(Node* node) { // Metode untuk menampilkan data Pre-order pada Pohon Biner
            if (node != nullptr) {
                std::cout << node->data << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }

        void inOrder(Node* node) { // Metode untuk menampilkan data In-order pada Pohon Biner
            if (node != nullptr) {
                inOrder(node->left);
                std::cout << node->data << " ";
                inOrder(node->right);
            }
        }

        void postOrder(Node* node) { // Metode untuk menampilkan data Post-order pada Pohon Biner
            if (node != nullptr) {
                postOrder(node->left);
                postOrder(node->right);
                std::cout << node->data << " ";
            }
        }

        void deleteTree(Node* node) { // Metode untuk menghapus seluruh Node pada Pohon Biner
            if (node == nullptr) {
                return;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }

        void printTree(Node* node, int space, bool isRight) { // Metode untuk menampilkan Pohon Biner secara visual
            if (node == nullptr) {
                return;
            }
            space += 1; // Menambahkan spasi
            printTree(node->right, space, true); // Menampilkan Node kanan
            std::cout << std::endl;
            for (int i = 1; i < space; i++) { // Menampilkan spasi
                std::cout << "    ";
            }
            if (isRight) {
                std::cout << "/--";
            } else if (space > 1){
                std::cout << "\\--";
            }
            std::cout << node->data; // Menampilkan data Node
            printTree(node->left, space, false); // Menampilkan Node kiri
        }

    public:
        BST() : root(nullptr) {} // Konstruktor untuk Pohon Biner

        void insert(int input) { // Metode untuk memasukkan data ke dalam Pohon Biner
            root = insert(root, input);
        }

        void deleteAll() { // Metode untuk menghapus seluruh Node pada Pohon Biner
            deleteTree(root);
            root = nullptr;
        }

        void printLevelOrder() { // Metode untuk menampilkan Pohon Biner secara visual
            printTree(root, 0, 0);
            std::cout << std::endl;
        }

        void preOrder() { // Metode untuk menampilkan data Pre-order pada Pohon Biner
            preOrder(root);
            std::cout << std::endl;
        }

        void inOrder() { // Metode untuk menampilkan data In-order pada Pohon Biner
            inOrder(root);
            std::cout << std::endl;
        }

        void postOrder() { // Metode untuk menampilkan data Post-order pada Pohon Biner
            postOrder(root);
            std::cout << std::endl;
        }
    };
    BST tree;
    void menuInterface();
    void print();
    void push();
    void pre();
    void in();
    void post();
    void del();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif