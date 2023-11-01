#include <iostream>
#include <vector>
using namespace std;

// Function to convert preorder to postorder
void preorderToPostorder(vector<int>& preorder, int& index, int min, int max) {
    if (index >= preorder.size()) {
        return;
    }

    int current = preorder[index];

    if (current < min || current > max) {
        return;
    }

    index++;

    preorderToPostorder(preorder, index, min, current - 1);
    preorderToPostorder(preorder, index, current + 1, max);

    cout << current << " ";
}

int main() {
    vector<int> preorder;
    preorder.push_back(2);
    preorder.push_back(4);
    preorder.push_back(3);
    preorder.push_back(8);
    preorder.push_back(10);
    preorder.push_back(9);
    preorder.push_back(5);
    int index = 0;

    cout << "Postorder traversal: ";
    preorderToPostorder(preorder, index, INT_MIN, INT_MAX);

    return 0;
}
