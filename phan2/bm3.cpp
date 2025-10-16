#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 50;
const int MAX_LEN = 50;

// H�m nh?p th�ng tin sinh vi�n
void nhapSinhVien(char fullName[][MAX_LEN], int& soSinhVien) {
    cout << "Nhap so luong sinh vien: ";
    cin >> soSinhVien;
    cin.ignore(); // Lo?i b? k� t? '\n' trong b? nh? d?m

    // Ki?m tra s? lu?ng sinh vi�n nh?p v�o
    if (soSinhVien > MAX_SINH_VIEN) {
        cout << "So luong sinh vien nhap vuot qua gioi han. Chi nhan toi da " << MAX_SINH_VIEN << " sinh vien." << endl;
        soSinhVien = MAX_SINH_VIEN;
    }

    // Nh?p h? t�n c?a t?ng sinh vi�n
    for (int i = 0; i < soSinhVien; ++i) {
        cout << "Nhap ho ten cho sinh vien thu " << i + 1 << ": ";
        cin.getline(fullName[i], MAX_LEN); // �?c t�n sinh vi�n t? input
    }
}

// H�m t�ch h? t? h? t�n
void tachHo(char fullName[][MAX_LEN], char firstName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien; ++i) {
        int j = 0;
        // Duy?t qua t?ng k� t? trong t�n d?n khi g?p d?u c�ch ho?c k?t th�c chu?i
        while (fullName[i][j] != ' ' && fullName[i][j] != '\0') {
            firstName[i][j] = fullName[i][j]; // Sao ch�p k� t? t? h? t�n sang h?
            ++j;
        }
        firstName[i][j] = '\0'; // Th�m k� t? k?t th�c chu?i
    }
}

// H�m t�ch t�n t? h? t�n
void tachTen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien; ++i) {
        char* strPart = strtok(fullName[i], " "); // T�ch t�n t? chu?i h? t�n
        char* lastNamePart = NULL;
        while (strPart != NULL) {
            lastNamePart = strPart; // Luu ph?n t�n v�o bi?n lastNamePart
            strPart = strtok(NULL, " "); // Ti?p t?c t�ch ph?n t? ti?p theo
        }
        strcpy(lastName[i], lastNamePart); // Sao ch�p ph?n t�n v�o m?ng lastName
    }
}

// H�m s?p x?p theo t�n
void sapXepTheoTen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien - 1; ++i) {
        for (int j = i + 1; j < soSinhVien; ++j) {
            // So s�nh hai ph?n t? li�n ti?p d?a tr�n ph?n t�n c?a sinh vi�n
            if (strcmp(lastName[i], lastName[j]) > 0) {
                // �?i ch? hai ph?n t? n?u ph?n t? sau c� ph?n t�n nh? hon ph?n t? tru?c
                swap(fullName[i], fullName[j]);
                swap(lastName[i], lastName[j]);
            }
        }
    }
}

// H�m t�m sinh vi�n c� h? l� "Nguy?n"
void timSinhVienNguyen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    cout << "Danh sach sinh vien co ho la 'Nguy?n':" << endl;
    for (int i = 0; i < soSinhVien; ++i) {
        // Ki?m tra n?u ph?n h? c?a sinh vi�n ch?a chu?i "Nguy?n"
        if (strstr(lastName[i], "Nguy?n") != NULL) {
            cout << fullName[i] << endl; // Xu?t th�ng tin c?a sinh vi�n d�
        }
    }
}

// H�m t�m sinh vi�n c� ph?n t�n d�i nh?t
void timSinhVienTenDaiNhat(char fullName[][MAX_LEN], int soSinhVien) {
    int iDoDaiMax = 0;
    // T�m d? d�i l?n nh?t c?a ph?n t�n
    for (int i = 0; i < soSinhVien; ++i) {
        int doDai = strlen(fullName[i]);
        if (doDai > iDoDaiMax) {
            iDoDaiMax = doDai;
        }
    }
    
    cout << "Sinh vien co phan ten dai nhat (" << iDoDaiMax << " ky tu):" << endl;
    // Xu?t th�ng tin c?a nh?ng sinh vi�n c� ph?n t�n c� d? d�i b?ng d? d�i l?n nh?t
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

    // Nh?p th�ng tin sinh vi�n
    nhapSinhVien(fullName, soSinhVien);

    // a) T�ch h?
    tachHo(fullName, firstName, soSinhVien);

    // b) T�ch t�n
    tachTen(fullName, lastName, soSinhVien);

    // c) S?p x?p theo t�n
    sapXepTheoTen(fullName, lastName, soSinhVien);

    // d) T�m sinh vi�n c� h? l� "Nguy?n"
    timSinhVienNguyen(fullName, lastName, soSinhVien);

    // e) T�m sinh vi�n c� ph?n t�n d�i nh?t
    timSinhVienTenDaiNhat(fullName, soSinhVien);

    return 0;
}

