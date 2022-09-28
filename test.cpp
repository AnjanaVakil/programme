#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;
vector<string> getNeighbors(string s)
{
    vector<string> res;
    for (int i = 0; i < 4; i++)
    {
        char temp = s[i];
        s[i] = (s[i] == '0' ? '9' : s[i] - 1);
        res.push_back(s);
        s[i]=temp;
        s[i] = (s[i] == '9' ? '0' : s[i] + 1);
        res.push_back(s);
        s[i] = temp;
    }
    for(int i=0;i<res.size();i++){
        cout << res[i] << endl;
    }
    return res;
}
int openLock(vector<string> &deadends, string target)
{
    if (target == "0000")
        return 0;

    unordered_set<string> dead(deadends.begin(), deadends.end());
    string init = "0000";
    if (dead.count(target) || dead.count(init))
        return -1;

    queue<pair<string, int> > q;
    q.emplace(init, 0);
    unordered_set<string> visited = {init};
    while (!q.empty())
    {
        auto [cur, step] = q.front();
        q.pop();
        cout << cur << "++\n";
        for (string next : getNeighbors(cur))
        {
            if (!dead.count(next) && !visited.count(next))
            {
                if (next == target)
                    return step + 1;
                q.emplace(next, step + 1);
                visited.insert(next);
            }
        }
    }
    return -1;
}
int main()
{

    // int numCourses = 2;
    // vector<vector<int> > prerequisites;
    // vector<int> temp;
    // temp.push_back(1);
    // temp.push_back(0);
    // prerequisites.push_back(temp);
    // findOrder(numCourses, prerequisites);
    vector<string> deadends;
    deadends.push_back("8888");
    string target = "0009";
    // 100,4,200,1,3,2
    //  strs = ["tars","rats","arts","star"]
    //["blw","bwl","wlb"]
    // strs.push_back(100);
    // strs.push_back(4);
    // strs.push_back(200);
    // strs.push_back(1);
    // strs.push_back(3);
    // strs.push_back(2);
    // cout << openLock(deadends, target);
    getNeighbors("0000");
    // vector<int> nums;
    // vector<vector<int> > seq;
    // //[4,1,5,2,6,3]
    // // [[5,2,6,3],[4,1,5,2]]
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    // // nums.push_back(2);
    // // nums.push_back(6);
    // // nums.push_back(3);
    // vector<int> temp;
    // temp.push_back(1);
    // temp.push_back(2);
    // // temp.push_back(6);
    // // temp.push_back(3);
    // seq.push_back(temp);
    // temp.clear();
    // temp.push_back(1);
    // temp.push_back(3);
    // // temp.push_back(5);
    // // temp.push_back(2);
    // seq.push_back(temp);
    // cout << sequenceReconstruction(nums, seq) << endl;
    return 0;
}