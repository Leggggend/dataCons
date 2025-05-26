// 任务描述
// 本关任务：设以带头结点的双向循环链表表示线性表L=（a1，a2，...，an），试编写一个时间复杂度为O(n)的算法，将L改变成L=（a1，a3，...，an，...，a4，a2）。
// 相关定义如下：
// typedef int ElemType;
// typedef  struct  Dnode
//     {
//         ElemType     data;
//         struct  Dnode  * prior, * next;
//     }  * DuLinkList;
// 函数原型：void  adjust(DuLinkList  L);

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的物理结构，2.双向循环链表的插入与删除。

// 编程要求
// 根据提示，在右侧编辑器补充代码，写出函数 void  adjust(DuLinkList  L) 的定义。

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：6 
//                  1 2 3 4 5 6
// 预期输出：1 3 5 6 4 2

// 测试输入：11
//                   2 11 3 5 7 6 12 13 8 9 20 
// 预期输出：2 3 7 12 8 20 9 13 6 5 11



void adjust(DuLinkList L) {
    if (L == NULL || L->next == L || L->next->next == L) return; // 空链表、单节点或双节点链表无需调整

    DuLinkList p = L->next; // 指向第一个节点
    DuLinkList oddHead = (DuLinkList)malloc(sizeof(struct Dnode)); // 奇数部分的头节点
    DuLinkList oddTail = oddHead; // 奇数部分的尾节点
    DuLinkList evenHead = (DuLinkList)malloc(sizeof(struct Dnode)); // 偶数部分的头节点
    DuLinkList evenTail = evenHead; // 偶数部分的尾节点
    DuLinkList q = p; 

    // 初始化辅助节点
    oddHead->next = oddHead;
    oddHead->prior = oddHead;
    evenHead->next = evenHead;
    evenHead->prior = evenHead;

    int count = 0; // 用于记录当前节点的位置（从1开始）

    while (p != L) {
        count++;
        if (count % 2 == 1) { // 奇数位置节点
            // 将p节点插入到奇数部分的尾部
            oddTail->next = p;
            p->prior = oddTail;
            oddTail = p; // 更新奇数部分的尾节点
            p = p->next; // 移动到下一个节点        
        } else { // 偶数位置节点
            q = p->next; // 保留下一个节点
            if (evenTail == evenHead) {
                evenHead->next = p;
                p->prior = evenHead;
                p->next = evenHead;
                evenHead->prior = p;
                evenTail = p;
            } else {
                // 将p节点插入到偶数部分的头部
                p->next = evenHead->next;
                evenHead->next->prior = p;
                evenHead->next = p;
                p->prior = evenHead;
            }
            p = q; // 保留节点启用
        }

    }

    // 将奇数部分和偶数部分连接起来
    oddTail->next = evenHead->next; // 奇数部分尾部连接偶数部分头部
    evenHead->next->prior = oddTail; // 更新偶数部分头部的前驱指针

    evenTail->next = L; // 偶数部分尾部连接到头节点
    L->prior = evenTail; // 更新头节点的前驱指针

    L->next = oddHead->next; // 头节点连接到奇数部分头部
    oddHead->next->prior = L; // 更新奇数部分头部的前驱指针

    // 释放辅助节点
    free(oddHead);
    free(evenHead);
}