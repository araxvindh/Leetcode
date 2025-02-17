class Solution {
public:
    
    bool isVaild(string s)
    {
        int bal=0;
        for(auto it :s)
        {
            if(it=='(')
            {
                bal++;
            }
            else if(it==')')
            {
                bal--;
            }

            if (bal<0) return false;
        }

        return bal==0;
    }

    vector<string> removeInvalidParentheses(string s) {
        
        vector<string>res;

        unordered_set<string>vis;
        queue<string>q;
        q.push(s);

        vis.insert(s);

        bool found =false;

        while(!q.empty())
        {
            string curr=q.front();
            q.pop();

            if(isVaild((curr)))
            {
                found=true;
                res.push_back(curr);
            }
            if(found) continue;
            for(int i=0;i<curr.size();i++)
            {
                if(curr[i]!='(' && curr[i]!=')') continue;
                string next =curr.substr(0,i)+curr.substr(i+1);

                if(vis.find(next)==vis.end())
                {
                    vis.insert(next);
                    q.push(next);
                }
            }
        }
        return res;
    }
};