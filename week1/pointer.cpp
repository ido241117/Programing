#include <iostream>
#include <string>
using namespace std;
/*
Câu 42. Hiện thực hàm int getValueAtIndex(int *ptr, int k) trả về giá trị của tại vị trí được
chỉ định trong mảng qua con trỏ. Trong đó: ptr là con trỏ tới phần tử đầu tiên trong mảng, k là vị
trí cần truy xuất phần tử (giá trị này không vượt quá độ dài của mảng).
*/

int getValueAtIndex(int *ptr, int k){
	return ptr[k];
}

/*
Câu 43.  thực hàm void swap(int *ptr1, int *ptr2) thực hiện hoán đổi giá trị tại vị trí
của 2 con trỏ trỏ tới. Trong đó: ptr1, ptr2 lần lượt là là các con trỏ trỏ tới vị trí cần hoàn đổi.
*/

void swap(int *ptr1, int *ptr2){
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
/*
Câu 44. Hiện thực hàm int calcSum(int *ptr, int n) tính và trả về tổng của các phần tử trong
mảng 1 chiều được cho bởi con trỏ. Trong đó: ptr là con trỏ tới phần tử đầu tiên trong mảng, n là
kích thước của mảng.
Lưu ý: Bạn cần phải dùng dereference operator (*) để lấy giá trị của các phần tử trong mảng.
Không được dùng subscript operator ([]).
*/
int calcSum(int *ptr, int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum += *(ptr +i);
	}

	return sum;
}

/*
Câu 45. Hiện thực hàm void add(int *ptr, int n, int k) thực hiện thêm phần tử vào cuối của
mảng 1 chiều được cho bởi con trỏ. Trong đó: ptr là con trỏ tới phần tử đầu tiên trong mảng, n, k
lần lượt là kích thước của mảng và phần tử cần được thêm vào.
*/
void add(int *ptr, int n, int k){
	*(ptr +n) = k;
}
/*
Câu 46. Hiện thực hàm int findMax(int *ptr, int n) tìm và trả về phần tử lớn nhất trong
mảng 1 chiều được cho bởi con trỏ. Trong đó: ptr là con trỏ tới phần tử đầu tiên trong mảng, n là
kích thước của mảng.
*/
int findMax(int *ptr, int n){
	int max = *ptr;
	for(int i=0;i<n;i++){
		if(max < *(ptr +i)){
			max = *(ptr +i);
		}
	}
	return max;
}

/*
Câu 47. Hiện thực hàm void reverse(int *ptr, int n) đảo ngược mảng 1 chiều được cho bởi
con trỏ. Trong đó: ptr là con trỏ tới phần tử đầu tiên trong mảng, n là kích thước của mảng 1 chiều.
Lưu ý: Bạn cần phải dùng dereference operator (*) để lấy giá trị của các phần tử trong mảng.
Không được dùng subscript operator ([]).
*/
void reverse(int *ptr, int n){
	for(int i=0;i<n/2;i++)
	{
		swap((ptr+i), (ptr-i-1));
	}
}
/*
Câu 48. Hiện thực hàm bool isSymmetry(int *head, int *tail) kiểm tra mảng 1 chiều có phải
là một mảng đối xứng hay không. Trong đó: head, tail lần lượt là con trỏ tới phần tử đầu tiên và
cuối cùng trong mảng
*/
bool isSymmetry(int *head, int *tail){

    while (head < tail) {
        if (*head != *tail) return false;
        head++;
        tail--;
    }
	return true ;
;
}
int main(){
	//int arr[] = {1,2,3,2,0};
	//int arr[] = {1,2,3,2,1};
	int arr[] = {1,2,3,2,2,1};
	//int arr[] = {1,2,3,3,2,0};
	int* ptr1 = arr;
	int* ptr2 = (arr + (sizeof(arr)/sizeof(arr[0])) - 1);

	cout << isSymmetry(ptr1, ptr2);
	
	return 0;
}