#include <iostream>
#include <cmath> // De su dung ham sqrt()
using namespace std;

// Ham kiem tra xem mot so co phai la so nguyen to hay khong
bool isPrime(int num) {
	
    if (num < 2) return false;//num khong phai la so nguyen to 
    for (int i = 2; i <= sqrt(num); ++i) {//chay tu 2 den can bac hai cua mun
        if (num % i == 0) {//neu num chia het cho 1 so trong khoang nay 
            return false;//khong phai so nguyen to
        }
    }
    return true;
}

int main() {
    int arr[100];
    int n;

    // Nhap so luong phan tu cua mang
    cout << "Nhap so luong phan tu cua mang (n <= 100): ";
    cin >> n;

    // Kiem tra gia tri hop le cua n
    //yeu cau n lon hon khong va nho hon 100
    if (n < 0 || n > 100) {
        cout << "So luong phan tu khong hop le." << endl;
        return 1;
    }

    // Nhap cac phan tu cua mang
    cout << "Nhap cac phan tu cua mang:" << endl;
    for (int i = 0; i < n; ++i) {//su dung vong lap de nhap tung phan tu
        cout << "arr[" << i << "]: ";//cho nguoi dung biet duoc phan tu dang nhap la thu may
        cin >> arr[i];//nhap gia tri cho tung phan tu thu i cua mang
    }

    // Hien thi cac so nguyen to trong mang
    cout << "Cac so nguyen to trong mang la:" << endl;
    for (int i = 0; i < n; ++i) {
        if (isPrime(arr[i])) {//gio ham isPrime kiem tra co phai la so nguyen to hay khong
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

