struct TreeNode { int val; std::vector<TreeNode*> children; };

void preorder(TreeNode* node) {
    if (node == nullptr) return;
    std::cout << node->val << " ";      // visit first
    for (TreeNode* c : node->children)  // then each subtree
        preorder(c);
}