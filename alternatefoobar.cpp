class FooBar {

private:
    int n;
    condition_variable cv;
    mutex mtx;
    bool isfooprinted;

public:
    FooBar(int n) {
        this->n = n;
        isfooprinted = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock <mutex> lock(mtx);
            cv.wait(lock, [this] { return !isfooprinted;});
        	printFoo();
            isfooprinted = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            unique_lock <mutex> lock(mtx);
            cv.wait(lock, [this] { return isfooprinted;});
        	printBar();
            isfooprinted = false;
            cv.notify_all();
        }
    }
};
