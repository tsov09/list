#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T value;
	Node* next = nullptr;
	Node* previous = nullptr;
};

template <typename T>
class List {
	Node<T>* head;
	Node<T>* end;

public:
	List() : head(nullptr), end(nullptr) {};
	void add_front(Node<T>* item) {
		item->next = head;
		head->previous = item;
		head = item;
	}
	void pop_front() {
		head = head->next;
		head->previous = nullptr;
	}
	void push_back(Node<T>* item) {
		if (head == nullptr) {
			head = item;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		item->previous = temp;
		temp->next = item;
		end = item;
	}
	void pop_back() {
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return;
		}
		else if (head->next == nullptr) {
			head = nullptr;
			return;
		}
		else {
			Node<T>* temp = head;
			while (temp->next->next != nullptr) {
				temp = temp->next;
			}
			temp->next = nullptr;
			end = temp;
		}
	}
	void insert(int position, Node<T>* item) {
		Node<T>* temp = head;
		if (position == 0) {
			head->previous = item;
			head = item;
			head->next = temp;
			head->previous = nullptr;
		}
		else if (position > 0) {
			for (int i = 0; i < position - 1; i++) {
				if (temp->next == nullptr) {
					cout << "Number is out of range" << endl;
					return;
				}
				temp = temp->next;
			}
			if (temp->next != nullptr) {
				temp->next->previous = item;
			}
			else {
				end = item;
			}
			item->next = temp->next;
			temp->next = item;
			item->previous = temp;
			 
		}
		else {
			cout << "The number must be positive." << endl;
		}
	}
	void print() {
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return;
		}
		Node<T>* temp = head;
		cout << "{ ";
		while (temp->next != nullptr) {
			cout << temp->value << ", ";
			temp = temp->next;
		}
		cout << temp->value << " }";
	}
	void print_from_end() {
		if (head == nullptr) {
			cout << "List is empty." << endl;
			return;
		}
		else if (end == nullptr) {
			cout << "{ " << head->value << " }";
		}
		else {
			Node<T>* temp = end;
			cout << "{ ";
			while (temp->previous != nullptr) {
				cout << temp->value << ", ";
				temp = temp->previous;
			}
			cout << temp->value << " }";
		}
	}
};

int main() {
	Node<int>* n_1 = new Node<int>;
	n_1->value = 7;

	Node<int>* n_2 = new Node<int>;
	n_2->value = 11;
	Node<int>* n_3 = new Node<int>;
	n_3->value = 18;
	Node<int>* n_4 = new Node<int>;
	n_4->value = 89;

	List<int>* list = new List<int>;
	list->push_back(n_1);
	list->push_back(n_2);
	list->push_back(n_4);
	list->push_back(n_3);
	cout << "push_back(...) 7, 11, 89, 18: ";
	list->print();
	cout << endl;
	cout << "pop_back(): ";
	list->pop_back();
	list->print();
	cout << endl;
	list->add_front(n_3);
	cout << "add_front() 18: ";
	list->print();
	cout << endl;
	list->pop_front();
	cout << "pop_front(): ";
	list->print();
	cout << endl;
	list->insert(2, n_3);
	cout << "insert(2, ) 18: ";
	list->print();
	cout << endl;
	list->print_from_end();
	cout << endl;
	delete n_1, n_2, n_3, n_4, list;

	return 0;
}