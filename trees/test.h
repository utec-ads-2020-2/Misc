#ifndef QUEUE_H
#define QUEUE_H

#include <list>

using namespace std;

#define DEFAULT 100

template <typename T>
class queue {
private:
    list<T> queueP;
public:
   queue(int size = DEFAULT) {

   }
   ~queue() {}
   void push(T push){ //Adds an element
        queueP.push_back(push);
   };
   void pop(T pop){  //removes an element
       if(queueP.size()!=0){queueP.pop_front();}
   };
   T front(){ //returns the front element
        if(queueP.size()!=0){return queueP.front();}
   };
    T back(){  //returns the back element
        if(queueP.size()!=0){return queueP.back();}
    };
   int size(){ //returns the size
       return queueP.size();
   };
   bool empty(){ //returns if the list is empy or not
        return queueP.empty();
   };
};
#endif