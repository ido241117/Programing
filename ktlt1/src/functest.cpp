#ifndef FUNCTEST_CPP
#define FUNCTEST_CPP

#include "../include/common.h"
#include "../include/task1.h"
#include "../include/task2.h"
#include "../include/task3.h"
#include "../include/task4.h"
#include <iostream>
using namespace std;

// Task 1: firstMeet() Test Cases

// TC_01: E1 = 0 (Cộng 29 EXP)
void tc_01() {
    int exp1 = 400, exp2 = 100;
    int result = firstMeet(exp1, exp2, 0);
    cout << "Input: EXP1=400, EXP2=100, E1=0" << endl;
    cout << "Result: " << result << endl;
}

// TC_02: E1 = 1 (Cộng 45 EXP, D lẻ)
void tc_02() {
    int exp1 = 300, exp2 = 200;
    int result = firstMeet(exp1, exp2, 1);
    cout << "Input: EXP1=300, EXP2=200, E1=1" << endl;
    cout << "Result: " << result << endl;
}

// TC_03: E1 = 2 (Cộng 75 EXP, Clamp MAX)
void tc_03() {
    int exp1 = 590, exp2 = 550;
    int result = firstMeet(exp1, exp2, 2);
    cout << "Input: EXP1=590, EXP2=550, E1=2" << endl;
    cout << "Result: " << result << endl;
}

// TC_04: E1 = 3 (Cộng cả 3: 149 EXP)
void tc_04() {
    int exp1 = 400, exp2 = 300;
    int result = firstMeet(exp1, exp2, 3);
    cout << "Input: EXP1=400, EXP2=300, E1=3" << endl;
    cout << "Result: " << result << endl;
}

// TC_05: E1 = 10 (Trong đoạn [4, 19] - Chỉ Thông tin 1)
void tc_05() {
    int exp1 = 300, exp2 = 200;
    int result = firstMeet(exp1, exp2, 10);
    cout << "Input: EXP1=300, EXP2=200, E1=10" << endl;
    cout << "Result: " << result << endl;
}

// TC_06: E1 = 40 (Trong đoạn [20, 49] - Chỉ Thông tin 2)
void tc_06() {
    int exp1 = 500, exp2 = 450;
    int result = firstMeet(exp1, exp2, 40);
    cout << "Input: EXP1=500, EXP2=450, E1=40" << endl;
    cout << "Result: " << result << endl;
}

// TC_07: E1 = 70 (Trong đoạn [66, 79] - Chuỗi tin 1 -> 2 thất bại)
void tc_07() {
    int exp1 = 500, exp2 = 100;
    int result = firstMeet(exp1, exp2, 70);
    cout << "Input: EXP1=500, EXP2=100, E1=70" << endl;
    cout << "Result: " << result << endl;
}

// TC_08: E1 = 70 (Trong đoạn [66, 79] - Chuỗi tin 1 -> 2 thành công)
void tc_08() {
    int exp1 = 500, exp2 = 190;
    int result = firstMeet(exp1, exp2, 70);
    cout << "Input: EXP1=500, EXP2=190, E1=70" << endl;
    cout << "Result: " << result << endl;
}

// TC_09: E1 = 81 (Full chuỗi 1->2->3 + Boost)
void tc_09() {
    int exp1 = 500, exp2 = 450;
    int result = firstMeet(exp1, exp2, 81);
    cout << "Input: EXP1=500, EXP2=450, E1=81" << endl;
    cout << "Result: " << result << endl;
}

// TC_10: E1 = 90 (Bị đứt chuỗi ở điều kiện EXP > 400)
void tc_10() {
    int exp1 = 500, exp2 = 300;
    int result = firstMeet(exp1, exp2, 90);
    cout << "Input: EXP1=500, EXP2=300, E1=90" << endl;
    cout << "Result: " << result << endl;
}

// TC_11: E1 ngoài khoảng [0, 99]
void tc_11() {
    int exp1 = 500, exp2 = 100;
    int result = firstMeet(exp1, exp2, 100);
    cout << "Input: EXP1=500, EXP2=100, E1=100" << endl;
    cout << "Result: " << result << endl;
}

