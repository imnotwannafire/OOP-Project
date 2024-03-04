#include <iostream>
using namespace std;
#include <string>
// CLASS PARENT - BASE CLASS
class Employee
{
protected:
    string name;
    int age;
    string gender;
    string addr;
    string phone_number;
    float height;
    float weight;

public:
    void Set();
    void Get();
    
    Employee();
    ~Employee();
};
void Employee::Set()
{
    cin.ignore();
    cout <<"Name: ";
    getline(cin, name);
    cout <<"Age: ";
    cin >> age;
    cin.ignore();
    cout <<"Gender: ";
    getline(cin, gender);
    cout <<"Address: ";
    getline(cin, addr);
    cout <<"Phone number: ";
    getline(cin, phone_number);
    cout <<"Height: ";
    cin >> height;
    cout <<"Weight: ";
    cin >> weight;
}

void Employee::Get()
{
    cout <<"\nName: " << name;
    cout <<"\nAge: " << age;
    cout <<"\nGender: " << gender;
    cout <<"\nAddress: " << addr;
    cout <<"\nPhone Number: " << phone_number;
    cout <<"\nHeight: " << height;
    cout <<"\nWeight: " << weight;
}

Employee::Employee()
{

}
Employee::~Employee()
{
    
}
// CHILDREN CLASS
class Plumber:public Employee
{
private:
    
    float work_time;
public:
    void Set();
    void Get();
    float Cal_salary();
    Plumber();
    ~Plumber();

};
Plumber::Plumber()
{

}
Plumber::~Plumber()
{
    
}
void Plumber::Set()
{
    Employee::Set(); // Call parent method
    cout <<"Work Time: ";
    cin >> work_time;


}

void Plumber::Get()
{
    Employee::Get();    // Call parent method
    cout <<"\nWork Time: " << work_time;
}

float Plumber::Cal_salary()
{
    float sal;
    sal = work_time * 5000;
    return sal;

}
class Delivery:public Employee
{
private:
    int deli_pack;
public:
    void Set();
    void Get();
    float Cal_salary();
    Delivery();
    ~Delivery();

};
Delivery::Delivery()
{

}
Delivery::~Delivery()
{
    
}
void Delivery::Set()
{
    Employee::Set();
    cout <<"\nDelivery Packet: ";
    cin >> deli_pack;

}

void Delivery::Get()
{
    Employee::Get();
    cout << "\nDelivered Package: "<<deli_pack;
}

float Delivery::Cal_salary()
{
    float sal;
    sal = deli_pack * 10000;
    return sal;

}
class Driver:public Employee
{
private:

    float distance;
public:
    void Set();
    void Get();
    float Cal_salary();
    Driver();
    ~Driver();

};
Driver::Driver()
{

}
Driver::~Driver()
{
    
}
void Driver::Set()
{
    Employee::Set();
    cout <<"\nDistance: ";
    cin >> distance;


}

void Driver::Get()
{
    Employee::Get();
    cout <<"\nDrive Distance: " << distance;
}
float Driver::Cal_salary()
{
    float sal;
    sal = distance * 15000;
    return sal;

}
void pausesys(void)
{
    cin.ignore();
     do {
     cout << '\n' << "Press the Enter key to continue.";
   } while (cin.get() != '\n');

}
double PlumberSalarySum(Plumber *emp_plumbers[], int m)
{
    double sum = 0;
    for(int i = 0;i<m;i++)
    {
        sum += emp_plumbers[i]->Cal_salary();
    }
    return sum;
}

double DeliverySalarySum(Delivery *emp_deliverer[], int n)
{
    double sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum += emp_deliverer[i]->Cal_salary();
    }
    return sum;
}

double DriverSalarySum(Driver *emp_drivers[], int t)
{
    double sum = 0; 
    for(int i = 0;i<t;i++)
    {
        sum += emp_drivers[i]->Cal_salary();
    }
    return sum;
}

