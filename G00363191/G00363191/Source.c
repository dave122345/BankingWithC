#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

typedef struct {
	char accountNum[30];
	char Fname[30];
	char Lname[30];
	char Address[30];
	float Balance;
	char Email[30];
	int rating;
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

	printf("Account number: %s\n", account->accountNum);
	printf("First Name: %s\n", account->Fname);
	printf("Last Name: %s\n", account->Lname);
	printf("Address: %s\n", account->Address);
	printf("Email: %s\n", account->Email);
	printf("Balance: %.2f\n", account->Balance);
	printf("rating: %d\n", account->rating);


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

	char Accountnum[30];
	char fName[30];
	char lName[30];
	char address[30];
	float balance;
	char email[30];
	int ratings;


	FILE* f = fopen(filename, "r");

	//printf("File open\n");


	while (fscanf(f, "%s %s %s %s %f %s %d", Accountnum, fName, lName, address, &balance, email, &ratings) == 7) {

		Account* account = malloc(sizeof(Account));

		strncpy(account->accountNum, Accountnum, 30);
		strncpy(account->Fname, fName, 30);
		strncpy(account->Lname, lName, 30);
		strncpy(account->Address, address, 30);
		account->Balance = balance;
		strncpy(account->Email, email, 30);
		account->rating = ratings;

		account->NEXT = NULL;

		addAccountItem(p_accountList, account);

	}
	fclose(f);

	//printf("file closed \n");

}

//find account
Account* find_account(Account* accountList) {

	//vars
	char accountNumber[30];
	char accountFName[30];
	char accountLName[30];
	int choice = 0;
	Account* current = accountList;

	printf("Enter 1 for searching with an account number or enter 2 to search with a full name:\n");
	scanf("%d", &choice);
	if (choice == 1) {
		//number search

		printf("Please enter the account number\n");
		scanf("%s", accountNumber);

		//printf("TEST: %s", accountNumber);



		while (current != NULL)
		{

			if (strcmp(accountNumber, current->accountNum) == 0) {
				//printf("inside search number\n");
				printf("Account found!\n");
				return current;

			}
			//printf("%s\n", accountNumber);

			current = current->NEXT;
		}

	}

	else if (choice == 2) {
		//name search

		printf("Please enter the account holders first name:\n");
		scanf("%s", accountFName);
		printf("Please enter the account holders last name:\n");
		scanf("%s", accountLName);

		//printf("TEST: %s %s", accountFName, accountLName);



		while (current != NULL)
		{

			if (strcmp(accountFName, current->Fname) == 0 && strcmp(accountLName, current->Lname) == 0) {
				//printf("inside search name\n");
				printf("Account found!\n");
				return current;

			}
			current = current->NEXT;
		}
	}



	return NULL;
}
//lodgement 
void lodge_to_account(Account* account)
{

	if (account == NULL)
	{
		return;
	}


	//vars
	float lodgement;
	float oldBalance = account->Balance;
	float newBalance;

	printf("How much do you want to lodge:\n");
	scanf("%f", &lodgement);

	newBalance = lodgement + oldBalance;

	printf("Your old balance was: %.2f\n", oldBalance);
	printf("Your new balance is: %.2f\n", newBalance);

	account->Balance = newBalance;


	print_account(account);




}

//withdraw 
void withdraw_from_account(Account* account)
{
	if (account == NULL)
	{
		return;
	}

	//vars
	float withdraw;
	float oldBalance = account->Balance;
	float newBalance;

	printf("How much do you want to withdraw:\n");
	scanf("%f", &withdraw);

	newBalance = oldBalance - withdraw;

	printf("Your old balance was: %.2f\n", oldBalance);
	printf("Your new balance is: %.2f\n", newBalance);

	account->Balance = newBalance;


	print_account(account);

}

//delete function
void removeAccount(Account** first, char* accountNum)
{
	if (*first == NULL)
	{
		return;
	}

	// Check if first element is to be removed

	Account* current = *first;

	if (strcmp(current->accountNum, accountNum) == 0)
	{
		printf("Found account (first element)\n");
		// Remove first element - set *first to next (second) node
		*first = current->NEXT;

		// Free the memory for the removed node
		free(current);
		return;
	}

	// Not the first element, so begin searching
	Account* prev = NULL;

	do
	{

		prev = current;
		current = current->NEXT;


		if (strcmp(current->accountNum, accountNum) == 0)
		{
			printf("Found account %s\n", accountNum);
			// Stitch previous and next elements together
			// Note: This also works if current is the last element

			prev->NEXT = current->NEXT;

			// Free the memory for the removed node
			free(current);
			return;
		}


	} while (current->NEXT != NULL);
}

//showing accounts
void showAccounts(Account* accountList)
{
	Account* current = accountList;

	while (current != NULL)
	{
		print_account(current);

		current = current->NEXT;
	}

}


