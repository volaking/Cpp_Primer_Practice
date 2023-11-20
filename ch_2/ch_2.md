# 第2章 变量和基本类型

## 2.3 复合类型

**2.19 说明指针和引用的主要区别**

引用即是别名，对引用的操作都相当于对所引用变量的操作；
引用初始化时就需要定义，且不能绑定到其他对象上去，引用本身不是一个对象，所以不能定义引用的引用，但是指针是一个对象，所以可以定义指针的引用；
引用必须指向一个对象，不能指向字面值；
引用符在等式左侧时，代表引用，在等式右侧时，代表取地址符。
不能为非常量引用绑定字面值，可以为常量引用绑定字面值   

指针本身代表一个地址，加上解引用符（*）表示这个地址的变量值；
指针存储的是内存地址，所以可以进行指针运算和指针算数操作。
底层const指针初始化是必须赋值

**2.20 请叙述下面这段代码的作用**

    int i = 42;
    int *p1 = &i;
    *p1 = *p1 * *p1

定义一个int型变量i = 42，定义一个int型指针*pi指向i，执行i = i * i

**2.21 请解释下属定义。这些定义中有非法的吗，为什么**

    int i = 0;

    double* dp = &i

合法。c++中double* dp = &i和double *dp = &i是一致的

    int *ip = i

不合法，指针在定义时必须指向一个地址，因此需要使用取地址符（&）

    int *p = &i

合法

**2.22 假设p是一个int型指针，请说明下述代码的含义**

    if (p)

指针是否指向空地址

    if(*p)

指针指向的值是否是空值

**2.23 给定指针p，你能知道他是否指向了一个合法的对象吗**

**2.24 下面这段代码中为什么p合法而lp非法**

    int i = 42;
    void *p = &i;
    long *lp = &i;

指针类型必须和所指类型一致，*lp是long型指针，void是通用类型指针，他可以接受任何形式的变量。

**2.25 说明下列变量的类型和值**

    int* ip, i, &r = i;

*ip是一个int型指针，i是一个int型变量，&r是一个指向i的引用

    int i, *ip = 0;

i是一个int型变量，*ip是一个指向0的引用

    int* ip, ip2;

ip是一个int型指针，ip2是一个int型变量

*\*是指针声明的一部分，没有int\*同时声明两个int指针的表示形式*

指向指针的引用

    int i = 42; // 定义一个整型变量i
    int *p; // 定义一个整型指针*p
    int *&r = p;    // 定义一个指向指针的引用&r，此时r相当于p的别名
    r = &i; // 指针p指向i
    *r = 0  // 将0赋给i

**2.26 下面哪些句子不合法，为什么**

    const int buf;
    
不合法，const类型变量必须在初始化时赋值

    int cnt = 0;

合法

    const int sz = cnt;

合法

    ++cnt; ++sz;

不和法，++sz，sz是一个const变量，不能更改const变量的值

## 2.4 const限定符

### 2.4.1 const的引用

非指向常量的引用不能指向常量；

不能通过常量引用修改所引用变量的值，但可以绕过指向常量的引用，直接对所引用的变量值进行修改。

    int i = 42;
    const int &ri = i;
    //ri = 10;
    i = 10;
    std::cout << ri << std::endl;
    return 0;

第三行是不合法的，因为ri是一个const引用，不能通过ri对所引用的变量进行修改，但可以通过第四行的形式，直接对所引用的值i进行修改，现在ri的返回值是修改后的i。

### 2.4.2 指针和const

指向常量的指针

类似与指向常量的引用，也可以使用 const *p = &i 定义一个指向常量的指针，它和指向常量的引用有相同的性质。

只能使用指向常量的指针指向一个const修饰的常量

不可以通过指向常量的指针修改所指向变量的值，指向常量的指针允许指向一个非常量变量，这时可以绕过指向常量的指针，直接修改变量的值

    const int i = 42;
    // int *ptr = &i;
    const int *cptr = &i;
    // *cptr = 10;

第二行是不合法的，因为*ptr是一个普通指针，他无法指向一个常量
第四行是不合法的，因为*cptr是一个常量指针，无法通过他修改他所指向的变量

与指向常量的引用不同的是，引用本身不能更换绑定的值，但指针可以，所以虽然不能通过指向常量的指针修改所指向的值，但是可以直接修改指针的指向

    int i = 42;
    int j = 24;
    const *ptr = &i;
    ptr = &j;

上面的代码定义了指向常量的指针*ptr指向i，不能通过*ptr修改i的值，但是可以修改*ptr的指向，让*ptr指向j


**2.27 下面哪些初始化是合法的**

    int i = -1, &r = 0;

不合法，引用必须指向一个对象，不可以直接指向字面值

    int *const p2 = &i2;

合法，定义了一个指向i2的常量指针

    const int i = -1, &r = 0;

合法，虽然引用不可以指向字面值，但字面值0会创建一个临时的int对象，表示&r指向一个值为0的int对象
    
    const int *const p3 = &i2;

合法，定义了一个指向常量的常量指针，指向i2

    const int *p1 = &i2;

合法，定义了一个指向常量的指针指向i2

    const int &const r2;

不合法，不可以使用&const引用

    const int i2 = i, &r = i;

合法，定义了一个int型常量i2的值等于i，定义了一个int型指向常量的引用&r

**2.28 说明下面这些定义什么意思，挑出其中不合法的**

    int i, *const cp;

合法，定义一个int型常量i，和一个int型常量指针*cp

    int *p1, *const p2;

不合法，定义了一个int型指针*p1，和一个int型常量指针p2

    const int ic, &r = ic;

