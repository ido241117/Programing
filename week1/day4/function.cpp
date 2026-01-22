# include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//26.Hiện thực hàm tính giai thừa của số N.
int Factorial(int num){
	int output =1;
	for(int i=1;i<=num;i++){
		output *=i;
	}
	return output;
}
/*
Câu 27. Viết hàm sum2 để tính tổng giá trị các phần tử trong mảng số nguyên.
Tham số:
•int* array: mảng số nguyên.
•int size: số phần tử trong mảng.
•int& result: tham số để lưu kết quả cuối cùng sau khi tính toán
*/

void sum2(int* arr, int size, int& result){
	result = 0;
	for(int i=0;i<size;i++){
		result +=arr[i];
	}
}
/*
Câu 28. Viết hàm bool completeNum(int N) để kiểm tra xem số nguyên dương N có phải là một
số hoàn thiện hay không. N là một số hoàn thiện nếu N bằng tổng tất cả ước số nguyên dương
(không bao gồm chính nó) của nó.
•Đầu vào: int N: số nguyên dương N cần kiểm tra.
•Đầu ra: trả về true nếu N là số hoàn thiện, ngược lại trả về false.
*/

bool completeNum(int N){
	int sum =0;
	for(int i=1;i<N;i++){
		if(N%i==0){
			sum +=i;
		}
	}
	if(sum==N)return true;

	return false;
}

/*
Câu 29. Một chuỗi được gọi là palindrome nếu chuỗi đó giống với chuỗi được đảo ngược từ chính nó.
Ví dụ: “eye”, “noon”, “abcba”... Hãy viết hàm kiểm tra xem một chuỗi có là palindrome hay không?
•Đầu vào: const char* str: chuỗi cần kiểm tra palindrome. str chỉ bao gồm chữ cái thường.
•Đầu ra: bool: true nếu chuỗi str là palindrome, ngược lại false
*/

bool palindrome(const char* str){
	int size =0;
	while(str[size] != '\0'){size++;}
	for(int i=0;i<size/2;i++){
		if(str[i] !=  str[size -i-1]){return false;}
	}

	return true;
}

/*
Câu 30. Một số tự nhiên n được gọi là đặc biệt khi và chỉ khi n là số nguyên tố và tổng các chữ số
của n cũng là số nguyên tố. Viết hàm kiểm tra một số tự nhiên có đặc biệt hay không.
•Đầu vào: int n: số tự nhiên cần kiểm tra có phải số đặc biệt không.
•Đầu ra: bool: trả về true nếu n là số đặc biệt, ngược lại trả về false.
*/

bool prime(int N){
	if (N < 2) return false;
	for(int i=2;i<N;i++){
		if (N % i == 0) {return false;}	
	}
	return true	;
}

bool special(int N){
	if (!prime(N)){return false;}
	string s = to_string(N);
	int sum=0;
	int temp =N;
	while(temp > 0){
		sum += temp % 10;
		temp /= 10;
	}
	
	if (!prime(sum)){return false;}
	
	return true;
}

/*
Câu 31. Viết một hàm mã hóa và một hàm giải mã một đoạn text theo phương pháp Caesar Cipher.
Để mã hoá và giải mã một chuỗi ký tự text, ta cần một tham số có giá trị nguyên là shift.
Hàm mã hóa (tên encrypt) sẽ thay đổi từng chữ cái trong text bằng cách dịch chuyển chữ cái đó
sang phải shift lần trong bảng chữ cái. Ví dụ với shift = 3. Khi đó ’a’ được mã hoá thành ’d’, ’b’
được mã hoá thành ’e’,... ’z’ được mã hoá thành ’c’.
Hàm giải mã (tên decrypt) sẽ nhận một chuỗi ký tự text và giá trị nguyên shift và giải mã chuỗi
ký tự này thành chuỗi ban đầu (tức dịch chuyển từng chữ cái sang trái shift lần trong bảng chữ
cái).
•Đầu vào:
– char* text: chuỗi ký tự cần được mã hoá hoặc giải mã, chỉ bao gồm chữ cái thường và
hoa
– int shift: giá trị dịch chuyển trong Caesar Cipher
•Đầu ra: Hàm không trả về. Chuỗi ký tự truyền vào text sẽ thay đổi trực tiếp trong hàm
*/
void encrypt(char* text, int shift) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } 
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        i++;
    }
}

void decrypt(char* text, int shift) {
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] >= 'a' && text[i] <= 'z') {
            // Cộng thêm 26 trước khi chia lấy dư để tránh số âm
            text[i] = (text[i] - 'a' - shift % 26 + 26) % 26 + 'a';
        } 
        else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - shift % 26 + 26) % 26 + 'A';
        }
        i++;
    }
}

/*
Câu 32. Viết hàm kiểm tra các phần tử trong mảng có duy nhất hay không.
•Đầu vào:
– int* arr: mảng số tự nhiên
– int n: số lượng phần tử trong mảng
•Đầu ra: bool: trả về true nếu các phần tử trong mảng là duy nhất, ngược lại trả về false.
*/

bool unique(int* arr,int n){
	sort(arr, arr + n);
	for(int i=0;i<n-1;i++){
		if(arr[i] == arr[i+1]){
			return false;
		} 
	}
	return true;
}

/*
Câu 33. Sinh viên hiện thực hàm int numberOfDiffCharac(string str) để trả về số kí tự phân
biệt trong chuỗi str.
Lưu ý: Chuỗi str chỉ bao gồm các kí tự từ a đến z (các chữ cái lowercase trong bảng chữ cái tiếng
Anh)
*/

int numberOfDiffCharac(string str){
	int size =0;
	int count =0;
	while(str[size] != '\0'){
		bool newchar = true;
		for(int i=0;i<size;i++){
			if(str[i] == str[size] ){
				newchar = false;
				break;
			}
		}if(newchar)count+=1;
		size ++;	
	}
	return count;
}

int main(){
	int a = 6;
	//cout << Factorial(a);

	int arr[]= {1,2,3};
	int result;
	//sum2(arr, sizeof(arr) / sizeof(arr[0]) , result);cout << result;
	
	const char* str ="eye";
	//cout << palindrome(str);

	//special(123456);
	char mystr[] = "abc";
	//encrypt(mystr,4);
	//cout << mystr;

	int arr1[]= {1,2,3,6,4,6};
	//cout << unique(arr1,sizeof(arr1) / sizeof(arr1[0]));
	string str1 = "abcdahj";
	cout << numberOfDiffCharac(str1);
	return 0;
}