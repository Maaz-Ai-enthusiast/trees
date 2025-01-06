#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
    public:
        char data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(char value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create the tree as shown in the diagram
TreeNode* createTree() {
    TreeNode* root = new TreeNode('A');
    TreeNode* nodeB = new TreeNode('B');
    TreeNode* nodeC = new TreeNode('C');
    TreeNode* nodeD = new TreeNode('D');
    TreeNode* nodeE = new TreeNode('E');
    TreeNode* nodeF = new TreeNode('F');
    TreeNode* nodeG = new TreeNode('G');
    TreeNode* nodeH = new TreeNode('H');
    TreeNode* nodeK = new TreeNode('K');

    root->left = nodeB;
    root->right = nodeC;

    nodeB->left = nodeD;

    nodeC->left = nodeE;
    nodeC->right = nodeF;

    nodeD->left = nodeG;
    nodeD->right = nodeH;

    nodeH->left = nodeK;

    return root;
}

// Function for level-order traversal (with your provided structure)
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;

    // Create a queue for normal level order traversal
    queue<TreeNode*> q;

    // Push the root node to the queue
    q.push(root);
    q.push(NULL); // Add marker for the first level

    // Perform normal level order traversal
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        // If temp is NULL, print a new line (end of the current level)
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL); // Add marker for next level
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

// Inorder traversal for verification
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = createTree();

    cout << "Tree nodes in level order traversal:" << endl;
    levelOrderTraversal(root);

    cout << "\nTree nodes in inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
