# WEEK 2: PYTHON FUNDAMENTALS (Day 8 - Day 14)

"""
Nội dung Tuần 2: Biến, kiểu dữ liệu, toán tử, nhập xuất.
Mỗi ngày gồm: Lý thuyết cơ bản + 15 bài tập (Dễ -> Khó).
"""

# ==========================================
# NGÀY 8: BIẾN VÀ CÁCH ĐẶT TÊN (VARIABLES)
# ==========================================
"""
### LÝ THUYẾT:
1. Biến là gì: Nơi lưu trữ giá trị trong bộ nhớ.
2. Cú pháp: ten_bien = gia_tri
3. Quy tắc đặt tên:
   - Phải bắt đầu bằng chữ cái hoặc dấu gạch dưới (_).
   - Không chứa khoảng trắng hoặc ký tự đặc biệt (@, #, $, ...).
   - Không trùng với từ khóa (print, if, while...).
   - Nên dùng snake_case (ví dụ: my_variable_name).

### BÀI TẬP NGÀY 8:
1. Khai báo một biến tên là 'name' và gán tên của bạn.
2. Khai báo một biến 'age' gán tuổi của bạn.
3. Tạo biến 'x' bằng 5, 'y' bằng 10. Tạo biến 'z' là tổng của x và y.
4. Đổi giá trị của 2 biến x và y cho nhau (Gợi ý: dùng biến tạm hoặc cú pháp x, y = y, x).
5. Kiểm tra xem tên biến '1st_name' có hợp lệ không? Giải thích.
6. Tạo một hằng số (biến không thay đổi) chứa số PI = 3.14.
7. Khai báo 3 biến trên một dòng duy nhất.
8. Tạo biến 'message' chứa câu chào "Chào mừng đến với Python!".
9. In ra kiểu dữ liệu của biến 'age' bằng hàm type().
10. Thử gán một giá trị mới cho biến 'name' đã tạo ở bài 1 và in ra.
11. Tạo biến 'is_student' gán giá trị True.
12. Đặt tên biến cho: "Số lượng học sinh trong lớp". (Dùng snake_case).
13. Thử in ra một biến chưa khai báo và quan sát lỗi.
14. Tạo biến 'a' = "10" (chuỗi). Thử cộng x (bài 3) với a. Quan sát lỗi.
15. (Nâng cao) Giải thích tại sao Python được gọi là ngôn ngữ "dynamic typing" dựa trên cách dùng biến.
"""

# ==========================================
# NGÀY 9: KIỂU SỐ NGUYÊN VÀ SỐ THỰC (INT & FLOAT)
# ==========================================
"""
### LÝ THUYẾT:
1. int: Số nguyên (không có dấu phẩy), ví dụ: 1, -5, 1000.
2. float: Số thực (có dấu phẩy động), ví dụ: 3.14, -0.5, 2.0.
3. Các phép toán: +, -, *, /, // (chia lấy nguyên), % (chia lấy dư), ** (lũy thừa).

### BÀI TẬP NGÀY 9:
1. Tính 25 + 30.
2. Tính 100 - 45.
3. Tính 12 * 12.
4. Chia 10 / 3 và quan sát kết quả (float).
5. Chia lấy phần nguyên của 10 cho 3 (//).
6. Chia lấy phần dư của 10 cho 3 (%).
7. Tính 2 mũ 10 (2^10).
8. Tính diện tích hình chữ nhật có chiều dài 5.5 và chiều rộng 3.2.
9. Chuyển đổi số thực 9.8 thành số nguyên (ép kiểu).
10. Tính giá trị biểu thức: 5 + 10 * 2. Giải thích thứ tự ưu tiên.
11. Tính chu vi hình tròn bán kính r = 4.5 (P = 2 * PI * r).
12. Tạo một biến 'balance = 100.5'. Cộng thêm 50 vào balance và in ra.
13. Kiểm tra xem 15 là số chẵn hay lẻ bằng phép toán %.
14. Tính trung bình cộng của 3 số: 7, 8.5, 9.
15. (Nâng cao) Tính căn bậc 2 của 16 (Gợi ý: lũy thừa 0.5).
"""

# ==========================================
# NGÀY 10: KIỂU CHUỖI VÀ BOOLEAN (STRING & BOOL)
# ==========================================
"""
### LÝ THUYẾT:
1. String: Văn bản, đặt trong ' ' hoặc " ".
   - Nối chuỗi: +. Lặp chuỗi: *.
   - F-string: f"Chào {name}".
2. Boolean: Chỉ có 2 giá trị: True hoặc False.

### BÀI TẬP NGÀY 10:
1. Nối 2 chuỗi "Học" và "Python" lại với nhau.
2. In ra chuỗi "Python" 10 lần bằng toán tử *.
3. Lấy độ dài của chuỗi "Hello World" (dùng hàm len()).
4. Chuyển chuỗi "python" thành chữ hoa hoàn toàn.
5. Kiểm tra xem chuỗi "Python" có nằm trong "I love Python" không.
6. Thay thế từ "Python" bằng "Java" trong câu "I like Python".
7. Dùng f-string để in ra: "Tôi là [tên], năm nay tôi [tuổi] tuổi".
8. Cắt chuỗi (Slicing): Lấy 3 ký tự đầu của chuỗi "Programming".
9. Đảo ngược chuỗi "abcde".
10. Tạo biến is_raining = True. In ra giá trị đảo ngược của nó (dùng 'not').
11. So sánh 5 > 3 và in ra kết quả boolean.
12. So sánh 10 == "10" và in ra kết quả.
13. Chuyển số 123 thành chuỗi "123".
14. Kiểm tra xem chuỗi "   " (chứa dấu cách) có phải chuỗi rỗng không?
15. (Nâng cao) Tách câu "Táo, Cam, Xoài" thành một danh sách các từ.
"""

