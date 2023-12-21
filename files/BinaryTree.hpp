#include <iostream>
#include <stdlib.h>

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

        if (pos == NULL) return -1;

        if(pos -> left == NULL && pos -> rigth == NULL) {
            return 0;
        } else {
            left_heigth = get_height(pos -> left);
            rigth_heigth = get_height(pos -> rigth);
        }

        if (left_heigth > rigth_heigth) {
            return left_heigth + 1;
        } else {
            return rigth_heigth + 1;
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
        show(pos -> left);
        show(pos -> rigth);
        cout << pos -> data << " ";
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
};
