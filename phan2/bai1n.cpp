#include <iostream>

// Ham kiem tra mang co doi xung hay khong
bool isSymmetricArray(int arr[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        if (arr[i] != arr[n - i - 1]) {
            return false; // Khong doi xung neu co it nhat mot cap phan tu khong giong nhau
        }
    }
    return true; // Doi xung neu tat ca cac cap phan tu deu giong nhau
}

int main() {
    int arr[100]; // Mang so nguyen
    int n; // So luong phan tu trong mang

    // Nhap so luong phan tu cua mang va cac phan tu cua mang
    std::cout << "Nhap so luong phan tu cua mang (toi da 100): ";
    std::cin >> n;
    std::cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Phan tu thu " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    // Kiem tra mang co doi xung hay khong
    if (isSymmetricArray(arr, n)) {
        std::cout << "Mang la mang doi xung.\n";
    } else {
        std::cout << "Mang khong la mang doi xung.\n";
    }

    return 0;
}

