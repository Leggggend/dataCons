// 任务描述
// 本关任务：编写一个函数实现结点赋值
// 函数原型：status Assign(BiTree &T,KeyType e,TElemType value)；
// 功能说明：e是和T中结点关键字类型相同的给定值；查找结点关键字等于e的结点，将该结点值修改成value，返回OK（要求结点关键字保持唯一性）。如果查找失败，返回ERROR。
// 提示：可在本题中定义实现LocateNode()函数来完成本关任务。
// 相关知识
// 为了完成本关任务，你需要掌握：1.二叉树，2.二叉链表，3.结点赋值的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数 Assign 的编写
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入为结点在满二叉树中的编号和结点值的序列，当结点在满二叉树中的编号为0时表示输入结束。例如： 6 4 d  表示（4，d）的结点在满二叉树中的编号为6； 0 0 null代表结束标记。接着输入的是e和value的值。正确完成赋值后，通过输出先序和中序遍历序列检验正确性。
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   3  10 new
// 预期输出： 
//  1,a 2,b 10,new 4,d 5,e
//  2,b 1,a 4,d 10,new 5,e
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   3  3 new
// 预期输出： 
//  1,a 2,b 3,new 4,d 5,e
//  2,b 1,a 4,d 3,new 5,e
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   3  2 new
// 预期输出： 赋值操作失败        
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   10  20 new
// 预期输出： 赋值操作失败

BiTNode* LocateNodeByKey(BiTree T, KeyType e)
//根据关键字查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
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

    /********** End **********/
}

// 根据满二叉树的编号查找节点
BiTNode* LocateNodeByIndex(BiTree T, int index) {
    if (!T) {
        return NULL; 
    }
    // 使用队列实现层次遍历
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T; 

    int currentIndex = 1;

    while (front < rear) {
        BiTree p = queue[front++]; 
        if (currentIndex == index) {
            return p; // 如果当前节点编号等于目标编号，返回该节点
        }

        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;

        currentIndex++; 
    }

    return NULL; 
}

status Assign(BiTree &T, KeyType e, TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // 现根据编号找结点
    BiTree p = LocateNodeByIndex(T, e);
    // 根据关键字找结点
    BiTree q = LocateNodeByKey(T, value.key);

    if ((q && q == p) || (!q && p)) { // 如果存在关键字且编号匹配或者关键字不存在但编号存在
        p->data.key = value.key;
        strcpy(p->data.others, value.others);
        return OK;    
    } 
    return ERROR;
    /********** End **********/
}
