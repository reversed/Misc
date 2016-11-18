using namespace std;

class Lock
{
public:
    Lock() { /* placeholder code to create the lock */ }
    ~Lock() { /* placeholder code to deallocate the lock */ }
    void AcquireLock() { /* placeholder to acquire the lock */ }
    void ReleaseLock() { /* placeholder to release the lock */ }
};

template <class T> class Singleton
{
private:
    static Lock lock;
    static T* object;
protected:
    Singleton() { }
public:
    static T* instance();
};

template <class T>
Lock Singleton<T>::lock;

template <class T>
T* Singleton<T>::object = 0;

template <class T>
T* Singleton<T>::instance()
{
    /* if object is not initialized, acquire lock */
    if (object == 0)
    {
        lock.AcquireLock();
        /* 
        ** If two threads simultaneously check and pass the first "if"
        ** condition, then only the one who acquired the lock first
        ** should create the instance
        */
        if (object == 0)
        {
            object = new T;
        }
        lock.ReleaseLock();
    }
    return object;
}

class Foo
{
    // to be defined
};

int main()
{
    Foo* singleton_foo = Singleton<Foo>::instance();
    return 0;
}






