#pragma once // Tranh dung do thu vien

using namespace std;

class CDocGia
{
protected:
    string hoten;
    string ngaylapthe;  //dd/mm/yyyy
    int sothanghieuluc;
public:
    void Input();           // Phuong thuc nhap thong tin
    void Output();          // Phuong thuc xuat thong tin
    CDocGia();
    ~CDocGia();
};