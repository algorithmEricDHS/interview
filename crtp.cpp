#include <iostream>
#include <vector>
#include <string>
template <class CRTP>
struct AllocationTracker
{
    AllocationTracker()
    {
        ++totalCreated;
    }

    void* operator new(size_t sz)
    {
        ++heapCreated;
        return ::operator new(sz);
    }
    bool isInList()
    {
    	string s = (string)this;
    	for(int i=0; i<heapList.size(); i++) {
    		if (s == heapList.at(i)) return true;
    	}
    	return false;
    }
    static int totalCreated;
    static int heapCreated;
    std::vector<string> HeapList; 
};

template <class CRTP>
int AllocationTracker<CRTP>::totalCreated;
template <class CRTP>
int AllocationTracker<CRTP>::heapCreated;
template <class CRTP>
vector<string> AllocationTracker<CRTP>::heapList;

class Derived : public AllocationTracker<Derived>
{
};

int main()
{
    using namespace std;
    cout << Derived::heapCreated << "/" << Derived::totalCreated << endl; // 0/0
    Derived dStack;
    cout << Derived::heapCreated << "/" << Derived::totalCreated << endl; // 0/1
    Derived* dHeap = new Derived;
    cout << Derived::heapCreated << "/" << Derived::totalCreated << endl; // 1/2
}
