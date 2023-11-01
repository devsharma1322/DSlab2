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
    if (data == -1) {
        return NULL;
    }
    root = new node(data);
    cout << "Enter the left value of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the right value of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

vector<int> topView(node* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    map<int, int> m;

    queue<pair<node*, int> > q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontend = temp.first;
        int hd = temp.second;
        if (m.find(hd) == m.end()) {
            m[hd] = frontend->data;
        }
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

    vector<int> topViewTraversal = topView(root);
    cout << "The top view of the tree is: ";
    for (int i = 0; i < topViewTraversal.size(); i++) {
        cout << topViewTraversal[i] << " ";
    }
    cout << endl;
}
