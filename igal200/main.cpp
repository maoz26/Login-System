#include <iostream>
#include <stdio.h>
#include "header_register.h"
#include "header_login.h"
#include "header_admin.h"

using namespace std;

void main()		//main menu
{
	char option = 'x';
	int boolean = 1;
	cout<<("|****************************************************|\n");
	cout<<("| Final project in c - version 1.0		     |\n");
	cout<<("|  By Maoz Tamir(301833232) & Nir Jackson (302634084)|\n");
	cout<<("|****************************************************|\n\n");
	while (boolean == 1)
	{
		cout<<"Please choose one of the following options "<<endl<<"('r'-register, 'l'-login, 'a'-admin, 'q'-quit)"<<endl;
		cin >> option;
		switch (option)
		{
		case 'r': 
			printf("Registeration begin\n");
			boolean = sign_up();
			break;	//register
		case 'l':
			boolean=LoginFunc();
			break;	//login
		case 'a':
			boolean=LoginAdmin();
			break;	//admin
		case 'q': printf("goodbye\n");
			boolean=0;
			break;	//quit
		}
	}
}