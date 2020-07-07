/*Convert any integer to a roman numeral
eg : 39 - XXXIX
*/

string Solution::intToRoman(int A){
  string ans = "";
  while(A){
    if(A-1000>=0){
      ans+="M";
      A-=1000;
    }
    else if(A-900>=0){
      ans+="CM";
      A-=900;
    }
    else if(A-500>=0){
      ans+="D";
      A-=500;
    }
    else if(A-400>=0){
      ans+="CD";
      A-=400;
    }
    else if(A-100>=0){
      ans+="C";
      A-=100;
    }
    else if(A-90>=0){
      ans+="XC";
      A-=90;
    }
    else if(A-50>=0){
      ans+="L";
      A-=50;
    }
    else if(A-40>=0){
      ans+="XL";
      A-=40;
    }
    else if(A-10>=0){
      ans+="X";
      A-=10;
    }
    else if(A-9>=0){
      ans+="IX";
      A-=9;
    }
    else if(A-5>=0)
    {
        ans+="V";
        A-=5;
    }
    else if(A-4>=0)
    {
        ans+="IV";
        A-=4;
    }
    else
    {
        ans+="I";
        A-=1;
    }
  }
  return ans;
}
