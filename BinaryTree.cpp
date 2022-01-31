#include <iostream>
#include<queue>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int val) { data = val; }
};

Node *CreateNode(int data)
{
	Node *root = new Node(data);
	root->left = NULL;
	root->right = NULL;
	return root;
}

Node *DeleteNode(Node *nodename)
{
	if (nodename->left == NULL && nodename->right == NULL)
	{
		nodename->data = 0;
		std::cout << " Node deleted successfully";
		return NULL;
	}
	else
		std::cout << "Cannot remove the parent member .." << std::endl;
		return nodename;
}

void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	std::cout << "Data : " << root->data << std::endl;
	inorder(root->right);
}

int main()
{
	bool check = true;
	char answer = 'y';
	int data;
	struct Node *root = new Node(10);
	std::queue<Node *> q;
	q.push(root);
	while(check)
	{
		std::cout << "Do you want to add a node?    :"; std::cin >> answer; if (answer == 'y'){
			std::cout << "Do you want left or right?     :"; std::cin >> answer; if(answer == 'l'){
				std::cout << "Enter the data: " ; std::cin >> data;
				root -> left = CreateNode(data);
				q.push(root -> left);
			}
			else
			{
				std::cout << "Enter the data: " ; std::cin >> data;
				root -> right = CreateNode(data);
				q.push(root -> right);
			}
		}
		std::cout << "Do you want to continue? "; std::cin >> answer; if (answer == 'n') check = false;
	}
	std::cout << " Data structure:" << std::endl;
	for (int i = 0; i < q.size() + 1; i++)
	{
		Node* tempNode = q.front();
		std::cout << tempNode -> left -> data << " <- " << tempNode -> data << " -> " << tempNode -> right -> data << std::endl;
		q.pop();
	}
}
