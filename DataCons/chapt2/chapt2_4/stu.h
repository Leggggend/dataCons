// 任务描述
// 本关任务：已知A、B和C为3个递增有序的线性表，现要求对A表做如下操作，删除那些既在B中出现，也在C中出现的元素。以带表头结点的单链表作为线性表的物理结构，编写实现上述操作的算法。
// 函数原型：void  TriLinkList(LinkList  A,LinkList  B,LinkList  C)；

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表，2.顺序表。
// 相关定义：
// typedef int ElemType;
// typedef struct node
//    { 
//         ElemType data;
//         struct node *next;
//    } NODE, *LinkList;

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数TriLinkList(LinkList  A,LinkList  B,LinkList  C)。要求算法效率尽可能高。

// 测试说明
// 平台会自动读取输入三个线性表的数据，对你编写的代码进行测试，并输出结果。

// 测试输入：1  3  5  7  9  10  11  12  20  0
//                  3  9  10  11  30 0
//                  3  6  7  9 11  13  50  0
// 预期输出：1  5  7  10  12  20

// void  TriLinkList(LinkList  A,LinkList  B,LinkList  C) { 
//     // 三个链表是有头结点的
//     LinkList pa = A;    
//     LinkList pA = pa->next; // 指向第一个节点

//     LinkList pB = B->next; 
//     LinkList pb = pB; // 作为比较的起始位置
//     LinkList pC = C->next;
//     LinkList pc = pC;

//     for (; pA != NULL; pA = pA->next, pa = pa->next) {
//         int x = pA->data;

//         for (pB = pb; pB != NULL; pB = pB->next) {
//             if ( x < pB->data) {
//                 pb = pb->next; // 基础指针后移
//                 continue;
//             } else if (x = pB->data) {
//                 pb = pB; // 更新比较起点
//                 for (pC = pc; pC !=NULL; pC = pC->next) {
//                     if (x < pC->data) {
//                         pc = pc->next; // 基础指针后移
//                         continue;
//                     } else if (x == pC->data) { // 找到了
//                         pc = pC;
//                         // 删除x
//                         pA->data = 0;
//                     } else break;
//                 }
//             } else break;
//         } 
//     }

//     pa = A;
//     pA = pa->next;

//     while (pA) {
//         LinkList pa1 = pA;        
//         if (pA->data == 0) {
//             pa->next = pA->next;
//             pA = pA->next;
//             free(pa1);
//         } else {
//             pa = pa->next;        
//             pA = pA->next;            
//         }

//     }
// }

void TriLinkList(LinkList A, LinkList B, LinkList C) {
    LinkList pa = A; // 指向A链表的当前节点
    LinkList pA = pa->next; // 指向A链表的下一个节点，用于遍历

    LinkList pB = B->next; 
    LinkList pC = C->next; 

    while (pA != NULL) { // 遍历A链表
        int x = pA->data; 
        int foundInB = 0; // 标记是否在B中找到
        int foundInC = 0; // 标记是否在C中找到

        // 在B链表中查找x
        while (pB != NULL && pB->data <= x) {
            if (pB->data == x) {
                foundInB = 1; // 在B中找到x
                break;
            }
            pB = pB->next; // 继续查找
        }

        // 如果在B中找到x，再在C链表中查找x
        if (foundInB) {
            while (pC != NULL && pC->data <= x) {
                if (pC->data == x) {
                    foundInC = 1; // 在C中找到x
                    break;
                }
                pC = pC->next; // 继续查找
            }
        }

        // 如果x在B和C中都找到，删除A链表中的节点
        if (foundInB && foundInC) {
            pa->next = pA->next; // 删除节点
            free(pA); // 释放节点内存
            pA = pa->next; // 更新pA指针
        } else {
            pa = pA; // 更新pa指针
            pA = pA->next; // 移动到下一个节点
        }
    }
}