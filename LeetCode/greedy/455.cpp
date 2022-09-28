class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0,i=0,j=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};

int findContentChildren(vector<int> &children, vector<int> &cookies)
{
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size())
    {
        if (children[child] <= cookies[cookie])
            ++child;
        ++cookie;
    }
    return child;
}

