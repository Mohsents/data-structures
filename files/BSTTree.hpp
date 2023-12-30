#include <iostream>
using namespace std;

template <class T> class BSTTree {
    private:
        struct Node {
            T data;
            struct Node *left;
            struct Node *rigth;
        };

        Node* create_node(T data) {
            Node *new_node = new(struct Node);
            if(new_node == NULL) cout << "Can not create node!";
            new_node -> data = data;
            return new_node;
        }

    public:
        Node *root;

        BSTTree() {
            root = create_node(NULL);
            root -> left = NULL;
            root -> rigth = NULL;
        }

    Node *insert(Node *root, T data) {
	if(root == NULL){
            Node *new_node = create_node(data);
            root = new_node;
	    return root;
    	}

	if(data < root -> data)
	    root -> left = insert(root -> left, data);
	else if(data > root -> data)
	    root -> rigth = insert(root -> rigth, data);

	return root;
    }

    void inorder_travers(Node *root) {
	if(root != NULL) {
	inorder_travers(root -> left);
	cout << root -> data << " ";
	inorder_travers(root -> rigth);
    }
  }

    bool search(Node *root, int key) {
	while(root != NULL) {
		if(key > root -> data) root = root -> rigth;
		else if(key < root -> data) root = root -> left;
		else return true;
        }
	return false;
  }

  Node* find_min(Node *root) {
	Node *temp = root;
	// The most left node is smallest in BSD tree
	while(temp -> left != NULL) temp = temp -> left;
	return temp;
  }

  Node* remove(Node *root, int key) {
	Node *temp;
	if(root == NULL) return root;

	if(key < root -> data)
	root -> left = remove(root -> left, key);
	else if(key > root -> data)
	root -> rigth = remove(root -> rigth, key);
	else {
		if(root -> left == NULL) {
			temp = root -> rigth;
			free(root);
			return temp;
		} else if(root -> rigth == NULL) {
			temp = root -> left;
			free(root);
			return temp;
		}

		temp = find_min(root -> rigth);
		root -> data = temp -> data;
		root -> rigth = remove(root -> rigth, temp -> data);
	}
	return root;
  }

  void nth_largest(Node *root, int n) {
	static int count = 0;
	if(root == NULL || count >= n) return;

	nth_largest(root -> rigth, n);
	count++;
	if(count == n) {
		cout << root -> data;
		return;
	}

	nth_largest(root -> left, n);
  }

};
