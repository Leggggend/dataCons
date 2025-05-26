// 任务描述
// 本关任务：编写一个函数实现线性表的删除操作。
// 函数原型：status ListDelete(LinkList &L,int i,ElemType &e)
// 功能说明：若线性表L不存在，返回INFEASIBLE；否则删除线性表L的第i个元素，若删除成功则将删除的值赋给e并返回OK，若删除失败则返回ERROR。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.单链表的定义，3.线性表删除操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数ListDelete的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 测试输入：0，此时表示对不存在的线性表进行删除操作
// 预期输出：
// INFEASIBLE

// 测试输入：1 11 12 13 14 15 0 3，第一个数1表示对一个已存在的线性表进行操作，后续是一个以0结束的数据元素序列，最后1个数据代表删除位置。后续含义相同。
// 预期输出：
// OK
// 13
// 11 12 14 15

// 测试输入：1 11 12 13 14 15 0 8
// 预期输出：
// ERROR
// 11 12 13 14 15

// 测试输入：1 11 12 13 14 15 0 0
// 预期输出：
// ERROR
// 11 12 13 14 15

status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL) {
        return INFEASIBLE;
    } else if (i < 1) { // i值不合法
        return ERROR;
    }

    LNode *p = L; // 从头节点开始
    int k = 0; // 当前节点的序号（头节点为0）

    // 查找第 i-1 个节点
    while (p != NULL && k < i - 1) {
        p = p->next;
        k++;
    }

    if (p == NULL || p->next == NULL || k > i - 1) { // 如果未找到第 i-1 个节点，或第 i 个节点不存在，或 i 超出范围
        return ERROR;
    }

    LNode* temp = p->next->next;
    e = p->next->data;
    free(p->next);
    p->next = temp;
    return OK;

    /********** End **********/
}