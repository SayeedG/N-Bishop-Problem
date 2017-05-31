//Sayeed Gulmahamad
#include <iostream>
#include <cmath>
using namespace std;
bool ok(int q[], int col, int n){
    for (int i=0; i<col; i++)
        if(q[i]/n+q[i]%n==q[col]/n+q[col]%n || q[i]/n-q[i]%n==q[col]/n-q[col]%n)
            return false;
    return true;
}
int factorial(int n){
    if (n==1) return n;
    return n*factorial(n-1);
}
void backtrack(int &c, int count, int k, int q[]){
    c--;
    if(c==-1){
        cout <<count/factorial(k)<<endl;
        delete []q;
        exit(1);
    }
}
int main(){
    int c=1, count=0, n = 0, k = 0;
    bool from_backtrack=false;
    cout <<"Give me an nXn board: ";
    cin >>n;
    cout <<"Enter k bishops: ";
    cin >>k;
    int* q = new int[k];
    q[0]=0;
    cout << "N: " << n << " \nK: " << k << " \n# Bishops: ";
    
    
    while(true){
        while(c<k){
            if(!from_backtrack)
                q[c]=-1;
            from_backtrack=false;
            while(q[c]<n*n){
                q[c]++;
                if(q[c]==n*n){
                    backtrack(c, count, k, q);
                    from_backtrack=true;
                    continue;
                }
                if(ok(q, c, n)){
                    c++;
                    break;
                }
            }
        }
        count++;
        backtrack(c, count, k, q);
        from_backtrack=true;
    }
    return 0;
}