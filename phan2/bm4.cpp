#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 40;
const int MAX_LEN = 40;

// Nh?p th�ng tin sinh vi�n
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

// T�ch h? t? h? t�n
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

// T�ch t�n t? h? t�n
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

// S?p x?p theo t�n
void sapXepTheoTen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    for (int i = 0; i < soSinhVien - 1; ++i) {
        for (int j = i + 1; j < soSinhVien; ++j) {
            if (strcmp(lastName[i], lastName[j]) > 0) {
                swap(fullName[i], fullName[j]);
                swap(lastName[i], lastName[j]);
            }
            else if (strcmp(lastName[i], lastName[j]) == 0) {
                // So s�nh t�n n?u h? gi?ng nhau
                if (strcmp(fullName[i], fullName[j]) > 0) {
                    swap(fullName[i], fullName[j]);
                }
            }
        }
    }
}

// T�m sinh vi�n c� h? l� "Nguyen"
void timSinhVienNguyen(char fullName[][MAX_LEN], char lastName[][MAX_LEN], int soSinhVien) {
    cout << "Danh sach sinh vien co ho la 'Nguyen':" << endl;
    for (int i = 0; i < soSinhVien; ++i) {
        if (strstr(fullName[i], "Nguyen") != NULL) { // S?a t? nullptr th�nh NULL
            cout << fullName[i] << endl;
        }
    }
}

// T�m sinh vi�n c� ph?n t�n d�i nh?t
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

    // Nh?p th�ng tin sinh vi�n
    nhapSinhVien(fullName, soSinhVien);

    // T�ch h?
    tachHo(fullName, firstName, soSinhVien);

    // T�ch t�n
    tachTen(fullName, lastName, soSinhVien);

    // S?p x?p theo t�n
    sapXepTheoTen(fullName, lastName, soSinhVien);

    // T�m sinh vi�n c� h? "Nguyen"
    timSinhVienNguyen(fullName, lastName, soSinhVien);

    // T�m sinh vi�n c� ph?n t�n d�i nh?t
    timSinhVienTenDaiNhat(fullName, soSinhVien);

    return 0;
}


