#include <iostream>
using namespace std;

// Ham kiem tra xem mot mang co dang duoc sap xep hay khong
// Tra ve 1 neu mang da duoc sap xep tang dan
// Tra ve -1 neu mang da duoc sap xep giam dan
// Tra ve 0 neu mang chua duoc sap xep
int isSorted(int arr[], int size)
{
    // Bien de kiem tra mang co duoc sap xep tang dan hay khong
    bool bAscending = true;
    // Bien de kiem tra mang co duoc sap xep giam dan hay khong
    bool bDescending = true;

    // Duyet qua cac phan tu cua mang
    for (int i = 0; i < size - 1; ++i)
    {
        // Neu phan tu hien tai lon hon phan tu ke tiep, mang khong duoc sap xep tang dan
        if (arr[i] > arr[i + 1])
        {
            bAscending = false;
        }
        // Neu phan tu hien tai nho hon phan tu ke tiep, mang khong duoc sap xep giam dan
        if (arr[i] < arr[i + 1])
        {
            bDescending = false;
        }
    }

    // Neu mang duoc sap xep tang dan
    if (bAscending)
    {
        cout << "Mang tang dan" << endl;
        return 1;
    }
    // Neu mang duoc sap xep giam dan
    else if (bDescending)
    {
        cout << "Mang giam dan" << endl;
        return -1;
    }
    // Neu mang chua duoc sap xep
    else
    {
        cout << "Mang chua duoc sap xep" << endl;
        return 0;
    }
}

int main() {
    // Khai bao mang va so luong phan tu
    int arr[100];
    int n;

    // Nhap so luong phan tu cua mang
    cout << "Nhap so luong phan tu cua mang (n <= 100): ";
    cin >> n;

    // Kiem tra gia tri hop le cua n
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

    // Goi ham kiem tra va hien thi ket qua
    int result = isSorted(arr, n);

    return 0;
}

