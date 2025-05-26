// �������񣺱�дһ������ʵ��ɾ������
// ����ԭ�ͣ�status DeleteArc(ALGraph &G, KeyType v, KeyType w)��
// ����˵����v��w�Ǻ�G�ж���ؼ���������ͬ�ĸ���ֵ�������������ͼG��ɾ����<v,w>���ɹ�����OK�����򷵻�ERROR��
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.ͼ�ĸ��2.�ڽӱ�3.ɾ�������������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���DeleteArc�ı�д��
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ������������Ϊ�������к͹�ϵ�����У���-1��Ϊ�������,������v��w��ֵ����ȷ��������ͼ���ڽӱ���ٵ��ú���DeleteArcɾ����<v,w>�������ɹ�ʱ��������ж����Լ���ϵ���ݡ�
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  5 6
// Ԥ�������
// 5 ���Ա� 2
// 8 ���� 2
// 7 ������ 1 3 0
// 6 ����ͼ 2 0
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  8 5
// Ԥ������� ɾ��������ʧ��
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  16 5
// Ԥ������� ɾ��������ʧ��

status DeleteArc(ALGraph& G, KeyType v, KeyType w)
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/

    if (G.vexnum < 2 || !G.arcnum) return INFEASIBLE;

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

    ArcNode* pre, * todlt;
    int flag = 0; // ����Ƿ���ڻ���

    //  ��v����
    todlt = G.vertices[indexv].firstarc;
    pre = NULL;
    while (todlt) {
        if (todlt->adjvex == indexw) {   // �ҵ�����
            if (!pre) {    // ��һ���ڵ�
                G.vertices[indexv].firstarc = NULL;
                free(todlt);
            } else {
                pre->nextarc = todlt->nextarc;
                free(todlt);
            }
            flag = 1;
            break;
        } else {
            pre = todlt;
            todlt = todlt->nextarc;
        }
    }

    if (!flag) return ERROR;   // ���߲�����

    //  ��w����
    todlt = G.vertices[indexw].firstarc;
    pre = NULL;
    while (todlt) {
        if (todlt->adjvex == indexv) {   // �ҵ�����
            if (!pre) {    // ��һ���ڵ�
                G.vertices[indexw].firstarc = NULL;
                free(todlt);
            } else {
                pre->nextarc = todlt->nextarc;
                free(todlt);
            }
            break;
        } else {
            pre = todlt;
            todlt = todlt->nextarc;
        }
    }

    G.arcnum--;

    return OK;

    /********** End **********/
}