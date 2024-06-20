/*
    File ini digunakan sebagai antarmuka untuk seluruh subProgram yang ada di dalam Chapter Hash. Setiap objek 
    kelas yang dideklarasikan di dalam file ini menyediakan berbagai fungsi spesifik yang dienkapsulasi untuk melakukan aktivitas pengoperasian 
    atau manipulasi data beserta attribute members yang diperlukan.
*/

#ifndef HASH_CHAPTER
#define HAsH_CHAPTER

#include "../Program Interface Files/programInterface.hpp"
#include "../Custom Utility Files/customUtility.hpp"

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk objek kelas dengan nama tugas pencarian data menggunakan algoritma pencarian linear dan binary search.
----------------------------------------------------------------------------------------------------------------------------------------*/

class hashSixOne: public Program {
private:
    std::string invalidIntInput;
    std::vector<long> array {}; // Inisialisasi vector untuk menyimpan data integer
    void linearSearch(const std::vector<long>& array, int target) {
        int position = -1;
        for (int index = 0; index < array.size(); ++index) {
            if (array[index] == target) {
                position = index;
                break;
            }
        }
        if (position != -1) {
            std::cout << "Linear Search: Target found at position " << position+1 << std::endl;
        } else {
            std::cout << "Linear Search: Target not found." << std::endl;
        }
    }

