#include <iostream>
#include <cmath> // Thu vien cho ham sqrt
using namespace std;

// Ham kiem tra xem mot so co phai la so chinh phuong hay khong
bool isPerfectSquare(int num) {
    int squareRoot = static_cast<int>(sqrt(num));
    return squareRoot * squareRoot == num;
}

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

// Ham tim so nguyen to dau tien xuat hien trong mang ma phan tu dung truoc cua no la so chinh phuong
int findFirstPrimeAfterPerfectSquare(int arr[], int size) {
    for (int i = 1; i < size; ++i) { // Bat dau tu phan tu thu hai vi phan tu dau tien khong co phan tu dung truoc
        if (isPerfectSquare(arr[i - 1]) && isPrime(arr[i])) {
            return arr[i];
        }
    }
    return -1; // Tra ve -1 neu khong tim thay so thoa dieu kien
}

int main() {
    int arr[100];
    int size;

    // Nhap so luong phan tu cua mang
    cout << "Nhap so luong phan tu cua mang (toi da 100 phan tu): ";
    cin >> size;

    // Nhap cac phan tu cua mang
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    // Tim so nguyen to dau tien xuat hien sau so chinh phuong trong mang
    int firstPrimeAfterPerfectSquare = findFirstPrimeAfterPerfectSquare(arr, size);
    if (firstPrimeAfterPerfectSquare != -1) {
        cout << "So nguyen to dau tien xuat hien sau so chinh phuong trong mang la: " << firstPrimeAfterPerfectSquare << endl;
    } else {
        cout << "Khong tim thay so nguyen to nao thoa dieu kien trong mang." << endl;
    }

    return 0;
}

