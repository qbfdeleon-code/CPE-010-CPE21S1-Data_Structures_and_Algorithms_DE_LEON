#include <iostream>

const int M = 4, N = 4;
int mat[M][N] = {{4,7,1,6},{6,7,3,9},{3,8,1,2},{7,1,7,3}};

int countPaths(int i, int j, int cost){
    if(i < 0 || j < 0 || cost < mat[i][j]) return 0;
    if(i == 0 && j == 0) return cost == mat[0][0];
    return countPaths(i-1, j, cost - mat[i][j]) + countPaths(i, j-1, cost - mat[i][j]);
}

int main(){
    std::cout << "Paths with cost 26: " << countPaths(M-1, N-1, 26) << std::endl;
}