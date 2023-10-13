//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
// Node structure definition
class Solution {
public:
    int floor(Node* root, int x) {
        int floorValue = -1; // Initialize floorValue as -1
        
        // Traverse the BST
        while (root != nullptr) {
            // If the current node's data is equal to x, the floor value is x
            if (root->data == x) {
                floorValue = root->data;
                break;
            }
            // If the current node's data is less than x, update floorValue and move to the right subtree
            else if (root->data < x) {
                floorValue = root->data;
                root = root->right;
            }
            // If the current node's data is greater than x, move to the left subtree
            else {
                root = root->left;
            }
        }
        return floorValue;
    }
};


//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends