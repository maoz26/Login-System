#ifndef header_system1_h
#define header_system1_h
#include <iostream>
#include <stdio.h>
using namespace std;

void list();

int Checkexist (long int id,char pass[10]);

void change_pass(long int id,char newpass[10]);

void upgrade_req(long int id);

void delete_req(int long id);

void SaveDataFunc();

void SendEmailFunc(long int id);

void SecQuestion(long int id);

void delete_list();


#endif
