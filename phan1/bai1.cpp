#include <iostream> 
using namespace std;

//khai bao  Ham de tim so dao nguoc cua mot so nguyen
int reverseNumber(int n) {
    int reversedNumber = 0; // Khoi tao bien luu tru so dao nguoc
    while (n > 0) {
        reversedNumber = reversedNumber * 10 + n % 10; // Tinh toan so dao nguoc
        //n%10 de lay chu so cuoi cung reversedNumber * 10 + n de them chu so vao dang sau chu so dao nguoc
        n /= 10; // Loai bo chu so cuoi cung cua n
    }
    return reversedNumber; // Tra ve so dao nguoc cua so nguyen
}

int main() {
    int number; 
    cout << "Nhap so nguyen: "; 
    cin >> number;
    
    // Goi ham reverseNumber de tim so dao nguoc cua so nguyen va luu vao bien reversed
    int reversed = reverseNumber(number);
    
    // In ra man hinh so dao nguoc cua so nguyen da nhap
    cout << "So dao nguoc cua so nguyen " << number << " la: " << reversed << endl;
    
    return 0; 
}

