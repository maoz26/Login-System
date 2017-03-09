#include "header_system1.h"
#include "header_system2.h"

struct student {
	char firstname[50];
	char lastname[50];
	long int id ;
	char email[50];
	char course[50];
	char password[10];
	char secQ[50];
	char secA[50];
	int MemA;
	int Upg;
	int Del;
	int Admin;
	student* next;
}; 

//System functions
student* creattailsentinal()	//creates tail sentinal with INT_MAX inside, return tail pointer
{
	student* new_item=(student*)malloc(sizeof(student));
	new_item->next=NULL;
	new_item->id=LONG_MAX;
	return new_item;
}

student* creatheadsentinal(student* tail)	//creates head sentina with INT_MIN inside, return head pointer
{
	student* new_item=(student*)malloc(sizeof(student));
	new_item->next=tail;
	new_item->id=LONG_MIN;
	return new_item;
}

void add_sorted(student* head, student* tail, student stemp)	//adds element sorted from small to big, it runs through the list until it finds a elment bigger than the data we want to add and adds in front of it 
{
	student* new_item=(student*)malloc(sizeof(student));
	strcpy(new_item->firstname,stemp.firstname);
	strcpy(new_item->lastname,stemp.lastname);
	new_item->id=stemp.id;
	strcpy(new_item->email,stemp.email);
	strcpy(new_item->course,stemp.course);
	strcpy(new_item->password,stemp.password);
	strcpy(new_item->secQ,stemp.secQ);
	strcpy(new_item->secA,stemp.secA);
	new_item->MemA=stemp.MemA;
	new_item->Upg=stemp.Upg;
	new_item->Del=stemp.Del;
	new_item->Admin=stemp.Admin;
	if (head->next==tail)
	{
		new_item->next=tail;
		head->next=new_item;
		return;
	}
	else
	{
		if (stemp.id<head->next->id)
		{
			new_item->next=head->next;
			head->next=new_item;
			return;
		}
		else
		{
			head=head->next;
			while ((stemp.id)>(head->next->id))
			{
				head=head->next;
			}
			new_item->next=head->next;
			head->next=new_item;
			return;
		}
	}
}

student* myfind(student* head, long int val, char pass[10])
{
	head=head->next;
	while(head->next!=NULL)
	{
		if((head->id==val)&&((strcmp(head->password,pass))==0)){
			return head;

		}
		head=head->next;
	}
	return NULL;
}   //find user for login functions

student* Userfind (student* head, long int id){

	head=head->next;
	while(head->next!=NULL)
	{
		if(head->id==id)
		{
			return head;

		}
		head=head->next;
	}
	return NULL;
}					//find user in a list

//global sentinals
student* tailglobal = creattailsentinal();
student* headglobal = creatheadsentinal(tailglobal);


//Admin and User Functions
void delete_list()//deletes list except for sentinals 
{ 
	student* head=headglobal;
	student* temp=head;
	while (head->next->next!=NULL) 
	{ 
		temp=head->next; 
		head->next=temp->next; 
		free(temp); 
	} 

	return; 
} 

void list(){
	student* tail = tailglobal;
	student* head = headglobal;
	student stud;
	FILE *fp2;
	fp2=fopen("users.txt","r");
	if (fp2!=NULL){
		while (fscanf(fp2,"%s\t%s\t%u\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",stud.firstname,stud.lastname,&stud.id,stud.email,stud.course,stud.password,stud.secQ,stud.secA,&stud.MemA,&stud.Upg,&stud.Del,&stud.Admin)!=EOF){

			add_sorted(head,tail,stud);

		}
	}else
	{
		cout<<"file not found"<<endl;
	}
	fclose(fp2);
	return;

}

void SaveDataFunc()
{
	FILE* fp;
	fp= fopen("users.txt", "w");
	student* head=headglobal;
	head=head->next;
	while (head->next!=NULL){
		fprintf(fp,"%s\t%s\t%u\t%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",head->firstname,head->lastname,head->id,head->email,head->course,head->password,head->secQ,head->secA,head->MemA,head->Upg,head->Del,head->Admin);
		head=head->next;
	}		

	fclose(fp);
}

