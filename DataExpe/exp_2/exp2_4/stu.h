// 任务描述
// 本关任务：编写一个函数实现线性表的判空。
// 函数名原型：status ListEmpty(LinkList L)
// 若线性表L不存在，则返回INFEASIBLE；若线性表L长度为0，则返回TRUE；不为0则返回FALSE。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.单链表的定义，3.线性表判空操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数ListEmpty的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 测试输入：2，此时表示对已存在的空线性表判空
// 预期输出：
// TRUE

// 测试输入：1，此时表示对已存在的非空线性表判空
// 预期输出：
// FALSE

// 测试输入：0，此时表示对不存在的线性表判空
// 预期输出：
// INFEASIBLE

status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/


    if (L == NULL) {
        return INFEASIBLE;
    } else if (L->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }

    return OK;
    /********** End **********/
}