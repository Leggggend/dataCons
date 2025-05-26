// 任务描述
// 本关任务：编写一个函数实现线性表的清空。
// 函数名原型：status ClearList(LinkList &L)
// 若线性表L不存在，清空L，释放所有数据元素的结点，返回OK；若线性表L不存在，则返回INFEASIBLE。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.单链表的定义，3.线性表清空操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数ClearList的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 测试输入：0，此时表示对不存在的线性表清空
// 预期输出：
// INFEASIBLE

// 测试输入：1，此时表示对已存在的线性表清空
// 预期输出：
// OK

status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    if (L == NULL) {
        return INFEASIBLE;
    } 

    // 释放链表空间
    LNode *current = L->next;
    while (current != NULL) {
        LNode* temp = current;
        current = current->next;
        free(temp); // 释放当前节点
    }
    L->next = NULL;

    return OK;
    /********** End **********/
}