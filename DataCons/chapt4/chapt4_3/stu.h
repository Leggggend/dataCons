// 任务描述
// 本关任务：编写一个实现字符串的替换操作Replace（&S,T,V）。

// 相关知识
// 为了完成本关任务，你需要掌握：
// 1.字符串以及字符串的基本操作;
// 2.字符串的堆分配存储结构，其数据类型定义：
// typedef struct {
//     char *ch;
//    int length;
// } HString;
// 3. Replace（&S,T,V）的语义：用V替换主串S中出现的所有与T相等的不重叠的子串。假定：S的串值为：`abc aaaaa 123`, T的串值为：`aa`, V的串值为：`#`， 则执行操作Replace（&S,T,V）后，S的串值为：`abc ##a 123`。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成Replace（&S,T,V）。

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：abc aaaaa 123
//        aa
//        #
// 预期输出：S的长度：11
//        abc ##a 123

// void Replace(HString &S, HString T, HString V) {

// }

void Replace(HString &S, HString T, HString V) {
    if (T.length == 0 || S.length == 0) {
        return; // 如果T为空字符串或S为空字符串，直接返回
    }

    // 创建一个临时字符串用于存储替换后的结果
    char *result = (char *)malloc(S.length + 1);
    if (result == NULL) {
        return; // 内存分配失败，直接返回
    }

    int i = 0; // 用于遍历原字符串
    int j = 0; // 用于填充结果字符串
    char *temp = S.ch; // 临时保存原字符串

    while (temp[i] != '\0') {
        // 检查当前字符是否是子串T的开始
        int match = 1;
        for (int k = 0; k < T.length; k++) {
            if (temp[i + k] != T.ch[k]) {
                match = 0;
                break;
            }
        }

        if (match) {
            // 如果匹配成功，复制替换字符串V到结果字符串
            strcpy(result + j, V.ch);
            j += V.length;
            i += T.length; // 跳过子串T的长度
        } else {
            // 如果不匹配，复制当前字符到结果字符串
            result[j++] = temp[i++];
        }
    }

    result[j] = '\0'; // 添加字符串结束符

    // 释放原字符串空间
    free(S.ch);
    if (result[j-1] == '!') {
        result[--j] = '\0';
    }
    S.ch = result; // 将结果字符串赋值给S
    S.length = j; // 更新S的长度
}