// TC_12: Sherlock bị trừ âm tiền (Case 2)
void tc_12() {
    int exp1 = 10, exp2 = 200;
    int result = firstMeet(exp1, exp2, 50);
    cout << "Input: EXP1=10, EXP2=200, E1=50" << endl;
    cout << "Result: " << result << endl;
}

// TC_13: Test hàm traceLuggage()
void tc_13() {
    int HP1 = 333, EXP1 = 430, M1 = 890, E2 = 39;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    cout << "Input: HP1 = 333, EXP1 = 430, M1 = 890, E2 = 39" << endl;
    cout << "Result: " << result << endl;
}

// TC_14: E1 = 0 (Cộng 29 EXP)
void tc_14() {
    int exp1 = 400, exp2 = 300;
    int result = firstMeet(exp1, exp2, 0);
    cout << "Input: exp1 = 400, exp2 = 300, E1=0" << endl;
    cout << "Result: " << result << endl;
}

// TC_15: Test chaseTaxi - Ví dụ 4.5 (E3=59, abs(taxiPoint) > SPoint, thất bại)
void tc_15() {
    int HP1 = 400, EXP1 = 600, HP2 = 350, EXP2 = 500, E3 = 59;
    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "Input: HP1=400, EXP1=600, HP2=350, EXP2=500, E3=59" << endl;
    cout << "Output: HP1=" << HP1 << ", EXP1=" << EXP1 << ", HP2=" << HP2 << ", EXP2=" << EXP2 << endl;
    cout << "Result: " << result << " (Expected: -3318)" << endl;
}

// TC_16: Test chaseTaxi - Ví dụ 4.6 (E3=99, abs(taxiPoint) < SPoint, thành công)
void tc_16() {
    int HP1 = 400, EXP1 = 600, HP2 = 350, EXP2 = 500, E3 = 99;
    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "Input: HP1=400, EXP1=600, HP2=350, EXP2=500, E3=99" << endl;
    cout << "Output: HP1=" << HP1 << ", EXP1=" << EXP1 << ", HP2=" << HP2 << ", EXP2=" << EXP2 << endl;
    cout << "Result: " << result << " (Expected: 1422)" << endl;
    cout << "HP2 should be 385: " << (HP2 == 385 ? "PASS" : "FAIL") << endl;
}

// TC_17: Test chaseTaxi - Kiểm tra làm tròn với HP2=351 (ceil(351*1.1)=387)
void tc_17() {
    int HP1 = 400, EXP1 = 600, HP2 = 351, EXP2 = 500, E3 = 99;
    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "Input: HP1=400, EXP1=600, HP2=351, EXP2=500, E3=99" << endl;
    cout << "Output: HP1=" << HP1 << ", EXP1=" << EXP1 << ", HP2=" << HP2 << ", EXP2=" << EXP2 << endl;
    cout << "Result: " << result << endl;
}

// Task 4: checkPassword() Test Cases

// TC_18: Mật khẩu hợp lệ (return -10)
void tc_18() {
    string email = "pink@gmail.com";
    string s = "Abc123@xyz";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -10 - Valid password)" << endl;
}

// TC_19: Độ dài < 8 (return -1) - Ví dụ 4.7
void tc_19() {
    string email = "pink@gmail.com";
    string s = "123xyz";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -1 - Too short)" << endl;
}

// TC_20: Độ dài > 20 (return -2)
void tc_20() {
    string email = "pink@gmail.com";
    string s = "Abc123@xyz0123456789!";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -2 - Too long)" << endl;
}

// TC_21: Chứa se ở đầu chuỗi (return -300) 
void tc_21() {
    string email = "pink@gmail.com";
    string s = "pinkAbc123@";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -300 - Contains 'pink' at position 0)" << endl;
}

// TC_22: Chứa se ở vị trí 6 (return -306) - Ví dụ 4.8
void tc_22() {
    string email = "pink@gmail.com";
    string s = "012345pink#pink";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -306 - Contains 'pink' at position 6)" << endl;
}

