// 任务描述
// 本关任务：编写一个函数实现线性表元素前驱的获取。
// 函数原型：status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 功能说明：若线性表L不存在，返回INFEASIBLE；若没有找到指定元素e的前驱，则查找失败，返回ERROR；若查找成功，则将值赋给pre，并返回OK。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.单链表的定义，3.线性表获取前驱元素操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数PriorElem的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 测试输入：1 11 12 13 14 15 0 14，第一个数1表示对一个已存在的线性表进行操作，后续是一个以0结束的数据元素序列，最后1个数据代表待查找前驱的元素值。后续含义相同。
// 预期输出：
// OK
// 13

// 测试输入：1 11 12 13 14 15 0 11
// 预期输出：
// ERROR

// 测试输入：1 11 12 13 14 15 0 18
// 预期输出：
// ERROR

// 测试输入：0，此时表示对不存在的线性表进行查找
// 预期输出：
// INFEASIBLE

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL) {
        return INFEASIBLE;
    } else if (L->next == NULL || L->next->next == NULL) {
        return ERROR;
    }

    LNode* temp = L->next; 
    while (temp->next != NULL) { // 遍历链表
        if (temp->next->data == e) { // 如果找到目标元素
            pre = temp->data; // 将前驱元素赋值给 pre
            return OK;
        }
        temp = temp->next; // 移动到下一个节点
    }

    return ERROR;
    /********** End **********/
}