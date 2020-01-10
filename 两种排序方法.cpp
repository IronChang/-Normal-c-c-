#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n = 0;
    while(cin>>n)
    {
        int len = 1;
        int lex = 1;
        //cin >> n;
        vector<string> vs(n);
        for (auto &i : vs)
        {
            cin >> i;
        }

        for (int i = 0; i < vs.size()-1; i++)
        {
            if (vs[i].size() > vs[i+1].size())
            {
                len = 0;
            }
        }

        for (int i = 0; i < vs.size()-1; i++)
        {
            if (vs[i] > vs[i + 1])
            {
                lex = 0;
            }
        }

        if (lex == 1 && len == 1)
        {
            cout << "both" << endl;
        }
        else if (lex == 1 && len == 0)
        {
            cout << "lexicographically" << endl;
        }
        else if (lex == 0 && len == 1)
        {
            cout << "lengths" << endl;
        }
        else
        {
            cout<<"none"<<endl;
        }
    }
	return 0;
}
