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
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping::menu()
{
    m:
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
    cout<<"\n\t\t\t please select!";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login \n";
            cout<<"\t\t\t Please Email \n";
            cin>>email;
            cout<<"\t\t\t Password      \n";
            cin>>password;

            if(email == "ibrahimkhan360@gmail.com" && password == "ibrahim@123")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid email/password";
            }
            break;

        case 2:
            buyer();
            break;

        case 3:
            exit(0);

        default:
            cout<<"Please select from the given options";
            break;
    }

    goto m;
}
void shopping:: administrator()
{
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_____1) Add the project________|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_____2) Modify the project_____|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_____3) Delete the project_____|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_____3) Back to main menu______|";

    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default :
        cout<<"Invalid choice!";
    }
    goto m;

}

void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t  Buyer   \n";
    cout<<"\t\t\t____________________\n";
    cout<<"                             ";
    cout<<"\t\t\t  1) Buyer product     \n";
    cout<<"                             ";
    cout<<"\t\t\t  2) Go back           \n";
    cout<<"\t\t\t  Enter your choice :   \n";

    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default :
        cout<<"Invalid choice";
    }

    goto m;

}

void shopping ::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new project ";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the "
    cin>>pname;
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",iso::app|iso::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    }
    if(token==1)
    {
        goto m;
    }
    else{
        data.open("database.txt",iso::app|iso::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<dis<<"\n";
        data.close();
    }

cout<<"\n\n\t\t Record inserted !";
}

int main() {
    shopping shop;
    shop.menu();
    return 0;
}
