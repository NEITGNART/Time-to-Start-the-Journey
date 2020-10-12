Có thể thấy rằng khoảng cách tối thiểu từ mỗi “hình tròn” của hình vuông đến tâm là như nhau (bạn có thể tìm quy luật bằng cách đếm).
Sau đó chia toàn bộ hình vuông thành tám hình tam giác nhỏ + tám đường thẳng, hoặc trực tiếp theo hình tròn để đếm.


#include <bits/stdc++.h>

using namespace std;

int t, n;
long long sum;

int main(void) {
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n;
		n >>= 1;
		sum = (long long)n*(n+1)*(2*n+1)/6;
		cout << sum * 8 << "\n";

	}


	return 0;
}



#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,ans=0;
        long long i;
        cin>>n;
        for(i=2;i<=n/2+1;i++)
        {
            ans+=(i-2)*(i-1);
        } 
        ans*=8;
        for(i=1;i<=n/2+1;i++)
        {
            ans+=(i-1)*8;
        }      
        cout<<ans<<endl;                                                                              
    }
    return 0;
}


#include <bits/stdc++.h>
 
using namespace std;
 
int t, n;
long long sum;
 
int main(void) {
 
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n;
		for (long long i = 1; i <= n/2; ++i) sum += i*i;
		cout << sum * 8 << "\n";
 
	}
 
 
	return 0;
}
