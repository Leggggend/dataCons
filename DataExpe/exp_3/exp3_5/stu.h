// ��������
// �������񣺱�дһ������ʵ�ֽ�㸳ֵ
// ����ԭ�ͣ�status Assign(BiTree &T,KeyType e,TElemType value)��
// ����˵����e�Ǻ�T�н��ؼ���������ͬ�ĸ���ֵ�����ҽ��ؼ��ֵ���e�Ľ�㣬���ý��ֵ�޸ĳ�value������OK��Ҫ����ؼ��ֱ���Ψһ�ԣ����������ʧ�ܣ�����ERROR��
// ��ʾ�����ڱ����ж���ʵ��LocateNode()��������ɱ�������
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.��������2.��������3.��㸳ֵ�����塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ��� Assign �ı�д
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ��������Ϊ��������������еı�źͽ��ֵ�����У�����������������еı��Ϊ0ʱ��ʾ������������磺 6 4 d  ��ʾ��4��d���Ľ�������������еı��Ϊ6�� 0 0 null���������ǡ������������e��value��ֵ����ȷ��ɸ�ֵ��ͨ��������������������м�����ȷ�ԡ�
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   3  10 new
// Ԥ������� 
//  1,a 2,b 10,new 4,d 5,e
//  2,b 1,a 4,d 10,new 5,e
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   3  3 new
// Ԥ������� 
//  1,a 2,b 3,new 4,d 5,e
//  2,b 1,a 4,d 3,new 5,e
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   3  2 new
// Ԥ������� ��ֵ����ʧ��        
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null   10  20 new
// Ԥ������� ��ֵ����ʧ��

BiTNode* LocateNodeByKey(BiTree T, KeyType e)
//���ݹؼ��ֲ��ҽ��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
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

    /********** End **********/
}

// �������������ı�Ų��ҽڵ�
BiTNode* LocateNodeByIndex(BiTree T, int index) {
    if (!T) {
        return NULL; 
    }
    // ʹ�ö���ʵ�ֲ�α���
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T; 

    int currentIndex = 1;

    while (front < rear) {
        BiTree p = queue[front++]; 
        if (currentIndex == index) {
            return p; // �����ǰ�ڵ��ŵ���Ŀ���ţ����ظýڵ�
        }

        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;

        currentIndex++; 
    }

    return NULL; 
}

status Assign(BiTree &T, KeyType e, TElemType value)
//ʵ�ֽ�㸳ֵ����������ͨ������������������ʵ�ֱ�������
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    // �ָ��ݱ���ҽ��
    BiTree p = LocateNodeByIndex(T, e);
    // ���ݹؼ����ҽ��
    BiTree q = LocateNodeByKey(T, value.key);

    if ((q && q == p) || (!q && p)) { // ������ڹؼ����ұ��ƥ����߹ؼ��ֲ����ڵ���Ŵ���
        p->data.key = value.key;
        strcpy(p->data.others, value.others);
        return OK;    
    } 
    return ERROR;
    /********** End **********/
}
