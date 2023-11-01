#include <iostream>
#include <vector>
using namespace std;

// Function to convert postorder to preorder
void postorderToPreorder(vector<int>& postorder, int start, int end) {
    if (start > end) {
        return;
    }

    // The last element in the postorder is the root in the preorder
    int root = postorder[end];
    cout << root << " ";

    // Find the index of the first element in the postorder that is smaller than the root
    int i = start;
    while (postorder[i] < root) {
        i++;
    }

    // Recursively process the left and right subtrees
    postorderToPreorder(postorder, start, i - 1);
    postorderToPreorder(postorder, i, end - 1);
}

int main() {
    vector<int> postorder ;
    postorder.push_back(2);
    postorder.push_back(4);
    postorder.push_back(3);
    postorder.push_back(8);
    postorder.push_back(10);
    postorder.push_back(9);
    postorder.push_back(5);
    
    cout << "Preorder traversal: ";
    postorderToPreorder(postorder, 0, postorder.size() - 1);
    
    return 0;
}
