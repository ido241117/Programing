#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

int mysum(int a, int b){
	return (a + b);
}

void reverse(char str[]){
	// Hàm reverse này lấy con trỏ đầu và cuối
	std :: reverse(str, str + strlen(str));
}

void recover(char signal[]) {
    int i = 0;
    while (signal[i] != '\0') {
        if (signal[i] >= 'A' && signal[i] <= 'Z') {
            signal[i] = signal[i] + 32; // Chuyển thành chữ thường
        } else if (signal[i] >= 'a' && signal[i] <= 'z') {
            signal[i] = signal[i] - 32; // Chuyển thành chữ hoa
        }
        // Ký tự khác giữ nguyên
        i++;
    }
}

int find(char str[], char substr[]){
	int len_str = 0;
	int len_substr = 0;
	while(str[len_str] != '\0') len_str++;
	while(substr[len_substr] != '\0') len_substr++;

	for (int i = 0; i <= len_str - len_substr; i++){
		int j = 0;
		while (j < len_substr && str[i + j] == substr[j]){
			j++;
		}
		if (j == len_substr) return i;
	}

	return -1;
}

void printFirstRepeatedWord(char str[]){
	int len_str = 0;
	while(str[len_str] != '\0') len_str++;

	for (int i = 0; i < len_str; i++){
		for (int j = 0; j < i; j++){
			if(str[j] == str[i]){
				std :: cout << str[j] << '\n';
				return;
			}
		}
	}
	std :: cout << "No Repetition." << '\n';
}

void process(const char str[], char outstr[]) {
	int i = 0;
	int j = 0;
	
	while (str[i] == ' ') i++;
	
	bool lastIsSpace = false;
	while(str[i] != '\0'){
		if(str[i] != ' '){
			outstr[j++] = str[i];
			lastIsSpace = false;
		}else if(!lastIsSpace){
			outstr[j++] = str[i];
			lastIsSpace = true;
		}
		i++;
	}
	if(outstr[j-1] == ' ') {j--;}
	outstr[j] = '\0';
}

void test_process(const char* input) {
    char output[100] = {0}; // Cấp phát buffer đủ lớn
    process(input, output);
    std::cout << "Input:  [" << input << "]\n";
    std::cout << "Output: [" << output << "]\n";
    std::cout << "-------------------\n";
}

void run_tests() {
    std::cout << "--- Cau 1: mysum ---\n";
    std::cout << "Input: (5, 6) -> Output: " << mysum(5, 6) << std::endl;

    std::cout << "\n--- Cau 2: reverse ---\n";
    char mychar[] = "abc";
    std::cout << "Input: 'abc' -> ";
    reverse(mychar);
    std::cout << "Output: " << mychar << std::endl;

    std::cout << "\n--- Cau 3: recover ---\n";
    char s[] = "AbC123xYz";
    std::cout << "Input: 'AbC123xYz' -> ";
    recover(s);
    std::cout << "Output: " << s << std::endl;

    std::cout << "\n--- Cau 4: find ---\n";
    char s1[] = "abcd";
    char s2[] = "bc";
    std::cout << "Input: ('abcd', 'bc') -> Output: " << find(s1, s2) << std::endl;

    std::cout << "\n--- Cau 5: printFirstRepeatedWord ---\n";
    char s3[] = "abcd";
    std::cout << "Input: 'abcd' -> Output: "; printFirstRepeatedWord(s3);
    char s4[] = "abcda";
    std::cout << "Input: 'abcda' -> Output: "; printFirstRepeatedWord(s4);

    std::cout << "\n--- Cau 6: process ---\n";
    test_process("  a  b  ");
    test_process("hello    world a ");
}

int main(){
	std :: cout << "Starting Tests..." << '\n';
	run_tests();
	return 0;
}