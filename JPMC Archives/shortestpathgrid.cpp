/* Given a grid of integers , find the shortest
sum path from 1,1 to n,m 
*/

#include<bits/stdc++.h>
using namespace std;

map<int,int> node_nums;							// stores node number and value

void dijkstra(vector<int> graph[],bool visited[],int n,int m,int count)
{
    int dist[n*m+1] ;				// set the vertices distances as infinity
    for(int i = 1 ; i<=n*m ; i++)
    	dist[i] = INT_MAX;
    dist[1] = node_nums[1];
    multiset < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.insert({node_nums[1] , 1});                          // insert the source node with distance = 0

    while(!s.empty())
    {
        pair <int , int> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        int x = p.second; int wei = p.first;
        if( visited[x] ) continue;                  // check if the popped vertex is visited before
         visited[x] = true;

        for(int i = 0; i < graph[x].size(); i++)
        {
        	if(!visited[graph[x][i]])
        	{
	            int e = graph[x][i];
	            int w = node_nums[graph[x][i]];
	            if(dist[x] + w < dist[e] )
	            {            						// check if the next vertex distance could be minimized
	                dist[e] = dist[x] + w;
	                s.insert({dist[e],e});           // insert the next vertex with the updated distance
	            }
	        }
        }
    }
    for(int i = 1 ; i<=count ; i++)
    		cout<<dist[i]<<" ";
}

int main()
{
	int n,m;
	cin>>n>>m;
	pair<int,int> arr[n][m];
	bool visited[n*m+1];
	memset(visited, false , sizeof(visited));  
	int count = 1;				//count node number 
	int temp;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			cin>>temp;		//value
			node_nums[count] = temp;
			arr[i][j] = make_pair(count,temp);
			count++;
		}
	}
	count--;
	vector<int> graph[n*m+1];

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			if(i == n-1 && j == n-1)
				break;
			else if(i == n-1)
			{
				graph[arr[i][j].first].push_back(arr[i][j+1].first);
				graph[arr[i][j+1].first].push_back(arr[i][j].first);
			}
			else if(j == m-1)
			{
				graph[arr[i][j].first].push_back(arr[i+1][j].first);
				graph[arr[i+1][j].first].push_back(arr[i][j].first);
			}
			else
			{
				graph[arr[i][j].first].push_back(arr[i+1][j].first);
				graph[arr[i][j].first].push_back(arr[i][j+1].first);
				graph[arr[i+1][j].first].push_back(arr[i][j].first);
				graph[arr[i][j+1].first].push_back(arr[i][j].first);
			}
			
		}
	}

	/* Print graph */
	for(int i = 1 ; i <= n*m ; i++)
	{
		cout<<"Node "<<i<<": ";
		for(int j = 0 ; j < graph[i].size() ; j++)
		{
			cout<<node_nums[graph[i][j]]<<" ";
		}
		cout<<endl;
	}


	dijkstra(graph,visited,n,m,count);


}