#include <iostream>
using namespace std;

// Ham loai bo cac phan tu trung nhau tu mang
void removeDuplicates(int arr[], int& size) {
    // Neu mang co 1 phan tu hoac khong co phan tu nao, khong can xu ly
    if (size <= 1)
        return;

    int j = 0;
    for (int i = 0; i < size - 1; ++i) {
        // Neu phan tu hien tai khac phan tu tiep theo
        if (arr[i] != arr[i + 1]) {
            // Luu phan tu duy nhat vao mang
            arr[j++] = arr[i];
        }
    }

    // Luu phan tu cuoi cung vao mang
    arr[j++] = arr[size - 1];

    // Cap nhat kich thuoc moi cua mang
    size = j;
}

int main() {
    int arr[100];
    int size;

    // Nhap so luong phan tu cua mang
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> size;

    // Nhap cac phan tu cua mang
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < size; ++i) {//su dung vong lap de nhap tung phan tu
        cout << "arr[" << i << "]: ";//cho nguoi dung biet duoc phan tu dang nhap la thu may
        cin >> arr[i];//nhap gia tri cho tung phan tu thu i cua mang
    }

    // Loai bo cac phan tu trung nhau
    removeDuplicates(arr, size);

    // In ra mang sau khi loai bo cac phan tu trung nhau
    cout << "Mang sau khi loai bo phan tu trung nhau:\n";
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }

    return 0;
}

