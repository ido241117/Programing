#include <iostream>
#include "class.cpp"
using namespace std;

template <typename T>
class Array {
	public:
		Array(int size, T initValue);
		~Array();
		
		//Copy contructor
		Array(Array<T> & other);
		
		// Pointer contructor
		Array(Array* other);
		void print();

		void setAt(int idx, T value);
		T getAt(int idx);

		// Nên làm khi một class là một vật chứa để truy cập dễ dàng hơn
		T& operator[](int idx);


		Array<T> & operator=(Array<T> & other);
	private:
		int size;
		T * p;
};

template <typename T>
Array<T> & Array<T>::operator=(Array<T> & other){
    if (this == &other) {return *this;}

	if (this->p != nullptr) {
        delete[] this->p; // Giải phóng mảng động
    }
	
	this->size = other.size;
	
	this -> p = new T[this -> size];
	
	for(int i=0;i<this->size;i++){
		this -> p[i] = other.p[i];
	}
	
	return *this;
}

template <typename T>
Array<T>::Array(int size, T initValue) {
	this -> size = size;
	
	// Cấp phát một mảng T với chiều dài size từ vị trí p
	this -> p = new T[size];
	
	for(int i=0;i<this->size;i++){
		p[i] = initValue;
	}

}

template <typename T>
Array<T>::Array(Array<T> &other) {
	this->size = other.size;
	this->p = new T[this->size];
	for (int i = 0; i < this->size; i++) {
		this->p[i] = other.p[i];
	}
}

template <typename T>
Array<T>::Array(Array* other) {
	if (other != nullptr) {
		this->size = other->size;
		this->p = other->p; // Cùng trỏ vào vùng nhớ cũ (Shallow Copy)
	} else {
		this->size = 0;
		this->p = nullptr;
	}
}

template <typename T>
Array<T>::~Array() {
	if (this->p != nullptr) {
        delete[] this->p; // Giải phóng mảng động
        this->p = nullptr; // Xóa dấu vết để tránh lỗi dangling pointer
    }

}

template <typename T>
void Array<T>::print(){
	for(int i=0;i<this->size;i++){
		cout << p[i] << " ";
	}
	cout << '\n';

}

template <typename T>
void Array<T>::setAt(int idx, T value){
	if (idx >= 0 && idx < size) {
		p[idx] = value;
	}
}

template <typename T>
T Array<T>::getAt(int idx){
	return p[idx];
}

// Là hàm thương tự như getAt, nhưng dùng được theo nhiều kiểu
template <typename T>
T& Array<T>::operator[](int idx){
	return p[idx];
}

void test_arr_int(){
	Array<int> arr(5, 0);
	arr.print();
	arr.setAt(2, 20);
	arr.print();
	cout << arr.getAt(2) << '\n';
	// nếu không có operator[] thì arr[2] sẽ gây lỗi
	cout << arr[2] << '\n';
}

void test_arr_char(){
	Array<char> arr(5, 'a');
	arr.print();
	arr.setAt(2, '@');
	arr.print();
	cout << arr[2] << '\n';
}

void test_arr_INTERGER(){
	Integer a(10);
	Integer b(20);
	Integer c = a + b;

	Array<Integer> arr(3, a);
	arr.print();
	arr.setAt(1, b);
	arr.setAt(2, c);
	arr.print();
}

void test_copy_constructor() {
    cout << "--- Test Copy Constructor ---\n";
    Array<int> arr1(3, 10);
    arr1.setAt(1, 20);
    cout << "arr1: "; arr1.print();

    Array<int> arr2(arr1); // Copy Constructor
    cout << "arr2 (copy of arr1): "; arr2.print();
    
    arr1.setAt(0, 99);
    cout << "After modifying arr1[0] = 99:\n";
    cout << "arr1 (modified): "; arr1.print();
    cout << "arr2 (should stay same): "; arr2.print(); 
}

void test_pointer_constructor() {
    cout << "--- Test Pointer Constructor (Shallow Copy) ---\n";
    Array<int>* arr1 = new Array<int>(3, 5);
    cout << "arr1: "; arr1->print();

    Array<int> arr3(arr1); // Pointer Constructor (Shallow Copy)
    cout << "arr3 (pointing to same memory as arr1): "; arr3.print();

    // Thay đổi arr1 để xem arr3 có đổi theo không
    arr1->setAt(0, 100);
    cout << "\nAfter modifying arr1[0] = 100:\n";
    cout << "arr1: "; arr1->print();
    cout << "arr3 (WILL change because of sharing memory): "; arr3.print(); 

    // CẢNH BÁO: Vì dùng chung vùng nhớ, không nên delete cả hai hoặc delete một cái rồi dùng cái kia.
    // Để tránh crash khi chạy test này, tôi sẽ không delete arr1 ở đây 
    // vì arr3 sẽ tự delete vùng nhớ này khi hàm kết thúc.
}

int main(){
	test_copy_constructor();
	cout << '\n';
	test_pointer_constructor();
	return 0;
}