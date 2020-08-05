// my first ans 
#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    int t;cin>>t;
    //int t=1;
    while(t--){
        int n;
        cin>>n;
        string inp;
        //cout<<inp<<endl;
        cin>>inp;
        int count=0;
        for(int i=1;i<=n/2;i++){
            string s="";
            s.append(string(i,'0'));
            s.append(string(i,'1'));
            //cout<<s<<endl;
            string inv="";
            inv.append(string(i,'1'));
            inv.append(string(i,'0'));
            //cout<<inv<<endl;
            for(int j=0;j<=n-2*i;j++){
                if(inp.substr(j,2*i)==s || inp.substr(j,2*i)==inv){
                   count++; 
                } 
            }
        }
        cout<<count<<endl;
    }
    
}
