// max value under constraint upper bound on weight
int knapsack( vector<int> value, vector<int> weight, int max_weight ) {
    int n = value.size();
    vector<vector<int>> m( n+1, vector<int>( max_weight+1, 0 ) );
    for( int i = 0; i < n; ++i )
        for( int j = 0; j <= max_weight; ++j )
            if( weight[i] > j )
                m[i+1][j] = m[i][j];
            else
                m[i+1][j] = max( m[i][j], m[i][j-weight[i]] + value[i] );
    return m[n][max_weight];
}
