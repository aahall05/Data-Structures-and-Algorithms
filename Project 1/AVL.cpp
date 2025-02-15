// Austin Hall
// 90207943

#include "AVL.h"
#include <regex>


/* MUTATORS */
void AVLTree::insert(std::string name, std::string ufid)
{
	if (!inTree(ufid)) {
		if (nameIsValid(name) && ufidIsValid(ufid)) {
			// if the tree is empty, create a new node and set it as the root
			if (this->root == nullptr)
				this->root = new Node(name, ufid);
			else
				this->root = insertHelper(this->root, name, ufid);

			std::cout << "successful" << std::endl;
		}
	}
	else {
		std::cout << "unsuccessful" << std::endl;
	
	}
	
	
}

Node* AVLTree::insertHelper(Node* node, std::string name, std::string ufid)
{
	// if the node is null, create a new node with name and ufid
	if (node == nullptr) {
		return new Node(name, ufid);
	}
	// if ufid is already in the tree, print unsuccessful and return nullptr
	else if (ufid.compare(node->ufid) == 0) {
		std::cout << "unsuccessful" << std::endl;
		return nullptr;
	}
	// if the ufid is less than the current node's ufid, go left
	else if (ufid.compare(node->ufid) < 0) {
		node->left = insertHelper(node->left, name, ufid);
	}
	// else the ufid is greater than the current node's ufid, go right
	else {
		node->right = insertHelper(node->right, name, ufid);
	}

	int balFactor = getHeight(node->left) - getHeight(node->right);
	
	//check for imbalance
	if(balFactor < -1 || balFactor > 1) {
		node = balance(node, balFactor);
	}

	return node;
}

void AVLTree::remove(std::string ufid)
{
	// if the ufid is in the tree, start traversal
	if (searchHelper(this->root, ufid, false, false) != nullptr) {
		bool wasRemoved = removeHelper(this->root, ufid) != nullptr;
		if (wasRemoved) {
			std::cout << "successful" << std::endl;
		}
		else {
			std::cout << "unsuccessful" << std::endl;
		}
	}
	else
		std::cout << "unsuccessful" << std::endl;
	
}

Node* AVLTree::removeHelper(Node* node, std::string ufid)
{
	
	// if the current node is null, return nullptr
	if (node == nullptr) {
		return nullptr;
	}
	// if the ufid matches node's ufid, remove node
	else if (ufid.compare(node->ufid) == 0) {

		// if node has 2 children, find the inorder successor
		if (node->left != nullptr && node->right != nullptr) {
			// copy the inorder successor's data to the current node
			Node* successor = inorderSuccessor(node->right);
			node->name = successor->name;
			node->ufid = successor->ufid;
			node->right = removeHelper(node->right, successor->ufid);


			//delete successor;
		}
		// Node with only one child or no child
		else {
			Node* temp = node;
			if (node->left == nullptr) {
				node = node->right; // Can be nullptr if no right child
			}
			else if (node->right == nullptr) {
				node = node->left; // Can be nullptr if no left child
			}
			delete temp;
		}

	}
	// else if the ufid is less than the current node's ufid, go left
	else if (ufid.compare(node->ufid) < 0) {
		node->left = removeHelper(node->left, ufid);
	}
	// else go right
	else
	{
		node->right = removeHelper(node->right, ufid);
	}



	return node;
	
}

Node* AVLTree::inorderSuccessor(Node* node)
{
	// if the current node is not null, go left until the left child is null
	if (node != nullptr) {
		if (node->left != nullptr) {
			return inorderSuccessor(node->left);
		}
		else {
			return node;
		}
	}
	return nullptr;
}

Node* AVLTree::balance(Node* node, int balFactor)
{
	
	if (balFactor > 1) {
		// Left heavy
		if (getHeight(node->left->left) >= getHeight(node->left->right)) {
			// Left-Left Case
			return rotateRight(node);
		}
		else {
			// Left-Right Case
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}
	}
	else if (balFactor < -1) {
		// Right heavy
		if (getHeight(node->right->right) >= getHeight(node->right->left)) {
			// Right-Right Case
			return rotateLeft(node);
		}
		else {
			// Right-Left Case
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}
	}
	// Node is balanced
	return node;
}

void AVLTree::printInorderHelper(Node* node, int& counter)
{
	// left, root, right
	
	if (node != nullptr) {
		if (node->left != nullptr) {
			printInorderHelper(node->left, counter);
		}

		std::cout << node->name;
		counter++;
		// dont print comma if the current node is the last node
		if (counter != size(this->root)) {
			std::cout << ", ";
		}

		if (node->right != nullptr) {
			printInorderHelper(node->right,	counter);
		}
	}
}

void AVLTree::printPreorderHelper(Node* node)
{
	// root, left, right

	// static counter used to print commas
	static int counter = 0;
	if (node != nullptr) {
		std::cout << node->name;
		counter++;
		// dont print comma if the current node is the last node
		if (counter != size(this->root)) {
			std::cout << ", ";
		}

		if (node->left != nullptr) {
			printPreorderHelper(node->left);
		}
		if (node->right != nullptr) {
			printPreorderHelper(node->right);
		}
	}
}

void AVLTree::printPostorderHelper(Node* node)
{
	// left, right, root

	// static counter used to print commas
	static int counter = 0;
	if (node != nullptr) {
		if (node->left != nullptr) {
			printPostorderHelper(node->left);
		}
		if (node->right != nullptr) {
			printPostorderHelper(node->right);
		}

		std::cout << node->name;
		counter++;
		// dont print comma if the current node is the last node
		if (counter != size(this->root)) {
			std::cout << ", ";
		}
	}
}

