#=>heap implementation
class heap{
    public :
    vector<int>input;
    int cur_Size=0;
    
    void modify_heap_delete(vector<int>&input,int index){
        int left_child=2*index+1;
        int right_child=2*index+2;
        int final_indexindex=index;
        int n=input.size()-1;
        
        if(left_child<n && input[final_indexindex]<input[left_child]){
            final_indexindex=left_child;
        }
        if(right_child<n && input[final_indexindex]<input[right_child])
        {
            final_indexindex=right_child;
        }
        if(index!=final_indexindex){
            swap(input[index],input[final_indexindex]);
            modify_heap_delete(input,final_indexindex);
            return;
        }
        
    }
    
    void delete_node(){
        cur_Size--;
        if(input.size()==1){
            input.clear();
            return;
        }
        else {
            input[0]=input[input.size()-1];
            modify_heap_delete(input,0);
        }
    }
    void modify_heap(vector<int>&input,int index){
        int cur_index=index;
        int parent=(index/2);
        
        if(input[parent]>=input[index]){
            return;
        }
        else {
            swap(input[parent],input[index]);
            modify_heap(input,parent);
        }
    }
    void insert_element(int x){
        input.push_back(x);
        cur_Size++;
        modify_heap(input,input.size()-1);
    }
    void output(){
        for(int i=0;i<cur_Size;i++)
        cout<<input[i]<<" ";
        cout<<endl;
    }
};

#include <bits/stdc++.h>
using namespace std;

int heap[100010];

void heapify(int i,int n)
{
      int largest=i;
      int l=2*i+1;
      int r=2*i+2;
      
      if(l<n && heap[l]>heap[largest])
      largest=l;
      
      if(r<n && heap[r]>heap[largest])
      largest=r;
      
      if(largest!=i)
      {
            swap(heap[largest],heap[i]);
            heapify(largest,n);
      }
      
}

void buildmaxheap(vector<int>heap)    //O(3N)
{
      int n=heap.size();
      for(int i=n/2;i>=0;i--)
      {
            heapify(i,n);
      }
}

void heapsort(vector<int>heap)   //max heap --> ascending sorted array 
                                  //min heap ==> desending sorted array                                          
{
      buildmaxheap(heap);
      
      int n=v.size();
      for(int i=n-1;i>=0;i--)
      {
            swap(heap[0],heap[i]);
            maxheapify(0,i);
      }
}

//priority queue

void insert(int x)
{
      int k=n;
      heap[n]=x;
      n++;
      
      heapfilterup(k);
}

void heapfilterup(int k)
{
      int p=(k-1)/2;
      
      if(p>=0 && heap[p]<heap[k])
      {
            swap(heap[p],heap[k]);
            heapfilterup(p);
      }
}
/*   while(k/2>0)
      {
            int p=(k-1)/2;
            
            if(heap[k]<heap[p])
            return ;
            else {
                  swap(heap[p],heap[k]);
                  k=p;
            }
      }  */
      
//    Sliding Window Maximum (Maximum of all subarrays of size k)
vector<int> solve(vector<int>v,int k)
{
      deque<int>dq;
      vector<int>ans;
      
      for(int i=0;i<v.size();i++)
      {
            while(!dq.empty() && dq.front()>=(i-k))   //ensure dq has only those elements which is in i to i-k range
            dq.pop_front();
            
            while(!dq.empty() && v[dq.front()]<v[i])  
            dq.pop_back();
            
            dq.push_back(i);
            
            if(i+1>=k)
            ans.push_back(v[dq.front()]);
      }
      return ans;
}
     
//K largest element in array

int solve(vector<int>v)
{
      priority_queue<int,vector<int>,greater<int>>pq;
      
      for(int i=0;i<n;i++)
      {
            if(pq.size()<k)
            {
                  pq.push(v[i]);
            }
            else {
                  if(pq.front()<v[i])
                  {
                        pq.pop();
                        pq.push(v[i]);
                  }
            }
      }
      return pq.front();
}

//Merge K sorted Arrays 

vector<int> solve(vector<vector<int>>v)
{
      priority_queue<v,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>>pq;
      
      for(int i=0;i<v.size();i++)
      pq.push({v[i][0],{i,0}});     //element   Array number    pos
      
      vector<int>ans;
      
      while(!pq.empty())
      {
             pair<int,pair<int,int>>p=pq.top();
             pq.pop();
             
             ans.push_back(p.first);
             
             int x=p.second.first;
             int pos=p.second.second;
             
             if(v[x].size()-1>pos)
             {
                   pq.push({v[x][pos+1],{x,pos+1}});
             }
      }
     return ans;
}

// K-th Largest Sum Contiguous Subarray    //n^2log(n^2)  ===> n^2log(k)
int solve(vector<int>v,int k)
{
      int n=v.size();
      int sum[n+1]={0};
      sum[0]=0;
      sum[1]=v[0];
      for(int i=2;i<n;i++)
      sum[i]=sum[i-1]+v[i-1];
      
      priority_queue<int,vector<int>,greater<int>>pq;
      
      for(int i=1;i<=n;i++)
      {
            for(int j=i;j<=n;j++)
            {
                  int x=sum[j]-sum[i-1];
                  
                  if(pq.size()<k)
                  {
                        pq.push(x);
                  }
                  else {
                        if(pq.top()<x)
                        {
                              pq.pop();
                              pq.push(x);
                        }
                  }
            }
      }
      return pq.top();
}

