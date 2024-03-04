#include "CDocGiaTreEm.h"

CDocGiaTreEm::CDocGiaTreEm()
{

}

CDocGiaTreEm::~CDocGiaTreEm()
{

}

void CDocGiaTreEm::Input()
{
    CDocGia::Input(); // Phuong thuc chung
    cin.ignore();
    cout <<"\nNhap ho ten nguoi dai dien:";
    getline(cin,hotenNDD);

}

void CDocGiaTreEm::Output()
{
    CDocGia::Output();
    cout<<"\nHo ten nguoi dai dien"<<hotenNDD;

}
int CDocGiaTreEm::Tinh_Tien_Lam_The()
{
    return sothanghieuluc*5000;
}