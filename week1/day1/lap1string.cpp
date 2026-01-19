#include <iostream>
#include <string>
using namespace std;

// Khai báo các hàm (Bạn sẽ hiện thực mã trong các hàm này)
void cutString(string s, int index) {
    if (index > s.length())return;
	cout << s.substr(index, s.length() - index);
}

void findAllIndex(string s1, string s2) {
    char c = s2[0];
	bool found = false;
	for(int i = 0; i < s1.length(); i++){
		if(s1[i] == c){
			if (found) cout << " ";
			cout << i;
			found = true;
		}
	}
	if(!found) 
		cout << "-1";
}
/*
void replaceString(string s, string s1, string s2) {
    size_t pos = s.rfind(s1); // Tìm vị trí cuối cùng của s1 trong s
    if (pos != string::npos) {
        s.replace(pos, s1.length(), s2); // Thay thế s1 bằng s2 tại vị trí tìm được
    }
    cout << s << endl;
}
*/

void replaceString(string s, string s1, string s2) {
    while(s.find(s1) != string :: npos){
		s.replace(s.find(s1), s1.length(), s2);
	}
	cout << s << endl;
}

void deleteWord(string s, string s1) {
    while(s.find(s1) != string :: npos){
		s.erase(s.find(s1), s1.length());
	}
	cout << s;
}

string longestPalindrome(string s) {
	int n = s.length();
	if (n == 0) return "";

	int start = 0, maxLen = 1;

	for (int i = 0; i < n; i++){
		int left = i;
		int right = i;
		while (left >= 0 && right < n && s[left] == s[right]) {
			if (right - left + 1 > maxLen){
				start = left;
				maxLen = right - left + 1;
			}
			left--; right++;
		}

		left = i;
		right = i + 1;
		while (left >= 0 && right < n && s[left] == s[right]) {
			if (right - left + 1 > maxLen){
				start = left;
				maxLen = right - left + 1;
			}
			left--; right++;
		}
	}

	return s.substr(start, maxLen);
}

int longestUniqueSubstr(string s) {
    
    return 0;
}

// --- Các hàm Test ---

void run_tests() {
    cout << "--- Cau 6: cutString ---\n";
    cout << "Input: ('HelloWorld', 5) -> Output: "; cutString("HelloWorld", 5); cout << endl;
    cout << "Input: ('ABC', 10) -> Output: "; cutString("ABC", 10); cout << "(empty expected)\n";

    cout << "\n--- Cau 7: findAllIndex ---\n";
    cout << "Input: ('abababa', 'aba') -> Output: "; findAllIndex("abababa", "aba"); cout << endl;
    cout << "Input: ('hello', 'x') -> Output: "; findAllIndex("hello", "x"); cout << endl;

    cout << "\n--- Cau 8: replaceString ---\n";
    cout << "Input: ('banana', 'na', 'XX') -> Output: "; replaceString("banana", "na", "XX"); cout << endl;

    cout << "\n--- Cau 9: deleteWord ---\n";
    cout << "Input: ('banana', 'na') -> Output: "; deleteWord("banana", "na"); cout << endl;

    cout << "\n--- Cau 10: longestPalindrome ---\n";
    cout << "Input: 'babab' -> Result: " << longestPalindrome("babab") << endl;
    cout << "Input: 'cbbc' -> Result: " << longestPalindrome("cbbc") << endl;

    cout << "\n--- Cau 11: longestUniqueSubstr ---\n";
    cout << "Input: 'abcabcbb' -> Length: " << longestUniqueSubstr("abcabcbb") << endl;
    cout << "Input: 'bbbbb' -> Length: " << longestUniqueSubstr("bbbbb") << endl;
}


int main(){
	cout << "Hello world" << '\n';
	run_tests();
	return 0;
}