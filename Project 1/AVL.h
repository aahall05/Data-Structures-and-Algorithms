// Austin Hall
// 90207943

#pragma once
//#ifndef P1DEMO_AVL_H
//#define P1DEMO_AVL_H
#include <iostream>
#include "AVL.h"

struct Node
{
	std::string name;
	std::string ufid;
	Node* left;
	Node* right;
	
	Node(std::string name, std:: string ufid) {
		this->name = name;
		this->ufid = ufid;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class AVLTree {
private:
	Node* root;
	Node* insertHelper(Node* node, std::string name, std::string ufid);
	Node* removeHelper(Node* node, std::string ufid);
	Node* inorderSuccessor(Node* node);
	Node* balance(Node* node, int balFactor);
	Node* searchHelper(Node* node, std::string input, bool isName, bool print);
	void printInorderHelper(Node* node, int& counter);
	void printPreorderHelper(Node* node);
	void printPostorderHelper(Node* node);
	void removeInorderHelper(Node* node, int& n, int& counter);
	int size(Node* node);
	Node* rotateRight(Node* node);
	Node* rotateLeft(Node* node);

public:

	/* TREE MANIPULATION*/
	void insert(std::string name, std::string ufid);
	void remove(std::string ufid);
	void search(std::string input);
	void removeInorder(int n);
	
	/* PRINTING */
	void printInorder();
	void printPreorder();
	void printPostorder();
	void printLevelCount();
	
	/* ACCESSORS */
	int getHeight(Node* node);
	bool inTree(std::string input);
	bool nameIsValid(std::string name);
	bool ufidIsValid(std::string ufid);
	int size();
	 
	/* CONSTRUCTION/DESTRUCTION */
	AVLTree() {
		root = nullptr;
	}

	void deleteTree(Node* node) {
		if (node == nullptr) {
			return;
		}

		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
	~AVLTree() {
		deleteTree(root);
	}
};
//#endif
