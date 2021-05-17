#include<stdio.h>
#include<stdlib.h>
//Representation of a polynomial having only one variable
typedef struct node
{
	int power;
	int coeff;
	struct node *link;
}node;
node *head = NULL;

node *add_at_end(node *ptr,int p,int c)
{
	node *temp = malloc(sizeof(node));
	temp->power=p;
	temp->coeff=c;
	temp->link=NULL;
	ptr->link=temp;
	ptr=temp;
	return temp;
}

void display()
{
	node *ptr=head;
	printf("\nOur polynomial is : ");
	while(ptr!=NULL)
	{
		if(ptr->coeff==0)
		printf("0 + ");
		else if(ptr->power==0)
		printf("%d + ",ptr->coeff);
		else if(ptr->coeff==0 && ptr->power==0)
		printf("0 + ");
		else
		printf("%dx^%d + ",ptr->coeff,ptr->power);
		ptr=ptr->link;
	}
	printf("0");
}

void create(int n)
{
	int p,c,i;
	head = malloc(sizeof(node));
	printf("\nEnter the coefficient for term 1 : ");
	scanf("%d",&c);
	printf("\nEnter the power for term 1 : ");
	scanf("%d",&p);
	head->power=p;
	head->coeff=c;
	head->link=NULL;
	node *ptr = head;
	for(i=2;i<=n;i++)
	{
		printf("\nEnter the coefficient for term %d : ",i);
		scanf("%d",&c);
		printf("\nEnter the power for term %d : ",i);
		scanf("%d",&p);
		ptr = add_at_end(ptr,p,c);
	}
}

int main()
{
	int n;
	printf("-------------------- Here we are representing a polynomial having only one variable ---------------------\n");
	printf("Enter the number of terms you want in your polynomial : ");
	scanf("%d",&n);
	create(n);
	display();
	return 0;
}
