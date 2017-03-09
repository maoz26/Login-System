#include <iostream>
#include "header_department.h"
using namespace std;

// Details of unregistered student 
struct item {
	char firstname[50];
	char lastname[50];
	long int id ;
	char email[50];
	char course[50];
}; 

// Details of registered student 
struct student {
	char firstname[50];
	char lastname[50];
	long int id ;
	char email[50];
	char course[50];
	long int password;
	char secQ[50];
	char secA[50];
	int MemA;
	int Upg;
	int Del;
	int Admin;
}; 

int create_new_user(item);

int Create_Account(long int id_check) 			// Creating a new account in the system
{
	long int id=0;
	int Result =0;
	item stu;
	FILE *fp;
	fp=fopen("student_list.txt","r");
	while (fscanf(fp,"%s%s%u%s%s",stu.firstname,stu.lastname,&stu.id,stu.email,stu.course)!=EOF)
	{
		if (id_check == stu.id)
		{
			Result = 1; //registration  success
			break;
		}

	}
	fclose(fp);
	if (Result == 0)
	{
		printf("User is not allowed to register\n");
	}

	else
	{
		printf("The user is allowed to register, lets start\n");
		int success= create_new_user(stu);
		printf("\nThe user registered successfully , the password is the same as your user id\nPlease change your password as soon as possible.\n");
		return success;	
	}

	return 1;

}//end create account

int create_new_user(item stu)
{
	FILE *fp1;
	FILE *fp2;
	fp1=fopen("users.txt","a");
	fp2=fopen("users.txt","r");
	student stu2;
	char tsecQ[50],tsecA[50];
	bool Result=false;
	while (fscanf(fp2,"%s%s%u%s%s%u%s%s%d%d%d%d",stu2.firstname,stu2.lastname,&stu2.id,stu2.email,stu2.course,&stu2.password,stu2.secQ,stu2.secA,&stu2.MemA,&stu2.Upg,&stu2.Del,&stu2.Admin)!=EOF)
	{
		if (stu2.id == stu.id)
		{
			Result = true; //registration  success
			break;
		}

	}
	if (!Result)
	{
		printf("Please choose security question\t");
		scanf("%s",tsecQ);
		printf("Please choose security answer\t");
		scanf("%s",tsecA);
		fprintf(fp1,"\n%s\t%s\t%u\t%s\t%s\t%u\t%s\t%s\t%d\t%d\t%d\t%d",stu.firstname,stu.lastname,stu.id,stu.email,stu.course,stu.id,tsecQ,tsecA,10,0,0,0);
		fclose(fp1);
	}else
	{
		cout<<"user already exists"<<endl;
	}
	return 1;
}