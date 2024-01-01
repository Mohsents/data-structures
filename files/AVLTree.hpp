#include <iostream>
using namespace std;

template <class T> class AVLTree {
    private:
        struct Node {
            T data;
            struct Node *left;
            struct Node *rigth;
	    int height;
        };

        Node* create_node(T data) {
            Node *new_node = new(struct Node);
            if(new_node == NULL) cout << "Can not create node!";
            new_node -> data = data;
	    new_node -> height = 1;
            return new_node;
        }

    public:
        Node *root;

        AVLTree() {
            root = create_node(NULL);
            root -> left = NULL;
            root -> rigth = NULL;
	    root -> height = 1;
        }

    int getMax(int a, int b) {
	return (a > b) ? a : b;
    }

    Node *getMin(Node *root) {
	Node *temp = root;

	while(temp -> left != NULL) {
		temp = temp -> left;
	}
	return temp;
    }

    int getHeight(Node *node) {
	if(node == NULL) return 0;
	return node -> height;
    }

    int getBalance(Node *node) {
	if(node == NULL) return 0;
	return getHeight(node -> left) - getHeight(node -> rigth);
    }

    Node *rigthRotate(Node *y) {
	Node *x, *T2;

	x = y -> left;
	T2 = x -> rigth;
	x -> rigth = y;
	y -> left = T2;

    	y -> height = max(getHeight(y -> left), getHeight(y -> rigth)) + 1;
    	x -> height = max(getHeight(x -> left), getHeight(x -> rigth)) + 1;

    	return x;
  }

    Node *leftRotate(Node *x) {
	Node *y, *T2;

	y = x -> rigth;
	T2 = y -> left;
	y -> left = x;
	x -> rigth = T2;

    	x -> height = max(getHeight(x -> left), getHeight(x -> rigth)) + 1;
    	y -> height = max(getHeight(y -> left), getHeight(y -> rigth)) + 1;

    	return y;
  }

  Node *add(Node *root, int key) {
	if(root == NULL) return create_node(key);

	if(key < root -> data) root -> left = add(root -> left, key);
	else if(key > root -> data) root -> rigth = add(root -> rigth, key);
	else return root;

	root -> height = 1 + getMax(getHeight(root -> left), getHeight(root -> rigth));

	int balance = getBalance(root);

	if(balance >= 2 && key < root -> left -> data)
		return rigthRotate(root);

	if(balance <= -2 && key > root -> rigth -> data)
		return leftRotate(root);

	if(balance >= 2 && key > root -> left -> data) {
		root -> left = leftRotate(root -> left);
		return rigthRotate(root);
        }

	if(balance <= -2 && key < root -> rigth -> data) {
		root -> rigth = rigthRotate(root -> rigth);
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

  Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if ( key < root -> data )
        root -> left = deleteNode(root -> left, key);
    else if( key > root -> data)
        root -> rigth = deleteNode(root -> rigth, key);
    else {
        if((root -> left == NULL) || (root -> rigth == NULL)){
            Node *temp = root -> left ? root -> left : root -> rigth;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else *root = *temp;

            free(temp);
        } else {
            Node *temp = getMin(root -> rigth);
            root -> data = temp -> data;
            root -> rigth = deleteNode(root -> rigth, temp -> data);
        }
    }

    if (root == NULL) return root;

    root -> height = 1 + getMax(getHeight(root -> left), getHeight(root -> rigth));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root -> left) >= 0)
        return rigthRotate(root);

    if (balance > 1 && getBalance(root -> left) < 0) {
        root -> left = leftRotate(root -> left);
        return rigthRotate(root);
    }

    if (balance < -1 && getBalance(root -> rigth) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root -> rigth) > 0) {
        root -> rigth = rigthRotate(root -> rigth);
        return leftRotate(root);
    }

    this -> root = root;
    return root;
    }

};
