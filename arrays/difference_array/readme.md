It is a technique used to apply range updates to an array. It helps to do multiple updates in constant time. Helpful in range modification

update Queries are given for eg  [(1,3,2),(2,4,3)] which means from index 1 to 3 increase each value by 2 and for index 2 to 4 increase each value by 3

For brute force,we can go to each range again and again and update the array
Worst case time complexity -> O(Q*N) where N = length of the array and Q=no of queries. It is like a prefix sum techique

eg:
nums=[0,0,0,0,0]
q=[(0,2,5)] where L=0,R=2,x=5

At the starting index,add value i.e add 5 to index 0
At the ending index,take it's next index i.e 2+1=3 and add a -(value) i.e -5 in this case. If this index doesn't exist,ignore this step

now, nums becomes
nums=[5,0,0,-5,0] ->taking prefix, we get
nums=[5,5,5,0,0] ->required array

For each query,
arr[L]+=x
arr[R+1]-=x (x+1<N)
Then take prefix sum

Code

int main()
{


//O(1) operation
for(auto &query:queries)
{
    int start=query[0];
    int end=query[1];
    int x=query[2];

    arr[start]+=x;
    if(end+1<n)
    {
        arr[end+1]-=x;
    }
}

//O(n)
for(int i=0;i<n;i++)
{
    arr[i]+=arr[i-1];
}
}