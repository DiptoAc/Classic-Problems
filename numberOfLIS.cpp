//n*n time complexity and n space complexity. 
int findNumberOfLIS(vector<int>& nums) 
    {
        int i,j,k;
        vector<int>v=nums;
        vector<int>vec(1,-1e7),temp(1,-1e7);
        for(auto it:v){vec.pb(it);}
        int len=vec.size();
        vector<int>track(len),mp(len);
        for(i=1;i<len;i++)
        {
            if(temp.back()<vec[i])
            {
                temp.pb(vec[i]);
                track[i]=temp.size()-1;
                continue;
            }
            int pos=lower_bound(temp.begin(),temp.end(),vec[i])-temp.begin();
            temp[pos]=vec[i];
            track[i]=pos;
        }
        int cnt=0;
        mp[0]=1;
        for(i=1;i<len;i++)
        {
            for(j=0;j<i;j++)
            {
                if(vec[j]<vec[i] && track[i]-1==track[j])
                {
                    mp[i]+=mp[j];
                }
            }
        }
        int ans=0;
        for(i=len-1;i>=0;i--)
        {
            if(track[i]==temp.size()-1){ans+=mp[i];}
        }
        return ans;
    }
//This function will find the number of lis.
