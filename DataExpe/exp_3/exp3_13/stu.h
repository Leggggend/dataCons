// ��������
// �������񣺱�д�����������ֱ�ʵ�ֽ���������������д���ļ��У��Ͷ����ļ��еĽ�����ݴ�����������
// ����ԭ�ͣ� 
// status SaveBiTree(BiTree T,char FileName[])��
// status LoadBiTree(BiTree &T,char FileName[])��
// ����˵��������SaveBiTreeʵ�ֽ�������Tд���ļ���ΪFileName���ļ��У�����OK������ LoadBiTree�����ļ���ΪFileName�Ľ�����ݣ�������������
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.��������2.��������3.�ļ�������
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���SaveBiTree��LoadBiTree�ı�д�������Զ��帨��������
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ��������Ϊ��������������еı�źͽ��ֵ�����У�����������������еı��Ϊ0ʱ��ʾ������������磺 6 4 d  ��ʾ��4��d���Ľ�������������еı��Ϊ6�� 0 0 null���������ǡ�
// ���Գ�������������д���������T������SaveBiTree��������T�Ľ������д���ļ��У��ٵ��ú��� LoadBiTree���������ݣ����´�������������ͨ��������������������ȷ�ԡ�
// �������룺1 1 a    2 2 b     3 3 c    6 4 d    7 5 e    0 0 null
// Ԥ������� 
//  1,a 2,b 3,c 4,d 5,e
//  2,b 1,a 4,d 3,c 5,e

// �ݹ麯�������������Ľ������д���ļ�
status SaveNode(BiTree node, FILE* fp) {
    if (node == NULL) {
        fprintf(fp, "0 null ");
        return OK;
    }
    fprintf(fp, "%d %s ", node->data.key, node->data.others);

    if (SaveNode(node->lchild, fp) != OK) {
        printf("����������ʧ��\n");
        return ERROR;
    }
    if (SaveNode(node->rchild, fp) != OK) {
        printf("����������ʧ��\n");
        return ERROR;
    }
    return OK;
}

status SaveBiTree(BiTree T, char FileName[])
//���������Ľ������д�뵽�ļ�FileName��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 1 *********/
    FILE *fp = fopen(FileName, "w");
    if (!fp) {
        return ERROR; // ���ļ�ʧ��
    }

    if (SaveNode(T, fp) != OK) {
        printf("����ʧ��\n");
        fclose(fp);
        return ERROR; // ���õݹ麯��
    }
    fclose(fp);  // �ر��ļ�
    return OK;
    /********** End 1 **********/
}

// �ݹ麯������ȡ�ļ��еĽ�����ݣ�����������
status LoadNode(BiTree &node, FILE* fp) {
    KeyType key;
    char others[20];
    int x = fscanf(fp, "%d %s ", &key, others);
    if (x == EOF) {
        printf("�ļ���ȡ����\n");
        return OK; 
    } else if (x != 2) {
        printf("��ȡ��ʽ����\n");
        return ERROR;
    }

    if (key == 0) {
        node = NULL;
        return OK;
    }

    node = (BiTree)malloc(sizeof(BiTNode));  
    if (!node) return ERROR; // �ڴ����ʧ��  
    node->data.key = key;
    strcpy(node->data.others, others);
    node->lchild = node->rchild = NULL;
    
    if(LoadNode(node->lchild, fp) != OK) {
        printf("����������ʧ��\n");
        return ERROR; // �ݹ鴴��������
    } 
    if(LoadNode(node->rchild, fp) != OK) {
        printf("����������ʧ��\n");
        return ERROR; // �ݹ鴴��������
    }
    return OK;
}

status LoadBiTree(BiTree &T,  char FileName[])
//�����ļ�FileName�Ľ�����ݣ�����������
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 2 *********/
    if (T) {
        printf("T�Ѵ���\n");
        return ERROR;
    }
    FILE *fp = fopen(FileName, "r");
    if (!fp) {
        printf("�ļ���ʧ��\n");
        return ERROR; 
    }

    if (LoadNode(T, fp) != OK) {
        printf("����ʧ��\n");
        fclose(fp);
        return ERROR; // ���õݹ麯��
    }
    fclose(fp); 
    return OK;
    /********** End 2 **********/
}