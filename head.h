#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

void Welcome() ///欢迎界面
{

    printf("\n\n\n\n\t\t*************************************************");
    printf("\n\n\n\n\t\t\t\t黑龙江八一农垦大学\n");
    printf("\n\n\n\n\t\t\t    欢迎进入教学评价系统  \n");
    printf("\n\n\n\n\t\t******************按任意键继续********************\n");
       char ch;
       ch=getch();
}

void title()//标头
{
    system("cls");//清屏
    puts("\n***********黑龙江八一农垦大学************************");
    puts("**************教学评价系统***************************\n");

}


typedef struct      ///账号密码结构体
{
    char user[20];
    char password[20];
    char email[30];
}UserPassword;

typedef struct     ///账号密码线性表构建
{
    UserPassword str[100];
    int len;  //len表示线性表长度，即线性表中有多少元素！第一个元素为str[0];
}ListUser;



void ListUserInit(ListUser *U) ///账号密码线性表  初始化
{
    U->len=0;
}

void ListUserInsert(ListUser *U,int loc,UserPassword e)  ///账号密码线性表  插入
{
    if(U->len>=100)
    {
        printf("可申请账号已达限制！！！"); //账号密码结构体已满
        return;
    }

    if(loc<0||loc>U->len+1)
    {
        printf("出现错误！");//插入账号密码结构体的位置错误
        return;
    }

    int i;
    for(i=U->len;i>loc;i--)
    {
        U->str[i]=U->str[i-1];
    }
    U->str[loc]=e;
    U->len++;
}

void ListUserCreat(ListUser *U)  ///  创建 从文件中读入数据到账号密码线性表
{
    FILE *fp;
    fp=fopen("UserPassword.txt","r+");
    if(fp==NULL)
    {
        puts("Can not open the UserPassword.txt \n");
        exit(0);
    }
    int i=1;//从第一个开始读入
    char c;
    UserPassword e;
    do
    {
        fscanf(fp,"%s",e.user);
        fseek(fp,1,1);
        fscanf(fp,"%s",e.password);
        fseek(fp,1,1);
        fscanf(fp,"%s",e.email);
        fseek(fp,1,1);


        ListUserInsert(U,i,e);
        i++;
        c=fgetc(fp);
        if(c!=EOF)
            fseek(fp,-1,1);
    }while(!feof(fp));
    fclose(fp);
}

void ApplyUser(ListUser *U)  ///帐号申请
{
    system("cls");
    title();
    printf("\t***账号申请***\n\n请输入帐号：");
    scanf("%s",U->str[U->len].user);
    printf("请输入密码：");
    scanf("%s",U->str[U->len].password);
    printf("请输入邮箱：");
    scanf("%s",U->str[U->len].email);
    U->len++;

}

int WriteinfileUser(ListUser *U)  ///账号写入文件
{
    FILE *fp;
    fp=fopen("UserPassword.txt","w+");
    if(fp==NULL)
    {
        puts("Can not open the UserPassword.txt \n");
        exit(0);
    }

    void write(FILE *fp,UserPassword *e)  ///账号写入函数
    {
        fprintf(fp,"%s\t",e->user);
        fprintf(fp,"%s\t",e->password);
        fprintf(fp,"%s\t",e->email);
        fprintf(fp,"\n");
    }

    int i;
    for(i=1;i<U->len;i++)
    {
        write(fp,&U->str[i]);
    }
    fclose(fp);
    return 1;   //账号写入成功
}

int Loginjudge(ListUser *U)  ///登陆及判断
{
    char user[20];
    char password[20];
    system("cls");
    title();
    printf("请输入登陆账号：\n");
    printf("               ");
    scanf("%s",user);
    printf("请输入登陆密码：\n");
    printf("               ");
    scanf("%s",password);
    char m; m=getchar();//消除回车干扰

   int i,j;
   for(i=0;i<U->len;i++)
   {
       if(strcmp(user,U->str[i].user)==0)
       {
           if(strcmp(password,U->str[i].password)==0)
                return 0;  //0登陆成功
            else return
                1;//密码错误
       }
   }
   return 2;//系统无此用户


}

int loginstate(int a)   ///登陆状态
{
    system("cls");
    title();
   if(a==0)
   {
       printf("登陆成功！\n");
       return 1;

   }
    else if(a==2)
    {
         printf("系统无此用户！\n");
         return 0;
    }


    else if(a==1)
    {
        printf("密码错误！\n");
        return 0;
    }

}

typedef struct   ///教学评价信息结构体
{
    char School[15];    //所评高校
    char Time[20];  //评价时间
    char Name[20];    //评价人姓名
    int scor[6];    //评价
}eva_list;

typedef struct   ///教师信息线性表构建
{
    eva_list stu[100];
    int len;
}List;

void ListInit(List *L)  ///线性表初始长度
{
    L->len=0;
}

void ListInsert(List *L,int loc,eva_list e) ///将元素插入线性表
{
    if(L->len>=99)
    {
        puts("List has been full.\n");
        return;
    }
    if(loc<0 || loc>L->len+1)
    {
        puts("error location.\n");
        return;
    }
    int i;
    for(i=L->len+1;i>loc;i--)
    {
        L->stu[i]=L->stu[i-1];
    }
    L->stu[loc]=e;
    L->len++;
}

