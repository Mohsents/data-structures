#include <iostream>
using namespace std;

template <class T> class AVLTree {
    private:
        struct Node {
            T data;
            struct Node *left;
            struct Node *rigth;
	    int heigth;
        };

        Node* create_node(T data) {
            Node *new_node = new(struct Node);
            if(new_node == NULL) cout << "Can not create node!";
            new_node -> data = data;
            return new_node;
        }

    public:
        Node *root;

        AVLTree() {
            root = create_node(NULL);
            root -> left = NULL;
            root -> rigth = NULL;
        }

    int getMax(int a, int b) {
	return (a > b) ? a : b;
    }

    int getHeigth(Node *node) {
	if(node == NULL) return 0;
	return node -> heigth;
    }

    int getBalance(Node *node) {
	if(node == NULL) return 0;
	return getHeigth(node -> left) - getHeigth(node -> rigth);
    }

    Node *rightRotate(Node *y) {
	Node *x, *T2;

	x = y -> left;
	T2 = x -> rigth;
	x -> rigth = y;
	y -> left = T2;

    	y -> heigth = max(getHeigth(y -> left), getHeigth(y -> rigth)) + 1;
    	x -> heigth = max(getHeigth(x -> left), getHeigth(x -> rigth)) + 1;

    	return x;
  }

    Node *leftRotate(Node *x) {
	Node *y, *T2;

	y = x -> rigth;
	T2 = y -> left;
	y -> left = x;
	x -> rigth = T2;

    	x -> heigth = max(getHeigth(x -> left), getHeigth(x -> rigth)) + 1;
    	y -> heigth = max(getHeigth(y -> left), getHeigth(y -> rigth)) + 1;

    	return y;
  }

  Node *add(Node *root, int key) {
	if(root == NULL) return create_node(key);

	if(key < root -> data) root -> left = add(root -> left, key);
	else if(key > root -> data) root -> rigth = add(root -> rigth, key);
	else return root;

	root -> heigth = 1 + max(getHeigth(root -> left), getHeigth(root -> rigth));

	int balance = getBalance(root);

	if(balance >= 2 && key < root -> left -> data)
		return rightRotate(root);

	if(balance <= -2 && key > root -> rigth -> data)
		return leftRotate(root);

	if(balance >= 2 && key > root -> left -> data) {
		root -> left = leftRotate(root -> left);
		return rightRotate(root);
        }

	if(balance <= -2 && key < root -> rigth -> data) {
		root -> rigth = rightRotate(root -> rigth);
		return leftRotate(root);
        }

	this -> root = root;
	return root;
  }

  void preorder(Node *root) {
	if(root != NULL) {
		cout << root -> data << " ";
		preorder(root -> left);
		preorder(root -> rigth);
	}
  }

};
