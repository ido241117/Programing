#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

// Constants
const int MIN_HP = 0;
const int MAX_HP = 666;
const int MIN_EXP = 0;
const int MAX_EXP = 600;
const int MIN_M = 0;
const int MAX_M = 3000;

int giaiMaSo(int n);
// Utility functions
int clamp(int value, int min_val, int max_val);
int clampCeil(int value, int numerator, int denominator, int min_val, int max_val);
int ceilDiv(int numerator, int denominator);
bool readInputFile(const string& filename, int& HP1, int& HP2, 
                   int& EXP1, int& EXP2, int& M1, int& M2, 
                   int& E1, int& E2, int& E3);

#endif
