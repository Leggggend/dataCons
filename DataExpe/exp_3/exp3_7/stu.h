// 任务描述
// 本关任务：编写一个函数实现结点插入
// 函数原型：status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)；
// 功能说明：e是和T中结点关键字类型相同的给定值，LR为0或1，c是待插入结点；根据LR为0或者1，插入结点c到T中，作为关键字为e的结点的左或右孩子结点，结点e的原有左子树或右子树则为结点c的右子树，返回OK。如果插入失败，返回ERROR。
// 特别地，当LR为-1时，作为根结点插入，原根结点作为c的右子树。
// 相关知识
// 为了完成本关任务，你需要掌握：1.二叉树，2.二叉链表，3.插入结点的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数InsertNode的编写
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入为结点在满二叉树中的编号和结点值的序列，当结点在满二叉树中的编号为0时表示输入结束。例如： 6 4 d  表示（4，d）的结点在满二叉树中的编号为6； 0 0 null代表结束标记。接着输入的是e、LR以及c的值。并通过输出先序和中序遍历检验正确性。
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null  3  0 6 f
// 预期输出： 
//  1,a 2,b 3,c 6,f 4,d 5,e
//  2,b 1,a 6,f 4,d 3,c 5,e
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null  3  0 3 f
// 待插入结点关键字有重复，无法插入结点3 f
// 预期输出：
//  插入操作失败
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null  10  0 6 f
// 二叉树中无关键字为10的结点，无法插入结点6 f
// 预期输出： 
//  插入操作失败

// 根据关键字查找结点
BiTNode* LocateNodeByKey(BiTree T, KeyType e) {
    if (!T) {
        return NULL;
    }
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        if (p->data.key == e) {
            return p;
        } 
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    return NULL;
}

status InsertNode(BiTree &T, KeyType e, int LR, TElemType c) {
    BiTNode* node = LocateNodeByKey(T, c.key);
    if (node) return ERROR; // 有重复关键字
    BiTNode* des = LocateNodeByKey(T, e);
    if (!des) return ERROR; // 没有找到插入位置
    BiTNode* ltemp = des->lchild;
    BiTNode* rtemp = des->rchild;

    BiTNode* newnode = (BiTNode*)malloc(sizeof(BiTNode));
    if (!newnode) return ERROR;
    newnode->data.key = c.key;
    strcpy(newnode->data.others, c.others);
    newnode->lchild = newnode->rchild = NULL;

    if (LR == -1) { // 作为根结点插入
        newnode->rchild = T;
        T = newnode;
        return OK;
    } else if (LR == 0) { // 作为左子树插入
        des->lchild = newnode;
        newnode->rchild = ltemp;
        return OK;
    } else if (LR == 1) { // 作为右子树插入
        des->rchild = newnode;
        newnode->rchild = rtemp;
        return OK;
    }

    return ERROR;
}