#include <vector>
#include <iostream>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Binary_Search_Tree{
    public:
    Node* root;

    Node* insert(Node* root, int val) {
    if(root == NULL)
        return new Node(val);

    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
    }

    Node* create_bst(vector<int>& nums) {
        Node* root = NULL;

        for(int x : nums) {
            root = insert(root, x);
        }

        return root;
    }

    // inorder prints sorted manner for bst
    void print_inorder(Node* root) {
        if(root == NULL) return;

        print_inorder(root->left);
        cout << root->val << " ";
        print_inorder(root->right);

    }

    // search in bst - Log(n) TC
    bool search_bst(Node* root, int key) {
        if(root == NULL) return false;

        if(root->val == key) return true;

        if(root->val < key) {
            return search_bst(root->right, key);
        } else return search_bst(root->left, key);
    }

    // delete node in bst
    Node* getInorderSuccessor(Node* root) {
        // helper function
        // is the left mode in right subtree
        while(root != NULL && root->left != NULL) {
            root = root->left;
        }

        return root;
    }

    Node* delete_node(Node*root, int key) {
        if(root == NULL) return NULL;

        if(root->val < key) {
            root->right =  delete_node(root->right, key);
        } else if(root->val > key) root->left = delete_node(root->left, key);
        else {
            // delete operation here
            // 3 conditions - either node has no child, 1 child or 2 child

            if(root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else {
                Node* Inorder_successor = getInorderSuccessor(root->right);
                root->val = Inorder_successor->val;
                root->right = delete_node(root->right, Inorder_successor->val);
            }
        }

        return root;
    }

    // helper function for create_bst_from_sorted_array
    Node* helper(vector<int> &sorted_nums, int st, int end) {
        if(st > end) return NULL;

        int mid = st + (end-st)/2;
        Node* root = new Node(sorted_nums[mid]);

        root->left = helper(sorted_nums, st, mid-1);
        root->right = helper(sorted_nums,mid+1, end);

        return root;
    }

    // create BST from sorted Array
    Node* create_bst_from_sorted_array(vector<int>& sorted_nums) {
        int st = 0;
        int end = sorted_nums.size() -1;
        return helper(sorted_nums,st, end);
    }

    // validate a BST
    bool isBST(Node* root, Node* min, Node* max) {
        if(root == NULL) return true;
        if(min != NULL && root->val <= min->val) return false;
        if(max != NULL && root->val >= max->val) return false;

        return isBST(root->left, min, root) && isBST(root->right, root, max);
    }

    // Minimum distance between BST Nodes - find the min difference of 2 nodes from a BST
    void inorderTraversal(Node* root, vector<int>& inorder) {
        if(root == NULL) return;

        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    int searchMin(vector<int>& inorder) {
        if(inorder.size() < 2) return 0;

        int minD = 2000;

        for(int i = 0; i < inorder.size()-1; i++) {
            minD = min(minD, inorder[i+1] - inorder[i]);
        }

        return minD;
    }

    int min_dis_BST(Node* root) {
        vector<int> inorder;

        inorderTraversal(root, inorder);

        return searchMin(inorder);
    }

    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL) return root;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        Node* prev = NULL;

        while(q.size() > 0) {
            Node* curr = q.front();
            q.pop();

            if(curr == NULL) {
                if(q.size() == 0) {
                    break;
                } 
                q.push(NULL);
            } else {
                if(curr->left != NULL) {
                    q.push(curr->left);
                } 
                if(curr->right != NULL) {
                    q.push(curr->right);
                }
                if(prev != NULL) {
                    prev->next = curr;
                }
            }
            prev = curr;
        }

        return root;
    }
};

class BSTIterator {
public:
    stack<TreeNode*> s;
    void storeLeftNodes(TreeNode* root) {
        while(root != NULL) {
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        // use the helper function here
        storeLeftNodes(root);
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();

        if(ans->right) storeLeftNodes(ans->right);

        return ans->val;
    }
    
    bool hasNext() {
        return s.size() > 0;
    }
};

class FindPredSuccInBST {
	public:
	Node* leftMostInRight(Node* root) {
		Node* ans = root;
		while (root != NULL) {
			ans = root->left;
			root = root->left;
		}
		
		return ans;
	}
	
	Node* rightMostInLeft(Node* root) {
		Node* ans = root;
		while (root != NULL) {
			ans = root->right;
			root = root->right;
		}
		
		return ans;
	}
	
	vector<Node*> findPreSuc(Node* root, int key) {
		// code here
		Node* succ = NULL;
		Node* pred = NULL;
		Node* curr = root;
		
		vector<Node*> ans;
		while (curr != NULL) {
			if (key < curr->data) {
				succ = curr;
				curr = curr->left;
			}
			else if (key > curr->data) {
				pred = curr;
				curr = curr->right;
			}
			else if (key == curr->data) {
				if (curr->left != NULL) {
					// call for pred helper func
					pred = rightMostInLeft(root->left);
				}
				
				if (curr->right != NULL) {
					// call for succ helper func
					succ = leftMostInRight(root->right);
				}
				
				break;
			}
		}
		
		ans.push_back(pred);
		ans.push_back(succ);
		
		return ans;
	}
};

int main() {
    Binary_Search_Tree bst;
    vector<int> nums = {30,223,100,521,62,41};

    vector<int> sorted_nums = {-10,-3, 0,5,9};

    Node* root = bst.create_bst(nums);
    bst.print_inorder(root);
    cout << endl;

    //cout << bst.search_bst(root, 5) << endl;

    // delete
    root = bst.delete_node(root, 521);
    bst.print_inorder(root);
    cout << endl;

    //cout << bst.isBST(root, NULL, NULL) << endl;

    cout << bst.min_dis_BST(root) << endl;

    return 0;
}