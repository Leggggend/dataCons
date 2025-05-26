// 任务描述
// 本关任务：编写一个矩阵加法。

// 相关知识
// 为了完成本关任务，你需要掌握：1.数组的压缩存储，2.稀疏矩阵。
// 在后台测试程序中，已经定义了如下稀疏矩阵三元组顺序表类型。
// #define  MAXSIZE 10000
// typedef struct  {
//    int       i,j;//非零元行、列下标
//    ElemType    e;
//  } Triple;        //三元组定义

// typedef struct  {
//    Triple  data[MAXSIZE+1];   //三元组从下标1开始存放
//    int  mu,nu,tu;         //对于矩阵的行数、列数和非零元素值
//  } TSMatrix;              //三元组顺序表的定义

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数ADD的编写。
// 函数原型：TSMatrix ADD(TSMatrix A,TSMatrix B);

// 测试说明
// 平台会对你编写的代码进行测试,首先依次输入2个矩阵的行列数以及非零元素个数，接着输入相应的三元组，输出运算结果。

// 测试输入：6 7 5
//        1 1 5  1 2 10  3 1 2  5 7 6  6 6 6
//        6 7 4
//        1 1 -5  2 2 13  3 1 20  5 7 2  

// 预期输出： 6 7 5
//           1 2 10  2 2 13  3 1 20  5 7 8  6 6 6  

TSMatrix ADD(TSMatrix A,TSMatrix B) {
    TSMatrix C;
    int p1 = 1, p2 = 1, p3 = 1; // 初始化指针

    // 初始化结果矩阵
    C.mu = A.mu;
    C.nu = A.nu;
    C.tu = 0; // 结果矩阵的非零元素个数初始化为0

    // 检查矩阵维度是否一致
    if (A.mu != B.mu || A.nu != B.nu) {
        printf("矩阵维度不一致，无法进行加法运算。\n");
        return C; // 返回空结果
    }

    // 遍历两个矩阵的三元组
    while (p1 <= A.tu && p2 <= B.tu) {
        if (A.data[p1].i == B.data[p2].i) {
            if (A.data[p1].j == B.data[p2].j) {
                // 行列位置相同，相加
                ElemType sum = A.data[p1].e + B.data[p2].e;
                if (sum != 0) {
                    C.data[p3].i = A.data[p1].i;
                    C.data[p3].j = A.data[p1].j;
                    C.data[p3].e = sum;
                    p3++;
                    C.tu++;
                }
                p1++;
                p2++;
            } else if (A.data[p1].j < B.data[p2].j) {
                // A的列位置较小，直接存入结果矩阵
                C.data[p3] = A.data[p1];
                p3++;
                C.tu++;
                p1++;
            } else {
                // B的列位置较小，直接存入结果矩阵
                C.data[p3] = B.data[p2];
                p3++;
                C.tu++;
                p2++;
            }
        } else if (A.data[p1].i < B.data[p2].i) {
            // A的行位置较小，直接存入结果矩阵
            C.data[p3] = A.data[p1];
            p3++;
            C.tu++;
            p1++;
        } else {
            // B的行位置较小，直接存入结果矩阵
            C.data[p3] = B.data[p2];
            p3++;
            C.tu++;
            p2++;
        }
    }

    // 处理剩余的三元组
    while (p1 <= A.tu) {
        C.data[p3] = A.data[p1];
        p3++;
        C.tu++;
        p1++;
    }

    while (p2 <= B.tu) {
        C.data[p3] = B.data[p2];
        p3++;
        C.tu++;
        p2++;
    }

    return C;
}