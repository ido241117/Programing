#include <iostream>
#include <string>
using namespace std;

/*
Câu 49. Hãy hiện thực hàm int* zeros(int n) tạo một mảng có n phần tử 0.
•Đầu vào: Kích thước mảng n.
•Đầu ra: Con trỏ trỏ tới mảng vừa được cấp phát.
Lưu ý: Trong trường hợp cấp phát thất bại, hàm sẽ trả về nullptr.
*/
int* zeros(int n){
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		arr[i] = 0;
	}
	return arr;
}

int* num(int n){
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		arr[i] = i;
	}
	return arr;
}

int* num3(int n, int a){
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		arr[i] = a++;
	}
	return arr;
}


/*
Câu 50. Hãy hiện thực hàm void shallowCopy(int*& newArr, int*& arr) có chức năng tạo một
bản sao của một mảng một chiều.
•Đầu vào: Mảng một chiều arr cần được sao chép.
•Đầu ra: Mảng đích một chiều newArr cần sao chép tới.
Lưu ý: Sau thực thi mảng được sao chép và mảng cần sao chép đều sử dụng chung một vùng nhớ.
*/

void shallowCopy(int*& newArr, int*& arr){
	newArr = arr;
}	

void test_shallowCopy(){
	int* arr = num(4);
	int* arr1;
	shallowCopy(arr1, arr);
	cout << *(arr1+1) << '\n';
	*(arr+1) = 100;
	cout << *(arr1+1);
}

/*
âu 51. Hãy hiện thực hàm int** deepCopy(int** matrix, int r, int c) trả về một bản sao
của matrix gồm r hàng và c cột.
•Đầu vào: Con trỏ matrix trỏ đến mảng hai chiều có kích thước r x c.
•Đầu ra: Con trỏ trỏ đến mảng hai chiều được sao chép.
Lưu ý: Sau thực thi, con trỏ trả về phải trỏ đến vùng nhớ được cấp phát mới và khi matrix truyền
vào có kích thước 0, hàm trả về nullptr.
*/

int** num2x(int r, int c){
	int** arr = new int*[r];
	for(int i=0;i<r;i++){
		arr[i] = num3(c,i*c);
	}
	return arr;
}

int** deepCopy(int** matrix, int r, int c){
	int** arr = new int*[r];
	for(int i=0;i<r;i++){
		arr[i] = new int[c];
		for(int j=0;j<c;j++){
			arr[i][j] = matrix[i][j];
		}
	}
	return arr;
}

void test_deepCopy(){
    int r = 2, c = 2;
    int** original = num2x(r, c);
    int** copy = deepCopy(original, r, c);

    cout << "Original [0][0] truoc: " << original[0][0] << endl;
    cout << "Copy [0][0] truoc: " << copy[0][0] << endl;

    // Thay đổi giá trị ở ma trận gốc
    original[0][0] = 999;

    cout << "Sau khi thay doi original[0][0] thanh 999:" << endl;
    cout << "Original [0][0]: " << original[0][0] << endl;
    cout << "Copy [0][0]: " << copy[0][0] << " (Khong thay doi)" << endl;
}

/*
Câu 52. Hãy hiện thực hàm void deleteMatrix(int**& matrix, int r) thực hiện giải phóng ô
nhớ cho một mảng động 2 chiều có r hàng. matrix được gán bằng giá trị NULL sau khi thực hiện
hàm.
Đầu vào: Mảng động hai chiều matrix có số hàng r cần giải phóng ô nhớ.
*/
void deleteMatrix(int**& matrix, int r){
	for(int i = 0; i < r; i++){
		delete[] matrix[i];
	}
	delete[] matrix;

	matrix = nullptr;
}


int main(){
	test_deepCopy();

	return 0;
}