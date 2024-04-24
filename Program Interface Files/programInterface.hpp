/*
    File ini digunakan sebagai antarmuka untuk memudahkan proses penjelajahan ke berbagai
    subprogram dari seluruh chapter yang ditugaskan pada mata pelajaran ini.
*/

#ifndef PROGRAM_INTERFACE_H
#define PROGRAM_INTERFACE_H

#include <iostream>
#include <string>
#include <map>

// Deklarasi awal dari objek Program dalam menjalankan setiap subprogram pada tiap chapter

class Program {
public:
    virtual void start() = 0;
    short taskList(const short);
};

#endif
