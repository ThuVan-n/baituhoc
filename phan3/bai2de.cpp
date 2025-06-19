#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 50;
const int MAX_LEN = 40;

// Hàm nh?p thông tin sinh viên
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

// Hàm tìm sinh viên có h? là "Nguyen"
void timSinhVienNguyen(char fullName[][MAX_LEN], int soSinhVien)
{
    cout << "Danh sach sinh vien co ho la Nguyen:" << endl;
    for (int i = 0; i < soSinhVien; ++i)
    {
        // So sánh h? c?a sinh viên v?i "Nguyen"
        if (strstr(fullName[i], "Nguyen") != NULL)
        {
            cout << fullName[i] << endl;
        }
    }
}

// Hàm tìm và xu?t sinh viên có ph?n tên dài nh?t
void timSinhVienTenDaiNhat(char fullName[][MAX_LEN], int soSinhVien)
{
    int iDoDaiMax = 0;

    // Tìm d? dài l?n nh?t c?a ph?n tên
    for (int i = 0; i < soSinhVien; ++i)
    {
        int doDai = strlen(fullName[i]);
        if (doDai > iDoDaiMax)
        {
            iDoDaiMax = doDai;
        }
    }

    // Xu?t các sinh viên có ph?n tên có d? dài b?ng d? dài l?n nh?t
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

    nhapSinhVien(fullName, soSinhVien); // Nh?p danh sách sinh viên

    timSinhVienNguyen(fullName, soSinhVien); // Tìm sinh viên có h? là "Nguyen"

    timSinhVienTenDaiNhat(fullName, soSinhVien); // Tìm sinh viên có ph?n tên dài nh?t

    return 0;
}

