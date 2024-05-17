#include <string>
#include <iostream>
#include "linkedlist.hpp"
#include "declaration.hpp"

namespace LinkedListChapter {
    namespace OrderedListDemo {
        void display(LinkedList::OrderedLinkedList<std::string> orderedList) {
            std::cout << "======\n";
            size_t length = orderedList.length();
            if (length == 0) {
                std::cout << "List Kosong" << "\n";
            }
            else {
                std::cout << "Isi: ";
                for (int i = 0; i < length; ++i) {
                    std::cout << orderedList.get(i);
                    if (i != length - 1) {
                        std::cout << "; ";
                    }
                };
                std::cout << "\n";
            }
        }

        int demo() {
            LinkedList::OrderedLinkedList<std::string> orderedList = LinkedList::OrderedLinkedList<std::string>();

            while (true) {
                display(orderedList);
                int input{};
                std::cout << "[(1) Tambah | (2) Ambil | (3) Hapus | (4) Keluar]: ";
                std::cin >> input;

                switch(input) {
                    case 1: {
                        std::string dataInput;
                        std::cin.ignore(); // console input cleanup?
                        std::cout << "Masukkan data: ";
                        std::getline(std::cin, dataInput);
                        orderedList.add(dataInput);
                        break;
                    }
                    case 4:
                        return 0;
                        break;
                }
            }
        }
    }
}