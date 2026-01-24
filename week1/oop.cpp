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
		Integer(int n){
			val = n;
		}

		void setValue(int a){
			this->val = a;
		} 

		int getValue(){
			return this->val;
		}
};


void test_class_Interger(){
	Integer myint(6);
	cout << myint.getValue() << '\n';
	myint.setValue(8);
	cout << myint.getValue() << '\n';
}

class Course 
{
	private:
		int ID;
		int numOfStudent;
		int numOfTeacher;
		int numOfTA;
	public:
		Course(int a){
			ID=a;
			numOfStudent=a;
			numOfTeacher=a;
			numOfTA=a;
		}
		void getinfo();
		void setinfo(int a, int b, int c, int d);
};

void Course::getinfo(){
	cout<< "CourseID = "<< ID << endl;
	cout<< "Number of student = " << numOfStudent << endl;
	cout<< "Number of teacher = " << numOfTeacher << endl;
	cout<< "Number of TA = " << numOfTA<< endl;
}

void Course::setinfo(int a, int b, int c, int d){
	ID =a;
	numOfStudent =b;
	numOfTeacher =c;
	numOfTA =d;
}
// Tạo một list đối tượng
Course** Coursemake(int n) {
    // 1. Tạo mảng chứa n con trỏ tới Course
    Course** myCourse = new Course*[n]; 

    for (int i = 0; i < n; i++) {
        // 2. Cấp phát động cho từng phần tử với giá trị i
        myCourse[i] = new Course(i); 
    }

	return myCourse;
}

void test_Coursemaker(){
	//Tương tác với list một đối tượng
	Course** arr_Course = Coursemake(3);
	arr_Course[2]->getinfo();
	arr_Course[2]->setinfo(100,200,300,400);
	arr_Course[2]->getinfo();
}

//template cơ bản để so sánh nhiều kiểu dữ liệu khác nhau
template <typename T> 
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T> 
class Array 
{
    private:
        int size;
        T *p; // Con trỏ quản lý mảng động

    public:
        // Constructor
        Array(int size, T initValue) {
            this->size = size;
            this->p = new T[size]; // Cấp phát n ô nhớ kiểu T
            for (int i = 0; i < size; i++) {
                p[i] = initValue; // Gán giá trị ban đầu
            }
        }

        // Destructor: Giải phóng bộ nhớ khi đối tượng bị hủy
        ~Array() {
            delete[] p;
        }

        // In toàn bộ mảng
        void print() {
            for (int i = 0; i < size; i++) {
                cout << p[i] << " ";
            }
            cout << endl;
        }

        // Gán giá trị tại vị trí idx
        void setAt(int idx, const T& value) {
            if (idx >= 0 && idx < size) {
                p[idx] = value;
            }
        }

        // Lấy giá trị tại vị trí idx
        T getAt(int idx) {
            return p[idx]; 
        }

        // Overload toán tử [] để dùng như mảng thường: myarr[i]
        T& operator[](int idx) {
            return p[idx];
        }
};

//Nạp chồng toán tử Operator
class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Định nghĩa toán tử cộng (+)
    // Nó nhận vào một đối tượng Point khác (vế bên phải dấu cộng)
    Point operator+(const Point& other) {
        Point result;
        result.x = this->x + other.x; // Cộng x với x
        result.y = this->y + other.y; // Cộng y với y
        return result;
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

//Kế thừa
class Shape {
protected: // protected cho phép class con truy cập, nhưng bên ngoài thì không
    int width;
    int height;

public:
    void setValues(int w, int h) {
        width = w;
        height = h;
    }
};

// --- Class Con (Derived Class) ---
// Cú pháp: class TenCon : public TenCha
class Rectangle : public Shape {
public:
    int getArea() {
        return width * height; // Dùng được width, height từ cha
    }
};

class Triangle : public Shape {
public:
    int getArea() {
        return (width * height) / 2;
    }
};

void test_Point(){
	Point p1(10, 5);
	Point p2(3, 8);
	Point p3 = p1 + p2;

	p3.display();
}

void test_Inhe(){
	Rectangle rect;
    Triangle tri;

    // Dùng phương thức kế thừa từ cha
    rect.setValues(5, 4);
    tri.setValues(5, 4);

	cout << "Dien tich hinh chu nhat: " << rect.getArea() << endl;
	cout << "Dien tich hinh tam giac: " << tri.getArea() << endl;
}

int main(){
	test_Inhe();



	return 0;
}