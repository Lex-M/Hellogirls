#include <stdio.h>

void setData(int a[],int n)//�������ݣ���ʼ������
{
    printf("������%d������Ԫ��ֵ��\n",n);
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d",&a[i]);
    }
    return;
}

int kMin(int k,int n,int a[])
{
    int i,x=0,y=0;
    int l[20],r[20];
    if (n==1) return a[0];
    else
    {
        for (i=1;i<n;i++)
        {
            if (a[i]<=a[0])
            {
                l[x++]=a[i];
            }
            else
                r[y++]=a[i];
        }
        l[x++]=a[0];
        if (k==x)
            return l[x-1];
        else if (k<x)
            return kMin(k,x,l);
        else
            return kMin(k-x,y,r);
    }
}

main()
{
    int n,num,k;
    int a[100];
    printf("����������Ԫ�ظ���n��");
    scanf("%d",&n);
    setData(a ,n);//��ʼ������
    printf("�������kСԪ����k��ֵ��");
    scanf("%d",&k);
    num=kMin(k,n,a);
    printf("����ĵ�%dСԪ���ǣ�%d\n",k,num);
}
