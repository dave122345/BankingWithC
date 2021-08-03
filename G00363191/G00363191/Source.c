#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

typedef struct {
	int accountNum;
	char Fname[30];
	char Lname[30];
	char Address[30];
	float Balance;
	char Email[30];
	char rating[30];
	struct Account* NEXT;
}Account;

typedef struct {

	char Username[30];
	char Password[30];

}Users;

void addAccountItem(Account** first, Account* account)
{
	if (*first == NULL)
	{
		*first = account;
		return;
	}

	// Finding the last node
	Account* current = *first;
	while (current->NEXT != NULL)
	{
		current = current->NEXT;
	}

	current->NEXT = account;


}



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


int load_users(char* filename, Users** p_userList)
{


	char username[30];
	char password[30];
	FILE* f = fopen(filename, "r");

	//printf("File open\n");




	int i = 0;
	while (fscanf(f, "%s %s", username, password) == 2) {

		Users* users = malloc(sizeof(Users));
		strncpy(users->Username, username, 30);
		strncpy(users->Password, password, 30);
		printf("%s %s\n", users->Username, users->Password);

		p_userList[i] = users;
		i++;
	}

	fclose(f);
	//printf("file closed \n");

}


int load_accountFile(char* filename, Account** p_accountList)
{

	int Accountnum;
	char fName[30];
	char lName[30];
	char address[30];
	float balance;
	char email[30];
	char ratings[30];
	Account* accountlist = NULL;
	FILE* f = fopen(filename, "r");

	//printf("File open\n");


	/*account->accountNum = 000001;
	strcpy(account->Fname, "Ben");
	strcpy(account->Lname, "O'Connor");
	strcpy(account->Address, "Somewhere");
	account->Balance = 001.00;
	strcpy(account->Email, "Ben@gmail.com");
	strcpy(account->rating, "Good");*/

	//print_account(account);

	int i = 0;
	while (fscanf(f, "%d %s %s %s %f %s %s", &Accountnum, fName, lName, address, &balance, email, ratings) == 7) {

		Account* account = malloc(sizeof(Account));
		account->accountNum = Accountnum;
		strncpy(account->Fname, fName, 30);
		strncpy(account->Lname, lName, 30);
		strncpy(account->Address, address, 30);
		account->Balance = balance;
		strncpy(account->Email, email, 30);
		strncpy(account->rating, ratings, 30);

		print_account(account);

		addAccountItem(&accountlist, account);

	}
	fclose(f);

	printf("Print contents of list");

	//Display the list
	Account* current = p_accountList;
	while (current != NULL)
	{
		print_account(current);

		current = current->NEXT;
	}


	//printf("file closed \n");

}




void main()
{
	//variables
	int choice = 0;
	char user_attempt[30];
	char pass_attempt[30];
	int i = 0;
	Users* userList[3];
	Account* account = malloc(sizeof(Account));
	Account* accountList = NULL;

	free(account);

	//start

	load_users("Users.txt", userList);
	load_accountFile("Accounts.txt", accountList);


	//free(user2);


	int a = 1;

	

	printf("Welcome please enter username and password to log in \n");


	while (a == 1) {
		int u = 0;
		printf("Please enter your username:\n");
		scanf("%s", user_attempt);



		for (i = 0; i < 3; i++) {
			//printf("%s %d \n", userList[i]->Username, i);

			if (strcmp(user_attempt, userList[i]->Username) == 0) {



				printf("user found!\n");
				u = 1;
				//ask for Password

				printf("Please enter your Password:\n");
				scanf("%s", pass_attempt);

				if (strcmp(pass_attempt, userList[i]->Password) == 0) {


					a = 0;
					break;

				}

				else {
					printf("incorrect details try again\n");
					break;


				}



			}

		}
		if (u == 0) {
			printf("incorrect details try again\n");

		}



	}

	

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





	//clean up users
	for (i = 0; i < 3; i++) {
		if (userList[i] != NULL) {
			free(userList[i]);
		}
	}



}//End of main





//EOF