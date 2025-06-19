#include <iostream>

// Ham tinh giai thua khong su dung de quy
unsigned long long factorialNoDeQuy(int num) {
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i) {
        result *= i; // Tich cac so tu 1 den num
    }
    return result; // Tra ve ket qua giai thua
}

// Ham tinh to hop chap k cua n
unsigned long long combination(int n, int k) {
    if (k < 0 || k > n) {
        return 0; // Neu k khong hop le, tra ve 0
    }

    // Su dung cong thuc toan hoc de tinh to hop chap k cua n
    return factorialNoDeQuy(n) / (factorialNoDeQuy(k) * factorialNoDeQuy(n - k));
}

int main() {
    int n, k;
    std::cout << "Nhap n va k: ";
    std::cin >> n >> k; // Nhap gia tri cua n va k tu nguoi dung

    // Goi ham combination de tinh to hop chap k cua n
    unsigned long long result = combination(n, k);
    
    // In ket qua ra man hinh
    std::cout << "To hop chap " << k << " cua " << n << " la: " << result << std::endl;

    return 0;
}

