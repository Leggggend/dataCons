// 任务描述
// 本关任务：编写一个函数实现线性表的求表长。
// 函数名原型：status ListLength(LinkList L)
// 若线性表L不存在，则返回INFEASIBLE；否则返回线性表L的长度。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.单链表的定义，3.线性表求表长操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数ListLength的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 测试输入：1 11 12 13 14 15 0，第一个数1表示对一个已存在的线性表进行操作，后续是一个以0结束的数据元素序列，最后对该线性表求表长
// 预期输出：
// 5

// 测试输入：0，此时表示对不存在的线性表求表长
// 预期输出：
// INFEASIBLE

int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    if (L == NULL) {
        return INFEASIBLE;
    }

    int length = 0;
    LNode* p = L->next;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    return length;


    /********** End **********/
}