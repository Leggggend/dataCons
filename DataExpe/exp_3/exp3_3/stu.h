// 任务描述
// 本关任务：编写一个函数求二叉树深度。
// 函数原型：int BiTreeDepth(BiTree T)；
// 功能说明：求二叉树T深度并返回深度值。

// 相关知识
// 为了完成本关任务，你需要掌握：1.二叉树，2.二叉链表，3.二叉树深度。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数BiTreeDepth的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 下列输入为结点在满二叉树中的编号和结点值的序列，当结点在满二叉树中的编号为0时表示输入结束。对根据该序列创建的二叉树求深度并输出。
// 例如： 6 4 d  表示（4，d）的结点在满二叉树中的编号为6； 0 0 null代表结束标记。


// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null
// 预期输出： 3


// 测试输入：0 0 null
// 预期输出：0

int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!T) {
        return 0;        
    } else {
        int leftDepth = BiTreeDepth(T->lchild);
        int rightDepth = BiTreeDepth(T->rchild);
        int x = (leftDepth > rightDepth) ? leftDepth : rightDepth;
        return (x + 1);
    }
    /********** End **********/
}
