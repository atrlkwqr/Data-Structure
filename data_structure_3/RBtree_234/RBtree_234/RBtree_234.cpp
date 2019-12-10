#include<iostream>
#include<string>
#define RED true
#define BLACK false

typedef struct treeRecord
{
	int key;
	struct treeRecord* LChild;
	struct treeRecord* RChild;
	bool color;
}node;

typedef node* Nptr;

Nptr CreateNode(int key)
{
	Nptr node = new treeRecord();
	node->key = key;
	node->color = RED;
	node->LChild = NULL;
	node->RChild = NULL;
	return node;
}

void InitRoot(Nptr root)
{
	root->color = BLACK;
}
#define SUCCESS (0)
#define RR_VIOLATE (1)
#define RECONSTRUCT (2)
#define RECOLOR (3)

int RRViolateCheck(Nptr root)
{
	if (root->RChild == NULL || root->RChild->color == BLACK || root->LChild == NULL || root->LChild->color == BLACK)
	{
		return RECONSTRUCT;
	}
	else
	{
		return RECOLOR;
	}
}

int ReconstructTree(Nptr start, int childKey, Nptr root)
{
	bool ppleft = start->key > childKey;
	Nptr pparent = ppleft ? start->LChild : start->RChild;
	bool pleft = pparent->key > childKey;
	Nptr parent = pleft ? pparent->LChild : pparent->RChild;
	bool cleft = parent->key > childKey;
	Nptr child = cleft ? parent->LChild : parent->RChild;
	Nptr newRoot;
	if (pleft && cleft)
	{
		Nptr temp = parent->RChild;
		parent->RChild = pparent;
		pparent->LChild = temp;

		newRoot = parent;
		parent->color = BLACK;
		child->color = RED;
		pparent->color = RED;
	}
	else if (pleft && !cleft)
	{
		Nptr temp = child->LChild;
		child->LChild = parent;
		parent->RChild = temp;

		temp = child->RChild;
		child->RChild = pparent;
		pparent->RChild = temp;

		newRoot = child;
		child->color = BLACK;
		parent->color = RED;
		pparent->color = RED;
	}
	else if (!pleft && cleft)
	{
		Nptr temp = child->LChild;
		child->LChild = pparent;
		pparent->RChild = temp;

		temp = child->RChild;
		child->RChild = parent;
		parent->RChild = temp;

		newRoot = child;
		child->color = BLACK;
		parent->color = RED;
		pparent->color = RED;
	}
	else
	{
		Nptr temp = parent->LChild;
		parent->LChild = pparent;
		pparent->RChild = temp;

		newRoot = parent;
		parent->color = BLACK;
		child->color = RED;
		pparent->color = RED;
	}

	if (ppleft)
	{
		start->LChild = newRoot;
	}
	else
	{
		start->RChild = newRoot;
	}
	if (start == root)
	{
		root->LChild = newRoot;
	}
	return SUCCESS;
}

int RecolorTree(Nptr root, Nptr parent)
{
	parent->LChild->color = BLACK;
	parent->RChild->color = BLACK;
	parent->color = RED;
	if (root->color == RED)
	{
		return RR_VIOLATE;
	}
	else
	{
		return SUCCESS;
	}
}

int InsertNode(Nptr parent, Nptr newNode, Nptr root)
{
	if (parent == NULL)
	{
		root->LChild = newNode;
		newNode->color = BLACK;
		return SUCCESS;
	}

	bool lchild = parent->key > newNode->key;
	Nptr child = lchild ? parent->LChild : parent->RChild;

	if (child == NULL)
	{
		if (lchild)
		{
			parent->LChild = newNode;
		}
		else
		{
			parent->RChild = newNode;
		}
		if (parent->color == RED && newNode->color == RED)
		{
			return RR_VIOLATE;
		}
		else
		{
			return SUCCESS;
		}
	}
	else
	{
		int ret = InsertNode(child, newNode, root);
		if (ret == SUCCESS)
		{
			return ret;
		}
		else if (ret == RR_VIOLATE)
		{
			return RRViolateCheck(parent);
		}
		else if (ret == RECONSTRUCT)
		{
			return ReconstructTree(parent, newNode->key, root);
		}
		else if (ret == RECOLOR)
		{
			return RecolorTree(parent, child);
		}

	}
}

void InsertNodeToRBTree(Nptr root, int value)
{
	Nptr node = CreateNode(value);
	int ret = InsertNode(root->LChild, node, root);
	if (ret == RECONSTRUCT)
	{
		ReconstructTree(root, value, root);
	}
	else if (ret == RECOLOR)
	{
		RecolorTree(root->LChild, root->LChild);
		root->LChild->color = BLACK;
	}
}

void RBPrettyPrint(const std::string prefix, Nptr node, bool isLeft)
{
	if (node != NULL)
	{
		std::cout << prefix;
		if (node->color == RED) std::cout << (isLeft ? " " : "       ");
		else std::cout << (isLeft ? "曳收收" : "曲收收");

		std::cout << " " << node->key;
		if (node->color == RED) std::cout << "*";
		std::cout << std::endl;

		RBPrettyPrint(prefix + (isLeft ? "早 " : " "), node->LChild, true);
		RBPrettyPrint(prefix + (isLeft ? "早 " : " "), node->RChild, false);
	}
}

