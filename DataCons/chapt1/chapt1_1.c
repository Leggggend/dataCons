// 任务描述
// 本关任务：试编写算法，计算函数值：n! * 2^n
// 函数原型：int suanfa（int a[], int n,int arrsize)
// 功能说明：计算 i!*2^i的值并存入数组 a[0..arrsize-1]的第 i-1 个分量中(i=1,2,…,n)。假设计算机中允许的整数最大值为 INT_MAX，则当 n>arrsize 或对某个 1<=k<=n,使得k!*2^k>INT_MAX 时，函数返回值为0；无错误时返回1；

// 相关知识
// 为了完成本关任务，你需要掌握：1.数组的概念，2.如何遍历数组。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数suanfa（int a[], int n,int arrsize)。

// 测试说明
// 测试程序会自动读取输入数据n和arrsize的值，对你编写的代码进行测试，并输出结果。

// 测试输入：5，10；
// 预期输出：2 8 48 3840 46080

// 测试输入：16，20；
// 预期输出：ERROR

// 测试输入：16，10；
// 预期输出：ERROR
#include<limits.h>

int suanfa(int a[], int n,int arrsize) {
    a[0] = 2; //n = i = 1

    if (n > arrsize || n <= 0){
        return 0;
    } //第一种错误，过大或者非正

    else {
        for (int i = 2; i <= n; i++) { //i = 2开始，填a[1]...
            long ans = (long)a[i-2] * 2 * i;
            if (ans > INT_MAX) {
                return 0; //第二种错误，结果过大
            }
            else {
                a[i-1] = (int)ans;
            }
        }
        return 1; //无错误
    }
}