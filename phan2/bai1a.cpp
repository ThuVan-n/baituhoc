#include <iostream>
using namespace std;

// Ham kiem tra xem mang co chua toan so chan hay khong
bool kiemTraSoChan(int a[], int n) {
    for (int i = 0; i < n; ++i) {//su dung vong lap 
        if (a[i] % 2 != 0) {//kiem tra xem so la chan hay le
            cout << "Mang khong chua toan so chan." << endl;
            return false;
        }
    }
    cout << "Mang chua toan so chan." << endl;
    return true;
}

int main() {
    int iArray[100];//khai bao mang
    int n;

    // Nhap so phan tu cua mang
    cout << "Nhap so phan tu cua mang (n <= 100): ";
    cin >> n;

    // Kiem tra gia tri hop le cua n
    if (n < 0 || n > 100) {
        cout << "So phan tu khong hop le." << endl;
        return 1;
    }

    // Nhap cac phan tu cua mang 
    cout << "Nhap cac phan tu cua mang:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "array[" << i << "]: ";
        cin >> iArray[i];
    }

    // Goi ham kiem tra va hien thi ket qua
    kiemTraSoChan(iArray, n);

    return 0;
}
