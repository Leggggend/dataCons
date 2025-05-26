// 任务描述
// 本关任务：编写一个函数实现线性表元素的查找。
// 函数原型：status LocateElem(LinkList L,ElemType e)
// 功能说明：若线性表L不存在，返回INFEASIBLE；若没有找到指定的元素e，则查找失败，返回ERROR；若查找成功，则返回元素逻辑序号i。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.单链表的定义，3.线性表查找操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数LocateElem的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 测试输入：1 11 12 13 14 15 0 14，第一个数1表示对一个已存在的线性表进行操作，后续是一个以0结束的数据元素序列，最后1个数据代表待查找的元素值。后续含义相同。
// 预期输出：
// 4

// 测试输入：1 11 12 13 14 15 0 18
// 预期输出：
// ERROR

// 测试输入：0，此时表示对不存在的线性表进行查找
// 预期输出：
// INFEASIBLE

status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
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

    int k = 1;
    p = L->next;
    while(k <= length) {
        if (p->data == e) {
            return k;
        }     
        p = p->next;
        k++;
    }
    return ERROR;
    /********** End **********/
}