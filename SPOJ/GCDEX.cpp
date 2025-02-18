#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll MAX=1000006;
ll A[1000006], phi[1000006];

void phii(){
  for(ll i=0; i<MAX; i++)
    phi[i] = i;
  for(ll i=1; i<MAX; i++){
	for(ll j=2*i; j<MAX; j+=i)
	  phi[j] -= phi[i];		
  }
}

void preprocess(){
  phii();	
  for(ll i=1; i<=MAX; i++){
  	for(ll j=2*i; j<=MAX; j+=i){
  	  A[j] += (i*phi[j/i]);	
	}
  }	
  for(ll i=1; i<MAX; i++) A[i]+=A[i-1];
}

int main(){
  preprocess();
  while(true){
  	ll n;
  	cin>>n;
  	if(n==0)
  	   break;
  	cout<<A[n]<<endl;
  	
  }
  return 0;	
}
