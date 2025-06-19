#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 40;
const int MAX_LEN = 40;

// Hàm nh?p thông tin sinh viên
void nhapSinhVien(char fullName[][MAX_LEN], int& soSinhVien)
{
    cout << "Nhap so luong sinh vien: ";
    cin >> soSinhVien;
    cin.ignore(); // Lo?i b? ký t? '\n' trong b? nh? d?m
    if (soSinhVien > MAX_SINH_VIEN)
    {
        cout << "So luong sinh vien nhap vuot qua gioi han. Chi nhan toi da " << MAX_SINH_VIEN << " sinh vien." << endl;
        soSinhVien = MAX_SINH_VIEN;
    }
    for (int i = 0; i < soSinhVien; ++i)
    {
        cout << "Nhap ho ten cho sinh vien thu " << i + 1 << ": ";
        cin.getline(fullName[i], MAX_LEN);
        // Ch?nh s?a d?nh d?ng chu?i h? tên
        // Ví d?: chuy?n t?t c? các ký t? thành ch? thu?ng d? th?c hi?n so sánh d? dàng hon
        for (int j = 0; j < strlen(fullName[i]); ++j)
        {
            fullName[i][j] = tolower(fullName[i][j]);
        }
    }
}

// Hàm s?p x?p m?ng fullName theo th? t? tang d?n c?a ph?n tên sinh viên
void sapXepTheoTen(char fullName[][MAX_LEN], int soSinhVien)
{
    for (int i = 0; i < soSinhVien - 1; ++i)
    {
        for (int j = i + 1; j < soSinhVien; ++j)
        {
            // So sánh ph?n tên c?a hai sinh viên
            if (strcmp(fullName[i] + strlen(fullName[i]) - 1, fullName[j] + strlen(fullName[j]) - 1) > 0)
            {
                // N?u ph?n tên c?a sinh viên th? i l?n hon ph?n tên c?a sinh viên th? j, thì hoán d?i v? trí
                char temp[MAX_LEN];
                strcpy(temp, fullName[i]);
                strcpy(fullName[i], fullName[j]);
                strcpy(fullName[j], temp);
            }
        }
    }
}

int main()
{
    char fullName[MAX_SINH_VIEN][MAX_LEN];
    int soSinhVien;

    nhapSinhVien(fullName, soSinhVien); // G?i hàm nh?p thông tin sinh viên

    sapXepTheoTen(fullName, soSinhVien); // G?i hàm s?p x?p theo tên

    // Xu?t danh sách sinh viên sau khi s?p x?p
    cout << "Danh sach sinh vien sau khi sap xep theo ten:" << endl;
    for (int i = 0; i < soSinhVien; ++i)
    {
        cout << fullName[i] << endl;
    }

    return 0;
}