//User functions
int Checkexist(long int id, char pass[10]){
	student* tail = tailglobal;
	student* head = headglobal;
	student* temp = myfind(head,id,pass);
	if (temp==NULL)
	{
		return 0;
	}else{
		return 1;
	}
}	//check if the user is in the list

void change_pass(long int id,char newpass[10]){

	student* head=headglobal;
	student* temp=Userfind(head,id);
	strcpy(temp->password,newpass);
	cout<<"password has been changed to: "<<newpass<<endl;
	return;

} //change password

void upgrade_req(int long id)
{
	student* head=headglobal;
	student* temp=Userfind(head,id);
	temp->Upg=1;
	cout<<"request has been sent to an admin for confirmation\n";
	return;
}	//ask admin for memory

void delete_req(int long id)
{
	student* head=headglobal;
	student* temp=Userfind(head,id);
	temp->Del=1;
	cout<<"request has been sent to an admin for confirmation\n";
	return;
} //ask admin to delete the account

void SendEmailFunc(long int id)
{
	student* head=headglobal;
	student* temp=Userfind(head,id);

	if (temp!=NULL)
	{
		cout<<"email with new password sent to "<<temp->email<<" (new password is:1234)"<<endl;
		strcpy(temp->password,"1234");
	}else
	{
		cout<<"user id not found, shuting down!"<<endl;
	}
	return;
}

void SecQuestion(long int id)
{
	student* head=headglobal;
	student* temp=Userfind(head,id);
	char tempans[50];
	if (temp!=NULL)
	{
		cout<<"The question is: "<<temp->secQ<<endl<<"what is your answer? : ";
		cin>>tempans;
		if(!(strcmp(temp->secA,tempans))){

			cout<<"Right answer!! your password is: "<<temp->password;
		}else
		{
			cout<<"wrong answer, shutting down!"<<endl;
		}

	}else
	{
		cout<<"user id not found, shuting down!"<<endl;
	}
	return;
}

//ADMIN FUNCTIONS

int Checkexistadmin(long int id, char pass[10])
{
	student* tail = tailglobal;
	student* head = headglobal;
	student* temp = myfind(head,id,pass);
	if (temp==NULL)
	{
		return 0;
	}else{
		if(temp->Admin==1)
		{

			return 1;

		}else{

			return 0;
		}
	}
}	//check if the admin is in the list

void Print_Elements()
{
	student* head = headglobal;
	head=head->next;
	if (head->next==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
	{
		cout<<"first name: \t last name: \t id: \t email: \t\t Memory Allocation:"<<endl;
		while (head->next!=NULL)
		{
			cout<<head->firstname<<"\t\t"<<head->lastname<<"\t\t"<<head->id<<"\t"<<head->email<<"\t"<<head->MemA<<endl;
			head=head->next;
		}
	}
	return;
}	//print the user list

void Mem_Upg()
{
	student* head=headglobal;
	head=head->next;
	char question;
	while(head->next!=NULL)
	{
		if(head->Upg==1)
		{
			head->Upg=0;
			cout<<"Would you like to accept the upgrade request of "<<head->firstname<<"  "<<head->lastname<<" he has "<<head->MemA<<"Gb [Y/N]"<<endl;
			cin>>question;
			if ((question=='Y')||(question=='y'))
			{
				head->MemA=head->MemA+10;
			}
		}
		head=head->next;
	}
	cout<<"no more requests"<<endl<<endl;
	return;
}	// approve or not the memory request

void Del_Acc()
{
	student* head=headglobal;
	student* temp;
	char question;
	bool deleted=false;
	while(head->next->next!=NULL)
	{
		if(head->next->Del==1)
		{
			head->next->Del=0;
			cout<<"Would you like to accept the Delete request of "<<head->next->firstname<<"  "<<head->next->lastname<<"[Y/N]"<<endl;
			cin>>question;
			if ((question=='Y')||(question=='y'))
			{
				temp=head->next->next;
				free(head->next);
				head->next=temp;
				cout<<"User has been deleted"<<endl;
				deleted=true;	
			}
		}
		if (!deleted)
		{
			head=head->next;
		}
		deleted = false;
	}
	cout<<"no more requests"<<endl<<endl;
	return;
}		//run all over the list and delete a specific user
