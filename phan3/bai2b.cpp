#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 50;
const int MAX_LEN = 50;

// Ham tach ten tu ho va ten
void tachTen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien; ++i) {
        int j = strlen(fullName[i]) - 1; // Tim vi tri cuoi cung cua chuoi ho ten
        // Duyet nguoc tu vi tri cuoi cung de tim dau cach
        while (j >= 0 && fullName[i][j] != ' ') {
            --j;
        }
        if (j >= 0) { // Neu tim thay dau cach
            strcpy(lastName[i], fullName[i] + j + 1); // Sao chep phan ten tu vi tri sau dau cach vao mang lastName
        } else { // Neu khong tim thay dau cach (chi co ho)
            strcpy(lastName[i], fullName[i]); // Sao chep toan bo chuoi vao mang lastName
        }
    }
}

int main() {
    char fullName[MAX_SINH_VIEN][MAX_LEN];
    char lastName[MAX_SINH_VIEN][MAX_LEN];
    int soSinhVien;

    // Nhap so luong sinh vien
    cout << "Nhap so luong sinh vien: ";
    cin >> soSinhVien;
    cin.ignore(); // Loai bo ky tu '\n' trong bo nho dem

    // Nhap ho ten cua tung sinh vien
    for (int i = 0; i < soSinhVien; ++i) {
        cout << "Nhap ho ten cho sinh vien thu " << i + 1 << ": ";
        cin.getline(fullName[i], MAX_LEN); // Doc ho ten sinh vien tu input
    }

    // Goi ham de tach ten tu ho va ten va luu vao mang lastName
    tachTen(fullName, lastName, soSinhVien);

    // Xuat ten cua sinh vien tu mang lastName
    cout << "Ten cua sinh vien:\n";
    for (int i = 0; i < soSinhVien; ++i) {
        cout << lastName[i] << endl;
    }

    return 0;
}

