// 任务描述
// 本关任务：编写一个函数实现结点删除
// 函数原型：status DeleteNode(BiTree &T,KeyType e)；
// 功能说明：e是和T中结点关键字类型相同的给定值。删除T中关键字为e的结点；同时，根据该被删结点的度进行讨论：
// 如关键字为e的结点度为0，删除即可；
// 如关键字为e的结点度为1，用关键字为e的结点孩子代替被删除的e位置；
// 如关键字为e的结点度为2，用e的左子树（简称为LC）代替被删除的e位置，将e的右子树（简称为RC）作为LC中最右节点的右子树。
// 成功删除结点后返回OK，否则返回ERROR。
// 相关知识
// 为了完成本关任务，你需要掌握：1.二叉树，2.二叉链表，3.删除结点的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数DeleteNode的编写
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入为结点在满二叉树中的编号和结点值的序列，当结点在满二叉树中的编号为0时表示输入结束。例如： 6 4 d  表示（4，d）的结点在满二叉树中的编号为6； 0 0 null代表结束标记。接着输入的是e值。正确完成删除后，通过输出先序和中序遍历序列检验正确性。
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   1
// 预期输出： 
//  2,b 3,c 4,d 5,e
//  2,b 4,d 3,c 5,e
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   10
//  预期输出：  删除操作失败

// 根据关键字查找结点和父节点
BiTNode* LocateNodeByKey(BiTree T, KeyType e, BiTNode*& parent, int &islor) {
    if (!T) {
        return NULL;
    }
    parent = NULL;
    islor = 0;

    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        if (p->lchild && p->lchild->data.key == e) {
            parent = p;
            islor = 0;
        } else if (p->rchild && p->rchild->data.key == e) {
            parent = p;
            islor = 1;
        }

        if (p->data.key == e) {
            return p;
        } 
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    return NULL;
}

BiTNode* MostRightNode(BiTree &T) {
    BiTNode* msn = T;
    while (msn && msn->rchild) {
        msn = msn->rchild;
    }
    return msn;
}
status DeleteNode(BiTree &T, KeyType e)
//删除结点。此题允许通过增加其它函数辅助实现本关任务
{
    BiTNode* parent = NULL;
    int islor = 0;
    BiTNode* todelete = LocateNodeByKey(T, e, parent, islor);
    if (!todelete) return ERROR;

    BiTNode* ltemp = todelete->lchild; // 左子树
    BiTNode* rtemp = todelete->rchild; // 右子树
    BiTNode* msn = NULL; // 最右结点
    if (!ltemp && !rtemp) { // 度为0
        if (parent) {
            if (!islor) parent->lchild = NULL;
            else parent->rchild = NULL;
        } else {
            T = NULL; // 删除根节点
        }
        free(todelete);
    } else if (!ltemp || !rtemp) { // 度为1
        BiTNode* child = ltemp ? ltemp : rtemp; // 获取非空子树
        if (parent) {
            if (!islor) parent->lchild = child;
            else parent->rchild = child;
        } else {
            T = child; // 删除根节点
        }
        free(todelete);
    } else { // 度为2
        msn = MostRightNode(ltemp); // 找到左子树的最右节点
        msn->rchild = rtemp; // 将右子树挂到最右节点的右孩子上
        if (parent) {
            if (!islor) parent->lchild = ltemp;
            else parent->rchild = ltemp;
        } else {
            T = ltemp; // 删除根节点
        }
        free(todelete);
    }
    return OK;

}