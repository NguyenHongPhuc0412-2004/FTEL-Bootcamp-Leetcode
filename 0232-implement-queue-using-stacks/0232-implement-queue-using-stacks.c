typedef struct {
    int *stack1;//dùng để nhận dữ liệu mới
    int top1;

    int *stack2;//luu tạm ,dùng lấy dữ liệu ra
    int top2;
    int cap;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->cap = 100;

    queue->stack1 = (int*)malloc(queue->cap * (sizeof(int)));
    queue->stack2 = (int*)malloc(queue->cap * (sizeof(int)));

    queue->top1 = -1;     
    queue->top2 = -1; 
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++(obj->top1)] = x;
}
void move(MyQueue* obj) {
    if (obj->top2 == -1) { // Chỉ chuyển khi stack2 rỗng
        while (obj->top1 != -1) {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    move(obj);
    return obj->stack2[(obj->top2)--];
}

int myQueuePeek(MyQueue* obj) {
    move(obj);
    return obj->stack2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/