// �����ڽӱ��ͼʵ��
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"  // �������͵���ض���
#include "func.h" // ��ع��ܵ�ʵ��

int main(void) {
    int i, k, result;
    int gindex = 0;           // ��ǰ����ͼ���
    int vindex = 0;            // ����λ��
    VertexType V[30];           // ����
    KeyType VR[100][2];         // ��
    ALGraph* g = NULL;
    Graphs Gs;                  // ͼ����
    Gs = (Graphs)malloc(sizeof(ALGraphs));
    Gs->length = 0;
    Gs->maxsize = 10;
    for (i = 0; i < 10; i++) {
        Gs->elem[i].G = NULL;
    }

    KeyType u, v;                  // �ؼ���
    VertexType value;           // ����
    char FileName[50];
    char GName[20];

    int op = 1;
    while (op) {
        system("cls");	// ����
        printf("\n\n");
        printf("         Menu For Graph On Adjacency List Structure \n");
        printf("-------------------------------------------------------------\n");
        printf("         1. CreateGraph             2. DestroyGraph\n");
        printf("         3. LocateVex               4. PutVex\n");
        printf("         5. FirstAdjVex             6. NextAdjVex\n");
        printf("         7. InsertVex               8. DeleteVex\n");
        printf("         9. InsertArc              10. DeleteArc\n");
        printf("        11. DFSTraverse            12. BFSTraverse\n");
        printf("        13. SavaGraph              14. LoadGraph\n");
        printf("        15. AddGraph               16. RemoveGraph\n");
        printf("        17. LocateGraph            18. VerticesSetLessThanK\n");
        printf("        19. ShortestPathLength     20. ConnectedComponentsNums\n");
        printf("        21. TraverseGraphs         22. CheckFile\n");
        printf("         0. Exit\n");
        printf("------------------------------------------------------------\n");
        printf("   ��ѡ�����Ĳ��� [0 ~ 21]: ");
        scanf("%d", &op);
        printf("------------------------------------------------------------\n");

        switch (op) {
        case 1: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n�����붥����Ϣ��");
                i = 0;
                do {
                    scanf("%d%s", &V[i].key, V[i].others);
                } while (V[i++].key != -1);
                printf("\n���������Ϣ��");
                i = 0;
                do {
                    scanf("%d%d", &VR[i][0], &VR[i][1]);
                } while (VR[i++][0] != -1);
                if (CreateCraph(*(Gs->elem[gindex].G), V, VR) != OK)
                    printf("\n����ʧ�ܣ�");
                else printf("\n�����ɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 2: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                if (DestroyGraph(*(Gs->elem[gindex].G)) != OK)
                    printf("\n����ʧ�ܣ�");
                else printf("\n���ٳɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 3: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫ���ҵĶ���ؼ��֣�");
                scanf("%d", &u);
                vindex = LocateVex(*(Gs->elem[gindex].G), u);
                if (vindex < 0) printf("\n���㲻���ڣ�");
                else {
                    VertexType* da = &(Gs->elem[gindex].G->vertices)[vindex].data;
                    printf("\n��%d�������� %d %s��", vindex, da->key, da->others);
                }
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 4: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫ�޸ĵĶ���ؼ��֣�");
                scanf("%d", &u);
                printf("\n�������޸ĺ��ֵ��");
                scanf("%d %s", &value.key, value.others);
                if (PutVex(*(Gs->elem[gindex].G), u, value) != OK) printf("\n�޸�ʧ�ܣ�");
                else printf("\n�޸ĳɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 5: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫ���ҵĶ���ؼ��֣�");
                scanf("%d", &u);
                int vindex = FirstAdjVex(*(Gs->elem[gindex].G), u);
                if (vindex < 0) printf("\n�������ٽӶ��㣡");
                else {
                    VertexType* da = &(Gs->elem[gindex].G->vertices)[vindex].data;
                    printf("\n�ö���ĵ�һ�ڽӶ���Ϊ %d %s��", da->key, da->others);
                }
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 6: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫ���ҵĶ���ؼ��ֺ�һ�ڽӶ��㣺");
                scanf("%d %d", &u, &v);
                int vindex = NextAdjVex(*(Gs->elem[gindex].G), u, v);
                if (vindex < 0) printf("\n�������ٽӶ��㣡");
                else {
                    VertexType* da = &(Gs->elem[gindex].G->vertices)[vindex].data;
                    printf("\n�ö������һ�ڽӶ���Ϊ%d %s��", da->key, da->others);
                }
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 7: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫ����Ķ�����Ϣ��");
                scanf("%d %s", &value.key, value.others
                );
                if (InsertVex(*(Gs->elem[gindex].G), value) != OK) printf("\n����ʧ�ܣ�");
                else printf("\n����ɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 8: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫɾ���Ķ���ؼ��֣�");
                scanf("%d", &u);
                if (DeleteVex(*(Gs->elem[gindex].G), u) != OK) printf("\nɾ��ʧ�ܣ�");
                else printf("\nɾ���ɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 9: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫ���ӵĻ���ͷ��β�ؼ��֣�");
                scanf("%d %d", &u, &v);
                if (InsertArc(*(Gs->elem[gindex].G), u, v) != OK) printf("\n����ʧ�ܣ�");
                else printf("\n����ɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 10: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫɾ���Ļ���ͷ��β�ؼ��֣�");
                scanf("%d %d", &u, &v);
                if (DeleteArc(*(Gs->elem[gindex].G), u, v) != OK) printf("\nɾ��ʧ�ܣ�");
                else printf("\nɾ���ɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 11: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n�������������ʼ����ؼ��֣�");
                scanf("%d", &u);
                int start = LocateVex(*(Gs->elem[gindex].G), u);
                if (start < 0) printf("\n���㲻���ڣ�");
                else {
                    if (DFSTraverse(*(Gs->elem[gindex].G), start, visit) != OK) printf("\n����ʧ�ܣ�");
                    else printf("\n�����ɹ���");
                }

            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 12: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n�������������ʼ����ؼ��֣�");
                scanf("%d", &u);
                int start = LocateVex(*(Gs->elem[gindex].G), u);
                if (start < 0) printf("\n���㲻���ڣ�");
                else {
                    if (BFSTraverse(*(Gs->elem[gindex].G), start, visit) != OK) printf("\n����ʧ�ܣ�");
                    else printf("\n�����ɹ���");
                }

            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 13: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n�������ļ�����");
                scanf("%s", FileName);
                if (SaveGraph(*(Gs->elem[gindex].G), FileName) != OK) printf("\n����ʧ�ܣ�");
                else printf("\n����ɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 14: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            if (AddGraph(Gs, GName) != OK) printf("\n���ʧ�ܣ�");
            else {
                printf("\n�������ļ�����");
                scanf("%s", FileName);
                if (LoadGraph(*(Gs->elem[Gs->length - 1].G), FileName) != OK) printf("\n��ȡʧ�ܣ�");
                else {
                    printf("\n��ȡ�ɹ���");
                }
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 15: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            if (AddGraph(Gs, GName) != OK) printf("\n���ʧ�ܣ�");
            else printf("\n��ӳɹ���");
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 16: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                if (RemoveGraph(Gs, GName) != OK) printf("\n�Ƴ�ʧ�ܣ�");
                else printf("\n�Ƴ��ɹ���");
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 17: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else printf("\n�ǵ�%d��ͼ��", gindex + 1);
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 18: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫ���ҵĶ��㣺");
                scanf("%d", &u);
                printf("\n���������k��");
                scanf("%d", &k);
                KeyType ans[MAX_VERTEX_NUM];
                g = Gs->elem[gindex].G;
                int result = VerticesSetLessThanK(*g, u, k, ans);
                if (result < 0) printf("\n����");
                else {
                    printf("\n���������Ķ�����%d����", result);
                    for (i = 0; i < result; i++) {
                        printf("\n%d %s", g->vertices[ans[i]].data.key, g->vertices[ans[i]].data.others);
                    }
                }
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 19: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                printf("\n������Ҫ���ҵ��������㣺");
                scanf("%d %d", &u, &v);
                result = ShortestPathLength(*(Gs->elem[gindex].G), u, v);
                if (result < 0) printf("\n������·����");
                else printf("\n���·������Ϊ%d��", result);
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 20: {
            printf("\n������Ҫ������ͼ�����ƣ�");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\nͼ�����ڣ�");
            else {
                result = ConnectedComponentsNums(*(Gs->elem[gindex].G));
                printf("\n��%d����ͨ������", result);
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 21: {
            if (TraverseGraphs(Gs) != OK) printf("\n�����ͼ��");
            else printf("\n�����ɹ���");
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 22: {
            char c[100];
            printf("\n������Ҫ�鿴���ļ�����");
            scanf("%s", FileName);
            FILE* fptr;
            if ((fptr = fopen(FileName, "r")) == NULL) {
                printf("Error! opening file");
                fclose(fptr);
            } else {
                while (fgets(c, sizeof(c), fptr) != NULL) {
                    printf("\n��ȡ����: %s", c);
                }
                fclose(fptr);
            }
            printf("\n�����������...");
            getchar();getchar();
            break;
        }
        case 0:
            break;
        } // end of switch
    } // end of while
    printf("��ӭ�´�ʹ�ñ�ϵͳ!\n");
    getchar();getchar();
    return 0;
} // end of main()