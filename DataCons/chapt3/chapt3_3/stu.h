// 任务描述
// 本关任务：假设称正读和反读都相同的字符序列为“回文”，例如，‘abba’和‘abcba’ 是回文，‘abcde’和‘ababab’则不是回文。试写一个算法判别读入的一个以‘@’为 结束符的字符序列是否是“回文”。 

// 相关知识
// 为了完成本关任务，你需要掌握：1.栈及其运算，2.队列及其运算。

// 编程要求
// 要求必须利用已通过的第1关栈的函数和第2关队列的函数，实现本关的任务。本关测试程序中已将前2关的函数包含在本关中，可以直接按函数名调用，如果前2关未通过，未按要求完成本关题目得分不超过本题分数的50%。
// 根据提示，在右侧编辑器完成函数：int isPalindrome(char *str) 的定义，满足任务要求。

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：abcdedcba@
// 预期输出：YES

// 测试输入：1234567@
// 预期输出：NO

int isPalindrome(char *str)
//判断字符串str是否回文，是则返回1，否则返回0
{
/**********begin**********/
    int curc = 0;
    int length = 0;
    int start;

    TWSTACK cstack;
    inistack(cstack);

    // 获取字符串长度
    for (curc = 0; str[curc] != '@'; curc++) {
        length++;
    }
    // 入栈
    for (curc = 0; curc < length/2; curc++) {
        // cstack.elem[cstack.top1++] = str[curc];
        push(cstack, 1, str[curc]);
    }

    start = (length/2 == (length-1)/2) ? (length/2 + 1) : (length/2);

    for (curc = start; curc < length; curc++) {
        char c;
        pop(cstack, 1, c);
        if (str[curc] != c) {
            return 0;
        }
    }
    return 1;

/********** end **********/
}
