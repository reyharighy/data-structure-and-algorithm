#ifndef MAIN_PROGRAM_H
#define MAIN_PROGRAM_H

#include <iostream>
#include <string>

class Program {
public:
    virtual void start() = 0;

    short taskList(short taskID, short start, short end, short anotherTaskID = 0, short anotherStart = 0, short anotherEnd = 0) {
        short count = end - start + 1;
        short anotherCount = anotherEnd - anotherStart + 1;
        
        for (size_t i = 1; i <= count; i++) {
            std::cout << "\n  " << std::to_string(i) << ". Tugas " 
                      << std::to_string(taskID) << " Nomor " << std::to_string(start + i - 1);
        }

        if (anotherTaskID) {
            short anotherIndex = end - start + 2;

            for (size_t i = anotherIndex; i <= (anotherCount + 1); i++) {
                std::cout << "\n  " << std::to_string(i) << ". Tugas "
                          << std::to_string(anotherTaskID) << " Nomor " << std::to_string(anotherStart + i - anotherIndex);
            }
        }

        std::cout << "\n  " << (anotherTaskID ? std::to_string(count + anotherCount + 1) : std::to_string(end - start + 2))
                  << ". Lihat Program-program pada Bab lain"
                  << "\n\nSilahkan masukan angka pilihan menu => ";

        return anotherTaskID ? (count + anotherCount) : (end - start + 1);
    }
};

#endif