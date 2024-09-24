//------------BINARY TREE--------------------//
#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Recursive function to create a tree manually
node *creat(node *root) {
    int val;
    cout << "Enter the data (-1 to stop): ";
    cin >> val;

    if (val == -1) {
        return NULL;  // Base case: no node is created if input is -1
    }

    root = new node(val);
    cout << "<---- Insert left of " << val << ": " << endl;
    root->left = creat(root->left);  // Recursively create the left subtree

    cout << "----> Insert right of " << val << ": " << endl;
    root->right = creat(root->right);  // Recursively create the right subtree

    return root;
}

// Function to create a tree by Level Order Traversal (LOT)
void creat_by_LOT(node *&root) {
    cout << "Enter the root node value: ";
    int data;
    cin >> data;

    if (data == -1) {
        return;  // No tree to create if root data is -1
    }

    root = new node(data);
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter the left child of " << temp->data << " (-1 for no child): ";
        int l;
        cin >> l;
        if (l != -1) {
            temp->left = new node(l);
            q.push(temp->left);
        }

        cout << "Enter the right child of " << temp->data << " (-1 for no child): ";
        int r;
        cin >> r;
        if (r != -1) {
            temp->right = new node(r);
            q.push(temp->right);
        }
    }
}

// Inorder Traversal (LNR)
void inorder(node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);       
    cout << root->data << " ";  
    inorder(root->right);       
}

// Preorder Traversal 
void preorder(node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";  
    preorder(root->left);       
    preorder(root->right);      
}

// Postorder Traversal 
void postorder(node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);      
    postorder(root->right);     
    cout << root->data << " ";  
}

// Level Order Traversal
void level_order_traversal(node *root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();  // Track the size of the current level
        for (int i = 0; i < levelSize; ++i) {
            node* temp = q.front();
            q.pop();

            cout << temp->data << " ";  

            if (temp->left != NULL) {
                q.push(temp->left);  
            }
            if (temp->right != NULL) {
                q.push(temp->right);  
            }
        }
        cout << endl;  
    }
}

// Main function
int main() {
    node* root = NULL;

    cout << "Creating binary tree using Level Order Traversal..." << endl;
    creat_by_LOT(root);  

    cout << "\nLevel Order Traversal of the tree:" << endl;
    level_order_traversal(root);  

    cout << "\nInorder Traversal:" << endl;
    inorder(root);  
    cout << endl;

    cout << "Preorder Traversal:" << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal :" << endl;
    postorder(root);  
    cout << endl;

    return 0;
}

