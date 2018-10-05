long long parts[P][P]; // [m][n] = # opdelingen van n die overal <= m zijn

long long partition(int upper) {
	parts[0][0] = 1;
	fill_n (parts[0] + 1, upper, 0);
	for (int n = 1; n <= upper; n++) {
		parts[n][0] = 1;
		for (int sum = 1; sum <= upper; sum++) {
			parts[n][sum] = parts[n - 1][sum];
			if (sum >= n)
				parts[n][sum] += parts[n][sum - n];
		}
	}
	return parts[upper][upper];
}

