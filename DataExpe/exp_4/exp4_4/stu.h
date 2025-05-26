// �������񣺱�дһ������ʵ�ֶ��㸳ֵ��
// ����ԭ�ͣ�stasus PutVex(ALGraph &G,KeyType u,VertexType value)��
// ����˵����u�Ǻ�G�ж���ؼ���������ͬ�ĸ���ֵ����������ǶԹؼ���Ϊu�Ķ��㸳ֵvalue��Ҫ��ؼ��־���Ψһ�ԣ����ɹ���ֵ����OK�����򷵻�ERROR��
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.ͼ�ĸ��2.�ڽӱ�3.���㸳ֵ���������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���PutVex�ı�д��
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ������������Ϊ�������к͹�ϵ�����У���-1��Ϊ�������,�����ǹؼ���u��value��ֵ����ȷ��������ͼ���ڽӱ�󣬵��ú���PutVex������u���в��ҵ����㣬��ֵvalue����ֵ�����ɹ�ʱ��������ж������ݡ�
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  6 9 ����ͼ
// Ԥ������� 5 ���Ա� 8 ���� 7 ������ 9 ����ͼ
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  10 9 ����ͼ
// Ԥ������� ��ֵ����ʧ��
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  6 5 ����ͼ
// Ԥ������� ��ֵ����ʧ��

#include <string.h>
status PutVex(ALGraph& G, KeyType u, VertexType value)
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    if (G.vexnum == 0) return INFEASIBLE;
    int index = -1;
    int bad = -1;      // ����ظ��ؼ���
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == value.key) {
            bad = i; break;
        }
        if (G.vertices[i].data.key == u) {
            index = i; break;
        }
    }
    if (index >= 0 && (bad < 0 || bad == index)) {
        G.vertices[index].data.key = value.key;
        strcpy(G.vertices[index].data.others, value.others);
        return OK;
    } else return ERROR;
    /********** End **********/
}
