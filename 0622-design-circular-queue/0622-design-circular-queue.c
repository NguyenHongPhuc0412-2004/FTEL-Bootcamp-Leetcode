
typedef struct {
    int *arr;
    int head;     // rear
    int tail;     // front
    int count;
    int capacity;
} MyCircularQueue;

// PROTOTYPE
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->arr = (int*)malloc(sizeof(int) * k);
    cq->head = -1;
    cq->tail = 0;
    cq->capacity = k;
    cq->count = 0;
    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)) return false;

    obj->head = (obj->head + 1) % obj->capacity;
    obj->arr[obj->head] = value;
    obj->count++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return false;

    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->count--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->tail];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->head];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->count == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->count == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}