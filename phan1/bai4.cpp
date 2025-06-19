//y tuong cua bai toan la su dung phep chia va lay phan du de chuyen do so he thap phan sang so he nhi phan
#include <iostream>
#include <string>

// Ham chuyen doi so he thap phan sang so he nhi phan hoac thap luc phan
std::string convertToBinaryOrHexadecimal(int decimalNumber, int base) 
{
    // Kiem tra neu co so khong phai la 2 hoac 16
    if (base != 2 && base != 16) 
    {
        std::cerr << "He so chi duoc phep la 2 hoac 16." << std::endl;
        return ""; // Tra ve chuoi rong neu co so khong hop le
    }

    std::string result = ""; // Khoi tao chuoi ket qua

    // Lap de chuyen doi tu he thap phan sang he nhi phan hoac thap luc phan
    while (decimalNumber > 0) 
    {
        int remainder = decimalNumber % base; // Tinh phan du

        char digit;
        // Chuyen doi phan du thanh ky tu tuong ung
        if (remainder < 10) 
        {
            digit = '0' + remainder;
        }
        else 
        {
            digit = 'A' + (remainder - 10);
        }

        // Them ky tu vao dau chuoi ket qua
        result = digit + result;

        // Chia so he thap phan cho co so de tiep tuc vong lap
        decimalNumber /= base;
    }

    return result; // Tra ve chuoi ket qua
}

int main()
{
    int decimalNumber;
    int base;

    std::cout << "Nhap so he thap phan can chuyen doi: ";
    std::cin >> decimalNumber;

    std::cout << "Nhap co so muon chuyen doi (2 hoac 16): ";
    std::cin >> base;

    // Goi ham convertToBinaryOrHexadecimal de chuyen doi va in ket qua
    std::string result = convertToBinaryOrHexadecimal(decimalNumber, base);
    if (result != "")
    {
        std::cout << "Ket qua sau khi chuyen doi la: " << result << std::endl;
    }

    return 0;
}

