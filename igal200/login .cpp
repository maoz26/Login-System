#include <iostream>
#include "header_login.h"
#include "header_system1.h"

using namespace std;


int LoginFunc()	//login function
{
	list();
	long int id;
	char pass[10];
	cout<<"User ID: ";
	cin>>id;
	cout<<"Password: ";
	cin>>pass;
	int result= Checkexist(id,pass);
	int counter=0;
	while (result==0)
	{
		cout<<"please try again (user and password!)"<<endl;
		cin>>id>>pass;
		result= Checkexist(id,pass);
		counter++;
		if (counter==3)
		{
			cout<<"3 failed attempts, would you like to recover you password?"<<endl<<"[1] via email, [2] via security question";
			int num;
			cin>>num;
			if (num==1){ 
				cout<<"enter valid id:"<<endl;
				cin>>id;
				SendEmailFunc(id); 
			}
			else if (num==2){
				cout<<"enter valid id:"<<endl;
				cin>>id;
				SecQuestion(id);
			}
			else cout<<"well fuck you too, i'm closing this shit!"<<endl;

			SaveDataFunc();
			return 0;
		}
	}
	bool stop=false;
	// user menu
	system("cls");
	while(!stop)
	{
		cout<<"Wellcome to the System"<<endl<<"[C]hange password"<<endl<<"[U]pgrade request"<<endl<<"[d]elete account"<<endl<<"[E]xit"<<endl;
		char option;
		cin>>option;

		switch(option)
		{
		case 'c':
		case 'C':
			{
				cout<<"enter new password"<<endl;
				cin>>pass;
				change_pass(id,pass); // call a function to change password
				break;
			}
		case 'u':
		case 'U':
			{
				upgrade_req(id); // call a function of Login as user
				break;
			}
		case 'd':
		case 'D':
			{
				delete_req(id); // call a function of registeration
				break;
			}
		case 'e':
		case 'E':
			{
				SaveDataFunc();
				delete_list();
				system ("cls");
				stop=true;
				break;
			}
		}
	}
	return 1;
}