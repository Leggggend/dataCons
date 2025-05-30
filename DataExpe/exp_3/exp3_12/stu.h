// 任务描述
// 本关任务：编写一个函数实现二叉树按层遍历
// 函数原型：status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))；
// 功能说明：对二叉树T进行按层遍历，Visit是一个函数指针的形参（可使用该函数对结点操作），对每个结点调用函数Visit访问一次且一次。
// 相关知识
// 为了完成本关任务，你需要掌握：1.二叉树，2.二叉链表，3.按层遍历的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数LevelOrderTraverse的编写
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入为结点在满二叉树中的编号和结点值的序列，当结点在满二叉树中的编号为0时表示输入结束。例如： 6 4 d  表示（4，d）的结点在满二叉树中的编号为6； 0 0 null代表结束标记。输出根据该序列创建的二叉树的按层遍历序列。
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null
// 预期输出： 
//  1,a 2,b 3,c 4,d 5,e

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//按层遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!T) {
        return ERROR;
    }

    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        visit(p);
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }

    return OK;
    /********** End **********/
}