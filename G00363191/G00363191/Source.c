#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

typedef struct  {
	int accountNum;
	char Fname[30];
	char Lname[30];
	char Address[30];
	float Balance;
	char Email[30];
	char rating[30];
}Account;


//defines and functions here
void print_account(Account* account)
{
	if (account == NULL)
	{
		return;
	}
	
	printf("Account number: %d\n", account->accountNum);
	printf("First Name: %s\n", account->Fname);
	printf("Last Name: %s\n", account->Lname);
	printf("Address: %s\n", account->Address);
	printf("Email: %s\n", account->Email);
	printf("Balance: %f\n", account->Balance);
	printf("rating: %s\n", account->rating);


	printf("\n");

}


void main()
{
	//variables
	int choice;
	Account* account= malloc(sizeof(Account)); 
	
	account->accountNum = 000001; 
	strcpy(account->Fname, "Ben");
	strcpy(account->Lname, "O'Connor");
	strcpy(account->Address, "Somewhere");
	account->Balance = 001.00;
	strcpy(account->Email, "Ben@gmail.com");
	strcpy(account->rating, "Good");
	
	print_account(account);

	free(account);

	//start
	

	/*
	FILE* f = fopen("Savegame.dat", "rb");
	printf("Loading Game\n");
	fread(drawn, sizeof(int), 100, f);
	fread(&Numofplayers, sizeof(int), 1, f);
	printf("\nNumofplayers = %d\n", Numofplayers);
	for (int p = 0; p < Numofplayers; p++)
	{
		players[p] = malloc(sizeof(bingo_player));
		fread(players[p], sizeof(struct bingo_player), 1, f);
	}
	fclose(f);*/

	printf("Menu");
	scanf("%d", &choice);

	if (choice == 1)
	{

	}
	else if (choice == 2)
	{

	}
	else if (choice == 3)
	{

	}
	else if (choice == -1)//exit
	{
		printf("Goodbye.\n");
		exit(0);
	}




}//End of main





//EOF