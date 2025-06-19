#include <iostream>
#include <cmath>

// Ham kiem tra xem mot so co phai la so nguyen to hay khong
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[100]; // Mang so nguyen
    int result[100]; // Mang chua cac so khong phai la so nguyen to
    int n; // So luong phan tu trong mang

    // Nhap so luong phan tu cua mang va cac phan tu cua mang
    std::cout << "Nhap so luong phan tu cua mang: ";
    std::cin >> n;
    std::cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Phan tu thu " << i + 1 << ": ";
        std::cin >> a[i];
    }

    int j = 0; // chi so cho mang ket qua
    for (int i = 0; i < n; ++i) {
        if (!isPrime(a[i])) { // Neu a[i] khong phai la so nguyen to
            result[j] = a[i]; // Dua a[i] vao mang ket qua
            ++j;
        }
    }

    // In ra mang ket qua
    std::cout << "Cac so khong phai la so nguyen to trong mang:\n";
    for (int i = 0; i < j; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