// Swap objects function
void swap_plumbers(Plumber *plumber1, Plumber *plumber2)
{
    Plumber *temp = new Plumber;
    temp = plumber2;
    plumber2 = plumber1;
    plumber1 = temp;
    delete temp;
}
void swap_deliverers(Delivery *deli1, Delivery *deli2)
{
    Delivery *temp = new Delivery;
    temp = deli2;
    deli2 = deli1;
    deli1 = temp;
    delete temp;
}
void swap_drivers(Driver *driver1, Driver *driver2)
{
    Driver *temp = new Driver;
    temp = driver2;
    driver2 = driver1;
    driver1 = temp;
    delete temp;
}
// Sort List by salary
void sort_plumber(Plumber *plumbers[],int n)
{
    for(int i = 0; i< n-1; i++)
    {
        for(int j = i+1; j<n;j++)
        {
            if(plumbers[i]->Cal_salary()<plumbers[j]->Cal_salary())
            {
                swap_plumbers(plumbers[i], plumbers[j]);
            }
        }
    }
}
void sort_deliverer(Delivery *deliverers[],int n)
{
    for(int i = 0; i< n-1; i++)
    {
        for(int j = i+1; j<n;j++)
        {
            if(deliverers[i]->Cal_salary()<deliverers[j]->Cal_salary())
            {
                swap_deliverers(deliverers[i], deliverers[j]);
            }
        }
    }
}
void sort_driver(Driver *drivers[],int n)
{
    for(int i = 0; i< n-1; i++)
    {
        for(int j = i+1; j<n;j++)
        {
            if(drivers[i]->Cal_salary()<drivers[j]->Cal_salary())
            {
                swap_drivers(drivers[i], drivers[j]);
            }
        }
    }
}
// Menu application
void Menu(Plumber *emp_plumbers[], Delivery *emp_deliverers[], Driver *emp_drivers[], int m, int n, int t)
{
    int choice = 0;
    while(true)
    {
        system("clear");
        cout << "\t\n================EMPLOYEE MANAGERMENT APPLICATION================";
        cout << "\t\n1. INPUT PLUMBER EMPLOYEE INFORMATION";
        cout << "\t\n2. INPUT DELIVERY EMPLOYEE INFORMATION";
        cout << "\t\n3. INPUT DRIVER EMPLOYEE INFORMATION";
        cout << "\t\n4. OUTPUT PLUMBER EMPLOYEE INFORMATION";
        cout << "\t\n5. OUTPUT DELIVERY EMPLOYEE INFORMATION";
        cout << "\t\n6. OUTPUT DRIVER EMPLOYEE INFORMATION";
        cout << "\t\n7. OUTPUT TOTAL SALARY PER MONTH";
        cout << "\t\n8. SORT LIST OF EMPLOYEE BY SALARY";
        cout << "\t\n===========================END========================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        if(choice < 1|| choice >8)
        {
            cout << "\n INVALID CHOICE. PLEASE TRY AGAIN\n";
        }
        else if(choice == 1)
        {
            Plumber *emp_plumber = new Plumber;   
            cout << "\t\nINPUT PLUMBER EMPLOYEE INFORMATION\n";
            emp_plumber->Set();
            emp_plumbers[n] = emp_plumber;
            n++;
        }
        else if(choice == 2)
        {
            Delivery *emp_deliverer = new Delivery;   // Allocate object memory
            cout << "\t\nINPUT DELIVERY EMPLOYEE INFORMATION\n";
            emp_deliverer->Set();
            emp_deliverers[m] = emp_deliverer;
            m++;
        }
        else if(choice == 3)
        {
            Driver *emp_driver = new Driver;   
            cout << "\t\nINPUT DELIVERY EMPLOYEE INFORMATION\n";
            emp_driver->Set();
            // Add Pointer object to Arrry of pointer
            emp_drivers[t] = emp_driver;
            t++;
        }
        else if(choice == 4)
        {   
            cout << "\t\nOUPUT PLUMBER EMPLOYEE INFORMATION\n";
            for (int i = 0; i< n; i++)
            {
                cout << "\t\n PLUMBER NUMBER"<<i+1<<endl;
            emp_plumbers[i]->Get();
            }
            cout <<"\n\n\t\t TOTAL SALARY FOR PLUMBERS: "<<(size_t)PlumberSalarySum(emp_plumbers,n)<<endl;
            pausesys();
            
        }
        else if(choice == 5)
        {
            cout << "\t\nOUPUT DELIVERY EMPLOYEE INFORMATION\n";
            for (int i = 0; i< m; i++)
            {
                cout << "\t\n DELIVERY NUMBER"<<i+1<<endl;
                emp_deliverers[i]->Get();
            }
            cout <<"\n\n\t\t TOTAL SALARY FOR DELIVERERS: "<<(size_t)DeliverySalarySum(emp_deliverers,m)<<endl;
            pausesys();
        }
        else if(choice == 6)
        {
            cout << "\t\nOUPUT DELIVERY EMPLOYEE INFORMATION\n";
            for (int i = 0; i< t; i++)
            {
                cout << "\t\n DRIVER NUMBER"<<i+1<<endl;
                emp_drivers[i]->Get();
            }
            cout <<"\n\n\t\t TOTAL SALARY FOR DRIVERS: "<<(size_t)DriverSalarySum(emp_drivers,t)<<endl;
            pausesys();
        }
        else if(choice == 7)
        {
            cout << "\t\nOUPUT TOTAL SALARY PER MONTH: "<<(size_t)DriverSalarySum(emp_drivers,t)+(size_t)DeliverySalarySum(emp_deliverers,m)+(size_t)PlumberSalarySum(emp_plumbers,n)<<endl;
            
            
            pausesys();
        }
        else if(choice == 8)
        {
            cout<<"\n\tSORT LIST OF PLUMBER BY SALARY\n";
            sort_plumber(emp_plumbers,n);
            for (int i = 0; i< n; i++)
            {
                cout << "\t\n PLUMBER NUMBER"<<i+1<<endl;
                emp_plumbers[i]->Get();
            }
            cout<<"\n\tSORT LIST OF DELIVERER BY SALARY\n";
            sort_deliverer(emp_deliverers,m);
            for (int i = 0; i< m; i++)
            {
                cout << "\t\n DELIVERS NUMBER"<<i+1<<endl;
                emp_deliverers[i]->Set();
            }
            cout<<"\n\tSORT LIST OF DRIVER BY SALARY\n";
            sort_driver(emp_drivers,t);
            for (int i = 0; i< t; i++)
            {
                cout << "\t\n PLUMBER NUMBER"<<i+1<<endl;
                emp_drivers[i]->Get();
            }
            
            pausesys();
        }
        else if(choice == 0){
            cout << "\n\tEXIT.\n";
            break;
        }

    }
    // Delete pointer object for 3 lists
    for (int i = 0; i< n; i++)
    {
        delete emp_plumbers[i];
    }
    for (int i = 0; i< m; i++)
    {
        delete emp_deliverers[i];
    } 

    for (int i = 0; i< t; i++)
    {
        delete emp_drivers[i];
    } 


}


int main()
{
    // Pointer Object - declare list of 100 pointers

    Plumber *emp_plumbers[100];      //Mang 1 chieu pointer nhan vien sua ong nuoc
    Delivery *emp_deliverers[100];   //Mang 1 chieu pointer nhan vien giao hang
    Driver *emp_drivers[100];        //Mang 1 chieu pointer nhan vien lai xe
    int m = 0;
    int n = 0;
    int t = 0;
    Menu(emp_plumbers, emp_deliverers, emp_drivers, m,n,t);
    system("pause");
    return 0;

}
