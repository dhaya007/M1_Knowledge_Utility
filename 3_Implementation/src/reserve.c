#include<stdio.h>
#include<stdlib.h>
#include"reserve.h"
#include"ticket.c"




int build_a_ticket( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->ID_num=1;
	printf("Name of the passenger : ");
	scanf("%s", new->Name);
	printf("Age of the passenger : ");
	scanf("%d", &new->Age);
    if(new->Age>=90 || new->Age<=10) {
        free(new);
        return -1;
    }
	begin=new;
	new->nxt=NULL;
	num++;
    return 1;
	
}

int reserve_a_ticket(node *begin)
{
	int temp;
	if(begin==NULL)
	{   
   		temp = build_a_ticket(begin);
		 return temp;
	}
	else 
	{
	
	node *temp, *new_node;
	temp=begin;
	while(temp->nxt!=NULL)
	{ 
	  temp=temp->nxt;
	}
	
	new_node=(node *)malloc(sizeof(node));
	
	printf("Name of the passenger: ");
	scanf("%s", new_node->Name);
	printf("Age of the passenger: ");
	scanf("%d", &new_node->Age);
    if(new_node->Age >=90 || new_node->Age<=10) {
        return -1;
    }
	new_node->nxt=NULL;
	if(num<=size)
	{
		num++;
		new_node->ID_num=num;
		temp->nxt=new_node;
		
		return 1;
	}
	else
	{
		enq(new_node);
		return 0;
	}
}
}


int cancel_ticket(int reg)
{
	node *p, *preptr, *new;
	p=begin;
	preptr=NULL;
	if(begin==NULL)
	return -1;
	if(p->nxt==NULL && p->ID_num==reg)
		{
		begin=NULL;
		num--;
		free(p);
		return 1;
		
		}
		
	else{	
	while(p->ID_num!=reg && p->nxt!=NULL)
		{
			preptr=p;
			p=p->nxt;
		}
		if(p==NULL && p->ID_num!=reg)
			return -1;
		else
			preptr->nxt=p->nxt;
		free(p);
		new=deq();
		while(preptr->nxt!=NULL)
			preptr=preptr->nxt;
		preptr->nxt=new;
		num--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rr==NULL)
	{
		rr=new_node;
		rr->nxt=NULL;
		first=rr;
	}
	else
	{
		node *temp;
		temp=new_node;
		rr->nxt=temp;
		temp->nxt=NULL;
		rr=temp;
	}
	count++;
}

node* deq()
{
	node *first1;
	first1=first;
	if(first==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(first->nxt!=NULL)
		{
			first=first->nxt;
			first1->nxt=NULL;
			return first1;
		}
		else
		{
			first=NULL;
			rr=NULL;
			
			return first1;
		}
	}	
}


void display()
{
	node *temp;
	temp=begin;
	while(temp!=NULL)
	{
		printf("\nID Number: %d\n", temp->ID_num);
		printf("Name of the passenger: %s\n\n", temp->Name);
		temp=temp->nxt;
    }
    
}

int main()
{
	int choice, status=0,canc=0, reg=0;
	begin=NULL;
	rr=NULL;
	first=NULL;
	
	
	
	printf("\t\t\t*RAILWAY RESERVATION*\t\t\t\t\n");
	int ch =0;
	while(ch!=4)
	{
	printf("\n\nDo you want to - \n 1. Book a ticket \n 2. Cancel Booking \n 3. Display Passenger Details \n 4. Exit\n\n");
	scanf("%d", &choice); 
	switch(choice)
	{	
		case 1 :  status=reserve_a_ticket(begin);
	              if(status==0)
	                printf("\nBooking Full!! \nYou are added to waiting list. Waiting list number %d", count);
	              else if(status == -1) {
                      printf("\n age not eligible");
                  }
                  else
	                printf(" \nYOUR BOOKING IS SUCCESSFUL!!! ENJOY YOUR JOURNEY! YOUR ID NUMBER is %d\n\n", num);
	                
	              break;
	        
	    case 2:   printf(" \n Give the ID Number to be cancelled\n");
	              scanf(" %d", &reg);
	              if(reg>num)
	              printf("Invalid!!");
	              else
	              {
	              canc=cancel_ticket(reg);
	              if(canc==-1)
	              	printf("\nID Number invalid!!\n");
	              else
	              	printf("\nRegistration cancelled successfully\n");
	              	}
	              break;
	              
	    case 3: display();
	    break;
	    case 4: exit(0);   
	    break;
	    default: printf("\nWrong Choice!\n");       
	           
	}
	
}

}