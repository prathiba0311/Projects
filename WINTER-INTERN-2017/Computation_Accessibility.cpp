#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define MOD 1000000007
#define INF 1000000000
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
#define endl '\n'
#define pl cout<<endl;
ll maxi=LLONG_MIN;
ll mini=LLONG_MAX;
void fast() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
ll t,i,j,k,n,temp,flag,ans,m,cnt,name;		//
vl com;
vl visit;
vl l;
vl r;
vector<pll> L;
 

class Graph 
{ 
    int V;    // No. of vertices 
  
    // Fills Stack with vertices (in increasing order of finishing 
    // times). The top element of stack has the maximum finishing  
    // time 
    void fillOrder(int v, bool visited[], stack<int> &Stack); 
  
    // A recursive function to print DFS starting from v 
    void DFSUtil(int v, bool visited[]); 
    void DFSStore(int v, bool visited[]);
public: 
	// An array of adjacency lists
	list<int> *adj; 
    Graph(int V); 
    void addEdge(int v, int w); 
  
    // The main function that finds and prints strongly connected 
    // components 
    void printSCCs(); 
  
    // Function that returns reverse (or transpose) of this graph 
    Graph getTranspose(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 

void Graph::DFSStore(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
    com[v]=cnt;
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// A recursive function to print DFS starting from v 
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 

  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph Graph::getTranspose() 
{ 
    Graph g(V); 
    for (int v = 0; v < V; v++) 
    { 
        // Recur for all the vertices adjacent to this vertex 
        list<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            g.adj[*i].push_back(v); 
        } 
    } 
    return g; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to vâ€™s list. 
} 
  
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            fillOrder(*i, visited, Stack); 
  
    // All vertices reachable from v are processed by now, push v  
    Stack.push(v); 
} 
  
// The main function that finds and prints all strongly connected  
// components 
void Graph::printSCCs() 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited (For first DFS) 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Fill vertices in stack according to their finishing times 
    for(int i = 0; i < V; i++) 
        if(visited[i] == false) 
            fillOrder(i, visited, Stack); 
  
    // Create a reversed graph 
    Graph gr = getTranspose(); 
  
    // Mark all the vertices as not visited (For second DFS) 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Now process all vertices in order defined by Stack 
    while (Stack.empty() == false) 
    { 
        // Pop a vertex from stack 
        int v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        { 
            gr.DFSStore(v, visited); 
            cnt++; 
        } 
    } 
} 

void dfs_left(set<ll> dag[],vector<ll>& visit,int node)
{
    int i;
	int cur=node;
	visit[cur]=1;
	for(set<ll>::iterator it =dag[cur].begin();it != dag[cur].end();it++)
	{
		if(visit[*it]!=1)
		{
			dfs_left(dag,visit,*it);
		}
	}
    L[cur].ff=name;
    name--;
}
void dfs_right(set<ll> dag[],vector<ll>& visit,int node)
{
	int cur=node;
	visit[cur]=1;
	for(set<ll>::reverse_iterator it =dag[cur].rbegin();it != dag[cur].rend();it++)
	{
		if(visit[*it]!=1)
		{
			dfs_right(dag,visit,*it);
		}
	}
    L[cur].ss=name;
    name--;
}
void query(int n)
{
    srand(time(NULL));
    ofstream F("queries55.txt",ios::out);
    //int N=rand()%1000000;
    int N=100000;
    F<<N<<endl;
    int a,b;
    while(N--)
    {
        a=rand()%n;
        b=rand()%n;
        F<<a<<' '<<b<<endl;
    }
    F.close();
}
// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    cout<<"Opening the Graph in the text file "<<endl;
    clock_t start,end;
    
    ifstream file("Test_Cases_55.txt");

    int v,e;
    start=clock();
    file>>v>>e;
    Graph g(v); 
    for(int i=0;i<e;i++)
    {
        int l,r;
        file>>l>>r;
        g.addEdge(l-1,r-1);
    }

    com.resize(v);
    g.printSCCs(); 
    set<ll> dag[cnt+2];
    set<ll> checkout;
    vl freq_in(cnt,0);

    for(i=0;i<v;i++)
    {
    	for( list<int>::iterator it=g.adj[i].begin();it != g.adj[i].end();it++)
    	{
    		if(com[*it]!=com[i])
    	       dag[com[i]].insert(com[*it]);
    	}  
    }
    for (i=0;i<cnt;i++)
    {
        if(dag[i].size()==0)
        {
            dag[i].insert(cnt+1);
		}
	}

    for(i=0;i<cnt;i++)
    {
    	for(set<ll>::iterator it =dag[i].begin();it != dag[i].end();it++)
    	{
    		checkout.insert(*it);
    	}
    }

    for(set<ll>::iterator it =checkout.begin();it != checkout.end();it++)
    	{
    		freq_in[*it]++;
    	}
    
    for(i=0;i<freq_in.size();i++)
    {
    	if(freq_in[i]==0)
    	{
    		dag[cnt].insert(i);
    	}
    }

  //initialisations
    visit.resize(cnt+2,0);
    name=cnt+2;
    L.resize(cnt+2);

    dfs_left(dag,visit,cnt);

    name=cnt+2;
    visit.clear();
    visit.resize(cnt+2,0);
    dfs_right(dag,visit,cnt);
    file.close();
    end=clock();
    cout.precision(5);
    cout<<"Time taken for computation is: "<<fixed<<double(end-start)/double(CLOCKS_PER_SEC)<<endl;
    cout<<"Generating queries onto queries.txt"<<endl;
    query(v);
    int run;
    file.open("queries55.txt");
    ofstream file2("55p.txt",ios::out);
    ofstream file1("answers.txt",ios::out|ios::app);
    file>>run;
    file1<<v<<' '<<e<<' '<<run<<endl;
    file1.precision(5);
    file1<<"Time taken for computation is: "<<fixed<<double(end-start)/double(CLOCKS_PER_SEC)<<' ';
    clock_t start1,end1;
    start1=clock(); 
    while(run--)
    {
        
        int v1,v2;
        file>>v1>>v2;
        if(L[com[v1]].ff<=L[com[v2]].ff&&L[com[v1]].ss<=L[com[v2]].ss)
            file2<<"Yes, "<<v2<<" is reachable from "<<v1<<endl;
        else
            file2<<"No, "<<v2<<" is not reachable from "<<v1<<endl;
    }
    end1=clock();
    file1.precision(5);
    file1<<fixed<< (double)(end1-start1)/double(CLOCKS_PER_SEC)<<' ';
    file.close();
    file2.close();
    file1.close();
    return 0;
} 
