struct Trie{
    struct node {
        node* child[26];
        int exist, cnt;
        node() {
            for (int i = 0; i < 26; i++) 
                child[i] = NULL;
            exist = 0;
            cnt = 0;
        }
    };

    node* root = new node();

    void insert(const string &s) {
        node* p = root;
        for(auto chr : s) {
            int nxt = chr -'a';
            if (p->child[nxt] == NULL)
                p->child[nxt] = new node();
            p = p->child[nxt];
            p->cnt++;
        }
        p->exist++;
    }

    bool findstring(const string &s){
        node* p = root;
        for(auto chr : s) {
            int nxt = chr -'a';
            if (p->child[nxt] == NULL) return 0;
            p = p->child[nxt];
        }
        return p->exist > 0;
    }

    bool redel(node* p, const string &s, int i) {
        if (i != (int)s.size()) {
            int c = s[i] - 'a';
            bool checkdel = redel(p->child[c], s, i + 1);
            if (checkdel) p->child[c] = NULL;
        }
        else p->exist--;

        if (p != root) {
            p->cnt--;
            if (p->cnt == 0) {
                delete(p);
                return 1;
            }
        }
        return 0;
    }

    void erase(const string &s) {
        if (findstring(s) == 0) return;
        redel(root, s, 0);
    }
};
Trie trie;
