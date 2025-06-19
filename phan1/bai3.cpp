//Y tuong cua bai toan la su dung vong lap de tinh toan cac phan tu cua day Fibonacci tu phan tu thu ba tro di dua tren hai phan tu truoc do cua day.
#include <iostream>

// Ham tim phan tu thu n cua day Fibonacci
unsigned long long findFibonacci(int n) 
{
    if (n <= 0) 
    {
        std::cerr << "Vui long nhap mot so nguyen duong." << std::endl;
        return 0; // Tra ve gia tri mac dinh neu n khong hop le
    }

    if (n == 1 || n == 2) 
    {
        return 1; // Tra ve 1 neu n = 1 hoac n = 2
    }

    // Khoi tao hai phan tu dau tien cua day Fibonacci
    
    unsigned long long fib1 = 1, fib2 = 1, fibonacci = 0;

    // Tinh toan phan tu thu n cua day Fibonacci su dung vong lap
    for (int i = 3; i <= n; ++i) 
    {
        fibonacci = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibonacci;
    }

    return fibonacci; // Tra ve phan tu thu n cua day Fibonacci
}

// Ham main de kiem tra ham findFibonacci()
int main()
{
    int n;
    std::cout << "Nhap so thu tu cua phan tu Fibonacci: ";
    std::cin >> n;

    // Goi ham findFibonacci de tim phan tu thu n va in ra man hinh
    unsigned long long result = findFibonacci(n);
    std::cout << "Phan tu thu " << n << " cua day Fibonacci la: " << result << std::endl;
    return 0;
}

