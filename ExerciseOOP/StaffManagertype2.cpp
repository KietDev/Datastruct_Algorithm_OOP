#include<iostream>
#include<string>
using namespace std;

class Nhanvien {
    protected:
    string ma, hoten, sdt, email;
    int luongcoban;
    public:
    virtual void Nhap();
    virtual void Xuat();
    virtual int Tinhluong() = 0;
};
void Nhanvien::Nhap() {
    cout << "Nhap vao ma nhan vien: ";
    getline(cin, ma);
    cout << "Nhap vao ho ten nhan vien: ";
    getline(cin, hoten);
    cout << "Nhap vao so dien thoai nhan vien: ";
    getline(cin , sdt);
    cout << "Nhap vao email nhan vien: ";
    getline(cin , email);
    cout << "Nhap vao luong co ban cua nhan vien: ";
    cin >> luongcoban; cin.ignore();
}
void Nhanvien::Xuat() {
    cout << ma << "\t" << hoten << "\t" << sdt << "\t" << email << "\t" << luongcoban << "\t";
}

class Laptrinhvien:public Nhanvien {
    private:
    int overtime;
    public:
    void Nhap();
    void Xuat();
    int Tinhluong();
};
void Laptrinhvien::Nhap() {
    Nhanvien::Nhap();
    cout << "Nhap vao so gio lam them: ";
    cin >> overtime; cin.ignore();
}
void Laptrinhvien::Xuat() {
    Nhanvien::Xuat();
    cout << overtime << endl;
}
int Laptrinhvien::Tinhluong() {
    return luongcoban + overtime * 200000;
}

class Kiemchungvien:public Nhanvien {
    private:
    int soloiphathienduoc;
    public:
    void Nhap();
    void Xuat();
    int Tinhluong();
};
void Kiemchungvien::Nhap() {
    Nhanvien::Nhap();
    cout << "Nhap vao so loi da phat hien duoc: ";
    cin >> soloiphathienduoc; cin.ignore();
}
void Kiemchungvien::Xuat() {
    Nhanvien::Xuat();
    cout << soloiphathienduoc << endl;
}
int Kiemchungvien::Tinhluong() {
    return luongcoban + soloiphathienduoc * 50000;
}

class Quanlinhanvien {
    private:
    int n;
    Nhanvien **nhanvien;
    public:
    Quanlinhanvien();
    ~Quanlinhanvien();
    void Nhap();
    void Xuat();
    float Luongtrungbinh();
    void Dsnhanvien(float average);
};
Quanlinhanvien::Quanlinhanvien() {
    cout << "Nhap vao so nhan vien cua cong ty: ";
    cin >> n; cin.ignore();
    nhanvien = new Nhanvien*[n];
}
Quanlinhanvien::~Quanlinhanvien() {
    for(int i = 0; i < n; i++) {
        delete nhanvien[i];
    }
    delete []nhanvien;
}
void Quanlinhanvien::Nhap() {
    int option;
    for(int i = 0; i < n; i++) {
        cout << "Nhap vao lua chon nhan vien( 1: lap trinh vien; 2: kiem chung vien): ";
        cin >> option; cin.ignore();
        if(option == 1) {
            nhanvien[i] = new Laptrinhvien;
        } else {
            nhanvien[i] = new Kiemchungvien;
        }
        nhanvien[i]->Nhap();
    }
}
float Quanlinhanvien::Luongtrungbinh() {
    float average;
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum = sum + nhanvien[i]->Tinhluong();
    }
    average = sum / n;
    return average;
}
void Quanlinhanvien::Dsnhanvien(float average) {
    cout << "Thong tin nhung nhan vien co muc luong thap hon muc luong trung binh: \n";
    for(int i = 0; i < n; i++) {
        if(float(nhanvien[i]->Tinhluong()) < average)
            nhanvien[i]->Xuat();
    } 
}

int main() {
    Quanlinhanvien quanli;
    quanli.Nhap();
    float average;
    average = quanli.Luongtrungbinh();
    quanli.Dsnhanvien(average);
    return 0;
}