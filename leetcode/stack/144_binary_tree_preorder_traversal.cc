//given a binary tree, return the preoder traversal of its nodes value

std::vector<int> preorder_traversal(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> res;
    std::stack<TreeNode*> s{root};
    while (!s.empty()) {
        TreeNode* t = s.top();
        s.pop();
        res.push_back(t->val);
        if (t->right) {
            s.push(t->right);
        }
        if (t->left) {
            s.push(t->left);
        }

    }
}

std::vector<int> preorder_traversal(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> res;
    std::stack<TreeNode*> s;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            res.push_back(p->val);
            p = p->left;
        } else {
            TreeNode* t = s.top();
            s.pop();
            p = t->right;
        }
    }
    return res;
}


//python version 
class Solution(object):
    def preorder_traversal(self, root):
        """
        :type root:TreeNode
        :rtype List[int]
        """
        if not root:
            return []
        stack = [root]
        res = []
        while stack:
            cur = stack.pop()
            res.append(cur.val)
            if cur.right:
                stack.append(cur.right)
            if cur.left:
                stack.append(cur.left)
        return res


class Solution(object):
    def preorder_traversal(self, root):
        """
        :type root : TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        return [root.val] + self.preorder_traversal(root.left) + 
        self.preorder_traversal(root.right)
