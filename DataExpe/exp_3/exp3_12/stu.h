// ��������
// �������񣺱�дһ������ʵ�ֶ������������
// ����ԭ�ͣ�status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))��
// ����˵�����Զ�����T���а��������Visit��һ������ָ����βΣ���ʹ�øú����Խ�����������ÿ�������ú���Visit����һ����һ�Ρ�
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.��������2.��������3.������������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���LevelOrderTraverse�ı�д
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ��������Ϊ��������������еı�źͽ��ֵ�����У�����������������еı��Ϊ0ʱ��ʾ������������磺 6 4 d  ��ʾ��4��d���Ľ�������������еı��Ϊ6�� 0 0 null���������ǡ�������ݸ����д����Ķ������İ���������С�
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null
// Ԥ������� 
//  1,a 2,b 3,c 4,d 5,e

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//�������������T
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if (!T) {
        return ERROR;
    }

    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        visit(p);
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }

    return OK;
    /********** End **********/
}