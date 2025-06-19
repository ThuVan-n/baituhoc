#include <iostream>

// Ham tron 2 mang tang dan thanh 1 mang cung tang dan
void tronMangTangDan(int mang1[], int size1, int mang2[], int size2, int ketQua[]) {
    int i = 0, j = 0, k = 0;

    // Lap qua ca hai mang dong thoi
    while (i < size1 && j < size2) {
        // So sanh phan tu hien tai cua moi mang
        if (mang1[i] < mang2[j]) {
            // Neu phan tu cua mang 1 nho hon, dua vao mang ket qua
            ketQua[k++] = mang1[i++];
        } else {
            // Neu phan tu cua mang 2 nho hon hoac bang, dua vao mang ket qua
            ketQua[k++] = mang2[j++];
        }
    }

    // Neu mot trong hai mang da duyet het, sao chep phan con lai cua mang kia vao mang ket qua
    while (i < size1) {
        ketQua[k++] = mang1[i++];
    }

    while (j < size2) {
        ketQua[k++] = mang2[j++];
    }
}

int main() {
    int size1, size2;
    
    // Nhap kich thuoc cua mang 1
    std::cout << "Nhap kich thuoc cua mang 1: ";
    std::cin >> size1;

    // Nhap cac phan tu cua mang 1
    int mang1[size1];
    std::cout << "Nhap cac phan tu cua mang 1:\n";
    for (int i = 0; i < size1; ++i) {
        std::cout << "Phan tu thu " << i + 1 << ": ";
        std::cin >> mang1[i];
    }

    // Nhap kich thuoc cua mang 2
    std::cout << "Nhap kich thuoc cua mang 2: ";
    std::cin >> size2;

    // Nhap cac phan tu cua mang 2
    int mang2[size2];
    std::cout << "Nhap cac phan tu cua mang 2:\n";
    for (int i = 0; i < size2; ++i) {
        std::cout << "Phan tu thu " << i + 1 << ": ";
        std::cin >> mang2[i];
    }

    int ketQua[size1 + size2]; // Mang ket qua co kich thuoc bang tong kich thuoc cua mang 1 va mang 2

    // Goi ham tron mang
    tronMangTangDan(mang1, size1, mang2, size2, ketQua);

    // In mang ket qua
    std::cout << "Mang ket qua sau khi tron: ";
    for (int i = 0; i < size1 + size2; ++i) {
        std::cout << ketQua[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

