#include<iostream>
using namespace std;

class linked_list{
	public:
	int data;
	linked_list* next;
	linked_list(int data,linked_list* next){
		this->data = data;		//or *(this).data = data
		this->next = next;
	}
	static linked_list* create_list();
	void traverse();
	int count();
	void add_node();
}*head = NULL;

linked_list* linked_list::create_list(){
	int no_of_nodes;
	int data;
	linked_list* head;
	cout<<"Enter number of nodes to be created"<<endl;
	cin>>no_of_nodes;
	for(int i=0; i<no_of_nodes;i++){
		cout<<"Enter data"<<endl;
		cin>>data;
		linked_list* temp = new linked_list(data,NULL);
		if(i ==0 ){
			head = temp;
			continue;
		}
		linked_list* p = head;
		while(p->next!= NULL)p =p->next;
		p->next = temp;
	}
	return head;
}
void linked_list::add_node(){
	cout<<"Enter data to be added "<<endl;
	int data,option;
	cin>>data;
	linked_list* temp = new linked_list(data,NULL);
	linked_list* p = ::head;
	cout<<"where you want to insert data"<<endl;
	cout<<"1. begining"<<endl;
	cout<<"2. last "<<endl;
	cout<<"3. at position"<<endl;
	cin>>option;
	if(option == 1){
		temp->data = data;
		temp->next = p;
		::head = temp;
	}else if(option == 2){
		linked_list* temp = new linked_list(data,NULL);
		while(p->next != NULL){
			p = p->next;
		}
		p->next=temp;
	//	::head = p;
	}

}

int linked_list::count(){
	linked_list* temp = ::head;
	int count=0;
	while(temp != NULL){
		count++;
		temp= temp->next;
	}
	return count;
}
void linked_list::traverse(){
	linked_list* temp = ::head;
	while(temp != NULL){
		cout<< temp->data<<"--->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
int main(){
	head = linked_list::create_list();
	head->traverse();
	head->add_node();
	head->traverse();
	cout<<endl;
	cout<<head->count()<<endl;
	return 0;
}
