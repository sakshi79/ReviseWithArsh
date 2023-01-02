class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map <int, int> m_secret;
        unordered_map <int, int> m_guess;
        string res = "";

        for(int i=0; i<secret.length(); i++)
        {
            if(secret[i] == guess[i])
                bulls++;
            else{
                m_secret[secret[i]]++;
                m_guess[guess[i]]++;
            }
        }
        for(auto i: m_secret)
        {
            if(m_guess.find(i.first) != m_guess.end() )
            {
                cows += min(i.second, m_guess[i.first] );
            }
        }

        res += to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
    }
};
