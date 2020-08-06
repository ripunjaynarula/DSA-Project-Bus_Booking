#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<cstdio>
#include<time.h>
using namespace std;
class link
{
  private:


int b,x,i,choice,n,a;
char cont;
int pint;

struct node
{
 int data;
string fname;
string lname;
string email;
string home;
string occup;
string tell;
string cell;
double account;
string gender;
double balance;
struct node *link;
}*head,*temp,*temp1,*temp2;
struct node *p[100];
public:
link()
{

head=NULL;
}
void hashing()
{   system("cls");
    int aaac;
    struct node *cad;
    clock_t ct;
    cout << "\nEnter Account number: \n";
    cin >> aaac;
    if(aaac>i || aaac<2017101)
    { cout<<"Entered Account Number is not valid\nFor trying again, press Y else N\n";
      char hc;
      cin>>hc;
      if(hc=='y' || hc=='Y')
        hashing();
      else;
      main_menu();
    }
    else
    {
    ct=clock();
    aaac = aaac%2017100;
    cad = p[aaac];
    ct=clock()-ct;
    gotoxy(45,3); cout<<"Entry Found\n";
    gotoxy(45,4); cout<<" ____________\n";
cout<<"==========================================================================================================================";
cout<<"\n";
cout<<"\n# Account Number: "<<cad-> data;
cout<<"\n# Name: "<<cad-> fname<<"\t"<<cad->lname;
cout<<"\n# Occupation : "<<cad ->occup;
cout<<"\n# Citizenship Number : "<<cad ->account;
cout<<"\n# Gender : "<<cad ->gender;
cout<<"\n# Telephone Number : "<<cad-> tell;
cout<<"\n# Cell-Phone Number : "<<cad -> cell;
cout<<"\n# Email Address : "<<cad -> email;
cout<<"\n# Home  Address : "<<cad-> home;
cout<<"\n# Balance : "<<cad-> balance;
cout<<"\n";
cout<<"===========================================================================================================================";
    //cout << cad->fname << endl;
    cout<<"\n Time elapsed during the hash lookup is\t"<<(float)ct/CLOCKS_PER_SEC<<"   seconds";
    //cout << cad->
    }
}
void start()
{
system("color 4f");
Sleep(800);
//gotoxy(52,10);
cout<<"Welcome to the bank management System\n";
cout<<"This has been created by Faraz, Shivam and Arpan\n";
gotoxy(52,12);
Sleep(500);
cout<<"Loading....."<<endl;
gotoxy(52,14);
Sleep(500);
cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
cout<<"\xDB\xDB\xDB\xDB";
Sleep(500);
cout<<"\xDB\xDB\xDB\xDB\xDB\xDB";
cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
system("color 1f");
//effect();
main_menu();
}
void main_menu()
  {

  do
  {
    system("cls");
    cout<<"\n\t\t\t\t\t\t  MAIN MENU \n";
    cout<<"\t\t\t\t\t__________________________________\n\n";
    cout<<"\n\t\t\t\t\t\t1.Create user account \n";
    cout<<"\n\t\t\t\t\t\t2.Close account\n";
    cout<<"\n\t\t\t\t\t\t3.Delete All Records\n";
    cout<<"\n\t\t\t\t\t\t4.Search for account details\n";
    cout<<"\n\t\t\t\t\t\t5.Display All Records\n";
    cout<<"\n\t\t\t\t\t\t6.Transactions\n";
    cout<<"\n\t\t\t\t\t\t7.About Developer\n";
    cout<<"\n\t\t\t\t\t\t8.Exit\n";
    cout<<"\n\t\t\t\t\t\t9.Hashing\n";
    cout<<"\n\t\t\t\t\t\t||Enter your choice: ";
   choice=getche();
   switch(choice)
    {
     case '1':
     system("cls");
     insert();
     break;
     case '2':
     system("cls");
    del_specify();
     break;
     case '3':
     system("cls");
     del();
     break;
     case '4':
     system("cls");
     search();
     break;
     case '5':
     system("cls");
     print();
     break;
     case '6':
     system("cls");
     transaction();
     break;
     case '7':
     About_Dev();
     break;
     case '8':
     exit(0);
     break;
     case '9':
        hashing();
        break;
     default:
    cout<<"\nInvalid Key Pressed.................";
      }

    cout<<"\n\n*Press ENTER KEY To <continue>";
   cout<<"\n\n*Press ESC KEY To <exit>";

    x=getche();
    system("cls");
    if(x==27)
    {
    exit(0);
    }

    else
    {
        main_menu();
    }
    }while(x==13);

    }

void About_Dev()
{
effect();
system("cls");
cout<<"\n";
gotoxy(45,1);
cout<<"\xDB\xDB\xDB\xDB\xDB\xDB About Developer \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n";
gotoxy(45,3);cout<<"\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB All Rights Reserved \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n";
Sleep(1000);cout<<"\nCoder Name : Faraz, ";Sleep(1000);cout<<"Shivam ";Sleep(1000);cout<<"and Arpan\n";
cout<<"\nProject Development started on : 29th March 2017 in VIT University\n";
cout<<"\nLanguage :C++\n";
cout<<"\nTeam Member Details : \n1)Arpan Srivastava 16BCE2133 \n2)Faraz Ahmad 16BCE0920\n3)Shivam Bhagwani 16BCE0717";
Sleep(2000);
cout<<"\n\n\nThis project was developed under the able guidance of our esteemed professor, Dr.Shaik Naseera, VIT University Vellore \n\n ";Sleep(8000);

}
void insert(void)
{

         gotoxy(45,1);cout<<" Add Record \n";
         gotoxy(45,2);cout<<" ___________\n";
         cout<<"\n";
         if(head==NULL)
         {
         head =new struct node;
         i=2017101;
        cout<<"\n# Account Number:"<<i<<endl;
        head->data=i;
        p[i%2017100] = head;
        cout<<"\n# First Name :" ;
        cin>>head->fname;
        cout<<"\n# Last Name:";
        cin>>head-> lname;
        cout<<"\n# Occupation : ";
        cin>>head->occup;
        cout<<"\n# Citizenship Number : ";
        cin>>head->account;
        cout<<"\n# Gender : ";
        cin>>head->gender;
        cout<<"\n# Enter Telephone Number : ";
        cin>>head->tell;
        cout<<"\n# Enter Cell-Phone Number : ";
        cin>>head->cell;
        cout<<"\n# Enter Email Address : ";
        cin>>head->email;
        cout<<"\n# Enter Home  Address : ";
        cin>>head->home;
        cout<<"\n# Enter the first deposit amount :";
        cin>>head->balance;
        head->link=NULL;
        cout<<"\nYour Record Has been Success Fully inserted\n";
         }

        else
        {    temp=head;
             head=new struct node;
             i++;
         cout<<"\n# Account Number :"<<i<<endl;
         head->data=i;
         p[i%2017100] = head;
        cout<<"\n# First Name :" ;
        cin>>head->fname;
        cout<<"\n# Enter Last Name :";
        cin>>head-> lname;
        cout<<"\n# Occupation : ";
          cin>>head->occup;
          cout<<"\n# Citizenship Number : ";
          cin>>head->account;
          cout<<"\n# Gender : ";
        cin>>head->gender;
        cout<<"\n# Enter Telephone Number : ";
            cin>>head->tell;
        cout<<"\n# Enter Cell-Phone Number : ";
        cin>>head->cell;
        cout<<"\n# Enter Email Address : ";
        cin>>head->email;
        cout<<"\n# Enter Home  Address : ";
        cin>>head->home;
        cout<<"\n# Enter the first deposit amount :";
        cin>>head->balance;
        head->link=NULL;
        cout<<"\nYour Record Has been Success Fully inserted\n";
          head->link=temp;
             }
              cout<<"\nDo You Want To Add Another Record ? y / n  \a";
             cont=getche();
             if(cont=='y')
              {
              cout<<"\n";
              system("cls");
              insert();
              }
main_menu();


      }

void search(void)
{

effect();

system("cls");
  temp=head;
  system("cls");
   cout<<"\nEnter the account number which you want to search:";
   cin>>a;
clock_t cx;
cx=clock();
while(head!=NULL)
{

   if(head->data==a)
   {
   cout<<"\n\n";
gotoxy(45,3); cout<<"Entry Found\n";
gotoxy(45,4); cout<<" ____________\n";
cout<<"==========================================================================================================================";
cout<<"\n";
cout<<"\n# Account Number: "<<head-> data;
cout<<"\n# First Name: "<<head-> fname<<"\t"<<head->lname;
cout<<"\n# Occupation : "<<head ->occup;
cout<<"\n# Citizenship Number : "<<head ->account;
cout<<"\n# Gender : "<<head ->gender;
cout<<"\n# Telephone Number : "<<head-> tell;
cout<<"\n# Cell-Phone Number : "<<head -> cell;
cout<<"\n# Email Address : "<<head -> email;
cout<<"\n# Home  Address : "<<head-> home;
cout<<"\n# Balance : "<<head-> balance;
cout<<"\n";
cout<<"===========================================================================================================================";
cx=clock()-cx;
cout<<"\n Time elapsed during the linear search is\t"<<(float)cx/CLOCKS_PER_SEC<<"   seconds";
head=temp;

              return;
 }
 else

  {
 head=head->link;
 }
}
cout<<"Not found";
cx=clock()-cx;
cout<<"\n Time elapsed during the linear search is\t"<<(float)cx/CLOCKS_PER_SEC<<"   seconds";
head=temp;

}

void del(void)
{
   while(head!=NULL)
   {
       delete(head);
       head=head->link;

   }
   cout<<"\nYour all record has been deleted....";

}

void print(void)
{
  effect();

         temp1=head;
  if(temp1==NULL)
  {

 cout<<"No Entries Found.....";
 Sleep(1000);
  main_menu();

  }


  x:
  system("cls");
  gotoxy(45,1);cout<<"Display Record \n";
cout<<"=====================================================================================================================";
cout<<"\n";
cout<<"\n# Account Number: "<<temp1-> data<<endl;
cout<<"\n# Name: "<<temp1->fname<<"\t"<<temp1->lname<<endl;
cout<<"\n# Occupation : "<<temp1 -> occup<<endl;
cout<<"\n# Citizenship Number : "<<temp1 ->account<<endl;
cout<<"\n# Gender : "<<temp1->gender<<endl;
cout<<"\n# Telephone Number : "<<temp1-> tell<<endl;
cout<<"\n# Cell-Phone Number : "<<temp1 -> cell<<endl;
cout<<"\n# Email Address : "<<temp1 -> email<<endl;
cout<<"\n# Balance : "<<temp1->balance <<endl;
cout<<"\n";
cout<<"=======================================================================================================================";
   cout<<"\n";
  cout<<"\nDo You Want To View Another Record ? y / n  \a";
  cont=getche();

   if(cont=='y')
  {

  cout<<"\n";

   if(temp1->link==NULL)
  {
  cout<<"\nNo More Entries ........";
  Sleep(1000);
 main_menu();
   }
  temp1=temp1->link;

  goto x;

  }


  else if(temp1->link==NULL)
  {
  cout<<"\nNo More Entries ........";
  Sleep(1000);

  main_menu();

  }

  else
  {
       main_menu();
  exit(0);
  }


}

void del_specify(void)

{
   effect();
system ("cls");
cout<<"\n\t\t\t Delete A Record \n";
     cout<<"\n\t\t\t ________________\n";
cout<<"Enter Id which you want to del:";
cin>>n;

if(head->data==n)
              {

              free(head);


              head=head->link;
                   cout<<"\n";
   cout<<n<<" is successfully deleted in node";
                             }
        else
        {
      delete_node(n);
        }


}


void delete_node(int n)
{
  effect();

temp1 = head;
temp2 = head;

while (temp1 != NULL)
{
if (temp1->data == n)
{

break;
}

if (temp1 == temp2)
{
temp1 = temp1->link;
}
else
{

temp2 = temp2->link;
temp1= temp2->link;
}}

if (temp1 == NULL){
cout << "ID not found" << endl;

}
else
{

temp2 -> link = temp2 ->link->link;
delete temp1;
    cout<<"\n";
   cout<<n<<" is successfully deleted in node";

}
}
void gotoxy(int x, int y)
{
COORD ord;
ord.X = x;
ord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
}

void effect()
{   int i,j;
char ch;
ch=220;
gotoxy(0,0);
for (i=0;i<25;i++)
{
    for(j=0;j<125;j++)
    {
    cout<<ch;

    }
    Sleep(12);

    cout<<"\n";
    }
gotoxy(0,0);
for (i=0;i<27;i++)
{
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t            \n";
    Sleep(20);
}
}
void transaction()
{
        double cash;
        int c;
        system("cls");
        gotoxy(50,50);
        cout<<"\n\t\t\t\t\t\t  Welcome to the transactions \n";
        cout<<"\t\t\t\t\t__________________________________\n\n";
        cout<<"\n\t\t\t\t\t\tWhat would you like to do now? \n";
        cout<<"\n\t\t\t\t\t\t1.Deposit \n";
        cout<<"\n\t\t\t\t\t\t2.Withdraw\n";
        cout<<"\n\t\t\t\t\t\t3.Go back to main menu\n\n";
        cout<<"\n\t\t\t\t\t\t||Enter your choice: \n\n";
        cin>>c;
        while(1)
        switch(c)
        {
            case 1:
                    deposit();
                    break;
            case 2:
                    withdraw();
                    break;
            case 3: main_menu();
            default:
            cout<<"Wrong choice entered\n";
                   transaction();



        }
}
void deposit()
{
    int aco;
    double b;
    system("cls");
    double cash;
    cout<<"Enter your account number\n";
    temp=head;
    cin>>aco;
    while(head!=NULL)
    {

       if(head->data==aco)
       {   cout<<"Welcome "<<head->fname<<"\n";
           cout<<"\nExisting balance : "<<head->balance;
           cout<<"\nEnter the amount you would like to deposit\n";
           cin>>cash;
           b=head->balance;
           b=b+cash;
           head->balance=b;
           cout<"The cash has been deposited\nThank you for banking with us\n";
           cout<<"Updated Balance: "<<head->balance<<"\n";
           head=temp;
           Sleep(2000);
           transaction();
       }
       else
       {
           head=head->link;
       }
    }
    cout<<"Wrong account number entered";
    Sleep(2000);
    transaction();
}
void withdraw()
{
    int aco;
    double b;
    double cash;
    system("cls");
    cout<<"Enter your account number\n";
    temp=head;
    cin>>aco;
    while(head!=NULL)
    {

       if(head->data==aco)
       {  cout<<"Welcome "<<head->fname<<"\n";
          cout<<"\nExisting balance : "<<head->balance;
          cout<<"\nEnter the amount you would like to withdraw\n";
          cin>>cash;
           b=head->balance;
           if(cash>b)
           {cout<<"Not enough amount to be withdrawn\n\n ";
           cout<<"Press y to continue and n to exit\n";
           char x;
           cin>>x;
            if(x=='y')
            {
                head=temp;
            main_menu();
            }
            else if(x=='n')
            {
                head=temp;
                exit(0);
            }
           }
           else
           {

           b=b-cash;
           head->balance=b;
           cout<"The cash has been Withdrawn\nThank you for banking with us\n";
           cout<<"Updated Balance: "<<head->balance<<"\n";
           Sleep(2000);
           head =temp;
           transaction();
           }
       }
       else
       {
           head=head->link;
       }
    }
    cout<<"Wrong account number entered\n";
    Sleep(2000);
    transaction();
    return;
}
};

int main()
{
char pass[10],password[10]="vitrocks";
int choice;
int i=0;
system("color 4f");
printf("\n\n\t\tEnter the password to login:");
scanf("%s",pass);
if (strcmp(pass,password)==0)
    {printf("\n\nPassword Match!\nLOADING");
    for(i=0;i<=6;i++)
    {
        //fordelay(100000000);
        printf(".");
    }
            system("cls");
       link obj;
       obj.start();
        getch();
    }
else
    {   printf("\n\nWrong password!!\a\a\a");
        login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d",&choice);
        if (choice==1)
                {

                    system("cls");
                    main();
                }

        else if (choice==0)
                {
                system("cls");

                }
        else
                {printf("\nInvalid!");
                system("cls");
                }

    }
    return 0;
}

