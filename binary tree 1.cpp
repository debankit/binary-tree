#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	//children
	Node* left;
	Node* right;
	Node(int value){
		left = NULL;
		right = NULL;
		data = value;
	}
};

class BiST{
	public:
	Node* root;
	//default constructor
	BiST(){
		root = NULL;
	}
	
	void insert(int value){
		 insertHelper(root, value);
	}
	void  insertHelper( Node* curr, int value){
		
		//base case if curr is null, insert there
		if(curr == NULL){
			root= new Node(value);
		}
		//else compare the ddata with value
		else if( value < curr->data){
			// if value<curr data -> move left and call insertHelper
					if(curr->left == NULL)
						curr->left=new Node(value);
					else
						insertHelper(curr->left, value);
		}
		else{
			//else move to right and call insertHelper
			if(curr->right)
				curr->right= new Node(value);
			else
			 	insertHelper(curr->right, value);
		}	
	}
	
	void display(){
		display2(root):
	}
	void display2(Node* curr){
		//base case
		if(curr == NULL) return;
		//dislay left
		display2(curr->left);
		//display current
		cout << curr->data <<",";
		//display right
		display2(curr->right);
	}

	Node* search(int value){
		return search2(root, value);
	}

	Node* search2(Node* curr, int val){
		if(curr->data == val || curr == NULL)
			return curr;
		else if((curr->data)< val)
			return search2(curr->right, val);
		else
			return search2(curr->left,val);
	}	

};

int main(){
	BiST bt1;
	bt1.insert(15);
	bt1.insert(10);
	bt1.insert(20);
	bt1.insert(13);
	bt1.insert(18);
	bt1.insert(5);
	bt1.insert(30);
	bt1.insert(7);
	bt1.insert(28);
	bt1.insert(44);
	bt1.display();
}




