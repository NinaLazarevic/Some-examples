#include <stdio.h>
#include <iostream>
#include <string.h>

int MinPeriod(int* a, int n); //problem no. 1

bool AreStringsIsomorphic(char* a, char* b); //problem no. 2

struct Node
{
	char data;
	Node* next;
};

void reverseNodes(Node** head, int indexA, int indexB); //problem no. 3
void addToHead(char data, Node** head);
void printList(Node* head);

struct TreeNode
{
	int value;
	TreeNode* sibling; // Pointer to the next sibling, or NULL if next sibling does not exist
	TreeNode* firstChild; // Pointer to the first child, or NULL if this is leaf
};
TreeNode* generateTree(int m, int* a); //problem no. 4
void preorder(TreeNode* root);

int main()
{
	int solution1, n;
	int a[50];

	char firstWord[15];
	char secondWord[15];



	/////// problem 1////////////
	//printf("Enter the size of array a: \n");
	//scanf("%d", &n);

	//while (n % 2 != 0)
	//{
	//	printf("\nSize you've entered is not even number. Please enter even number: \n");
	//	scanf("%d", &n);
	//}

	//printf("\nEnter elements of array a: \n");
	//for (int i = 0; i < n; i++)
	//{
	//	scanf("%d", &a[i]);
	//}

	//solution1 = MinPeriod(a, n);

	//printf("Solution for problem no. 1 is %d", solution1);


	///////////problem no. 2////////////////

	//printf("Enter first word:\n");
	//scanf("%s", firstWord);
	//printf("Enter second word:\n");
	//scanf("%s", secondWord);

	//while (strlen(firstWord) != strlen(secondWord))
	//{
	//	printf("Lenght of the words must be equal. Try again. \n");
	//	printf("Enter first word:\n");
	//	scanf("%s", firstWord);
	//	printf("Enter second word:\n");
	//	scanf("%s", secondWord);
	//}

	//if (AreStringsIsomorphic(firstWord, secondWord))
	//	printf("Strings are isomorphic");
	//else
	//	printf("Strings are not isomorphic");


	////////////problem no. 3 ///////////////

	//Node* head = NULL;
	//Node newNode = {};

	//int indexA = 2;
	//int indexB = 5;
	//
	//addToHead('2', &head);
	//addToHead('e', &head);
	//addToHead('q', &head);
	//addToHead('x', &head);
	//addToHead('c', &head);
	//addToHead('a', &head);

	//printf("List is: \n");
	//printList(head);

	//reverseNodes(&head, indexA, indexB);

	//printf("\nReversed list form index %d to index %d is: \n", indexA, indexB);
	//printList(head);

	//////////////////problem no. 4 //////////////////////////////

	int aa[] = { 3,1,4,48,2,5,3,6,18 };
	TreeNode* root = generateTree(9, aa);
	preorder(root);

}
int MinPeriod(int* a, int n)
{
	int T; //period
	int firstEl;

	firstEl = a[0];
	T = 1;
	
	while (a[T] != firstEl && T < n)
	{
		T++;
	}

	if (T == n) return n; //every element of array a is different from one another

	if (n % T != 0) 
		return n;
	else 
		return T;

}
bool AreStringsIsomorphic(char* a, char* b)
{
	char letterA;
	char letterB;

	int lenght = strlen(a);

	int i = 0; int j;
	bool result = true;

	while (i < lenght && result)
	{
		letterA = a[i]; //character for checking
		letterB = b[i]; // pair for character in string a

		for (j = i + 1; j < lenght; j++)
		{
			if (a[j] == letterA && b[j] != letterB)
				result = false;
		}

		i++;
	}

	return result;
}

void reverseNodes(Node** head, int indexA, int indexB)
{
	Node* tmpA = new Node();
	Node* tmpB = new Node();
	Node* prev = new Node();
	Node* curr = new Node();
	Node* next = new Node();

	tmpA = *head;

	for (int i = 1; i < indexA -1; i++)
	{
		tmpA = tmpA->next;
	}
	
	tmpB = *head;
	for (int i = 1; i < indexB + 1; i++)
	{
		tmpB = tmpB->next;
	}
	
	prev = tmpA->next;
	curr = prev->next;
	next = curr->next;

	while (next != tmpB)
	{
		curr->next = prev;

		prev = curr;
		curr = next;
		next = next->next;
	}

	curr->next = prev;

	tmpA->next->next = tmpB;
	tmpA->next = curr;
}


void printList(Node* head)
{
	Node* tmp;

	for (tmp = head; tmp != NULL; tmp = tmp->next)
	{
		if(tmp->next != NULL)
			printf("%c -> ", tmp->data);
		else
			printf("%c", tmp->data);
	}
}
void addToHead(char data, Node** head)
{
	if (*head == NULL)
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = NULL;

		*head = newNode;
	}
	else
	{
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = *head;

		*head = newNode;
	}
}
TreeNode* generateTree(int m, int* a)
{
	TreeNode* root = new TreeNode();
	TreeNode* curr = new TreeNode();

	root->value = a[0];
	root->firstChild = NULL;
	root->sibling = NULL;

	curr = root;

	//split array a on 2 arrays (one of possible solutions)
	int k = 1;
	int l = m / 2;

	while (a[l] % 2 != 0)
	{
		l++;
	}

	for (int j = 0; j < 2; j++)
	{
		if (j == 0)
		{
			TreeNode* newNode = new TreeNode();
			root->firstChild = newNode;
			curr = root->firstChild;
		}
		else
		{
			TreeNode* newNode = new TreeNode();
			root->sibling = newNode;
			curr = root->sibling;
		}

		for (int i = k; i < l; i++)
		{
			curr->value = a[i];
			curr->firstChild = NULL;
			curr->sibling = NULL;

			if (i != l - 1)
			{
				if (a[i] % 2 != 0) //can have kids
				{
					TreeNode* newNode = new TreeNode();
					curr->firstChild = newNode;
					curr = curr->firstChild;
				}
				else
				{
					TreeNode* newNode = new TreeNode();
					curr->sibling = newNode;
					curr = curr->sibling;
				}
			}
		}

		k = l;
		l = m;
	}

	return root;
}
void preorder(TreeNode* root)
{
	if (root == NULL)
		return;
	if(root->firstChild==NULL) //if it is leaf
		printf("%d -->", root->value);
	else
		printf("%d ==>", root->value);
	preorder(root->firstChild);
	preorder(root->sibling);
	
}