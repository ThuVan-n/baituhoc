#include <iostream>
using namespace std;

// Ham tinh gia tri cua da thuc F(x)
double calculatePolynomial(double coeffi[], int n, double x) {
    double result = 0.0; // Khoi tao ket qua ban dau la 0
    double xPower = 1.0; // Khoi tao luy thua cua x la 1

    // Duyet qua tung he so cua da thuc
    for (int i = 0; i <= n; ++i) {
        result += coeffi[i] * xPower; // Tinh tich cua he so va luy thua cua x, sau do cong vao ket qua
        xPower *= x; // Tinh luy thua tiep theo cua x
    }

    return result; // Tra ve ket qua cuoi cung cua da thuc
}

int main() {
    int n;
    cout << "Nhap bac cua da thuc: ";
    cin >> n;

    double coeffi[n+1]; // Khai bao mang chua cac he so cua da thuc

    // Nhap cac he so cua da thuc tu nguoi dung
    cout << "Nhap cac he so cua da thuc: ";
    for (int i = 0; i <= n; ++i) {
        cin >> coeffi[i];
    }

    double x;
    cout << "Nhap gia tri x: ";
    cin >> x; // Nhap gia tri x tu nguoi dung

    // Tinh gia tri cua da thuc tai gia tri x da nhap
    double result = calculatePolynomial(coeffi, n, x);
    cout << "Gia tri cua da thuc tai x = " << x << " la: " << result << endl;

    return 0;
}

