#include <iostream>
#include <vector>
#include <stack>

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
		void printPreOrderIter();
		int	 getHeight();
		bool isSearchTree();
		int numNodes = 0;
		void mirror();
		bool remove(int key);
		int getMin();
		int getMax();
		void printTree();
		void printLeaves();
		void printInorderIter();
		
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
		node* remove(int key, node *leaf);
		int getMin(node* leaf);
		int getMax(node* leaf);
		void printTree(node *leaf, int level);
		vector<vector<int>> entries;
		void printLeaves(node *leaf);
		
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

void btree::printInorderIter(){
	if (root == NULL){
		return;
	}
	else{
		stack<node*> toPrint;
		node* current = root;
		while (current != NULL || !toPrint.empty()){
			if (current != NULL){
				toPrint.push(current);
				current = current -> left;
			}
			else{
				node* n = toPrint.top();
				cout << n->key<<" ";
				current = n->right;
				toPrint.pop();
			}
		}
		cout <<endl;
		
		
	}
}
void btree::printPreOrderIter(){
	if (root == NULL){
		return;
	}
	else{
		stack<node*> toPrint;
		node* current = root;
		toPrint.push(current);
		while (! toPrint.empty()){
			node* curr = toPrint.top();
			toPrint.pop();
			cout << curr->key<<" ";
			if (curr->right)
				toPrint.push(curr->right);
			if (curr->left)
				toPrint.push(curr->left);
		}
	}
	
}

void btree::printPostOrderIter(){
	if (root == NULL){
		return;
	}
	else{
		stack<node>* toPrint;
		//node* curr = root;
		toPrint.push(root);
		while (! toPrint.empty()){
			node curr* = toPrint.top();
			toPrint.pop();
			if (curr == NULL){
				
			}
			else {
				
			}
		}
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

bool btree::remove(int key){
	cout<<"\nremove(key)";
	root =  remove(key, root);
	return true;
}

node* btree::remove(int key, node *leaf){
	//cout <<"\nremove(node):"<<leaf->key;
	// if key not found and node is leaf key is not found
	if (leaf == NULL){
		//cout<<"NULL";
		return leaf;
	}
	// check if key is node, or in left or right subtree
	else if ( key < leaf->key ){
		//cout <<"l";
		leaf->left = remove(key, leaf->left);
	}
	else if (key > leaf->key) {
		//cout <<"r";
		leaf->right = remove(key, leaf->right);
	}
	// current node has to be deleted
	else {
		//cout <<"ELSE";
		// if node is leaf, just delete node
		if (leaf->left == NULL && leaf->right == NULL){
			//cout<<"delLeaf:"<<leaf->key;
			//delete(leaf);
			leaf = NULL;
			//cout<<"delLeaf:"<<leaf->key;
			
		}
		// if node has only left child, delete node and link to left child
		else if (leaf->left != NULL && leaf->right == NULL){
			//cout <<"!lr\t";
			node *tmp = leaf;
			leaf = leaf->left;
			delete(tmp);
			
		}
		// analogous for only right child
		else if (leaf->left == NULL && leaf->right != NULL){
			//cout <<"l!r\t";
			node *tmp = leaf;
			leaf = leaf->right;
			delete(tmp);
			
		}
		// most complex case, node has 2 children
		else if (leaf->left != NULL && leaf->right != NULL){
			//cout <<"!l!r\t";
			// first, find min of right subtree of node to delete
			int tmpVal = getMin(leaf->right);
			// set current node to min
			leaf->key = tmpVal;
			// now duplicate values, therefore delete the duplicate value in right subtree
			leaf->right = remove(tmpVal,leaf->right);
			
		}
	}
	//cout << "over";
	return leaf;
}

int btree::getMin(){
	return getMin(root);
}
int btree::getMax(){
	return getMax(root);
}

int btree::getMax(node *leaf){
	node *runner = leaf;
	while (runner->right != NULL){
		runner = runner->right;
	}
	return runner->key;
}

int btree::getMin(node *leaf){
	node *runner = leaf;
	while (runner->left != NULL){
		runner = runner->left;
	}
	return runner->key;
}

void btree::printTree(){
	
	int numLevels = this->getHeight();
	entries.assign(numLevels,vector<int>(0));
	printTree(root,0);
	for (auto &i : entries){
		//cout <<"1";
		for (auto &j:i){
			cout << j<<" ";
		}
		cout <<endl;
	}
	
}

void btree::printLeaves(){
	printLeaves(root);
	cout << endl;
}

void btree::printLeaves(node *leaf){
	if (leaf == NULL){
		return;
	}
	else{
		if (leaf->left == NULL && leaf->right == NULL)
			cout << leaf->key<<" ";
		else {
			printLeaves(leaf->left);
			printLeaves(leaf->right);
		}
	}
}
void btree::printTree(node *leaf, int level){
	// recursive function to save all values of one height / level to a vector
	if (leaf == NULL){
		return;
	}
	else {
		entries[level].push_back(leaf->key);
	}
	level ++;
	printTree(leaf->left, level);
	printTree(leaf->right, level);
	return;
}
int main(int argc, char *argv[]) {
	btree* tree = new btree();
	btree* tree2 = new btree();	
	int numVals = 10;
	int vals[] = {9,1,0,5,3,2,6,7,4,8};
	for (int i=0;i<numVals;++i)
		tree->insert(vals[i]);
	tree->printInorder();
	tree->printPostorder();
	tree->printPreorder();
	cout <<"ITER:";tree->printPreOrderIter();
	std::cout <<" Height of Tree: " << tree->getHeight() << std::endl;
	std::cout <<tree->search(3)<<", "<< tree->search(8)<<","<<tree->search(11)<<endl;
	std::cout <<"Is Tree Search Tree?" << tree->isSearchTree()<<endl;
	tree->mirror();
	tree->printInorder();
	cout << tree->isSearchTree()<<endl;
	tree->mirror();
	tree->printInorder();
	cout<<"ITER: ";tree->printInorderIter();
	tree->printPostorder();
	cout << tree->isSearchTree()<<endl;
	cout <<"Min: "<< tree->getMin() <<", Max: "<<tree->getMax()<<endl;
	tree->printTree();
	tree->printLeaves();
	cout <<"Before remove\n";
	tree->remove(8);
	cout <<"After remove\n";
	tree->printInorder();
	tree->printPostorder();
	cout <<"Min: "<< tree->getMin() <<", Max: "<<tree->getMax()<<endl;
	tree->printTree();
	tree->printLeaves();
}

