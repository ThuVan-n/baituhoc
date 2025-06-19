#include <iostream>
#include <climits> // De su dung INT_MIN
#include <algorithm> // De su dung ham std::sort

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

// Ham nhap mang A
void nhapMang(int A[][MAX_COLS], int m, int n) {
    // Hien thi thong bao yeu cau nguoi dung nhap du lieu cho mang A
    cout << "Nhap cac phan tu cua mang A[" << m << "][" << n << "]:\n";
    
    // Duyet qua tung hang cua mang
    for (int i = 0; i < m; ++i) {
        // Duyet qua tung cot cua moi hang
        for (int j = 0; j < n; ++j) {
            // Hien thi thong bao yeu cau nguoi dung nhap gia tri cua moi phan tu
            cout << "A[" << i << "][" << j << "]: ";
            // Nhap gia tri cua phan tu vao mang A tai vi tri (i, j)
            cin >> A[i][j];
        }
    }
}

// Ham xuat mang A
void xuatMang(int A[][MAX_COL], int m, int n) {
    // Hien thi thong bao cho biet se xuat mang A ra man hinh
    cout << "Mang A[" << m << "][" << n << "]:\n";
    
    // Duyet qua tung hang cua mang
    for (int i = 0; i < m; ++i) {
        // Duyet qua tung cot cua moi hang
        for (int j = 0; j < n; ++j) {
            // Xuat gia tri cua phan tu tai vi tri (i, j) cua mang A
            cout << A[i][j] << " ";
        }
        // Xuong dong sau khi hoan thanh xuat tat ca phan tu cua hang i
        cout << endl;
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
            if (A[i][j] > max) {
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
            sum += A[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            dongMax = i;
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
    int temp[MAX_ROWS * MAX_COLS];
    int index = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[index++] = A[i][j];
        }
    }
    std::sort(temp, temp + m * n, std::greater<int>());
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


