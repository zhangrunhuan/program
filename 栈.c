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
        printf("栈溢出\n");
        return 0;
    }
    s->data[++s->top]=data;
    return 1;
}

DATA popstack(stacktype *s)
{
    if(s->top==0)
    {
        printf("栈为空!\n");
        exit (0);
    }
    return (s->data[s->top--]);
}

DATA peekstack(stacktype *s)
{
    if(s->top==0)
    {
        printf("栈为空\n");
        exit(0);
    }
    return (s->data[s->top]);
}

void main()
{
    stacktype *s;
    DATA data,date;
    s=stinit();
    printf("入栈操作\n");
    do
    {
    printf("请输入学生的姓名、年龄：\n");
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
        printf("\n出栈操作，请按任意键进行操作\n");
        getchar();
        date=popstack(s);
        printf("出栈的数据是(%s %d)\n",date.name,date.age);
            }while(1);

            stackfree(s);

}
