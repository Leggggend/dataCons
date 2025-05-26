// 任务描述
// 本关任务：编写一个函数实现顺序表的销毁。
// 函数名原型：status DestroyList(LinkList &L)
// 如果线性表L存在，该操作释放线性表的空间，使线性表成为未初始化状态，返回OK；否则对于一个未初始的线性表，是不能进行销毁操作的，返回INFEASIBLE。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.单链表的定义，3.销毁操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数DestroyList的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 测试输入：0，此时表示对不存在的线性表进行销毁操作
// 预期输出：
// INFEASIBLE

// 测试输入：1，此时表示对已存在的线性表进行销毁操作
// 预期输出：
// OK

status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    if (L == NULL) {
        return INFEASIBLE;
    } 

    // 释放链表空间
    LNode *current = L;
    while (current != NULL) {
        LNode* temp = current;
        current = current->next;
        free(temp); // 释放当前节点
    }

    L = NULL;
    return OK;
    /********** End **********/
}