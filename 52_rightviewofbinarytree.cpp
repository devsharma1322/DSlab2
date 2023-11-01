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

node* buildTree(node* root) {
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new node(data);
    if (data == -1) {
        return NULL;
    }
    cout << "Enter the left value of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the right value of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

vector<int> rightView(node* root) {
    vector<int> ans;
    if (!root) {
        return ans;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            node* current = q.front();
            q.pop();

            // The last node at each level is part of the right view
            if (i == size - 1) {
                ans.push_back(current->data);
            }

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }

    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree(root);

    vector<int> rightViewTraversal = rightView(root);
    cout << "The right view of the tree is: ";
    for (int i = 0; i < rightViewTraversal.size(); i++) {
        cout << rightViewTraversal[i] << " ";
    }
    cout << endl;
}
