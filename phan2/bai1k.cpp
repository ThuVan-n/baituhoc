#include <iostream>

// Ham hoan doi gia tri cua hai phan tu
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Ham sap xep mang giam dan
void sortDescending(int arr[], int n) {
    // Su dung thuat toan doi cho (bubble sort)
    // Lap qua tung phan tu trong mang (tru phan tu cuoi cung)
    for (int i = 0; i < n - 1; ++i) {
        // Duyet qua cac phan tu con lai trong mang
        for (int j = i + 1; j < n; ++j) {
            // Neu phan tu hien tai lon hon phan tu sau do
            if (arr[i] < arr[j]) {
                // Hoan doi gia tri cua hai phan tu de dam bao sap xep giam dan
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

    // Goi ham sap xep mang giam dan
    sortDescending(arr, n);

    // In ra mang da duoc sap xep giam dan
    std::cout << "Mang sau khi sap xep giam dan:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

