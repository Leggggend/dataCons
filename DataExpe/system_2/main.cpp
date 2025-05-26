// ������ʽ�洢�ṹ�����Ա�ʵ��
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "def.h" // �������͵���ض���
#include "func.h" // ��ع��ܵ�ʵ��

int main(void) {
    // ��ʼ�������
    LISTS Lists;
    Lists.length = 0;
    Lists.listsize = 10; 
    for (int i = 0; i < Lists.listsize; i++) {
        Lists.elem[i].name[0] = '\0';
    }
    char ListName[30];
    char FileName[50];
    int index = -1; // �洢��ǰ���Ա�
    int op = 1;
    while (op) {
        system("cls");	// ����
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
        printf("    ���е����Ա��洢��һ���ѳ�ʼ�����ܹ�����У�\n");
        printf("    ���в����������е����Ա���в�����\n");
        printf("    ���������Ĳ��� [0 ~ 21]: ");
        scanf("%d", &op);        
        printf("---------------------------------------------------------\n");
        switch (op) {
        case 1:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0 || Lists.elem[index].L != NULL) {
                printf("���Ա����ڻ�����Ա��Ѱ���Ԫ��!\n");
            } else if (InitList(Lists.elem[index].L) == OK) {
                printf("���Ա��ʼ���ɹ�!\n");
                printf("���������Ա��е�Ԫ��, ��0����: ");
                ElemType e;
                scanf("%d",&e);
                while (e) {
                    if (ListInsert(Lists.elem[index].L, ListLength(Lists.elem[index].L) + 1, e) == OK) {
                        scanf("%d", &e);                    
                    } else {
                        printf("\n����ʧ��!\n");
                        break;
                    }
                }
                printf("\n����ɹ�!\n");
            } else {
                printf("\n���Ա��ʼ��ʧ��!\n");
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 2:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else if (DestroyList(Lists.elem[index].L) == OK) {
                printf("�ݻٳɹ�!\n");
            } else {
                printf("����ʧ��!\n");    
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 3:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else
            if (ClearList(Lists.elem[index].L) == OK) {
                printf("��ճɹ�!\n");
            } else {
                printf("����ʧ��!\n");   
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 4:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                int x = ListEmpty(Lists.elem[index].L);
                if (x == INFEASIBLE) {
                    printf("����ʧ��!\n");
                } else if (x == TRUE) {
                    printf("���Ա�Ϊ��!\n");
                } else {
                    printf("���Ա�ǿ�!\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 5:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                int x = ListLength(Lists.elem[index].L);
                if (x == INFEASIBLE) {
                    printf("����ʧ��!\n");
                } else {
                    printf("���Ա���Ϊ%d!\n", x);
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 6:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                int i;
                ElemType e;
                printf("������λ��:");
                scanf("%d", &i);    
                if (GetElem(Lists.elem[index].L, i, e) == OK) {
                    printf("���Ա��е�%d��Ԫ��Ϊ:%d!\n", i, e);
                } else {
                    printf("����ʧ��!\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 7:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                ElemType e;
                printf("������Ԫ��:");
                scanf("%d", &e);
                int x = LocateElem(Lists.elem[index].L, e);   
                if (x > 0) {
                    printf("��Ԫ�������Ա��%d��λ��!\n", x);
                } else {
                    printf("����ʧ��!\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 8:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                ElemType pre, cur;
                printf("������Ԫ��:");
                scanf("%d", &cur);
                if (PriorElem(Lists.elem[index].L, cur, pre) == OK) {
                    printf("��Ԫ�ص�ǰ��Ϊ:%d!\n", pre);
                } else {
                    printf("����ʧ��!\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 9:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                ElemType nex, cur;
                printf("������Ԫ��:");
                scanf("%d", &cur);
                if (NextElem(Lists.elem[index].L, cur, nex) == OK) {
                    printf("��Ԫ�صĺ��Ϊ:%d!\n", nex);
                } else {
                    printf("����ʧ��!\n");
                }             
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 10:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                int i;            
                ElemType e;
                printf("������λ��:");
                scanf("%d", &i);
                printf("������Ԫ��:");
                scanf("%d", &e); 
                if (ListInsert(Lists.elem[index].L, i, e) == OK) {
                    printf("����ɹ�!\n");
                } else {
                    printf("����ʧ��!\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 11:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                int i;
                ElemType e;
                printf("������λ��:");
                scanf("%d", &i);
                if (ListDelete(Lists.elem[index].L, i, e) == OK) {
                    printf("ɾ���ɹ�, ��ɾ��Ԫ��Ϊ%d!\n", e);
                } else {
                    printf("����ʧ��!\n");
                }
            } 
            printf("�����������...");
            getchar();getchar();
            break;
        case 12: 
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                printf("���Ա���Ԫ��Ϊ...\n");
                if(ListTrabverse(Lists.elem[index].L) == INFEASIBLE) {
                    printf("����ʧ��!\n");
                } else {
                    printf("�����ɹ�!\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 13:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                if (ReverseList(Lists.elem[index].L) == OK) {
                    printf("��ת�ɹ�!\n");
                } else {
                    printf("����ʧ�ܣ�\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 14: 
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                int k;
                ElemType e;
                printf("������ָ����k: ");
                scanf("%d", &k);
                if (RemoveNthFromEnd(Lists.elem[index].L, k, e) == OK) {
                    printf("ɾ���ɹ�����ɾ����Ԫ����%d��\n", e);
                } else {
                    printf("����ʧ��!\n");
                }
            }   
            printf("�����������...");
            getchar();getchar();
            break;
        case 15:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!\n");
            } else {
                SortList(Lists.elem[index].L);
                printf("����ɹ�!\n");
            }    
            printf("�����������...");
            getchar();getchar();
            break;
        case 16:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            if (LocateList(Lists, ListName) > 0) {
                printf("���Ա��Ѵ���!\n");
            } else {
                if (AddList(Lists, ListName) == OK) {
                    printf("��ӳɹ�\n");
                } else {
                    printf("����ʧ��\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 17:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName);
            if (index > 0) {
                printf("���ܱ��е�%d��!\n", index);
            } else {
                printf("����ʧ��\n");
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 18:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            if (RemoveList(Lists, ListName) == OK) {
                printf("�Ƴ��ɹ�\n");
            } else {
                printf("����ʧ��!\n");
            }
            printf("�����������...");
            getchar();getchar();
            break;
        case 19:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!");
            } else {
                printf("�������ļ�����");
                scanf("%s", FileName);
                if (SaveList(Lists.elem[index].L, FileName) == OK) {
                    printf("����ɹ�!");
                } else {
                    printf("����ʧ��!");
                }                
            }
            printf("�����������...");
            getchar();getchar();
            break;   
        case 20:
            printf("���������Ա�����:");
            scanf("%s", ListName);
            index = LocateList(Lists, ListName) - 1;
            if (index < 0) {
                printf("���Ա�����!!");
            } else {
                printf("�������ļ���:");
                scanf("%s", FileName);
                if (LoadList(Lists.elem[index].L, FileName) == OK) {
                    printf("��ȡ�ɹ�!");
                } else {
                    printf("����ʧ��!");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;  
        case 21:
            if (ShowAllLists(Lists) == INFEASIBLE) {
                printf("Ŀǰû�пɲ��������Ա�!\n");
            }
            printf("�����������...");
            getchar();getchar();
            break;             
        case 0:
            break;
        } // end of switch
    } // end of while
    printf("��ӭ�´�ʹ�ñ�ϵͳ!\n");
    getchar();getchar();
    return 0;
} // end of main()