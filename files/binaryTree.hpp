#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

template <class T> class BinaryTree {
    private:
        struct Node {
            T data;
	    bool rigthThread;
            struct Node *left;
            struct Node *rigth;
        }*pos;

        Node* create_node(T data) {
            Node *new_node = new(struct Node);
            if(new_node == NULL) cout << "Can not create node!";
            new_node -> data = data;
            return new_node;
        }

    public:
        Node *root;

        BinaryTree() {
            root = create_node(NULL);
            pos = create_node(NULL);
            root -> left = NULL;
            root -> rigth = NULL;
            pos = root;
        }

    void create_tree(T root_data) {
        Node *new_node = create_node(root_data);
        root = new_node;
        new_node -> left = create_node(2);
        new_node -> rigth = create_node(3);
        new_node -> left -> left = create_node(4);
        new_node -> left -> rigth = create_node(5);
        new_node -> left -> left -> left = create_node(6);
        new_node -> left -> left -> rigth = create_node(7);
    }

    int get_height(Node *pos) {
        int left_heigth, rigth_heigth;

        if(pos == NULL) {
            return 0;
        } else {
            left_heigth = get_height(pos -> left);
            rigth_heigth = get_height(pos -> rigth);

            	if (left_heigth > rigth_heigth)
                return left_heigth + 1;
          	else return rigth_heigth + 1;
        }
    }

    int get_count_leaf(Node *pos) {
        if(pos == NULL) return 0;

        if(pos -> left == NULL && pos -> rigth == NULL) {
            return 1;
        } else {
            return get_count_leaf(pos -> left) + get_count_leaf(pos -> rigth);
        }
    }

    int get_count(Node *pos) {
        if(pos == NULL) {
            return 0;
        } else {
            return (1 + get_count(pos -> left) + get_count(pos -> rigth));
        }
    }

    void delete_tree(Node *pos) {
        if(pos == NULL) return;

        delete_tree(pos -> left);
        delete_tree(pos -> rigth);
        delete pos;
    }

    void show(Node *pos) {
        if(pos == NULL) return;
        cout << pos -> data << " ";
        show(pos -> left);
        show(pos -> rigth);
    }

    int get_max(Node *pos) {
        int node_data, left_max, rigth_max;
        if(pos == NULL) return -1;

        node_data = pos -> data;
        left_max = get_max(pos -> left);
        rigth_max = get_max(pos -> rigth);

        if (left_max > node_data) {
            node_data = left_max;
        }

        if (rigth_max > node_data) {
            node_data = rigth_max;
        }

        return node_data;
    }

    void in_order_traversal(Node *root) {
        stack<Node*> stack;
        Node *curr = root;

        while (curr != NULL || stack.empty() == false) {
            while(curr != NULL) {
                stack.push(curr);
                curr = curr -> left;
            }

            Node *node = stack.top();
            stack.pop();
            cout << node -> data << " ";
            curr = node -> rigth;
        }
    }

    void pre_order_teraversal(Node *root) {
        stack<Node*> stack;
        Node *curr = root;

        stack.push(curr);
        while (!stack.empty()) {
            curr = stack.top();
            stack.pop();
            cout << curr -> data << " ";

	    if (curr -> rigth != NULL) {
            stack.push(curr -> rigth);
           }

	   if (curr -> left != NULL) {
	    stack.push(curr -> left);
	}
    }
  }

   void level_order_traversal(Node *pos) {
	int heigth = get_height(pos);
	for(int i = 0; i <= heigth; i++){
	    print_current_level(pos, i);
	}
  }


   void print_current_level(Node *root, int level) {
	if(root == NULL) return;
	if(level == 1) {
		cout << root -> data << " ";
	} else if(level > 1) {
	     print_current_level(root -> left, level - 1);
	     print_current_level(root -> rigth, level - 1);
     }
  }

  bool is_identical(Node *root_a, Node *root_b) {
	if(root_a == NULL && root_b == NULL) {
		return true;
	}

	if(root_a != NULL && root_b != NULL){
		return root_a -> data == root_b -> data &&
		is_identical(root_a -> left, root_b -> left) &&
 		is_identical(root_a -> rigth, root_b -> rigth);
	}
	return false;
   }

  int find_level(Node *root, int item) {
	if(root == NULL) return -1;

	int dist = 0;
	if(root -> data == item ||
	(dist = find_level(root -> left, item)) >= 0 ||
	(dist = find_level(root -> rigth, item)) >= 0) {
		return dist + 1;
	}

	return dist;
   }

  bool find_ancestors(Node *root, int item) {
 	if(root == NULL) return false;

	if(root -> data == item) return true;

	if(find_ancestors(root -> left, item) || find_ancestors(root -> rigth, item)) {
		cout << root -> data << " ";
		return true;
	}
	return false;
   }

  bool is_complete_tree(Node *root) {
	queue<Node *> queue;
	bool flag = false;
	queue.push(root);

	if(root == NULL) return true;

	while (!queue.empty()) {
        Node* temp = queue.front();
        queue.pop();

        if (temp -> left) {
            if (flag == true)
                return false;

            queue.push(temp -> left);
        } else flag = true;

        if (temp -> rigth) {
            if (flag == true)
                return false;

            queue.push(temp -> rigth);
        } else flag = true;

        return true;
    }
  }


  Node *find_LCA(Node *root, int a, int b) {
	if(root == NULL) return NULL;

	if(root -> data == a || root -> data == b) return root;

	Node *left_LCA = find_LCA(root -> left, a, b);
	Node *rigth_LCA = find_LCA(root -> rigth, a, b);

	if(left_LCA && rigth_LCA) return root;

	return (left_LCA != NULL) ? left_LCA : rigth_LCA;
  }

  Node* find_left_most(Node* node){
    if (node == NULL)
        return NULL;

    while (node -> left != NULL)
        node = node -> left;

    return node;
  }

  // We must create a threaded tree.
  void in_order_threaded_travers(Node *root) {
	Node *curr = find_left_most(root);

	while(curr != NULL) {
		cout << curr -> data << " ";
		if(curr -> rigthThread) curr = curr -> rigth;
		else curr = find_left_most(curr -> rigth);
 	}
  }

  int root_to_leaf_sum(Node *root, int x) {
	if(root == NULL) return 0;

	x = (x * 10 + root -> data);

	if(root -> left == NULL && root -> rigth == NULL) return x;

	return root_to_leaf_sum(root -> left, x) + root_to_leaf_sum(root -> rigth, x);
  }
};
