
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int val){
			data=val;
			next=NULL;
		}
};

void insertEnd(node* &head, int val){
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

void insertHead(node* &head , int val){
	node* n=new node(val);
	n->next=head;
	head=n;
}

void insertBetween(node* &head, int val, int key){
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

void display(node* head){
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

void deleteHead(node* &head){
	node* temp=head;
	head=head->next;
	delete temp;
	
}

void deletes(node* &head, int val){
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

void deleteBetween(node* &head, int key){
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

int main()
{
	node*head=NULL;
	insertEnd(head,1);
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
	display(head);
	
	
	return 0;
}
