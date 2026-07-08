class BSTNode{
private:
    int key;
    BSTNode* left; BSTNode* right;

public:
    BSTNode(int v) : key(v), left(nullptr), right(nullptr){}
    int getKey(){return this->key;}

    void setKey(int v) {this->key = v;}
    BSTNode* getLeft() {return this->left;}
    void setLeft(BSTNode* l) {this->left = l;}
    BSTNode* getRight() {return this->right;}
    void setRight(BSTNode* r) {this->right = r;}

};

class BST{
private:
    BSTNode* root;
    int count;

    BSTNode* insert(BSTNode* rt, int k){ //TODO
        if(rt == nullptr){
            return new BSTNode(k);
        }
        if(k < rt->getKey()){
            rt->setLeft(insert(rt->getLeft(), k));
        }
        else{
            rt->setRight(insert(rt->getRight(), k));
        }
        return rt;
    };

    bool find(BSTNode* rt, int k){
        BSTNode* rt = root;

        while(rt != nullptr && rt->getKey()){
            if(k < rt->getKey()){
                rt = rt->getLeft();
            }
            else{
                rt = rt->getRight();
            }
        }
        return rt;
    } //TODO

    void clear(BSTNode* rt){
        if(rt != nullptr){
            this->clear(rt->getLeft());
            this->clear(rt->getRight());
            delete rt;
        }
    }

public:
    BST() : root(nullptr), count(0){}
    ~BST() {this->clear();}

    void insert(int k){
        root = insert(root, k);
        count++;
    } //TODO
    bool find(int k){
        return find(root, k);
    } //TODO

    void clear(){
        this->clear(this->root);
    }
};