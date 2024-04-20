#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    long long key;
    Node *left;
    Node *right;

    Node(long long value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

struct TREE {
    Node *root;

    TREE() {
        root = nullptr;
    }

    Node *insert(Node *tmp, long long key) {
        Node *new_node = new Node(key);
        if (root) {
            if (!tmp) {
                return new_node;
            }
            if (key < tmp->key) {
                tmp->left = insert(tmp->left, key);
            } else {
                if (key > tmp->key) {
                    tmp->right = insert(tmp->right, key);
                }
            }
            return tmp;
        }
        root = new_node;
        return root;
    }

    Node *minn(Node *root) {
        Node *tmp = root;
        while (tmp and tmp->left) {
            tmp = tmp->left;
        }
        return tmp;
    }

    Node *deleted(Node *tmp, long long key) {
        if (!tmp) {
            return tmp;
        }
        if (tmp->key > key) {
            tmp->left = deleted(tmp->left, key);
        }
        if (tmp->key < key) {
            tmp->right = deleted(tmp->right, key);
        }
        if (tmp->key == key) {
            if (tmp->left and tmp->right) {
                tmp->key = minn(tmp->right)->key;
                tmp->right = deleted(tmp->right, tmp->key);
            } else {
                if (tmp->left) {
                    tmp = tmp->left;
                } else {
                    if (tmp->right) {
                        tmp = tmp->right;
                    } else {
                        tmp = nullptr;
                    }
                }
            }
        }
        return tmp;
    }

    string exists(Node *tmp, long long key) {
        string result = "false";
        if (!tmp) {
            return result;
        }
        if (tmp->key > key) {
            return exists(tmp->left, key);
        }
        if (tmp->key < key) {
            return exists(tmp->right, key);
        }
        result = "true";
        return result;

    }

    string next(long long key) {
        Node *tmp = root;
        Node *result = nullptr;
        string res = "none";
        while (tmp) {
            if (tmp->key > key) {
                result = tmp;
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
        if (result) {
            res = to_string(result->key);
        }
        return res;
    }

    string prev(long long key) {
        Node *tmp = root;
        Node *result = nullptr;
        string res = "none";
        while (tmp) {
            if (tmp->key < key) {
                result = tmp;
                tmp = tmp->right;
            } else {
                tmp = tmp->left;
            }
        }
        if (result) {
            res = to_string(result->key);
        }
        return res;
    }

};

int main() {
    TREE tree;
    string s;
    long long key;
    while (cin >> s) {
        cin >> key;
        if (s == "insert") {
            tree.insert(tree.root, key);
        }
        if (s == "delete") {
            tree.root = tree.deleted(tree.root, key);
        }
        if (s == "exists") {
            cout << tree.exists(tree.root, key) << '\n';
        }
        if (s == "next") {
            cout << tree.next(key) << '\n';
        }
        if (s == "prev") {
            cout << tree.prev(key) << '\n';
        }
    }
}
