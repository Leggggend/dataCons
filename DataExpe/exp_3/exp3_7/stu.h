// ��������
// �������񣺱�дһ������ʵ�ֽ�����
// ����ԭ�ͣ�status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)��
// ����˵����e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ��LRΪ0��1��c�Ǵ������㣻����LRΪ0����1��������c��T�У���Ϊ�ؼ���Ϊe�Ľ�������Һ��ӽ�㣬���e��ԭ������������������Ϊ���c��������������OK���������ʧ�ܣ�����ERROR��
// �ر�أ���LRΪ-1ʱ����Ϊ�������룬ԭ�������Ϊc����������
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.��������2.��������3.����������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���InsertNode�ı�д
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ��������Ϊ��������������еı�źͽ��ֵ�����У�����������������еı��Ϊ0ʱ��ʾ������������磺 6 4 d  ��ʾ��4��d���Ľ�������������еı��Ϊ6�� 0 0 null���������ǡ������������e��LR�Լ�c��ֵ����ͨ�����������������������ȷ�ԡ�
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null  3  0 6 f
// Ԥ������� 
//  1,a 2,b 3,c 6,f 4,d 5,e
//  2,b 1,a 6,f 4,d 3,c 5,e
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null  3  0 3 f
// ��������ؼ������ظ����޷�������3 f
// Ԥ�������
//  �������ʧ��
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null  10  0 6 f
// ���������޹ؼ���Ϊ10�Ľ�㣬�޷�������6 f
// Ԥ������� 
//  �������ʧ��

// ���ݹؼ��ֲ��ҽ��
BiTNode* LocateNodeByKey(BiTree T, KeyType e) {
    if (!T) {
        return NULL;
    }
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        if (p->data.key == e) {
            return p;
        } 
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    return NULL;
}

status InsertNode(BiTree &T, KeyType e, int LR, TElemType c) {
    BiTNode* node = LocateNodeByKey(T, c.key);
    if (node) return ERROR; // ���ظ��ؼ���
    BiTNode* des = LocateNodeByKey(T, e);
    if (!des) return ERROR; // û���ҵ�����λ��
    BiTNode* ltemp = des->lchild;
    BiTNode* rtemp = des->rchild;

    BiTNode* newnode = (BiTNode*)malloc(sizeof(BiTNode));
    if (!newnode) return ERROR;
    newnode->data.key = c.key;
    strcpy(newnode->data.others, c.others);
    newnode->lchild = newnode->rchild = NULL;

    if (LR == -1) { // ��Ϊ��������
        newnode->rchild = T;
        T = newnode;
        return OK;
    } else if (LR == 0) { // ��Ϊ����������
        des->lchild = newnode;
        newnode->rchild = ltemp;
        return OK;
    } else if (LR == 1) { // ��Ϊ����������
        des->rchild = newnode;
        newnode->rchild = rtemp;
        return OK;
    }

    return ERROR;
}