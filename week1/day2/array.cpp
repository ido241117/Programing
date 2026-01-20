#include <iostream>
#include <cmath>
using namespace std;

/*
Câu 12. Cho mảng 2 chiều chứa các số nguyên, kích thước M x N. Hiện thực hàm int findMaxColumn
(int arr[][1000], int row, int col) để tìm chỉ số của cột có tổng tất cả các phần tử lớn nhất,
trong đó arr, row và col lần lượt là mảng 2 chiều, số hàng và số cột của mảng.
Lưu ý: Cột đầu tiên được đánh chỉ số 0. Nếu có nhiều hơn một cột có tổng lớn nhất, ta chọn cột
có chỉ số lớn nhất.
*/
int findMaxColumn(int arr[][1000], int row, int col){
	int maxcol = -99; // Không để giá trị 0 vì có khả năng tổng tất cả các cột đều là số âm
	int maxsumcol = 0;
	for (int i = 0; i < col; i++){
		int sumcol = 0;
		for (int j = 0; j < row; j++){
			sumcol += arr[j][i];
		}
		if(sumcol >= maxsumcol){
			maxsumcol = sumcol;
			maxcol = i;
		}

	}
	
	return maxcol;
}

/*
Câu 13. Cho mảng 2 chiều chứa các số nguyên, kích thước N x N. Hiện thực hàm int diagonalProduct
(int arr[][1000], int row, int col) để tìm tích của tất cả các phần tử trong đường chéo chính
của mảng, trong đó arr, row và col lần lượt là mảng 2 chiều, số hàng và số cột của mảng
*/
int diagonalProduct(int arr[][1000], int row, int col){
	int output = 1;
	for (int i = 0; i < row; i++){
		output *= arr[i][i];
	}
	return output;
}

/*
Câu 14. Cho mảng 2 chiều chứa các số nguyên, kích thước N x N. Một ma trận được gọi là đối xứng
nếu với mọi i,j; giá trị của phần tử ở hàng i, cột j luôn bằng giá trị của phần tử ở hàng j, cột i.
Hiện thực hàm bool isSymmetric(int arr[][1000], int row, int col) để kiểm tra xem mảng
này có phải là một ma trận đối xứng hay không, trong đó arr, row và col lần lượt là mảng 2 chiều,
số hàng và số cột của mảng
*/
bool isSymmetric(int arr[][1000], int row, int col){
	bool isSymmetric = true;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if(arr[i][j] != arr[j][i]){
				isSymmetric = false;
			}
		}
	}
	return isSymmetric;
}

/*
Câu 15. Cho mảng 2 chiều chứa các số nguyên, kích thước M x N. Tổng của một đường chéo là tổng
tất cả các phần tử nằm trên đường chéo đó. Hiện thực hàm int diagonalDiff(int arr[][1000],
int row, int col, int x, int y) để tìm giá trị tuyệt đối của hiệu giữa hai đường chéo đi qua
ô có số hàng x và số cột y, trong đó arr, row và col lần lượt là mảng 2 chiều, số hàng, số cột của
mảng; x và y biểu thị ô có số hàng là x và số cột là y trong mảng đã cho (0 ≤x < row và 0 ≤y <
col).
*/
int diagonalDiff(int arr[][1000], int row, int col, int x, int y){
	int summain = 0;
	int tempx = x;int tempy = y;
	while (tempx < row && tempy < col){
		summain += arr[tempx][tempy];
		tempx++;
		tempy++;
	}

	tempx = x;tempy = y;
	while(tempx >= 0 && tempy >= 0){
		summain += arr[tempx][tempy];
		tempx--;
		tempy--;
	}
	summain -= arr[x][y];
	int sumsub = 0;
	tempx = x;tempy = y;
	while(tempx < row && tempy >= 0){
		sumsub += arr[tempx][tempy];
		tempx++;
		tempy--;
	}
	tempx = x;tempy = y;
	while(tempx >= 0 && tempy < col){
		sumsub += arr[tempx][tempy];
		tempx--;
		tempy++;
	}
	sumsub -= arr[x][y];

	return abs(summain - sumsub);
}

/*
Câu 16. Cho mảng 2 chiều chứa các số nguyên, kích thước M x N. Một hàng trong mảng được gọi
là HN1 nếu trong hàng đó, mỗi phần tử đều có giá trị không lớn hơn các phần tử đứng sau nó.
Hiện thực hàm int ascendingRows(int arr[][1000], int row, int col) để tìm số hàng HN1
có trong mảng, trong đó arr, row và col lần lượt là mảng 2 chiều, số hàng và số cột của mảng.
*/
int ascendingRows(int arr[][1000], int row, int col){
	int output = 0;
	for (int i=0;i<row;i++){
		bool ascending = true;
		for (int j=0;j<col;j++){
			
			if(j < col-1 && arr[i][j] > arr[i][j+1]){
				ascending = false;
			}
		}
		if(ascending){output += 1;} 
	}
	return output;
}
/*
Câu 17. Cho mảng 2 chiều chứa các số nguyên, kích thước M x N. Một cột của mảng được gọi là HN2
nếu tổng tất cả các phần tử trong cột đó là số nguyên tố. Hiện thực hàm int primeColumns(int
arr[][1000], int row, int col) để tìm số cột HN2 có trong mảng, trong đó arr, row và col lần
lượt là mảng 2 chiều, số hàng và số cột của mảng.
*/
bool prime(int num){
	if (num <= 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {return false;}
	}
	return true;
}


