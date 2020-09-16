
// A C Program to demonstrate adjacency list  
// representation of graphs 
#include <stdio.h> 
#include <stdlib.h> 
  
#define maxNode = 4;

typedef struct Node 
{
	int vertexNum;
	struct Node *next;
}Node;

typedef struct List 
{
	Node *head;
}List;

List *adjlist[maxNode] = {0};

void addNode(int s, int d)
{
	Node *dest, *temp, *src;
	if(adjlist[s]->head==NULL)
	{
		src=(Node*)malloc(sizeof(Node));
		src->vertexNum=s;
		src->next=NULL;
		adjlist[s]->head=src;
	}
	dest=(Node*)malloc(sizeof(Node));
	dest->vertexNum=d;
	dest->next=NULL;
	temp=adjlist[s]->head;
	while(temp->next?=NULL)
		temp=temp->next;
	temp->next=dest;
}

void printList()
{
	int i;
	for(i=0; i<maxNode; i++)
	{
		Node *p=adjlist[i]->head;
		printf("Adjacency list for vertex %d\n", i);
		while(p)
		{
			printf("%d ", p->vertexNum);
			p=p->next;
		}
		printf("\n");
	}
}
  
// Driver program to test above functions 
int main() 
{ 
    int i;
	for (i=0; i<maxNode; i++)
	{
		adjlist[i]=(List*)malloc(sizeof(List));
		adjlist[i]->head=NULL;
	}
	addNode(0,1);
	addNode(0,3);
	addNode(1,2);
	printList();
	getch();
  
    // return 0; 
} 
