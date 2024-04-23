#ifndef CUSTOM_UTILITY_H
#define CUSTOM_UTILITY_H

#include <string>

std::string normalizeInput();
long inputIntValidator(std::string*);
void outputBuffer();
void invalidMenuChosen(short*, std::string*);
std::string titleCase();
void setCapacityValue(bool*, int*, int*, std::string*, std::string**);

#endif 