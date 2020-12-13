#include "BSTree.h"
TreeNode* BSTree::findKey(TreeNode* n, int key) 
{
	if (!n)
		return NULL;
	if (key < n->m_data)
		return findKey(n->m_left, key);
	if (key > n->m_data)
		return findKey(n->m_right, key);
	return n;
}
void BSTree::addKey(TreeNode*& n, int key)
{
	if (!n) 
	{
		n = new TreeNode(key);
		return;
	}
	if (key < n->m_data)
		addKey(n->m_left, key);
	else if (key >= n->m_data)
		addKey(n->m_right, key);
}
void BSTree::deleteBST(TreeNode*& n) 
{
	if (n == NULL)
		return;
	deleteBST(n->m_left);
	deleteBST(n->m_right);
	delete n;
}
void BSTree::removeKey(TreeNode*& n, int key)
{
	if (!n) 
		return;
	if (key < n->m_data)
		removeKey(n->m_left, key);
	else if (key > n->m_data)
		removeKey(n->m_right, key);
	else 
		replace(n, key);
}
void BSTree::replace(TreeNode*& n, int key)
{
	if (!n->m_left) 
	{
		TreeNode* rep = n->m_right;
		delete n;;
		n = rep;
	}
	else if (!n->m_right) 
	{
		TreeNode* rep = n->m_left;
		delete n;
		n = rep;
	}
	else
	{ 
		TreeNode* rep = findLeftMost(n->m_right);
		swap(n->m_data, rep->m_data);
		removeKey(n->m_right, key);
	}
}
TreeNode* BSTree::findLeftMost(TreeNode* n)
{
	if (n->m_left)
		return findLeftMost(n->m_left);
	return n;
}
void BSTree::visit(TreeNode* n)
{
	if (n) 
	{
		visit(n->m_left);
		cout << n->m_data << " ";
		visit(n->m_right);
	}
}
BSTree::BSTree()
{
	m_root = NULL;
}
BSTree::~BSTree() 
{
	deleteBST(m_root);
	m_root = NULL;
}
bool BSTree::isEmpty()
{
	return m_root == NULL;
}
void BSTree::addKey(int key)
{
	addKey(m_root, key);
}
TreeNode* BSTree::findKey(int key)
{
	return findKey(m_root, key);
}
void BSTree::removeKey(int key)
{
	removeKey(m_root, key);
}
void BSTree::visit() 
{
	visit(m_root);
}
TreeNode* BSTree::findLeftMost() 
{
	return findLeftMost(m_root->m_right);
}
void BSTree::visitBFS()
{
	if (!m_root)
		return;
	queue<TreeNode*> q;
	TreeNode* node = m_root;
	int level = 0;
	q.push(node);
	while (!q.empty()) 
	{
		int size = q.size();
		cout << "Level: " << ++level << " => ";
		while (size--)
		{
			TreeNode* n = q.front();
			q.pop();
			cout << n->m_data << " ";
			if (n->m_left)
				q.push(n->m_left);
			if (n->m_right)
				q.push(n->m_right);
		}
		cout << endl;
	}
}
void BSTree::sumEachLevel() 
{
	if (m_root == NULL)
		return;
	int sum = 0;
	queue<TreeNode*> q;
	TreeNode* node = m_root;
	int level = 0;
	q.push(node);
	while (!q.empty()) 
	{
		int size = q.size();
		cout << "Sum each level: " << setw(2) << ++level << " => ";
		while (size--) 
		{
			TreeNode* n = q.front();
			q.pop();
			sum += n->m_data;
			if (n->m_left)
				q.push(n->m_left);
			if (n->m_right)
				q.push(n->m_right);
		}
		cout << setw(1) << sum << "\n";
		sum = 0;
	}
}
void BSTree::maxMinEachLevel() 
{
	if (m_root == NULL)
		return;
	queue<TreeNode*> q;
	TreeNode* node = m_root;
	int level = 0;
	int max = 0;
	q.push(node);
	while (!q.empty()) 
	{
		int size = q.size();
		int min = q.front()->m_data;
		while (size--)
		{
			TreeNode* n = q.front();
			max = n->m_data;
			q.pop();
			if (n->m_left)
				q.push(n->m_left);
			if (n->m_right)
				q.push(n->m_right);
		}
		cout << "Level: " << setw(2) << ++level << " => MIN: " << setw(3) << min << " - MAX " << max << "\n";
	}
}
void BSTree::deleteNodeOdd() 
{
	deleteNodeOdd(m_root);
}
void BSTree::deleteNodeOdd(TreeNode*& n)
{
	if (!n)
		return;

	if (n->m_data % 2 == 1)
	{
		removeKey(n, n->m_data);
		deleteNodeOdd(m_root);
	}
	else {
		deleteNodeOdd(n->m_left);
		deleteNodeOdd(n->m_right);
	}
}
void BSTree::printMinMax()
{
	vector<int> v;
	printMinMax(m_root, v);
	int index = v.size() - 1;
	int i = 0;
	while (i < index)
		cout << v[i++] << " " << v[index--] << " ";
	if (i == index)
		cout << v[i] << endl;
}
void BSTree::printMinMax(TreeNode* n, vector<int>& v)
{

	if (!n)
		return;
	printMinMax(n->m_left, v);
	v.push_back(n->m_data);
	printMinMax(n->m_right, v);
}
TreeNode* BSTree::predecessor(TreeNode* n)
{
	if (!n->m_left)
		return n;
	return _predecessor(n->m_left);
}
TreeNode* BSTree::_predecessor(TreeNode* n)
{
	if (!n->m_right)
		return n;
	_predecessor(n->m_right);
}
TreeNode* BSTree::successor(TreeNode* n)
{
	if (!n->m_right)
		return n;
	return _successor(n->m_right);
}
TreeNode* BSTree::_successor(TreeNode* n)
{
	if (!n->m_left)
		return n;
	_successor(n->m_left);
}
TreeNode* BSTree::getRoot()
{
	return m_root;
}
int BSTree::countFind(TreeNode* n, int key, int count)
{
	count++;
	if (n == NULL)
		return count;
	if (key < n->m_data)
		return countFind(n->m_left, key, count);
	if (key > n->m_data)
		return countFind(n->m_right, key, count);
	return count;
}
int BSTree::countFind(int key)
{
	return countFind(m_root, key, 0);
}