    void binarySearch(const std::vector<long>& array, int target) {
        int low = 0;
        int high = array.size() - 1;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (target > array[mid]) {
                low = mid + 1;
            } else if (target < array[mid]) {
                high = mid - 1;
            } else {
                std::cout << "Binary Search: Target found at position " << mid+1 << std::endl;
                return;
            }
        }
        std::cout << "Binary Search: Target not found." << std::endl;
    }
    void search(std::vector<long> array, int target) {
        bool sorted = true;
        for (int i = 1; i < array.size(); ++i) {
            if (array[i - 1] > array[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            binarySearch(array, target);
        } else {
            linearSearch(array, target);
        }
    }

    void menuInterface();
    void search();
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
    PART 2: Deklarasi awal untuk objek kelas dengan nama tugas Penanganan Tabrakan Hash dengan cara Pengalamatan Terbuka.
----------------------------------------------------------------------------------------------------------------------------------------*/

class hashSixTwo : public Program {
private:
    std::string invalidIntInput;
    class HashTable {
    private:
        std::vector<std::pair<int, std::string>> table;
        int capacity;

        int hashFunction(int key) const {
            return key % capacity;
        }

    public:
        HashTable(int size) : table(size, {-1, ""}), capacity(size) {}

        void insert(int key, std::string data) {
            int hash = hashFunction(key);
            int ori = hash;
            while (table[hash].second != "") {
                if (table[hash].first == key) {
                    table[hash].second = data;
                    return;
                }
                hash = (hash + 1) % capacity;
                if (hash == ori) {
                    std::cout << "Tabel Hash sudah penuh! Hapus data terlebih dahulu";
                    return;
                }
            }
            table[hash] = {key, data};
        }

        void search(int key) {
            int hash = hashFunction(key);
            int ori = hash;
            while (table[hash].second != "") {
                if (table[hash].first == key) {
                    std::cout << "Kunci " << key << " ditemukan dengan data: " << table[hash].second << '\n';
                    return;
                }
                hash = (hash + 1) % capacity;
                if (hash == ori) {
                    std::cout << "Kunci tidak ditemukan di dalam tabel hash" << '\n';
                    return;
                }
            }
        }

        void remove(int key) {
            int hash = hashFunction(key);
            int ori = hash;
            while (table[hash].second != "") {
                if (table[hash].first == key) {
                    std::cout << "Data dengan kunci " << key << " berhasil dihapus.\n";
                    table[hash] = {-1, ""};
                    return;
                }
                hash = (hash + 1) % capacity;
            }
            std::cout << "Kunci tidak ditemukan di dalam tabel hash.\n";
        }

        void clear() {
            for (int i = 0; i < capacity; ++i) {
                table[i] = {-1, ""};
            }
            std::cout << "Semua data berhasil dihapus.\n";
        }

        void display() {
            std::cout << "Isi Tabel Hash:\n";
            std::cout << "----------------\n";
            for (int i = 0; i < capacity; ++i) {
                if (table[i].second != "") {
                    std::cout << "Index " << i+1 << ": " << table[i].first << " -> " << table[i].second << '\n';
                } else {
                    std::cout << "Index " << i+1 << ": Kosong\n";
                }
            }
            std::cout << "----------------\n";
        }

        int size() const {
            int total = 0;
            for (int i = 0; i < capacity; ++i) {
                if (table[i].second != "") {
                    ++total;
                }
            }
            return total;
        }
    };
    HashTable table {0};
    void menuInterface();
    void search();
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
    PART 3: Deklarasi awal untuk objek kelas dengan nama tugas Penanganan Tabrakan Hash dengan cara Pembentukan Rantai 
----------------------------------------------------------------------------------------------------------------------------------------*/

class hashSixThree: public Program {
private:
    std::string invalidIntInput;
    struct Node {
        int key;
        std::string data;
        Node* next;

        Node(int k, std::string d) : key(k), data(d), next(nullptr) {}
    };

    class HashTable {
    private:
        std::vector<Node*> table;
        int M;

        int hash_function(int key) {
            return key % M;
        }

    public:
        HashTable(int size) : table(size, nullptr), M(size) {}

        void insert(int key, std::string data) {
            int hash = hash_function(key);
            Node* newNode = new Node(key, data);
            if (table[hash] == nullptr) {
                table[hash] = newNode;
            } else {
                Node* current = table[hash];
                while (current->next != nullptr) {
                    if (current->key == key) {
                        current->data = data;  
                        delete newNode;
                        return;
                    }
                    current = current->next;
                }
                if (current->key == key) {
                    current->data = data; 
                    delete newNode;
                } else {
                    current->next = newNode;
                }
            }
        }

        void search(int key) {
            int hash = hash_function(key);
            Node* current = table[hash];
            while (current != nullptr) {
                if (current->key == key) {
                    std::cout << "Kunci " << key << " ditemukan dengan data: " << current->data << '\n';
                    return;
                }
                current = current->next;
            }
            std::cout << "Kunci tidak ditemukan di dalam tabel hash\n";
        }

        void remove(int key) {
            int hash = hash_function(key);
            Node* current = table[hash];
            Node* prev = nullptr;
            while (current != nullptr) {
                if (current->key == key) {
                    if (prev == nullptr) {
                        table[hash] = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current;
                    std::cout << "Data dengan kunci " << key << " berhasil dihapus.\n";
                    return;
                }
                prev = current;
                current = current->next;
            }
            std::cout << "Kunci tidak ditemukan di dalam tabel hash.\n";
        }

        void clear() {
            for (int i = 0; i < M; ++i) {
                Node* current = table[i];
                while (current != nullptr) {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
                table[i] = nullptr;
            }
            std::cout << "Semua data berhasil dihapus.\n";
        }

        void display() {
            std::cout << "Isi Tabel Hash (dengan chaining):\n";
            for (int i = 0; i < M; ++i) {
                std::cout << "[" << i << "]: ";
                Node* current = table[i];
                while (current != nullptr) {
                    std::cout << "(" << current->key << ", " << current->data << ") -> ";
                    current = current->next;
                }
                std::cout << "Kosong\n";
            }
        }

        int size() const {
            int total = 0;
            for (int i = 0; i < M; ++i) {
                Node* current = table[i];
                while (current != nullptr) {
                    ++total;
                    current = current->next;
                }
            }
            return total;
        }

        ~HashTable() {
            for (int i = 0; i < M; ++i) {
                Node* current = table[i];
                while (current != nullptr) {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
        }
    };
    HashTable table {0};
    void menuInterface();
    void search();
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
    PART 4: Deklarasi awal untuk objek kelas dengan nama tugas Penanganan Tabrakan Hash dengan cara Pengalamatan Buket.
----------------------------------------------------------------------------------------------------------------------------------------*/

class hashSixFour: public Program {
private:
    std::string invalidIntInput;
    struct Bucket {
        int key;
        std::string data;
        Bucket(int k, std::string d) : key(k), data(d) {}
    };

    class HashTable {
    private:
        std::vector<std::vector<Bucket>> buckets;
        int capacity;

        int hashFunction(int key) const {
            return key % capacity;
        }

    public:
        HashTable(int capacity) : buckets(capacity), capacity(capacity) {}

        void insert(int key, std::string value) {
            int hash = hashFunction(key);
            for (auto& bucket : buckets[hash]) {
                if (bucket.key == key) {
                    bucket.data = value;
                }
            }
            buckets[hash].emplace_back(key, value);
        }

        void search(long key) const {
            long hash = hashFunction(key);
            for (const auto& bucket : buckets[hash]) {
                if (bucket.key == key) {
                    std::cout << "Key " << key << " found with value: " << bucket.data << '\n';
                }
            }
            std::cout << "Key not found in the hash table.\n";
        }

        void remove(int key) {
            int hash = hashFunction(key);
            char found = false;
            auto& bucketList = buckets[hash];
            for (auto it = bucketList.begin(); it != bucketList.end(); ++it) {
                if (it->key == key) {
                    bucketList.erase(it);
                    std::cout << "Data with key " << key << " successfully removed.\n";
                    found = true;
                }
            }
            if (!found) {
                std::cout << "Key not found in the hash table.\n";
            }
        }

        void clear() {
            for (int i = 0; i < capacity; ++i) {
                buckets[i].clear();
            }
            std::cout << "All data successfully removed.\n";
        }

        void display() const {
            for (int i = 0; i < capacity; ++i) {
                std::cout << "[" << i << "]: ";
                for (const auto& bucket : buckets[i]) {
                    std::cout << "(" << bucket.key << ", " << bucket.data << ") -> ";
                }
                std::cout << "Empty\n";
            }
        }

        int size() const {
            int total = 0;
            for (int i = 0; i < capacity; ++i) {
                total += buckets[i].size();
            }
            return total;
        }
    };
    HashTable table {0};
    void menuInterface();
    void search();
    void preview();
    void del();
    void push();
public:
    void start() override; // Metode polymorphism untuk menjalankan program
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 4.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif