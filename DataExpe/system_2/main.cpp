// 基于链式存储结构的线性表实现
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "def.h" // 数据类型的相关定义
#include "func.h" // 相关功能的实现

int main(void) {
    // 初始化管理表
    LISTS Lists;
    Lists.length = 0;
    Lists.listsize = 10; 
    for (int i = 0; i < Lists.listsize; i++) {
        Lists.elem[i].name[0] = '\0';
    }
    char ListName[30];
    char FileName[50];
    int index = -1; // 存储当前线性表
    int op = 1;
    while (op) {
        system("cls");	// 清屏
        printf("\n\n");
        printf("      Menu for Linear Table On Link Structure \n");
        printf("---------------------------------------------------------\n");
        printf("          1. InitList        2. DestroyList\n");
        printf("          3. ClearList       4. ListEmpty\n");
        printf("          5. ListLength      6. GetElem\n");
        printf("          7. LocateElem      8. PriorElem\n");
        printf("          9. NextElem       10. ListInsert\n");
        printf("         11. ListDelete     12. ListTrabverse\n");
        printf("         13. ReverseList    14. RemoveNthFromEnd\n");
        printf("         15. SortList       16. AddList\n");
        printf("         17. LocateList     18. RemoveList\n");
        printf("         19. SaveList       20. LoadList\n");
        printf("         21. ShowAllLists\n");
        printf("          0. Exit\n");
        printf("---------------------------------------------------------\n");
        printf("    所有的线性表将存储在一个已初始化的总管理表中，\n");
        printf("    所有操作均对其中的线性表进行操作。\n");
        printf("    请输入您的操作 [0 ~ 21]: ");
        scanf("%d", &op);        
        printf("---------------------------------------------------------\n");
        switch (op) {
        case 1:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0 || Lists.elem[index].L != NULL) {
                printf("线性表不存在或该线性表已包含元素!\n");
            } else if (InitList(Lists.elem[index].L) == OK) {
                printf("线性表初始化成功!\n");
                printf("请输入线性表中的元素, 以0结束: ");
                ElemType e;
                scanf("%d",&e);
                while (e) {
                    if (ListInsert(Lists.elem[index].L, ListLength(Lists.elem[index].L) + 1, e) == OK) {
                        scanf("%d", &e);                    
                    } else {
                        printf("\n输入失败!\n");
                        break;
                    }
                }
                printf("\n输入成功!\n");
            } else {
                printf("\n线性表初始化失败!\n");
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 2:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else if (DestroyList(Lists.elem[index].L) == OK) {
                printf("摧毁成功!\n");
            } else {
                printf("操作失败!\n");    
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 3:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else
            if (ClearList(Lists.elem[index].L) == OK) {
                printf("清空成功!\n");
            } else {
                printf("操作失败!\n");   
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 4:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                int x = ListEmpty(Lists.elem[index].L);
                if (x == INFEASIBLE) {
                    printf("操作失败!\n");
                } else if (x == TRUE) {
                    printf("线性表为空!\n");
                } else {
                    printf("线性表非空!\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 5:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                int x = ListLength(Lists.elem[index].L);
                if (x == INFEASIBLE) {
                    printf("操作失败!\n");
                } else {
                    printf("线性表长度为%d!\n", x);
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 6:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                int i;
                ElemType e;
                printf("请输入位置:");
                scanf("%d", &i);    
                if (GetElem(Lists.elem[index].L, i, e) == OK) {
                    printf("线性表中第%d个元素为:%d!\n", i, e);
                } else {
                    printf("操作失败!\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 7:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                ElemType e;
                printf("请输入元素:");
                scanf("%d", &e);
                int x = LocateElem(Lists.elem[index].L, e);   
                if (x > 0) {
                    printf("该元素在线性表第%d个位置!\n", x);
                } else {
                    printf("操作失败!\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 8:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                ElemType pre, cur;
                printf("请输入元素:");
                scanf("%d", &cur);
                if (PriorElem(Lists.elem[index].L, cur, pre) == OK) {
                    printf("该元素的前驱为:%d!\n", pre);
                } else {
                    printf("操作失败!\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 9:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                ElemType nex, cur;
                printf("请输入元素:");
                scanf("%d", &cur);
                if (NextElem(Lists.elem[index].L, cur, nex) == OK) {
                    printf("该元素的后继为:%d!\n", nex);
                } else {
                    printf("操作失败!\n");
                }             
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 10:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                int i;            
                ElemType e;
                printf("请输入位置:");
                scanf("%d", &i);
                printf("请输入元素:");
                scanf("%d", &e); 
                if (ListInsert(Lists.elem[index].L, i, e) == OK) {
                    printf("插入成功!\n");
                } else {
                    printf("操作失败!\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 11:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                int i;
                ElemType e;
                printf("请输入位置:");
                scanf("%d", &i);
                if (ListDelete(Lists.elem[index].L, i, e) == OK) {
                    printf("删除成功, 被删除元素为%d!\n", e);
                } else {
                    printf("操作失败!\n");
                }
            } 
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 12: 
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                printf("线性表中元素为...\n");
                if(ListTrabverse(Lists.elem[index].L) == INFEASIBLE) {
                    printf("操作失败!\n");
                } else {
                    printf("遍历成功!\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 13:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                if (ReverseList(Lists.elem[index].L) == OK) {
                    printf("翻转成功!\n");
                } else {
                    printf("操作失败！\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 14: 
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                int k;
                ElemType e;
                printf("请输入指定的k: ");
                scanf("%d", &k);
                if (RemoveNthFromEnd(Lists.elem[index].L, k, e) == OK) {
                    printf("删除成功！被删除的元素是%d。\n", e);
                } else {
                    printf("操作失败!\n");
                }
            }   
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 15:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!\n");
            } else {
                SortList(Lists.elem[index].L);
                printf("排序成功!\n");
            }    
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 16:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            if (LocateList(Lists, ListName) > 0) {
                printf("线性表已存在!\n");
            } else {
                if (AddList(Lists, ListName) == OK) {
                    printf("添加成功\n");
                } else {
                    printf("操作失败\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 17:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName);
            if (index > 0) {
                printf("在总表中第%d个!\n", index);
            } else {
                printf("操作失败\n");
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 18:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            if (RemoveList(Lists, ListName) == OK) {
                printf("移除成功\n");
            } else {
                printf("操作失败!\n");
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        case 19:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!");
            } else {
                printf("请输入文件名：");
                scanf("%s", FileName);
                if (SaveList(Lists.elem[index].L, FileName) == OK) {
                    printf("保存成功!");
                } else {
                    printf("操作失败!");
                }                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;   
        case 20:
            printf("请输入线性表名称:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("线性表不存在!!");
            } else {
                printf("请输入文件名:");
                scanf("%s", FileName);
                if (LoadList(Lists.elem[index].L, FileName) == OK) {
                    printf("读取成功!");
                } else {
                    printf("操作失败!");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;  
        case 21:
            if (ShowAllLists(Lists) == INFEASIBLE) {
                printf("目前没有可操作的线性表!\n");
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;             
        case 0:
            break;
        } // end of switch
    } // end of while
    printf("欢迎下次使用本系统!\n");
    getchar();getchar();
    return 0;
} // end of main()