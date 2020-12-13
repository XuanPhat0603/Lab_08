#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;
struct TreeNode 
{
	int m_data;
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode(int data) : TreeNode(data, NULL, NULL) {}
	TreeNode(int data, TreeNode* l, TreeNode* r)
	:m_data(data), m_left(l), m_right(r) {}
};
class BSTree
{
private:
	TreeNode* m_root;
	TreeNode* findKey(TreeNode*, int);
	void addKey(TreeNode*&, int);
	void removeKey(TreeNode*&, int);
	void replace(TreeNode*&, int);
	TreeNode* findLeftMost(TreeNode*);
	void visit(TreeNode*);
	void deleteBST(TreeNode*&);
	void deleteNodeOdd(TreeNode*&);
	void printMinMax(TreeNode*, vector<int>&);
	TreeNode* _predecessor(TreeNode*);
	TreeNode* _successor(TreeNode*);
	int countFind(TreeNode*, int, int);
public:
	TreeNode* getRoot();
	BSTree();
	~BSTree();
	bool isEmpty();
	TreeNode* findKey(int);
	void addKey(int);
	void removeKey(int);
	void visit();
	void visitBFS();
	void sumEachLevel();
	void maxMinEachLevel();
	TreeNode* findLeftMost();
	void deleteNodeOdd();
	void printMinMax();
	TreeNode* predecessor(TreeNode*);
	TreeNode* successor(TreeNode*);
	int countFind(int);
};

