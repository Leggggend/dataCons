// �������񣺱�дһ������ʵ�ֲ��뻡��
// ����ԭ�ͣ�status InsertArc(ALGraph &G,KeyType v,KeyType w)��
// ����˵����v��w�Ǻ�G�ж���ؼ���������ͬ�ĸ���ֵ�������������ͼG�����ӻ�<v,w>���ɹ�����OK�����򷵻�ERROR��
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.ͼ�ĸ��2.�ڽӱ�3.���뻡���������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���InsertArc�ı�д��
// �������ʱ��Լ�����ײ巨��
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ������������Ϊ�������к͹�ϵ�����У���-1��Ϊ�������,������v��w��ֵ����ȷ��������ͼ���ڽӱ���ٵ��ú���InsertArc���뻡<v,w>�������ɹ�ʱ��������ж����Լ���ϵ���ݡ�
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  6 8
// Ԥ�������
// 5 ���Ա� 2 3
// 8 ���� 3 2
// 7 ������ 1 3 0
// 6 ����ͼ 1 2 0
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  6 5
// Ԥ������� ���뻡����ʧ��
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  16 15
// Ԥ������� ���뻡����ʧ��

status InsertArc(ALGraph& G, KeyType v, KeyType w)
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    // ���ҹؼ���Ϊv�Ķ���λ��
    if (G.vexnum < 2) return INFEASIBLE;

    int indexv = -1;
    int indexw = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (indexv < 0 || indexw < 0) {    // ����
            int k = G.vertices[i].data.key;
            if (k == v)
                indexv = i;
            if (k == w)
                indexw = i;
        } else break;
    }
    if (indexv < 0 || indexw < 0) return ERROR; // û���ҵ�����v��w

    ArcNode* p;
    ArcNode* pnew;

    // ���ԭ�еĻ�
    p = G.vertices[indexv].firstarc;
    while (p) {
        if (p->adjvex == indexw) return ERROR;   // �����Ѿ�����
        p = p->nextarc;
    }

    //  ��v����
    p = G.vertices[indexv].firstarc;
    pnew = (ArcNode*)malloc(sizeof(ArcNode));
    pnew->adjvex = indexw;
    pnew->nextarc = p;
    G.vertices[indexv].firstarc = pnew;

    //  ��w����
    p = G.vertices[indexw].firstarc;
    pnew = (ArcNode*)malloc(sizeof(ArcNode));
    pnew->adjvex = indexv;
    pnew->nextarc = p;
    G.vertices[indexw].firstarc = pnew;

    G.arcnum++;

    return OK;
    /********** End **********/
}