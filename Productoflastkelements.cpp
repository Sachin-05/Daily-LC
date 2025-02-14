class ProductOfNumbers {
private:
    vector <int> prefixprod;
public:
    ProductOfNumbers() {
       prefixprod = {1}; //intialsie the prefix prod vector here
    }
    
    void add(int num) {
        if(num == 0){
            //then again reset the prefix prod array to 1
            prefixprod.clear();
            prefixprod.push_back(1);
        }else{
            prefixprod.push_back(prefixprod.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixprod.size(); // and this should always be in increment of 1
        if(k >= n ){
            return 0;
        }
        return prefixprod[n-1] / prefixprod[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
