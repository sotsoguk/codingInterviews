#include <iostream>

using namespace std;

struct node
{
	int key;
	node *left;
	node *right;
};

class btree
{
	public:
		btree();
		~btree();
		
		void insert(int key);
		bool search(int key);
		void destroy_tree();
		void printInorder();
		void printPostorder();
		void printPreorder();
		int	 getHeight();
		bool isSearchTree();
		int numNodes = 0;
		void mirror();
		
	private:
		void destroy_tree(node *leaf);
		void insert(int key, node *leaf);
		bool search(int key, node *leaf);
		node *newNode(int key);
		node *root;
		void printInorder(node *leaf);
		void printPostorder(node *leaf);
		void printPreorder(node *leaf);
		int  getHeight(node *leaf);
		bool isSearchTree(node* leaf, int min, int max);
		void mirror(node* leaf);
		
};

btree::btree()
{
	root = NULL;
}

btree::~btree()
{
	destroy_tree();
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

void btree::destroy_tree(node *leaf)
{
	destroy_tree(leaf->left);
	destroy_tree(leaf->right);
	delete leaf;
}

node *btree::newNode(int key)
{
	node* n = new(struct node);
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void btree::insert(int key){
	if (root != NULL)
	{
		insert(key, root);
	}
	else {
		root = newNode(key);
		
	}
	numNodes++;
}

void btree::insert(int key, node *leaf){
	if (key <= leaf->key){
		if (leaf->left != NULL){
			insert(key, leaf->left);
		}
		else {
			leaf->left = newNode(key);
		}
	}
	if (key > leaf->key){
		if (leaf->right != NULL){
			insert(key, leaf->right);
		}
		else {
			leaf->right = newNode(key);
		}
	}
}

void btree::printInorder(){
	printInorder(root);
	std::cout << std::endl;
}
void btree::printPostorder(){
	printPostorder(root);
	std::cout << std::endl;
}

void btree::printPreorder(){
	printPreorder(root);
	std::cout << std::endl;
}
void btree::printInorder(node *leaf){
	if (leaf == NULL)
		return;
	else {
		printInorder(leaf->left);
		std::cout << leaf->key << " ";
		printInorder(leaf->right);
	}
}
void btree::printPreorder(node *leaf){
	if (leaf == NULL)
		return;
	else {
		std::cout << leaf->key << " ";
		printPreorder(leaf->left);
		printPreorder(leaf->right);
	}
}
void btree::printPostorder(node *leaf){
	if (leaf == NULL)
		return;
	else {
		printPostorder(leaf->left);
		printPostorder(leaf->right);
		std::cout << leaf->key << " ";
	}
}
int btree::getHeight(){
	return getHeight(root);
}

int btree::getHeight(node *leaf){
	if (leaf == NULL)
		return 0;
	else {
		return max(getHeight(leaf->left), getHeight(leaf->right)) + 1;
	}
}

bool btree::search(int key){
	return search(key, root);
}

bool btree::search(int key, node *leaf){
	if (leaf == NULL)
		return false;
	else {
		if (leaf->key == key)
			return true;
		else {
			if (key < leaf->key)
				return search(key, leaf->left);
			else {
				return search(key, leaf->right);
			}
		}
	}	
}

bool btree::isSearchTree(){
	return isSearchTree(root, INT_MIN, INT_MAX);
}
bool btree::isSearchTree(node *leaf, int min, int max){
	// base case is a search tree
	if (leaf == NULL)
		return true;
	else {
		// check if current node fulfills min / max property
		if (leaf->key <= min || leaf->key > max)
			return false;
		// check left tree
		if (!(isSearchTree(leaf->left, min, leaf->key) ))
			return false;
		// check right tree
		if (!(isSearchTree(leaf->right, leaf->key, max)))
			return false;
		
		return true;
	}
}

void btree::mirror(){
	mirror(root);
}

void btree::mirror(node *leaf){
	if (leaf == NULL)
		return;
	else {
		//mirror left subtree
		mirror(leaf->left);
		mirror(leaf->right);
		node *tmp = leaf->left;
		leaf->left = leaf->right;
		leaf->right = tmp;
		
	}
}
int main(int argc, char *argv[]) {
	btree* tree = new btree();	
	int numVals = 10;
	int vals[] = {9,1,0,5,3,2,6,7,4,8};
	for (int i=0;i<numVals;++i)
		tree->insert(vals[i]);
	tree->printInorder();
	tree->printPostorder();
	tree->printPreorder();
	std::cout <<" Height of Tree: " << tree->getHeight() << std::endl;
	std::cout <<tree->search(3)<<", "<< tree->search(8)<<","<<tree->search(11)<<endl;
	std::cout <<"Is Tree Search Tree?" << tree->isSearchTree()<<endl;
	tree->mirror();
	tree->printInorder();
	cout << tree->isSearchTree()<<endl;
	tree->mirror();
	tree->printInorder();
	cout << tree->isSearchTree()<<endl;
}

