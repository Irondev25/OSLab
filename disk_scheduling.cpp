#include<bits/stdc++.h>

using namespace std;

int dsize;

void sstf(int* p, int n, int initial){
    int i,j,k,d;
    sort(p,p+n);
    k=0;
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        d=abs(initial-p[i]);
        if(d<min){
            min=d;
            k=i;
        }
    }
    i=k-1;
    j=k+1;
    int s=min;
    int t=0,r;
    cout<<initial<<" -> "<<p[k]<<" -> ";
    for(t=0;t<n-1;t++){
        r=k;
        if(i<0 || (j<n && ((p[j]-p[k])<(p[k]-p[i])))){
            k=j;
            j++;
        }
        else{
            k=i;
            i--;
        }
        cout<<p[k]<<" ->";
        int d = abs(p[r] - p[k]);
        s+=d;
    }
    cout << "\nTotal seek time: " << s << endl;
}

int scan(int *p, int n, int initial, int prev){
    sort(p,p+n);
    int seek=0;
    if((initial-prev)>0){
        seek+=(dsize-1)-initial;
        if(p[0]<initial)
            seek+=(dsize-1-p[0]);
    }
    else{
        seek+=initial;
        if(p[n-1]>initial)
            seek+=p[n-1];
    }
    cout<<"\n"<<seek<<endl;
}

int main(){
    freopen("din.txt","r",stdin);
    int n, initial,prev;
    cin>>n>>initial>>prev>>dsize;
    int queue[100];
    for(int i=0;i<n;i++){
        cin>>queue[i];
    }
    sstf(queue,n,initial);
    scan(queue,n,initial,prev);
    return 0;
}