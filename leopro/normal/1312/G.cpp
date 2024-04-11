#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

struct node {
    map<char, node *> next_nodes;
    int time = 0;
    bool term = false;
    int sub_term_count = 0;

    node() = default;

    node *add(char c) {
        return next_nodes[c] = new node();
    }
};

int dfs(node *cur) {
    for (auto next : cur->next_nodes) cur->sub_term_count += dfs(next.second);
    return cur->sub_term_count += cur->term;
};

void dfs(node *cur, int length, int completion) {
    cur->time = min(length, (cur->term ? completion : (int)1e6) + 1);
    int prev = cur->term;
    for (auto next : cur->next_nodes) {
        dfs(next.second, cur->time + 1, min(completion, cur->time) + prev);
        prev += next.second->sub_term_count;
    }
};

void solve() {
    autoint n;
    vector<node *> words(1, new node());
    for (int i = 0; i < n; ++i) {
        autoint p;
        char c;
        cin >> c;
        words.emplace_back(words[p]->add(c));
    }
    autoint k;
    vector<int> a(k);
    cin >> a;
    for (int w : a) words[w]->term = true;
    dfs(words[0]);

    dfs(words[0], 0, 0);
    for (int w : a) cout << words[w]->time << ' ';
}