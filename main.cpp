#include <iostream>
#include <fstream>
         
using namespace std;
                        
int main() {
    ifstream file;
    file.open("input.txt");  
     
    int n, m;       
    file >> n >> m;
             
    int allocation[n][m];
    int max_demand[n][m];
    int available[m];
    int need[n][m];
    int finish[n];
    int safe_sequence[n];
    
   // Read in the available resources
    for (int i = 0; i < m; i++) {
        file >> available[i];
    }
 
   // Read in the allocation matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> allocation[i][j];
        }
    }
    
    // Read in the max demand matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> max_demand[i][j];
        }
    }
     
    int f[n], ans[n], ind = 0;
    for (int k = 0; k < n; k++) {
        f[k] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max_demand[i][j] - allocation[i][j];
        }
    }
    
    int y = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        flag = 1;
                        break;
                    }
                }
                
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        available[y] += allocation[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
   
    int flag = 1;
   
    // To check if sequence is safe or not
    for(int i = 0;i<n;i++) {
        if(f[i]==0) {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }
 
    if(flag==1) {
        cout << "Following is the SAFE Sequence" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << " P" << ans[i] << " ->";
        }
        cout << " P" << ans[n - 1] <<endl;
    }
 
    return (0);
    file.close();
}            
    
    


