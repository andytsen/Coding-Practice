#include <iostream>
#define max(a,b) ( (a>b) ? (a) : (b) )

using namespace std;

int main() {

    int n;
    cin>>n;
    int a[n+1][n+1],b[n+1][n+1];
    for(int i=1;i<=n;i++){
        cin>>a[1][i];
        b[1][i]=a[1][i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            a[i][j]=a[i-1][j]^a[i-1][j+1];
            b[i][j]=max(a[i][j],max(b[i-1][j],b[i-1][j+1]));
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n - i + 1; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n - i + 1; ++j) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    int test;
    int l,r;
    cin>>test;
    while(test--){
        cin>>l>>r;
        //cout<<b[r-l+1][l]<<endl;
    }
}
