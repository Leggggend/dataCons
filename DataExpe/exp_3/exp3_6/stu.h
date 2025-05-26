// ��������
// �������񣺱�дһ������ʵ�ֻ���ֵܽ��
// ����ԭ�ͣ�BiTNode* GetSibling(BiTree T,KeyType e)��
// e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ�����ҽ��ؼ��ֵ���e�Ľ����ֵܽ�㣬�������ֵܽ��ָ�롣�������ʧ�ܣ�����NULL��
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.��������2.��������3.����ֵܽ������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ��� GetSibling �ı�д
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ��������Ϊ��������������еı�źͽ��ֵ�����У�����������������еı��Ϊ0ʱ��ʾ������������磺 6 4 d  ��ʾ��4��d���Ľ�������������еı��Ϊ6�� 0 0 null���������ǡ������������e��ֵ�����Ϊ���ҵ����ֵܽ��ֵ��
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null    3
// Ԥ������� 2,b
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   22 
// Ԥ������� ���ֵܽ�� 
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   1 
// Ԥ������� ���ֵܽ��

// BiTNode* GetSibling(BiTree T,KeyType e)
// //ʵ�ֻ���ֵܽ��
// {
//     // �������ﲹ����룬��ɱ�������
//     /********** Begin *********/


//     /********** End **********/
// }


// ���ҹؼ��ֵ��� e �Ľڵ�ĸ��ڵ�
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

// ����ֵܽ��
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



// ֱ�ӻ���ֵܽڵ�
BiTNode* GetSibling(BiTree T, KeyType e) {
    if (!T) {
        return NULL; 
    }
    if (T->lchild && T->lchild->data.key == e) {
        return T->rchild; // �����Һ�����Ϊ�ֵܽڵ�
    }
    if (T->rchild && T->rchild->data.key == e) {
        return T->lchild; // ����������Ϊ�ֵܽڵ�
    }
    BiTNode* result = GetSibling(T->lchild, e);
    if (result) return result; // ��������������ҵ������ؽ��
    return GetSibling(T->rchild, e); // �������������в���
}
