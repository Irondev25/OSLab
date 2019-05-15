#include<bits/stdc++.h>
using namespace std;

struct mem
{
    int l,h,dif;
};

bool compare(struct mem m1 , struct mem m2)
{
    return(m2.dif > m1.dif);
}

bool compare1(struct mem m1 , struct mem m2)
{
    return(m2.dif < m1.dif);
}

void bestfit(struct mem *m1 , int n, int* p , int np )
{
    struct mem m[10];
    for(int i=0;i<n;i++)
    {
        m[i].dif=m1[i].dif;
        m[i].h=m1[i].h;
        m[i].l=m1[i].l;
    }
    int ans[10][10],flag;
    for(int i=0;i<np;i++)
    {
        sort(m,m+n,compare);
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(m[j].dif >= p[i] )
            {
                ans[i][0]=m[j].l;
                m[j].l = m[j].l + p[i];
                m[j].dif = m[j].h - m[j].l;
                ans[i][1]=m[j].l;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"best fit not possible\n";
            return;
        }


    }
    cout<<"\nbest fit \n";
    for(int i=0;i<np;i++)
    {
        cout<<ans[i][0]<<"  "<<ans[i][1]<<endl;
    }
    cout << endl;
}

void firstfit(struct mem *m1 , int n, int* p , int np)
{
    struct mem m[10];
    for(int i=0;i<n;i++)
    {
        m[i].dif=m1[i].dif;
        m[i].h=m1[i].h;
        m[i].l=m1[i].l;
    }
    int ans[10][10],flag;
    for(int i=0;i<np;i++)
    {
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(m[j].h-m[j].l >= p[i] )
            {
                ans[i][0]=m[j].l;
                m[j].l = m[j].l + p[i];
                ans[i][1]=m[j].l;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"first fit not possible\n";
            return;
        }
    }
    cout<<"\nfirst fit \n";
    for(int i=0;i<np;i++)
    {
        cout<<ans[i][0]<<"  "<<ans[i][1]<<endl;
    }
    cout << endl;
}

void worstfit(struct mem *m1, int n, int* p , int np)
{
    struct mem m[10];
    for(int i=0;i<n;i++)
    {
        m[i].dif=m1[i].dif;
        m[i].h=m1[i].h;
        m[i].l=m1[i].l;
    }
    int ans[10][10],flag;
    for(int i=0;i<np;i++)
    {
        sort(m,m+n,compare1);
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(m[j].h-m[j].l >= p[i] )
            {
                ans[i][0]=m[j].l;
                m[j].l = m[j].l + p[i];
                m[j].dif = m[j].h - m[j].l;
                ans[i][1]=m[j].l;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"worst fit not possible\n";
            return;
        }
    }
    cout<<"\nbest fit \n";
    for(int i=0;i<np;i++)
    {
        cout<<ans[i][0]<<"  "<<ans[i][1]<<endl;
    }
    cout<<endl;
}

int main()
{
    freopen("fitin.txt","r",stdin);
    struct mem m[10];
    int n,np,p[10];
    cin>>n>>np;
    for(int i=0;i<n;i++)
    {
        cin>>m[i].l>>m[i].h;
        m[i].dif=(m[i].h - m[i].l);
    }
    for(int i=0;i<np;i++)
        cin>>p[i];
    firstfit(m,n,p,np);
    bestfit(m,n,p,np);
    worstfit(m,n,p,np);
    return 0;
}
