#include<bits/stdc++.h>
using namespace std;

class Node {
	/* This is basic node of Singly linkedlist. It has just two blocks,
	one block contains the data of node and other one contains the
	address of next node or NULL.
	*/
	public:
	int data;
	Node* next;
	
	Node(int data) {
	    this->data = data;
	}
};
Node *start = NULL;

void insert(int new_data) {
	/* Inserting at the last of the linkedlist.
	*/
    Node *temp=start;
	Node *new_node = new Node(new_data);
	new_node->next = NULL;
	if(start == NULL){
	    start = new_node;
	}else {
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;	
	}
}

void deleteList() {
	Node *temp=start, *t;
	while(temp != NULL) {
        t = temp->next;
        free(temp);
        temp = t;
	}
	start = NULL;
}

void display() {
	Node *temp=start;
	if(start==NULL) {
		cout<<"Linkedlist is empty"<<endl;
	}else {
		while(temp!=NULL) {
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}

int main() {
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	display();
	deleteList();
	display();
	return 0;
}
