//y tuong cua bai toan la su dung vong lap loai bo tung so dong thoi tang bien dem len 1 cho den het 
#include <iostream>

// Ham tra ve chieu dai cua mot so nguyen
int getIntegerLength(int num)
{
    // Xu ly truong hop dac biet: so 0 co chieu dai la 1
    if (num == 0) 
    
        return 1; 

    // Xac dinh chieu dai su dung vong lap
    int length = 0; // Bien dem chieu dai cua so nguyen
    while (num != 0)
    {
        num /= 10; // Loai bo chu so cuoi cung cua so nguyen
        ++length; // Tang bien dem chieu dai len 1
    }

    return length; // Tra ve chieu dai cua so nguyen
}

int main() {
    int so_nguyen;
    std::cout << "Nhap so nguyen: "; 
    std::cin >> so_nguyen; 
    
    // Goi ham getIntegerLength de tinh chieu dai cua so nguyen va in ket qua ra man hinh
    int chieu_dai = getIntegerLength(so_nguyen);
    std::cout << "Chieu dai cua so nguyen " << so_nguyen << " la: " << chieu_dai << std::endl;
    return 0;
    }

