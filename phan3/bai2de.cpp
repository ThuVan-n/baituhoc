#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 50;
const int MAX_LEN = 40;

// H�m nh?p th�ng tin sinh vi�n
void nhapSinhVien(char fullName[][MAX_LEN], int& soSinhVien)
{
    cout << "Nhap so luong sinh vien: ";
    cin >> soSinhVien;
    cin.ignore();
    if (soSinhVien > MAX_SINH_VIEN)
    {
        cout << "So luong sinh vien nhap vuot qua gioi han. Chi nhan toi da " << MAX_SINH_VIEN << " sinh vien." << endl;
        soSinhVien = MAX_SINH_VIEN;
    }
    for (int i = 0; i < soSinhVien; ++i)
    {
        cout << "Nhap ho ten cho sinh vien thu " << i + 1 << ": ";
        cin.getline(fullName[i], MAX_LEN);
    }
}

// H�m t�m sinh vi�n c� h? l� "Nguyen"
void timSinhVienNguyen(char fullName[][MAX_LEN], int soSinhVien)
{
    cout << "Danh sach sinh vien co ho la Nguyen:" << endl;
    for (int i = 0; i < soSinhVien; ++i)
    {
        // So s�nh h? c?a sinh vi�n v?i "Nguyen"
        if (strstr(fullName[i], "Nguyen") != NULL)
        {
            cout << fullName[i] << endl;
        }
    }
}

// H�m t�m v� xu?t sinh vi�n c� ph?n t�n d�i nh?t
void timSinhVienTenDaiNhat(char fullName[][MAX_LEN], int soSinhVien)
{
    int iDoDaiMax = 0;

    // T�m d? d�i l?n nh?t c?a ph?n t�n
    for (int i = 0; i < soSinhVien; ++i)
    {
        int doDai = strlen(fullName[i]);
        if (doDai > iDoDaiMax)
        {
            iDoDaiMax = doDai;
        }
    }

    // Xu?t c�c sinh vi�n c� ph?n t�n c� d? d�i b?ng d? d�i l?n nh?t
    cout << "Sinh vien co phan ten dai nhat la:" << endl;
    for (int i = 0; i < soSinhVien; ++i)
    {
        if (strlen(fullName[i]) == iDoDaiMax)
        {
            cout << fullName[i] << endl;
        }
    }
}

int main()
{
    char fullName[MAX_SINH_VIEN][MAX_LEN];
    int soSinhVien;

    nhapSinhVien(fullName, soSinhVien); // Nh?p danh s�ch sinh vi�n

    timSinhVienNguyen(fullName, soSinhVien); // T�m sinh vi�n c� h? l� "Nguyen"

    timSinhVienTenDaiNhat(fullName, soSinhVien); // T�m sinh vi�n c� ph?n t�n d�i nh?t

    return 0;
}

