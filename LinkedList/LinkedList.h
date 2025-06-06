# include <iostream>
# include "linearList.h"
# include <stdlib.h>

using namespace std;

template <class T>
struct LinkNode{                                  // 链表结点类的定义
    T data;                                       // 数据域
    LinkNode<T> * next;                           // 链指针域
    LinkNode(LinkNode<T> * ptr = nullptr){next = ptr;}  // 仅初始化指针成员的构造函数    
    LinkNode(const T& item,LinkNode<T> *ptr=nullptr)
    {data = item; next = ptr;}                     // 初始化数据与指针成员的构造函数
};

template<class T>
class List : public LinearList<T>{                   // 当链表类定义，不用继承也可以实现
    public:
    List(){first = new LinkNode<T>;}               // 构造函数
    List(const T& x){first = new LinkNode<T>(x);}  // 构造函数
    List(List<T>& L);                              // 复制构造函数
    ~List(){makeEmpty();}                          // 析构函数
    void makeEmpty();                              // 将链表置为空表
    int Length()const;                             // 计算链表的长度
    LinkNode<T> * getHead()const {return first;}   // 返回附加头结点地址
    LinkNode<T> * Search(T x);                     // 搜索含数据x的元素
    LinkNode<T> * Locate(int i)const;                   // 搜索第i个元素的地址
    bool getData(int i,T& x)const;                 // 取出第i个元素的值
    void setData(int i,T& x);                      // 用x修改第i个元素的值
    bool Insert(int i,T& x);                        // 在第i个元素后插入x
    bool Remove(int i,T& x);                       // 删除第i个元素，x返回该元素的值
    bool IsEmpty()const                            // 判表空否？空则返回true
        {return first->next == NULL?true:false;}
    bool IsFull()const {return false;}             // 判表满否？不满则返回false
    //void Sort();                                   // 排序
    void input(T endTag);                                  // 输入
    void output();                                 // 输出
    List<T>& operator=(List<T>& L);                // 重载函数：赋值
    protected:
    LinkNode<T> *first;                            // 链表的头指针
};

template <class T>
List<T>::List(List<T>& L){
    // 复制构造函数
    T value;
    LinkNode<T> * srcptr = L.getHead();
    LinkNode<T> * destptr = first = new LinkNode<T>();
    while(srcptr->next != nullptr){
        value = srcptr->next->data;
        destptr->next = new LinkNode<T>(value);
        destptr = destptr->next;
        srcptr = srcptr->next;
    }
    destptr->next = nullptr;
};

template<class T>
void List<T>::makeEmpty(){
    // 将链表设置为空表
    LinkNode<T> *q;
    while(first->next != NULL){
        q = first ->next;
        first->next = q->next;
        delete q;
    }  //最后一次赋值将first置为nullptr
};

template<class T>
int List<T>::Length()const{
    // 计算带附加头结点的单链表的长度
    LinkNode<T> *p = first->next;
    int count = 0;
    while(p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
};

template<class T>
LinkNode<T> *List<T>::Search(T x){
    // 在表中搜索含数据x的结点，搜索成功时返回该节点地址；否则返回NULL值
    LinkNode<T> * current = first->next;
    while(current != NULL)
        if(current->data == x) break;
        else current = current->next;
    return current;
};

template<class T>
LinkNode<T> * List<T>::Locate(int i)const{
// 定位函数。返回表中第i个元素的地址。若i<0或i超出表中结点个数，则返回NULL
    if(i < 0) return NULL;
    LinkNode<T> * current = first; 
    int k = 0;
    while(current != NULL && k < i) {
        current = current->next;
        k++;
    } //如果超过则会为空出循环 
    return current;
};

template<class T>
bool List<T>::getData(int i, T& x)const {
// 取出表中第i个元素的值
    if(i<=0) return NULL;
    LinkNode<T> *current = Locate(i);
    if(current == NULL) return false;
    else{ 
        x = current->data;
        return true;
    }
};

template<class T>
void List<T>::setData(int i, T& x){
// 给链表中第i个元素赋值x
    if(i<=0)return;
    LinkNode<T> * current = Locate(i);
    if(current == NULL) return;
    else current ->data = x;
};

template<class T>
bool List<T>::Insert(int i,T& x){
// 将新元素x插入在链表中第i个结点之后
    LinkNode<T> *current = Locate(i);
    if(current == NULL) return false;
    LinkNode<T> * newNode = new LinkNode<T>(x);
    if(newNode == NULL){ 
        cerr<<"存储分配错误"<<endl;
        exit(1);
    }
    newNode->next = current->next;
    current->next = newNode;
    return true;
};

template<class T>
bool List<T>::Remove(int i,T& x){
// 将链表中第i个元素删去，通过引用型参数x返回该元素的值
    LinkNode<T> * current = Locate(i-1);
    if(current == NULL || current->next == NULL) return false;
    LinkNode<T> *del = current->next;
    current->next = del->next;
    x = del->data;
    delete del;
    return true;
};

template<class T>
void List<T>::output(){
// 单链表的输出函数：将单链表中所有数据按逻辑顺序输出到屏幕上
    LinkNode<T> *current = first->next;
    int k = 1;
    while(current != NULL){
        cout << "第" << k << "个元素：" << current->data << endl;
        current = current->next;
        k++;
    }
};

template<class T>
void List<T>::input(T endTag){
// 尾插法插法建立单链表
    LinkNode<T> *newNode,*last;
    T val;
    makeEmpty();
    cin >> val;
    last = first;
    while(val != endTag){              // last指向表尾
        newNode = new LinkNode<T>(val);
        if(newNode == NULL){cerr<<"存储分配错误！"<<endl;exit(1);}
        last->next = newNode;
        last = newNode;
        cin >> val;                   // 插入到表末端
    }
    last->next = NULL;               // 表收尾，这一句实际可省略
}
template<class T>
List<T>& List<T>::operator=(List<T>& L){
// 重载函数：赋值操作，形式如A=B，其中A是调用此操作的对象，B是与参数表中的
// 引用型参数L结合的实参
    T value;
    LinkNode<T> * srcptr = L.getHead();
    LinkNode<T> * destptr = first = new LinkNode<T>;
    while(srcptr->link!=NULL){
        value = srcptr->next->data;
        destptr->next = new LinkNode<T>(value);
        destptr = destptr->next;
        srcptr = srcptr->next;
    }
    destptr->next = NULL;
    return * this;
};