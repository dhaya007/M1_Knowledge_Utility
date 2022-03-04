#include<stdio.h>
#define size 2


typedef struct NODE
{
	int ID_num;
	int Age;
	char Name[25];
	struct NODE *nxt;
} node;

node* deq();
int build_a_ticket();
int reserve_a_ticket(node*);
int cancel_ticket(int);
void enq(node*);
void display();


node *begin;
node *first;
node *rr;
int count=0;
int num=0;