template <class T>
class LinearList{
    public:
//        LinearList();                            // 构造函数
//        ~LinearList();                            // 析构函数
//        virtual int Size()const = 0;              // 求表的最大体积
        virtual int Length()const = 0;            // 求表长度
//        virtual int Search(T& x)const = 0;        // 求表中搜索给定值x
//        LinkNode<T> * Search(T x);
//        virtual int Locate(int i)const = 0;       // 求表中定位第i个元素位置
//        LinkNode<T> * Locate(int i);
//        virtual bool getData(int i, T& x) = 0;    // 取第i个表项的值
        virtual bool getData(int i,T& x)const=0;
        virtual void setData(int i, T& x) = 0;    // 修改第i个表项的值为x
        virtual bool Insert(int i, T& x) = 0;     // 在第i个表项后插入x
        virtual bool Remove(int i, T& x) = 0;     // 删除第i个表项，通过x返回
        virtual bool IsEmpty()const = 0;          // 判表空
        virtual bool IsFull()const = 0;           // 判表满
//        virtual void Sort() = 0;                  // 排序
        virtual void input(T endTag) = 0;                 // 输入
        virtual void output() = 0;                // 输出
//        virtual LinearList<T> operator = (LinearList<T>& L) = 0;   // 复制
};