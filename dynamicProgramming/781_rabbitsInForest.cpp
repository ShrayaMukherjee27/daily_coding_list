#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res =0;
        unordered_map<int, int> mp;
        for(int i=0;i<answers.size();i++){
            mp[answers[i]]++;
        }
        for(auto p : mp){
            int rabbit = p.first;
            int rCount = p.second;
            if(rCount % (rabbit + 1) ==0){
                int x = rCount / (rabbit + 1);
                res += (rabbit + 1)*x;
            }
            else{
                int x = rCount / (rabbit + 1);
                res += (rabbit + 1)*(x+1);
            }
        }
        return res;
    }
};