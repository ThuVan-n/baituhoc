#include <iostream>

const int MAX_SIZE = 10;

// Ham nhap ma tran A tu ban phim
void nhapMaTran(int A[][MAX_SIZE], int n) {
    std::cout << "Nhap cac phan tu cua ma tran A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> A[i][j];
        }
    }
}

// Ham xuat ma tran A ra man hinh
void xuatMaTran(int A[][MAX_SIZE], int n) {
    std::cout << "Ma tran A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Ham kiem tra mot so co phai la so nguyen to khong
bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Ham dem so luong so nguyen to trong mot dong cua ma tran
int demSoNguyenTo(int A[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (laSoNguyenTo(A[i])) {
            count++;
        }
    }
    return count;
}

// Ham liet ke cac dong co nhieu so nguyen to nhat trong ma tran
void lietKeDongNhieuSoNguyenToNhat(int A[][MAX_SIZE], int n) {
    int maxPrimeCount = 0; // Bien luu tru so luong so nguyen to nhieu nhat
    for (int i = 0; i < n; ++i) {
        maxPrimeCount = std::max(maxPrimeCount, demSoNguyenTo(A[i], n));
    }

    // Xuat cac dong co so luong so nguyen to bang maxPrimeCount
    std::cout << "Cac dong co nhieu so nguyen to nhat la:";
    for (int i = 0; i < n; ++i) {
        if (demSoNguyenTo(A[i], n) == maxPrimeCount) {
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;
}

// Ham tinh tong cac so tren duong bien cua ma tran
int tinhTongDuongBien(int A[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        // Tinh tong cac so tren hang dau va hang cuoi
        sum += A[0][i];
        sum += A[n - 1][i];
        // Tinh tong cac so tren cot dau va cot cuoi
        sum += A[i][0];
        sum += A[i][n - 1];
    }
    // Loai bo cac phan tu duoc tinh trung o goc
    sum -= A[0][0] + A[0][n - 1] + A[n - 1][0] + A[n - 1][n - 1];
    return sum;
}

int main() {
    int n;
    // Nhap kich thuoc cua ma tran tu nguoi dung
    std::cout << "Nhap cap cua ma tran (n <= 10): ";
    std::cin >> n;

    int A[MAX_SIZE][MAX_SIZE]; // Khai bao ma tran A voi kich thuoc toi da la MAX_SIZE

    // Nhap ma tran A tu nguoi dung
    nhapMaTran(A, n);
    // Xuat ma tran A da nhap
    xuatMaTran(A, n);

    // Liet ke cac dong co nhieu so nguyen to nhat
    lietKeDongNhieuSoNguyenToNhat(A, n);

    // Tinh tong cac so tren duong bien cua ma tran
    int tongDuongBien = tinhTongDuongBien(A, n);
    std::cout << "Tong cac so tren duong bien cua ma tran: " << tongDuongBien << std::endl;

    return 0;
}

