#include <iostream>
#include <string>
#include <cctype> // Thu vien de su dung cac ham kiem tra ky tu

// a) Ham xuat chuoi theo chieu nguoc lai
void xuatChuoiNguocLai(const std::string& str) {
    std::cout << "Chuoi S theo chieu nguoc lai: ";
    for (int i = str.length() - 1; i >= 0; --i) {
        std::cout << str[i];
    }
    std::cout << std::endl;
}



// b) Ham dem so chu cai va chu so trong chuoi
void demChuCaiVaChuSo(const std::string& str) {
    int chuCai = 0, chuSo = 0;
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (isalpha(c)) { // Kiem tra xem co phai la chu cai khong
            chuCai++;
        } else if (isdigit(c)) { // Kiem tra xem co phai la chu so khong
            chuSo++;
        }
    }
    std::cout << "Chuoi S co " << chuCai << " chu cai va " << chuSo << " chu so." << std::endl;
}

// c) Ham dinh dang chuoi theo yeu cau
std::string dinhDangChuoi(const std::string& str) {
    std::string formattedStr;
    bool newWord = true; // Bien danh dau la tu moi
    for (int i = 0; i < str.length(); ++i) {
        char c = str[i]; // Khai bao bien c o day
        if (isspace(c)) { // Neu la khoang trang
            newWord = true; // Danh dau tu moi
            formattedStr += ' '; // Them khoang trang vao chuoi dinh dang
        } else {
            if (newWord) { // Neu la ky tu dau tien cua tu
                formattedStr += toupper(c); // Viet hoa ky tu
                newWord = false; // Danh dau tu da duoc xu ly
            } else {
                formattedStr += tolower(c); // Viet thuong cac ky tu khac trong tu
            }
        }
    }
    return formattedStr;
}


// d) Ham kiem tra xem chuoi S co phai la "Ngon ngu lap trinh C++" hay khong
bool laChuoiNgonNguLapTrinhCpp(const std::string& str) {
    return (str == "Ngon ngu lap trinh C++");
}


// e) Ham xoa cac ky tu khong phai la chu cai khoi chuoi S
std::string xoaKyTuKhongPhaiChuCai(const std::string& str) {
    std::string result;
    for (int i = 0; i < str.length(); ++i) {
        char c = str[i]; // Khai bao bien c o day
        if (isalpha(c)) { // Neu la chu cai
            result += c;
        }
    }
    return result;
}

// f) Ham thay the cac chu in hoa trong chuoi S bang ki tu dau *
std::string thayTheChuInHoa(const std::string& str) {
    std::string result;
    for (int i = 0; i < str.length(); ++i) {
        char c = str[i]; // Khai bao bien c o day
        if (isupper(c)) { // Neu la chu in hoa
            result += '*';
        } else {
            result += c;
        }
    }
    return result;
}

// g) Ham them vao cuoi chuoi S chuoi "Hello"
std::string themChuoiHelloCuoiChuoi(const std::string& str) {
    return str + " Hello";
}

int main() {
    std::string S;
    std::cout << "Nhap chuoi S: ";
    std::getline(std::cin, S); // Nhap chuoi co the chua ca dau cach

    xuatChuoiNguocLai(S); // a) Xuat chuoi theo chieu nguoc lai
    demChuCaiVaChuSo(S); // b) Dem so chu cai va chu so trong chuoi

    // c) Dinh dang chuoi S theo yeu cau
    std::string S_DinhDang = dinhDangChuoi(S);
    std::cout << "Chuoi S sau khi dinh dang: " << S_DinhDang << std::endl;

    // d) Kiem tra xem chuoi S co phai la "Ngon ngu lap trinh C++" hay khong
    bool isNgonNguLapTrinhCpp = laChuoiNgonNguLapTrinhCpp(S);
    std::cout << "Chuoi S " << (isNgonNguLapTrinhCpp ? "la" : "khong la") << " 'Ngon ngu lap trinh C++'" << std::endl;

    // e) Xoa cac ky tu khong phai la chu cai khoi chuoi S
    std::string S_ChiChuCai = xoaKyTuKhongPhaiChuCai(S);
    std::cout << "Chuoi S sau khi xoa cac ky tu khong phai la chu cai: " << S_ChiChuCai << std::endl;

    // f) Thay the cac chu in hoa trong chuoi S bang ki tu dau *
    std::string S_ThayThe = thayTheChuInHoa(S);
    std::cout << "Chuoi S sau khi thay the cac chu in hoa: " << S_ThayThe << std::endl;

    // g) Them vao cuoi chuoi S chuoi "Hello"
    std::string S_ThemHello = themChuoiHelloCuoiChuoi(S);
    std::cout << "Chuoi S sau khi them chuoi 'Hello' vao cuoi: " << S_ThemHello << std::endl;

    return 0;
}

