#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Constants
#define nMems 300
#define IDdigits 10

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
void search_id(LibMember *);
void printdate(Date *);
void printloanedbook(LibMember *, int);
int menu();

// Main function
int main()
{
	printf("hello world");
}

// Function Definition
void printloanedbook(LibMember *ptr, int index)
{
	Date *ptr2return = &(ptr->LoanBooks[index].ReturnDate);

	printf("Name of book: %s\n", ptr->LoanBooks[index].BookName);
	printf("Name of Author: %s\n", ptr->LoanBooks[index].AuthorName);
	printf("Return date: ");
	printdate(ptr2return);
}

void printdate(Date *ptr)
{
	printf("%d.%d.%d\n", ptr->Day, ptr->Month, ptr->Year);
}

void print_member(LibMember *ptr)
{
	Date *ptr2birth = &(ptr->DateOfBirth);

	printf("Name: %s\n", ptr->Name);
	printf("ID: %s\n", ptr->Id);
	printf("Date of Birth: ");
	printdate(ptr2birth);
}

void search_id(LibMember *ptr)
{
}

int menu()
{
	short int menu_choice = 0;

	do
	{
		printf("Database System Menu:\n");
		printf("1. Add member\n");
		printf("2. Loan books\n");
		printf("3. Return books\n");
		printf("4. Check books overdue\n");
		printf("5. Delete member\n");
		printf("6. Display all members\n");
		printf("7. Quit\n");
		printf("Please choose:\n");
		scanf(" %d\n", &menu_choice);

		if ((menu_choice < 1) && (menu_choice > 7))
			printf("Error, Wrong input. Please try again.\n");

	} while ((menu_choice < 1) && (menu_choice > 7));

	return menu_choice;
}
