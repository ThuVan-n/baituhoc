#include <iostream>
using namespace std;

int insertAtPosition(int arr[], int size, int x, int p) 
{
    // Kiem tra vi tri chen co hop le khong
    if (p >= 0 && p <= size) 
    {
        // Dich chuyen cac phan tu tu vi tri chen den cuoi mang sang phai mot vi tri
        for (int i = size; i > p; --i) 
        {
            arr[i] = arr[i - 1];
        }
        
        // Chen gia tri moi vao vi tri p
        arr[p] = x;
        
        // Tang kich thuoc mang len mot don vi
        ++size;
    }
    else 
    {
        // In thong bao loi neu vi tri chen khong hop le
        cout << "Vi tri chen khong hop le." << endl;
    }
    
    // Tra ve kich thuoc moi cua mang sau khi chen
    return size;
}

int main() {
    int arr[100];
    int size, x, p;

    // Nhap so luong phan tu cua mang
    cout << "Nhap so luong phan tu cua mang (toi da 100 phan tu): ";
    cin >> size;

    // Nhap cac phan tu cua mang
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }

    // Nhap gia tri va vi tri chen
    cout << "Nhap gia tri can chen: ";
    cin >> x;
    cout << "Nhap vi tri can chen: ";
    cin >> p;

    // Chen so vao mang
    size = insertAtPosition(arr, size, x, p);

    // In ra mang sau khi chen
    cout << "Mang sau khi chen:\n";
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }

    return 0;
}

