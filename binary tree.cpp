#include <iostream>
using namespace std;
class BSTree {
public:
	struct wezel {
		int val;
		wezel *lewy, *prawy, *parent;
	};
	wezel* root;

	BSTree() { root = NULL; }
	void isEmpty();
	void addBST(int v);
	void searchBST(int v);
	void printBST(wezel* n);
	void deleteWezel (int v);

	//~BSTree();
};
int main()
{

	BSTree tree = BSTree();
	tree.addBST(15);
	tree.addBST(18);
	tree.addBST(25);
	tree.addBST(8);
	tree.addBST(5);
    tree.addBST(9);
	tree.addBST(17);
	//tree.printBST(tree.root);
	//tree.searchBST(170);
	//tree.isEmpty();
	tree.deleteWezel(18);
	tree.deleteWezel(25);
	tree.deleteWezel(5);
	tree.deleteWezel(9);
	tree.searchBST(19);
	tree.printBST(tree.root);
	tree.addBST(25);
	 tree.addBST(9);
	tree.printBST(tree.root);

}

void BSTree::addBST(int v)
{

	if (root == NULL)
	{
		root = new wezel;
		root->val = v;
		root->prawy = NULL;
		root->lewy = NULL;
		root->parent = NULL;
		cout << "tworze root" << endl;
	}
	else
	{
		wezel* exist = root;

		while (exist != NULL)
		{

			if (v > exist->val)
			{

				if (exist->prawy != NULL)
				{
					exist = exist->prawy;

				}

				else
				{
					wezel* nowy = new wezel;
					nowy->val = v;
					//root->prawy = nowy;
					nowy->prawy = NULL;
					nowy->lewy = NULL;
					nowy->parent = exist;
					exist->prawy = nowy;
					cout << "tworze prawy" << endl;
					break;

				}



			}
			else
			{
				if (exist->lewy != NULL)
					exist = exist->lewy;
				else
				{
					wezel* nowy = new wezel;
					nowy->val = v;
					nowy->lewy = NULL;
					nowy->prawy = NULL;
					nowy->parent = exist;
					exist->lewy = nowy;
					cout << "tworze lewy" << endl;
					break;

				}
			}
		}



	}
}

void BSTree::printBST(wezel* n)
{

	if (n != NULL)
	{
		printBST(n->lewy);
		cout << n->val <<endl;
		printBST(n->prawy);
	}







}
void BSTree::searchBST(int v)
{
	if (v == root->val)
	{
		cout << "YES"<<endl;
	}
	else
    {
	    wezel* biezacy = root;

		while (v != biezacy->val)
		{

			if (v > biezacy->val)
			{
				if (biezacy->prawy == NULL)
				{
					cout << "NO"<<endl;
					break;
				}
				else

				biezacy = biezacy->prawy;
				if(biezacy->val==v)
                {

                    cout<<"yes";
                }


			}
			else if (v < biezacy->val)
			{
				if (biezacy->lewy == NULL)
				{
					cout << "NO"<<endl;
					break;
				}
				else
				biezacy = biezacy->lewy;
				if(biezacy->val==v)
                {

                    cout<<"yes"<<endl;
                }


			}

		}


	}
}


void BSTree::isEmpty()
{


    if(root==NULL)
    {

        cout<<"yes"<<endl;
    }
    else
        cout<<"no"<<endl;
}
void BSTree::deleteWezel(int v)
{
    if (v == root->val)
	{
      root->val==NULL;
	}

	else
    {
	    wezel* biezacy = root;

		while (v != biezacy->val)
		{

			if (v > biezacy->val)
			{
				biezacy = biezacy->prawy;

			}
			else if (v < biezacy->val)
			{

				biezacy = biezacy->lewy;
			}

		}
biezacy->val=NULL;
biezacy=NULL;


	}

}
