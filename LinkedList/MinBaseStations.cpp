#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& nums) {
    if (nums.empty() || nums[0] == 0) return nullptr;
    
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (i < nums.size() && nums[i] != 0) {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;
        
        if (i < nums.size() && nums[i] != 0) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

int minCameraCover(TreeNode* root) {
    // 0: uncovered, 1: covered, 2: has camera
    int result = 0;
    
    function<int(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return 1;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        if (left == 0 || right == 0) {
            result++;
            return 2;
        }
        
        if (left == 2 || right == 2) {
            return 1;
        }
        
        return 0;
    };
    
    if (dfs(root) == 0) {
        result++;
    }
    
    return result;
}

int main() {
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    
    TreeNode* root = buildTree(nums);
    cout << minCameraCover(root) << endl;
    
    return 0;
}
