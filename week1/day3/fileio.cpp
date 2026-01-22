#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
/*
Câu 20. Viết hàm void calSum(string fileName) để tính tổng của các số nguyên không âm được
đọc vào từ một file đuôi txt (các số nằm trên 1 hàng phân cách với nhau bằng một khoảng trắng).
•Đầu vào: Biến fileName là tên file dữ liệu chứa các số nguyên không âm (các số nằm trên 1
hàng phân cách với nhau bằng một khoảng trắng).
•Đầu ra: Một số nguyên là tổng của các số nguyên đầu vào
*/
void calSum(string fileName){
	ifstream val(fileName);
	int n;
	int sum = 0;
	// dùng trực tiếp vì nếu >> không hoạt động sẽ trả về 0
	while (val >> n) {
		sum += n;
	}
	cout << sum;
	val.close();
}	

/*
Câu 21. Viết hàm void uppercase(string output) để đọc vào chuỗi S từ bàn phím, sau đó chuyển
tất các ký tự trong chuỗi S thành ký tự viết hoa và xuất kết quả ra file output.
Chú ý: chỉ thay đổi các chữ cái in thường, các kí tự khác sẽ được giữ nguyên.
Đầu vào: Biến output chứa tên file dùng để xuất kết quả.
Đầu ra: Hàm đọc chuỗi S từ bàn phím và xử lý chuỗi như mô tả. Sau đó ghi chuỗi đã xử lý
vào file có tên được chứa trong biến output (hàm không trả về kết quả)
*/

void upper(string signal) {
    int i = 0;
    while (signal[i] != '\0') {
		if (signal[i] >= 'a' && signal[i] <= 'z') {
            signal[i] = signal[i] - 32;
        }
        i++;
    }
}

