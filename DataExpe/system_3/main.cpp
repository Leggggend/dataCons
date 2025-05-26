// ������ʽ�洢�ṹ�����Ա�ʵ��
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "def.h" // �������͵���ض���
#include "func.h" // ��ع��ܵ�ʵ��

int main(void) {
    BiTree T = NULL;
    char currentTName[30]; // ��ǰ��������    
    int curindex = 0;      // ��ǰ�������
    strcpy(currentTName, "����ӻ��л�����");

    BiForest F;    
    F = (BiForest)malloc(sizeof(Forest));
    F->length = 0;
    for (int i = 0; i < 10; i++) {
        F->elem[i].T = NULL;
    }

    KeyType e;
    char FileName[50];
    char TreeName[30];
    TElemType definition1[100];
    DEF definition2[100];

    int op = 1;
    while (op) {
        system("cls");	// ����
        printf("\n\n");
        printf("      Menu For Binary Tree On Binary Linked Structure \n");
        printf("-------------------------------------------------------------\n");
        printf("          1. CreateBiTree         2. DestroyBiTree\n");
        printf("          3. ClearBiTree          4. BiTreeEmpty\n");
        printf("          5. ListDepth            6. LocateNode\n");
        printf("          7. AssignNode           8. GetSibling\n");
        printf("          9. InsertNode          10. DeleteNode\n");
        printf("         11. PreOrderTraverse    12. InOrederTrabverse\n");
        printf("         13. PostOrderTraverse   14. LevelOrderTraverse\n");
        printf("         15. MaxPathSum          16. LowestCommonAncestor\n");
        printf("         17. InvertBiTree        18. SaveBiTree\n");
        printf("         19. LoadBiTree          20. AddBiTree\n");
        printf("         21. LocateBiTree        22. RemoveBiTree\n");
        printf("         23. TraverseBiForest    24. TurnToBiTree\n");
        printf("          0. Exit\n");
        printf("------------------------------------------------------------\n");
        printf("    ��ǰ������������\n");
        printf("       ��ţ�%d\n", curindex);
        printf("       ������%s\n", currentTName);
        printf("    ��ѡ�����Ĳ��� [0 ~ 24]: ");
        scanf("%d", &op);        
        printf("------------------------------------------------------------\n");

        switch (op) {
        case 1: {
            if (T) printf("��ǰ���Ѱ������ݣ�\n");
            else {
                int method;
                printf("��ѡ�����뷽ʽ��1-���ս��(�Ƽ�)��2-����������ţ���");
                scanf("%d", &method);
                if (method == 1) {
                    int i = 0;
                    printf("�����������У�");
                    do {
                        scanf("%d %s", &definition1[i].key, definition1[i].others);
                    } while (definition1[i++].key != -1);
                    if (CreateBiTree1(T, definition1) != OK) printf("\n����ʧ�ܣ�\n");
                    else {
                        F->elem[curindex-1].T = T; // ɭ�ּ�¼�� ���ⶪʧ
                        printf("\n�����ɹ���\n"); 
                    }                     
                } else if (method == 2) {
                    int i = 0;
                    printf("�����������У�");
                    do {
                        scanf("%d %d %s", &definition2[i].pos, &definition2[i].data.key, definition2[i].data.others);
                    } while (definition2[i++].pos);
                    if (CreateBiTree2(T, definition2, i) != OK) printf("\n����ʧ�ܣ�\n");
                    else {
                        printf("\n�����ɹ���\n"); 
                        F->elem[curindex-1].T = T; // ɭ�ּ�¼�� ���ⶪʧ
                    }
                } else {
                    printf("������1����2��\n");
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 2: {
            if (!T) printf("����Ϊ�գ�\n");
            else if (DestroyBiTree(T) != OK) 
                printf("\n�ݻ�ʧ�ܣ�\n");
            else printf("\n�ݻٳɹ���\n");                
            printf("�����������...");
            getchar();getchar();
            break;            
        }

        case 3: {
            if (!T) printf("����Ϊ�գ�\n");
            else if (ClearBiTree(T) != OK) 
                printf("\n���ʧ�ܣ�\n");
            else printf("\n��ճɹ���\n");                
            printf("�����������...");
            getchar();getchar();
            break;            
        }

        case 4: {
            if (BiTreeEmpty(T) == TRUE) printf("��Ϊ�գ�\n");
            else printf("���ǿգ�\n");
            printf("�����������...");
            getchar();getchar();
            break;            
        }

        case 5: {
            if (!T) printf("��Ϊ�գ�\n");  
            else printf("�������Ϊ%d��\n", BiTreeDepth(T));                
            printf("�����������...");
            getchar();getchar();
            break;            
        }

        case 6: {
            if (!T) printf("��Ϊ�գ�\n");
            else {
                printf("\n������Ҫ���ҵĽ��ؼ��֣�");
                scanf("%d", &e);
                BiTree p = LocateNode(T, e);
                if (!p) printf("\nĿ���㲻���ڣ�\n");
                else printf("\nĿ����Ϊ(%d,%s)��\n", p->data.key, p->data.others);                
            }
            printf("�����������...");
            getchar();getchar();
            break;            
        }

        case 7: {
            if (!T) printf("��Ϊ�գ�\n");
            else {
                TElemType value;
                printf("\n������Ҫ��ֵ�Ľ��ؼ��֣�");
                scanf("%d", &e);
                printf("\n������Ҫ����ֵ��");
                scanf("%d %s", &value.key, value.others);
                if (AssignNode(T, e, value) != OK) 
                    printf("\n��㲻���ڻ�ؼ����ظ���\n");
                else printf("\n��ֵ�ɹ���\n");                
            }
            printf("�����������...");
            getchar();getchar();
            break;
        }
 
        case 8: {
            if (!T) printf("��Ϊ�գ�\n");
            else {
                printf("\n������Ҫ��ѯ�Ĺؼ��֣�");
                scanf("%d", &e);
                BiTree sib = GetSibling(T, e);
                if (!sib) printf("\n��ѯʧ�ܣ�\n");
                else 
                    printf("\n�ֵܽ��Ϊ(%d, %s)��\n", sib->data.key, sib->data.others);                
            }
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 9:{            
            if (!T) printf("��Ϊ�գ�\n");
            else {
                int LR;
                TElemType c;
                printf("\n���������ķ�ʽ��");
                scanf("%d", &LR); 
                if (LR != -1) {
                    printf("\n���������λ�õĹؼ��֣�");
                    scanf("%d", &e);
                }       
                printf("\n���������Ľ�㣺");
                scanf("%d %s", &c.key, c.others);
                if (InsertNode(T, e, LR, c) != OK) printf("\n����ʧ�ܣ�\n");
                else printf("\n����ɹ���\n");                
            }
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 10:{
            if (!T) printf("��Ϊ�գ�\n");
            else {
                printf("������Ҫɾ���ڵ�Ĺؼ��֣�");
                scanf("%d", &e);
                if (DeleteNode(T, e) != OK) 
                    printf("\nĿ���㲻���ڣ�\n");
                else printf("\nɾ���ɹ���\n");                
            }
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 11:{
            if (!T) printf("��Ϊ�գ�\n");
            else if (PreOrderTraverse(T, Visit) != OK) 
                printf("\n����ʧ�ܣ�\n");               
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 12: {
            if (!T) printf("��Ϊ�գ�\n");
            else if (InOrderTraverse(T, Visit) != OK) 
                printf("\n����ʧ�ܣ�\n");
            printf("\n�����������...");
            getchar();getchar();
            break;
        }
 
        case 13:{
            if (!T) printf("��Ϊ�գ�\n");
            else if (PostOrderTraverse(T, Visit) != OK) printf("\n����ʧ�ܣ�\n");
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 14: {
            if (!T) printf("��Ϊ�գ�\n");
            else if (LevelOrderTraverse(T, Visit) != OK)
                printf("\n����ʧ�ܣ�\n");
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 15:{
            if (!T) printf("��Ϊ�գ�\n");
            else printf("\n���·����Ϊ��%d��\n", MaxPathSum(T));
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 16:{
            if (!T) printf("��Ϊ�գ�\n");
            else {
                KeyType e1, e2;
                printf("\n����������Ҫ��ѯ���Ĺؼ��֣�");
                scanf("%d %d", &e1, &e2);
                BiTree anc = LowestCommonAncestor(T, e1, e2);
                if (!anc) printf("\n�����ڹ������ȣ�\n");
                else 
                    printf("\n�����������Ϊ��(%d, %s)��\n", anc->data.key, anc->data.others);                
            }
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 17:{
            if (!T) printf("��Ϊ�գ�\n");
            else if (InvertBiTree(T) != OK) printf("\n��תʧ�ܣ�\n");
            else printf("\n��ת�ɹ���\n");
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 18:{
            if (!T) printf("��Ϊ�գ�\n");
            else {
                printf("\n�������ļ�����");
                scanf("%s", FileName);
                if (SaveBiTree(T, FileName) != OK) printf("\n����ʧ�ܣ�\n");
                else {
                    F->elem[curindex-1].T = T; // ɭ�ּ�¼�� ���ⶪʧ
                    printf("\n����ɹ���\n");                
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 19:{
            if (T) printf("���ǿգ�\n");
            else {
                printf("\n�������ļ�����");
                scanf("%s", FileName);
                if (LoadBiTree(T, FileName) != OK) printf("\n��ȡʧ�ܣ�\n");
                else {
                    F->elem[curindex-1].T = T; // ɭ�ּ�¼�� ���ⶪʧ
                    printf("\n��ȡ�ɹ���\n");                
                    
                }
            }
            printf("�����������...");
            getchar();getchar();
            break;  
        }
 
        case 20:{
            if (F->length == 10) printf("ɭ��������\n");
            else {
                printf("\n������Ҫ��ӵ�������");
                scanf("%s", TreeName);
                printf("������\n");
                if (AddBiTree(F, TreeName) != OK) printf("\n�����ظ���\n");
                else printf("\n��ӳɹ���\n");                
            }
            printf("�����������...");
            getchar();getchar();
            break;  
        }

        case 21:{
            if (!F->length) printf("ɭ��Ϊ�գ�\n");
            else {
                printf("\n������������");
                scanf("%s", TreeName);
                int index;
                index = LocateBiTree(F, TreeName);
                if (!index) printf("\n������ɭ���У�\n");
                else printf("\n��ɭ���е�%d������\n", index);                
            }
            printf("�����������...");
            getchar();getchar();
            break;   
        }

        case 22:{
            if (!F->length) printf("ɭ��Ϊ�գ�\n");
            else {
                printf("\n������������");
                scanf("%s", TreeName);
                if (RemoveBiTree(F, TreeName) != OK) printf("\n������ɭ���У�\n");
                else printf("\n�Ƴ��ɹ���\n"); 
                if (!strcmp(TreeName, currentTName)) { // ����Ƴ���ǰ��
                    curindex = 0;
                    T = NULL;
                    strcpy(currentTName, "����ӻ��л�����");
                }          
            }
            printf("�����������...");
            getchar();getchar();
            break;
        }

        case 23:{
            if (!F->length) printf("ɭ��Ϊ�գ�\n");
            else if (TraverseBiForest(F) != OK) printf("\n����ʧ�ܣ�\n");               
            printf("\n�����������...");
            getchar();getchar();
            break;
        }

        case 24:{
            if (!F->length) printf("ɭ��Ϊ�գ�\n");
            else {
                int order;
                printf("\n������Ҫ����������ţ�");
                scanf("%d", &order);
                if (TurnToBiTree(F, T, curindex, currentTName, order) != OK) printf("\n��ŷǷ���\n");
                else 
                    printf("\n���л�����%s��\n", currentTName);                
            }
            printf("�����������...");
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