#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    ll result, result1, result2, tmp; //正常 优先
    char calc;
    string str;
    stack<ll> st;
    getline(cin, str);
    stringstream ss(str);
    cin >> result;
    ss >> tmp;
    st.push(tmp);
    result2 = tmp;
    while (ss >> calc)
    {
        ss >> tmp;
        if (calc == '+')
        {
            result2 += tmp;
            st.push(tmp);
        }
        else
        {
            result2 *= tmp;
            tmp *= st.top();
            st.pop();
            st.push(tmp);
        }
    }
    result1 = 0;
    while (st.empty() == false)
    {
        //printf("%lld\n", st.top());
        
        result1 += st.top();
        st.pop();
    }
    if (result1 == result && result2 == result)
        puts("U");
    else if (result1 != result && result2 != result)
        puts("I");
    else if (result1 == result && result2 != result)
        puts("M");
    else
        puts("L");
    return 0;
}
