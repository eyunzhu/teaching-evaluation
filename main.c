#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    system("color 0a"); //界面颜色设定
    Welcome(); ///欢迎界面
    title();            //标题

    ListUser U;         //用户名线性表
    ListUserInit(&U);   //账号密码线性表  初始化
    ListUserCreat(&U);

    printf("\n\t1.登陆\t2.注册\n\n请输入："); //选择操作

    int c1;
    scanf("%d",&c1);

    if(c1==2)
    {

        ApplyUser(&U);
        WriteinfileUser(&U);
        printf("\n账号申请成功！\n\t按回车键继续");
        c1=getchar();
        c1=getchar();
    }

  WriteinfileUser(&U);//密码账号的写入

   location1 : if(loginstate(Loginjudge(&U))==0)
        {
            printf("1.重新输入，2：退出系统\n");
            int n;
            scanf("%d",&n);
            if(n==1)
                goto location1;
           else
               exit(0);
        }
  WriteinfileUser(&U);//密码账号的写入

    List L;
    ListInit(&L);
    ListCreat(&L);

    while(1)
{
    location2 :system("cls");
    title();
    printf("================================\n");
    printf("请选择操作：\n");
    printf("            1.教学评价\n");
    printf("            2.评价结果\n");
    printf("            3.退出系统\n\n");

    char ch;
    ch=getchar();
    switch(ch)
    {
        case '1' :              //1.数据输入  加入记录、写入文件
            addrecord(&L);
            break;
        case '2' :              //2.数据输出   遍历
            ListDisplay(&L);
            break;

        case '3' :
            exit(0);
    }

    int s1;
    printf("1.继续操作 2.退出系统\n");
    scanf("%d",&s1);
    char m; m=getchar();//消除回车干扰
    if(s1==1)
        goto location2;
   break;//跳出while
}

    writeinfile(&L);
        return 0;
}