void ListCreat(List *L)  ///（创建）从文件中读入数据到线性表
{
    FILE *fp;
    fp=fopen("eva_list.txt","r+");    ///打开方式为r或r+!!!不可为w+
    if(fp==NULL)
    {
        puts("Can not open the file.\n");
        exit(0);
    }

    char c;
    int i,j;
    eva_list e;
    i=1;//第一次的插入位置
    do
    {
        fscanf(fp,"%s",&e.School);
        fscanf(fp,"%s",&e.Time);
        fscanf(fp,"%s",&e.Name);
        for(j=0;j<6;j++)
        {
            fscanf(fp,"%d",&e.scor[j]);
        }

        ListInsert(L,i,e);
        i++;
        c=fgetc(fp);

        c=fgetc(fp);///防止文件结束前有\n
        if(c!=EOF)
            fseek(fp,-1,1);

    }while(!feof(fp));
    fclose(fp);
}

void ListDisplay(List *L)///遍历
{
   system("cls");
   puts("***********************************************************评教结果**********************************************************\n");
   puts("&请最大化窗口&\n\n");
   puts("等级'1','2','3','4','5'  其中1:优,2:较优,3:好,4:一般,5:差\n");
   puts("序号\t所评高校\t\t评价时间\t\t评价人姓名\t\t高校环境\t教学环节\t师资队伍\t课程体系\t学生群体\t总体评价 \n");

    int i,j;
    for(i=1;i<L->len+1;i++)
    {
        printf("%d\t%s\t\t%s\t\t%s\t  ",i,L->stu[i].School,L->stu[i].Time,L->stu[i].Name);
        for(j=0;j<6;j++)
        {
            printf("              %d",L->stu[i].scor[j]);
        }
       printf("\n");
    }
    printf("\n\n");
}

void writeinfile(List *L)  ///把线性表写入文件中
{
    FILE *fp;
    fp=fopen("eva_list.txt","w+");
    if(fp==NULL)
    {
        puts("Can not open the file.\n");
        exit(0);
    }

    void write(FILE *fp,eva_list *rpt) //写入函数
    {
        fprintf(fp,"%s\t",rpt->School);
        fprintf(fp,"%s\t",rpt->Time);
        fprintf(fp,"%s\t",rpt->Name);
        fprintf(fp,"%d\t",rpt->scor[0]);

        fprintf(fp,"%d\t",rpt->scor[1]);
        fprintf(fp,"%d\t",rpt->scor[2]);
        fprintf(fp,"%d\t",rpt->scor[3]);
        fprintf(fp,"%d\t",rpt->scor[4]);
        fprintf(fp,"%d",rpt->scor[5]);
        fprintf(fp,"\n");
    }

    int i;
    for(i=1;i<L->len+1;i++)//从第一个开始写入
    {
        write(fp,&L->stu[i]);
    }
    fclose(fp);
}

void addrecord(List *L)  ///增添数据
{
    system("cls");
    title();
	int i,n;
	printf("评教数据个数为：");
	scanf("%d",&n);
	/*动态结构数组*/
	eva_list *a;
	a=(eva_list *)malloc(sizeof(eva_list)*n);
	if(a==0)
    {
        puts("动态结构数组定义出错！！！");
        exit(0);
    }

    for(i=0;i<n;i++)
	{
	    printf("请输入第%d个数据\n",i+1);
	    printf("所评高校：");
            scanf("%s",a[i].School);
	    printf("评价时间：");
            scanf("%s",a[i].Time);
	    printf("评价人姓名：");
            scanf("%s",a[i].Name);

	    printf("\n高校环境：");
	    puts("\n             请输入等级'1','2','3','4','5'  其中1:优,2:较优,3:好,4:一般,5:差");
            scanf("%d",&a[i].scor[0]);
        printf("\n教学环节：");
        puts("\n             请输入等级'1','2','3','4','5'  其中1:优,2:较优,3:好,4:一般,5:差");
            scanf("%d",&a[i].scor[1]);
        printf("\n师资队伍：");
        puts("\n             请输入等级'1','2','3','4','5'  其中1:优,2:较优,3:好,4:一般,5:差");
            scanf("%d",&a[i].scor[2]);
        printf("\n课程体系：");
        puts("\n             请输入等级'1','2','3','4','5'  其中1:优,2:较优,3:好,4:一般,5:差");
            scanf("%d",&a[i].scor[3]);
        printf("\n学生群体：");
        puts("\n             请输入等级'1','2','3','4','5'  其中1:优,2:较优,3:好,4:一般,5:差");
            scanf("%d",&a[i].scor[4]);
        printf("\n总体评价：");
        puts("\n             请输入等级'1','2','3','4','5'  其中1:优,2:较优,3:好,4:一般,5:差");
            scanf("%d",&a[i].scor[5]);
        printf("\n");

        ListInsert(L,1+L->len,a[i]);///此时L为形参指针类型！！！
	}
}

#endif // HEAD_H_INCLUDED
