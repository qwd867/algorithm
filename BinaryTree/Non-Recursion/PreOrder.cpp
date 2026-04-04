#include <iostream>
#include <stack>

typedef struct __Node
{
    int val = 0;
    __Node *left = nullptr;
    __Node *right = nullptr;
} Node, *pNode;

pNode createFixedTree()
{
    // 根节点 1
    pNode root = new Node();
    root->val = 1;

    // 左孩子 2
    root->left = new Node();
    root->left->val = 2;

    // 右孩子 3
    root->right = new Node();
    root->right->val = 3;

    // 2 的左孩子 4
    root->left->left = new Node();
    root->left->left->val = 4;

    // 2 的右孩子 5
    root->left->right = new Node();
    root->left->right->val = 5;

    return root;
}

// 二叉树 前序遍历（非递归/迭代版）
// 前序遍历规则：根节点 -> 左子树 -> 右子树
void PreOrder(pNode head)
{
    // 用栈模拟递归，存储待遍历的树节点
    std::stack<pNode> myStack = {};

    // 当前节点指针，初始指向根节点
    auto curNode = head;

    // 第一步：先把根节点压入栈
    myStack.push(curNode);

    // 循环：栈不为空就一直遍历
    while (!myStack.empty())
    {
        // ====================== 处理当前节点 ======================
        // 取栈顶节点（当前要访问的节点）
        auto curNode = myStack.top();
        // 前序：先打印根节点
        printf("%d\n", curNode->val);
        // 打印完就把这个节点从栈里弹出（已处理完毕）
        myStack.pop();

        // ====================== 压入子节点（关键！） ======================
        // 栈是“先进后出”，我们想要 先遍历左、再遍历右
        // 所以必须 先压右节点、再压左节点
        // 这样出栈时才会先左后右，符合前序规则

        // 如果有右孩子，先把右孩子压栈
        if (curNode->right != nullptr)
        {
            myStack.push(curNode->right);
        }

        // 如果有左孩子，再把左孩子压栈
        if (curNode->left != nullptr)
        {
            myStack.push(curNode->left);
        }
    }
}

int main()
{
    auto head = createFixedTree();
    PreOrder(head);
}