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

    // kth level of a binary tree - return nodes at kth (valid) level of tree
    void kth_level(Node* root, int k) {
        if(root == NULL) return;

        if(k == 1) {
            cout << root->val << " ";
            return;
        }

        kth_level(root->left, k-1);
        kth_level(root->right, k-1);
    }

    Node* lca(Node* root, Node* p, Node* q) {
        // return lowest common ancestor
        if(root == NULL) return NULL;

        if(root->val == p->val || root->val == q->val) {
            return root;
        }

        Node* leftLca = lca(root->left, p, q);
        Node* rightLca = lca(root->right, p, q);

        if(leftLca && rightLca) return root;
        else if(leftLca != NULL) return leftLca;
        else return rightLca;
    }

    int search(vector<int>& inorder, int left, int right, int val) {
        for(int i = left; i <= right; i++) {
            if(inorder[i] == val) return i;
        }

        return -1;
    }

    Node* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        if(left>right) return NULL;

        Node* root = new Node(preorder[preIdx]);

        int inIdx = search(inorder, left,right, preorder[preIdx]);
        preIdx++;
        
        root->left = helper(preorder, inorder, preIdx, left, inIdx -1);
        root->right = helper(preorder, inorder, preIdx, inIdx +1, right);

        return root;
    }

    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx,0, inorder.size()-1);
    }

    int sumTree(Node* root) {
        if(root == NULL) return 0;

        int leftSum = sumTree(root->left);
        int rightSum = sumTree(root->right);

        root->val += leftSum + rightSum;
        return root->val;
    }

    // return all paths from root - leaf (approach - dfs)
    void allPaths(Node* root, string path, vector<string>& ans) {
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        if(root->left) {
            allPaths(root->left,path+"->"+to_string(root->left->val), ans);
        }

        if(root->right) {
            allPaths(root->right, path+"->"+to_string(root->right->val), ans);
        }
    }

    vector<string> binaryTreePaths(Node* root) {
        // dfs travseral from root - leaf
        vector<string> ans;
        string path = to_string(root->val);

        allPaths(root, path, ans);
        return ans;
    }

    int widthOfBinaryTree(Node* root) {
        queue<pair<Node*, unsigned long long>> q;
        q.push({root, 0});

        int maxWid = 0;

        while(q.size() > 0) {
            int currSize = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;
            maxWid = max(maxWid, (int)(endIdx-stIdx + 1));

            for(int i = 0; i < currSize; i++) {
                auto currNode = q.front();
                q.pop();
                if(currNode.first->left) {
                    q.push({currNode.first->left, currNode.second*2+1});
                }

                if(currNode.first->right) {
                    q.push({currNode.first->right, currNode.second*2+2});
                }
            }
        }

        return maxWid;
    }

    vector<int> morris_inorder_traversal(Node* root) {
        vector<int> res;
        Node* curr = root;

        while(curr != NULL) {
            if(curr->left == NULL) {
                // If no left child, visit this node 
                // and go right
                res.push_back(curr->val);
                curr = curr->right;
            }

            else {
                Node* IP = curr->left;
                while(IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }
                // Make curr the right child of its 
                // inorder predecessor
                if(IP->right == NULL) {
                    // create a thread
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }

    Node* nextRight;
    void flatten_binary_to_list(Node* root) {
        // in place approach where root->left == NULL, root->right = list.next;
        if(root == NULL) return;

        flatten_binary_to_list(root->right);
        flatten_binary_to_list(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
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

    // cout << bt.height(root) << endl;
    // cout << "number of nodes - " << bt.countNode(root) << endl;
    // cout << "sum of all nodes - "<< bt.sumOfNodes(root) << endl; 
    
    //bt.kth_level(root, 2);

    cout << bt.sumTree(root) << endl;
    bt.preOrderTraverse(root);

    return 0;
}