#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* create_node(int data){
	node* new_node = new node();
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}
node* insert_data(node* root,int data){
	if(root == NULL){
		root = create_node(data);
	}else if(data <= root->data){
		root->left = insert_data(root->left,data);
	}else{
		root->right = insert_data(root->right,data);
	}
	return root;
}
bool search(node* root,int data){
	if(root == NULL)return false;
	else if(root->data == data)return true;
	else if(data <= root->data)return search(root->left,data);
	else return search(root->right,data);
}

int main(){
	int number;
	node* root = NULL;
	root = insert_data(root,15);
	root = insert_data(root,10);
	root = insert_data(root,20);
	root = insert_data(root,25);
	root = insert_data(root,8);
	root = insert_data(root,12);
	cout<<"Enter number be searche\n";
	cin>>number;
	if(search(root,number) == true)cout<<"Found\n";
	else cout<<"not found";
	return 0;
}

