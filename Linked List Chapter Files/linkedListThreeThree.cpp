/*
    File ini berisi implementasi dari berbagai fungsi yang dideklarasikan di dalam file "linkedListChapter.hpp" untuk tugas dengan nama
    Implementasi linked list untuk membuat antrian.
*/

#include "linkedListChapter.hpp" 

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Implementasi linked list untuk membuat antrian
----------------------------------------------------------------------------------------------------------------------------------------*/

void display(Queue<std::string> q) {
    auto output = q;
    if (output.isEmpty()) {
        std::cout << "(kosong)";
    }
    while (!output.isEmpty()) {
        std::cout << output.dequeue() << "; ";
    }
}

void linkedListThreeThree::start() {
    std::cout << "Masukkan banyaknya anggota maks.: ";
    size_t size;
    std::cin >> size;
    auto q{Queue<std::string>()};

    while (true) {
        std::cout << "Anggota antrian: ";
        display(q);
        std::cout << "\n[(1) Tambah | (2) Ambil | (3) Keluar]: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cin.ignore();
                std::string input;

                std::cout << "Masukkan data: ";
                std::getline(std::cin, input);
                try {
                    q.enqueue(input);
                } catch (const std::out_of_range& e) {
                    std::cout << "Antrian penuh.\n";
                }
                break;
            }
            case 2: {
                try {
                    std::string data = q.dequeue();
                    std::cout << "Data yang diambil: " << data << "\n";
                }
                catch (const std::out_of_range& e) {
                    std::cout << "Antrian kosong.\n";
                }
                break;
            }
            default:
                break;
        }
    }
}   

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/