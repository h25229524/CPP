#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	node *next;
};

class linkedlist{
public:
	node *head;
	node *tail;
	//constructor
	linkedlist(){
		head = NULL;
		tail = NULL;
	}
	//destructor
	~linkedlist(){
		printf("linkedlist destructed");
	}
	//get length of list
	int get_length(){
		int length = 0;
		node *cur = head;
		while(cur != NULL){
			cur = cur->next;
			length ++;
		}
		return length;
	}
	//insert data to the front
	int insert_front(int data){
		node *ptr = head;
		head = new node();
		head->data = data;
		head->next = ptr;
		tail = (ptr == NULL) ? head : tail;
		return 0;
	}
	//insert data to the back
	int	insert_back(int data){
		if(tail == NULL){
			insert_front(data);
			return 0;
		}
		tail->next = new node();
		tail = tail->next;
		tail->data = data;
		tail->next = NULL;
		return 0;
	}
	//delete certain data
	int deleteC(int data){
		node *link = head;
		node *ptr = link->next;
		if(head->data == data){
			free(head);
			head = NULL;
			head = ptr;
			return 0;
		}
		while(ptr != NULL){
			if(ptr->data == data){
				link->next = ptr->next;
				free(ptr);
				return 0;
			}
			link = link->next;
			ptr = link->next;
		}
		return 1;
	}	
	//print all the data;
	int print_all(){
		node *cur = head;
		while(cur != NULL){
			printf("%p:", cur);
			printf("%d ", cur->data);
			printf("\n");
			cur = cur->next;
		}
		return 0;
	}
	//clear all the data in the list
	int clear(){
		node *cur = head;
		node *cur_next;
		head = NULL;
		tail = NULL;
		while(cur != NULL){
			cur_next = cur->next;
			delete(cur);
			cur = cur_next;
			return 0;
		}
		return 1;		
	}
};  

int main(){
	linkedlist lt;
	for(int i = 1;i < 10;i++){
		lt.insert_front(i);
		lt.insert_back(i);
	}
	lt.deleteC(9);
	lt.deleteC(9);
	lt.deleteC(4);
	lt.print_all();
	printf("%d\n", lt.get_length());
	lt.clear();
	printf("%d\n", lt.get_length());
	delete(&lt);
	return 0;
}
