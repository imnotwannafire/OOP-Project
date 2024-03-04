#include "CDocGia.h"

CDocGia::CDocGia()
{

}

CDocGia::~CDocGia()
{

}

void CDocGia::Input()
{
    cin.ignore();
    cout << "\nNhap ho va ten doc gia: ";
    getline(cin, hoten);
    cin.ignore();
    cout << "\nNhap ngay lap the: ";
    getline(cin, ngaylapthe);
    cout << "\nNhap so thang hieu luc: ";
    cin >> sothanghieuluc;

}

void CDocGia::Output()
{
    cout << "\nHo va ten doc gia: "<<hoten;
    cout << "\nNgay lap the: "<<ngaylapthe;
    cout << "\nSo thang hieu luc: "<<sothanghieuluc;

}