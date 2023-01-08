// Question link: https://leetcode.com/problems/invalid-transactions/

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        int n = transactions.size();
        vector<string> names;
        vector<int> time;
        vector<int> amount;
        vector<string> cities;
        vector<bool> invalid(n, false);
        
        int flag = 0;
        for(auto str:transactions){
            stringstream ss(str);
            string st;
            while(getline(ss,st,',')){
                if(flag==0){
                    names.emplace_back(st);
                    flag=1;
                }
                else if(flag==1){
                    time.emplace_back(stoi(st));
                    flag=2;
                }
                else if(flag==2){
                    amount.emplace_back(stoi(st));
                    flag=3;                    
                }
                else if(flag==3){
                    cities.emplace_back(st);
                    flag=0;                    
                }
            }                    
        }

        for(int i=0; i<n; i++)
        {
            if(amount[i] > 1000)
                invalid[i] = true;
            else
            {
                for(int j=0; j<n; j++)
                {
                    if(names[i]==names[j] && cities[i]!=cities[j] && abs(time[j]-time[i])<=60)
                    {
                        invalid[i] = true;
                        invalid[j] = true;
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
            if(invalid[i])
                res.push_back(transactions[i]);

        return res;

    }
};
