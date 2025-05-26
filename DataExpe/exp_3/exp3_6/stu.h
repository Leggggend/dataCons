// 任务描述
// 本关任务：编写一个函数实现获得兄弟结点
// 函数原型：BiTNode* GetSibling(BiTree T,KeyType e)；
// e是和T中结点关键字类型相同的给定值；查找结点关键字等于e的结点的兄弟结点，返回其兄弟结点指针。如果查找失败，返回NULL。
// 相关知识
// 为了完成本关任务，你需要掌握：1.二叉树，2.二叉链表，3.获得兄弟结点的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数 GetSibling 的编写
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入为结点在满二叉树中的编号和结点值的序列，当结点在满二叉树中的编号为0时表示输入结束。例如： 6 4 d  表示（4，d）的结点在满二叉树中的编号为6； 0 0 null代表结束标记。接着输入的是e的值。输出为查找到的兄弟结点值。
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null    3
// 预期输出： 2,b
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   22 
// 预期输出： 无兄弟结点 
// 测试输入：1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   1 
// 预期输出： 无兄弟结点

// BiTNode* GetSibling(BiTree T,KeyType e)
// //实现获得兄弟结点
// {
//     // 请在这里补充代码，完成本关任务
//     /********** Begin *********/


//     /********** End **********/
// }


// 查找关键字等于 e 的节点的父节点
BiTNode* GetParent(BiTree T, KeyType e) {
    if (!T) {
        return NULL; 
    }

    if (T->lchild && T->lchild->data.key == e) {
        return T; 
    } else if (T->rchild && T->rchild->data.key == e) {
        return T; 
    }
    BiTNode* parent = GetParent(T->lchild, e);
    if (parent) {
        return parent; 
    } else {
        return GetParent(T->rchild, e);         
    }
}

// 获得兄弟结点
// BiTNode* GetSibling(BiTree T, KeyType e) {
//     if (!T || T->data.key == e) {
//         return NULL; 
//     } 
//     BiTNode* parent;
//     parent = GetParent(T, e);
//     if (parent) {
//         if (parent->lchild && parent->lchild->data.key == e)
//         {
//             return parent->rchild;
//         } else if (parent->rchild && parent->rchild->data.key == e){
//             return parent->lchild;
//         }        
//     }
//     return NULL; 
// }



// 直接获得兄弟节点
BiTNode* GetSibling(BiTree T, KeyType e) {
    if (!T) {
        return NULL; 
    }
    if (T->lchild && T->lchild->data.key == e) {
        return T->rchild; // 返回右孩子作为兄弟节点
    }
    if (T->rchild && T->rchild->data.key == e) {
        return T->lchild; // 返回左孩子作为兄弟节点
    }
    BiTNode* result = GetSibling(T->lchild, e);
    if (result) return result; // 如果在左子树中找到，返回结果
    return GetSibling(T->rchild, e); // 否则在右子树中查找
}
