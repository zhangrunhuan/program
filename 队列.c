#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define QUEUELEN 15

typedef struct
{
    char name[10];
    int age;
}DATA;

typedef struct
{
    DATA data[QUEUELEN];
    int head;
    int tail;
}sqtype;

sqtype *sqlinit()
{
    sqtype *q;
    if(q=(sqtype*)malloc (sizeof(sqtype)))
    {
        q->head=0;
        q->tail=0;
        return q;
    }
    else
    {
        return NULL;
    }
}

int sqlempty(sqtype *q)
{
    int tem;
    tem=q->head=q->tail;
    return (tem);
}


int sqlfull(sqtype *q)
{
    int tem;
    tem=q->tail=QUEUELEN;
    return tem;
}

void sqlchear(sqtype *s)
{
    s->head=0;
    s->tail=0;
}

void sqlfree(sqtype *s)
{
    if(s!=NULL)
    {
        free(s);
    }
}

int sqlinsert(sqtype *s,DATA data)
{
    if(s->tail==QUEUELEN)
    {
        printf("��������������ʧ��");
        return(0);
    }
    else
    {
        s->data[s->tail++]=data;
        return (1);
    }
}

DATA *sqlout(sqtype *s)
{
    if(s->head==s->tail)
    {
        printf("�����Կգ�����ʧ��");
        exit (0);
    }
    else
    {
        return &(s->data[s->head++]);
    }
}

DATA *sqlpeek(sqtype *s)
{
    if(sqlempty(s))
    {
        printf("�ն���");
        return NULL;
    }
    else
    {
        return &(s->data[s->head]);
    }
}

int sqllen(sqtype *q)
{
    int temp;
    temp=q->tail-q->head;
    return (temp);
}

void main()
{
    sqtype *s;
    DATA data;
    DATA *date;
    s=sqlinit();
    printf("��Ӳ���\n");
    do
    {
    printf("������ѧ��������������\n");
    scanf("%s%d",data.name,&data.age);
    if(strcmp(data.name,"0")==0)
    {
        break;
    }
    else{
            sqlinsert(s,data);

    }
    }while(1);
    do
    {
        printf("���Ӳ����������������\n");
        getchar();
        date=sqlout(s);
        printf("ѧ��������������Ϊ%s %d",date->name,date->age);
    }while(1);
    sqlfree(s);
}
