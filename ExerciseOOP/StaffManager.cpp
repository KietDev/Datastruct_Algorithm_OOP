#include<iostream>
#include<string>
using namespace std;

class Staff {
    protected:
    string name, dayofbirth;
    int salary;
    public:
    Staff();
    virtual void Input();
    void Output();
    virtual void CalculateSalary() = 0;
    virtual bool TypeStaff() = 0;
    int GetSalary();
};
Staff::Staff() {
    salary = 0;
}
void Staff::Input() {
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter day of birth: ";
    getline(cin, dayofbirth);
}
void Staff::Output() {
    cout << name << "\t" << dayofbirth << "\t" << salary << endl;
}
int Staff::GetSalary() {
    return salary;
}
//------------------------------------------------------------------------------------------------------------//
class OfficeStaff:public Staff {
    private:
    int numberofworkingdays;
    public:
    OfficeStaff();
    void Input();
    void CalculateSalary();
    bool TypeStaff();
};
OfficeStaff::OfficeStaff() {
    numberofworkingdays = 0;
}
void OfficeStaff::Input() {
    Staff::Input();
    cout << "Enter number of working days: ";
    cin >> numberofworkingdays; cin.ignore();
}
void OfficeStaff::CalculateSalary() {
    salary = numberofworkingdays * 100000;
}
bool OfficeStaff::TypeStaff() {
    return true;
}
//--------------------------------------------------------------------------------------------------------------//
class ProductionStaff:public Staff {
    private:
    int basesalary, numberofproducts;
    public:
    ProductionStaff();
    void Input();
    void CalculateSalary();
    bool TypeStaff();
};
ProductionStaff::ProductionStaff() {
    basesalary = 0;
    numberofproducts = 0;
}
void ProductionStaff::Input() {
    Staff::Input();
    cout << "Enter base salary: ";
    cin >> basesalary; cin.ignore();
    cout << "Enter number of products: ";
    cin >> numberofproducts; cin.ignore();
}
void ProductionStaff::CalculateSalary() {
    salary = basesalary + numberofproducts * 5000;
}
bool ProductionStaff::TypeStaff() {
    return false;
}
//--------------------------------------------------------------------------------------------------------------------//
class ListStaff {
    private:
    int numbers;
    Staff **staff;
    public:
    ListStaff();
    ~ListStaff();
    void Input();
    void Output();
    void CalculateSalary();
    int SumSalary();
    void SalaryMax();
    void SalaryMin();
    void sortdecrease();
};
ListStaff::ListStaff() {
    cout << "Enter numbers of staff in company: ";
    cin >> numbers; cin.ignore();
    staff = new Staff*[numbers];
}
ListStaff::~ListStaff() {
    for(int i = 0; i < numbers; i++) {
        delete staff[i];
    }
    delete []staff;
}
void ListStaff::Input() {
    int option;
    for(int i = 0; i < numbers; i++) {
        cout << "Enter option(1: Office staff / 2: Production staff): ";
        cin >> option; cin.ignore();
        if(option == 1) {
            staff[i] = new OfficeStaff;
        } else {
            staff[i] = new ProductionStaff;
        }
        staff[i]->Input();
    }
}
void ListStaff::Output() {
    for(int i = 0; i < numbers; i++) {
        staff[i]->Output();
    }
}
void ListStaff::CalculateSalary() {
    for(int i = 0; i < numbers; i++) {
        staff[i]->CalculateSalary();
    }
}
int ListStaff::SumSalary() {
    int sum = 0;
    for(int i = 0; i < numbers; i++) {
        sum = sum + staff[i]->GetSalary();
    }
    return sum;
}
void ListStaff::SalaryMax() {
    int salarymax = staff[0]->GetSalary();
    Staff *max = staff[0];
    for(int i = 1; i < numbers; i++) {
        if(staff[i]->GetSalary() > salarymax) {
            salarymax = staff[i]->GetSalary();
            max = staff[i];
        }
    }
    max->Output();
}
void ListStaff::SalaryMin() {
    int salarymin = staff[0]->GetSalary();
    Staff *min = staff[0];
    for(int i = 1; i < numbers; i++) {
        if(staff[i]->GetSalary() < salarymin) {
            salarymin = staff[i]->GetSalary();
            min = staff[i];
        }
    }
    min->Output();
}
void ListStaff::sortdecrease() {
    Staff *swap = NULL;
    for(int i = 0; i < numbers; i++) {
        for(int j = i + 1; j < numbers; j++) {
            if(staff[i]->GetSalary() < staff[j]->GetSalary()) {
                swap = staff[i];
                staff[i] = staff[j];
                staff[j] = swap;
            }
        }
    }
}

int main() {
    ListStaff l;
    cout << "Input information staff of company: \n";
    l.Input();
    cout << "Calculate Salary for staff of company!\n";
    l.CalculateSalary();
    cout << "Output information staff of company\n";
    cout << "Name |\tDay of birth |\tSalary\n"; 
    l.Output();
    int sum = l.SumSalary();
    cout << "Salary company pay for staff: " << sum << endl;
    cout << "Infomation staff have slary max in company:\n";
    l.SalaryMax();
    cout << "Infomation staff have salary min in company:\n";
    l.SalaryMin();
    cout << "Sort list staff and output information\n";
    l.sortdecrease();
    cout << "Name |\tDay of birth |\tSalary\n"; 
    l.Output();
    return 0;
}