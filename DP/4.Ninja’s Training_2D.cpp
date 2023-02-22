// Simple recurssive code

int solve(int n,vector<vector<int>> &points,int exercise){

    if(n==0){
        int mari = 0;
        for(int i=0;i<3;i++){
            if(i != exercise){
                mari = max(mari,points[n][i]);
            }
        }
        return mari;
    }

    
    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=exercise){
            int power = points[n][i] + solve(n-1,points,i);
            maxi = max(maxi,power);
        }
    }
    return maxi;
}

// DP top down
int solve(int n,vector<vector<int>> &points,int exercise,vector<vector<int>> &dp){

    if(n==0){
        int mari = 0;
        for(int i=0;i<3;i++){
            if(i != exercise){
                mari = max(mari,points[n][i]);
            }
        }
        return mari;
    }
    if (dp[n][exercise] != -1) {
        return dp[n][exercise];
    }

    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i!=exercise){
            int power = points[n][i] + solve(n-1,points,i,dp);
            maxi = max(maxi,power);
        }
    }
    return dp[n][exercise] = maxi;
}

// DP bottom up approach
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][1],points[0][0]);
    dp[0][3] = max(points[0][1],max(points[0][2],points[0][0]));


    for (int i = 1; i <= n - 1; i++) {
      for (int last = 0; last <= 3; last++) {
          dp[i][last] = 0;
        //   int maxi = 0;
          for (int task = 0; task < 3; task++) {
            if (task != last) {
                int power = points[i][task] + dp[i-1][task];
                dp[i][last] = max(dp[i][last],power);
            }
          }
          
      }
    }
    return dp[n-1][3];
}

// dp bottom up with space optimisation 
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector < int > prev(4, 0);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for (int day = 1; day < n; day++) {

    vector < int > temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }

    prev = temp;

  }

  return prev[3];
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> ninja(4, vector<int>(4, -1));
    return solve(n-1,points,3);
}