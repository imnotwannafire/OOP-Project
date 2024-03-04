#include "CThuVien.h"

CThuVien::CThuVien()
{

}

CThuVien::~CThuVien()
{

}

void CThuVien::Input()
{
    int luachon;
    while(true)
    {
        cout << "\n\n\t\t================THU VIEN ====================";
        cout << "\n\n\t\t1. Doc Gia Tre Em";
        cout << "\n\n\t\t2. Doc Gia Nguoi Lon";
        cout << "\n\n\t\t=================== END =====================";

        cout << "\n\n\t\tNhap Lua Chon";
        cin >> luachon;
        if(luachon == 1)
        {
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA\n";
            CDocGiaTreEm *x = new CDocGiaTreEm; 
            x -> Input();
            ds_docgiatreem.push_back(x);

        }
        else if(luachon == 2)
        {
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA\n";
            CDocGiaNguoiLon *x = new CDocGiaNguoiLon; 
            x -> Input();
            ds_docgianguoilon.push_back(x);

        }
        else if (luachon == 0)
        {
            break;
        }
        else{
            cout <<"\n Lua chon khong hop le. Xin chon lai";
            pausesys();
        }
    }

}

void CThuVien::Output()
{
    for(int i=0; i< ds_docgiatreem.size(); i++)
    {
        cout << "\n\n\t\t ============ THONG TIN DOC GIA TRE EM ===============";
        ds_docgiatreem[i]->Output();
        pausesys();
    }

    for(int i=0; i< ds_docgianguoilon.size(); i++)
    {
        cout << "\n\n\t\t ============ THONG TIN DOC GIA NGUOI LON ===============";
        ds_docgianguoilon[i]->Output();
        pausesys();
    }

}
int CThuVien::Tinh_Tien_Lam_The()
{
    int sum = 0;
    for(int i=0; i< ds_docgiatreem.size(); i++)
    {
        sum += ds_docgiatreem[i] ->Tinh_Tien_Lam_The();
        
    }

    for(int i=0; i< ds_docgianguoilon.size(); i++)
    {
        sum += ds_docgianguoilon[i] ->Tinh_Tien_Lam_The();
        
    }
    return sum;
}
void pausesys(void)
{
    cin.ignore();
     do {
     cout << '\n' << "Press the Enter key to continue.";
   } while (cin.get() != '\n');

}