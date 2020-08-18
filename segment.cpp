#include<bits/stdc++.h>
using namespace std;
class segmentTree{
    int leftmost,rightmost;
    int sum=0;
    segmentTree *leftchild;
    segmentTree *rightchild;
    public:
    segmentTree(int l,int r,int a[])
    {
        leftmost = l;
        rightmost = r;
        if(leftmost==rightmost)
        sum+=a[leftmost];
        else{
        int mid = (leftmost+rightmost)/2; 
        leftchild = new segmentTree(leftmost,mid,a);
        rightchild = new segmentTree(mid+1,rightmost,a);
        recal();
        }
    }
    void recal(){
        if(leftmost==rightmost)
        return;
        else
        sum=(leftchild->sum)+(rightchild->sum);
    }
    
    void pointUpdate(int index,int newVal){
        if(leftmost==rightmost)
        sum = newVal;
        else{
            if(index<=leftchild->rightmost)
            leftchild->pointUpdate(index,newVal);
            else
            rightchild->pointUpdate(index,newVal);
            recal();
        }
    }

    int rangesum(int l,int r){
        if(r<leftmost || l>rightmost)
        return 0;
        else if(l<=leftmost && r>=rightmost)
        return sum;
        else
        return leftchild->rangesum(l,r) + rightchild->rangesum(l,r);
    }

};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
    cin>>arr[i];
    segmentTree st(0,n-1,arr);
    cout<<"Queries :\n";
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int temp;
        cin>>temp;
        if(temp==1)
        {
            cout<<"Range query : give l and r :";
            int l,r;
            cin>>l>>r;
            cout<<st.rangesum(l-1,r-1);
        }
        else{
            cout<<"Point update : give index and value :";
            int indx,val;
            cin>>indx>>val;
            st.pointUpdate(indx-1,val);
        }
    }
    return 0;
}