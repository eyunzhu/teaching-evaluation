#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

void Welcome() ///��ӭ����
{

    printf("\n\n\n\n\t\t*************************************************");
    printf("\n\n\n\n\t\t\t\t��������һũ�Ѵ�ѧ\n");
    printf("\n\n\n\n\t\t\t    ��ӭ�����ѧ����ϵͳ  \n");
    printf("\n\n\n\n\t\t******************�����������********************\n");
       char ch;
       ch=getch();
}

void title()//��ͷ
{
    system("cls");//����
    puts("\n***********��������һũ�Ѵ�ѧ************************");
    puts("**************��ѧ����ϵͳ***************************\n");

}


typedef struct      ///�˺�����ṹ��
{
    char user[20];
    char password[20];
    char email[30];
}UserPassword;

typedef struct     ///�˺��������Ա���
{
    UserPassword str[100];
    int len;  //len��ʾ���Ա��ȣ������Ա����ж���Ԫ�أ���һ��Ԫ��Ϊstr[0];
}ListUser;



void ListUserInit(ListUser *U) ///�˺��������Ա�  ��ʼ��
{
    U->len=0;
}

void ListUserInsert(ListUser *U,int loc,UserPassword e)  ///�˺��������Ա�  ����
{
    if(U->len>=100)
    {
        printf("�������˺��Ѵ����ƣ�����"); //�˺�����ṹ������
        return;
    }

    if(loc<0||loc>U->len+1)
    {
        printf("���ִ���");//�����˺�����ṹ���λ�ô���
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

void ListUserCreat(ListUser *U)  ///  ���� ���ļ��ж������ݵ��˺��������Ա�
{
    FILE *fp;
    fp=fopen("UserPassword.txt","r+");
    if(fp==NULL)
    {
        puts("Can not open the UserPassword.txt \n");
        exit(0);
    }
    int i=1;//�ӵ�һ����ʼ����
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

void ApplyUser(ListUser *U)  ///�ʺ�����
{
    system("cls");
    title();
    printf("\t***�˺�����***\n\n�������ʺţ�");
    scanf("%s",U->str[U->len].user);
    printf("���������룺");
    scanf("%s",U->str[U->len].password);
    printf("���������䣺");
    scanf("%s",U->str[U->len].email);
    U->len++;

}

int WriteinfileUser(ListUser *U)  ///�˺�д���ļ�
{
    FILE *fp;
    fp=fopen("UserPassword.txt","w+");
    if(fp==NULL)
    {
        puts("Can not open the UserPassword.txt \n");
        exit(0);
    }

    void write(FILE *fp,UserPassword *e)  ///�˺�д�뺯��
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
    return 1;   //�˺�д��ɹ�
}

int Loginjudge(ListUser *U)  ///��½���ж�
{
    char user[20];
    char password[20];
    system("cls");
    title();
    printf("�������½�˺ţ�\n");
    printf("               ");
    scanf("%s",user);
    printf("�������½���룺\n");
    printf("               ");
    scanf("%s",password);
    char m; m=getchar();//�����س�����

   int i,j;
   for(i=0;i<U->len;i++)
   {
       if(strcmp(user,U->str[i].user)==0)
       {
           if(strcmp(password,U->str[i].password)==0)
                return 0;  //0��½�ɹ�
            else return
                1;//�������
       }
   }
   return 2;//ϵͳ�޴��û�


}

int loginstate(int a)   ///��½״̬
{
    system("cls");
    title();
   if(a==0)
   {
       printf("��½�ɹ���\n");
       return 1;

   }
    else if(a==2)
    {
         printf("ϵͳ�޴��û���\n");
         return 0;
    }


    else if(a==1)
    {
        printf("�������\n");
        return 0;
    }

}

typedef struct   ///��ѧ������Ϣ�ṹ��
{
    char School[15];    //������У
    char Time[20];  //����ʱ��
    char Name[20];    //����������
    int scor[6];    //����
}eva_list;

typedef struct   ///��ʦ��Ϣ���Ա���
{
    eva_list stu[100];
    int len;
}List;

void ListInit(List *L)  ///���Ա��ʼ����
{
    L->len=0;
}

void ListInsert(List *L,int loc,eva_list e) ///��Ԫ�ز������Ա�
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

void ListCreat(List *L)  ///�����������ļ��ж������ݵ����Ա�
{
    FILE *fp;
    fp=fopen("eva_list.txt","r+");    ///�򿪷�ʽΪr��r+!!!����Ϊw+
    if(fp==NULL)
    {
        puts("Can not open the file.\n");
        exit(0);
    }

    char c;
    int i,j;
    eva_list e;
    i=1;//��һ�εĲ���λ��
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

        c=fgetc(fp);///��ֹ�ļ�����ǰ��\n
        if(c!=EOF)
            fseek(fp,-1,1);

    }while(!feof(fp));
    fclose(fp);
}

void ListDisplay(List *L)///����
{
   system("cls");
   puts("***********************************************************���̽��**********************************************************\n");
   puts("&����󻯴���&\n\n");
   puts("�ȼ�'1','2','3','4','5'  ����1:��,2:����,3:��,4:һ��,5:��\n");
   puts("���\t������У\t\t����ʱ��\t\t����������\t\t��У����\t��ѧ����\tʦ�ʶ���\t�γ���ϵ\tѧ��Ⱥ��\t�������� \n");

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

void writeinfile(List *L)  ///�����Ա�д���ļ���
{
    FILE *fp;
    fp=fopen("eva_list.txt","w+");
    if(fp==NULL)
    {
        puts("Can not open the file.\n");
        exit(0);
    }

    void write(FILE *fp,eva_list *rpt) //д�뺯��
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
    for(i=1;i<L->len+1;i++)//�ӵ�һ����ʼд��
    {
        write(fp,&L->stu[i]);
    }
    fclose(fp);
}

void addrecord(List *L)  ///��������
{
    system("cls");
    title();
	int i,n;
	printf("�������ݸ���Ϊ��");
	scanf("%d",&n);
	/*��̬�ṹ����*/
	eva_list *a;
	a=(eva_list *)malloc(sizeof(eva_list)*n);
	if(a==0)
    {
        puts("��̬�ṹ���鶨���������");
        exit(0);
    }

    for(i=0;i<n;i++)
	{
	    printf("�������%d������\n",i+1);
	    printf("������У��");
            scanf("%s",a[i].School);
	    printf("����ʱ�䣺");
            scanf("%s",a[i].Time);
	    printf("������������");
            scanf("%s",a[i].Name);

	    printf("\n��У������");
	    puts("\n             ������ȼ�'1','2','3','4','5'  ����1:��,2:����,3:��,4:һ��,5:��");
            scanf("%d",&a[i].scor[0]);
        printf("\n��ѧ���ڣ�");
        puts("\n             ������ȼ�'1','2','3','4','5'  ����1:��,2:����,3:��,4:һ��,5:��");
            scanf("%d",&a[i].scor[1]);
        printf("\nʦ�ʶ��飺");
        puts("\n             ������ȼ�'1','2','3','4','5'  ����1:��,2:����,3:��,4:һ��,5:��");
            scanf("%d",&a[i].scor[2]);
        printf("\n�γ���ϵ��");
        puts("\n             ������ȼ�'1','2','3','4','5'  ����1:��,2:����,3:��,4:һ��,5:��");
            scanf("%d",&a[i].scor[3]);
        printf("\nѧ��Ⱥ�壺");
        puts("\n             ������ȼ�'1','2','3','4','5'  ����1:��,2:����,3:��,4:һ��,5:��");
            scanf("%d",&a[i].scor[4]);
        printf("\n�������ۣ�");
        puts("\n             ������ȼ�'1','2','3','4','5'  ����1:��,2:����,3:��,4:һ��,5:��");
            scanf("%d",&a[i].scor[5]);
        printf("\n");

        ListInsert(L,1+L->len,a[i]);///��ʱLΪ�β�ָ�����ͣ�����
	}
}

#endif // HEAD_H_INCLUDED
