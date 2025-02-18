#include<bits/stdc++.h>
using namespace std;

//Abbreviation of types
#define ull unsigned long long int
#define ll long long int
#define vi vector<int> 
#define vl vector<ll> 
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pair<ll,ll>>
#define umap unordered_map
#define uset unordered_set
#define pb push_back 
#define ff first 
#define ss second

//Abbreviation of operations
#define all(c) c.begin(), c.end()
#define maxarr(A) *max_element(A, A+n) 
#define maxvec(v) *max_element(all(v)) 
#define minarr(A) *min_element(A, A+n);
#define minvec(v) *min_element(all(v));
#define lb(v,elem) lower_bound(all(v),elem)
#define ub(v,elem) upper_bound(all(v),elem)
#define sz(z) (int)z.size()

//Abbreviation of loops
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rev(i,a,b) for(int i=a; i>=b; i--)

//Taking inputs
#define readarray(a,n) rep(i,0,n) cin>>a[i];
#define print(a,n) rep(i,0,n) cout<<a[i]<<" ";cout<<endl;

//Fast IO
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//Debugging tools 
#define debug(v) cout<<#v<<endl;for(ll i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
#define debugn(v,n) cout<<#v<<endl;for(ll i=0; i<n; i++) cout<<v[i]<<" "; cout<<endl;
#define printset(s) for(auto it=s.begin; it!=s.end(); it++) cout<<*it<<" ";cout<<endl;
#define deb(sum) cout<<#sum<<" = "<<sum<<endl;

//Predefined values
#define mod 998244353
#define INF (ll)1e18
#define endl "\n"
#define pi 3.142857142857143

ll binpow(ll a, ll b) { if (b == 0) return 1; ll res = binpow(a, b / 2);if (b % 2) return res * res * a;else return res * res;}
ll modexpo(ll x, ll y, ll p){ ll res = 1;  x = x % p; if (x == 0) return 0; while (y > 0){  if (y & 1)  res = (res*x) % p;  y = y>>1;x = (x*x) % p; } return res%mod;}
ll modmul(ll a, ll b){ ll res = 0;a = a%mod;while(b>0){if(b%2==1)res = (res + a)%mod;a = (a<<1) % mod;b = b>>1;}return res % mod;}
ll modmulinv(ll a){ll v = 0, u = 1,md = mod;if(md==1) return 0;while(a>1){ll d = a/md;ll t = md;md = a % md;a = t;t = v;v = u - d * v;u = t;}if(u<0) u += mod;return u;}
vector<int> getPrimes(int M){vi p(M+1,1);vector<int>prime;for(int i=2; i*i <= M; ++i){if(p[i]){for(int j = i*i; j<=M; j+=i) p[j] = 0;}}rep(i,2,M) if(p[i]) prime.push_back(i);return prime;}
void checkAcceptance(){
    f1.open("output.in",ios::in);
    f2.open("expected.in",ios::in);
    while(1){
        c1=f1.get();
        c2=f2.get();
        if(c1!=c2){
            flag=0;
            break;
        }
        if((c1==EOF)||(c2==EOF))
            break;
    }
    f1.close();
    f2.close();
    if(flag)
        cout<<"Files are same.";
    else
        cout<<"Files are not same.";
}

string s;
int findval(int l, int r, int type){
	int val=0;
	rep(i,l,r+1) if(s[i]!=('a'+type)) val++;
	return val;

}

int findChange(int l, int r, int type){
	if(r==l){
		if(('a'+type)==s[l]) return 0;
		return 1;
	}

	int m = (l+r)/2;
	int tm1 = findval(l,m,type);
	int tm2 = findval(m+1,r,type);
	
	return min(tm1+findChange(m+1,r,type+1), tm2 + findChange(l,m,type+1));
}
  
int main() { 
    FASTIO;
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif

    //vi pm = getPrimes(1005);
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin>>s;
        
    	int ans = findChange(0,n-1,0);
    	//ans = min(tmp, ans);

    	cout<<ans<<endl;

    }

    
    #ifndef ONLINE_JUDGE
        checkAcceptance();
    #endif
    return 0;
} 








