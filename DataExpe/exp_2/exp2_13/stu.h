// 任务描述
// 本关任务：编写二个函数，分别实现将线性表的数据元素写入到文件中，和将文件中的数据元素读入到线性表
// 函数原型：status SaveList(LinkList L,char FileName[])
// 功能说明：如果线性表L不存在，返回INFEASIBLE；否则将线性表L的全部元素写入到文件名为FileName的文件中，返回OK。
// 函数原型：status LoadList(LinkList &L,char FileName[])
// 功能说明：如果线性表L存在，表示L中已经有数据，读入数据会覆盖原数据造成数据丢失，返回INFEASIBLE；否则将文件名为FileName的数据读入到线性表L中，返回OK。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.单链表的定义，3. 文件操作。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数SaveList和LoadList的编写

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：

// 测试输入：0，此时表示对不存在的线性表进行写文件操作，对存在的线性表进行读操作。
// 预期输出：
// INFEASIBLE
// INFEASIBLE

// 测试输入：1 11 12 13 14 15 0，第一个数1表示对一个已存在的线性表进行写操作，后续是一个以0结束的数据元素序列。完成写入后，再对一个未初始化的线性表对该文件进行读操作。
// 预期输出：
// OK
// OK
// 11 12 13 14 15

status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/

    if (L == NULL) {
        return INFEASIBLE;
    }
    FILE *fp = fopen(FileName, "wb");
    if (fp == NULL) {
        return ERROR;
    }
    LNode *p = L->next;
    while (p != NULL) {
        fwrite(&(p->data), sizeof(ElemType), 1, fp);
        p = p->next;
    }
    fclose(fp);
    return OK;

    /********** End 1 **********/
}

status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/

    if (L != NULL) {
        return INFEASIBLE;
    }
    FILE *fp = fopen(FileName, "rb");
    if (fp == NULL) {
        return ERROR;
    }
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *r = L;
    ElemType e;
    while (fread(&e, sizeof(ElemType), 1, fp) == 1) {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = NULL;
        r->next = s;
        r = s;
    }
    fclose(fp);
    return OK;
    /********** End 2 **********/
}
