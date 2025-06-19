#include <iostream>

int getIntegerLength(int num)
{
    int length = 0;
    while (num != 0)
    {
        num /= 10;
        ++length;
    }
    return length;
}

int main()
{
    int so_nguyen;
    std::cout << "Nhap so nguyen: ";
    std::cin >> so_nguyen;

    int chieu_dai = getIntegerLength(so_nguyen);
    std::cout << "Chieu dai cua so nguyen " << so_nguyen << " la: " << chieu_dai << std::endl;
    return 0;
} // Ğ?m b?o có d?u } dóng k?t thúc c?a hàm main và k?t thúc c?a chuong trình

