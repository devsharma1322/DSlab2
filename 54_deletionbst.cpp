#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBST(node* root, int d) {
    if (root == NULL) {
        root = new node(d);
        return root;
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void levelOrder(node* root) {
    if (!root)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

node* findMin(node* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

node* deletion(node* root, int d) {
    if (root == NULL) {
        return root;
    }

    if (d < root->data) {
        root->left = deletion(root->left, d);
    } else if (d > root->data) {
        root->right = deletion(root->right, d);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deletion(root->right, temp->data);
    }
    return root;
}

void takeInput(node*& root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data (-1 to stop): ";
        cin >> data;
    }
}

int main() {
    node* root = NULL;
    takeInput(root);

    cout << "Level Order Traversal before deletion: ";
    levelOrder(root);
    cout << endl;

    int key;
    cout << "Enter the node to delete: ";
    cin >> key;

    root = deletion(root, key);

    cout << "Level Order Traversal after deletion: ";
    levelOrder(root);
    cout << endl;
}
