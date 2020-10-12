Câu hỏi tư duy khá thú vị.
Có thể nhận thấy rằng câu trả lời là 0 khi n = 1, câu trả lời là m khi n = 2 và tổng chênh lệch không vượt quá 2 * m khi n = 3, tức là câu trả lời là 2 * m. Trường hợp lớn nhất là 0 a1 0 a2 0 a3 ... được xây dựng như thế này (a1 + a2 + a3 .. = m) hoặc 0 0 0 m 0 0 0 (m phải được đặt ở giữa)

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n==1) cout<<0<<endl;
        else if(n==2)cout<<m<<endl;
        else cout<<2*m<<endl;
    }
}
