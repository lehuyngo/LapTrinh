#include <iostream>

using namespace std;

int main()
{
int n;
    int a[100];
    
    cin>>n;
    for( int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
        cout<<"so chan"<<endl;
        else cout<<"so le"<<endl;
    }
    return 0;
}