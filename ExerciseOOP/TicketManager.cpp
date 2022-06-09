#include<iostream>
#include<string>
using namespace std;

class Ve {
    protected:
    string ma, hoten;
    int namsinh, sotrochoi;
    public:
    virtual void Nhap();
    virtual bool Loaive() = 0;
    virtual int Tienve() = 0;
};
void Ve::Nhap() {
    cout << "Nhap vao ma ve: ";
    getline(cin, ma);
    cout << "Nhap vao ho ten: ";
    getline(cin, hoten);
    cout << "Nhap vao nam sinh: ";
    cin >> namsinh; cin.ignore();
}
class Vetrongoi:public Ve {
    public:
    void Nhap();
    bool Loaive();
    int Tienve();
};
void Vetrongoi::Nhap() {
    Ve::Nhap();
    sotrochoi = 30;
    cout << "So tro choi duoc tham du la: " << sotrochoi << endl;
}
bool Vetrongoi::Loaive() {
    return true;
}
int Vetrongoi::Tienve() {
    return 300;
}
class Vetungphan:public Ve {
    public:
    void Nhap();
    bool Loaive();
    int Tienve();
};
void Vetungphan::Nhap() {
    Ve::Nhap();
    cout << "Nhap vao so tro  choi tham du: ";
    cin >> sotrochoi; cin.ignore();
}
bool Vetungphan::Loaive() {
    return false;
}
int Vetungphan::Tienve() {
    return 70 + sotrochoi * 20;
}

class Quanlive {
    private:
    int n;
    Ve **ve;
    public:
    void Nhap();
    int Tongtienve();
    int Sovetungphan();
};
void Quanlive::Nhap() {
    cout << "Nhap vao so luong ve: ";
    cin >> n; cin.ignore();
    ve = new Ve*[n];
    int option;
    for(int i = 0; i < n; i++) {
        cout << "Nhap vao lua chon loai ve( 1: ve tron goi (true); 2: ve tung phan (false)): ";
        cin >> option; cin.ignore();
        if(option == 1) {
            ve[i] = new Vetrongoi;
        } else {
            ve[i] = new Vetungphan;
        }
        ve[i]->Nhap();
    }
}
int Quanlive::Tongtienve() {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum = sum + ve[i]->Tienve();
    }
    return sum;
}
int Quanlive::Sovetungphan() {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(ve[i]->Loaive() == false) 
            count++;
    }
    return count;
}


int main() {
    Quanlive quanli;
    quanli.Nhap();
    cout << "Tong so tien ve cong vien thu duoc: " << quanli.Tongtienve() << endl;
    cout << "So ve loai tung phan la: " << quanli.Sovetungphan() << endl;
    return 0;
}