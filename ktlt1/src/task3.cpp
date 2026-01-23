#include "../include/common.h"
#include "../include/task3.h"

int maxDuongCheo(int matrix[10][10], int a, int b) {
    int max = matrix[0][0];
	for (int i = 0; i < 10; i++) {
        int j = i - (a - b); // Rut ra tu cong thuc i - j = a - b
        if (j >= 0 && j < 10) {
            if (max < matrix[i][j]){max = matrix[i][j];};
        }
    }
	
	for (int i = 0; i < 10; i++) {
        int j = (a + b) - i; // Rut ra tu cong thuc i + j = a + b
        if (j >= 0 && j < 10) {
            if (max < matrix[i][j]){max = matrix[i][j];};
        }
    }
	return max;
}


// TODO: Implement Task 3 functions here
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3){
	int arr[10][10];
	int row=0,col=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			arr[j][i] = ((E3 *j) + (i *2)) *(i -j);
			if(arr[j][i] > 2*E3){row += 1;} ;
			if(arr[j][i] < -E3){col += 1;} ;
		}
	}
	int taxiPoint = arr[col = giaiMaSo(col)][row = giaiMaSo(row)];
	int SPoint = maxDuongCheo(arr, col, row);
	
	if(abs(taxiPoint) < SPoint)
	{
		EXP1 = clampCeil(EXP1, 112, 100, MIN_EXP, MAX_EXP);
		EXP2 = clampCeil(EXP2, 112, 100, MIN_EXP, MAX_EXP);
		HP1 = clampCeil(HP1, 11, 10, MIN_HP, MAX_HP);
		HP2 = clampCeil(HP2, 11, 10, MIN_HP, MAX_HP);
		return SPoint;
	}else{
		EXP1 = clampCeil(EXP1, 88, 100, MIN_EXP, MAX_EXP);
		EXP2 = clampCeil(EXP2, 88, 100, MIN_EXP, MAX_EXP);
		HP1 = clampCeil(HP1, 9, 10, MIN_HP, MAX_HP);
		HP2 = clampCeil(HP2, 9, 10, MIN_HP, MAX_HP);
		return taxiPoint;
	}

}
