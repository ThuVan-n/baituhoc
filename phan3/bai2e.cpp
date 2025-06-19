#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SINH_VIEN = 40;
const int MAX_LEN = 40;

// Ham chuyen doi chuoi (chuyen tat ca cac ky tu thanh chu thuong)
void formatStr(char str[]) {
    // Chinh sua dinh dang chuoi (chuyen tat ca cac ky tu thanh chu thuong)
    for (int j = 0; j < strlen(str); ++j)
    {
        str[j] = tolower(str[j]);
    }
}

// Ham nhap thong tin cua sinh vien va tim sinh vien co phan ten dai nhat
void nhapSinhVien(char fullName[][MAX_LEN], int& soSinhVien)
{
    cout << "Nhap so luong sinh vien: "; // Nhap so luong sinh vien
    cin >> soSinhVien;
    cin.ignore();
    if (soSinhVien > MAX_SINH_VIEN)
    {
        cout << "So luong sinh vien nhap vuot qua gioi han. Chi nhan toi da " << MAX_SINH_VIEN << " sinh vien." << endl;
        soSinhVien = MAX_SINH_VIEN;
    }
    
    int iDoDaiMax = 0; // Bien luu do dai cua chuoi dai nhat
    
    for (int i = 0; i < soSinhVien; ++i)
    {
        cout << "Nhap ho ten cho sinh vien thu " << i + 1 << ": "; // Nhap ho ten cho sinh vien thu i+1
        cin.getline(fullName[i], MAX_LEN);
        formatStr(fullName[i]); // Chuyen doi dinh dang cua chuoi ho ten
        int len = strlen(fullName[i]); // Lay do dai cua chuoi
        
        // Neu do dai cua chuoi lon hon iDoDaiMax, cap nhat iDoDaiMax
        if (len > iDoDaiMax) {
            iDoDaiMax = len;
        }
    }
    
    // Xuat ra man hinh cac sinh vien co phan ten co do dai bang iDoDaiMax
    cout << "Sinh vien co phan ten dai nhat (" << iDoDaiMax << " ky tu):" << endl;
    for (int i = 0; i < soSinhVien; ++i) {
        if (strlen(fullName[i]) == iDoDaiMax) {
            cout << fullName[i] << endl;
        }
    }
}

int main()
{
    char fullName[MAX_SINH_VIEN][MAX_LEN];
    int soSinhVien;

    nhapSinhVien(fullName, soSinhVien); // Nhap thong tin cua sinh vien va tim sinh vien co phan ten dai nhat

    return 0;
}

