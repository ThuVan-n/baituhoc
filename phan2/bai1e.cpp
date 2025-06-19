#include <iostream>
using namespace std;

int main() {
    int arr[100];
    int size;
    int countEven = 0; // Bien dem so luong so chan
    int countOdd = 0;  // Bien dem so luong so le

    // Nhap so luong phan tu cua mang (toi da 100 phan tu)
    cout << "Nhap so luong phan tu cua mang (toi da 100 phan tu): ";
    cin >> size;

    // Nhap cac phan tu cua mang
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];

        // Kiem tra xem phan tu hien tai la so chan hay so le va cap nhat bien dem tuong ung
        if (arr[i] % 2 == 0) {
            countEven++;
        } else {
            countOdd++;
        }
    }

    

    // Xuat so luong so chan va so luong so le trong mang
    cout << "So luong so chan trong mang: " << countEven << endl;
    cout << "So luong so le trong mang: " << countOdd << endl;

    return 0;
}

