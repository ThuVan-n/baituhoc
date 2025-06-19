#include <iostream>

// Ham hoan doi gia tri cua hai phan tu
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Ham sap xep nua dau cua mang tang dan, nua sau cua mang giam dan
void sortHalfArray(int arr[], int n) {
    if (n <= 1)
        return;

    // Sap xep nua dau cua mang tang dan
    for (int i = 0; i < n/2 - 1; ++i) {
        for (int j = i + 1; j < n/2; ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    // Sap xep nua sau cua mang giam dan
    for (int i = n/2; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
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

    // Goi ham sap xep nua dau cua mang tang dan, nua sau cua mang giam dan
    sortHalfArray(arr, n);

    // In ra mang da duoc sap xep
    std::cout << "Mang sau khi sap xep nua dau tang dan, nua sau giam dan:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

