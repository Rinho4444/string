struct Trie{
    struct node{
        node* left;
        node* right;
        int cnt;
        int exist;

        node(){
            left = right = NULL;
            cnt = 0;
            exist = 0;
        }
    };

    node* root = new node();

    void insert(int num){
        node* p = root;
        for(int i = 31; i >= 0; i--){
            int id = (num >> i) & 1;

            if(id){
                if (p->right == NULL)
                    p->right = new node();
                p = p->right;
            } else{
                if (p->left == NULL)
                    p->left = new node();
                p = p->left;
            }
            p->cnt++;
        }
        p->exist++;
    }

    bool findnum(int num){
        node* p = root;
        for(int i = 31; i >= 0; i--){
            int id = (num >> i) & 1;

            if(id){
                if (p->right == NULL) return 0;
                p = p->right;
            } else{
                if (p->left == NULL) return 0;
                p = p->left;
            }
        }
        return p->exist > 0;
    }

    void erase(int num){
        node* p = root;
        for(int i = 31 ; i >= 0 ; i--){
            int id = (num >> i) & 1;

            if(id) p = p->right;
            else p = p->left;

            p->cnt--;
        }
        p->exist--;
    }
} trie;
