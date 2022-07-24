#include <iostream>
using namespace std;

/*Complete the functions below*/
int find(int A[],int X)
{
       //add code here
       if(X == A[X]){
           return X;
       }
       return find(A,A[X]); // else find its parent and return it
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
	int x = find(A,X); // parent of X
	int y = find(A,Z); // parent of Z
	A[x] = y; // 

}

int main() {
	// your code goes here
    int t;
    cin>>t;
    int a[n+1];
    for(int i = 1; i<=n; i++){
        a[i] = i;
    }
    int k;
    cin>>k;
    for(int i = 0; i<k; i++){
        string s;
        cin>>s;
        if(s=="UNION"){
            int z,x;
            cin>>z>>x;
            unionSet(a,x,z);
        }
        else{
            int x;
            cin>>x;
            int parent = find(a,x);
            cout<<parent<<" ";
        }
    
    }
    cout<<endl;
	return 0;
}
