#include "../include/common.h"
#include "../include/task2.h"

int nearestPerfectSquare(int a) {
	int lower = (int)std::sqrt(a);
	int upper = lower + 1;
	int lowerSq = lower * lower;
	int upperSq = upper * upper;
	if (a - lowerSq <= upperSq - a) {
		return lowerSq;
	} else {
		return upperSq;
	}
}

double P1(int EXP1) {
	double S = nearestPerfectSquare(EXP1);
	if(EXP1 >= S){return 1;}
	return ((EXP1 / S) + 80.0) / 123.0;
}

void step1(int& HP1, int& M1)
{
	if(HP1 < 200)
	{
		HP1 = clampCeil(HP1, 13, 10, MIN_HP, MAX_HP);
		M1 = clamp(M1 - 150, MIN_M, MAX_M);
	}else
	{
		HP1 = clampCeil(HP1, 11, 10, MIN_HP, MAX_HP);
		M1 = clamp(M1 - 70, MIN_M, MAX_M);
	}

}

void step2(int& EXP1, int& M1)
{
	if(EXP1 < 400)
	{
		M1 = clamp(M1 - 200, MIN_M, MAX_M);
		EXP1 = clampCeil(EXP1, 113, 100, MIN_EXP, MAX_EXP);
	}else
	{
		M1 = clamp(M1 - 120, MIN_M, MAX_M);
		EXP1 = clampCeil(EXP1, 113, 100, MIN_EXP, MAX_EXP);
	}
}

void step3(int& EXP1, int& M1)
{
	if(EXP1 < 300)
	{
		M1 = clamp(M1 - 100, MIN_M, MAX_M);
	}else
	{
		M1 = clamp(M1 - 120, MIN_M, MAX_M);
		EXP1 = clampCeil(EXP1, 9, 10, MIN_EXP, MAX_EXP);
	}
}


void case2(int& HP1, int& EXP1, int& M1, int E2)
{
	step1(HP1, M1);
	if(M1==0){return;}
	step2(EXP1, M1);
	if(M1==0){return;}
	step3(EXP1, M1);
	
}

void case1(int& HP1, int& EXP1, int& M1, int E2)
{
	int i =1;
	int half = M1/2;
	while(M1 > half)
	{
		if(i==1){
			step1(HP1, M1);
			i =2;
		}else if(i==2){
			step2(EXP1, M1);
			i =3;
		}else{
			step3(EXP1, M1);
			i =1;
		}
	}
}

double P2(int& HP1, int& EXP1, int& M1, int E2)
{
	if(E2%2==0){
		case2(HP1, EXP1, M1, E2);
	}
	else
	{
		case1(HP1, EXP1, M1, E2);
	}

	HP1 = clampCeil(HP1, 83, 100, MIN_HP, MAX_HP);
	EXP1 = clampCeil(EXP1, 117, 100, MIN_EXP, MAX_EXP);
	
	return P1(EXP1);
}

double P3(int E2)
{
	int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	return (float)P[giaiMaSo(E2)] / 100;
}

// TODO: Implement Task 2 functions here
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
	if(E2 < 0 || E2 > 99){return -99;}
	
	double p1 = P1(EXP1);
	double p2 = P2(HP1, EXP1, M1, E2);
	double p3 = P3(E2);

	if(p1 + p2 + p3 < 1.5)
	{
		HP1 = clampCeil(HP1, 85, 100, MIN_HP, MAX_HP);
		EXP1 = clampCeil(EXP1, 115, 100, MIN_EXP, MAX_EXP);
	}else
	{
		HP1 = clampCeil(HP1, 9, 10, MIN_HP, MAX_HP);
		EXP1 = clampCeil(EXP1, 12, 10, MIN_EXP, MAX_EXP);
	}
	return HP1 + EXP1 + M1;
}