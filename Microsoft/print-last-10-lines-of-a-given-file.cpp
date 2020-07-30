// '\n' is considered one char in a string in c++ ; 

#include<bits/stdc++.h>
using namespace std;
#define DELIM '\n'

int main(){
    string str = "str1\nstr2\nstr3\nstr4\nstr5\nstr6\nstr7\nstr8\nstr9\nstr10\nstr11\nstr12\nstr13\nstr14\nstr15\nstr16\nstr17\nstr18\nstr19\nstr20\nstr21\nstr22\nstr23\nstr24\nstr25";
    int key=10;                 // key - last 10 lines
    int siz = str.size();
    cout<<"size is "<<siz<<endl;
    int count =0;
    int i = siz-1;
    while(count<key){
        if(str[i]==DELIM){
            count++;
            i--;
        }
        else{
            i--;
        }
    }
    cout<<str.substr(i+1,siz-i-1);  // from position i+1 onwards the next (siz-i-1) characters
}