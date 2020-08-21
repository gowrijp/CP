/*
Alice wants to secure his bank account details and wants to encrypt his password P. He wants to encrypt it in such a fashion:-
Suppose P = "zyxabc", he will randomly shuffle his password, then he will concatenate a random string S1 in starting of P and a random string S2 at end of the string P. Let S1 = "fgh" and S2 = "bvf" then encrypted string become H = "fghcxabyzbvf".
Bob has got a password and an encrypted string, He being a hacker wants to check if the encrypted string can be a valid one for the password he have.
The password and encrypted password only consists of lower case english alphabets.

Input:
First line of input contains an integer T, denoting the number of test cases. First line of each test case contains the string P, second line of the test case contains the string H.

Output:
Print "Yes" if it is a valid one else "No".

Your Task:
This is a functional problem . You don't need to take input just complete the function valid() which accepts two strings P and S as parameters and return 0 or 1.

Constraints:
1<= T  <=30
1<= |P| <=105
1<= |H| <=105

Example:
Input:
2
zyxabc
fghcxabyzbvf
htc
hxtcczht

Output:
Yes
No
*/

// Function to check if two arrays are equal 
bool isEqual(int a[], int b[])
{
    for(int i=0; i<26; i++)
        if(a[i]!=b[i])
            return false;
    
    return true;
}

bool valid(string P, string S){
    // write your code here
    
    // Base Case
    if(S.size() < P.size())
        return false;
    
    // Create two hash arrays of size 26 each
    // for storing frequency of characters
    // hash1[]: stores frequency of characters of password String
    // hash2[]: stores frequency of characters of encrypted string
    //          of window of length P.size()
    int hash1[26] = {0}; 
    int hash2[26] = {0};
    
    // Calculate frequency of password string P
    for(int i=0; i<P.size(); i++)
        hash1[P[i]-'a']++;
        
    // Using two variables l and r for window 
    int l = 0, r = P.size() - 1;
    
    // Calculate hash for first window of encrypted string
    for(int i = l; i<=r; i++)
    {
        hash2[S[i]-'a']++;
    }
    
    // If all characters in current window is same as 
    // that of Password string, we return true 
    if(isEqual(hash1, hash2))
        return true;
        
    // Move window by 1 step ahead
    r++;
        
    // Traverse the encrypted string with
    // window of size P.size()
    while(r<S.size())
    {   
        // Remove first element of last window
        hash2[S[l]-'a']--;
        l++;
        
        // Add last element of current window
        hash2[S[r]-'a']++;
        r++;
        
        // If all characters in current window is same as 
        // that of Password string, we return true
        if(isEqual(hash1, hash2))
            return true;
    }
    
    return false;
}
