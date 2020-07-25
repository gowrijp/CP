/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.*/

#include<bits/stdc++.h>
using namespace std;
/* some eg : 22/55 , 5/8 , 22/7
numerator = 5
den =8
ans = 0.625
*/
/*
Base case : numerator = 0 then return 0
            check if the overall number is negative
if remainder = 0 return Num/Den
if the denominator has only 2,5,10 and its multiples as factors then it wont be a recurring 
decimal. Else find number of digits in the recurring part
*/


string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    bool minus = ((numerator > 0 && denominator < 0) 
                        || (numerator < 0 && denominator > 0)) ? true  : false;
    int64_t N = abs(int64_t(numerator));
    int64_t D = abs(int64_t(denominator));

    int64_t n = N/D;  //n=0
    string ret;
    if (minus) ret.append("-");
    ret.append(to_string(n)); // ret="0"
    // R is remainder
    int64_t R = N - n*D;        // R = 5
    if (R == 0) return ret; 
    ret.append(".");           //ret="0."
    int nrm = 0;               //nrm=0
    int64_t d = D;
    n = N;
    while(n%10 == 0 && d %10 == 0) {  //n=5 d=8
        n/=10;
        d/=10;
    }
    while(n%5 == 0 && d %5 == 0) {
        n/=5;
        d/=5;
    }
    while(n%2 == 0 && d %2 == 0) {
        n/=2;
        d/=2;
    }
    
    while (d%10 ==0) {
        d/=10;
        nrm++;
    }
    while (d%5==0) {
        d/=5;
        nrm++;
    }
    while (d%2==0) {
        d/=2;
        nrm++;          //nrm=3 and d=1
    }
    
    int pos = ret.length();  // pos=2
    ret.resize(pos+nrm);
    int i = 0;               // i=0
    while (R > 0 && i < nrm) { // R=5 R=2  R=4
        R*=10;                 //R=50 R=20 R=40
        int M = R / D;         //M=6 M=2  M=5
        R -= M * D;            //R=2 R=4 R=0
        ret[pos++] = M + '0';   //ret="0.6" ret="0.62" ret="0.625"
        i++;
    }

    if (R == 0) return ret;

    //first pass calculate length of repeated seq
    
    int lng = 0;
    int64_t Rstart = R;  //Rstart = 1
    
    do {
        R*=10;              //R=10  R=30  R=20 R=60 R=40 R=50
        R -= (R / D) * D;   //R=3  R=2  R=6 R=4 R=5 R=1
        lng++;              //lng=1 lng=2 lng=3 lng=4 lng=5 lng=6
    } while (Rstart != R);
    
    ret.resize(pos+lng+2);  //lng-repeating seq , 2 for the 2 brackets 
    ret[pos++] = '(';       // ret ="0.("
    while (lng-- > 0) {     
        R*=10;              //R=2*10=20
        int64_t M = R / D;  //M=6
        R -= M * D;         //R=2
        ret[pos++] = M + '0'; //changing m to char ret="0.(6"
    }
    ret[pos] = ')';         // ret ="0.(6)"
    return ret;
}

int main(){
    int Num=6;
    int Den = 5;  // 5/8 -> ans=0.625
    // try 22/7 ans = 3.(142857)
    cout<<fractionToDecimal(Num,Den)<<endl;

}