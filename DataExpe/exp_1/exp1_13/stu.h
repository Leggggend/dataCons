// 任务描述
// 本关任务：编写两个函数实现将顺序表的数据元素的读写文件。
// 函数原型：status SaveList(SqList L,char FileName[])
// 函数原型：status LoadList(SqList &L,char FileName[])

// 功能说明：
// SaveList：如果线性表L不存在，返回INFEASIBLE；否则将线性表L的全部元素写入到文件名为FileName的文件中，返回OK。
// LoadList：如果线性表L存在，表示L中已经有数据，读入数据会覆盖原数据造成数据丢失，返回INFEASIBLE；否则将文件名为FileName的数据读入到线性表L中，返回OK。本实验不考虑用追加的方式读入文件数据追加到现有线性表中。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.顺序表的定义，3.文件操作。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数SaveList和LoadList的编写。不能使用前面关卡实现的函数InitList和ListInsert。

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：0；此时表示对不存在的线性表进行写文件操作,或表示读入文件数据覆盖已存在的线性表导致数据丢失。
// 预期输出：
// INFEASIBLE

// 测试输入：1 11 12 13 14 15 0，第一个数1表示对一个已存在的线性表进行操作，后续是一个以0结束的数据元素序列。
// 预期输出：
// 5
// 11 12 13 14 15

status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    // 如果线性表不存在
    if (!L.elem) {
        return INFEASIBLE;
    }
    FILE* fp = fopen(FileName, "w");
    if (!fp) {
        return INFEASIBLE;
    }

    // fwrite(L.elem, sizeof(L.elem), 1, fp);

    // 写入线性表的长度
    fwrite(&L.length, sizeof(L.length), 1, fp);

    // 写入线性表的元素
    for (int i = 0; i < L.length; i++) {
        fwrite(&L.elem[i], sizeof(ElemType), 1, fp);
    }

    fclose(fp);
    return OK;

    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    // 如果线性表已存在
    if (L.elem) {
        return INFEASIBLE;
    } 

    // 初始化线性表
    L.elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;

    // 打开文件
    FILE* fp = fopen(FileName, "r");
    if (!fp) {
        free(L.elem); // 释放已分配的内存
        L.elem = NULL;
        return INFEASIBLE; // 文件打开失败
    }

    // 读取线性表的长度
    fread(&L.length, sizeof(L.length), 1, fp);

    // 动态调整存储容量
    if (L.length > L.listsize) {
        L.listsize = L.length;
        L.elem = (ElemType*)realloc(L.elem, sizeof(ElemType) * L.listsize);
        if (!L.elem) {
            fclose(fp);
            return INFEASIBLE; // 内存重新分配失败
        }
    }

    // 读取线性表的元素
    for (int i = 0; i < L.length; i++) {
        fread(&L.elem[i], sizeof(ElemType), 1, fp);
    }

    fclose(fp);
    return OK;

    /********** End **********/
}