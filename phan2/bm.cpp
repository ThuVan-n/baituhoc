#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 50;
const int MAX_LEN = 50;

// Hàm nh?p thông tin sinh viên
void nhapSinhVien(char fullName[][MAX_LEN], int& soSinhVien) {
    cout << "Nhap so luong sinh vien: ";
    cin >> soSinhVien;
    cin.ignore(); // Lo?i b? ký t? '\n' trong b? nh? d?m

    // Ki?m tra s? lu?ng sinh viên nh?p vào
    if (soSinhVien > MAX_SINH_VIEN) {
        cout << "So luong sinh vien nhap vuot qua gioi han. Chi nhan toi da " << MAX_SINH_VIEN << " sinh vien." << endl;
        soSinhVien = MAX_SINH_VIEN;
    }

    // Nh?p h? tên c?a t?ng sinh viên
    for (int i = 0; i < soSinhVien; ++i) {
        cout << "Nhap ho ten cho sinh vien thu " << i + 1 << ": ";
        cin.getline(fullName[i], MAX_LEN); // Ð?c tên sinh viên t? input
    }
}

// Hàm tách h? t? h? tên
void tachHo(char fullName[][MAX_LEN], char firstName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien; ++i) {
        int j = 0;
        // Duy?t qua t?ng ký t? trong tên d?n khi g?p d?u cách ho?c k?t thúc chu?i
        while (fullName[i][j] != ' ' && fullName[i][j] != '\0') {
            firstName[i][j] = fullName[i][j]; // Sao chép ký t? t? h? tên sang h?
            ++j;
        }
        firstName[i][j] = '\0'; // Thêm ký t? k?t thúc chu?i
    }
}

// Hàm tách tên t? h? tên
void tachTen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien; ++i) {
        char* strPart = strtok(fullName[i], " "); // Tách tên t? chu?i h? tên
        char* lastNamePart = NULL; // Kh?i t?o con tr? b?ng NULL
        while (strPart != NULL) {
            lastNamePart = strPart; // Luu ph?n tên vào bi?n lastNamePart
            strPart = strtok(NULL, " "); // Ti?p t?c tách ph?n t? ti?p theo
        }
        strcpy(lastName[i], lastNamePart); // Sao chép ph?n tên vào m?ng lastName
    }
}

// Hàm s?p x?p theo tên
void sapXepTheoTen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien - 1; ++i) {
        for (int j = i + 1; j < soSinhVien; ++j) {
            // So sánh hai ph?n t? liên ti?p d?a trên ph?n tên c?a sinh viên
            if (strcmp(lastName[i], lastName[j]) > 0) {
                // Ð?i ch? hai ph?n t? n?u ph?n t? sau có ph?n tên nh? hon ph?n t? tru?c
                swap(fullName[i], fullName[j]);
                swap(lastName[i], lastName[j]);
            }
        }
    }
}

// Hàm tìm sinh viên có h? là "Nguyen"
void timSinhVienNguyen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    cout << "Danh sach sinh vien co ho la 'Nguyen':" << endl;
    for (int i = 0; i < soSinhVien; ++i) {
        // Ki?m tra n?u ph?n h? c?a sinh viên ch?a chu?i "Nguyen"
        if (strstr(lastName[i], "Nguyen") != NULL) {
            cout << fullName[i] << endl; // Xu?t thông tin c?a sinh viên dó
        }
    }
}

// Ham tim sinh vien co phan ten dai nhat
void timSinhVienTenDaiNhat(char fullName[][MAX_LEN], int soSinhVien) {
    int iDoDaiMax = 0;
    // Tim do dai lon nhat cua phan ten
    for (int i = 0; i < soSinhVien; ++i) {
        int doDai = strlen(fullName[i]);
        if (doDai > iDoDaiMax) {
            iDoDaiMax = doDai;
        }
    }
    
    cout << "Sinh vien co phan ten dai nhat (" << iDoDaiMax << " ky tu):" << endl;
    // Xuat thong tin cua nhung sinh vien co phan ten co do dai bang do dai lon nhat
    for (int i = 0; i < soSinhVien; ++i) {
        if (strlen(fullName[i]) == iDoDaiMax) {
            cout << fullName[i] << endl;
        }
    }
}

int main() {
    char fullName[MAX_SINH_VIEN][MAX_LEN];
    char firstName[MAX_SINH_VIEN][MAX_LEN];
    char lastName[MAX_SINH_VIEN][MAX_LEN];
    int soSinhVien;

    // Nhap thong tin sinh vien
    nhapSinhVien(fullName, soSinhVien);

    // a) Tach ho
    tachHo(fullName, firstName, soSinhVien);

    // b) Tach ten
    tachTen(fullName, lastName, soSinhVien);

    // c) Sap xep theo ten
    sapXepTheoTen(fullName, lastName, soSinhVien);

    // d) Tim sinh vien co ho la "Nguyen"
    timSinhVienNguyen(fullName, lastName, soSinhVien);

    // e) Tim sinh vien co phan ten dai nhat
    timSinhVienTenDaiNhat(fullName, soSinhVien);

    return 0;
}

