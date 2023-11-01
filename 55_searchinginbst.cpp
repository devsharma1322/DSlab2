#include <iostream>
#include <queue>
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
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

bool search(node* root, int target) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == target) {
        return true;
    } else if (target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
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
    cout << "Enter the data" << endl;
    takeInput(root);
    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    int target;
    cout<<"Target:";
    cin>>target;
    if (search(root, target)) {
        cout << target << " found in the BST." << endl;
    } else {
        cout << target << " not found in the BST." << endl;
    }
}
