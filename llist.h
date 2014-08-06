#pragma once
#include <iostream>

class Node {
	public:
		int data;
		Node* link;

		Node(int);
};

class LinkedList {
	public:
		Node* start;
		int length;

		LinkedList(int);
		~LinkedList();

		bool isEmpty();
		// void CreateList();
		void AppendNode(int);
		void InsertNode(int, int);
		void DeleteNode(int);
		void DisplayList();
};