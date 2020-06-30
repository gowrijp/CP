void subset(vector<int> &arr,vector<vector<int>> &ans,vector<int> temp,int index)
{
    //insert
    ans.push_back(temp);

    for(int i=index;i<arr.size();i++)
    {
        temp.push_back(arr[i]);
        subset(arr,ans,temp,i+1);
        temp.pop_back();
    }
    return;
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> ans;
    vector<vector<int>> fin;
    vector<int> arr;
    for(int i=1;i<=A;i++){
      arr.push_back(i);
    }
    int index=0;
    vector<int> temp;
    subset(arr,ans,temp,index);
    int le=ans.size();
    for(int t=0;t<le;t++){
      if(ans[t].size()==B){
        fin.push_back(ans[t]);
      }
    }
    return fin;


}
