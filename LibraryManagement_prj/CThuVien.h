#pragma once
#include <iostream>
#include <string>
#include "CDocGiaTreEm.h"
#include "CDocGiaNguoiLon.h"
#include <vector>
using namespace std;
class CThuVien
{
private:
    vector<CDocGiaTreEm*> ds_docgiatreem;
    vector<CDocGiaNguoiLon*> ds_docgianguoilon;
public:
    void Input();           // Phuong thuc nhap thong tin
    void Output();          // Phuong thuc xuat thong tin
    int Tinh_Tien_Lam_The();
    CThuVien();
    ~CThuVien();
};