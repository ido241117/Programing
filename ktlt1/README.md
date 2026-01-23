# Study in Pink - KTLT Project

## Cấu trúc dự án

```
ktlt1/
├── include/          # Header files (.h)
│   ├── common.h      # Constants và utility functions
│   ├── task1.h       # Task 1: First Meet
│   ├── task2.h       # Task 2: Trace Luggage
│   └── task3.h       # Task 3: Chase Taxi
│
├── src/              # Source files (.cpp)
│   ├── main.cpp      # Main program
│   ├── utils.cpp     # Utility implementations
│   ├── task1.cpp     # Task 1 implementation
│   ├── task2.cpp     # Task 2 implementation
│   └── task3.cpp     # Task 3 implementation
│
├── tests/            # Test cases
│   ├── input/        # Input files (.txt)
│   │   ├── tc_01.txt
│   │   └── tc_02.txt
│   ├── expected/     # Expected outputs & ghi chú của bạn
│   │   ├── tc_01.txt (ghi chú về test case 01)
│   │   └── tc_02.txt (ghi chú về test case 02)
│   └── output/       # Actual outputs (tự động tạo khi chạy test)
│       ├── tc_01_output.txt
│       └── tc_02_output.txt
│
├── build/            # Compiled files (exe, obj)
│
├── scripts/          # Build & run scripts
│   ├── build.bat
│   └── run_test.bat
│
├── docs/             # Documentation
│
├── Makefile          # Build configuration
└── README.md         # This file
```

## Cách sử dụng

### 1. Sau khi sửa code → Build lại

**Mỗi khi sửa code trong `src/*.cpp` hoặc `include/*.h`, phải build lại:**

```bash
# Cách 1: Dùng Makefile
make

# Cách 2: Dùng script Windows
scripts\build.bat

# Cách 3: Build lại từ đầu (clean + build)
make clean
make
```

### 2. Chạy test case

**Chạy một test case cụ thể:**
```bash
# Format: build\main.exe <đường_dẫn_input> [tên_test]
build\main.exe tests\input\tc_01.txt
build\main.exe tests\input\tc_02.txt "Test 02"
build\main.exe tests\input\input2.txt "My Custom Test"

# Output tự động lưu vào: tests\output\<tên_file>_output.txt
# Ví dụ: tc_01.txt -> tests\output\tc_01_output.txt
```

**Xem kết quả:**
```bash
# Mở file output để xem kết quả chi tiết
notepad tests\output\tc_01_output.txt

# So sánh với expected (ghi chú của bạn)
notepad tests\expected\tc_01.txt
```

**Chạy nhiều test cases:**
```bash
# Sử dụng script (đã config sẵn)
scripts\run_test.bat

# Hoặc chạy từng cái
build\main.exe tests\input\tc_01.txt
build\main.exe tests\input\tc_02.txt
build\main.exe tests\input\input2.txt
```

### 3. Workflow: Sửa code → Test

**Ví dụ: Vừa sửa hàm `firstMeet()` trong task1.cpp**

```bash

# Bước 3: Xem kết quả trong tests\output\
notepad tests\output\tc_01_output.txt
notepad tests\output\tc_02_output.txt

# Hoặc chạy hết một lúc:
scripts\run_test.bat
```

### 4. Quản lý ghi chú test case

**File trong `tests/expected/` là ghi chú của bạn:**
- Tạo file `tests/expected/tc_01.txt` để ghi chú về test case 01
- Ví dụ nội dung:
  ```
  Case 1:
  E1 = 0
  EXP2 = 0
  -> EXP2 += 29
  Expected result: 29
  ```

**File trong `tests/output/` là kết quả chạy thực tế:**
- Tự động tạo khi chạy test
- Chứa input values, kết quả từng task
- S(Optional) Tạo file ghi chú `tests/expected/input2.txt`:
   ```
   Test input2:
   - Test case đặc biệt với E1 = 3
   - Expect EXP2 += (29+45+75)
   ```

3. Build và chạy:
   ```bash
   make
   build\main.exe tests\input\input2.txt
   ```

4. Xem kết quả:
   ```bash
   notepad tests\output\input2_output.txt
   ```

5*Ví dụ: Tạo file `input2.txt`**

1. Tạo file `tests/input/input2.txt` với format:
   ```
   172 172
   400 300
   450 450
   3 1 0
   ```
   (Mỗi dòng 3 số: HP, EXP, M, E)

2. Build project:
   ```bash
   make
   ```

3. Chạy test mới:
   ```bash
   build\main.exe tests\input\input2.txt "Input2"
   ```

4. (Optional) Thêm                      # Build project
make clean                              # Xóa build files
build\main.exe tests\input\tc_01.txt   # Chạy test, lưu vào tests\output\
notepad tests\output\tc_01_output.txt  # Xem kết quả
scripts\run_test.bat
### 5. Commands nhanh

```bash
make               # Build project
make clean         # Xóa build files
make test          # Chạy test mặc định
build\main.exe tests\input\tc_01.txt    # Chạy test cụ thể
scripts\run_test.bat                    # Chạy tất cả tests
```

## TODO

- [ ] Implement Task 1: firstMeet
- [ ] Implement Task 2: traceLuggage
- [ ] Implement Task 3: chaseTaxi
- [ ] Implement utility functions
- [ ] Add more test cases
- [ ] Verify với expected outputs

## Troubleshooting

**Lỗi: "make: command not found"**
→ Dùng `scripts\build.bat` thay vì `make`

**Sau khi sửa code mà kết quả không đổi?**
→ Phải `make` lại để build code mới

**Muốn test nhiều input nhanh?**
→ Thêm tất cả vào `scripts\run_test.bat` rồi chạy một lần

## Notes

- **QUAN TRỌNG:** Mỗi khi sửa code phải `make` lại!
- Implementations trong `src/*.cpp`, declarations trong `include/*.h`
- Build files tự động tạo trong `build/`
- Thêm test cases trong `tests/input/`
- Format input: 3 dòng, mỗi dòng 3 số (HP, EXP, M, E)
