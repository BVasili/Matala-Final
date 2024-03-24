#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// Constants
#define nMems 300
#define IDdigits 10
#define num_LoanBooks 4

// Structures Declaration
typedef struct
{
	unsigned short int Year;
	unsigned short int Month;
	unsigned short int Day;
} Date;

typedef struct
{
	char *BookName;
	char *AuthorName;
	Date ReturnDate;
} Book;

typedef struct
{
	char *Name;
	char Id[IDdigits];
	Date DateOfBirth;
	int nBooks;
	Book *LoanBooks;
} LibMember;

// Function Declaration
void print_member(LibMember *);
int search_id(LibMember *, int, char[]);
void printdate(Date *);
void printloanedbook(LibMember *, int);
int menu();
void add_member(LibMember *, int);
void formatName(char *str);
int hasNumber(const char *str);
int isOnlyLetters(const char *str);
int isOnlyNumbers(const char *str);

// Main function
int main()
{
	menu();
	system("pause");
}

// Print loaned book information
void printloanedbook(LibMember *ptr, int index)
{
	if (&(ptr->LoanBooks[index]) == NULL)
		return;

	Date *ptr2return = &(ptr->LoanBooks[index].ReturnDate);

	printf("Name of book: %s\n", ptr->LoanBooks[index].BookName);
	printf("Name of Author: %s\n", ptr->LoanBooks[index].AuthorName);
	printf("Return date: ");
	printdate(ptr2return);
}

// Print date function
void printdate(Date *ptr)
{
	printf("%d.%d.%d\n", ptr->Day, ptr->Month, ptr->Year);
}

// Prints information about library member
void print_member(LibMember *ptr)
{
	Date *ptr2birth = &(ptr->DateOfBirth);

	printf("Name: %s\n", ptr->Name);
	printf("ID: %s\n", ptr->Id);
	printf("Date of Birth: ");
	printdate(ptr2birth);

	for (int i = 0; i < num_LoanBooks; i++)
		printloanedbook(ptr, i);
}

// Searches for ID in Database.
int search_id(LibMember member_array[], int activeUsers, char id[])
{
	// Compares given ID to the database and returns index if found.
	for (int i = 0; i < activeUsers; i++)
	{
		if (strcmp(member_array[i].Id, id))
			return i;
	}
	// Returns -1 if ID is not within database.
	return -1;
}

// Prints menu, returns menu choice as a short int.
int menu()
{
	short int menu_choice = 0;
	do
	{
		menu_choice = 0;
		printf("Database System Menu:\n");
		printf("1. Add member\n");
		printf("2. Loan books\n");
		printf("3. Return books\n");
		printf("4. Check books overdue\n");
		printf("5. Delete member\n");
		printf("6. Display all members\n");
		printf("7. Quit\n");
		printf("Please choose an action:\n");
		scanf("%d", &menu_choice);

		/* Checks if user inputed valid number - prints error and
		   asks user to input valid number */
		if ((menu_choice < 1) || (menu_choice > 7))
			printf("\nError, Wrong input. Please try again.\n\n\n");

		// Flushes buffer to eliminate endless loop.
		fseek(stdin, 0, SEEK_END);

	} while ((menu_choice < 1) || (menu_choice > 7));

	return menu_choice;
}

void formatName(char *str)
{
	*str = toupper(*str); // First letter to-be uppercase
	while (*str)
	{
		*str = tolower(*str);

		if (*(str - 1) == ' ')
			*str = toupper(*str);

		str++;
	}
}

int hasNumber(const char *str)
{
	while (*str)
	{
		if (isdigit(*str))
		{
			return true; // Return true if a digit is found
		}
		str++;
	}
	return false; // Return false if no digit is found
}

int isOnlyLetters(const char *str)
{
	while (*str)
	{
		if (!isalpha(*str))
		{
			return false; // Return false if a non-alphabetic character is found
		}
		str++;
	}
	return true; // Return true if only letters are found
}

int isOnlyNumbers(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return false; // Return 0 if a non-numeric character is found
		}
		str++;
	}
	return true; // Return 1 if only numbers are found
}

void add_member(LibMember *ptr, int activeUsers)
{
	char name[40] = {'a'};
	char id[9];
	Date date_of_birth;
	do
	{ // Gets name and checks if valid
		printf("Enter your name: ");
		fgets(name, sizeof(name), stdin);

		if (name[strlen(name) - 1] == '\n')
			name[strlen(name) - 1] = '\0';

		if (!isOnlyLetters(name))
			printf("Error a valid name\n");

	} while (!isOnlyLetters(name));

	formatName(name);

	do
	{ // Gets ID numbers and check if its valid

		printf("Enter your id: ");
		fgets(id, sizeof(id), stdin);

		if (!isOnlyNumbers(id))
			printf("enter only numbers");

	} while (!isOnlyNumbers(id));
}