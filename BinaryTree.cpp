#include<iostream>

struct Node 
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int val) {data = val;}
};

Node* CreateNode(int data)
{
	Node *root = new Node(data);
	root -> left = NULL;
	root -> right = NULL;
	return root;
}

void inorder(Node* root)
{
	if (root == NULL) return;
	inorder(root -> left);
	std::cout << "Data : " << root -> data << std::endl;
	inorder(root -> right);
}

int main()
{
	struct Node *root = new Node(10);
	root -> left = CreateNode(20);
	root -> right = CreateNode(30);
	root -> left -> left = CreateNode(40);
	root -> right -> right = CreateNode(50);

	inorder(root);
	
	return 0;
}	


