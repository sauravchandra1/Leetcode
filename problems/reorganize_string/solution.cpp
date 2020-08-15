struct Mycomp{
    bool operator()(pair<int,int>& p1, pair<int,int>& p2){
        return p1.second < p2.second;
    }  
};
class Solution {
public:
        string reorganizeString(string str) {
        unordered_map<char,int> hash;
        for(int i = 0; i < str.size();i++){
            hash[str[i]]++;
        }
        if(hash.size()==1)
            return "";
        priority_queue<pair<int,int>,vector<pair<int,int>>,Mycomp> pq;
        for(auto it : hash){
            pq.push({it.first,it.second});
        }
        string result = "";
        while(pq.size()>1){
            auto it = pq.top();
            pq.pop();
            result += it.first;
            auto itr = pq.top();
            pq.pop();
            result += itr.first;
            if(it.second-1 > 0)
                pq.push({it.first, it.second - 1});
            if(itr.second-1 > 0)
                pq.push({itr.first, itr.second - 1});
        }
        if(!pq.empty()){
            auto ip = pq.top();
            pq.pop();
            if(ip.second > 1)
                return "";
           else
                result += ip.first;
        }

        return result; 
    }
};