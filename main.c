#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    system("color 0a"); //������ɫ�趨
    Welcome(); ///��ӭ����
    title();            //����

    ListUser U;         //�û������Ա�
    ListUserInit(&U);   //�˺��������Ա�  ��ʼ��
    ListUserCreat(&U);

    printf("\n\t1.��½\t2.ע��\n\n�����룺"); //ѡ�����

    int c1;
    scanf("%d",&c1);

    if(c1==2)
    {

        ApplyUser(&U);
        WriteinfileUser(&U);
        printf("\n�˺�����ɹ���\n\t���س�������");
        c1=getchar();
        c1=getchar();
    }

  WriteinfileUser(&U);//�����˺ŵ�д��

   location1 : if(loginstate(Loginjudge(&U))==0)
        {
            printf("1.�������룬2���˳�ϵͳ\n");
            int n;
            scanf("%d",&n);
            if(n==1)
                goto location1;
           else
               exit(0);
        }
  WriteinfileUser(&U);//�����˺ŵ�д��

    List L;
    ListInit(&L);
    ListCreat(&L);

    while(1)
{
    location2 :system("cls");
    title();
    printf("================================\n");
    printf("��ѡ�������\n");
    printf("            1.��ѧ����\n");
    printf("            2.���۽��\n");
    printf("            3.�˳�ϵͳ\n\n");

    char ch;
    ch=getchar();
    switch(ch)
    {
        case '1' :              //1.��������  �����¼��д���ļ�
            addrecord(&L);
            break;
        case '2' :              //2.�������   ����
            ListDisplay(&L);
            break;

        case '3' :
            exit(0);
    }

    int s1;
    printf("1.�������� 2.�˳�ϵͳ\n");
    scanf("%d",&s1);
    char m; m=getchar();//�����س�����
    if(s1==1)
        goto location2;
   break;//����while
}

    writeinfile(&L);
        return 0;
}
