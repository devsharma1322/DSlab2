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

void solve(node* root, vector<int>& ans, int level) {
    if (root == NULL) {
        return;
    }
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(node* root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree(root);

    vector<int> leftViewTraversal = leftView(root);
    cout << "The left view of the tree is: ";
    for (int i = 0; i < leftViewTraversal.size(); i++) {
        cout << leftViewTraversal[i] << " ";
    }
    cout << endl;
}
