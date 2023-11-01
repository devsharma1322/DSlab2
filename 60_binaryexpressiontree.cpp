#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;

    Node(string data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryExpressionTree {
private:
    Node* root;

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    Node* buildExpressionTree(string postfix) {
        stack<Node*> st;
        for (char c : postfix) {
            if (isalnum(c)) {
                string operand(1, c);
                st.push(new Node(operand));
            } else if (isOperator(c)) {
                Node* rightOperand = st.top();
                st.pop();
                Node* leftOperand = st.top();
                st.pop();
                Node* newNode = new Node(string(1, c));
                newNode->left = leftOperand;
                newNode->right = rightOperand;
                st.push(newNode);
            }
        }
        return st.top();
    }

    int evaluateExpressionTree(Node* root) {
        if (root) {
            if (!isOperator(root->data[0])) {
                return stoi(root->data);
            }
            int leftValue = evaluateExpressionTree(root->left);
            int rightValue = evaluateExpressionTree(root->right);
            switch (root->data[0]) {
                case '+':
                    return leftValue + rightValue;
                case '-':
                    return leftValue - rightValue;
                case '*':
                    return leftValue * rightValue;
                case '/':
                    return leftValue / rightValue;
            }
        }
        return 0;
    }

    void printInfixExpression(Node* root) {
        if (root) {
            bool isOperatorNode = isOperator(root->data[0]);
            if (isOperatorNode) {
                cout << "(";
            }
            printInfixExpression(root->left);
            cout << root->data;
            printInfixExpression(root->right);
            if (isOperatorNode) {
                cout << ")";
            }
        }
    }

public:
    BinaryExpressionTree(string postfixExpression) {
        root = buildExpressionTree(postfixExpression);
    }

    int evaluate() {
        return evaluateExpressionTree(root);
    }

    void printInfix() {
        printInfixExpression(root);
        cout << endl;
    }
};

int main() {
    string postfixExpression = "42*7+";
    BinaryExpressionTree expressionTree(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Infix Expression: ";
    expressionTree.printInfix();

    int result = expressionTree.evaluate();
    cout << "Result: " << result << endl;

    return 0;
}
