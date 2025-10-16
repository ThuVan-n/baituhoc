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
} // �?m b?o c� d?u } d�ng k?t th�c c?a h�m main v� k?t th�c c?a chuong tr�nh

