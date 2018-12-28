// implement a linked list in c++
#include <iostream>


using namespace std;
struct node{
	int data;
	node *next;
};

class list {
	private:
		node *head, *tail;
	public:
		list(){ head = NULL; tail = NULL;length = 0;}
		void append(int n);
		void prepend(int n);
		bool contains(int n);
		bool remove(int n);
		void reverse();
		void print();
		int at(int pos);
		int length;
};

//functions for linked list
void list::reverse(){
	
	if (head == NULL || head->next == NULL){
		return;
	}
	if (head->next->next == NULL){
		node *tmp=head;
		tail->next = head;
		head->next = NULL;
		head = tail;
		tail = tmp;
		return;
	}
	node* prev = NULL;
	node* curr = head;
	node* nxt = NULL;
	
	while (curr != NULL){
		nxt = curr->next;
		curr->next = prev;
		// go to next node
		prev = curr;
		curr = nxt;
		//cout<<prev->data<<","<<curr->data<<","<<nxt->data<<endl;
		
		//cout <<"h";	
	}
	cout<<"!";
	node *tmp = head;
	head = tail;
	tail = tmp;
	return;
}
void list::print(){
	node *curr = head;
	//cout<<tail->data<<":\t";
	//cout<<head->data<<":\t";
	cout<<"#"<<length<<"\t";
	while (curr != NULL){
		std::cout <<curr->data<<"\t";
		curr = curr->next;
	}
	std::cout << std::endl;
}
void list::append(int n){
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	
	// check if list is empty, so new elemnt is head and tail
	if (head == NULL){
		head = tmp;
		tail = tmp;
	}
	else{
		tail->next = tmp;
		tail = tail->next;
	}
	length++;
}

void list::prepend(int n){
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;
	
	//check if list ist empty
	if (head == NULL){
		head = tmp;
		tail = tmp;
	}
	else{
		tmp->next = head;
		head = tmp;
	}
	length++;
}

int list::at(int pos){
	if (pos >= length)
		return -1;
	unsigned int cnt = 0;
	node *curr = head;
	while (cnt <pos){
		curr = curr->next;
		cnt++;
	}
	return curr->data;
}
bool list::contains(int n){
	node *curr = head;
	while (curr != NULL){
		if (curr->data == n)
			return true;
		curr = curr->next;
	}
	return false;
}

bool list::remove(int n){
	// we have to differentiate if the node is head, tail or somewhere in the middle
	//empty list
	if (head == NULL)
		return false;
	length --;
	// value to remove is head
	if (head->data == n){
		//check if head is only value in list
		if (head->next == NULL){
			delete head;
			head = NULL;
			tail = NULL;
			return true;
		}
		else{
			node *tmp = head;
			head = head->next;
			delete tmp;
			return true;
		}
	}
	//value is in middle or tail
	node *tmp = head;
	while (tmp->next != NULL){
		node *prev = tmp;
		node *curr = tmp->next;
		if (curr->data == n){
			//check if node to remove is last value
			if (curr->next == NULL){
				tail = prev;
				prev->next = NULL;
				delete curr;
				return true;
			}
			//else value is in the middle
			else {
				prev->next = curr->next;
				delete curr;
				return true;
			}
		}
		tmp = tmp->next;	
	}
	// value was not in list
	length ++;
	return false;
}
int main(int argc, char *argv[]) {
	list l;
	//l.append(5);
	//l.append(9);
	//l.append(36);
	
	//l.prepend(20);
	//l.append(10);
	//l.prepend(30);
	//for (int i=1;i<5;i++) l.append(i);
	//cout << l.contains(21)<<endl;
	//l.print();
//	l.remove(5);
//	l.remove(5);
//	l.print();
//	l.remove(4);
//	l.remove(3);
//	l.print();
//	l.remove(1);
//	l.print();
//	l.remove(2);
//	l.print();
//	l.remove(1);	
	//cout << l.at(1)<<endl;
	//for (int i=0;i<l.length;i++)
	//		cout << i<<":"<<l.at(i)<<endl;
	l.append(1);
	l.append(2);
	l.append(3);
	l.print();
	l.reverse();
	l.print();
		
}
