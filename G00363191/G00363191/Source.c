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
}Account;

typedef struct {

	char Username[30];
	char Password[30];

}Users;



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


void load_user(Users* users)
{



	printf("\n");

}


void main()
{
	//variables
	int choice = 0;
	char user_attempt[30];
	char pass_attempt[30];
	char username[30];
	char password[30];
	Account* account = malloc(sizeof(Account));

	/*account->accountNum = 000001;
	strcpy(account->Fname, "Ben");
	strcpy(account->Lname, "O'Connor");
	strcpy(account->Address, "Somewhere");
	account->Balance = 001.00;
	strcpy(account->Email, "Ben@gmail.com");
	strcpy(account->rating, "Good");*/

	//print_account(account);

	free(account);

	//start

	FILE* f = fopen("Users.txt", "r");

	//printf("File open\n");

	Users* userList[3];


	int i = 0;
	while (fscanf(f, "%s %s", username, password) == 2) {

		Users* users = malloc(sizeof(Users));
		strncpy(users->Username, username, 30);
		strncpy(users->Password, password, 30);
		printf("%s %s\n", users->Username, users->Password);

		userList[i] = users;
		i++;




	}

	fclose(f);
	//printf("file closed \n");


	//free(user2);


	int a = 1;
	int u = 0;

	printf("Welcome please enter username and password to log in \n");


	while (a == 1) {

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