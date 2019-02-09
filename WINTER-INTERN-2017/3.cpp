#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define MOD 1000000007
#define INF 1000000000
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define ss second
#define ff first
#define endl '\n'
#define pl cout<<endl;
ll maxi=LLONG_MIN;
ll mini=LLONG_MAX;
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
ll t,i,j,k,n,temp,flag,ans,m,cnt,name;
vl com;
vl visit;
vl l;
vl r;
vector<pll> L;
int check;
void dfs(vi adj[],vi &vis, int v1,int v2)
{
	vis[v1]=1;
	if(v1==v2)
		check=1;
	for(int i=0;i<adj[v1].size();i++)
		if(!vis[adj[v1][i]])
			dfs(adj,vis,adj[v1][i],v2);
}
int main()
{
	ifstream file("Test_Cases_44.txt");
	int v,e;
	file>>v>>e;
	vi adj[v];
	for(int i=0;i<e;i++)
	{	
		int a,b;
		file>>a>>b;
		adj[a-1].pb(b-1);
	}
	vi vis(v);
	file.close();

	ifstream file1("queries44.txt");
	int run;
	file1>>run;
	ofstream file2("44d.txt",ios::out);
	ofstream file3("answers1.txt",ios::out|ios::app);
	clock_t start1,end1;
    start1=clock();
	while(run--)
	{
		vis.clear();
		vis.resize(v,0);
		int v1,v2;
        file1>>v1>>v2;
        check=0;
        dfs(adj,vis,v1,v2);
        if(check==1)
        	file2<<"Yes, "<<v2<<" is reachable from "<<v1<<endl;
        else
        	file2<<"No, "<<v2<<" is not reachable from "<<v1<<endl;
	}
	file1.close();
	file2.close();
	end1=clock();
    file3.precision(5);
    file3<<fixed<< (double)(end1-start1)/double(CLOCKS_PER_SEC)<<endl;
    file3.close();
}