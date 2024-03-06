#include <iostream>
#include <string>
#include <vector>
using namespace std;
class CDocGia
{
protected:
    string hoten;
    string ngaylapthe;  //dd/mm/yyyy
    int sothanghieuluc;
public:
    virtual void Input();           // Phuong thuc nhap thong tin
    virtual void Output();          // Phuong thuc xuat thong tin
    virtual int Tinh_Tien_Lam_The() = 0; 
    CDocGia();
    ~CDocGia();
};
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
class CDocGiaTreEm:public CDocGia
{
private:
    string hotenNDD;
public:
    void Input();           // Phuong thuc nhap thong tin
    void Output();          // Phuong thuc xuat thong tin
    int Tinh_Tien_Lam_The();
    CDocGiaTreEm();
    ~CDocGiaTreEm();
};
class CThuVien
{
private:
    vector<CDocGia*> ds_docgia; // Khai bao mang 1 chieu chua lop cha - vi do co virtual cho nen no se da hinh sang duoc tung lop con tuong ung
public:
    void Input();           // Phuong thuc nhap thong tin
    void Output();          // Phuong thuc xuat thong tin
    int Tinh_Tien_Lam_The();
    CThuVien();
    ~CThuVien();
};
void pausesys(void)
{
    cin.ignore();
     do {
     cout << '\n' << "Press the Enter key to continue.";
   } while (cin.get() != '\n');

}
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
    cout<<"\nSo CMND: "<<CMND;

}
int CDocGiaNguoiLon::Tinh_Tien_Lam_The()
{
    return sothanghieuluc*10000;
}
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
    cout<<"\nHo ten nguoi dai dien: "<<hotenNDD;

}
int CDocGiaTreEm::Tinh_Tien_Lam_The()
{
    return sothanghieuluc*5000;
}

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
        cout << "\n\n\t\t0. Thoat";
        cout << "\n\n\t\t=================== END =====================";

        cout << "\n\n\t\tNhap Lua Chon: ";
        cin >> luachon;
        CDocGia *x;
        if(luachon == 1)
        {
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA\n";
            x= new CDocGiaTreEm; 
            x -> Input();
            ds_docgia.push_back(x);

        }
        else if(luachon == 2)
        {
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA\n";
            x = new CDocGiaNguoiLon; 
            x -> Input();
            ds_docgia.push_back(x);

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
    for(int i=0; i< ds_docgia.size(); i++)
    {
        cout << "\n\n\t\t THONG TIN DOC GIA THU "<<i+1;
        ds_docgia[i]->Output();
        
    }
    pausesys();



}
int CThuVien::Tinh_Tien_Lam_The()
{
    int sum = 0;
    for(int i=0; i< ds_docgia.size(); i++)
    {
        sum += ds_docgia[i] ->Tinh_Tien_Lam_The();
        
    }

    return sum;
}
int main()
{
    CThuVien *x = new CThuVien;
    x ->Input();
    x ->Output();
    cout << "\n\n\t\t TONG TIEN LAM THE: "<<x->Tinh_Tien_Lam_The()<< endl;
    
    delete x;

    pausesys();
    return 0;
}