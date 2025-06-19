#include<iostream>
using namespace std;
// Ham tinh uoc so chung lon nhat cua hai so nguyen x va y
int USCLN(int x, int y) 
{
    // Dung thuat toan Euclid de tinh uoc so chung lon nhat
    // Neu y khac 0 (tuc la y la uoc so), tiep tuc vong lap
    while (y != 0) 
    {
        int temp = y;   // Luu giu gia tri cua y vao bien tam thoi
        y = x % y;      // Cap nhat y thanh phan du khi chia x cho y
        x = temp;       // Cap nhat x thanh gia tri ban dau cua y
    }
    // Khi y = 0, x chinh la uoc so chung lon nhat
    return x;           // Tra ve gia tri cua uoc so chung lon nhat
}

int main() 
{
    // Khai bao bien
    int a, b, c;

    // Nhap ba so nguyen tu nguoi dung
    cout << "Nhap vao 3 so nguyen a, b, c: ";
    cin >> a >> b >> c;

    // Tinh tong cua 3 uoc so chung lon nhat
    int sum = USCLN(a, b) + USCLN(b, c) + USCLN(a, c);

    // In ket qua ra man hinh
    cout << "Tong cua 3 uoc so chung lon nhat la: " << sum << endl;

    return 0;
}

