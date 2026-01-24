#include <iostream>
using namespace std;

/*
Câu 74. Hãy thiết kế một class Integer với một biến private val dạng int. Class gồm các phương
thức sau:
•constructor nhận biến val ban đầu.
•setValue() để thay đổi giá trị biến val.
•getValue() để lấy giá trị biến val.
*/
class Integer
{
	private:
		int val;
	public:
		Integer();
		Integer(int n);
		
		// Để thực hiện Integer a(5); Integer b(a)
		Integer(Integer* other);
		
		void setValue(int a);
		int getValue();
		void print(){cout << this->val << " ";}

		// Nạp chồng toán tử + =
		Integer operator+(const Integer& other);
		Integer& operator=(const Integer& other);


		// Hàm để dùng toán tử << và cout trực tiếp. ví dụ cout << Interger a(10);
		friend ostream& operator<<(ostream& os, const Integer& obj) {
            os << obj.val;
            return os;
        }

};

Integer::Integer(){
	this ->val = 0;
}

Integer::Integer(Integer* other) {
    if (other != nullptr) {
        this->val = other->val;
    } else {
        this->val = 0; // Giá trị mặc định nếu con trỏ rỗng
    }
}

Integer::Integer(int n){
	this ->val = n;
}

void Integer::setValue(int a){
	this->val=a;
}

int Integer::getValue(){
	return this->val;
}

Integer Integer::operator+(const Integer& other){
	return Integer(this->val + other.val);
}

Integer& Integer::operator=(const Integer& other){
	this->val = other.val;
	return *this;
}

void test_class_1(){
	//Tạo num mặc định
	Integer num;
	cout << num.getValue() << '\n';

	//Tạo num với tham số
	Integer num1(30);
	cout << num1.getValue() << '\n';

	//Tạo một con trỏ tới num
	Integer* numptr = &num1;
	cout << numptr->getValue() << '\n';

	//Thay đổi giá trị trực tiếp
	num.setValue(5);
	cout << num.getValue() << '\n';

	//Thay đổi giá trị rồi gọi con trỏ
	num1.setValue(40);
	cout << numptr->getValue() << '\n';

	//Thay đổi giá trị bằng con trỏ
	numptr->setValue(50);
	cout << num1.getValue() << '\n';
}

void test_Interger_array(){
	//cấp phát động một đối tượng
	//num chỉ lưu con trỏ thôi
	Integer* num = new Integer(5);
	cout << num -> getValue() << '\n';

	//cấp phát động một list 5 đối tượng
	//list vẫn chỉ lưu con trỏ thôi
	//dùng thêm một vòng for duyệt qua list[i] nữa để set giá trị
	Integer* list = new Integer[5];
	cout << list -> getValue() << '\n';
	cout << list[1].getValue()<< '\n';

	//cấp phát động một list 5 con trỏ
	//lưu ý vì chỉ mới là con trỏ nên chưa thể get được
	Integer** arr = new Integer*[5];
	arr[2] = new Integer(2);
	cout << arr[2] -> getValue() << '\n';
	// Vì 0 chưa khởi tạo nhưng đã được cấp phát nên in ra giá trị bất kì
	cout << arr[0] -> getValue() << '\n';

}



void test_Operator(){
	Integer a(10);
	Integer b(20);
	Integer c = a + b;

	cout << c.getValue() << '\n';

	cout << a.getValue() << '\n';
	a = b;
	cout << a.getValue() << '\n';
}

void test_pointer_contructor(){
	Integer a(10);
	Integer b(a);

	cout << b.getValue() << '\n';
	a.setValue(5);
	cout << a.getValue() << '\n';
	cout << b.getValue() << '\n';
}

void test_Operator2(){
	Integer a(10);
	
	Integer c(a + 5);
	cout << c.getValue() << '\n';

	cout << Integer(6) + 2  << '\n';
	
}

void test_lab(){
	int x =5;
	int y =6;
	int z =7;

	Integer a(x);
	Integer b(y);
	Integer* t = new Integer(z);
	Integer c(t);

	a.print(); b.print();
	(a + b + c + 4).print();
}
