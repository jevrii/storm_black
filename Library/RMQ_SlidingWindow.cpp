void sliding_window_minimum(vector<int>& a, int k) {
	// pair<int, int> represents the pair (a[i], i)
	deque<pii> window;
	for (int i = 0; i < a.size(); i++) {
		while (!window.empty() && window.back().first >= a[i]) // ### change to <= for max
			window.pop_back();
		window.emplace_back(mp(a[i], i));
		while(window.front().second <= i - k)
			window.pop_front();
		cout << (window.front().first) << ' '; // answer for first subarray
	}
}