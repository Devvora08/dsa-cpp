#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

class BinaryTree {
    public:
    Node* root;
    int idx = -1;

    Node* preOrder(vector<int> &pre) {
        idx++;
        if(pre[idx] == -1) {
            return NULL;
        }

        Node* root = new Node(pre[idx]);
        root->left = preOrder(pre);
        root->right = preOrder(pre);

        return root;
    }
    
    // DFS Traversals
    void preOrderTraverse(Node* root) {
        idx++;
        if(root == NULL) {
            cout << " NULL ";
            return;
        }
        cout << root->val << " ";
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
    }

    void inOrder(Node* root) {
        idx++;
        if(root == NULL) {
            cout << " NULL ";
            return;
        }

        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }

    void postOrder(Node* root) {
        if(root == NULL) {
            cout << " NULL ";
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
    }

    // BFS Traversal 
    void bfs(Node* root) {
        queue<Node*> q;
        q.push(root);

        while(q.size() > 0) {
            Node* curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if(curr->left != NULL) {
                q.push(curr->left);
            }

            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }

        cout << endl;
    }  

    // height of a binary tree
    int height(Node* root) {
        if(root == NULL) return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        return max(leftHt, rightHt) + 1;
    }

    // count number of nodes in tree
    int countNode(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int left = countNode(root->left);
        int right = countNode(root->right);

        return left + right + 1;
    }

    // sum of all nodes
    int sumOfNodes(Node* root) {
        if(root == NULL) return 0;

        int left = sumOfNodes(root->left);
        int right = sumOfNodes(root->right);

        return left + right + root->val;
    }

    // Check if 2 input trees are identical
    bool isIdentical(Node* root1, Node* root2) {
        if(root1 == NULL || root2 == NULL) return root1 == root2;
        bool left = isIdentical(root1->left, root2->left);
        bool right = isIdentical(root1->right, root2->right);

        return left && right && root1->val == root2->val;
    }

    // check if subtree part of tree
    bool isSubTree(Node* root, Node* subRoot) {
        if(root == NULL || subRoot == NULL) return root == subRoot;
        if(root->val == subRoot->val && this->isIdentical(root, subRoot)) return true;

        return isSubTree(root->left, subRoot) || isSubTree(root->right, subRoot);
    }

    // return the diameter of a binary tree
    int diameterOfBinaryTree(Node* root) {
        if(root == NULL) return 0;

        int leftDiam = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);

        int currentDiam = height(root->left) + height(root->right);

        int maxDiam = max(leftDiam, rightDiam);
        maxDiam = max(maxDiam, currentDiam);

        return maxDiam;
    }
};

int main() {
    vector<int> pre = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> pre2 = {1,2,-1,-1,3,4,-1,-1,5,6,7,-1,8,-1,-1};

    BinaryTree bt;

    Node* root = bt.preOrder(pre);
    cout << endl;

    bt.preOrderTraverse(root);
    cout << endl;
    // bt.inOrder(root);
    // cout << endl;
    // bt.postOrder(root);
    // cout << endl;

    // bt.bfs(root);

    cout << bt.height(root) << endl;
    cout << "number of nodes - " << bt.countNode(root) << endl;
    cout << "sum of all nodes - "<< bt.sumOfNodes(root) << endl; 
    

    return 0;
}