# ==========================================
# NGÀY 11: TOÁN TỬ SỐ HỌC, SO SÁNH, LOGIC
# ==========================================
"""
### LÝ THUYẾT:
1. So sánh: ==, !=, >, <, >=, <=.
2. Logic: and, or, not.
   - and: Cả hai đều True -> True.
   - or: Một trong hai True -> True.

### BÀI TẬP NGÀY 11:
1. Kiểm tra 15 có lớn hơn 10 VÀ nhỏ hơn 20 không.
2. Kiểm tra một số x có phải số dương chẵn không (x > 0 and x % 2 == 0).
3. Cho a = 5, b = 10. Kiểm tra xem (a + b) có bằng 15 không.
4. Kiểm tra xem 'apple' có bằng 'Apple' không.
5. In kết quả của: True or False.
6. In kết quả của: not (10 > 5).
7. Kiểm tra một năm có phải năm nhuận không (Gợi ý: chia hết cho 4 nhưng không cho 100, hoặc chia hết cho 400).
8. Kiểm tra xem một số có nằm ngoài khoảng [1, 100] không.
9. So sánh 3 số a, b, c và tìm số lớn nhất (dùng toán tử so sánh).
10. Cho x = 7. Kiểm tra 5 < x < 10 (cách viết rút gọn trong Python).
11. Kết quả của expression: (5 > 2) and (3 < 1).
12. Kết quả của expression: (10 == 10) or (1 == 2).
13. Dùng toán tử gán kết hợp: x = 10; x += 5. In x.
14. Kiểm tra xem một ký tự có phải là nguyên âm (a, e, i, o, u) không.
15. (Nâng cao) Giải thích "Short-circuit evaluation" trong toán tử 'and' và 'or'.
"""

# ==========================================
# NGÀY 12: NHẬP XUẤT DỮ LIỆU (INPUT & OUTPUT)
# ==========================================
"""
### LÝ THUYẾT:
1. print(): Xuất dữ liệu. Có tham số sep=, end=.
2. input(): Nhập dữ liệu (luôn trả về kiểu chuỗi). Cần ép kiểu nếu muốn dùng số: int(input()).

### BÀI TẬP NGÀY 12:
1. Yêu cầu người dùng nhập tên và in ra: "Chào [tên]!".
2. Nhập vào 2 số nguyên, tính tổng và in ra.
3. Nhập vào bán kính hình tròn, tính diện tích.
4. Nhập vào năm sinh, tính tuổi hiện tại.
5. In 3 từ "Tôi", "Yêu", "Python" trên cùng 1 dòng, ngăn cách bởi dấu gạch ngang (-).
6. Nhập một số thực, in ra dưới dạng chỉ có 2 chữ số thập phân (dùng format hoặc f-string).
7. Nhập vào một câu, in ra độ dài của câu đó.
8. Viết chương trình nhập vào cân nặng (kg) và chiều cao (m), tính chỉ số BMI.
9. In ra: "Dòng 1" và "Dòng 2" mà không dùng 2 lệnh print (Gợi ý: \n).
10. Nhập vào số giây, đổi sang định dạng Phút : Giây.
11. In ra bảng cửu chương của một số người dùng nhập vào (chưa học vòng lặp thì viết thủ công 10 dòng print).
12. Nhập mật khẩu và in ra "Độ dài mật khẩu là: [x] ký tự".
13. Dùng lệnh print để vẽ một hình tam giác đơn giản bằng dấu *.
14. Nhập vào giá tiền và phần trăm giảm giá, in ra số tiền phải trả.
15. (Nâng cao) Tìm hiểu cách dùng hàm print để ghi nội dung vào một file text (tham số file=).
"""

# ==========================================
# NGÀY 13: THỰC HÀNH TỔNG HỢP TUẦN 2
# ==========================================
"""
### MỤC TIÊU: Vận dụng toàn bộ kiến thức tuần 2 để giải quyết bài toán thực tế.

### BÀI TẬP TỔNG HỢP:
1. **Quản lý học sinh**: Nhập tên, toán, lý, hóa. Tính điểm trung bình và in ra bảng điểm đẹp mắt.
2. **Chuyển đổi tiền tệ**: Nhập số tiền USD, tỷ giá, chuyển sang VND.
3. **Tính lương**: Nhập số giờ làm, lương mỗi giờ. Tính tổng lương (có tính thêm 1.5 lần nếu làm thêm > 40h - dùng logic toán học nếu chưa học if).
4. **Trò chơi đoán số**: Máy có số x = 7, người dùng nhập số đoán. In ra kết quả so sánh (Đúng/Sai).
5. **Tách tên**: Nhập Họ và Tên đầy đủ, tách ra Họ và Tên (giả sử chỉ có 2 chữ).
6. **Ứng dụng Shopping**: Nhập giá 3 món hàng, tính tổng tiền, tính thuế VAT 10%, in hóa đơn.
... (Tiếp tục thiết kế thêm bài tập ...)
"""

# ==========================================
# NGÀY 14: NGHỈ / ÔN TẬP
# ==========================================
"""
- Xem lại các bài tập khó trong tuần.
- Tự tạo ra 5 bài tập mới dựa trên những gì đã học.
- Chuẩn bị cho Tuần 3: Cấu trúc điều kiện (if-else).
"""
