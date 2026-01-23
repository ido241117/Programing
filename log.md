# Learning Log

## 2026-01-18
- **Chủ đề**: Kỹ thuật lập trình - C-String và C++ String Class.
- **Nội dung hoàn thành**:
    - **C-String**: Thực hiện các hàm đảo ngược chuỗi (`reverse`), chuyển đổi hoa/thường (`recover`), tìm chuỗi con (`find`), in từ lặp lại (`printFirstRepeatedWord`), và xử lý khoảng trắng thừa (`process`).
    - **C++ String Class**: Thực hiện cắt chuỗi (`cutString`), tìm tất cả vị trí ký tự (`findAllIndex`), thay thế chuỗi con cuối cùng (`replaceString`), xóa từ (`deleteWord`), và tìm chuỗi đối xứng dài nhất (`longestPalindrome`).
- **Tình trạng**: Đã hoàn thành mục tiêu của Ngày 1 đến Ngày 4 trong kế hoạch.

## 2026-01-19
- **Chủ đề**: Kỹ thuật lập trình - Mảng 2 chiều.
- **Nội dung hoàn thành**:
    - **Mảng 2 chiều**:
        - Tìm cột có tổng lớn nhất (`findMaxColumn`).
        - Tính tích đường chéo chính (`diagonalProduct`).
        - Kiểm tra ma trận đối xứng (`isSymmetric`).
        - Tính hiệu đường chéo qua một ô (`diagonalDiff`).
        - Đếm số hàng tăng dần (`ascendingRows`).
        - Đếm số cột có tổng là số nguyên tố (`primeColumns`).
        - Tìm ô `HN3` (tổng hàng và cột là số nguyên tố) (`specialCells`).
        - Đếm mảng con 2x2 có tổng lẻ (`subMatrix`).
- **Tình trạng**: Đã hoàn thành mục tiêu của Ngày 5 và Ngày 6 trong kế hoạch.

## 2026-01-20
- **Chủ đề**: Kỹ thuật lập trình - File I/O.
- **Nội dung hoàn thành**:
    - **File I/O**:
        - Tính tổng các số từ file (`calSum`).
        - Chuyển đổi ký tự thường sang hoa và xuất ra file (`uppercase`).
        - Đọc ma trận từ file, tìm giá trị lớn nhất theo dòng và toàn bộ (`process`).
        - Xếp loại học sinh dựa trên điểm số đọc từ file (`studendGrading`).
        - Tính tiền hóa đơn khách hàng từ số liệu sản phẩm và đơn hàng (`calMoney`).
        - Quản lý thư viện: Kiểm tra tác giả và sách trong thư viện (`manage`).
- **Tình trạng**: Đã hoàn thành các bài tập File I/O (tương ứng Tuần 2 trong kế hoạch).

## 2026-01-21 đến 2026-01-23
- **Chủ đề**: Kỹ thuật lập trình - Dự án tổng hợp "Study in Pink - Part 1".
- **Mô tả dự án**: Bài tập lớn về Sherlock Holmes và Watson, áp dụng kiến thức tổng hợp từ các tuần trước.
- **Nội dung hoàn thành**:
    - **Task 1 - firstMeet()**: Xử lý cuộc gặp gỡ đầu tiên giữa Sherlock và Watson.
        - Xử lý các trường hợp E1 từ 0-3: Cập nhật EXP2 dựa trên bảng giá trị, tính D và cập nhật EXP1.
        - Xử lý các trường hợp E1 từ 4-99: Chuỗi thông tin 1-5 với điều kiện tích lũy, boost 15% khi đủ điều kiện.
        - Áp dụng clamp để giữ giá trị trong khoảng [0, 600].
    - **Task 2 - traceLuggage()**: Truy tìm hành lý qua 3 con đường.
        - Con đường 1: Tính xác suất P1 dựa trên số chính phương gần nhất.
        - Con đường 2: Thực hiện chuỗi sự kiện (mua thức ăn/nước, thuê xe, giúp người vô gia cư), xử lý E2 chẵn/lẻ.
        - Con đường 3: Lấy P3 từ mảng cố định dựa trên giải mã số.
        - Cập nhật HP1, EXP1 dựa trên tổng xác suất.
    - **Task 3 - chaseTaxi()**: Đuổi theo taxi với ma trận 10x10.
        - Tính điểm Taxi tại mỗi vị trí theo công thức ((E3*j) + (i*2)) * (i-j).
        - Tìm điểm gặp nhau dựa trên số lượng điểm thỏa điều kiện.
        - Tìm giá trị max trên 2 đường chéo qua điểm gặp.
        - So sánh và cập nhật HP/EXP cho cả Sherlock và Watson.
    - **Task 4 - checkPassword() & findCorrectPassword()**: Xác thực và tìm mật khẩu.
        - Kiểm tra độ dài [8, 20], ký tự đặc biệt, không chứa email substring.
        - Kiểm tra không có quá 2 ký tự liên tiếp giống nhau.
        - Tìm mật khẩu xuất hiện nhiều nhất, ưu tiên độ dài khi tần suất bằng nhau.
    - **Kỹ năng áp dụng**:
        - Xử lý điều kiện phức tạp và logic phân nhánh.
        - Làm việc với ma trận 2D, tìm kiếm và so sánh.
        - Xử lý chuỗi, validation và pattern matching.
        - Áp dụng clamp và làm tròn (ceil) cho các giá trị số.
        - Cấu trúc dự án với header files, source files, và test cases.
        - Sử dụng Makefile và scripts để build và test tự động.
- **Tình trạng**: Đã hoàn thành dự án KTLT1 với 4 tasks chính, bao gồm 45+ test cases.