不合法，定义了一个int型常量ic但没有给他初始值，和一个指向常量的引用&r指向ic

    const int *const p3;

不合法，定义了一个指向常量的常量指针*p3，因为不能修改常量指针的指向，所以必须在初始化常量指针的时候给他赋值

    const int *p;

合法，定义了一个指向常量的指针*p

2.29 假设一有上一个练习中定义的那些变量，则下面哪些语句是合法的

    i = ic;

合法
    
    p1 = p3;

合法

    p1 = &ic;

合法

    p3 = &ic;

不合法，p3是一个指向常量的常量指针，不能改变指针的指向

    p2 = p1;

不合法，p2是一个常量指针

    ic = *p3;

不合法，ic是一个int型常量

### 2.4.3 顶层const

顶层const：指针本身是个常量，可以应用于任何数据类型
底层const：指针指向一个常量，多应用于指针等符合类型

顶层const可以随意赋值和拷贝，但是底层const在复制时需要考虑，拷入的值是否有等同的底层const属性

**2.30 下面这些语句对象被声明成了顶层const还是底层const**

    const int v2 = 0;

顶层const

    int v1 = v2;

普通变量

    int *p1 = &v1, &r1 = v1;

普通指针和普通引用

    const int *p2 = &v2, *const p3 = &i, &r2 = v2;

顶层const和底层const

**2.31 哪些语句是合法的，顶层const和底层const在每个例子中的体现**

    r1 = v2;

    v2是一个常量，将v2的值赋给r1

    p1 = p2; p2 = p1;

    p1是一个指针，p2是一个指向常量的指针，两个指针交换地址

    p1 = p3; p2 = p3;

    p1 = p3不合法，因为p3是指向常量的常量指针，而p1没有底层const属性，不能接受拷贝
    p2 = p3合法，底层const可以互相拷贝

### 2.4.4 constexpr和常量表达式

常量表达式：值不会改变并且在编译过程中就可以得到计算结果的表达式

一个数据是常量表达式需要满足，两个条件，一这个数据是一个const数据类型，二这个数据的初始值是固定的值

constexpr类型，必须是一个常量而且用常量表达式进行初始化

constexpr在初始化指针时，仅对指针有效

    constexpr int *p = &j; // *p是一个常量指针
    constexpr const int *p = &j;    // *p是一个指向常量的常量指针

**2.32 下面代码是否合法，不合法请修改**

    int null = 0, *p = null;
不合法，因为null是空值关键字，不能使用null作为变量名

## 2.5 处理类型

### 2.5.1 类型别名

    typedef A B; // A类型别名为B
    Using B = A; // 使用B作为A的别名

指针、常量和类型别名

类型别名指代的是复合类型

    typedef char *pst;
    const pst cstr = 0; // ！= const char *cstr = 0, == char *const cstr = 0
    const pst *ps;

如果typedef中包含指针，那么指针就是数据类型的一部分，而不再属于声明符。比如typedef char *pst; const pst 会作用在整个pst中变成一个常量指针，而不是指向常量的指针。

### 2.5.2 auto类型说明符

auto让编译器自动推断变量的类型，所以需要变量具有初始值

auto也可以在一条数据中声明多个变量，但这要求这一行中的所有变量类型都相同

复合类型、常量和auto

当auto用于初始化一个引用的时候，auto参考的引用值的类型

    int i = 0, &r = i;
    auto a = r; // a是一个整数

auto一般会忽略顶层const，保留底层const

    const int ci = i, &cr = ci;
    auto b = ci;    // b是int类型，顶层const被auto忽略
    auto c = cr;    // c也是int类型，cr是ci的别名，auto参考ci进行判断类型
    auto d = &i;    // d是int型的指针，对int型变量取地址，即为指向该变量的指针
    auto e = &ci;   // e是指向常量的指针，对常量取地址，即为指向常量的指针

如果希望推断出的auto类型是一个顶层const类型，需要指定const

    const auto f = ci;

当设置一个类型为auto的引用时，顶层常量属性保留

**2.33 利用本节定义的变量，判断下列语句的运行结果**

    a = 42; b = 42; c = 42;
    d = 42; e = 42; g = 42;

a是整数合法；b是整数，合法；c也是整数常量，不合法；d是整型指针，不合法；e是指向常量的整型指针，不合法；g是整型常量，不合法。

**2.34 输出上一题赋值前后的变量内容**

**2.35 判断下列定义推断的类型是什么，然后编写程序进行验证**

    const int i = 42;
    auto j = i; cosnst auto &k = i; auto *p = &i;
    const auto j2 = i, &k2 = i;

i int, j int, k const int, p const int *p, j2 const int, k2 const &k2

### 2.5.3 decltype类型指示符

decltype用于希望使用一个表达式的类型，又不希望使用它的值进行初始化时

decltype与auto的区别，decltype包括const和引用符

如果decltype(())内部有括号，那么decltype返回的一定是引用类型

    const int i = 42, *p = &i, &r = i;
    decltype(r + 0) b;
    decltype(*p) c; // c是int&

**2.36 指出每一个变量的类型以及程序结束时他们各自的值**

    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;

c int, d int &d = a

**2.37 赋值会产生引用，int i, decltype(i = x)的类型是int&**

    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;

c int, d int&

## 2.6 自定义数据结构

### 2.6.1 定义Sales_data类型

    struct ClassName {};

### 2.6.2 使用Sales_data类

    #include "Sales_data.h"

### 2.6.3 编写自己的头文件

    #ifndef SALES_DATA_H
    #define SALES_DATA_H

    #include <string>

    struct Sales_data {};

    #endif

