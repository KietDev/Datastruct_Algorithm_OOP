#include<iostream>
#include<time.h>
#include<string>
using namespace std;

class Cattle {
    protected:
    int amount;
    public:
    Cattle();
    void Input();
    void Output();
    virtual string Chirp() = 0;
    virtual int giveMilk() = 0;
    virtual int type() = 0;
    int birth();
    int getamount();
};
Cattle::Cattle() {
    amount = 0;
}
void Cattle::Input() {
    cout << "Enter number of cattles: ";
    cin >> amount;
}
void Cattle::Output() {
    cout << amount << "\t";
}
int Cattle::birth() {
    srand(time(0));
    int sum = 0;
    for(int i = 0; i < amount; i++) {
    int r = 0 + rand() % (50 + 1 - 0);
    sum = sum + r;
    }
    return sum;
}
int  Cattle::getamount() {
    return amount;
}

class Cow:public Cattle {
    public:
    string Chirp();
    int giveMilk();
    int type();
};
string Cow::Chirp() {
    return "I'm cow";
}
int Cow::giveMilk() {
    srand(time(0));
    int milk = 0;
    for(int i = 0; i < amount; i++) {
    int r = 0 + rand() % (20 + 1 -0);
    milk = milk + r;
    }
    return milk;
}
int Cow::type() {
    return 1;
}

class Sheep:public Cattle {
    public:
    string Chirp();
    int giveMilk();
    int type();
};
string Sheep::Chirp() {
    return "I'm sheep";
}
int Sheep::giveMilk() {
    srand(time(0));
    int milk = 0;
    for(int i = 0; i < amount; i++) {
    int r = 0 + rand() % (5 + 1 - 0);
    milk = milk + r;
    }
    return milk;
}
int Sheep::type() {
    return 2;
}

class Goat:public Cattle {
    public:
    string Chirp();
    int giveMilk();
    int type();
};
string Goat::Chirp() {
    return "I'm goat";
}
int Goat::giveMilk() {
    srand(time(0));
    int milk = 0;
    for(int i = 0; i < amount; i++) {
    int r = 0 + rand() % (10 + 1 - 0);
    milk = milk +r;
    }
    return milk;
}
int Goat::type() {
    return 3;
}

class Farm {
    private:
    Cattle **cattle;
    public:
    Farm();
    void Input();
    void Output();
    int sumMilk();
    int sumCattle();
};
Farm::Farm() {
    cattle = new Cattle*[3];
}
void Farm::Input() {
    int option;
    for(int i = 0; i < 3; i++) {
        cout << "Enter option(1: cow, 2: sheep, 3: goat): ";
        cin >> option;
        if(option == 1) {
            cattle[i] = new Cow;
        } else if(option == 2) {
            cattle[i] = new Sheep;
        } else {
            cattle[i] = new Goat;
        }
        cattle[i]->Input();
    }
}
void Farm::Output() {
    cout << "Type |\tAmount |\tChirp |" << endl;
    for(int i = 0; i < 3; i ++) {
        cout << cattle[i]->type() << "\t";
        cattle[i]->Output();
        cout << cattle[i]->Chirp() << "\t" << endl;
    }
}
int Farm::sumMilk() {
    int sum = 0;
    for(int i = 0; i < 3; i ++) {
        sum = sum + cattle[i]->giveMilk();
    }
    return sum;
}
int Farm::sumCattle() {
    int sum = 0;
    for(int i = 0; i < 3; i ++) {
        sum = sum + cattle[i]->birth() + cattle[i]->getamount();
    }
    return sum;
}

int main() {
    Farm f;
    cout << "Enter information: \n";
    f.Input();
    f.Output();
    cout << "Sum cattle is: " << f.sumCattle() << endl;
    cout << "Sum lit milk is: " << f.sumMilk() << endl; 
    return 0;
}