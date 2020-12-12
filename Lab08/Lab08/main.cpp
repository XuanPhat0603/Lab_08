#include "BSTree.h"
#include <fstream>
int main()
{
	int x;
	BSTree a, b;
	fstream in1, in2;
	in1.open("data_bst.bin", ios::in | ios::binary);
	in2.open("data_bst_search.bin", ios::in | ios::binary);
	/*while (!in1.eof())
	{
		in1.read((char*)&x, sizeof(x));
		a.addKey(x);
	}*/
	/*while (!in2.eof()) {
		in2.read((char*)&x, sizeof(x));
		b.addKey(x);
	}*/
	//b.visitBFS();
	a.addKey(50);
	a.addKey(30);
	a.addKey(20);
	a.addKey(40);
	a.addKey(70);
	a.addKey(60);
	a.addKey(80);
	a.addKey(45);
	cout << a.successor(a.getRoot()->m_right->m_right)->m_data << endl;
	//	cout << a.successor(50)->m_data;
		//cout << a.successor(a.node()->m_right)->m_data;
		//a.visit();
	//	a.visitBFS();
		//a.printMinMax();
		//a.sumEachLevel();
		//a.maxMinEachLevel();
		//a.deleteNodeOdd();
	//	a.visitBFS();
		//a.removeKey(871);
		//a.sumEachLevel();
	return 0;
}