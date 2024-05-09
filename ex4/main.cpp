#include <iostream>

using namespace std;

class Engine{
    private:
    int m_EngineCapacity;
    int m_Horsepower;
    bool m_EngineRunning;
    public:
    Engine(int EngineCapacity = 2000, int Horsepower = 200){
        m_EngineCapacity = EngineCapacity;
        m_Horsepower = Horsepower;
        m_EngineRunning = false;
    }
    bool EngineStart(){
        if(!m_EngineRunning){
            m_EngineRunning = true;
        }
        return true;
    };
    bool EngineStop(){
        if(!m_EngineRunning){
            m_EngineRunning = false;
        }
        return true;
    };
    bool get_EngineStatus(){
        return m_EngineRunning;
    };
};

class Fueltank{
    private:
        int m_FueltankCapacity;
        int m_Gas_grade;
    public:
        Fueltank(int FueltankCapacity = 3000, int Gas = 98){
            m_FueltankCapacity = FueltankCapacity;
            m_Gas_grade = Gas;
        }
        int fuel_up(int v, int gas){
            if(m_FueltankCapacity < v){
                cout << "Error: FueltankCapacity: " << m_FueltankCapacity << " but fuel up: " << v << endl;
            }
            if(m_Gas_grade != gas){
                cout << "Error: Gas_grade: " << gas << " Correct Gas_grade: " << m_Gas_grade << endl;
            }
            if(m_FueltankCapacity >= v && m_Gas_grade == gas){
                cout << "fuel_up: " << v << " Gas_grade: " << gas << endl;
            }
            return 0;
        };
        int set_Gas_grade(int Gas_grade){
            m_Gas_grade = Gas_grade;
            cout << "Set Gas_grade: " << m_Gas_grade << endl;
            return 0;
        }
        int get_Gas_grade(){
            return m_Gas_grade;
        };
};

class Car{
    private:
        Engine m_Engine;
        Fueltank m_Fueltank;
        int m_MaxSeating;
        int m_price;
        int m_base;
        string m_brand;
        string m_model;
        int m_year;
        void m_UpdatePrice(int base = 500000){
            m_price = m_MaxSeating * base;
        }
    public:
    Car(string x, string y, int z, int s){
        m_brand = x;
        m_model = y;
        m_year = z;
        m_MaxSeating = s;
        m_UpdatePrice();
    }
    int get_NaxSeating(){
        return m_MaxSeating;
    }
    int get_price(){
        return m_price;
    }
    void set_base(int n){
        m_base = n;
    }
    string get_brand(){
        return m_brand;
    }
    bool get_EngineStatus(){
        return m_Engine.get_EngineStatus();
    }
    bool startEngine(){
        return m_Engine.EngineStart();
    }
    bool stopEngine(){
        return m_Engine.EngineStop();
    }
    int get_Gas_grade(){
        return m_Fueltank.get_Gas_grade();
    }
    int set_Gas_grade(int gas){
        return m_Fueltank.set_Gas_grade(gas);
    }
    int fuel_up(int v, int gas){
        return m_Fueltank.fuel_up(v, gas);
    }
};

class AUDI_Car : public Car{
    private:
    public:
    AUDI_Car(string y, int z, int s) : Car("AUDI", y, z, s){
        cout << "Constructing AUDI_Car\n";
    }
};

int main(){
    AUDI_Car car_2("A1", 2021, 2);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.set_Gas_grade(95);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.fuel_up(300, 95);
}
