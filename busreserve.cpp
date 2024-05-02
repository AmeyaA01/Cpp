#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef struct{
	char name[50];
	int bus_num;
	int seat_num;
}pd;
void reservation(void);
void viewdetails(void);
void cancel(void);
void print ticket (char name[],int,int,float);
void specificbus(int);
float charge(int);
void login();
int main()
{
	cout<<"\t\t|                                               |\n";
	cout<<"\t\t|        -----------------------------          |\n";
	cout<<"\t\t|            BUS RESERVATION SYSTEM             |\n";
	cout<<"\t\t|        -----------------------------          |\n";
	cout<<"\t\t|                                               |\n";

	login();
	int menu_choice,choice_return;
	start:
	cout<<"\n1>> Reserve A Ticket";
	cout<<"\n------------------------";
	cout<<"\n2>> View All Buses";
	cout<<"\n------------------------";
	cout<<"\n3>> Cancel Reservation";
	cout<<"\n------------------------";
	cout<<"\n4>> Exit";
	cout<<"\n------------------------";
	cout<<"\n\n-->";
	cin>>menu_choice;
	switch(menu_choice)
	{
		case 1:
			reservation();
			break;
		case 2:
			viewdetails();
			break;
		case 3:
			cancel();
			break;
		case 4:
			return(0);
			break;
		default:
			cout<<"\nInvalid choice";
	}
	goto start;
	return(0);
}
void viewdetails(void)
{
	cout<<"------------------------------------------------------------------------------------------";
	cout<<"\nbs.No\tDrivers name    \tDestinations               \tCharges  \tTime\n";
	cout<<"------------------------------------------------------------------------------------------";
	cout<<"\n4738\tSagarDesai\tKasaba Bawada To Talsande\t\t120\t8.20Am";
	cout<<"\n4854\tShashikantChougule \tFulewadi To Talsande     \t\t130\t8am";
	cout<<"\n7506\tSachin Vade   \tarud sagaon  To Talsande \t\t130\t7:30am";
	cout<<"\n4855\tShivajiRanage \tKalamba To Talsande      \t\t150\t7:30am";
	cout<<"\n4850\tSandip Divtankarm \tIchalkaranji To  Talsande \t\t140\t7am";
	cout<<"\n4839\tRajat Patel        \tHupari To Talsande       \t\t140\t7:45am";
    cout<<"\n2376\tSunil Jakahale     \tWaliwade To Talsande     \t\t125\t7:50am";
    cout<<"\n4236\tDipak Chavan       \tSatave To Talsande       \t\t85 \t7:30am\n";
}
void reservation(void)
{
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	fstream seats_reserved;
	seats_reserved.open("seats_reserved",ios::out);
	cout<<"\nEnter Your Name:> ";
	fflush(stdin);
	gets(passdetails.name);
	cout<<"\nChoose seat Number:> ";
	cin>>passdetails.seat_num;
	cout<<"\n\n>>Press Enter To View Available Buses<< ";
	viewdetails();
	cout<<"\n\nEnter bus number:> ";
	start1:
	cin>>passdetails.bus_num;
	if(passdetails.bus_num>=0076 && passdetails.bus_num<=7506)
	{
		charges=charge(passdetails.bus_num);
		printticket(passdetails.name,passdetails.seat_num,passdetails.bus_num,charges);
	}
	else
	{
		cout<<"\nInvalid bus Number! Enter again--> ";
		goto start1;
	}
	cout<<"\n\nConfirm Ticket (y/n):>";
	start:
	cin>>confirm;
	if(confirm == 'y')
	{
		seats_reserved<<"---> Customer Information <---\n";
		seats_reserved<<"1. |Name: "<<passdetails.name<<"\t"<<"|Seat Number: "<<passdetails.seat_num
					<<"\t"<<"|Bus Number: "<<passdetails.bus_num<<"\t"<<"|Charges: "<<charges<<endl;
		cout<<"=======================";
		cout<<"\n\n Congratulation...... Your Reservation Done.......Happy Journey!\n\n";
		cout<<"=======================";
	}
	else
	{
		if(confirm=='n'){
			cout<<"\nReservation Not Done!";
		}
		else
		{
			cout<<"\nInvalid choice entered! Enter again-----> ";
			goto start;
		}
	}
	seats_reserved.close();

}
float charge(int bus_num)
{
	if (bus_num==4738)
	{
		return 120.0;
	}
	if (bus_num==4854)
	{
		return(130.0);
	}
	if (bus_num==7506)
	{
		return(130.0);
	}
	if (bus_num==4855)
	{
		return(150.0);
	}
	if (bus_num==4850)
	{
		return(140.0);
	}
	if (bus_num==4839)
	{
		return(140.0);
	}
	if (bus_num==2376)
	{
		return(125.0);
	}
	if (bus_num==4236)
	{
		return(85.0);
	}

}
void printticket(char name[],int seat_num,int bus_num,float charges)
{
	cout<<"-------------------\n";
	cout<<"\tTICKET\n";
	cout<<"-------------------\n\n";
	cout<<"Name          :\t"<<name;
	cout<<"\nSeat Number :\t"<<seat_num;
	cout<<"\nBus Number  :\t"<<bus_num;
	specificbus(bus_num);
	cout<<"\nCharges     :\t"<<charges;
}
void specificbus(int bus_num)
{

	if (bus_num==4738)
	{
		cout<<"\nDrivers Name:\tSagar desai";
		cout<<"\nDestination :\tKasaba Bawada To Talsande";
		cout<<"\nDeparture   :\t8:20am ";
	}
	if (bus_num==4854)
	{
		cout<<"\nDrivers Name:\tShashikant Chougule";
		cout<<"\nDestination :\tFulewadi TO Talsande";
		cout<<"\nDeparture   :\t8am";
	}
	if (bus_num==7506)
	{
		cout<<"\nDrivers Name:\tSachin vade";
		cout<<"\nDestination :\tSarud Sagaon To Talsande ";
		cout<<"\nDeparture   :\t7:30am";
	}
	if (bus_num==4855)
	{
		cout<<"\nDrivers Name:\tShivaji Ranage";
		cout<<"\nDestination :\tKalamba To Talsande";
		cout<<"\nDeparture   :\t7:30am ";
	}
	if (bus_num==4850)
	{
		cout<<"\nDrivers Name:\tSandip Divtankar";
		cout<<"\nDestination :\tIchalkaranji To Talsande";
		cout<<"\nDeparture   :\t7am";
	}
	if (bus_num==4839)
	{
		cout<<"\nDrivers Name:\tRajat Patel";
		cout<<"\nDestination :\tHupari To Talsande";
		cout<<"\nDeparture   :\t7:45am ";
	}
	if (bus_num==2376)
	{
		cout<<"\nDrivers Name:\tSunil Jakahale";
		cout<<"\nDestination :\twaliwade To Talsande";
		cout<<"\nDeparture   :\t7:50am ";
	}
	if (bus_num==4236)
	{
		cout<<"\nDrivers Name:\tDipak Chavan";
		cout<<"\nDestination :\tsatave TO Talsande";
		cout<<"\nDeparture   :\t7:30am ";
	}
}
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10];
    char pass[10];
    do
	{
    cout<<"\n  =======================  LOGIN FORM  =======================\n  ";
    cout<<" \n                       ENTER USERNAME:-";
	cin>>uname;
	cout<<" \n                       ENTER PASSWORD:-";
	cin>>pass;
	i=0;
	if(strcmp(uname,"admin")==0 && strcmp(pass,"admin123")==0)
	{
	cout<<"  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL";

	break;
	}
	else
	{
		cout<<"\n        SORRY !!!!  LOGIN IS UNSUCESSFUL";
		a++;
	
	}
}
	while(a<=3);
	if (a>3)
	{
		cout<<"\nSorry you have entered the wrong username and password !!!";
		
	}
}
void cancel(void)
{
	int busnum;
		cout<<"Enter the bus number: \n";
		cin>>busnum;
		cout<<"\n\nCancelled";
		
}
