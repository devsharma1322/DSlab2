#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

vector<int> bottomView(node* root) {
    map<int, int> m;
    vector<int> ans;
    queue<pair<node*, int> > q;
    if (root == NULL) {
        return ans;
    }
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontend = temp.first;
        int hd = temp.second;
        m[hd] = frontend->data;
        if (frontend->left) {
            q.push(make_pair(frontend->left, hd - 1));
        }
        if (frontend->right) {
            q.push(make_pair(frontend->right, hd + 1));
        }
    }

    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        ans.push_back(it->second);
    }
    return ans;
}

int main() {
    node* root = NULL;
    root = buildTree(root);

    vector<int> bottomViewTraversal = bottomView(root);
    cout << "The bottom view of the tree is: ";
    for (int i = 0; i < bottomViewTraversal.size(); i++) {
        cout << bottomViewTraversal[i] << " ";
    }
    cout << endl;
}
