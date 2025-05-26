// 任务描述
// 本关任务：已知A、B和C为3个递增有序的线性表，现要求对A表做如下操作，删除那些既在B中出现，也在C中出现的元素。以顺序表作为线性表的物理结构，编写实现上述操作的算法。
// 函数原型：void  TriSqList(SqList  &A,SqList  B,SqList  C)；

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表，2.顺序表。
// 相关定义：
// typedef int ElemType;
// typedef struct
//    { 
//         ElemType *elem;
//         int length;
//         int listsize;
//     } SqList;

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数TriSqList(SqList  &A,SqList  B,SqList  C)。
// 要求算法效率尽可能高。

// 测试说明
// 平台会自动读取输入三个线性表的数据，对你编写的代码进行测试，并输出结果。

// 测试输入：1  3  5  7  9  10  11  12  20  0
//                  3  9  10  11  30 0
//                  3  6  7  9 11  13  50  0
// 预期输出：1  5  7  10  12  20

// void  TriSqList(SqList  &A,SqList  B,SqList  C) {
//     int indexA = 0;
//     int indexB = 0;    
//     int indexC = 0;

//     for (indexA = 0; indexA < A.length; indexA++) { //首先找出所有重复的元素
//         int x = A.elem[indexA];

//         for (int i = indexB; i < B.length; i++) { // 首先判断B中是否有x
//             if (x < B.elem[i]) { // 当B中i位当前值大于x时
//                 indexB++;
//                 continue;
//             } else if (x == B.elem[i]) { // 若有x
//                 indexB = i;
//                 for (int j = indexC; j < C.length; j++) { // 判断C中是否有x，与B的判断逻辑一样
//                     if (x < C.elem[j]) {
//                         indexC++;
//                         continue;
//                     } else if (x == C.elem[j]) {
//                         indexC = j;
//                         A.elem[indexA] = 0;
//                     } else{
//                         break;
//                     }
//                 }
//             } else { // 没有找到重复的x
//                 break;
//             }
//         }
//     }

//     for (int k = 0; k < A.length; k++) {
//         if (A.elem[k] == 0) {
//             for (int m = k; m < A.length - 1; m++) { // 移位
//                 A.elem[m] = A.elem[m + 1];
//             }
//         }
//     }
// }


void TriSqList(SqList &A, SqList B, SqList C) {
    int k = 0; // 用于记录A表中需要保留的元素数量

    for (int i = 0; i < A.length; i++) {
        int x = A.elem[i];
        int foundInB = 0, foundInC = 0;
        // 在B中查找x
        for (int j = 0; j < B.length; j++) {
            if (x == B.elem[j]) {
                foundInB = 1;
                break;
            } else if (x < B.elem[j]) { // B中当前值更大，直接结束匹配
                break;
            }
        }
        // 如果在B中找到x，再在C中查找x
        if (foundInB) {
            for (int j = 0; j < C.length; j++) {
                if (x == C.elem[j]) {
                    foundInC = 1;
                    break;
                } else if (x < C.elem[j]) {
                    break;
                }
            }
        }
        // 如果x不在B和C中同时出现，则保留x
        if (!foundInB || !foundInC) {
            A.elem[k++] = x;
        }
    }
    // 更新A的长度
    A.length = k;
}