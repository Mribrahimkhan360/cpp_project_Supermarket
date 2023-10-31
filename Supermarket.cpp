#include<iostream>
#include<fstream>

using namespace std;
class shopping
{
private:
    int pcode;
    float dis;
    string pname;

    public:
        void menu();
        void administrator();
        void buer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};
void shopping :: menu()
{
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t___________________________________________\n";
    cout<<"\t\t\t\t                                           \n";
    cout<<"\t\t\t\t           Hupermarket Main Menu           \n";
    cout<<"\t\t\t\t                                           \n";
    cout<<"\t\t\t\t___________________________________________\n";
    cout<<"\t\t\t\t|    1) Administrator         |\n";
    cout<<"\t\t\t\t|                             |\n";
    cout<<"\t\t\t\t|    2) Buyer                 |\n";
    cout<<"\t\t\t\t|                             |\n";
    cout<<"\t\t\t\t|    3) Exit                  |\n";
}
