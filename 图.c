#include <stdio.h>

#define Maxnum 20
#define Maxvalue 65535
#define nol -1
#define used 0

int path[Maxnum];
int tmpvertex[Maxnum];

typedef struct{
char vertex[Maxnum];
int Gtype;
int vertexnum;
int edgenum;
int edgeweight[Maxnum][Maxnum];
int istrav[Maxnum];
}graph;

void creategraph (graph *gm)
{
    int i,j,k;
    int weight;
    char estart,eend;

    printf("请输入图中各顶点的信息：\n");
    for(i=0;i<gm->vertexnum;i++)
    {
        getchar();
        printf("第%d个顶点: ",i+1);
        scanf("%c",&(gm->vertex[i]));
    }

    printf("输入构成个边的顶点和权值\n");
    for (k=0;k<gm->edgenum;k++)
    {
        getchar();
        printf("第%d条边：\n",k+1);
        scanf("%c %c %d",&estart,&eend,&weight);
        for(i=0;estart!=gm->vertex[i];i++);
        for(j=0;eend!=gm->vertex[j];j++);
        gm->edgeweight[i][j]=weight;
        if(gm->Gtype==0)
        {
            gm->edgeweight[j][i]=weight;
        }
    }

}

void cleargraph(graph *gm)
{
    int i,j;
    for(i=0;i<gm->vertexnum;i++)
    {
        for(j=0;j<gm->vertexnum;j++)
        {
            gm->edgeweight[i][j]=Maxvalue;
        }
    }
}

void outgraph(graph *gm)
{
    int i,j;
    for(j=0;j<gm->vertexnum;j++)
    {
        printf("\t%c",gm->vertex[j]);

    }
    printf ("\n");
    for(i=0;i<gm->vertexnum;i++)
    {
        printf("%c",gm->vertex[i]);
        for(j=0;j<gm->vertexnum;j++)
        {
            if(gm->edgeweight[i][j]==Maxvalue)
            {
                printf("\tZ");
            }
            else{
                printf("\t%d",gm->edgeweight[i][j]);
            }
        }
        printf("\n");
    }

}

void deeptraone(graph *gm,int n)
{
    int i;
    gm->istrav[n]=1;
    printf("->%c",gm->vertex[n]);
    for(i=0;i<gm->vertexnum;i++)
    {
        if(gm->edgeweight[n][i]!=Maxvalue&&!gm->istrav[n])
        {
            deeptraone(gm,i);
        }
    }
}

void deeptragraph(graph *gm)
{
    int i;
    for(i=0;i<gm->vertexnum;i++)
    {
        gm->istrav[i]=0;
    }
    printf("深度优先遍历节点：");
    for(i=0;i<gm->vertexnum;i++)
    {
        if(!gm->istrav[i])
        {
            deeptraone(gm,i);
        }
    }
    printf("\n");
}

void primgraph(graph gm)
{
    int i,j,k,sum,min;
    int weight[Maxnum];
    char vtempx[Maxnum];

    sum=0;
    for(i=1;i<gm.vertexnum;i++)
    {
        weight[i]=gm.edgeweight[0][i];
        if(weight[i]==Maxvalue)
        {
            vtempx[i]=nol;
        }
        else
        {
            vtempx[i]=gm.vertex[0];
        }
    }
    vtempx[0]=used;
    weight[0]=Maxvalue;
    for(i=1;i<gm.vertexnum;i++)
    {
        min=weight[0];
        k=i;
        for(j=1;j<gm.vertexnum;j++)
        {
            if(weight[j]<min&&vtempx[j]>0)
            {
                min=weight[j];
                k=j;

            }
        }
        sum+=min;
        printf("(%c,%c)",vtempx[k],gm.vertex[k]);
        vtempx[k]=used;
        weight[k]=Maxvalue;
        for(j=0;j<gm.vertexnum;j++)
        {
            if(gm.edgeweight[k][j]<weight[j]&&vtempx[j]!=0)
            {
                weight[j]=gm.edgeweight[k][j];
                vtempx[j]=gm.vertex[k];
            }
        }
    }
    printf("\n最小生成树的总值为：%d\n",sum);
}

void dist(graph gm,int vend)
{
    int weight[Maxnum];
    int i,j,k,min;
    vend--;
    for(i=0;i<gm.vertexnum;i++)
    {
        weight[i]=gm.edgeweight[vend][i];

    }
    for(i=0;i<gm.vertexnum;i++)
    {
        if(weight[i]<Maxvalue&&weight[i]>0)
        {
            path[i]=vend;
        }
    }
    for(i=0;i<gm.vertexnum;i++)
    {
        tmpvertex[i]=0;
    }
    tmpvertex[vend]=1;
    weight[vend]=0;
    for(i=0;i<gm.vertexnum;i++)
    {
        min=Maxvalue;
        k=vend;
        for(j=0;j<gm.vertexnum;j++)
        {
            if(tmpvertex[j]==0&&weight[j]<min)
            {
                min=weight[j];
                k=j;
            }

        }
        tmpvertex[k]=1;
        for(j=0;j<gm.vertexnum;j++)
        {
            if(tmpvertex[j]==0&&weight[k]+gm.edgeweight[k][j]<weight[j])
            {
                weight[j]=weight[k]+gm.edgeweight[k][j];
                path[j]=k;
            }
        }
    }
}
void main()
{
    graph gm;
    int vend,i,j,k;
    printf("输入生成图的类型：");
    scanf("%d",&gm.Gtype);
    printf("输入图的顶点数量：");
    scanf("%d",&gm.vertexnum);
    printf("请输入图的边数量: ");
    scanf("%d",&gm.edgenum);
    cleargraph(&gm);
    creategraph(&gm);
    printf("该图的邻接矩阵数据如下：\n");
    outgraph(&gm);
    deeptragraph(&gm);
    primgraph(gm);
     printf("请输入结束点：\n");
     scanf("%d",&vend);
     dist(gm,vend);
     vend--;
     printf("\n各顶点到达顶点%c的最短路径为（起始点-结束点）：\n",gm.vertex[vend]);
     for(i=0;i<gm.vertexnum;i++)
     {
         if(tmpvertex[i]==1)
         {
             k=i;
             while(k!=vend)
             {
                 printf("顶点%c->",gm.vertex[k]);
                 k=path[k];
             }
             printf("顶点%c\n",gm.vertex[k]);
         }
         else
         {
             printf("%c-%c：无路径",gm.vertex[i],gm.vertex[vend]);
         }
     }

}
