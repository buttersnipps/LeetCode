// linkedlistadd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct node
{
	int data;
	node* next;

	node(int x) :data(x), next(nullptr){}
};
void push(node* * head_ref, int new_data) {
	node* new_node = new node(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;

}
void print(node* node) {
	while (node != nullptr) {
		std::cout<< node->data;
		node = node->next;
	}
}
node* addtwolist(node* l1, node* l2)
{
	node* result = nullptr;
	node* temp = nullptr;
	node* prev = nullptr;


	int carry = 0;
	int sum=0;
	while (l1 != nullptr || l2 != nullptr) {
		 
		sum = carry + (l1 != nullptr ? l1->data : 0) + (l2 != nullptr ? l2->data : 0);
		carry = (sum >= 10) ? 1 : 0;
		sum = sum % 10;
		temp = new node(sum);
		if (result == nullptr)
		{
			result = temp;
		
		}
		else {
			prev->next = temp;
		}
		prev = temp;
		if (l2 != nullptr) {
			l2 = l2->next;
		}
		if (l1 != nullptr) {
			l1 = l1->next;
		}
	}
	if (carry > 0) {
		temp->next = new node(carry);
	}


	return result;
	
}
int main()
{
	node* res = nullptr;
	node* first = nullptr;
	node* second = nullptr;

	push(&first, 2);
	push(&first, 4);
	push(&first, 3);

	std::cout << "First list is" << std::endl;
	print(first);
	printf("\n");

	push(&second, 5);
	push(&second, 6);
	push(&second, 4);
	std::cout << "second list is" << std::endl;
	print(second);
	printf("\n");
	res = addtwolist(first, second);
	printf("\n");
	printf("\n");
	print(res);
	printf("\n");


    return 0;
}

