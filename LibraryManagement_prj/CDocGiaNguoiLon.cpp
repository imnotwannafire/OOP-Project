#include "CDocGiaNguoiLon.h"

CDocGiaNguoiLon::CDocGiaNguoiLon()
{

}

CDocGiaNguoiLon::~CDocGiaNguoiLon()
{

}

void CDocGiaNguoiLon::Input()
{
    CDocGia::Input(); // Phuong thuc chung
    cin.ignore();
    cout <<"\nNhap so CMND:";
    getline(cin,CMND);

}

void CDocGiaNguoiLon::Output()
{
    CDocGia::Output();
    cout<<"\nSo CMND"<<CMND;

}
int CDocGiaNguoiLon::Tinh_Tien_Lam_The()
{
    return sothanghieuluc*10000;
}