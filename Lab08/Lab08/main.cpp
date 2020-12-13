#include "BSTree.h"
int main()
{
	map<int, vector<int>> list;
	int x;
	BSTree a, b;
	fstream in1, in2;
	in1.open("data_bst.bin", ios::in | ios::binary);
	in2.open("data_bst_search.bin", ios::in | ios::binary);
	while (!in1.eof()) 
	{
		in1.read((char*)&x, sizeof(x));
		a.addKey(x);
		b.addKey(x);
	}

	cout << "\nEX01: \nA. Create Tree: \n";
	a.visit();
	cout << "\n";
	system("pause");
	system("cls");

	cout << "\nB. Sum all the node at each level: \n";
	a.sumEachLevel();
	system("pause");
	system("cls");

	cout << "\nC. Find MAX - MIN each level: \n";
	a.maxMinEachLevel();
	system("pause");
	system("cls");

	cout << "\nD + E. Predecessor - Successor Node: root -> right -> left: \n\n";
	cout << "Predecessor: " << a.successor(a.getRoot()->m_right->m_left)->m_data << "\n";
	cout << "Successor: " << a.predecessor(a.getRoot()->m_right->m_left)->m_data << "\n";
	system("pause");
	system("cls");

	cout << "\nF. Delete Node Odd: \n";
	a.deleteNodeOdd();
	a.visit();
	cout << "\n";
	system("pause");
	system("cls");

	cout << "\nG. Print MIN - MAX: \n";
	a.printMinMax();
	cout << "\n";
	system("pause");
	system("cls");

	cout << "\nEX02: Search Cost: \n";
	while (!in2.eof()) 
	{
		in2.read((char*)&x, sizeof(x));
		list[x].push_back(1);
	}
	for (auto it : list)
		cout << "\nSearch cost : " << setw(3) << it.first << " => " << setw(3) << b.countFind(it.first) * it.second.size();
	return 0;
}

