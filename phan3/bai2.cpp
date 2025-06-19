#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Ham tach ho tu mang fullName va luu vao mang firstName
void extractFirstName(const vector<string>& fullName, vector<string>& firstName) {
    for (const string& name : fullName) {
        // Tim vi tri cua dau cach dau tien trong ten
        size_t spacePos = name.find(' ');
        // Lay phan tu dau tien cua chuoi, tu dau den vi tri dau cach
        string first = name.substr(0, spacePos);
        firstName.push_back(first);
    }
}

// Ham tach ten tu mang fullName va luu vao mang lastName
void extractLastName(const vector<string>& fullName, vector<string>& lastName) {
    for (const string& name : fullName) {
        // Tim vi tri cua dau cach cuoi cung trong ten
        size_t spacePos = name.rfind(' ');
        // Lay phan tu thu 2 cua chuoi, tu vi tri dau cach cuoi cung den het
        string last = name.substr(spacePos + 1);
        lastName.push_back(last);
    }
}

int main() {
    // Khai bao va nhap so luong sinh vien va ten cua tung sinh vien
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore(); // Xoa bo nho dem

    // Kiem tra so luong sinh vien co hop le khong
    if (n < 1 || n > 50) {
        cout << "So luong sinh vien khong hop le.\n";
        return 1; // Ket thuc chuong trinh voi ma loi
    }

    // Khai bao va nhap ten cua sinh vien
    vector<string> fullName(n);
    cout << "Nhap ten cua tung sinh vien:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Sinh vien " << i + 1 << ": ";
        getline(cin, fullName[i]);
    }

    // a) Tach ho tu mang fullName va luu vao mang firstName
    vector<string> firstName;
    extractFirstName(fullName, firstName);
    
    // b) Tach ten tu mang fullName va luu vao mang lastName
    vector<string> lastName;
    extractLastName(fullName, lastName);

    // c) Sap xep mang fullName theo thu tu tang dan cua phan ten sinh vien
    sort(fullName.begin(), fullName.end(), [](const string& a, const string& b) {
        // So sanh phan ten cua hai chuoi
        size_t posA = a.rfind(' ');
        size_t posB = b.rfind(' ');
        return a.substr(posA + 1) < b.substr(posB + 1);
    });

    // d) Tim nhung sinh vien co ho la "Nguyen"
    cout << "Nhung sinh vien co ho la 'Nguyen':\n";
    for (const string& name : fullName) {
        if (name.find("Nguyen") != string::npos) {
            cout << name << endl;
        }
    }

    // e) Tim nhung sinh vien ma phan ten co nhieu ky tu nhat
    string longestName;
    for (const string& name : fullName) {
        if (name.size() > longestName.size()) {
            longestName = name;
        }
    }
    cout << "Sinh vien co phan ten dai nhat: " << longestName << endl;

    return 0;
}

