#include "../include/common.h"
#include "../include/task4.h"

bool checkspecial(char s){
	char arr[] = {'@', '#', '%', '$', '!'};
	bool special = false;
	for(int i=0;i<5;i++){
		if(s == arr[i]){
			special =true;
		}
	}
	return special;
}

//email = "pink@gmail.com";
//s = "123xyz";
int checkPassword(string email, string s){
	if(s.length() < 8){return -1;}
	if(s.length() > 20){return -2;}
		
	string se = email.substr(0,email.find("@"));
	if(s.find(se) != string::npos){
		return -(300 + s.find(se));
	}
	
	bool special = false;
	for (int i=0;i<s.length();i++)
	{
		if(checkspecial(s[i])){special = true;}	
		
		if(i < s.length() - 2 && s[i] == s[i+1] && s[i+1] == s[i+2]){
			return -(400 + i);
		}
	}
	if(special == false){
		return -5;
	}

	return -10;
}

int findCorrectPassword(string* arr_pwds, int num_pwds){
	int max =0;
	int temp =0;
	for (int i = 0; i < num_pwds; i++) 
	{
		int count = 0;
		for (int j = 0; j < num_pwds; j++)
		{
			if(arr_pwds[i] == arr_pwds[j]){count++;}	
		}
		if(max < count)
		{
			max =count;
			temp =i;
		}
		if(max == count && arr_pwds[i].length() > arr_pwds[temp].length() )
		{
			max =count;
			temp =i;
		}
	}
	return temp;
}