void add_account(Account** p_accountList)
{
	char Accountnum[30];
	char fName[30];
	char lName[30];
	char address[30];
	float balance;
	char email[30];
	int ratings;

	printf("Please enter your Account number:\n");
	scanf("%s", Accountnum);

	printf("Please enter your First Name:\n");
	scanf("%s", fName);

	printf("Please enter your Last Name:\n");
	scanf("%s", lName);

	printf("Please enter your address (county you live in):\n");
	scanf("%s", address);

	printf("Please enter the balance in the acccount:\n");
	scanf("%.2f", &balance);

	printf("Please enter your e-mail:\n");
	scanf("%s", email);

	printf("Please enter a rating for the service of the bank (1 = excellent, 2 = very good, 3 = satisfactory, 4 = disappointing or 5 = bad):\n");
	scanf("%d", &ratings);

	Account* account = malloc(sizeof(Account));

	strncpy(account->accountNum, Accountnum, 30);
	strncpy(account->Fname, fName, 30);
	strncpy(account->Lname, lName, 30);
	strncpy(account->Address, address, 30);
	account->Balance = balance;
	strncpy(account->Email, email, 30);
	account->rating = ratings;

	account->NEXT = NULL;

	addAccountItem(p_accountList, account);


}

char* stats_genarator(Account* accountList, char *stats) {

	Account* current = accountList;
	
	float count1 = 0;
	float count2 = 0;
	float count3 = 0;
	float count4 = 0;
	float count5 = 0;


	

	while (current != NULL)
	{
		switch (current->rating) {
		case 1:
			count1++;
			break;
		case 2:
			count2++;
			break;
		case 3:
			count3++;
			break;
		case 4:
			count4++;
			break;
		case 5:
			count5++;
			break;
		default:
			printf("Invalid rating detected\n");
		}


		current = current->NEXT;
	}
	float total = count1 + count2 + count3 + count4 + count5;


	float result1 = (count1 / total) * 100;
	float result2 = (count2 / total) * 100;
	float result3 = (count3 / total) * 100;
	float result4 = (count4 / total) * 100;
	float result5 = (count5 / total) * 100;

	sprintf(stats, "percentage of:\n customers for excellent review: %.2f\n customers for very good review: %.2f\n customers for satisfactory review: %.2f\n customers for disappointing review: %.2f\n customers for bad review: %.2f\n", result1, result2, result3, result4, result5);

	return stats;


}

void print_report(Account* accountList) {
	Account* current = accountList;
	FILE* filename = "Report.txt";
	char stats[500];

	FILE* f = fopen(filename, "w+");


	while (current != NULL)
	{
		//saving file
		//fprintf(f, "%s %s %s %s %.2f %s %d \n", current->accountNum, current->Fname, current->Lname, current->Address, current->Balance, current->Email, current->rating);
		fprintf(f, "%s %s %s %s %.2f %s %d \n", current->accountNum, current->Fname, current->Lname, current->Address, current->Balance, current->Email, current->rating);


		current = current->NEXT;

	}

	//stats area
	fprintf(f, "system generated stats are %s", stats_genarator(accountList, stats));



}

//saving to file
void saveToFile(char* filename, Account* accountList)
{
	Account* current = accountList;

	FILE* f = fopen(filename, "w");

	while (current != NULL)
	{
		//saving file
		fprintf(f, "%s %s %s %s %.2f %s %d \n", current->accountNum, current->Fname, current->Lname, current->Address, current->Balance, current->Email, current->rating);

		current = current->NEXT;
	}

	//clsoing file
	fclose(f);
}


void main()
{
	//variables
	int choice = 0;
	char stats[500];
	char user_attempt[30];
	char pass_attempt[30];
	int i = 0;
	Users* userList[3];
	Account* account = malloc(sizeof(Account));

	Account* accountList = NULL;

	free(account);

	//start

	load_users("Users.txt", userList);
	load_accountFile("Bank.txt", &accountList);

	printf("Print contents of list\n");

	//Display the list - TEST
	Account* current = accountList;
	while (current != NULL)
	{
		print_account(current);

		current = current->NEXT;
	}


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

	//menu
	while (choice != -1) {
		printf("Welcome to your menu\n");
		printf("1. add account \n2. display all accounts with a balance less than 100\n3. display account holder details\n4. make a lodgement\n5. withdraw money from account\n6. Delete\n7. genereate stats\n8. print account account holders into a report file\n or enter -1 to exit\n");
		scanf("%d", &choice);


		if (choice == 1)
		{
			//add new account
			add_account(&accountList);
		}
		else if (choice == 2)
		{
			//display all account with balance < 100
			showAccounts(accountList);

		}
		else if (choice == 3)
		{
			//display account holder details
			Account* account = find_account(accountList);
			print_account(account);
		}
		else if (choice == 4)
		{
			//lodge to account
			Account* account = find_account(accountList);
			lodge_to_account(account);

		}
		else if (choice == 5)
		{
			//withdraw from acccount
			Account* account = find_account(accountList);
			withdraw_from_account(account);
		}
		else if (choice == 6)
		{
			//delete account

			Account* account = find_account(accountList);
			removeAccount(&accountList, account->accountNum);
		}
		else if (choice == 7)
		{
			//stats
			printf("system generated stats are %s", stats_genarator(accountList, stats));
		}
		else if (choice == 8)
		{
			//print all account info into a report file
			print_report(accountList);
		}
		else if (choice == -1)//exit
		{

			saveToFile("Bank.txt", accountList);

			//clean up users
			for (i = 0; i < 3; i++) {
				if (userList[i] != NULL) {
					free(userList[i]);
				}
			}

			Account* current = accountList;

			while (current != NULL)
			{
				Account* temp = current;

				current = current->NEXT;
				free(temp);
			}
			printf("Goodbye.\n");

			exit(0);
		}
	}
}//End of main
//EOF