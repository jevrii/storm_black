// Aho Corasick algorithm.
// Modify lines marked with ###

template <const int TOTLEN, const int SIGMA> struct AhoCorasick  {
	int nxt_node = 1, trie[TOTLEN][SIGMA], fail[TOTLEN], nxt[TOTLEN][SIGMA];
	int has_str[TOTLEN]; // has_str flag, such as count or bitset

	// fail[s]: ending node of the proper prefix of some pattern which is the longest proper suffix of s
	// has_str[s]: indexes of all words ending at s

	void init() {
		memset(trie, -1, sizeof(trie));
		memset(has_str, 0, sizeof(has_str));
		memset(fail, -1, sizeof(fail));
		memset(nxt, -1, sizeof(nxt));
		nxt_node = 1;
	}

	int toInt(char c) {
		if ('a' <= c && c <= 'z') return c - 'a';
		else return c - 'A' + 26;
	}

	void insert(string s, int tag) { // insert string[id] into the trie
		int cur = 0;
		for (char c : s) {
			if (trie[cur][toInt(c)] == -1) // no next node
				trie[cur][toInt(c)] = nxt_node++;
			cur = trie[cur][toInt(c)];
		}
		has_str[cur] += tag; // ### s can terminate at this node. ++ for count, | for bitset
	}

	void buildFail() {
		queue<int> q;
		for (int ch = 0; ch < SIGMA; ch++) // build initial edges for depth-1 nodes
			if (trie[0][ch] >= 1) {
				fail[trie[0][ch]] = 0;
				q.push(trie[0][ch]);
			}
			else trie[0][ch] = 0; // if no edge, loop back to self. modifies trie edge!
		while (q.size()) {
			int now = q.front(); q.pop();
			for (int ch = 0; ch < SIGMA; ch++) {
				if (trie[now][ch] != -1) { // has trie edge
					int f = fail[now];
					while (trie[f][ch] == -1) // go back until node has ch as child
						f = fail[f];
					f = trie[f][ch]; // forwards 1 char, suffix fail points to this
					fail[trie[now][ch]] = f;
					has_str[trie[now][ch]] += has_str[f]; // ### += for count, |= for bitset
					q.push(trie[now][ch]);
				}
			}
		}
	}

	int nextState(int cur, char c) { // at this node, where to go next with edge c?
		if (nxt[cur][toInt(c)] != -1) return nxt[cur][toInt(c)];
		if (trie[cur][toInt(c)] != -1)
			return nxt[cur][toInt(c)] = trie[cur][toInt(c)];
		else return nxt[cur][toInt(c)] = nextState(fail[cur], c);
	}
};

/*
 * Usage:
 *
 * 1. AhoCorasick<1005, 20> aho;
 * 2. aho.init();
 * 3. for all strings, call aho.insert(s, [finish_tag]);
 * 4. aho.buildFail();
 *
 * for string searching, follow each character on aho.nextState
 */

// Example:

void search(string text) { // assume tag has bitset of strings ending here
	int cur = 0;
	for (int i = 0; i < text.length(); i++) {
		char c = text[i];
		cur = aho.nextState(cur, c);
		if (not aho.has_str[cur]) // no string ending here
			continue;
		for (int j = 0; j < n; j++) {
			if (!!(aho.has_str[cur] & (1 << j))) {
				cout<<str[j]<<": [" << i - str[j].length() + 1<<", " << i << "]\n";
			}
		}
	}
}

int main() {
// init n, str[] here.
	n = 4; string input[] = {"he", "she", "his", "hers"};
	for (int i = 0; i < n; i++) aho.insert(input[i]);
	aho.buildFail();
	for (int i = 0; i < nxt_node; i++) {
		cout << "node " << i << ": " << fail[i] << ' ';
		for (int j = 0; j < n; j++)
			cout << !!(has_str[i] & (1 << j));
		cout << '\n';
	}
// 0 0 0 1 2 0 3 0 3; 2: 1000, 5: 1100, 7: 0010, 9: 0001
	search("ahishers"); // his: [1, 3], he: [4, 5], she: [3, 5], hers: [4, 7]
}