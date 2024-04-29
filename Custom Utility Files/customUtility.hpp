/*
    File ini digunakan sebagai antarmuka untuk menyimpan berbagai fungsi dasar yang berkaitan dengan standard input dari pengguna. 
    Selain itu, file ini juga berperan dalam memenuhi proses abstraksi dari tiap fungsi yang disediakan.
*/

#ifndef CUSTOM_UTILITY_H
#define CUSTOM_UTILITY_H

#include <string>
#include <iostream>
#include <sstream>
#include <charconv>

/*----------------------------------------------------------------------------------------------------------------------------------------
    PART 1: Deklarasi awal untuk berbagai fungsi dari file "customUtility.cpp". Definisi tiap fungsi ada di file "customUtility.cpp".
----------------------------------------------------------------------------------------------------------------------------------------*/

std::string normalizeInput(); // Definisi ada di PART 1
long inputIntValidator(std::string*); // Definisi ada di PART 2
void outputBuffer(); // Definisi ada di PART 3
void invalidMenuChosen(short*, std::string*); // Mengacu ke PART 4
std::string titleCase(); // Definisi ada di PART 5
void setCapacityValue(bool*, int*, int*, std::string*, std::string**); // Definisi ada di PART 6

/*----------------------------------------------------------------------------------------------------------------------------------------
    END OF SCOPE FOR PART 1.
----------------------------------------------------------------------------------------------------------------------------------------*/

#endif 
