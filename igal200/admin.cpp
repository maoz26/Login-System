#include "header_admin.h"
#include "header_system2.h"

int LoginAdmin(){
	list();
	long int id;
	char pass[10];
	cout<< "Please enter admin ID: ";
	cin>>id;
	cout<< "Please enter admin password: ";
	cin>>pass;
	int result=Checkexistadmin(id,pass);
	if (result==1){
		cout<<"welcom admin"<<endl;
		system("cls");
		bool stop=false;
		while(!stop)
		{
			cout<<"Wellcome to the Admin Menu"<<endl<<"[M]emory upgrade"<<endl<<"[D]elete request"<<endl<<"[P]rint user list"<<endl<<"[E]xit"<<endl;
			char option;
			cin>>option;
			switch(option)
			{
			case 'm':
			case 'M':
				{
					Mem_Upg(); // call a function to change password
					break;
				}
			case 'd':
			case 'D':
				{
					Del_Acc(); // call a function of Login as user
					break;
				}
			case 'p':
			case 'P':
				{
					Print_Elements(); // call a function of registeration
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

	}else
	{
		return 0;
	}

	return 1;

}