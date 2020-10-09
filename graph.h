typedef struct
{
	struct Node* nodes[65535]; //lista de listas ou vector de lista
}Graph;

typedef struct node
{
	int id;
	struct node* next;
}Node;
