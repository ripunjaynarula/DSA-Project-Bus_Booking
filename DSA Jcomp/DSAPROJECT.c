#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
char i = ':';
char chEmpty[] = "Empty";
struct time
{
	int iHrs, iMins;
};
static int Num = 0;
struct node
{
	int bus_no;
	int iBusNum;
	int iBusCode;
	char chSeat[8][4][20];
	char chDrivers_Name[20];
	struct time stDeparture_Time, stArrival_Time;
	char chGoesTo[20];
	char chGoesFrom[20];
	float fFare;
	int iTicketSold;
	struct node *next;
} * p;
//Searching a Bus its bus number
void colour()
{
	system("color 70");
	system("color 0e");
	char a = 177, b = 219;
	int i;
	system("color 70");
	printf("\n\n\n\t\t\tLOADING........");
	printf("\n\n\n");
	printf("\t\t\t\t\t");
	for (i = 0; i <= 25; i++)
		printf("%c", a);
	Sleep(150);
	printf("\r");
	printf("\t\t\t\t\t ");
	for (i = 0; i <= 25; i++)
	{
		printf("%c", b);
		Sleep(200);
	}
	system("cls");
}

void srch(int num)
{
	struct node *r;
	r = p;
	if (num == 1)
	{
		printf("\nBus code -> %d\tDriver's name -> %s", r->bus_no, r->chDrivers_Name);
		printf("\nArrival time -> %d%c%d\tDeparture time -> %d%c%d", r->stArrival_Time.iHrs, i, r->stArrival_Time.iMins, r->stDeparture_Time.iHrs, i, r->stDeparture_Time.iMins);
		printf("\nFrom -> %s \t To -> %s", r->chGoesFrom, r->chGoesTo);
		printf("\nFare -> %f \t Tickets sold -> %d", r->fFare, r->iTicketSold);
		int i1, i2, index = 0;
		for (i1 = 0; i1 < 8; i1++)
		{
			printf("\n");
			for (i2 = 0; i2 < 4; i2++)
			{
				index++;
				printf("%d. %s\t ", index, r->chSeat[i1][i2]);
			}
		}
	}
	else if (num <= cunt(p))
	{
		int i;
		for (i = 1; i < num; i++)
		{
			r = r->next;
		}
		printf("\nBus code -> %d\tDriver's name -> %s", r->bus_no, r->chDrivers_Name);
		printf("\nArrival time -> %d%c%d\tDeparture time -> %d%c%d", r->stArrival_Time.iHrs, i, r->stArrival_Time.iMins, r->stDeparture_Time.iHrs, i, r->stDeparture_Time.iMins);
		printf("\nFrom -> %s \t To -> %s", r->chGoesFrom, r->chGoesTo);
		printf("\nFare -> %f \t Tickets sold -> %d", r->fFare, r->iTicketSold);
		int i1, i2, index = 0;
		for (i1 = 0; i1 < 8; i1++)
		{
			printf("\n");
			for (i2 = 0; i2 < 4; i2++)
			{
				index++;
				printf("%d. %s\t ", index, r->chSeat[i1][i2]);
			}
		}
	}
	else
	{
		printf("\n Wrong Bus number input (Remember, not Bus code, BusNUMBER!)\n");
	}
}
//counting total number of buses
int cunt(struct node *q)
{
	struct node *temp;
	temp = q;
	int tot = 0;
	while (temp != NULL)
	{
		tot++;
		temp = temp->next;
	}
	return (tot);
}
//deleting a bus entry by its Bus code by its value
void Delete(int num)
{
	struct node *temp, *r;
	r = p;
	while (r != NULL)
	{
		if (r->bus_no == num)
		{
			if (r == p)
			{
				p = r->next;
				free(r);
				return;
			}
			else
			{
				temp->next = r->next;
				free(r);
				return;
			}
		}
		else
		{
			temp = r;
			r = r->next;
		}
	}
	printf("No such Bus code found.\n");
}
void insert(int x)
{
	struct node *temp, *m;
	m = p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->bus_no = x;
	Num++;
	temp->iBusNum = Num;
dname:
	printf("Enter driver's name : ");
	fflush(stdin);
	gets(temp->chDrivers_Name);
	if (strlen(temp->chDrivers_Name) > 20)
	{
		printf("Maximum 20 characters are allowed");
		goto dname;
	}
aTime:
	printf("Enter arrival time : ");
	fflush(stdin);
	scanf("%d%c%d", &temp->stArrival_Time.iHrs, &i, &temp->stArrival_Time.iMins);
	if (temp->stArrival_Time.iHrs == 0)
	{
		printf("\nInvalid time.");
		goto aTime;
	}
	if ((i != ':') || (temp->stArrival_Time.iHrs >= 24) || (temp->stArrival_Time.iHrs < 0) || (temp->stArrival_Time.iMins >= 60) || (temp->stArrival_Time.iMins < 0))
	{
		printf("\nInvalid time !\n\t\tOnly format HH:MM accepted\n");
		goto aTime;
	}
dTime:
	printf("Enter departure time : ");
	fflush(stdin);
	scanf("%d%c%d", &temp->stDeparture_Time.iHrs, &i, &temp->stDeparture_Time.iMins);
	if (temp->stDeparture_Time.iHrs == 0)
	{
		printf("\nInvalid time.");
		goto dTime;
	}
	if ((i != ':') || (temp->stDeparture_Time.iHrs >= 24) || (temp->stDeparture_Time.iHrs < 0) || (temp->stDeparture_Time.iMins >= 60) || (temp->stDeparture_Time.iMins < 0))
	{
		printf("\nInvalid time !\n\t\tOnly format HH:MM accepted\n");
		goto dTime;
	}
to:
	printf("Enter destination : ");
	fflush(stdin);
	gets(temp->chGoesTo);
	if (strlen(temp->chGoesTo) > 20)
	{
		printf("\nOnly 20 characters or less");
		goto to;
	}
from:
	printf("Enter starting place : ");
	fflush(stdin);
	gets(temp->chGoesFrom);
	if (strlen(temp->chGoesFrom) > 20)
	{
		printf("\nOnly 20 characters or less");
		goto from;
	}
	printf("Enter fare of one ticket : ");
	fflush(stdin);
	scanf("%f", &temp->fFare);
	temp->iTicketSold = 0;
	int i1, i2;
	for (i1 = 0; i1 < 8; i1++)
	{
		for (i2 = 0; i2 < 4; i2++)
		{
			strcpy(temp->chSeat[i1][i2], chEmpty);
		}
	}
	if (p == NULL)
	{
		p = temp;
		p->next = NULL;
	}
	else
	{
		while (m->next != NULL)
			m = m->next;
		m->next = temp;
		m = temp;
		m->next = NULL;
	}
}
void Print(struct node *q)
{
	struct node *r;
	r = q;
	int cnt = 1;
	while (r != NULL)
	{
		line();
		printf("\n\nBus code -> %d\tBus number -> %d \tDriver's name -> %s", r->bus_no, cnt, r->chDrivers_Name);
		printf("\nArrival time -> %d%c%d\tDeparture time -> %d%c%d", r->stArrival_Time.iHrs, i, r->stArrival_Time.iMins, r->stDeparture_Time.iHrs, i, r->stDeparture_Time.iMins);
		printf("\nFrom -> %s \t To -> %s", r->chGoesFrom, r->chGoesTo);
		printf("\nFare -> %f \t Tickets sold -> %d", r->fFare, r->iTicketSold);
		cnt++;
		int i1, i2, index = 0;
		for (i1 = 0; i1 < 8; i1++)
		{
			printf("\n");
			for (i2 = 0; i2 < 4; i2++)
			{
				index++;
				printf("%d. %s\t ", index, r->chSeat[i1][i2]);
			}
		}
		r = r->next;
	}
	printf("\n");
}
void reservation(struct node *q)
{
	struct node *r;
	r = q;
	int num, count = 0, Seat;
res:
	printf("Enter bus number : ");
	fflush(stdin);
	scanf("%d", &num);
	if (num > cunt(q) || (num < 1))
	{
		printf("Sorry, no bus found with the given Bus number.\n");
		goto res;
	}
	while (count < num - 1)
	{
		r = r->next;
		count++;
	}
seat:
	printf("Enter seat number : ");
	fflush(stdin);
	scanf("%d", &Seat);
	char Name[20];
	if (Seat > 32)
	{
		printf("Only 32 seats are there.\n");
		goto seat;
	}
	else if (Seat < 1)
	{
		printf("Invalid input.\n");
		goto seat;
	}
	else if (strcmp(r->chSeat[Seat / 4][Seat % 4 - 1], "Empty") == 0)
	{
		printf("Enter the passenger's name : ");
	name:
		fflush(stdin);
		gets(Name);
		if (strlen(Name) > 20)
		{
			printf("Max 20 characters allowed\n");
			goto name;
		}
		strcpy(r->chSeat[Seat / 4][Seat % 4 - 1], Name);
		printf("\nSeat successfully reserved!\nDo you want to continue reservation ? : ");
		r->iTicketSold++;
		char ch;
		ch = getchar();
		if (ch == 'y' || ch == 'Y')
		{
			reservation(q);
		}
		else
			main();
	}
	else
	{
		printf("Seat already booked!\n");
		goto seat;
	}
}
void cancel()
{
	if (Num == 0)
	{
		printf("Bus list is empty.\n");
		main();
	}
	struct node *r;
	r = p;
enter:
	printf("Enter Bus number : ");
	int bus, ind = 1;
	fflush(stdin);
	scanf("%d", &bus);
	if (bus < 1 || bus > cunt(p))
	{
		printf("\nInvalid input.\n");
		goto enter;
	}
	else
	{
		while (ind < bus)
		{
			r = r->next;
			ind++;
		}
	}
	printf("Enter seat number : ");
	int sea;
	scanf("%d", &sea);
	if (strcmp(r->chSeat[sea / 4][sea % 4 - 1], "Empty") == 0)
	{
		printf("The seat is already empty !\n");
		goto enter;
	}
	else
	{
		strcpy(r->chSeat[sea / 4][sea % 4 - 1], "Empty");
		printf("Successfully canceled reservation.\n");
		r->iTicketSold--;
		main();
	}
}
void daily_profit()
{
	struct node *r, *s;
	r = p;
	s = p;
	int cnt = 0;
	if (cunt(p) == 0)
	{
		printf("No buses are available\n");
		main();
	}
	while (s != NULL)
	{
		if (s->iTicketSold != 0)
		{
			cnt++;
		}
		s = s->next;
	}
	if (cnt == 0)
	{
		printf("No booking is done yet.\n");
		getch();
		main();
	}
	float Total = 0;
	while (r != NULL)
	{
		Total = Total + (r->iTicketSold * r->fFare);
		r = r->next;
	}
	printf("The total income of the buses is : %.2f\n", Total);
	main();
}
void line()
{
	int i;
	printf("\n");
	for (i = 0; i < 60; i++)
	{
		printf("*");
	}
	printf("\n");
}
//The main function
int main()
{
	int A, fux = 0,flag=0;
	while (1)

	{
		line();
		if(flag==0)
		{
			colour();
			flag=1;
		}

		printf("\n0.EXIT\n1.INSERTING NEW BUS.");
		printf("\n2.REMOVING BUS AND ALL ITS COMPONENTS FROM LIST BY BUS code");
		printf("\n3.PRINTING DETAILS OF ALL BUSES");
		printf("\n4.TOTAL NUMBER OF BUSES\n5.SEARCHING BUS BY ITS BUS NUMBER");
		printf("\n6.Reservation of seats\n7.Cancel a reservation\n8.Daily profit.");
		printf("\n\nEnter your choice here : ");
		scanf("%d", &A);
		switch (A)
		{
		case 1:
		{
			int x, n, i;
			line();
			printf("Enter bus code : ");
			scanf("%d", &x);
			insert(x);
			break;
		}
		case 2:
		{
			line();
			printf("\n Enter Bus code : ");
			int num;
			scanf("%d", &num);
			Delete(num);
			Print(p);
		}
		case 3:
		{
			line();
			Print(p);
			break;
		}
		case 4:
		{
			line();
			printf("Total number of Buses are %d\n", cunt(p));
			break;
		}
		case 5:
		{
			int num;
			line();
			printf("Enter Bus number : ");
			scanf("%d", &num);
			if (num > cunt(p) || num < 1)
			{
				printf("Invalid number !! \n");
				main();
			}
			srch(num);
			break;
		}
		case 6:
		{
			line();
			reservation(p);
			break;
		}
		case 7:
		{
			line();
			cancel();
			break;
		}
		case 8:
		{
			line();
			daily_profit();
			break;
		}
		case 0:
		{
			line();
			exit(1);
			break;
		}
		default:
		{
			printf("\n\nWrong choice...");
			break;
		}

	}
	}
	return 0;
}
