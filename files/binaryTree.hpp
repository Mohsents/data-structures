#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

template <class T> class BinaryTree {
    private:
        struct Node {
            T data;
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

    void root_to_leaf(Node *pos) {
        string path;
        print_paht(pos, path);
    }

    void print_paht(Node *pos, string path) {
        if(pos == NULL) return;

        path.append(to_string(pos -> data));

        if (pos -> left == NULL && pos -> rigth == NULL) {
            print_root_to_leaf_sum(path);
        } else {
            print_paht(pos -> left, path);
            print_paht(pos -> rigth, path);
        }
    }

    void print_root_to_leaf_sum(string path) {
        static int sum = 0;
        sum += stoi(path);

        cout << "Sum " << path << "=" << sum << " + ";
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

};
