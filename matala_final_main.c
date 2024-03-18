#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define nMems 300
#define IDdigits 10

typedef struct {
	unsigned short int Year;
	unsigned short int Month;
	unsigned short int Day;
} Date;

typedef struct {
	char BookName[1];
	char AuthorName[1];
	Date ReturnDate;
} Book;

typedef struct {
	char Name[1];
	char Id[IDdigits];
	Date DateOfBirth;
	int nBooks;
	Book  LoanBooks[4];

} LibMember;

void print_member(int*);
void search_id(int*);
int menu();

int main() {
	printf("hello world");
}

void print_member(int*)
{
}

void search_id(int*)
{
}

int menu()
{
	return 0;
}
