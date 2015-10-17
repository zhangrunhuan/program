#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 50

typedef struct
{
     char name[20];
     int age;
}DATA;

typedef struct stack
{
    DATA data[MAXLEN +1];
    int top;
}stacktype;

stacktype *stinit()
{
    stacktype *p;
    if(p=(stacktype*)malloc(sizeof(stacktype)))
    {
        p->top=0;
        return p;
    }
    return NULL;
}

int stackempty(stacktype *s)
{
    int t;
    t=(s->top==0);
    return t;
}

int stackfull(stacktype *s)
{
    int t;
    t=(s->top==MAXLEN);
    return t;
}

void stackclear(stacktype *s)
{
    s->top=0;
}

void stcakfree(stacktype *s)
{
    if(s)
    {
        free(s);
    }
}

int pushstack(stacktype *s,DATA data)
{
    if((s->top+1)>MAXLEN)
    {
        printf("ջ���\n");
        return 0;
    }
    s->data[++s->top]=data;
    return 1;
}

DATA popstack(stacktype *s)
{
    if(s->top==0)
    {
        printf("ջΪ��!\n");
        exit (0);
    }
    return (s->data[s->top--]);
}

DATA peekstack(stacktype *s)
{
    if(s->top==0)
    {
        printf("ջΪ��\n");
        exit(0);
    }
    return (s->data[s->top]);
}

void main()
{
    stacktype *s;
    DATA data,date;
    s=stinit();
    printf("��ջ����\n");
    do
    {
    printf("������ѧ�������������䣺\n");
    scanf("%s%d",data.name,&data.age);
    if(strcmp(data.name,"0")==0)
    {
        break;
    }
    else
    {
        pushstack(s,data);
    }
    }while(1);

    do
    {
        printf("\n��ջ�������밴��������в���\n");
        getchar();
        date=popstack(s);
        printf("��ջ��������(%s %d)\n",date.name,date.age);
            }while(1);

            stackfree(s);

}
