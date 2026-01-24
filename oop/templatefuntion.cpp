#include <iostream>
#include "class.cpp"
using namespace std;

//template cơ bản dành cho 1 hàm
template <typename T>
T mysum(T a, T b){
	return a + b;
}

void test_sum_int(){
	int a = 5;
	int b = 7;
	cout << mysum(a,b) << '\n';
}

void test_sum_float(){
	float a = 5.5;
	float b = 8.6;
	cout << mysum(a,b) << '\n';
}

void test_sum_Interger(){
	Integer a(10);
	Integer b(20);
	cout << mysum(a,b).getValue() << '\n';
}

int main(){
	test_sum_Interger();
	
	return 0;
}