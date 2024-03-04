#pragma once
#include <iostream>
#include <string>
#include "CDocGia.h"
using namespace std;
class CDocGiaNguoiLon:public CDocGia
{
private:
    string CMND;
public:
    void Input();           // Phuong thuc nhap thong tin
    void Output();          // Phuong thuc xuat thong tin
    int Tinh_Tien_Lam_The();
    CDocGiaNguoiLon();
    ~CDocGiaNguoiLon();
};