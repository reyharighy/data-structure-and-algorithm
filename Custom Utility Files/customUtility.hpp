/*
    File ini digunakan sebagai antarmuka untuk menyimpan berbagai fungsi dasar
    yang berkaitan dengan error handling saat pengguna melakukan input terhadap sistem 
*/

#ifndef CUSTOM_UTILITY_H
#define CUSTOM_UTILITY_H

#include <string>
#include <iostream>
#include <sstream>
#include <charconv>

// Deklarasi awal untuk fungsi-fungsi dari source file customUtility.cpp

std::string normalizeInput();
long inputIntValidator(std::string*);
void outputBuffer();
void invalidMenuChosen(short*, std::string*);
std::string titleCase();
void setCapacityValue(bool*, int*, int*, std::string*, std::string**);

#endif