// TC_23: Chứa 3 ký tự liên tiếp giống nhau ở đầu (return -400)
void tc_23() {
    string email = "pink@gmail.com";
    string s = "aaaBc123@xyz";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -400 - Triple 'a' at position 0)" << endl;
}

// TC_24: Chứa 3 ký tự liên tiếp giống nhau ở vị trí 5 (return -405)
void tc_24() {
    string email = "pink@gmail.com";
    string s = "Abc12!!!xyz@";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -405 - Triple '!' at position 5)" << endl;
}

// TC_25: Không chứa ký tự đặc biệt (return -5)
void tc_25() {
    string email = "pink@gmail.com";
    string s = "Abc123xyz";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -5 - No special character)" << endl;
}

// TC_26: Chứa đúng 2 ký tự liên tiếp (hợp lệ)
void tc_26() {
    string email = "pink@gmail.com";
    string s = "Abc11@xyz";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -10 - Valid, only 2 consecutive)" << endl;
}

// TC_27: Tất cả các ký tự đặc biệt (@, #, %, $, !)
void tc_27() {
    string email = "pink@gmail.com";
    string s = "Abc@#%$!123";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -10 - Valid with all special chars)" << endl;
}

// TC_28: Edge case - độ dài đúng 8
void tc_28() {
    string email = "pink@gmail.com";
    string s = "Abc123@z";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -10 - Valid, length=8)" << endl;
}

// TC_29: Edge case - độ dài đúng 20
void tc_29() {
    string email = "pink@gmail.com";
    string s = "Abc123@xyz0123456789";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -10 - Valid, length=20)" << endl;
}

// TC_30: Mật khẩu chỉ có số và ký tự đặc biệt
void tc_30() {
    string email = "pink@gmail.com";
    string s = "12345678@90";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -10 - Valid, numbers + special)" << endl;
}

// TC_31: Kiểm tra 4 ký tự liên tiếp giống nhau (lỗi ở vị trí đầu tiên)
void tc_31() {
    string email = "pink@gmail.com";
    string s = "Abcccc@123";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -402 - Four 'c' starting at position 2)" << endl;
}

// TC_32: Chứa se ở cuối chuỗi
void tc_32() {
    string email = "pink@gmail.com";
    string s = "Abc123@pink";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -307 - Contains 'pink' at position 7)" << endl;
}

// TC_33: Email khác, se khác
void tc_33() {
    string email = "john@example.com";
    string s = "Pass@123word";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -10 - Valid, different email)" << endl;
}

// TC_34: Chứa se nhưng có ký tự đặc biệt ở cuối
void tc_34() {
    string email = "john@example.com";
    string s = "12345john@";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -305 - Contains 'john' at position 5)" << endl;
}

// TC_35: Độ dài đúng 7 (quá ngắn)
void tc_35() {
    string email = "pink@gmail.com";
    string s = "Ab12@xy";
    int result = checkPassword(email, s);
    cout << "Input: email=\"" << email << "\", s=\"" << s << "\"" << endl;
    cout << "Result: " << result << " (Expected: -1 - Length=7, too short)" << endl;
}

// Task 5: findCorrectPassword() Test Cases

// TC_36: Ví dụ 4.9 - Một mật khẩu xuất hiện nhiều nhất
void tc_36() {
    string arr_pwds[] = {"123xyz", "pink#pink", "pink123", "xxxx@xxxx", "pink#pink", "pink123", "pink123"};
    int num_pwds = 7;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"123xyz\", \"pink#pink\", \"pink123\", \"xxxx@xxxx\", \"pink#pink\", \"pink123\", \"pink123\"}" << endl;
    cout << "Result: " << result << " (Expected: 2 - 'pink123' appears 3 times, first at index 2)" << endl;
}

// TC_37: Ví dụ 4.10 - Hai mật khẩu cùng tần suất, chọn mật khẩu dài hơn
void tc_37() {
    string arr_pwds[] = {"pink123", "xxxx@xxxx", "123xyz", "pink#pink", "pink#pink", "pink123"};
    int num_pwds = 6;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"pink123\", \"xxxx@xxxx\", \"123xyz\", \"pink#pink\", \"pink#pink\", \"pink123\"}" << endl;
    cout << "Result: " << result << " (Expected: 3 - Both appear 2 times, 'pink#pink' is longer, first at index 3)" << endl;
}

