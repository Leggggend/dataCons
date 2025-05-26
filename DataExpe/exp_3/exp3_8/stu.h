// ��������
// �������񣺱�дһ������ʵ�ֽ��ɾ��
// ����ԭ�ͣ�status DeleteNode(BiTree &T,KeyType e)��
// ����˵����e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ��ɾ��T�йؼ���Ϊe�Ľ�㣻ͬʱ�����ݸñ�ɾ���ĶȽ������ۣ�
// ��ؼ���Ϊe�Ľ���Ϊ0��ɾ�����ɣ�
// ��ؼ���Ϊe�Ľ���Ϊ1���ùؼ���Ϊe�Ľ�㺢�Ӵ��汻ɾ����eλ�ã�
// ��ؼ���Ϊe�Ľ���Ϊ2����e�������������ΪLC�����汻ɾ����eλ�ã���e�������������ΪRC����ΪLC�����ҽڵ����������
// �ɹ�ɾ�����󷵻�OK�����򷵻�ERROR��
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.��������2.��������3.ɾ���������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���DeleteNode�ı�д
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ��������Ϊ��������������еı�źͽ��ֵ�����У�����������������еı��Ϊ0ʱ��ʾ������������磺 6 4 d  ��ʾ��4��d���Ľ�������������еı��Ϊ6�� 0 0 null���������ǡ������������eֵ����ȷ���ɾ����ͨ��������������������м�����ȷ�ԡ�
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   1
// Ԥ������� 
//  2,b 3,c 4,d 5,e
//  2,b 4,d 3,c 5,e
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   10
//  Ԥ�������  ɾ������ʧ��

// ���ݹؼ��ֲ��ҽ��͸��ڵ�
BiTNode* LocateNodeByKey(BiTree T, KeyType e, BiTNode*& parent, int &islor) {
    if (!T) {
        return NULL;
    }
    parent = NULL;
    islor = 0;

    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        if (p->lchild && p->lchild->data.key == e) {
            parent = p;
            islor = 0;
        } else if (p->rchild && p->rchild->data.key == e) {
            parent = p;
            islor = 1;
        }

        if (p->data.key == e) {
            return p;
        } 
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    return NULL;
}

BiTNode* MostRightNode(BiTree &T) {
    BiTNode* msn = T;
    while (msn && msn->rchild) {
        msn = msn->rchild;
    }
    return msn;
}
status DeleteNode(BiTree &T, KeyType e)
//ɾ����㡣��������ͨ������������������ʵ�ֱ�������
{
    BiTNode* parent = NULL;
    int islor = 0;
    BiTNode* todelete = LocateNodeByKey(T, e, parent, islor);
    if (!todelete) return ERROR;

    BiTNode* ltemp = todelete->lchild; // ������
    BiTNode* rtemp = todelete->rchild; // ������
    BiTNode* msn = NULL; // ���ҽ��
    if (!ltemp && !rtemp) { // ��Ϊ0
        if (parent) {
            if (!islor) parent->lchild = NULL;
            else parent->rchild = NULL;
        } else {
            T = NULL; // ɾ�����ڵ�
        }
        free(todelete);
    } else if (!ltemp || !rtemp) { // ��Ϊ1
        BiTNode* child = ltemp ? ltemp : rtemp; // ��ȡ�ǿ�����
        if (parent) {
            if (!islor) parent->lchild = child;
            else parent->rchild = child;
        } else {
            T = child; // ɾ�����ڵ�
        }
        free(todelete);
    } else { // ��Ϊ2
        msn = MostRightNode(ltemp); // �ҵ������������ҽڵ�
        msn->rchild = rtemp; // ���������ҵ����ҽڵ���Һ�����
        if (parent) {
            if (!islor) parent->lchild = ltemp;
            else parent->rchild = ltemp;
        } else {
            T = ltemp; // ɾ�����ڵ�
        }
        free(todelete);
    }
    return OK;

}