//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

string reorganize(string str)
{
      string ans="";
      int count=0;
      unordered_map<char,int>mp;
      for(int i=0;i<str.size();i++)
      {
      mp[str[i]]++;
      count=max(count,mp[str[i]]);
      }
      
      if(count>(str.size()/2))return ans;
      
      priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
      
      for(auto x : mp)
      {
            pq.push({x.second,x});
      }
      while(!pq.empty())
      {
            pair<int,char>p=pq.top();
            
            ans.push_back(p.second);
            
            pq.pop();
            
            if(!pq.empty())
            {
                  pair<int,char>q=pq.top();
                  pq.pop();
                  
                  ans.push_back(q.second);
                  
                  if(q.first>1)
                  pq.push({q.first-1,q.second});
                  
            }
            
            if(p.first>1)
            {
                  pq.push({p.first-1,p.second});
            }
      }
      return ans;
}

//Merge K sorted Link list

ListNode* merge(vector<ListNode*>&v)
{
      priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
      
      for(int i=0;i<v.size();i++)
      pq.push({v[i]->val,v[i]});
      
      ListNode* head=new ListNode(-1);
      ListNode* temp=head;
      while(!pq.empty())
      {
            temp->next=pq.top().second;
            pq.pop();
            
            if(pq.top()->next)
            {
                  pq.push({pq.top()->next->val,pq.top()->next});
            }
      }
      return head->next;
}

//Median of stream of integers
class MedianFinder {
public:
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    MedianFinder() {
        while(max_heap.size()!=0)max_heap.pop();
        while(min_heap.size()!=0)min_heap.pop();
    }
    
    void addNum(int num) {
        if(max_heap.size()==0)max_heap.push(num);
        
        else if (max_heap.top()>num){
            max_heap.push(num);
        }
        else min_heap.push(num);
        
        if(max_heap.size()>min_heap.size()+1){
            min_heap.push(max_heap.top());
        max_heap.pop();
        }
        else if (min_heap.size()>max_heap.size())
            
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if((max_heap.size()+min_heap.size())%2==0){
            return (max_heap.top()+min_heap.top())/2.0;
        }
        else return max_heap.top()*1.0;
    }
};

//Minimum cost to connect ropes

int cost(vector<int>v)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<v.size();i++)
    pq.push({v[i]});
    int ans=0;
    while(pq.size()!=1)
    {
       int a=pq.top();
       pq.pop();
       int b=pq.top();
       pq.pop();
       
       ans+=a+b;
       pq.push(a+b);
       
    }
    return pq.top();
}

//comvert Min Heap to Max Heap
// ==> simple hepify with buildmaxheap

//Minimum sum using the elements of the array

string solve(int arr[], int n) {
        sort(arr,arr+n);
        
        int i=0,j=1;
        string s1="",s2="";
        while(j<n)
        {
            s1.push_back(arr[i]+'0');
            s2.push_back(arr[j]+'0');
            
            i=i+2;
            j=j+2;
        }
        if(n%2!=0)
           s1.push_back(arr[i]+'0');
        
        
        string ans="";
        int carry=0;
        i=s1.size()-1,j=s2.size()-1;
        
        while(i>=0 || j>=0 || carry>0)
        {
            int sum=carry;
            if(i>=0)
            sum+=s1[i]-'0';
            
            if(j>=0)
            sum+=s2[j]-'0';
            
            ans.push_back((sum%10)+'0');
            carry=sum/10;
            i--;j--;
        }
        reverse(ans.begin(),ans.end());
        i=0;
        while(i<ans.size()-1 && ans[i]=='0')
        i++;
        
        return ans.substr(i);
}
//Return first k maximum sum of 2 arrays

vector<int>kmaxsum(vector<int>a,vector<int>b,int k)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    priority_queue<pair<int,pair<int,int>,vector<pair<int,pair<int,int>>>>pq;
    int n=a.size()-1;
    int m=b.size()-1;
    
    pq.push({a[n][m],{n,m}});
    vector<int>ans;
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

    
    while(ans.size()!=k)
    {
        pair<int,pair<int,int>p=pq.top();
        pq.pop();
        ans.push_back(p.first);
        
        int x=p.second.first;
        int y=p.second.second;
        
        if(x>0 && dp[x-1][y]=-1)
        {
            pq.push({a[x-1]+b[y],{x-1,y}});
            dp[x-1][y]=1;
        }
        if(y>0 && dp[x][y-1]=-1)
        {
            pq.push({a[x]+b[y-1],{x,y-1}});
            dp[x][y-1]=1;
        }
    }
    return ans;
}

//distict numbers in window
vector<int> distictnumbers(vector<int>v,int B)
{
    vector<int>ans;
    unordered_map<int,int>mp;
    
    for(int i=0;i<v.size();i++)
    mp[v[i]]=0;
    
    int count=0;
    
    for(int i=0;i<v.size();i++)
    {
        mp[v[i]]++;
        if(mp[v[i]]==1)
        count++;
        
        if(i+1>=B)
        {
            ans.push_back(count);
            mp[v[i+1-B]]--;
            
            if(mp[v[i+1-B]]==0)
            count--;
        }
    }
    return ans;
}


int main() {
	// your code goes here
	return 0;
}
