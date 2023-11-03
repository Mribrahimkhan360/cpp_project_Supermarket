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
{   m:
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
    int c,price;
    int token=0;
    float p;
    float d;
    string n,pname;

    cout<<"\n\n\t\t\t Add new project ";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the ";
    cin>>pname;
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        std::ofstream data("database.txt", std::ios::app | std::ios::out);
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
    else
    {
        std::ofstream data("database.txt", std::ios::app | std::ios::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<dis<<"\n";
        data.close();
    }

    cout<<"\n\n\t\t Record inserted !";
}

void shopping ::edit()
{
    fstream data,data1;
    int pkey;
    int token =0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the recoard";
    cout<<"\n\t\t\t Project code :";
    cin>>pkey;

    data.open("database.text",ios::in);
    if(!idea)
    {
        cout<<"\n\nFile doesn't exist!";
    }
    else
    {
        data1.open("database.txt",ios::app | ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Prodcut new code : ";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<p<<" "<<"\n";
                     cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<dis<<"\n";
            }
            data>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0)
        {
            cout<<"\n\n Record not found sorry!";
        }
    }

}

void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token =0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);

    if(!idea)
    {
        cout<<"File doesn't exist";
    }

    else
    {
        data1.open("database.txt",iso::app | iso::out);
        data>>pcode>>pname>>price>>dis;
        while(pcode==pkey)
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data1.close();
        data1.close();

        remove("Database.txt");
        remove("Database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found";
        }

    }
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n____________________________________________________\n";
    cout<<"ProNo \t\tName\t\tPrice \n";
    cout<<"\n\n____________________________________________________\n";
    data>>pcode>.pname>>price>>dis;

    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}


void shopping receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;



    cout<<"\n\n\t\t\t\t ReCEIPT ";
    data.open("database.txt",ios::in);
    if(!idea)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();

        list();
        cout<<"\n________________________________________\n";
        cout<<"\n                                        \n";
        cout<<"\n           Please please the order      \n";
        cout<<"\n                                        \n";
        cout<<"\n________________________________________\n";
        do
        {
            m:
            cout<<"\n \n Enter Product code :";
            cin>>arrc[c];
            cout<<arrq[c];
            for(int i=0; i<c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n DUplicate product code. Pleae try again!";
                    goto m;
                }
                c++;
                cout<<"\n\n\t\t\t___________RECEIPT____________\n";
                cout<<"\ Prpduct No\t Product Name\t Product Quantity\tprice\tAmount with discount\n";
                for(int i=0;i<c;i++)
                {
                    data.open("database.txt",ios::in);
                    data>>pcode>>pname>>price>>dis;
                    while(!data.eof())
                    {
                        if(pcode==arrc[i])
                        {
                            amount=price*arrq[i];
                            dis=amount-(amount*dis/100);
                            total=total+dis;
                            count<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                        }
                        data>>pcode>>pname>>price>>dis;
                    }
                }
                data.close();
            }
        }
    }
    cout<<"\n\n________________________________________________";
    cout<<"\n Total Amount : "<<total;
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}
