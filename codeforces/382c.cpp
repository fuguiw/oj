#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int n,i,a[100000];
map<int,int> R,X,C;
int main()
{
	for(cin>>n; i<n; cin>>a[i++]);
	if (n==1) cout << -1;
	else
	{
		for(sort(a,a+n);--i;) ++X[a[i]-a[i-1]], C[a[i]-a[i-1]]=i;
		int t,p;
		t=X.begin()->first;
		p=X.rbegin()->first;
		if (t==p) R[a[0]-t]=R[a[n-1]+t]=(n>2 || t%2)?1:R[a[0]+t/2]=1;
		if (X.size()==2 && p==2*t && X[p]==1) R[a[C[p]]-t]=1;
		cout << R.size() << endl;
		for (map<int,int>::iterator e=R.begin(); R.size()&& e!=R.end(); ++e)  cout << e->first << ' ';
	}
	return 0;
}