void uppercase(string outputfilename, string output){
	ofstream val(outputfilename);
	upper(output);
	val << output;
	val.close();
	cout << "Ghi thành công";
}
/*
Câu 22. Viết hàm void process(string fileName) đọc một file đuôi txt, dòng đầu gồm 2 số N
và M cách nhau bởi 1 khoảng trắng, N dòng theo sau, mỗi dòng gồm M số thực cách nhau bởi 1
khoảng trắng; trả về giá trị lớn nhất của mỗi dòng và giá trị lớn nhất trong tất cả các số.
•Đầu vào: Biến fileName là tên file chứa dữ liệu đầu vào.
•Đầu ra: Giá trị lớn nhất của mỗi dòng và giá trị lớn nhất của tất cả các số, cách nhau bởi ký
tự khoảng trắng
*/
void process(string fileName){
    ifstream val(fileName);
    int row;
    int numperrow;
    val >> row >> numperrow;
    float finalmax;
    for(int i=0;i<row;i++){
        float max;
        for(int j=0;j<numperrow;j++){
            float a;
            val >> a;
            if(max < a)max=a;
        }
        cout << max << " ";
        if(finalmax<max)finalmax=max;
    }
    cout << finalmax;

}
/*
Câu 23. Viết hàm void studendGrading(string fileName) đọc một file đuôi txt, dòng đầu gồm
1 số nguyên dương N, N dòng theo sau mỗi dòng chứa 4 số thực lần lượt là điểm số của các môn
NMĐT, KTLT, DSA và PPL của N học sinh.
Điểm trung bình (ĐTB) của sinh viên sẽ là trung bình cộng của 4 cột điểm trên. Sinh viên sẽ được
xếp loại dựa trên ĐTB như sau:
•Loại A nếu ĐTB ≥8 và không có môn nào dưới 5.
•Loại B nếu 8 > ĐTB ≥6.5 và không có môn nào dưới 5.
•Loại C nếu 6.5 > ĐTB ≥5 và không có môn nào dưới 5.
•Loại D cho các trường hợp còn lại.
Xác định số lượng sinh viên mỗi loại và xuất kết quả ra màn hình.
•Đầu vào: Biến fileName là tên file chứa chứa thông tin về điểm số của sinh viên.
•Đầu ra: Số lượng sinh viên mỗi loại được ghi ra màn hình.
*/
void studendGrading(string fileName) {
    int A =0;
    int B =0;
    int C =0;
    int D =0;
    ifstream val(fileName);
    int row;
    val >> row;
    for(int i=0;i<row;i++){
        float sum =0;
        bool less5 = false;
        for(int j=0;j<4;j++){
            float a;
            val >> a;
            sum += a;
            if(a<5)less5=true;
        }
        float ave = sum/4;
        if(less5 || ave < 5){
            D+=1;
        }else if(ave >= 5 && ave <6.5){
            C+=1;
        }else if(ave >= 6.5 && ave <8){
            B+=1;
        }else if(ave >= 8 && ave <10){
            A+=1;
        }
    }
    cout <<A<<B<<C<<D;

}
/*
âu 24. Viết hàm void calMoney(string price, string buy) đọc vào 2 file price.txt và buy.txt.
Trong đó:
•File price.txt chứa thông tin về các sản phẩm, gồm: Dòng đầu tiên chứa số nguyên dương N
(N ≤20) là số lượng sản phẩm hiện có trong cửa hàng. N dòng tiếp theo mỗi dòng chứa 2 số
nguyên dương là ID và giá của các sản phẩm tương ứng. Ví dụ:
3
1 10
2 15
3 12
Có nghĩa là: hiện tại có 3 sản phẩm được bán trong cửa hàng, sản phẩm 1 giá 10 sản phẩm 2
giá 15 và sản phẩm 3 có giá là 12.
•File buy.txt chứa thông tin về việc mua hàng hóa của khách hàng. Dòng đầu tiên chứa số
nguyên dương M là số lượng khách hàng mua hàng trong 1 ngày. M dòng tiếp theo mỗi dòng
chứa thông tin như sau: sẽ có nhiều giá trị nằm trên một hàng, cách nhau bởi một khoảng
trắng. Giá trị đầu tiên sẽ là tên khách hàng (dạng string), các giá trị còn lại sẽ đi theo cặp
với nhau, tương ứng là: <ID sản phẩm>_<số lượng tương ứng>. Ví dụ:
2
A 1 2 2 3
B 1 3 3 2
Có nghĩa là có 2 khách hàng A và B, A mua 2 sản phẩm loại 1 và 3 sản phẩm loại 2; B mua 3
sản phẩm loại 1 và 2 sản phẩm loại 3.
Lưu ý: ID của sản phẩm và tên khách hàng là duy nhất (không lặp lại).
Tính số tiền mỗi khách hàng cần trả, sau đó xuất kết quả ra màn hình.
•Đầu vào: 2 biến price (là tên của file chứa thông tin sản phẩm) và buy (là tên của file chứa
thông tin mua hàng).
•Đầu ra: Số tiền mỗi khách hàng cần trả.
*/
void calMoney(string price, string buy){
    ifstream fileprice(price);
    int productnum;
    fileprice >> productnum;
    int pricetable[1000];
    for (int i = 0; i < productnum; i++){
        int price,id;
        fileprice >> id >> price;
        pricetable[id] = price;
    }

    ifstream filebuy(buy);
    int numcustomer;
    filebuy >> numcustomer;
    string line;
    getline(filebuy, line);
    for(int i=0;i<numcustomer;i++){
        getline(filebuy, line);
        stringstream ss(line);
        string name;
        ss >> name;
        cout << name;
        int count,countid;
        int sum =0;
        while(ss >> countid>> count){
            sum+= count * pricetable[countid];
        }
        cout << " " << sum << "\n";

    }

}
/*
Câu 25. Viết hàm void manage(string library, string book, string author) đọc vào 3 file
library.txt, book.txt và author.txt. Trong đó:
•File library.txt chứa thông tin của các thư viện, gồm: dòng đầu tiên chứa số nguyên dương
N là số lượng thư viện được khảo sát. N dòng tiếp theo, mỗi dòng chứa 6 giá trị được phân
cách nhau bằng dấu khoảng trắng. Cho mỗi dòng, giá trị đầu tiên là tên của Thư viện (tên
Thư viện là duy nhất), 5 giá trị còn lại là 5 số nguyên dương, là ID của 5 quyển sách có trong
thư viện đó. Ví dụ:
5
A 1 2 3 4 5
LB 5 3 1 2 4
LC 4 1 5 2 3
•File book.txt chứa thông tin của các quyến sách, gồm: dòng đầu tiên chứa số nguyên dương
M là số lượng đầu sách có trong tất cả các thư viện. M dòng tiếp theo mỗi dòng chứa 3 giá
trị (phân cách nhau bởi một dấu khoảng trắng) có ý nghĩa như sau: giá trị đầu tiên là một số
nguyên dương đại diện cho Mã số sách (ID - ID là duy nhất), giá trị thứ 2 là năm sản xuất và
giá trị cuối cùng là thể loại. Ví dụ:
5
1 2000 A
2 2001 B
3 1993 D
4 1997 A
5 1995 C
•File author.txt chứa thông tin của các tác giả, gồm: dòng đầu tiên chứa số nguyên dương P
là số lượng tất cả các tác giả của các sách trong các thư viện (giả sử 1 quyển sách chỉ được
sáng tác bới 1 tác giả). P dòng tiếp theo mỗi dòng chứa các giá trị như sau (các giá trị được
phân cách với nhau bằng 1 dấu khoảng trắng): giá trị đầu tiên là Tên tác giả, các giá trị còn
lại là ID của các quyển sách mà người đó đã sáng tác. Ví dụ:
3
David 1 5
John 3
Henry 2 4
Xác định xem Thư viện L có chứa tác phẩm nào của Tác giả A hay không, nếu có xuất ra màn hình
giá trị True, ngược lại xuất ra False, với L và A được nhập vào từ bàn phím.
•Đầu vào: 3 biến library, book và author lần lượt chứa tên file library.txt, book.txt và
author.txt.
•Đầu ra: True hoặc False ứng với đầu vào
*/
void manage(string library, string book, string authorFile, string author, string lib){
    bool output = false;
    ifstream authorfile(authorFile);
    ifstream libfile(library);
    int numauthor;
    authorfile >> numauthor;
    
    int numlib;
    libfile >> numlib;
    string line;
    getline(libfile, line);
    
    int bookinlib[5];
    for(int i=0;i<numlib;i++){
        getline(libfile, line);
        stringstream ss(line);
        string libname;
        ss >> libname;
        
        if(libname==lib){
            for(int j=0;j<5;j++){
                ss >> bookinlib[j];
            }
        }
    }

    
    getline(authorfile, line);
    for(int i=0;i<numauthor;i++){
        getline(authorfile, line);
        stringstream ss(line);
        string authorname;
        ss >> authorname;
        if(authorname==author){
            cout << authorname<< '\n';
            int bookid;
            while(ss >> bookid){
                for(int j=0;j<5;j++){
                    cout << '\n' << "so sánh: bookid == bookinlib: " << bookid << "===" << bookinlib[j] << '\n';
                    if(bookid==bookinlib[j]){
                        output = true;
                        cout << "đã tìm thấy";
                    }
                }
            }
        }
    }
    if(!output)cout << "không tìm thấy";
}

