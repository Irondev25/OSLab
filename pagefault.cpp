#include<bits/stdc++.h>
using namespace std;
int cap=4;
int fifo(int *p , int n)
{
    queue<int> q;
    set<int> s;
    int pf=0;
    for(int i=0;i<n;i++)
    {
        if(s.size() < cap)
        {
            if(s.find(p[i]) == s.end())
            {
                pf++;
                q.push(p[i]);
                s.insert(p[i]);
            }
        }
        else
        {
            if(s.find(p[i]) == s.end())
            {
                pf++;
                s.erase(q.front());
                q.push(p[i]);
                s.insert(p[i]);
                q.pop();
            }
        }

    }
    return pf;
}

int lru_pf(int *p , int n)
{
    int pf=0;
    map<int , int> m;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.size()<cap)
        {
            if(s.find(p[i]) == s.end())
            {
                pf++;
                m[p[i]]=i;
                s.insert(p[i]);
            }

        }
        else
        {
            if(s.find(p[i]) == s.end())
            {
                pf++;
                int lru=9999,page_to_replace;
                set<int>::iterator it;
                for(it=s.begin();it != s.end();it++)
                {
                    if(m[*it]<lru)
                    {
                        lru=m[*it];
                        page_to_replace=(*it);
                    }
                }
                s.erase(page_to_replace);
                m.erase(page_to_replace);
                s.insert(p[i]);
                m[p[i]]=i;
            }
            m[p[i]]=i;
        }


    }
    return pf;
}

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout << "fifo : "<<fifo(pages,n)<<endl<<"lru : "<<lru_pf(pages,n);
    return 0;
}
