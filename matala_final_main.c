#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nMems 300
#define IDdigits 10

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

void print_member(LibMember *);
void search_id(LibMember *);
void printdate(Date *);
void printloanedbook(LibMember*,int);
int menu();

int main()
{
	printf("hello world");
}

void printloanedbook(LibMember *ptr,int index){
Date *ptr2return = &(ptr->LoanBooks[index].ReturnDate);
printf("Name of book: %s\n",ptr->LoanBooks[index].BookName);
printf("Name of Author: %s\n",ptr->LoanBooks[index].AuthorName);
printf("Return date: ");
printdate(ptr2return);

}

void printdate(Date *ptr)
{
	printf("%d.%d.%d\n", ptr->Day, ptr->Month, ptr->Year);
}

void print_member(LibMember *ptr)
{
	Date* ptr2birth = &(ptr->DateOfBirth);
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
	return 0;
}
//hey there