void run_tests() {
    cout << "--- Cau 20: calSum ---" << endl;
    cout << "Expected: 155, Result: ";
    calSum("week1/day3/data/sum.txt");
    cout << endl;

    cout << "\n--- Cau 21: uppercase ---" << endl;
    cout << "Please type 'hello world' and press Enter: ";
    //uppercase("week1/day3/data/output.txt");
    cout << "Result written to week1/day3/data/output.txt. Please check it." << endl;

    cout << "\n--- Cau 22: process ---" << endl;
    cout << "Expected: 3.5 4 4, Result: ";
    //process("week1/day3/data/process.txt");
    cout << endl;

    cout << "\n--- Cau 23: studendGrading ---" << endl;
    cout << "Expected: A: 1, B: 1, C: 0, D: 2, Result: ";
    //studendGrading("week1/day3/data/grades.txt");
    cout << endl;

    cout << "\n--- Cau 24: calMoney ---" << endl;
    cout << "Expected: 65 54, Result: ";
    //calMoney("week1/day3/data/prices.txt", "week1/day3/data/buys.txt");
    cout << endl;

    cout << "\n--- Cau 25: manage ---" << endl;
    cout << "Type 'L1 David' (Library L1, Author David): " << endl;
    cout << "Expected: True, Result: ";
    //manage("week1/day3/data/libraries.txt", "week1/day3/data/books.txt", "week1/day3/data/authors.txt");
    cout << endl;
}

int main(){
    //run_tests();
	//calSum("data.txt");
	//uppercase("data.txt", "Hello111");
    //process("data.txt");
    //studendGrading("data.txt");
    //calMoney("price.txt", "buy.txt");
    string author = "David";
    string lib = "L1";
    manage("libraries.txt","books.txt","authors.txt",author, lib);
}