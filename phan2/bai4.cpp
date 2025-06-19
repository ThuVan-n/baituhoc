#include<iostream>
#include<cmath>
using namespace std;

void nhap(int a[][10], int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout << "Nhap phan tu a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
	cout << endl;
}

void xuat(int a[][10], int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int tongNgoaiDuongCheoChinh(int a[][10], int n){
	int tong =0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i!=j){
				tong += a[i][j];
			}
		}
	}
	return tong;
}

int maxDuongCheoChinh(int a[][10], int n){
	int max = a[0][0];
    for (int i = 0; i < n; i++) {
        if (a[i][i] > max) {
            max = a[i][i];
        }
    }
    return max;
}

int soAmTrenDuongCheoPhu(int a[][10], int n){
	int am=0;
	int j = n-1;
	for(int i=0;i<n;++i){
		if(a[i][j] < 0){
			am++;
		}
		j--;
	}
	return am;
}
	
int KTnguyenTo(int n) {
	for(int i=2;i<=sqrt(n);++i){
		if(n%i==0) return 0;
	}
	return n>1;
}

int soLuongSoNTo(int a[][10], int n){
	int nto=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(KTnguyenTo(a[i][j]))
				nto++;
		}
	}
	return nto;
}

void xuatHien(int a[][10], int n){
	int c[100] = {0}, d[100] = {0}, max=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(a[i][j] < 0){
				d[abs (a[i][j])]++;
			}
			else c[a[i][j]]++;
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(c[a[i][j]] > max && a[i][j] > 0){
				max = c[a[i][j]];
			}
			if(d[abs(a[i][j])] > max){
				max = d[abs(a[i][j])];
			}
		}
	} 
	cout << "So xuat hien nhieu nhat trong mang la: ";
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(c[a[i][j]] == max){
				cout << a[i][j] << " ";	
				c[a[i][j]] = 0;
			}
			if(d[abs(a[i][j])] == max){
				cout << "So " << a[i][j] << ", ";
				d[abs(a[i][j])] = 0;
			}
		}
	}
	cout << endl;
}

void dongNhieuSoChan(int a[][10], int n){
	int max=0, c[10];
	for(int i=0;i<n;++i){
		int chan=0;
		for(int j=0;j<n;++j){
			if(a[i][j] % 2 ==0){
				chan++;
			}
		}
		c[i] = chan;
		if(chan > max){
			max = chan;
		}
	}
	cout << "Dong co nhieu so chan nhat la: \n";
	for(int i=0;i<n;++i){
		if(c[i] == max){
			cout << "Dong " << i+1 << "\n";
		}
	}
	cout << endl;
}

void dongNhieuSoNTo(int a[][10], int n){
	int max=0, c[10];
	for(int i=0;i<n;++i){
		int nto=0;
		for(int j=0;j<n;++j){
			if(KTnguyenTo(a[i][j])){
				nto++;
			}
		}
		c[i] = nto;
		if(nto > max){
			max = nto;
		}
	}
	cout << "Dong co nhieu so nguyen to nhat la: \n";
	for(int i=0;i<n;++i){
		if(c[i] == max){
			cout << "Dong " << i+1 << "\n";
		}
	}
	cout << endl;
}



int main(){
	int n;
	cout << "Nhap so luong phan tu cua mang (0:10] : ";
	cin >> n;
	while(n <=0 || n > 10){
		cout << "Nhap lai so luong phan tu cua mang: ";
		cin >> n;
	}
	int a[10][10];
	nhap(a,n);
	cout << "Mang da nhap la: \n";
	xuat(a,n);
	cout << "Tong cac phan tu nam ngoai duong cheo chinh la: ";
	cout << tongNgoaiDuongCheoChinh(a,n) << endl;
	cout << "Gia tri lon nhat tren duong cheo chinh la: ";
	cout << maxDuongCheoChinh(a,n) << endl;	
	cout << "So luong phan tu am nam tren duong cheo phu: ";
	cout << soAmTrenDuongCheoPhu(a,n) << endl;
	cout << "So luong so nguyen to co trong mang la: " << soLuongSoNTo(a,n) << endl;
	xuatHien(a,n);
	dongNhieuSoChan(a,n);
	dongNhieuSoNTo(a,n);
	
}



