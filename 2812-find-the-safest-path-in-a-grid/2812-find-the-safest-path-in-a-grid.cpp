class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){

            auto [x,y]=q.front();
            q.pop();

            for(auto &d:dirs){

                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && ny>=0 && nx<n && ny<n &&
                   dist[nx][ny]==INT_MAX){

                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        int low=0;
        int high=2*n;
        int ans=0;

        while(low<=high){

            int mid=(low+high)/2;

            if(canReach(dist,mid)){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }

        return ans;
    }

    bool canReach(vector<vector<int>>& dist,int safe){

        int n=dist.size();

        if(dist[0][0]<safe)
            return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));

        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){

            auto [x,y]=q.front();
            q.pop();

            if(x==n-1 && y==n-1)
                return true;

            for(auto &d:dirs){

                int nx=x+d[0];
                int ny=y+d[1];

                if(nx>=0 && ny>=0 && nx<n && ny<n &&
                   !vis[nx][ny] &&
                   dist[nx][ny]>=safe){

                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }
};