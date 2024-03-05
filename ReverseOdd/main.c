#include <stdio.h>
#include <stdlib.h>
typedef struct{
   int*items;
   int front,rear,capacity,nofelement;
}queue;

typedef struct
{
    int items[20];
    int top;
}Stack;

Stack* initialize()
{
    Stack*s=malloc(sizeof(Stack));
    s->top=0;
    return s;
}

void push(Stack*s,int x)
{
    s->items[s->top]=x;
    s->top++;

}

int pop(Stack*s)
{
 s->top--;
 return s->items[s->top];

}


void displaystack(Stack*s)
{
    Stack*temp=initialize();
    while(!isEmptystack(s))
    {
        int x=pop(s);
      printf("%d ",x);
      push(temp,x);
    }
    while(!isEmptystack(temp))
    {
        push(s,pop(temp));
    }

}

int isEmptystack(Stack*s)
{

    return s->top==0;
}

int isFullstack(Stack*s)
{
    if(s->top==20)
        return 1;
    else
        return 0;

}







queue*init(int n){
 queue*q=malloc(sizeof(queue));
 q->items=malloc(n*sizeof(int));
 q->front=q->rear=0;
 q->capacity=n;
 q->nofelement=0;
 return q;
}
int isfull(queue*q){
return q->nofelement==q->capacity;
}

int isempty(queue*q){
return q->nofelement==0;
}

void enqueue(queue *q,int x){
   if(!isfull(q)){
      q->items[q->rear]=x;
      q->rear=(q->rear+1)%(q->capacity);
      q->nofelement++;}

   }

   int getFront(queue *q)
{
    if (!isempty(q))
        return q->items[q->front];
    else
    {
        printf("Queue is Empty\n");
        exit(1);
    }
}

  int getRear(queue *q)
{
    if (!isempty(q))
        return q->items[q->rear-1];
    else
    {
        printf("Queue is Empty\n");
        exit(1);
    }
}

int dequeue(queue*q){

 if(!isempty(q)){
    int x=q->items[q->front];
    q->front=(q->front+1)%q->capacity;
    q->nofelement--;
    return x;

 }

}

int maximum(queue*q){
    int count=q->nofelement;
queue*copy=init(count);
int max=dequeue(q);

  enqueue(copy,max);

while(!isempty(q)){
    int x=dequeue(q);
    if(x>max)
        max=x;
    enqueue(copy,x);
    }
    while(!isempty(copy)){
        enqueue(q,dequeue(copy));
    }
    return max;

}

void swaphead_tail(queue*q){

  int copy=getFront(q);
  dequeue(q);
  queue*tmp=init(q->nofelement);
  while(q->nofelement!=1){
    enqueue(tmp,dequeue(q));
  }
   int copy2=dequeue(q);
   enqueue(q,copy2);
   while(!isempty(tmp))
    enqueue(q,dequeue(tmp));

   enqueue(q,copy);

}


void display (queue *q)
{
    queue *temp = init(20);
    while (!isempty(q))
    {
        int x = dequeue(q);
        printf("%d ", x);
        enqueue(temp, x);
    }
    while (!isempty(temp))
        enqueue(q, dequeue(temp));
    printf("\n");
}

void reverseee(queue*q,int k){
int i;
Stack*s=initialize();
queue*temp=init(20);
for(i=0;i<k;i++){
    push(s,dequeue(q));


}
while(!isempty(q)){
    enqueue(temp,dequeue(q));
}
while(!isEmptystack(s)){
    enqueue(q,pop(s));
}
while(!isempty(temp)){
    enqueue(q,dequeue(temp));
}

display(q);
}

void specificindex(queue*q,int index,int value){

queue*org=init(20);
queue*sec=init(20);
int i;
  if(index>q->nofelement){
    printf("Can not insert in this position\n");
    return;
  }

for(i=0;i<index-1;i++){
    enqueue(org,dequeue(q));

}
while(!isempty(q)){
    enqueue(sec,dequeue(q));
}
enqueue(org,value);

while(!isempty(sec)){
    enqueue(org,dequeue(sec));
}
while(!isempty(org)){

    enqueue(q,dequeue(org));
}
display(q);

}


queue *reverseodd(queue*q){

Stack*s=initialize();
 queue*tmp=init(20);
 queue*finall=init(20);
 while(!isempty(q)){
        int x=dequeue(q);
    if(x%2!=0){
        push(s,x);}
        enqueue(tmp,x);
}


 while(!isempty(tmp)){
    int y=dequeue(tmp);
    if(y%2!=0){
        enqueue(finall,pop(s));

    }
    else{
        enqueue(finall,y);
    }

 }
  return finall;



}




int main()
{ queue *q = init(20);
    enqueue(q, 14);
    enqueue(q, 13);
    enqueue(q, 17);
    enqueue(q, 8);
    enqueue(q, 4);
    enqueue(q, 15);
    enqueue(q, 18);
    enqueue(q, 19);
    printf("The origin queue is\n");
    display(q);

    int max=maximum(q);
    printf("The maximum value is %d\n\n",max);

    printf("The value of front =  %d ,the value of rear =  %d\n",getFront(q),getRear(q));
    swaphead_tail(q);
    printf("After swaping the value of the front = %d and the value of rear = %d\n\n",getFront(q),getRear(q));


    int index,element;


    printf("The index u want to insert in\n");
    scanf("%d",&index);
    printf("Enter ur value\n");
    scanf("%d",&element);
    specificindex(q,index,element);
    queue*xx=reverseodd(q);
    printf("The queue After the reverse ODD is\n");
    display(xx);

     int x;
     printf("the elements u want to reverse after the index of\n");
     scanf("%d",&x);
     reverseee(xx,x);
    return 0;
}