int primeColumns(int arr[][1000], int row, int col){
	int output = 0;
	for (int i=0;i<col;i++){
		int sumcol = 0;
		for (int j=0;j<row;j++){
			sumcol += arr[j][i];
		}
		if(prime(sumcol)){output+=1;}
	}
	return output;
}

/*
Câu 18. Cho mảng 2 chiều chứa các số nguyên, kích thước M x N. Hiện thực hàm int specialCells
(int arr[][1000], int row, int col), trong đó; arr, row và col lần lượt là mảng 2 chiều, số
hàng và số cột của mảng. Một ô trong mảng được gọi là HN3 nếu tổng tất cả các phần tử trong
hàng chứa ô đó và tổng tất cả các phần tử trong cột chứa ô đó đều là số nguyên tố. Tìm số ô HN3
trong mảng.
Ghi chú: (Các) thư viện iostream, vector và string đã được khai báo, và namespace std đã
được sử dụng.
*/
int specialCells (int arr[][1000], int row, int col){
	int output = 0;
	for (int i=0;i<row;i++){
		for (int j=0;j<col;j++){
			int sumcol = 0;
			int sumrol = 0;
			for (int k=0;k<row;k++){sumcol += arr[k][j];}
			for (int k=0;k<col;k++){sumrol += arr[i][k];}
			if(prime(sumcol) && prime(sumrol)){
				output+=1;
			}
		}
	}
	return output;
}

/*
Câu 19. Cho mảng 2 chiều chứa các số nguyên, kích thước M x N. Hiện thực hàm int subMatrix(int
arr[][1000], int row, int col), trong đó; arr, row và col lần lượt là mảng 2 chiều, số hàng và
số cột của mảng. Một mảng con kích thước 2x2 thuộc mảng đã cho được gọi là HN4 nếu tổng tất cả
các phần tử trong nó là một số lẻ. Tìm số mảng con HN4 trong mảng đã cho.
Ghi chú: (Các) thư viện iostream, vector và string đã được khai báo, và namespace std đã
được sử dụng.
*/
int subMatrix(int arr[][1000], int row, int col){
	int count = 0;
	for (int i=0;i<row-1;i++){
		for (int j=0;j<col-1;j++){
			if((arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1]) % 2 != 0){
				count += 1;
			}
		}
	}
	return count;
}

void run_tests() {
    int arr1[3][1000] = {
        {1, 2, 3},
        {4, 5, 10},
        {7, 8, 9}
    };
    int arr2[3][1000] = {
        {1, 0, 2},
        {0, 3, 4},
        {2, 4, 5}
    };
    int arr3[2][1000] = {
        {1, 2, 3},
        {4, 5, 2}
    };

    cout << "--- Cau 12: findMaxColumn ---" << endl;
    cout << "Expected: 2, Result: " << findMaxColumn(arr1, 3, 3) << endl;

    cout << "\n--- Cau 13: diagonalProduct ---" << endl;
    cout << "Expected: 45, Result: " << diagonalProduct(arr1, 3, 3) << endl;

    cout << "\n--- Cau 14: isSymmetric ---" << endl;
    cout << "Expected: 0 (false), Result: " << isSymmetric(arr1, 3, 3) << endl;
    cout << "Expected: 1 (true), Result: " << isSymmetric(arr2, 3, 3) << endl;

    cout << "\n--- Cau 15: diagonalDiff ---" << endl;
    // (x,y) = (1,1). Diag 1: (0,0),(1,1),(2,2)=1+5+9=15. Diag 2: (0,2),(1,1),(2,0)=3+5+7=15. Diff = 0.
    cout << "Expected: 0, Result: " << diagonalDiff(arr1, 3, 3, 1, 1) << endl;

    cout << "\n--- Cau 16: ascendingRows ---" << endl;
    // arr1 has all 3 rows ascending.
    cout << "Expected: 3, Result: " << ascendingRows(arr1, 3, 3) << endl;

    cout << "\n--- Cau 17: primeColumns ---" << endl;
    // Col sums of arr3: 1+4=5 (prime), 2+5=7 (prime), 3+2=5 (prime).
    cout << "Expected: 3, Result: " << primeColumns(arr3, 2, 3) << endl;

    cout << "\n--- Cau 18: specialCells ---" << endl;
    // Sum rows arr3: 1+2+3=6, 4+5+2=11 (prime). Col sums: 5, 7, 5 (all prime).
    // Cells in row 1 are HN3 if their col sum is prime. (1,0), (1,1), (1,2) have col sums 5, 7, 5. All prime.
    cout << "Expected: 3, Result: " << specialCells(arr3, 2, 3) << endl;

    cout << "\n--- Cau 19: subMatrix ---" << endl;
    // arr3 2x2 submatrices:
    // [1 2] sum=12
    // [4 5]
    // [2 3] sum=14
    // [5 2]
    cout << "Expected: 0, Result: " << subMatrix(arr3, 2, 3) << endl;
}

int main(){
	run_tests();
	return 0;
}