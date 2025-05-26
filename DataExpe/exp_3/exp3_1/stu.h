// 任务描述
// 本关任务：编写一个函数创建二叉树。
// 函数原型：status CreateBiTree(BiTree &T,TElemType definition[])；
// 功能说明：根据带空子树的二叉树先序遍历序列definition（注意该数组元素类型为TElemType），构造一个如下图所示的二叉链表T（要求二叉树T中各结点关键字具有唯一性）。根指针指向根结点，不需要在根结点之上再增加头结点。

// 相关知识
// 为了完成本关任务，你需要掌握：1.二叉树，2.二叉链表，3.创建二叉树的语义。
// 二叉树结点类型定义：

// typedef int KeyType; 
// typedef struct {  //二叉树结点数据类型定义
//      KeyType  key;
//      char others[20];
// } TElemType; 
// typedef struct BiTNode{  //二叉链表结点的定义
//       TElemType  data;
//       struct BiTNode *lchild,*rchild;
// } BiTNode, *BiTree;
// **相关类型定义详见简介部分。**
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数CreateBiTree的编写。本题允许通过增加其它函数来辅助实现本关任务。

// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试。
// 下列输入序列为二叉树带空子树的先序遍历结点序列，每个结点对应一个整型的关键字和一个字符串，当关键字为0时，表示空子树，为-1表示输入结束；正确创建二叉树后，通过输出先序和中序遍历序列检验正确性。

// 测试输入：1 a 2 b 0 null  0 null 3 c 4 d  0 null  0 null 5 e  0 null  0 null -1 null
// 预期输出：
//  1,a 2,b 3,c 4,d 5,e
//  2,b 1,a 4,d 3,c 5,e
// 测试输入：1 a 2 b 0 null  0 null 3 c 3 d  0 null  0 null 5 e  0 null  0 null -1 null
// 预期输出：关键字不唯一


BiTNode* LocateNode(BiTree T, KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!T) return NULL;
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        if (p->data.key == e) return p;
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    return NULL;
    /********** End **********/
}

status CreateBiTree(BiTree &T, TElemType definition[]) {
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
    static int index = 0; // 使用静态变量记录当前处理位置
    static BiTree root = NULL; // 记录整棵树的根，用于检查关键字唯一性
    // 初始化处理
    if (index == 0) root = NULL; // 重置根节点指针
    if (definition[index].key == -1) return OK;
    else if (definition[index].key == 0) {
        T = NULL;
        index++;
        return OK;
    }
    if (LocateNode(root, definition[index].key)) return ERROR;
    // 创建新节点
    T = (BiTree)malloc(sizeof(BiTNode));
    if (!T) return OVERFLOW;
    T->data.key = definition[index].key;
    strcpy(T->data.others, definition[index].others);
    T->lchild = T->rchild = NULL;
    // 记录根节点
    if (index == 0) root = T;
    index++;
    // 递归创建左右子树
    if (CreateBiTree(T->lchild, definition) == ERROR) return ERROR;
    if (CreateBiTree(T->rchild, definition) == ERROR) return ERROR;
    return OK;
}