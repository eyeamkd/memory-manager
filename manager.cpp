// Base Class interface


class IMemoryManager{
    public:
    virtual bool Init(void *head, unsigned int bufferSize, unsigned int blockSize) = 0;
    virtual void* Alloc() = 0;
    virtual void Free() = 0;
    
    private: 
    int memory;

}; 

class MemoryManager : public IMemoryManager{ 
    private:
    int* memory;
    int freeMemory;
    int allocatedMemory;
    int* lastAllocatedAddress;  
    int* maxSize; 

    public: 
    unsigned int bufferSize;
    unsigned int blockSize; 
    int* current; 

    bool Init(void* head, unsigned int bufferSize, unsigned int blockSize){ 
        bufferSize = bufferSize;
        blockSize = blockSize; 
        freeMemory = bufferSize; 
        allocatedMemory = 0; 
        current = (int*)head;
        memory = new int(bufferSize); 
        maxSize = current + bufferSize;
    }; 
    void* Alloc(){   
        if(current!=maxSize){ 
            // current pointer type is void, hence in order to increment or decrement it 
            current += blockSize;  
            return current;
        }else{
            return nullptr;
        }
    };

    void Free(){ 
        //delete operator is used to free up memory
    };


};



