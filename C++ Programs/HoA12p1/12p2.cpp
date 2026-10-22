#include <iostream>
#include <cstring>
#include <algorithm>

int memo[1000];

int getMinSteps ( int n )
{
    if ( n == 1 ) return 0; // base case
    if( memo[n] != -1 ) return memo[n]; // we have solved it already :)
    int r = 1 + getMinSteps( n - 1 ); // '-1' step . 'r' will contain the optimal answer finally
    if( n%2 == 0 ) r = std::min( r , 1 + getMinSteps( n / 2 ) ) ; // '/2' step
    if( n%3 == 0 ) r = std::min( r , 1 + getMinSteps( n / 3 ) ) ; // '/3' step
    memo[n] = r ; // save the result.
    return r;
}

int main(){
    std::memset(memo, -1, sizeof memo);
    int t[] = {1, 4, 7, 10};
    for(int n : t) std::cout << "n = " << n << " -> " << getMinSteps(n) << std::endl;
}