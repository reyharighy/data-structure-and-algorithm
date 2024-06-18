/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Urutan (Sort). Setiap objek kelas 
    yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef SORT_CHAPTER
#define SORT_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& output, const std::vector<T>& array)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        output << array[i];
        if (i != array.size() - 1)
        {
            output << " - ";
        }
    }
    return output;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Bubble Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourOne: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array, arrayClone {};
    std::vector<std::string> arrayString, arrayStringClone {};
    void bubbleSort(std::vector<long>& array, bool ascending) {
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

    void bubbleSortString(std::vector<std::string>& arrayString, bool ascending) {
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
    std::vector<long> array, arrayClone {};
    std::vector<std::string> arrayString, arrayStringClone {};
    void insertionSort(std::vector<long>& array, bool ascending) {
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

    void insertionSortString(std::vector<std::string>& arrayString, bool ascending) {
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
    void selectionSort(std::vector<long>& array, bool ascending) {
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

    void selectionSortString(std::vector<std::string>& arrayString, bool ascending) {
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
    class Node {
    public:
        int data;
        Node *left, *right;
        Node(int input) : data(input), left(nullptr), right(nullptr) {}
    };

    class BST {
    private:
        Node* root;

        Node* insert(Node* node, int input) {
            if (node == nullptr) {
                return new Node(input);
            }

            if (input < node->data) {
                node->left = insert(node->left, input);
            } else if (input > node->data) {
                node->right = insert(node->right, input);
            }

            return node;
        }

        void preOrder(Node* node) {
            if (node != nullptr) {
                std::cout << node->data << " ";
                preOrder(node->left);
                preOrder(node->right);
            }
        }

        void inOrder(Node* node) {
            if (node != nullptr) {
                inOrder(node->left);
                std::cout << node->data << " ";
                inOrder(node->right);
            }
        }

        void postOrder(Node* node) {
            if (node != nullptr) {
                postOrder(node->left);
                postOrder(node->right);
                std::cout << node->data << " ";
            }
        }

        void deleteTree(Node* node) {
            if (node == nullptr) {
                return;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }

        void printSpaces(int spaceCount) {
            for (int i = 0; i < spaceCount; i++) {
                std::cout << "      ";
            }
        }

        void printTree(Node* node, int space) {
            if (node == nullptr) {
                return;
            }
            space += 1;
            printTree(node->right, space);
            printSpaces(space - 1);
            std::cout << node->data << "\n";
            printTree(node->left, space);
        }

    public:
        BST() : root(nullptr) {}

        void insert(int input) {
            root = insert(root, input);
        }

        void deleteAll() {
            deleteTree(root);
            root = nullptr;
        }

        void printLevelOrder() {
            std::cout << std::endl;
            printTree(root, 0);
        }

        void preOrder() {
            preOrder(root);
            std::cout << "\n";
        }

        void inOrder() {
            inOrder(root);
            std::cout << "\n";
        }

        void postOrder() {
            postOrder(root);
            std::cout << "\n";
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