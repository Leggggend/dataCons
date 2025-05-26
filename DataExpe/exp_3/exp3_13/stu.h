// 任务描述
// 本关任务：编写两个函数，分别实现将二叉树结点的数据写到文件中，和读入文件中的结点数据创建二叉树。
// 函数原型： 
// status SaveBiTree(BiTree T,char FileName[])；
// status LoadBiTree(BiTree &T,char FileName[])；
// 功能说明：函数SaveBiTree实现将二叉树T写到文件名为FileName的文件中，返回OK；函数 LoadBiTree读入文件名为FileName的结点数据，创建二叉树。
// 相关知识
// 为了完成本关任务，你需要掌握：1.二叉树，2.二叉链表，3.文件操作。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数SaveBiTree和LoadBiTree的编写。允许自定义辅助函数。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入为结点在满二叉树中的编号和结点值的序列，当结点在满二叉树中的编号为0时表示输入结束。例如： 6 4 d  表示（4，d）的结点在满二叉树中的编号为6； 0 0 null代表结束标记。
// 测试程序依据这个序列创建二叉树T，调用SaveBiTree将二叉树T的结点数据写到文件中；再调用函数 LoadBiTree读入结点数据，重新创建二叉树，并通过先序和中序遍历检验正确性。
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null
// 预期输出： 
//  1,a 2,b 3,c 4,d 5,e
//  2,b 1,a 4,d 3,c 5,e

// 递归函数：将二叉树的结点数据写入文件
status SaveNode(BiTree node, FILE* fp) {
    if (node == NULL) {
        fprintf(fp, "0 null ");
        return OK;
    }
    fprintf(fp, "%d %s ", node->data.key, node->data.others);

    if (SaveNode(node->lchild, fp) != OK) {
        printf("左子树保存失败\n");
        return ERROR;
    }
    if (SaveNode(node->rchild, fp) != OK) {
        printf("右子树保存失败\n");
        return ERROR;
    }
    return OK;
}

status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE *fp = fopen(FileName, "w");
    if (!fp) {
        return ERROR; // 打开文件失败
    }

    if (SaveNode(T, fp) != OK) {
        printf("调用失败\n");
        fclose(fp);
        return ERROR; // 调用递归函数
    }
    fclose(fp);  // 关闭文件
    return OK;
    /********** End 1 **********/
}

// 递归函数：读取文件中的结点数据，创建二叉树
status LoadNode(BiTree &node, FILE* fp) {
    KeyType key;
    char others[20];
    int x = fscanf(fp, "%d %s ", &key, others);
    if (x == EOF) {
        printf("文件读取结束\n");
        return OK; 
    } else if (x != 2) {
        printf("读取格式错误\n");
        return ERROR;
    }

    if (key == 0) {
        node = NULL;
        return OK;
    }

    node = (BiTree)malloc(sizeof(BiTNode));  
    if (!node) return ERROR; // 内存分配失败  
    node->data.key = key;
    strcpy(node->data.others, others);
    node->lchild = node->rchild = NULL;
    
    if(LoadNode(node->lchild, fp) != OK) {
        printf("左子树创建失败\n");
        return ERROR; // 递归创建左子树
    } 
    if(LoadNode(node->rchild, fp) != OK) {
        printf("右子树创建失败\n");
        return ERROR; // 递归创建右子树
    }
    return OK;
}

status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if (T) {
        printf("T已存在\n");
        return ERROR;
    }
    FILE *fp = fopen(FileName, "r");
    if (!fp) {
        printf("文件打开失败\n");
        return ERROR; 
    }

    if (LoadNode(T, fp) != OK) {
        printf("调用失败\n");
        fclose(fp);
        return ERROR; // 调用递归函数
    }
    fclose(fp); 
    return OK;
    /********** End 2 **********/
}