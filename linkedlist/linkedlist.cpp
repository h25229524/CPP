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
	linkedlist(){
		head = new node();
		tail = head;
		head->data = 0;
		head->next = NULL;
	}
	int insert_front(int data){
		node *ptr = head;
		head = new node();
		head->data = data;
		head->next = ptr;
		return 0;
	}
	int	insert_behind(int data){
		tail->next = new node();
		tail = tail->next;
		tail->data = data;
		tail->next = NULL;
		return 0;
	}
	int delete(){
		
	}
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
};  

int main(){
	linkedlist lt;
	for(int i = 1;i < 10;i++){
		lt.insert_front(i);
		lt.insert_behind(i);
	}
	lt.print_all();
	return 0;
}
