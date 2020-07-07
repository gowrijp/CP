/*Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.
Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20*/

    int Solution::romanToInt(string A) {
        map<char,int>chk;
        chk['L']=50,chk['C']=100,chk['D']=500,chk['M']=1000;
        chk['X']=10,chk['I']=1,chk['V']=5;
        int i=0,ans=0,n=A.size();
        while(i<n)
        {
            if(i!=n-1)
            {
                if(chk[A[i+1]]>chk[A[i]])
                {
                    ans+=chk[A[i+1]]-chk[A[i]];
                    i+=2;
                }
                else
                {
                    ans+=chk[A[i]];
                    i++;
                }
            }
            else
            {
                ans+=chk[A[i]];
                i+=1;
            }
        }
        return ans;
    } 
