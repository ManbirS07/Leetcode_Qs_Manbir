class Solution {
public:
    int maxArea(vector<int>& arr) 
    {
        int area=0;
        int n=arr.size();
        int l=0,r=n-1;

        while(l<=r)
        {
            if(arr[l]<arr[r])
            {
                //hamesha min height lete h kyuki zyada wali lenge toh watter will overflow
                //pehla hi case solve karke dekhlena when height=min(1,7) and width= last index-first index
                int height=min(arr[l],arr[r]);
                int width=r-l;
                area=max(area,height*width);
                l++;
            }
            else 
            {
                int height=min(arr[l],arr[r]); //height=arr[r]
                int width=r-l;
                area=max(area,height*width);
                r--;
            }
        }
        return area;
    }
};