#include <iostream>
#include <queue>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int val) { data = val; }
};

std::queue<Node *> q;

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

Node *usingDataGetParent(int checkData)
{
	std::queue<Node *> temp(q);
	while (!temp.empty())
	{
		if (temp.front()->data == checkData)
		{
			return temp.front();
		}
		else
		{
			temp.pop();
		}
	}
	return NULL;
}

int main()
{
	bool check = true;
	char answer = 'y';
	int checkParent;
	int data;
	struct Node *root = new Node(10);

	q.push(root);
	while (check)
	{
		std::cout << "Do you want to add a node?    :";
		std::cin >> answer;
		if (answer == 'y')
		{
			std::cout << "Do you want left or right?     :";
			std::cin >> answer;
			if (answer == 'l')
			{
				std::cout << "Enter the data: ";
				std::cin >> data;
				std::cout << "After which data node, you want to add this? : ";
				std::cin >> checkParent;
				if (usingDataGetParent(checkParent) != NULL)
				{
					usingDataGetParent(checkParent)->left = CreateNode(data);
					q.push(usingDataGetParent(checkParent)->left);
					std::cout << "Data moved under the parent : " << usingDataGetParent(checkParent) << "\n";
				}
				else
				{
					std::cout << "Sorry!, no such data node found";
				}
			}
			else
			{
				std::cout << "Enter the data: ";
				std::cin >> data;
				std::cout << "After which data node, you want to add this? : ";
				std::cin >> checkParent;
				if (usingDataGetParent(checkParent) != NULL)
				{
					usingDataGetParent(checkParent)->right = CreateNode(data);
					q.push(usingDataGetParent(checkParent)->right);
					std::cout << "Data moved under the parent : " << usingDataGetParent(checkParent) << "\n";
				}
				else
				{
					std::cout << "Sorry!, no such data node found";
				}
			}
		}
		std::cout << "Do you want to continue? ";
		std::cin >> answer;
		if (answer == 'n')
			check = false;
	}
	std::cout << " Data structure:" << std::endl;
	inorder(root);
}
