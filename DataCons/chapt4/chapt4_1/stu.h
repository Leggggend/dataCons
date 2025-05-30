// 任务描述
// 本关任务：编写一个算法，将数组A中的n个元素A[0]至A[n-1]循环右移k位。要求算法时间复杂度为O（n），空间复杂度为O（1）

// 相关知识
// 为了完成本关任务，你需要掌握：1.一维数组，2.数组的遍历。

// 编程要求
// 根据提示，在右侧编辑器填写算法函数，实现将大小为n的数据元素数组a中的元素循环右移k位。要求函数原型为：
// void ShiftRightCircular(ElemType a[],int n,int k)
// 其中k的值可为负整数，表示循环左移；ElemType已经在后台测试程序中定义。

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：10，5；（输入的是n与k的值）
// 预期输出：
//  6 7 8 9 10 1 2 3 4 5

// 测试输入：10，-3；
// 预期输出：
//  4 5 6 7 8 9 10 1 2 3

// 考虑到题目要求时间复杂度为线性，因此不能逐个暴力移动，再加上空间复杂度，几乎就是要求在原数组上进行移动了
void ShiftRightCircular(ElemType a[],int n,int k) {
    if (n <= 0) return; // 如果数组为空，直接返回

    k = k % n;
    if (k < 0) k = n + k; // 转换为正数的右移

    for (int start = 0, count = 0; count < n; start++) {
        int current = start;
        ElemType temp = a[start];

        do {
            int next = (current + k) % n; // 计算下一个位置
            ElemType temp2 = a[next];
            a[next] = temp;
            temp = temp2;
            current = next;
            count++;
        } while (current != start); // 当回到起点时结束循环
    }
}