void AVLTree::removeInorderHelper(Node* node, int& n, int& counter)
{
	// Visit each node using inorder traversal

	// visit the very left node first
	if (node != nullptr) {
		if (node->left != nullptr) {
			removeInorderHelper(node->left, n, counter);
		}
		
		

		// If the next node (using inorder traversal is node->right) is the one 
		// to be removed, call removeHelper and update parent
		if (n == counter + 1) {
			node->right = removeHelper(node->right, node->right->ufid);
			//if removal of the next node was successful, print successful
			if (node->right == nullptr) {
				std::cout << "successful" << std::endl;
			}
		}
		// Increment counter 
		counter++;
		
		if (node->right != nullptr) {
			removeInorderHelper(node->right, n, counter);
		}
	}
}

void AVLTree::removeInorder(int n)
{
	if (this->root != nullptr && n > 0) {
		int counter = 0;
		removeInorderHelper(this->root, n, counter);

		// if the whole tree was traversed and counter is less than n, print unsuccessful
		if (counter < n) {
			std::cout << "unsuccessful" << std::endl;
		}
	}
	else
		std::cout << "unsuccessful" << std::endl;
}


/* ACCESSORS */
void AVLTree::search(std::string input) {
	// if search is called from main, then print the name/ufid

	Node* result = nullptr;
	if (isdigit(input[0])) {
		result = searchHelper(this->root, input, false, true);
	}
	else{
		result = searchHelper(this->root, input, true, true);
	}
	if(result == nullptr)
		std::cout << "unsuccessful" << std::endl;
}

Node* AVLTree::searchHelper(Node* node, std::string input, bool isName, bool print)
{
	if (node != nullptr) {
		if (isName) {
			// Check root for name or ufid match
			if (input.compare(node->name) == 0) {
				if (print)
					std::cout << node->ufid << std::endl;
				return node;
			}

			// Continue searching the left and right subtrees
			Node* result = nullptr;

			if(node->left != nullptr)
				result = searchHelper(node->left, input, isName, print);
			if(node->right != nullptr)
				result = searchHelper(node->right, input, isName, print);
		
			return result;
		}
		else {
			// perform binary search by ufid
			if (input.compare(node->ufid) == 0) {
				if (print)
					std::cout << node->name << std::endl;
				return node;
			}
			else if (input.compare(node->ufid) < 0) {
				return searchHelper(node->left, input, isName, print);
			}
			else {
				return searchHelper(node->right, input, isName, print);
			}
		
		}

	}

	return nullptr;
}


void AVLTree::printInorder()
{
	//prints in Left Root Right order
	if (this->root != nullptr) {
		int counter = 0;
		printInorderHelper(this->root, counter);
	}
	std::cout << std::endl;
}

void AVLTree::printPreorder()
{
	//prints in Root Left Right order
	if (this->root != nullptr) {
		printPreorderHelper(this->root);
	}
	std::cout << std::endl;
}

void AVLTree::printPostorder()
{
	//prints in Left Right Root order
	if (this->root != nullptr) {
		printPostorderHelper(this->root);
	}
	std::cout << std::endl;
}

void AVLTree::printLevelCount()
{

	// prints 0 if the head is null
	if (this->root == nullptr) {
		std::cout << 0;
	}
	else {
		std::cout << getHeight(this->root);
	}
	std::cout << std::endl;
}

int AVLTree::getHeight(Node* node)
{
	if (node != nullptr) {
		// if node has no children, return 1
		if (node->left == nullptr && node->right == nullptr) {
			// if the current node HAS a value, but no children, return 1
			return 1;
		}
		else {
			return 1 + std::max(getHeight(node->left), getHeight(node->right));
		}
	}
	else {
		// if the current node IS null, return 0
		return 0;
	}
}

bool AVLTree::inTree(std::string input)
{
	// if the input is a digit, and searchHelper doesn't return null, return true
	if (isdigit(input[0]) && searchHelper(this->root, input, false, false) != nullptr) {
		return true;
	}
	// else, search for name
	else if (searchHelper(this->root, input, true, false) != nullptr){
		return true;
	}

	return false;
}

bool AVLTree::nameIsValid(std::string name)
{
	// regex to check if the name consists of only upper case, lower case, and spaces
	std::regex nameRegex("^[a-zA-Z ]+$");
	bool nameContains = std::regex_match(name, nameRegex);
	
	if (nameContains)
		return true;
	else
		return false;
	
}

bool AVLTree::ufidIsValid(std::string ufid)
{
	// regex to check if the ufid consists of 8 digits exactly
	std::regex ufidRegex("^[0-9]{8}$");
	bool ufidContains = std::regex_match(ufid, ufidRegex);

	if(ufidContains)
		return true;
	else
		return false;
}

int AVLTree::size()
{
	return size(this->root);
}

int AVLTree::size(Node* node)
{
	if (node == nullptr) {
		return 0;
	}
	else {
		return 1 + size(node->left) + size(node->right);
	}
}

Node* AVLTree::rotateRight(Node* node)
{
	Node* x = node->left;
	Node* T2 = x->right;

	// Perform rotation
	x->right = node;
	node->left = T2;

	return x;
}

Node* AVLTree::rotateLeft(Node* node)
{
	Node* x = node->right;
	Node* temp = x->left;

	// Perform rotation
	x->left = node;
	node->right = temp;

	return x;
}



