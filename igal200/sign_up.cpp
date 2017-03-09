#include "header_register.h"
#include "header_department.h"
#include <iostream>
using namespace std;


int sign_up()		//sign up function
{
	long int id_check=0;
	printf( "welcome new user, please sign up\n");
	printf( "please enter your ID:\t");
	scanf ("%u", &id_check);
	int result = Create_Account(id_check);
	return result;
}
