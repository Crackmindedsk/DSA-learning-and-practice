
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class node{
	int data;
	node* next;
	
	
}

class LinkedList : public node {
	private:
	node* head;
	public:
	LinkedList(int val){
		head=new node;
		head.data=val;
		head.next=NULL;
	}

void insertEnd(int val){
	node* n=new node(val);
	if(head==NULL){
		head=n;
		return;
	}
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=n;
}

void insertHead(int val){
	node* n=new node(val);
	n->next=head;
	head=n;
}

void insertBetween(int val, int key){
	node* n=new node(val);
	int pos=1;
	if(pos==key){
		insertHead(head,val);
		return;
	}
	node* temp=head;
	while(pos!=key){
		temp=temp->next;
		pos++;
	}
	n->next=temp->next;
	temp->next=n;
	
}

void display(){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

bool search(node* head, int key){
	node* temp=head;
	while(temp!=NULL){
		if(temp->data==key)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}

void deleteHead(){
	node* temp=head;
	head=head->next;
	delete temp;
	
}

void deletes(int val){
	if(head==NULL){
		return;
	}
	if(head->next==NULL){
		deleteHead(head);
	}
	node* temp=head;
	while(temp->next->data!=val){
		temp=temp->next;
	}
	node* n=temp->next;
	temp->next=temp->next->next;
	delete n;
}

void deleteBetween(int key){
	if(key==1){
		deleteHead(head);
	}
	node* temp=head;
	for(int i=2;i<key;i++){
		temp=temp->next;
	}
	node* n=temp->next;
	temp->next=temp->next->next;
	delete n;
}
};

int main()
{
	/*insertEnd(head,1);
	insertEnd(head,2);
	insertEnd(head,3);
	insertBetween(head,7,2);
	display(head);
	cout<<search(head,1)<<endl;
	insertHead(head,4);
	deletes(head,1);
	display(head);
	deleteHead(head);
	display(head);
	deleteBetween(head,2);
	display(head);*/
	LinkedList obj(1);
	obj.insertHead(10);
	obj.insertEnd(99);
	// CALL WHATEVER YOU LIKE
	return 0;
}
