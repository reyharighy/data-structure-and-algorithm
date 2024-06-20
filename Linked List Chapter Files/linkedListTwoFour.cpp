/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "linkedListChapter.hpp" untuk tugas dengan nama
    Implementasi linked list untuk mencari data.
*/

#include "linkedListChapter.hpp" 

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Implementasi linked list untuk mencari data
----------------------------------------------------------------------------------------------------------------------------------------*/

struct KeyVal { // Struct untuk menyimpan data key-value 
    std::string key;
    std::string value;
};

class KeyValList : public LinkedList<KeyVal> { // Kelas turunan dari LinkedList
    public:
        std::string getDataOfKey(std::string key) { // Mengembalikan value dari key yang dicari
            Node<KeyVal>* currentNode = this->head; // Pointer ke node pertama
            int index = 0;
            size_t len = this->length(); // Panjang linked list
            while (currentNode->data.key != key && currentNode->next != nullptr) { // Iterasi sampai key ditemukan
                currentNode = currentNode->next; // Pindah ke node berikutnya
                ++index;
            }
            if (currentNode->data.key == key) { // Jika key ditemukan
                return currentNode->data.value; // Mengembalikan value dari key
            }
            throw std::out_of_range("Data not found");
        }
        size_t getIndexOfKey(std::string key) { // Mengembalikan index dari key yang dicari
            Node<KeyVal>* currentNode = this->head;
            int index = 0;
            size_t len = this->length(); // Panjang linked list
            while (currentNode->data.key != key && currentNode->next != nullptr) { // Iterasi sampai key ditemukan
                currentNode = currentNode->next; // Pindah ke node berikutnya
                ++index;
            }
            if (currentNode->data.key == key) { // Jika key ditemukan
                return index; // Mengembalikan index dari key
            }
            throw std::out_of_range("Data not found");
        };
};

void display(KeyValList list) { // Menampilkan seluruh data key-value
    size_t length = list.length(); // Panjang linked list
    if (length == 0) { // Jika linked list kosong
        std::cout << "List kosong." << "\n";
    }
    else { // Jika linked list tidak kosong
        for (size_t i = 0; i < length; ++i) { // Iterasi untuk menampilkan seluruh data
            auto current = list.get(i); // Mendapatkan data dari index ke-i
            std::cout << current.key << ": " << current.value << "\n"; // Menampilkan data
        }
    }
};

void linkedListTwoFour::start() { // Fungsi utama untuk menjalankan program
    auto list = KeyValList(); // Membuat objek dari kelas KeyValList
    while (true) { // Looping menu
        std::cout << "List kode & nama" << "\n";
        int input{};
        std::cout << "[(1) Tampilkan | (2) Tambah | (3) Cari | (4) Hapus | (9) Keluar]: ";
        std::cin >> input;

        switch (input) { // Pilihan menu
            case 1: {
                display(list); // Menampilkan seluruh data
                break;
            }
            case 2: { // Menambahkan data
                KeyVal data; // Membuat objek dari struct KeyVal
                std::cout << "Masukkan kunci: "; 
                std::cin.ignore(); 
                std::getline(std::cin, data.key); // Memasukkan data key
                std::cout << "Masukkan nama: ";
                std::getline(std::cin, data.value); // Memasukkan data value
                list.add(data); // Menambahkan data ke linked list
                break;
            }
            case 3: { // Mencari data
                std::cout << "Masukkan kunci: ";
                std::cin.ignore();
                std::string keyInput;
                std::getline(std::cin, keyInput); // Memasukkan data key
                try { // Menggunakan try-catch untuk menangani exception
                    auto value = list.getDataOfKey(keyInput); // Mendapatkan value dari key
                    std::cout << "Hasil: \n" << keyInput << ": " << value << "\n"; // Menampilkan hasil pencarian
                }
                catch (const std::exception& e) { // Menangani exception
                    std::cout << "Data tidak ditemukan\n";
                }
                break;
            }
            case 4: { // Menghapus data
                std::cout << "Masukkan kunci: ";
                std::cin.ignore();
                std::string keyInput;
                std::getline(std::cin, keyInput); // Memasukkan data key
                try { // Menggunakan try-catch untuk menangani exception
                    auto index = list.getIndexOfKey(keyInput); // Mendapatkan index dari key
                    list.remove(index); // Menghapus data dari linked list
                    std::cout << "Data telah dihapus.";
                }
                catch (const std::exception& e) { // Menangani exception
                    std::cout << "Data tidak ditemukan\n";
                }
                break;
            }
            case 9: { // Keluar dari program
                break;
            }
        }
    }
};

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/