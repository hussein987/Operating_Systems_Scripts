#include <stdio.h>
#include <stdlib.h>

// Linked list struct
struct list{
	int data;
	struct list *next;
};

// define node as a opinter of datatype struct lsit
typedef struct list* node;

// create a new node and initialize its data with some value
node create_node(int value){
	node temp;
	temp = (node)malloc(sizeof(struct list));
	temp -> next = NULL;
	temp -> data = value;
	return temp;
}

// calculate the size of the linked list
int get_size(node head){
	int ans = 0;
	if(head == NULL) return 0;
	while(head -> next != NULL){
		head = head -> next;	
		ans++;
	}
	return ans+1;
}

// isnert a node with some value and index in the linked list 
void insert_node(node *head, int index, int value){
	if(index > get_size(*head) || index < 0){
		printf("index is not valid\n");
		return;	
	}
	node temp = *head;
	node new_node = create_node(value);
	if(index == 0) {
		new_node -> next = temp;
		*head = new_node;
		return;	
	}
	for(int i=0;i<index-1;i++)
		temp = temp -> next;
	new_node -> next = temp -> next;
	temp -> next = new_node;
}

// delete a node of some index from the linked list
void delete_node(node *head, int index){
	node temp = *head;
	if(index > get_size(temp) || index < 0){
		printf("index not valid\n");
		return;
	}
	if(index == 0){
		*head = temp -> next;
		free(temp);
		return;
	}
	for(int i=0;i<index-1;i++)
		temp = temp -> next;
	node prev = temp;
	node nxt = (temp -> next) -> next;
	free(prev -> next);
	prev -> next = nxt;
}

// prints the elements of the linked list
void print_list(node head){
	while(head != NULL){
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

/*----------------------------------------MAIN----------------------------------------------*/

int main(){
	// creating a list of 3 elements
	node head = create_node(1);
	head -> next = create_node(2);		
	(head -> next) -> next = create_node(3);

	// print the initial list
	print_list(head);

	// insert a node with a value 10 in the 3rd index and print the new list
	insert_node(&head, 3, 10);
	print_list(head);

	// delete the node with index 3 from the list and print the new list
	delete_node(&head, 3);
	print_list(head);
	
	// insert a node with a value 11 in the 1st index and print the new list
	insert_node(&head, 1, 11);
	print_list(head);
	return 0;
}
