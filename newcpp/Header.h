#pragma once
#include <iostream>
#include <algorithm>

struct Node {

	int data;
	Node* next;
	Node(int _data) : data(_data), next(nullptr){}

};


struct List {

	Node* first;
	Node* last;

	List() : first(nullptr), last(nullptr){}

	bool is_empty() {
		return last == nullptr;
	}

	void push_back(int x) {
		Node* c = new Node(x);
		if (is_empty()) {
			first = c;
			last = c;
			return;
		}
		last->next = c;
		last = c;
	}

	void push_front(int x) {
		Node* c = new Node(x);
		if (is_empty()) {
			first = c;
			last = c;
		}
		c->next = first;
		first = c;
		
	}

	int amount_El(int &a) {
		a = 0;
		Node* k = first;
		while (1) {
			if (k->next == NULL) { std::cout << "size: 0 " << std::endl; break; }
			else {
				a++;
			}
			k = k->next;
		}
		a++;
		return a;
	}

	void sort() {
		int amount = 0; 
		amount_El(amount);
		bool wh = true;

		for (int i = 0; i < amount; i++) {
			Node* s = first;
			wh = true;
			std::cout << i << ") ";
			while (wh) {
				if (s->next->data < s->data) {
					std::cout << "Swap(" << s->next->data << " " << s->data << ")  ";
					std::swap(s->next->data, s->data);
				}
				s = s->next;
				if (s->next == NULL) {
					wh = false;
				}
			}
			std::cout << std::endl;
		}

		
	}

	void pop_front() {
		Node* y = first;
		first = first->next;
		delete y;		
	}

	void pop_back() {
		Node* e = first;
		while (e != nullptr) {
			if (e->next == last) {
				last = e;
				break;
			}
			e = e->next;
		}
		while (1) {
			if (e == nullptr) { break; }
			else {	e = e->next; }
		}
		delete e;
	}

	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p != nullptr) {
			std::cout << p->data <<  " ";
			p = p->next;
		}
		std::cout << std::endl;
	}

	void find(int F) {
		Node* q = first;
		int amount = 0;
		amount_El(amount);
		for (int i = 0; i < amount; i++) {
			if (F == q->data) {
				std::cout << "Number of element: " << i << std::endl;
				std::cout << "Addres: " << q << std::endl;
				break;
			}
			else {
				q = q->next;
			}
		}
	}

	int size() {
		int amount = 0;
		amount_El(amount);
		return amount;
	}

	void clear() {
		int amount = 0;
		amount_El(amount);
		for (int i = 0; i < amount; i++) {
			pop_front();
		}
	}
};