#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	struct sinhvien //Khai b�o c?u tr�c sinhvien
	{ 
		char ten[33];
		int tuoi;
		char que_quan[33];
	}*p;
	sinhvien a={"Ly Minh Tai", 22, "Hai Duong"};
	cout<<a.tuoi<<endl; // Xu?t ra 22
	p=new sinhvien;
	strcpy(p->ten, a.ten); Copy th�nh ph?n ten t? c?u tr�c a sang p
	cout<<p->ten; // Xu?t ra Ly Minh Tai	
}
