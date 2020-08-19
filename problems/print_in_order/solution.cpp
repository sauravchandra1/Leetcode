class Foo {
    private:
    condition_variable cv;
    int i;
    mutex mut;
    public:
    Foo(): i(1) {}
    void first(function < void() > printFirst) {
        unique_lock < mutex > lk(mut);
        cv.wait(lk, [this]() -> bool {
            return this -> i == 1;
        });
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        i++;
        cv.notify_all();
    }

    void second(function < void() > printSecond) {
        unique_lock < mutex > lk(mut);
        cv.wait(lk, [this]() -> bool {
            return this -> i == 2;
        });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        i++;
        cv.notify_all();
    }

    void third(function < void() > printThird) {
        unique_lock < mutex > lk(mut);
        cv.wait(lk, [this]() -> bool {
            return this -> i == 3;
        });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        i++;
        cv.notify_all();
    }
};