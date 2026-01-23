#include <iostream>
using namespace std;

/*
Câu 34. Cho số nguyên n và số nguyên dương e, trong đó n là số cần tính lũy thừa và e là số mũ.
Hãy viết một hàm đệ quy int calculate_power(int n, int e) để tính giá trị của n^e.
*/

int calculate_power(int n, int e){
	if (e == 0) return 1;
	return n * calculate_power(n, e - 1);
}

int main(){
	int n=2;
	int e=4;
	cout << calculate_power(n,e);
	return 0;
}