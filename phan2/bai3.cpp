#include <iostream>
#include <climits> // De su dung INT_MIN
#include <algorithm> // De su dung ham std::sort

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

// a. Nhap mang A
void nhapMang(int A[][MAX_COLS], int m, int n) {
    std::cout << "Nhap mang A[" << m << "][" << n << "]:\n";
    // Duyet qua tung hang cua mang
    for (int i = 0; i < m; ++i) {
    	// Duyet qua tung cot cua moi hang
        for (int j = 0; j < n; ++j) {
        	 // Hien thi thong bao yeu cau nguoi dung nhap gia tri cua moi phan tu
            std::cout << "A[" << i << "][" << j << "]: ";
            // Nhap gia tri cua phan tu vao mang A tai vi tri (i, j)
            std::cin >> A[i][j];
        }
    }
}
// Ham xuat mang A
void xuatMang(int A[][MAX_COLS], int m, int n) {
    std::cout << "Mang A:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
        	// Xuat gia tri cua phan tu tai vi tri (i, j) cua mang A
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// b. Dem so luong phan tu am trong mang
int demSoLuongAm(int A[][MAX_COLS], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] < 0) {
                ++count;
            }
        }
    }
    return count;
}

// c. Tim gia tri lon nhat trong mang
int timMax(int A[][MAX_COLS], int m, int n) {
    int max = INT_MIN;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] > max) {//gan cho gia tri dau tien la max sau do kiem tra qua tung phan tu dem khi ket thuc
                max = A[i][j];
            }
        }
    }
    return max;
}

// d. Tim dong co tong phan tu lon nhat
int timDongTongMax(int A[][MAX_COLS], int m, int n) {
    int maxSum = INT_MIN;
    int dongMax = -1;
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += A[i][j];//tinh tong cac phan tu tren dong thu i
        }
        if (sum > maxSum) {
            maxSum = sum;
            dongMax = i;//luu lai dong co tong lon nhat
        }
    }
    return dongMax;
}

// e. Sap xep tung dong cua A theo thu tu tang dan
void sapXepTangDanTheoDong(int A[][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; ++i) {
        std::sort(A[i], A[i] + n);
    }
}

// f. Sap xep mang A theo thu tu giam dan
void sapXepGiamDan(int A[][MAX_COLS], int m, int n) {
    // Tao mot mang tam de luu tru tat ca cac phan tu cua mang 2D A
    int temp[MAX_ROWS * MAX_COLS];
    int index = 0;

    // Sao chep tat ca cac phan tu tu mang A vao mang temp
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[index++] = A[i][j];
        }
    }

    // Sap xep mang temp theo thu tu giam dan
    std::sort(temp, temp + m * n, std::greater<int>());

    // Sao chep lai cac phan tu da duoc sap xep tu mang temp vao mang A ban dau
    index = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = temp[index++];
        }
    }
}


int main() {
    int m, n;
    std::cout << "Nhap so hang (m): ";
    std::cin >> m;
    std::cout << "Nhap so cot (n): ";
    std::cin >> n;

    int A[MAX_ROWS][MAX_COLS];

    // a. Nhap mang A
    nhapMang(A, m, n);
    
    // a. Xuat mang A
    xuatMang(A, m, n);

    // b. Dem so luong phan tu am trong mang
    std::cout << "So luong phan tu am trong mang: " << demSoLuongAm(A, m, n) << std::endl;

    // c. Tim gia tri lon nhat trong mang
    std::cout << "Gia tri lon nhat trong mang: " << timMax(A, m, n) << std::endl;

    // d. Tim dong co tong phan tu lon nhat
    int dongMax = timDongTongMax(A, m, n);
    if (dongMax != -1) {
        std::cout << "Dong co tong cac phan tu lon nhat: " << dongMax << std::endl;
    } else {
        std::cout << "Mang rong." << std::endl;
    }

    // e. Sap xep tung dong cua A theo thu tu tang dan
    sapXepTangDanTheoDong(A, m, n);
    std::cout << "Mang sau khi sap xep tung dong tang dan:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // f. Sap xep mang A theo thu tu giam dan
    sapXepGiamDan(A, m, n);
    std::cout << "Mang sau khi sap xep giam dan:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



