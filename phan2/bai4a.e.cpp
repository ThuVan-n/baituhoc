#include <iostream>

const int MAX_SIZE = 10;

// Ham nhap ma tran A
void nhapMaTran(int A[][MAX_SIZE], int n) {
    std::cout << "Nhap cac phan tu cua ma tran A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> A[i][j];
        }
    }
}

// Ham xuat ma tran A
void xuatMaTran(int A[][MAX_SIZE], int n) {
    std::cout << "Ma tran A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Ham tinh tong cac phan tu nam ngoai duong cheo chinh
int tinhTongNgoaiDuongCheo(int A[][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) { // Kiem tra nam ngoai duong cheo chinh
                sum += A[i][j];
            }
        }
    }
    return sum;
}

// Ham tim gia tri lon nhat tren duong cheo chinh
int timMaxTrenDuongCheoChinh(int A[][MAX_SIZE], int n) {
    int maxVal = A[0][0];
    for (int i = 1; i < n; ++i) {
        if (A[i][i] > maxVal) { // So sanh voi cac phan tu tren duong cheo chinh
            maxVal = A[i][i];
        }
    }
    return maxVal;
}

// Ham dem so luong phan tu la so am tren duong cheo phu
int demSoAmDuongCheoPhu(int A[][MAX_SIZE], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i][n - i - 1] < 0) { // Kiem tra so am tren duong cheo phu
            count++;
        }
    }
    return count;
}

// Ham kiem tra so nguyen to
bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Ham dem so luong so nguyen to trong ma tran
int demSoNguyenTo(int A[][MAX_SIZE], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laSoNguyenTo(A[i][j])) { // Kiem tra so nguyen to
                count++;
            }
        }
    }
    return count;
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

    // Tinh tong cac phan tu nam ngoai duong cheo chinh cua ma tran A
    int tongNgoaiDuongCheo = tinhTongNgoaiDuongCheo(A, n);
    std::cout << "Tong cac phan tu nam ngoai duong cheo chinh: " << tongNgoaiDuongCheo << std::endl;

    // Tim gia tri lon nhat tren duong cheo chinh cua ma tran A
    int maxTrenDuongCheo = timMaxTrenDuongCheoChinh(A, n);
    std::cout << "Gia tri lon nhat tren duong cheo chinh: " << maxTrenDuongCheo << std::endl;

    // Dem so luong phan tu la so am tren duong cheo phu cua ma tran A
    int soAmTrenDuongCheoPhu = demSoAmDuongCheoPhu(A, n);
    std::cout << "So luong phan tu am tren duong cheo phu: " << soAmTrenDuongCheoPhu << std::endl;

    // Dem so luong so nguyen to trong ma tran A
    int soNguyenTo = demSoNguyenTo(A, n);
    std::cout << "So luong so nguyen to trong ma tran: " << soNguyenTo << std::endl;

    return 0;
}