// TC_38: Tất cả mật khẩu đều khác nhau (chọn mật khẩu dài nhất ở vị trí đầu tiên)
void tc_38() {
    string arr_pwds[] = {"abc@123", "xy#45678", "test@1", "longer#password"};
    int num_pwds = 4;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"abc@123\", \"xy#45678\", \"test@1\", \"longer#password\"}" << endl;
    cout << "Result: " << result << " (Expected: 3 - All appear 1 time, 'longer#password' is longest)" << endl;
}

// TC_39: Tất cả mật khẩu giống nhau
void tc_39() {
    string arr_pwds[] = {"abc@123", "abc@123", "abc@123", "abc@123"};
    int num_pwds = 4;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"abc@123\", \"abc@123\", \"abc@123\", \"abc@123\"}" << endl;
    cout << "Result: " << result << " (Expected: 0 - All same, return first position)" << endl;
}

// TC_40: Mật khẩu xuất hiện nhiều nhất ở cuối mảng
void tc_40() {
    string arr_pwds[] = {"abc@123", "xyz#456", "test@1", "xyz#456", "xyz#456"};
    int num_pwds = 5;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"abc@123\", \"xyz#456\", \"test@1\", \"xyz#456\", \"xyz#456\"}" << endl;
    cout << "Result: " << result << " (Expected: 1 - 'xyz#456' appears 3 times, first at index 1)" << endl;
}

// TC_41: Hai mật khẩu cùng tần suất và độ dài (chọn cái xuất hiện đầu tiên)
void tc_41() {
    string arr_pwds[] = {"abc@123", "xyz#456", "abc@123", "xyz#456"};
    int num_pwds = 4;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"abc@123\", \"xyz#456\", \"abc@123\", \"xyz#456\"}" << endl;
    cout << "Result: " << result << " (Expected: 0 - Both appear 2 times, same length, return first)" << endl;
}

// TC_42: Mảng có 1 phần tử duy nhất
void tc_42() {
    string arr_pwds[] = {"abc@123"};
    int num_pwds = 1;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"abc@123\"}" << endl;
    cout << "Result: " << result << " (Expected: 0 - Only one password)" << endl;
}

// TC_43: Ba mật khẩu khác nhau cùng xuất hiện 2 lần, độ dài khác nhau
void tc_43() {
    string arr_pwds[] = {"a@1", "bb@22", "ccc@333", "a@1", "bb@22", "ccc@333"};
    int num_pwds = 6;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"a@1\", \"bb@22\", \"ccc@333\", \"a@1\", \"bb@22\", \"ccc@333\"}" << endl;
    cout << "Result: " << result << " (Expected: 2 - All appear 2 times, 'ccc@333' is longest, first at index 2)" << endl;
}

// TC_44: Mật khẩu dài nhất xuất hiện ít nhất
void tc_44() {
    string arr_pwds[] = {"a@1", "a@1", "a@1", "verylongpassword@123"};
    int num_pwds = 4;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"a@1\", \"a@1\", \"a@1\", \"verylongpassword@123\"}" << endl;
    cout << "Result: " << result << " (Expected: 0 - 'a@1' appears 3 times, more than long password)" << endl;
}

// TC_45: Kiểm tra với mật khẩu có ký tự đặc biệt và độ dài bằng nhau
void tc_45() {
    string arr_pwds[] = {"aaa@111", "bbb#222", "ccc$333", "aaa@111", "bbb#222", "bbb#222"};
    int num_pwds = 6;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "Input: arr_pwds = {\"aaa@111\", \"bbb#222\", \"ccc$333\", \"aaa@111\", \"bbb#222\", \"bbb#222\"}" << endl;
    cout << "Result: " << result << " (Expected: 1 - 'bbb#222' appears 3 times, first at index 1)" << endl;
}


#endif