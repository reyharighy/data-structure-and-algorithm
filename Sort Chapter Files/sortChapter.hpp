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
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (const auto& el : vec)
    {
        os << el << ' ';
    }
    return os;
}

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Bubble Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourOne: public Program {
private:
    bool isDataExist {false};
    std::string invalidIntInput;
    std::vector<long> array, arrayCopy {};
    void menuInterface();
    void sort();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~SortFourOne(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Insertion Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourTwo: public Program {
private:
    bool isDataExist {false};
    std::string invalidIntInput;
    std::vector<long> array, arrayCopy {};
    void menuInterface();
    void sort();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~SortFourTwo(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 2.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas mengurutkan data menggunakan Selection Sort.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourThree: public Program {
private:
    bool isDataExist {false};
    std::string invalidIntInput;
    std::vector<long> array, arrayCopy {};
    void menuInterface();
    void sort();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~SortFourThree(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 3.
----------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas Pre-order, In-order, dan Post-order Traversal pada Pohon Biner.
----------------------------------------------------------------------------------------------------------------------------------------*/

class SortFourFour: public Program {
private:
    bool isDataExist {false};
    std::string invalidIntInput;
    std::vector<long> array, arrayCopy {};
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    class BST {
    public:
        Node* root;
        BST() : root(nullptr) {}
        Node* insert(Node* node, int data) {
            if (node == nullptr) {
                return new Node(data);
            } 
            if (data < node->data) {
                node->left = insert(node->left, data);
            } else if (data > node->data) {
                node->right = insert(node->right, data);
            }
            return node;
        }

        void insert(int data) {
            root = insert(root, data);
        }

        void preOrder(Node* node) {
            if (node == nullptr) return;
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }

        void inOrder(Node* node) {
            if (node == nullptr) return;
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }

        void postOrder(Node* node) {
            if (node == nullptr) return;
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    };
    void menuInterface();
    void sort();
    void push();
    void pre();
    void in();
    void post();

public:
    void start() override; // Metode polymorphism untuk menjalankan program
    ~SortFourFour(); // Destructor untuk mencegah memory leaks pada variabel "arrayPointer"
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif