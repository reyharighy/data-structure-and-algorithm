#include "declaration.hpp"
#include "linkedlist.hpp"
#include <string>

namespace LinkedListChapter {
    namespace KeyValListDemo {
        struct KeyVal {
            std::string key;
            std::string value;
        };

        class KeyValList : public LinkedListImplementation::LinkedList<KeyVal> {
            public:
                std::string find(std::string key) { // finds the value of a key.
                    LinkedListImplementation::Node<KeyVal>* currentNode = this->head;
                    int index = 0;
                    size_t len = this->length();
                    while (currentNode->data.key != key && currentNode->next != nullptr) {
                        currentNode = currentNode->next;
                        ++index;
                    }
                    if (currentNode->data.key == key) {
                        return currentNode->data.value;
                    }
                    throw std::out_of_range("Data not found");
                };
                KeyVal get(size_t index) {
                    return LinkedListImplementation::LinkedList<KeyVal>::get(index);
                }
        };

        void display(KeyValList list) {
            size_t length = list.length();
            if (length == 0) {
                std::cout << "List kosong." << "\n";
            }
            else {
                for (size_t i = 0; i < length; ++i) {
                    auto current = list.get(i);
                    std::cout << current.key << ": " << current.value << "\n";
                }
            }
        };

        int demo() {
            auto list = KeyValList();
            while (true) {
                std::cout << "List kode & nama" << "\n";
                int input{};
                std::cout << "[(1) Tampilkan | (2) Tambah | (3) Cari | (9) Keluar]: ";
                std::cin >> input;

                switch (input) {
                    case 1: {
                        display(list);
                        break;
                    }
                    case 2: {
                        KeyVal data;
                        std::cout << "Masukkan kunci: ";
                        std::cin.ignore();
                        std::getline(std::cin, data.key);
                        std::cout << "Masukkan nama: ";
                        std::getline(std::cin, data.value);
                        list.add(data);
                        break;
                    }
                    case 3: {
                        std::cout << "Masukkan kunci: ";
                        std::cin.ignore();
                        std::string keyInput;
                        std::getline(std::cin, keyInput); 
                        try {
                            auto value = list.find(keyInput);
                            std::cout << "Hasil: \n" << keyInput << ": " << value << "\n";
                        }
                        catch (const std::exception& e) {
                            std::cout << "Data tidak ditemukan\n";
                        }
                        break;
                    }
                    case 9:
                        return 0;
                        break;
                }
            }
        };
    }
}