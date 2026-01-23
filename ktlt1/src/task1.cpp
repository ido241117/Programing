#include "../include/common.h"
#include "../include/task1.h"

int case21(int& EXP1, int& EXP2, int E1)
{
	EXP2 += (int)ceil(E1 / 4.0 + 19);
	EXP2 = clamp(EXP2, 0, 600);
	EXP1 -= E1;
	EXP1 = clamp(EXP1, 0, 600);

	return EXP1 + EXP2;
}
int case22(int& EXP1, int& EXP2, int E1)
{
	EXP2 += (int)ceil(E1 / 9.0 + 21);
	EXP2 = clamp(EXP2, 0, 600);
	EXP1 -= E1;
	EXP1 = clamp(EXP1, 0, 600);

	return EXP1 + EXP2;
}
int case23(int& EXP1, int& EXP2, int E1){
{
	EXP2 += (int)ceil(E1 / 16.0 + 17);
	EXP2 = clamp(EXP2, 0, 600);
	EXP1 -= E1;
	EXP1 = clamp(EXP1, 0, 600);

	return EXP1 + EXP2;
}
}
int case24(int& EXP1, int& EXP2, int E1){
	EXP2 += (int)ceil(E1 / 4.0 + 19);
	EXP2 = clamp(EXP2, 0, 600);
	if(EXP2 > 200)
	{
		EXP2 += (int)ceil(E1 / 9.0 + 21);
		EXP2 = clamp(EXP2, 0, 600);
	}
	EXP1 -= E1;
	return EXP1 + EXP2;
}
int case25(int& EXP1, int& EXP2, int E1){
	EXP2 += (int)ceil(E1 / 4.0 + 19);
	EXP2 = clamp(EXP2, 0, 600);
	EXP2 += (int)ceil(E1 / 9.0 + 21);
	EXP2 = clamp(EXP2, 0, 600);
	if(EXP2 > 400)
	{
		EXP2 += (int)ceil(E1 / 16.0 + 17);
		EXP2 = clamp(EXP2, 0, 600);
		EXP2 *= 1.15;
		EXP2 = clamp(EXP2, 0, 600);
	}
	EXP1 -= E1;
	EXP1 = clamp(EXP1, 0, 600);
	
	return EXP1 + EXP2;
}

int case1(int& EXP1, int& EXP2, int E1)
{
	if(E1 ==0){EXP2 += 29;}
	else if(E1 ==1){EXP2 += 45;}
	else if(E1 ==2){EXP2 += 75;}
	else if(E1 ==3){EXP2 += (29+45+75);}
	
	EXP2 = clamp(EXP2, 0, 600);

	int D = E1*3 + EXP1*7;

	if(D%2==0){EXP1 = (int)ceil(EXP1 + D / 200.0) ;}
	else{EXP1 = (int)ceil(EXP1 - D / 100.0);}
	EXP1 = clamp(EXP1, 0, 600);
	return EXP1 + EXP2;
}

int case2(int& EXP1, int& EXP2, int E1)
{
	if (E1 <= 19){return case21(EXP1, EXP2, E1);}
	else if(E1 <= 49){return case22(EXP1, EXP2, E1);}
	else if(E1 <= 65){return case23(EXP1, EXP2, E1);}
	else if(E1 <= 79){return case24(EXP1, EXP2, E1);}
	else if(E1 <= 99){return case25(EXP1, EXP2, E1);}
}


int firstMeet(int& EXP1, int& EXP2, int E1)
{
	if(E1 < 0 || E1 > 99)
	{
		return -99;
	}
	else if(E1 <= 3)
	{
		return case1(EXP1, EXP2, E1);
	}
	else if(E1 <= 99)
	{
		return case2(EXP1, EXP2, E1);
	}
	return 0;
}
