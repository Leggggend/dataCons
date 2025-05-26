// ��������
// �������񣺱�дһ������������������
// ����ԭ�ͣ�status CreateBiTree(BiTree &T,TElemType definition[])��
// ����˵�������ݴ��������Ķ����������������definition��ע�������Ԫ������ΪTElemType��������һ������ͼ��ʾ�Ķ�������T��Ҫ�������T�и����ؼ��־���Ψһ�ԣ�����ָ��ָ�����㣬����Ҫ�ڸ����֮��������ͷ��㡣

// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.��������2.��������3.���������������塣
// ������������Ͷ��壺

// typedef int KeyType; 
// typedef struct {  //����������������Ͷ���
//      KeyType  key;
//      char others[20];
// } TElemType; 
// typedef struct BiTNode{  //����������Ķ���
//       TElemType  data;
//       struct BiTNode *lchild,*rchild;
// } BiTNode, *BiTree;
// **������Ͷ��������鲿�֡�**
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���CreateBiTree�ı�д����������ͨ��������������������ʵ�ֱ�������

// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԡ�
// ������������Ϊ�����������������������������У�ÿ������Ӧһ�����͵Ĺؼ��ֺ�һ���ַ��������ؼ���Ϊ0ʱ����ʾ��������Ϊ-1��ʾ�����������ȷ������������ͨ��������������������м�����ȷ�ԡ�

// �������룺1 a 2 b 0 null  0 null 3 c 4 d  0 null  0 null 5 e  0 null  0 null -1 null
// Ԥ�������
//  1,a 2,b 3,c 4,d 5,e
//  2,b 1,a 4,d 3,c 5,e
// �������룺1 a 2 b 0 null  0 null 3 c 3 d  0 null  0 null 5 e  0 null  0 null -1 null
// Ԥ��������ؼ��ֲ�Ψһ


BiTNode* LocateNode(BiTree T, KeyType e)
//���ҽ��
{
    // �������ﲹ����룬��ɱ�������
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
/*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
    static int index = 0; // ʹ�þ�̬������¼��ǰ����λ��
    static BiTree root = NULL; // ��¼�������ĸ������ڼ��ؼ���Ψһ��
    // ��ʼ������
    if (index == 0) root = NULL; // ���ø��ڵ�ָ��
    if (definition[index].key == -1) return OK;
    else if (definition[index].key == 0) {
        T = NULL;
        index++;
        return OK;
    }
    if (LocateNode(root, definition[index].key)) return ERROR;
    // �����½ڵ�
    T = (BiTree)malloc(sizeof(BiTNode));
    if (!T) return OVERFLOW;
    T->data.key = definition[index].key;
    strcpy(T->data.others, definition[index].others);
    T->lchild = T->rchild = NULL;
    // ��¼���ڵ�
    if (index == 0) root = T;
    index++;
    // �ݹ鴴����������
    if (CreateBiTree(T->lchild, definition) == ERROR) return ERROR;
    if (CreateBiTree(T->rchild, definition) == ERROR) return ERROR;
    return OK;
}