void RightRotation(Nptr root, bool isLeftChild)
{
	Nptr parent = isLeftChild ? root->LChild : root->RChild;
	Nptr lchild = parent->LChild;
	Nptr rchild = parent->RChild;
	Nptr temp = lchild->RChild;
	lchild->RChild = parent;
	parent->LChild = temp;
	if (isLeftChild)
	{
		root->LChild = lchild;
	}
	else
	{
		root->RChild = lchild;
	}
}
void LeftRotation(Nptr root, bool isLeftChild)
{
	Nptr parent = isLeftChild ? root->LChild : root->RChild;
	Nptr lchild = parent->LChild;
	Nptr rchild = parent->RChild;
	Nptr temp = rchild->LChild;
	rchild->LChild = parent;
	parent->RChild = temp;
	if (isLeftChild)
	{
		root->LChild = rchild;
	}
	else
	{
		root->RChild = rchild;
	}
}

void RemoveNode(Nptr parent, Nptr child, bool left)
{
	if (child->LChild == NULL)
	{
		if (left)
		{
			parent->LChild = child->RChild;
		}
		else
		{
			parent->RChild = child->RChild;
		}
	}
	else
	{
		Nptr newChild = child->LChild;
		Nptr newChildParent = child;
		while (newChild->RChild != NULL)
		{
			newChild = newChild->RChild;
			newChildParent = newChildParent->RChild;
		}
		if (left)
		{
			parent->LChild = newChild;
		}
		else
		{
			parent->RChild = child->RChild;
		}
		newChild->RChild = child->RChild;

		delete child;
	}
}

#define RED_NODE_DELETE (1)
#define DOUBLE_BLACK_DELETE (2)
#define LEFT_ROTATION (3)
#define DOUBLE_BLACK_DETECT (4)
int DeleteNode(Nptr node, int value)
{
	if (node->key == value)
	{
		if (node->color == RED)
		{
			return RED_NODE_DELETE;
		}
		else {
			return DOUBLE_BLACK_DELETE;
		}
	}
	else
	{
		bool left = node->key < value;
		int ret = DeleteNode(left ? node->LChild : node->RChild, value);
		if (ret == SUCCESS)
		{
			return ret;
		}
		else if (ret == RED_NODE_DELETE)
		{
			Nptr child = left ? node->LChild : node->RChild;
			RemoveNode(node, child, left);
			child = left ? node->LChild : node->RChild;
			child->color = BLACK;
			return SUCCESS;
		}
		else if (ret == LEFT_ROTATION)
		{
			LeftRotation(node, node->key < value);
			if (node->color == BLACK && (left ? node->LChild : node->RChild)->color == BLACK)
			{
				return DOUBLE_BLACK_DETECT;
			}
			else
			{
				return SUCCESS;
			}
		}
		else if (ret == DOUBLE_BLACK_DETECT)
		{

		}
		else if (ret == DOUBLE_BLACK_DELETE)
		{
			Nptr child = left ? node->LChild : node->RChild;
			RemoveNode(node, child, left);
			Nptr sibling = left ? node->RChild : node->LChild;
			if (sibling->color == RED)
			{
				sibling->color = BLACK;
				node->color = RED;
				return LEFT_ROTATION;
			}
			else
			{
				bool lChildColor = (sibling->LChild == NULL || sibling->LChild->color == BLACK) ? BLACK : RED;
				bool rChildColor = (sibling->RChild == NULL || sibling->RChild->color == BLACK) ? BLACK : RED;
				if (rChildColor == RED)
				{
					sibling->color = node->color;
					node->RChild->color = BLACK;
					if (sibling->RChild != NULL)
						sibling->RChild->color = BLACK;
					return LEFT_ROTATION;
				}
				if (sibling->LChild->color == RED && sibling->RChild->color == BLACK)
				{

				}
				if (lChildColor&& sibling->LChild->color == BLACK)
				{

				}
			}
		}
	}
}
void DeleteNodeInRBTree(Nptr root, int value)
{
	int ret = DeleteNode(root->LChild, value);
}


int main()
{
	Nptr tree = CreateNode(100000);
	InsertNodeToRBTree(tree, 10);
	InsertNodeToRBTree(tree, 20);
	InsertNodeToRBTree(tree, 30);
	InsertNodeToRBTree(tree, 40);
	InsertNodeToRBTree(tree, 50);
	InsertNodeToRBTree(tree, 60);
	InsertNodeToRBTree(tree, 70);
	InsertNodeToRBTree(tree, 80);
	InsertNodeToRBTree(tree, 90);
	InsertNodeToRBTree(tree, 100);
	RBPrettyPrint("", tree->LChild, false);
	std::cout << std::endl;


	return 0;
}