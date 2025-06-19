#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 50;
const int MAX_LEN = 50;

// Ham tach ho tu ho ten
void tachHo(char fullName[][MAX_LEN], char firstName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien; ++i) {
        int j = 0;
        // Duyet qua tung ky tu trong ten den khi gap dau cach hoac ket thuc chuoi
        while (fullName[i][j] != ' ' && fullName[i][j] != '\0') {
            firstName[i][j] = fullName[i][j]; // Sao chep ky tu tu ho ten sang ho
            ++j;
        }
        firstName[i][j] = '\0'; // Them ky tu ket thuc chuoi
    }
}

int main() {
    char fullName[MAX_SINH_VIEN][MAX_LEN];
    char firstName[MAX_SINH_VIEN][MAX_LEN];
    int soSinhVien;

    // Nhap so luong sinh vien
    cout << "Nhap so luong sinh vien: ";
    cin >> soSinhVien;
    cin.ignore(); // Loai bo ky tu '\n' trong bo nho dem

    // Nhap ho ten cua tung sinh vien
    for (int i = 0; i < soSinhVien; ++i) {
        cout << "Nhap ho ten cho sinh vien thu " << i + 1 << ": ";
        cin.getline(fullName[i], MAX_LEN); // Doc ten sinh vien tu input
    }

    // Goi ham de tach ho tu ho ten va luu vao mang firstName
    tachHo(fullName, firstName, soSinhVien);

    // Xuat ho cua sinh vien tu mang firstName
    cout << "Ho cua sinh vien:\n";
    for (int i = 0; i < soSinhVien; ++i) {
        cout << firstName[i] << endl;
    }

    return 0;
}



