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

// Ham tim cac so xuat hien nhieu nhat trong ma tran
void timSoXuatHienNhieuNhat(int A[][MAX_SIZE], int n) {
    int freq[MAX_SIZE * MAX_SIZE] = {0}; // Mang luu tan suat xuat hien cua cac so
    int maxFreq = 0; // Bien luu tru tan suat xuat hien lon nhat

    // Tinh tan suat xuat hien cua tung so trong ma tran
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            freq[A[i][j]]++;
            maxFreq = std::max(maxFreq, freq[A[i][j]]);
        }
    }

    // Xuat cac so co tan suat xuat hien bang maxFreq
    std::cout << "Cac so xuat hien nhieu nhat trong ma tran la:";
    for (int i = 0; i < MAX_SIZE * MAX_SIZE; ++i) {
        if (freq[i] == maxFreq) {
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;
}

// Ham dem so luong so chan trong mot dong cua ma tran
int demSoChan(int A[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Ham liet ke cac dong co nhieu so chan nhat trong ma tran
void lietKeDongNhieuSoChanNhat(int A[][MAX_SIZE], int n) {
    int maxEvenCount = 0; // Bien luu tru so luong so chan nhieu nhat
    for (int i = 0; i < n; ++i) {
        maxEvenCount = std::max(maxEvenCount, demSoChan(A[i], n));
    }

    // Xuat cac dong co so luong so chan bang maxEvenCount
    std::cout << "Cac dong co nhieu so chan nhat la:";
    for (int i = 0; i < n; ++i) {
        if (demSoChan(A[i], n) == maxEvenCount) {
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;
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

    // Tim cac so xuat hien nhieu nhat trong ma tran
    timSoXuatHienNhieuNhat(A, n);

    // Liet ke cac dong co nhieu so chan nhat
    lietKeDongNhieuSoChanNhat(A, n);

    return 0;
}

