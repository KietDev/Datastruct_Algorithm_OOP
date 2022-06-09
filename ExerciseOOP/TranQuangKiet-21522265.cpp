#include<iostream>
#include<string>
using namespace std;



class Khoahoc {
    protected:
    int solanthilailithuyet, solanthilaithuchanh;
    public:
    int getthilaithuchanh();
    virtual void Nhap();
    virtual int hocphi() = 0;
    virtual int loai() = 0;
    virtual int tienthuchanh() = 0;
};
int Khoahoc::getthilaithuchanh() {
    return solanthilaithuchanh;
}
void Khoahoc::Nhap() {
    cout << "so lan thi lai li thuyet: ";
    cin >> solanthilailithuyet; cin.ignore();
    cout << "So lan thi lai thuc hanh: ";
    cin >> solanthilaithuchanh; cin.ignore();
}

class Khoahoccanban:public Khoahoc {
    public:
    int hocphi();
    int loai();
    int tienthuchanh();
};
int Khoahoccanban::tienthuchanh() {
    return solanthilaithuchanh * 400000;
}
int Khoahoccanban::hocphi() {
    return 4500000;
}
int Khoahoccanban::loai() {
    return 1;
}
class Khoahocnangcao:public Khoahoc {
    private:
    int sogiohoc1kem1;
    public:
    void Nhap();
    int hocphi();
    int loai();
    int tienthuchanh();
};
void Khoahocnangcao::Nhap() {
    Khoahoc::Nhap();
    cout << "So gio hoc thuc hanh 1 kem 1: ";
    cin >> sogiohoc1kem1; cin.ignore();
}
int Khoahocnangcao::tienthuchanh() {
    return solanthilaithuchanh * 400000 + sogiohoc1kem1 * 200000;
}
int Khoahocnangcao::hocphi() {
    return 7500000;
}
int Khoahocnangcao::loai() {
    return 2;
}
class Khoahocvip:public Khoahoc {
    public:
    void Nhap();
    int hocphi();
    int loai();
    int tienthuchanh();
};
void Khoahocvip::Nhap() {
    return;
}
int Khoahocvip::tienthuchanh() {
    return 0;
}
int Khoahocvip::hocphi() {
    return 18000000;
}
int Khoahocvip::loai() {
    return 3;
}
class Hocvien {
    private:
    string hoten, ngaysinh, cmnd;
    float chieucao, cannang;
    Khoahoc *khoahoc;
    public:
    void Nhap();
    friend class Dsquanli;
};
void Hocvien::Nhap() {
    int k;
    cout << "Nhap vao ho ten: ";
    getline(cin, hoten);
    cout << "Nhap vao ngay thang nam sinh: ";
    getline(cin, ngaysinh);
    cout << "Nhap vao so chung minh nhan dan: ";
    getline(cin, cmnd);
    cout << "Nhap vao chieu cao: ";
    cin >> chieucao; cin.ignore();
    cout << "Nhap vao can nang: ";
    cin >> cannang; cin.ignore();
    cout << "Nhap vao khoa hoc: ";
    cin >> k; cin.ignore();
    if(k == 1) {
        khoahoc = new Khoahoccanban;
    } else if(k == 2) {
        khoahoc = new Khoahocnangcao;
    } else {
        khoahoc = new Khoahocvip;
    }
    khoahoc->Nhap();
}

class Dsquanli {
    private:
    int n;
    Hocvien *hocvien;
    public:
    void Nhap();
    int Tongtienthuchanh();
    float Phantramnangcaokothilaithuchanh();
    int trungbinh();
};
void Dsquanli::Nhap() {
    cout << "Nhap vao so hoc vien: ";
    cin >> n; cin.ignore();
    hocvien = new Hocvien[n];
    for(int i = 0; i < n; i++) {
        hocvien[i].Nhap();
    }
}
int Dsquanli::Tongtienthuchanh() {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = sum + hocvien[i].khoahoc->tienthuchanh();
    }
    return sum;
}
float Dsquanli::Phantramnangcaokothilaithuchanh() {
    int count = 0, count2 = 0;
    for(int i = 0; i < n; i++) {
        if(hocvien[i].khoahoc->loai() == 2) count2++;
        if(hocvien[i].khoahoc->loai() == 2 && hocvien[i].khoahoc->getthilaithuchanh() == 0) {
            count++;
        }
        
    }
    float phantram = (count * 100) / count2;
    return phantram;
}
int Dsquanli::trungbinh() {
    int count = 0, count2 = 0;
    for(int i = 0; i < n; i++) {
        if(hocvien[i].khoahoc->loai() == 2) count2++;
        if(hocvien[i].khoahoc->loai() == 2 && hocvien[i].khoahoc->getthilaithuchanh() == 0) {
            count++;
        }
    }
    return (count2 - count) / count2;
}


int main() {
    Dsquanli ds;
    ds.Nhap();
    cout << "Tong so tien thuc hanh ma trung tam thu duoc: " << ds.Tongtienthuchanh() << endl;
    cout << "Phan tram ve nang cao khong can thi lai thuc hanh: " << ds.Phantramnangcaokothilaithuchanh() << endl;
    cout << "Trung binh moi ve nang cao can thi lai so lan la: " << ds.trungbinh();
    return 0;
}