/*
(اللهم صلْ وسلم وزد وبارك على سيدنا محمد )

꧁IslaM_SobhY꧂

 */
#include <bits/stdc++.h>
using namespace std;
#define SUPERPOWER ios_base::sync_with_stdio(false); cout.tie(0);
#define  el "\12"
const int  Max_pateint = 5;
const int MAx_spec = 20;
struct Main_Info
{
    int pos;
    string Names[Max_pateint];
    bool Statues[Max_pateint];
    Main_Info()
    {
        pos = 0;
    }

    void Add_name_statues(string name,bool statues)
    {
       Names[pos] = name;
       Statues[pos] = statues;
        pos++;
    }
    void Print_Stat()
    {
        for(int i = 0; i < pos; i++)
        {
            cout << Names[i] << " " << (Statues[i] == 0 ? "Regular" : "Aurget") << el;
        }
    }
    const int Get_pos()
    {
        return pos;
    }
};
struct My_Hospital_queue
{
   Main_Info pateint_info[MAx_spec];
    void Add_End(const string& name, const bool stat,int spec)
    {
        spec--;
        pateint_info[spec].Add_name_statues(name,stat);
    }
    void Add_Front(const string& name, const bool& stat, int spec)
    {
        spec--;
        //Doing the right shift for the array
        int pos = pateint_info[spec].Get_pos();
        for(int i = pos-1; i >=0; i--)
        {
            pateint_info[spec].Names[i+1] =  pateint_info[spec].Names[i];
            pateint_info[spec].Statues[i+1] = pateint_info[spec].Statues[i];
        }
        pateint_info[spec].Names[0] = name;
        pateint_info[spec].Statues[0] = stat;
        pateint_info[spec].pos++;
    }
    const string Remove_Front(int spec) {
        spec--;
        if(pateint_info[spec].Get_pos() == 0)
        {
            return "";
        }
        string ret = pateint_info[spec].Names[0];
        //Doing the left shift for the array
         int pos = pateint_info[pos].Get_pos();
        for(int i = 1; i < pos; i++)
        {
             pateint_info[spec].Names[i-1] =  pateint_info[spec].Names[i];
            pateint_info[spec].Statues[i-1] = pateint_info[spec].Statues[i];
        }
         pateint_info[spec].pos--;
        return ret;
    }
    void print()
    {
        bool ok = 1;
        for(int i = 0; i < 20; i++)
        {

            if(pateint_info[i].Get_pos() != 0)
            {
                ok = 0;
                int num = pateint_info[i].Get_pos();
                cout << "In Specializatio Number : " << i+1 << " There Is : " <<
                num  << (num > 1 ? " Patients And They Are " : " Patient And He is ")<< el;
                pateint_info[i].Print_Stat();
            }

        }
        if(ok)
        {
            cout << "There Is No Patients At The Moment !" << el;
        }

    }
    int Get_Queue_pos(int spec)
    {
        spec--;
        return pateint_info[spec].Get_pos();
    }
};


struct Main_Hospital
{
    My_Hospital_queue Hospital;
    int PrintOptions()
{
    cout << "Enter your choice : " << el;
    cout << "1) Add new patients" << el;
    cout << "2) Print all patients" << el;
    cout << "3) Get Next patient " << el;
    cout << "4) Exit" << el;
     int choice;
     cin >> choice;
     return choice;
}
void GetUser_Choice()
{
    int spec;
    string name;
    bool stat;
    cout << "Enter specialization, name, status : ";
    cin >> spec >> name >> stat;
    if(Hospital.Get_Queue_pos(spec) >= 5)
    {
        cout << "Can't Accept any More Patients " << el;
        return;
    }
    if(stat == 0)
    {
        Hospital.Add_End(name,stat,spec);
    }else
    {
        Hospital.Add_Front(name,stat,spec);
    }
}
void Print_Pateints()
{
    Hospital.print();
}
void Get_Next()
{
    int spec;
    cout << "Enter Specialization : ";
    cin >> spec;
    string name = Hospital.Remove_Front(spec);
    if(name == "")
    {
        cout << "There is No Patients Now Have Rest Doc!" << el;
        return;
    }
    cout << name << " Please Go With Dr : ";
}
void Run()
{
    while(1)
    {
       int ret  = PrintOptions();
       if(ret == 1)
       {
           GetUser_Choice();
       }else if(ret == 2)
       {
           Print_Pateints();
       }else if(ret == 3)
       {
           Get_Next();
       }else
       {
           cout << "Bye!" << el;
           break;
       }
       cout << el << "------------------------------" << el;
    }


}
};
int main() {
     SUPERPOWER;
int t = 1;//cin >> t;
while(t--)
{
    //write the code here
    //int n;cin >> n;
Main_Hospital Hosbital_system;

Hosbital_system.Run();




}
  return 0;
}





