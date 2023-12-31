#include <iostream>
#include <stack>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree() {
        root = nullptr;
    }

    void constructTree(string expression) {
        stack<Node*> nodeStack;

        for (int i = expression.length() - 1; i >= 0; i--) {
            char c = expression[i];

            if (isalpha(c)) {
                Node* newNode = new Node(c);
                nodeStack.push(newNode);
            } else {
                Node* newNode = new Node(c);
                newNode->left = nodeStack.top();
                nodeStack.pop();
                newNode->right = nodeStack.top();
                nodeStack.pop();

                nodeStack.push(newNode);
            }
        }

        root = nodeStack.top();
    }

    void postorderTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }

        stack<Node*>s1;
        stack<Node*>s2;

        Node* temp = root;
        s1.push(temp);
        while(!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left!=NULL)
                s1.push(temp->left);
            if (temp->right!=NULL)
                s1.push(temp->right);
        }

        while(!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            cout<<temp->data;
        }


        cout << endl;
    }

    void deleteTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void deleteTree() {
        deleteTree(root);
        root = nullptr;
        cout << "Tree deleted." << endl;
    }
};

int main() {
    Tree expressionTree;

    string prefixExpression;
    cout << "Enter the prefix expression: ";
    getline(cin, prefixExpression);

    expressionTree.constructTree(prefixExpression);

    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Perform Postorder Traversal" << endl;
        cout << "2. Delete Tree" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Postorder Traversal: ";
                expressionTree.postorderTraversal();
                break;
            case 2:
                expressionTree.deleteTree();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}