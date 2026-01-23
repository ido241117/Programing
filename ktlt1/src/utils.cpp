#include "../include/common.h"

// Hàm clamp: giới hạn giá trị trong khoảng [min_val, max_val]
int clamp(int value, int min_val, int max_val) {
    if(value > max_val)
	{
		value = max_val;
	}
	if(value < min_val)
	{
		value = min_val;
	}
    return value;
}

// Hàm clamp với phép nhân và làm tròn lên: ceil(value * numerator / denominator)
int clampCeil(int value, int numerator, int denominator, int min_val, int max_val) {
    int result = (value * numerator + denominator - 1) / denominator;
    return clamp(result, min_val, max_val);
}

// Hàm chia làm tròn lên: ceil(numerator / denominator)
int ceilDiv(int numerator, int denominator) {
    return (numerator + denominator - 1) / denominator;
}

int giaiMaSo(int n) {

    if (n < 10) {return n;}
    
    while(n >= 10){
        int hangChuc = n / 10;
        int hangDonVi = n % 10;
        int tong = hangChuc + hangDonVi;
        n = tong;
    }
    return n % 10;
}

// Đọc dữ liệu từ file input
bool readInputFile(const string& filename, int& HP1, int& HP2, 
                   int& EXP1, int& EXP2, int& M1, int& M2, 
                   int& E1, int& E2, int& E3) {
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "Cannot open file: " << filename << endl;
        return false;
    }
    
    // Format: HP1 HP2 EXP1 EXP2 M1 M2 E1 E2 E3
	ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
    
    ifs.close();
    return true;
}
