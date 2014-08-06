#include "llist.h"

Node::Node(int num):data(num){
	this->link = NULL;
}

LinkedList::LinkedList(int start_data){
	this->start = new Node(start_data);
	this->length = 1;
}

void LinkedList::AppendNode(int num){
	Node* temp = this->start;
	while(temp->link != NULL){
		temp = temp->link;
	}
	Node* new_node = new Node(num);
	temp->link = new_node;
	this->length += 1;
}

void LinkedList::InsertNode(int num, int pos){
	if(pos != 1 && pos <= this->length){
		int counter = 1;
		Node* prev = this->start;
		Node* curr = this->start;

		while(counter != pos){
			prev = curr;
			curr = curr->link;
			counter += 1;
		}

		Node* new_node = new Node(num);
		prev->link = new_node;
		new_node->link = curr;
	}
	else if(pos == 1){
		Node* new_node = new Node(num);
		new_node->link = this->start;
		start = new_node;
	}
	else{
		std::cout << "Bad input! No cookie!" << std::endl;
	}

	this->length += 1;
}

void LinkedList::DeleteNode(int pos){
	if(pos == 1){
		Node* temp = this->start;
		start = this->start->link;
		delete temp;
		temp = NULL;						// dangling pointer?
	}
}

// void LinkedList::CreateList(){
// }

bool LinkedList::isEmpty(){
	if(this->start == NULL){
		// assert(this->length == 0)
		return 1;
	}
	return 0;
}

void LinkedList::DisplayList(){
	Node* temp = this->start;
	while(temp->link != NULL){
		std::cout << temp->data << "\t";
		temp = temp->link;
	}
	std::cout << temp->data << std::endl;
}

LinkedList::~LinkedList(){
	Node* temp = this->start;
	Node* curr = temp;
	while(curr->link != NULL){
		temp = curr->link;

		curr->link = NULL;
		delete curr;
		curr = temp;
	}
	delete curr;
	this->start = NULL;
	this->length = 0;
}

int main(int argc, char const *argv[])
{
	LinkedList l(5);
	l.AppendNode(3);
	l.InsertNode(1, 4);
	l.DisplayList();
	return 0;
}