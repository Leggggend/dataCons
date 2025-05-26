// 基于邻接表的图实现
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"  // 数据类型的相关定义
#include "func.h" // 相关功能的实现

int main(void) {
    int i, k, result;
    int gindex = 0;           // 当前操作图编号
    int vindex = 0;            // 顶点位序
    VertexType V[30];           // 顶点
    KeyType VR[100][2];         // 边
    ALGraph* g = NULL;
    Graphs Gs;                  // 图表集合
    Gs = (Graphs)malloc(sizeof(ALGraphs));
    Gs->length = 0;
    Gs->maxsize = 10;
    for (i = 0; i < 10; i++) {
        Gs->elem[i].G = NULL;
    }

    KeyType u, v;                  // 关键字
    VertexType value;           // 顶点
    char FileName[50];
    char GName[20];

    int op = 1;
    while (op) {
        system("cls");	// 清屏
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
        printf("   请选择您的操作 [0 ~ 21]: ");
        scanf("%d", &op);
        printf("------------------------------------------------------------\n");

        switch (op) {
        case 1: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入顶点信息：");
                i = 0;
                do {
                    scanf("%d%s", &V[i].key, V[i].others);
                } while (V[i++].key != -1);
                printf("\n请输入边信息：");
                i = 0;
                do {
                    scanf("%d%d", &VR[i][0], &VR[i][1]);
                } while (VR[i++][0] != -1);
                if (CreateCraph(*(Gs->elem[gindex].G), V, VR) != OK)
                    printf("\n创建失败！");
                else printf("\n创建成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 2: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                if (DestroyGraph(*(Gs->elem[gindex].G)) != OK)
                    printf("\n销毁失败！");
                else printf("\n销毁成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 3: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要查找的顶点关键字：");
                scanf("%d", &u);
                vindex = LocateVex(*(Gs->elem[gindex].G), u);
                if (vindex < 0) printf("\n顶点不存在！");
                else {
                    VertexType* da = &(Gs->elem[gindex].G->vertices)[vindex].data;
                    printf("\n第%d个顶点是 %d %s！", vindex, da->key, da->others);
                }
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 4: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要修改的顶点关键字：");
                scanf("%d", &u);
                printf("\n请输入修改后的值：");
                scanf("%d %s", &value.key, value.others);
                if (PutVex(*(Gs->elem[gindex].G), u, value) != OK) printf("\n修改失败！");
                else printf("\n修改成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 5: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要查找的顶点关键字：");
                scanf("%d", &u);
                int vindex = FirstAdjVex(*(Gs->elem[gindex].G), u);
                if (vindex < 0) printf("\n不存在临接顶点！");
                else {
                    VertexType* da = &(Gs->elem[gindex].G->vertices)[vindex].data;
                    printf("\n该顶点的第一邻接顶点为 %d %s！", da->key, da->others);
                }
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 6: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要查找的顶点关键字和一邻接顶点：");
                scanf("%d %d", &u, &v);
                int vindex = NextAdjVex(*(Gs->elem[gindex].G), u, v);
                if (vindex < 0) printf("\n不存在临接顶点！");
                else {
                    VertexType* da = &(Gs->elem[gindex].G->vertices)[vindex].data;
                    printf("\n该顶点的下一邻接顶点为%d %s！", da->key, da->others);
                }
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 7: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要插入的顶点信息：");
                scanf("%d %s", &value.key, value.others
                );
                if (InsertVex(*(Gs->elem[gindex].G), value) != OK) printf("\n插入失败！");
                else printf("\n插入成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 8: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要删除的顶点关键字：");
                scanf("%d", &u);
                if (DeleteVex(*(Gs->elem[gindex].G), u) != OK) printf("\n删除失败！");
                else printf("\n删除成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 9: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要增加的弧的头和尾关键字：");
                scanf("%d %d", &u, &v);
                if (InsertArc(*(Gs->elem[gindex].G), u, v) != OK) printf("\n插入失败！");
                else printf("\n插入成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 10: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要删除的弧的头和尾关键字：");
                scanf("%d %d", &u, &v);
                if (DeleteArc(*(Gs->elem[gindex].G), u, v) != OK) printf("\n删除失败！");
                else printf("\n删除成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 11: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入遍历的起始顶点关键字：");
                scanf("%d", &u);
                int start = LocateVex(*(Gs->elem[gindex].G), u);
                if (start < 0) printf("\n顶点不存在！");
                else {
                    if (DFSTraverse(*(Gs->elem[gindex].G), start, visit) != OK) printf("\n遍历失败！");
                    else printf("\n遍历成功！");
                }

            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 12: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入遍历的起始顶点关键字：");
                scanf("%d", &u);
                int start = LocateVex(*(Gs->elem[gindex].G), u);
                if (start < 0) printf("\n顶点不存在！");
                else {
                    if (BFSTraverse(*(Gs->elem[gindex].G), start, visit) != OK) printf("\n遍历失败！");
                    else printf("\n遍历成功！");
                }

            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 13: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入文件名：");
                scanf("%s", FileName);
                if (SaveGraph(*(Gs->elem[gindex].G), FileName) != OK) printf("\n保存失败！");
                else printf("\n保存成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 14: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            if (AddGraph(Gs, GName) != OK) printf("\n添加失败！");
            else {
                printf("\n请输入文件名：");
                scanf("%s", FileName);
                if (LoadGraph(*(Gs->elem[Gs->length - 1].G), FileName) != OK) printf("\n读取失败！");
                else {
                    printf("\n读取成功！");
                }
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 15: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            if (AddGraph(Gs, GName) != OK) printf("\n添加失败！");
            else printf("\n添加成功！");
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 16: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                if (RemoveGraph(Gs, GName) != OK) printf("\n移除失败！");
                else printf("\n移除成功！");
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 17: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else printf("\n是第%d个图！", gindex + 1);
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 18: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要查找的顶点：");
                scanf("%d", &u);
                printf("\n请输入距离k：");
                scanf("%d", &k);
                KeyType ans[MAX_VERTEX_NUM];
                g = Gs->elem[gindex].G;
                int result = VerticesSetLessThanK(*g, u, k, ans);
                if (result < 0) printf("\n错误！");
                else {
                    printf("\n符合条件的顶点有%d个：", result);
                    for (i = 0; i < result; i++) {
                        printf("\n%d %s", g->vertices[ans[i]].data.key, g->vertices[ans[i]].data.others);
                    }
                }
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 19: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                printf("\n请输入要查找的两个顶点：");
                scanf("%d %d", &u, &v);
                result = ShortestPathLength(*(Gs->elem[gindex].G), u, v);
                if (result < 0) printf("\n不存在路径！");
                else printf("\n最短路径长度为%d！", result);
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 20: {
            printf("\n请输入要操作的图的名称：");
            scanf("%s", GName);
            gindex = LocateGraph(Gs, GName);
            if (gindex < 0) printf("\n图不存在！");
            else {
                result = ConnectedComponentsNums(*(Gs->elem[gindex].G));
                printf("\n有%d个联通分量！", result);
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 21: {
            if (TraverseGraphs(Gs) != OK) printf("\n请添加图！");
            else printf("\n遍历成功！");
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 22: {
            char c[100];
            printf("\n请输入要查看的文件名：");
            scanf("%s", FileName);
            FILE* fptr;
            if ((fptr = fopen(FileName, "r")) == NULL) {
                printf("Error! opening file");
                fclose(fptr);
            } else {
                while (fgets(c, sizeof(c), fptr) != NULL) {
                    printf("\n读取内容: %s", c);
                }
                fclose(fptr);
            }
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }
        case 0:
            break;
        } // end of switch
    } // end of while
    printf("欢迎下次使用本系统!\n");
    getchar();getchar();
    return 0;
} // end of main()