#include <iostream>

// Ham tinh uoc so chung lon nhat cua hai so nguyen x va y
int USCLN(int x, int y) 
{
    // Su dung thuat toan Euclid de tinh uoc so chung lon nhat
    // Neu y khac 0 (tuc la y la uoc so), tiep tuc vong lap
    while (y != 0) 
    {
        int temp = y;  
        y = x % y;      // Cap nhat y thanh phan du khi chia x cho y
        x = temp;     
    }
    // Khi y = 0, x chinh la uoc so chung lon nhat
    return x;           // Tra ve gia tri cua uoc so chung lon nhat
}

// Ham tinh boi so chung nho nhat cua hai so nguyen x va y
int BSCNN(int x, int y) 
{
    return (x * y) / USCLN(x, y); // BSCNN = (a * b) / USCLN(a, b)
}

int main() 
{
    // Khai bao bien
    int a, b, c;

    // Nhap ba so nguyen tu nguoi dung
    std::cout << "Nhap vao 3 so nguyen a, b, c: ";
    std::cin >> a >> b >> c;

    // Tinh tong cua USCLN(a, b) va BSCNN(a, c)
    int sum = USCLN(a, b) + BSCNN(a, c);

    // In ket qua ra man hinh
    std::cout << "Tong cua USCLN(a, b) va BSCNN(a, c) la: " << sum << std::endl;

    return 0;
}

