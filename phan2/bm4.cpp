#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 40;
const int MAX_LEN = 40;

// Nh?p thông tin sinh viên
void nhapSinhVien(char fullName[][MAX_LEN], int& soSinhVien) {
    cout << "Nhap so luong sinh vien: ";
    cin >> soSinhVien;
    cin.ignore();
    
    if (soSinhVien > MAX_SINH_VIEN) {
        cout << "So luong sinh vien nhap vuot qua gioi han. Chi nhan toi da " << MAX_SINH_VIEN << " sinh vien." << endl;
        soSinhVien = MAX_SINH_VIEN;
    }

    for (int i = 0; i < soSinhVien; ++i) {
        cout << "Nhap ho ten cho sinh vien thu " << i + 1 << ": ";
        cin.getline(fullName[i], MAX_LEN);
    }
}

// Tách h? t? h? tên
void tachHo(char fullName[][MAX_LEN], char firstName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien; ++i) {
        int j = 0;
        while (fullName[i][j] != ' ' && fullName[i][j] != '\0') {
            firstName[i][j] = fullName[i][j];
            ++j;
        }
        firstName[i][j] = '\0';
    }
}

// Tách tên t? h? tên
void tachTen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien; ++i) {
        char temp[MAX_LEN];
        strcpy(temp, fullName[i]);
        char acTen[MAX_LEN] = { 0 };
        char* strPart = strtok(temp, " ");
        while (strPart != NULL) {
            strcpy(acTen, strPart);
            strPart = strtok(NULL, " ");
        }
        strcpy(lastName[i], acTen);
    }
}

// S?p x?p theo tên
void sapXepTheoTen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien - 1; ++i) {
        for (int j = i + 1; j < soSinhVien; ++j) {
            if (strcmp(lastName[i], lastName[j]) > 0) {
                swap(fullName[i], fullName[j]);
                swap(lastName[i], lastName[j]);
            }
            else if (strcmp(lastName[i], lastName[j]) == 0) {
                // So sánh tên n?u h? gi?ng nhau
                if (strcmp(fullName[i], fullName[j]) > 0) {
                    swap(fullName[i], fullName[j]);
                }
            }
        }
    }
}

// Tìm sinh viên có h? là "Nguyen"
void timSinhVienNguyen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    cout << "Danh sach sinh vien co ho la 'Nguyen':" << endl;
    for (int i = 0; i < soSinhVien; ++i) {
        if (strstr(fullName[i], "Nguyen") != NULL) { // S?a t? nullptr thành NULL
            cout << fullName[i] << endl;
        }
    }
}

// Tìm sinh viên có ph?n tên dài nh?t
void timSinhVienTenDaiNhat(char fullName[][MAX_LEN], int soSinhVien) {
    int iDoDaiMax = 0;
    for (int i = 0; i < soSinhVien; ++i) {
        int doDai = strlen(fullName[i]);
        if (doDai > iDoDaiMax) {
            iDoDaiMax = doDai;
        }
    }
    
    cout << "Sinh vien co phan ten dai nhat (" << iDoDaiMax << " ky tu):" << endl;
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

    // Nh?p thông tin sinh viên
    nhapSinhVien(fullName, soSinhVien);

    // Tách h?
    tachHo(fullName, firstName, soSinhVien);

    // Tách tên
    tachTen(fullName, lastName, soSinhVien);

    // S?p x?p theo tên
    sapXepTheoTen(fullName, lastName, soSinhVien);

    // Tìm sinh viên có h? "Nguyen"
    timSinhVienNguyen(fullName, lastName, soSinhVien);

    // Tìm sinh viên có ph?n tên dài nh?t
    timSinhVienTenDaiNhat(fullName, soSinhVien);

    return 0;
}


