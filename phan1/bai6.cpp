#include <iostream>

// Ham tinh so Fibonacci tai vi tri n
int fibonacci(int n) 
{
     // Truong hop co ban: neu n <= 1, tra ve gia tri cua n
    if (n <= 1) 
    {
        return n;
    }

    // Khai bao mot mang de luu tru cac so Fibonacci tu 0 den n
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    // Tinh toan cac so Fibonacci tu 2 den n
    for (int i = 2; i <= n; ++i) 
    {
        // Su dung quy luat fib[i] = fib[i-1] + fib[i-2]
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Tra ve so Fibonacci tai vi tri n
    return fib[n];
}

// Ham tinh tong cac so Fibonacci chan tu F(M) den F(N)
int sumEvenFibonacci(int M, int N) 
{
    int sum = 0;
    int currentFibonacci = fibonacci(M);

    // Vong lap qua tung so Fibonacci tu F(M) den F(N)
    while (currentFibonacci <= fibonacci(N)) 
    {
        // Kiem tra xem so hien tai co phai la so chan khong
        if (currentFibonacci % 2 == 0) 
        {
            sum += currentFibonacci; // Neu la so chan, them vao tong
        }

        // Chuyen sang so Fibonacci ke tiep
        ++M;
        currentFibonacci = fibonacci(M);
    }

    return sum;
}

int main() 
{
    int M, N;
    std::cout << "Nhap M va N (M < N): ";
    std::cin >> M >> N;

    // Kiem tra neu M >= N, thi thoat chuong trinh
    if (M >= N) 
    {
        std::cout << "Nhap sai, M phai nho hon N.\n";
        return 1;
    }

    // Tinh tong cac so Fibonacci chan tu F(M) den F(N)
    int sum = sumEvenFibonacci(M, N);
    std::cout << "Tong cac so Fibonacci chan tu F(" << M << ") den F(" << N << ") la: " << sum << std::endl;

    return 0;
}

