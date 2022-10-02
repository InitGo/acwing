
规定空树不是任何一个树的子树或者子结构
- 子树

```c++
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot || !root) return false; //子树为空， 子树不空但root为空， 都false
        if (isSame(root, subRoot)) return true; //检查根节点是否就是目标子树
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); //检查左右子树是否包含目标子树
    }

    bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b || a->val != b->val) return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};
```

- 树的子结构：树中有重合部分就算子结构

```c++
class Solution {
public:
    bool isSubStructure(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot || !root) return false;
        if (isSame(root, subRoot)) return true;
        return isSubStructure(root->left, subRoot) || isSubStructure(root->right, subRoot);
    }

    bool isSame(TreeNode* a, TreeNode* b) {
        if (!b) return true;
        if (!a) return false;
        if (a->val != b->val) return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};
```

- 区别：isSame()函数中
  - 子树：二者结构必须相同，需要同时为空，同时不空，val相等
  - 子结构：subRoot为空时即可返回true