# 变量和基本类型

c++中基本的算术类型分为整形和浮点型，他们的尺寸不一（size=尺寸=”单体“字节数；length=长度=容器中元素个数)。

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled.png)

类型转换：类型所表示的值的范围决定转换的过程

- 非布尔值赋给布尔类型时，初始值为0则结果false，否则为true。
- 布尔值赋给非布尔类型，初始false为0，初始true为1。
- 赋给无符号类型一个超范围的值。结果为初始值对无符号类型表示数值总数取模后的余数。例如，把-1赋值给8比特大小的unsigned char（0至255区间的值）所得结果为255。

字符和字符串字面值（单引号为一个char型字面值，双引号为字符串型字面值）。字符串字面值实际是由常量字符构成的数组，编译器在字符串结尾添加空字符（'\0'），字符串字面值实际长度比内容多1。

转义序列

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%201.png)



```
💡 什么是对象：通常情况下，对象是指一块能存储数据并具有某种类型的内存空间，并不区分其为类还是内置类型，也不区分是否命名或是否只读。
```



### 引用与指针

引用通过&d定义引用类型（引用即别名），引用类型与绑定对象严格匹配。

指针实现对其它对象的间接访问，其本身就是一个对象，可以赋值与拷贝，指针存放着所指对象的地址，可利用解引用符（*）通过指针访问对象，可利用nullptr来初始化空指针。

定义指向指针的引用

```cpp
int i=42;
int *p;    //p是一个int型指针
int *&r=p; //r是一个对指针p的应用

r=&i;      //r引用一个指针，即令p指向i
*r=0;      //解引用r得到i，即p指向的对象i的值改为0
```

需要理解相关指针或变量的类型，**可以从右向左阅读r的定义，其中离变量名最近的符号对变量的类型有最直接的影响。**

### 限定符const相关

当引用被绑定到const对象上，称之为对**常量的引用**，对常量的引用不能用作修改它绑定的对象。

区分 指向常量的指针 和 指针常量（不变的是指针本身的值）

```cpp
const double pi=3.14;
const double *cptr=&pi;      //cptr是指向常量的指针

int num=0;
int *const cur=&num;         //指针cur一直指向num

const double pi=3.14;
const double *const pip=&pi; //pip是一个指向常量对象的常量指针

//通过从右向左阅读确定声明的基本类型
```

用**顶层const**表示指针本身是一个常量，用**底层const**表示指针所指对象是一个常量。

不能用一个字面值去初始化一个非常量引用（int &r = 42  //错误）。

### 类型别名

使用传统关键字 typedef 定义类型别名

使用别名声明定义类型别名

```cpp
typedef double wages;   //wages是double的同义词
typedef wages base, *p; //base是double的同义词，p是double* 的同义词

using SI = Sales_item;   //别名声明
```

# 字符串，变量和数组

### 标准库类型string

用等号初始化一个变量，实际上执行的是拷贝初始化；如果不是用等号，则执行的是直接初始化

```cpp
string s = "hiya";//拷贝初始化
string s1("hiya");//直接初始化
string s2(10,'c');//直接初始化
```

通过>>运算符将标准输入读取到string对象中，string对象会自动忽略开头的空白，从第一个字符开始直至下一处空白。

使用getline函数（参数是一个输入和一个string对象）代替>>运算符，读到一整行直至换行符（读取换行符但不存入string对象）。

当string对象和字符字面值及字符串字面值相加，需要确保加号（+）的两侧至少有一个string对象。

```cpp
string s7="hello" + "," + s2;//错误，字面值不能直接相加(加括号也不行)

**//究其原因，字符串字面值与string是不同类型的**
```

使用基于范围的for语句

```cpp
for (declaration : expression)
     statement                //语法形式

string s("Hello World");
for(auto &c : s)
	c = toupper(c);            //将字母大写
cout<< a <<endl;             //利用for语句和引用改变字符串中字符

```

要想访问string对象中单个字符有两种方式：**使用下标**和**使用迭代器。**

下标运算符（[ ]）的接收参数是string::size_type类型的值

```
💡 string对象的下标必须大于0而小于s.size( )，为确保下标不会小于0，设下标的类型为string::size_type，因为此类型是无符号数
```



### 标准库类型vector

标准库类型vector表示对象的集合。

列表初始化vector对象时，如果提供的是初始元素值的列表，则只能把初始值都放入花括号，而不是圆括号。

创建指定数量的元素：

```cpp
vector <int> ivec(10,-1);
vector <string> svec(10,"hi!");

//区分圆括号与花括号
vector <int> ivec(10);  //10个0元素
vector <int> ivec{10};  //一个值为10的元素
```

向vector对象中添加元素：push_back（将一个值当成vector对象的尾元素压到vector对象的尾端）

```cpp
string word;
vector<string> text;
while(cin>>word){
	text.push_back(word);
}
```



```
💡 vector对象（以及string对象）的下标运算符用于访问已存在的元素，而不能用于添加元素。
```



### 迭代器

所有的标准库容器都可以使用迭代器。

迭代器中end指向的是容器“尾元素的下一个位置”，若容器为空，则begin与end返回的是同一迭代器。

使用 * 返回迭代器的解引用，即返回其所指元素。

为便于得到const_iterator类型的返回值，引入cbegin和cend（只读不写）。

`(*it) . empty ()`   其中的括号不可少，先解引用再点运算。引入了箭头运算符（- >）把引用和成员访问结合，即 `it- >men=(*it) . mem` 。

两迭代器相减（iter1 - iter2）的结果是它们之间的距离

```cpp
//迭代器进行二分搜索
auto beg = text.begin(), end = text.end();
auto mid = text.begin() + (end - beg)/2;

while(mid != end && *mid !=sought){
	if(sought < *mid)
		end = mid;
	else
		beg = mid + 1;
	mid = beg + (end - beg)/2;
}
```

### 数组

```
💡 如果不清楚元素的具体个数，使用vector
```

与vector和string一样，当需要遍历数组所有元素时，最好的方法就是使用**范围for语句。**

利用数组名称初始化数组指针时，指向数组第一个元素。

```cpp
string nums[]={"one", "two", "three"}

string *p = &nums[0];
string *p2 = nums   //和上一句等价

auto ia(nums);      //ia是一个string指针，指向nums的第一个元素
++ia；              //ia指向nums[1]
```

数组中含有begin和end同名函数，将数组作为他们的参数使用。

```cpp
int ia[] = {0,1,2,3,4,5};
int *beg = begin(ia);
int *last = end(ia);
```

### 多维数组

```
💡 多维数据本质是数组的数组
```

使用范围for语句处理多维数组

```cpp
size_t cnt = 0;
for(auto &row : ia)
	for(auto &col : row){
		col = cnt;
		++cnt;
}

for(const auto &row : ia)
	for(auto col : row)
		cout << col <<endl;
//后一个循环没有写操作，为了避免数组被转换为指针，将外层循环的控制变量写成引用
```

# 表达式

c++中除非有要求，一般都使用递增的前置版本（将运算对象加一，然后将改变后的对象作为求值结果）。

## 条件运算符

在输出表达式中使用时，由于条件运算符的优先级非常低，当嵌套条件运算子表达式时，通常需要在两端加上括号。

sizeof 运算符返回一条表达式或一个类型名字所占的字节数

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%202.png)

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%203.png)

# 语句

### 条件语句

if 语句中 **悬垂 else 问题**：规定在嵌套 if 语句中，else 与离他最近的尚未匹配的 if 相匹配。

switch语句中，如果表达式与某个 case 标签匹配，程序从该标签后第一条语句开始执行，直至 switch 结尾或遇到 break  语句（简而言之，**记得加 break**）。

如果需要为某个 case 分支中定义并初始化一个变量，应该把变量定义在块内，以确保后边 case 标签在作用域外。

### 迭代语句

do while 语句应在条件括号的后面用一个分号结束。

### 跳转语句

break 负责终止离它最近的 while ，do while，for 或 switch 语句。

# 函数

### 函数基础

在函数中定义的局部静态对象（将局部变量定义为static类型），在初始化之后，直至程序结束才被销毁（例：可用于计算函数执行次数）。

函数声明与定义类似，但声明不需要函数体，用一个分号代替即可。

分离式编译

### 参数传递

当面对大的类型的类对象时，拷贝操作难以实现，通过形参访问该对象。

```
💡 如果函数无须改变引用形参的值，将其声名为常量引用。
```

- 传值（形）参数与传引用（形）参数的区别：
  
    传值方式下，形参与实参是两个相互独立的变量，在函数内对于形参的改变不会影响实参的值；
    
    传引用方式下，形参对应实参的别名（互相绑定），对形参的改变实质是对实参的改变。
    

**const 实参与形参（p.191）：**

```cpp
void fcn(const int i) //fcn能够读取i，但不能向i写值
```

C++中可以定义若干相同名字的函数，但不同函数的形参列表应当有所区别。

把函数不会改变的形参应该尽量定义为常量引用，因为这样可能误导使用者认为该程序允许修改变量的值，而且通常的const对象、字面值或者需要类型转换的对象不能传给普通的引用形参。

```
💡 C++ 中常见的几种输入字符串的方法：
```

[cin、cin.get()、cin.getline()、getline()、gets()、getchar()](https://www.runoob.com/note/50168)

数组有两个特殊性质：不允许拷贝数组，使用数组（通常）会转换为指针。所以无法以值的形式传递数组参数，为函数传递数组时实质是传递数组首元素的指针。

```
💡 以数组为形参的函数必须保证使用数组是不会越界（任何时候使用数组都需要注意）。
```



- 在传递数组参数时，有三种技术用于管理指针形参
    1. 不控制指针的边界，数组本身含有结束标志，适用于有明显结束标记的数组，但对于int等类型取值宽泛的不太合适。
       
        ```cpp
        void print(const char *cp)
        {
        	if(cp)
        		while(*cp)
        			cout << *cp++;
        }
        ```
        
    2. 使用begin和end函数限定数组边界，使用类似标准库规范的方法传递数组的首尾指针。
       
        ```cpp
        void print(const int *beg, const int *end)
        {
        	while(beg != end)
        		cout << *beg++ << endl;
        }
        ```
        
    3. 指定数组的维度，专门定义一个表示数组大小的形参。
       
        ```cpp
        void print(const int ia[], size_t size)
        {
        	for(size_t i = 0; i != size; ++i)
        		cout << ia[i] << endl;
        }
        //该方法限定输入的数组维度，如果传入维度与期望值不一样，可能导致出现差错，不至于是错误。
        ```
        

形参可以定义为数组的引用，此时的形参不仅绑定到对应的实参上，也是数组上。

```
💡 数组的引用两端括号不可少。
f ( int   &arr[10] )       //错误：将arr声明为引用的数组

f ( int   (&arr)[10] )     //正确：arr是具有10个整数的整形数组的引用。
```



main函数处理命令行：

```cpp
int main(int argc, char *argv[]){......}
int main(int argc, char **argv){......}
//第二个形参argv是一个数组，第一个形参argc表示数组中字符串数量。
```

可变形参initializer_list：（和 vector 一样属于模板类型，需要说明元素类型；和vector不一样， initializater_list 中元素都是**常量值（不可改变）**）

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%204.png)

当initializer_list 对象是类类型或容器类型（比如string）时，在范围 for 循环中使用，有必要将控制变量声明为引用类型。其他情况不需要。

### 返回类型和 return 语句

函数完成后，其所占用的空间和内存立即被释放，因此在函数中返回局部变量的引用将无法指向有效的内存区域。

```cpp
const string &manip()
{
	string ret;
	if( !ret.empty())
		return ret;        //错误：返回的是局部对象的引用
	else
		return "Empty";    //错误："Empty"也是一个局部临时量
```

同上，返回临时变量的指针也是错误的。

引用的返回为左值，也即可以将该函数的返回放在等号左边，来为其赋值。

```cpp
int& get(int* arry, int index)
{
	return arry[index];   //返回引用
}

int main(int argc, char** argv)
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
	{
		get(ia, i) = i;   //为返回的引用赋值
	}
```



💡 **递归**：一个函数调用了自身，无论这种调用是直接的还是间接的，都被称为递归。



编写递归函数的关键是确认递归规律和递归终止条件。

通过**使用类型别名**，可以轻松实现返回数组的指针或引用的函数。P.205（还有使用尾置返回类型和使用 decltype ）

```cpp
typedef int arrT[10];    //arrT是类型别名，表示含有10个整数的数组
using arrT = int[10];    //与上一条等价
arrT* func(int i);       //func返回一个指向含有10个整数的数组的指针

//如果不使用类型别名，需要牢记名字后面数组维度
int arrT[10];             //arr是一个含有10个整数的数组
int (*p2)[10] = &arrT;    //p2是一个指针，指向含有10个整数的数组

//返回数组指针的函数形式：Type (*function(parameter_list)) [dimention]
//例子：
int (*func(int i)) [10];
//对func函数解引用的调用是一个大小为10的数组，且数组中元素是int类型
```

### 函数重载

（同一个作用域中几个函数的名字相同但形参列表不同，编译器可以根据传递的实参判断想要使用的函数。）

C++规定重载函数必须在形参数量或形参类型上有所区别，与返回类型关系不大。

### 函数中的一些特殊语言

使用默认实参调用函数时，如果想使用默认实参，调用函数时直接忽略实参即可。如果自行设置实参，但传入的实参类型与定义不相符合，编译器会自行进行类型转换，默认的实参会放在传入的实参之后。

```
💡 通常，应该在函数声明中指定默认实参，并将声明放在合适的头文件中。
```

使用**内联函数**（将该函数在每个调用点上“内联地”展开），有效减少调用函数时的开销。

在函数返回类型前加上 inline 关键字，可以声明内联函数。

```
💡 在类中需要inline函数，首先在类中正常声明函数，然后在类外部使用inline关键字定义函数
```

### 函数指针

函数指针指向某种特定的函数类型，函数类型它的返回类型和形参类型共同决定。

```cpp
bool LengthCompare(const string &, const string &);
//要声明一个指向该函数的指针，用指针替换函数名
bool (*pf)(const string &, const string &);  //如果缺少括号，则pf是一个返回值为bool指针的函数
```

# 类

类的基本思想是数据抽象和封装。

数据抽象是依赖于接口和实现的分离编程技术。

类的接口包括用户能执行的各种操作；类的实现包括类的数据成员、负责接口实现的函数体以及定义类所需的各种私有函数。

### 定义抽象数据类型

将const 关键字放在成员函数的参数列表之后，表示该参数是指向常量的，这样使用const的成员函数被称为常量成员函数。

```
💡 常量对象，以及常量对象的引用和指针都只能调用常量成员函数。
```

**构造函数**：类通过构造函数来控制其对象的初始化过程，构造函数的任务是初始化类对象的数据成员。

当类没有声明任何构造函数时，编译器自动生成默认构造函数。

在C++11新标准中，如果需要默认行为，可以在参数列表后面写上 **=default** 来要求编译器生成构造函数。=default 既可以和声明一起出现在类的内部，也可以作为定义出现在类的外部。如果 =default 出现在类的内部，则默认构造函数是内联函数；如果在类的外部，该成员在默认情况下不是内联的。

```cpp
class Sales_data {
public:
	//定义默认构造函数，与只接受一个string实参的构造函数功能相同
	Sales_data(std::string s = "") : bookNo(s) { }
	//常规构造函数
	Sales_data(std::string s, unsigned cnt, double rev) :bookNo(s), units_sold(cnt), revenue(rev* cnt) { }

	Sales_data(std::istream& is) { read(is, &this); }
};
```

### 访问控制与封装

**访问说明符**加强类的封装性：public说明的成员可被整个程序访问，public成员定义类的接口；private说明的成员只能被类的成员函数访问。

使用class和struct定义类的唯一区别就是默认的访问权限：使用struct关键字，定义在第一个访问符之前的成员时public的；使用class关键字，则是private的。

一个类如果需要允许其它类或函数访问它的非公有成员，方法是令其它类或函数成为它的友元（通过在类内的函数声明前面加一个 friend 关键字）。

### 类的其他特性

在类中提供构造函数后，如果需要默认的构造函数，则使用 =default 告诉编译器。

**可变数据成员（mutable）：**在变量的声明中加入mutable关键字，即使是在const函数中也可以让可变成员的值改变。

使用**this指针**访问成员的优点是，可以明确指出访问的是对象的成员，并且可以在成员函数中使用与数据成员同名的形参；缺点是代码不够简洁。

分别定义两个类，即使两个类的成员列表完全一致，两个类也是完全不同的类型。

A 类中成员需要访问 B 类中的私有成员，则 B 类需要把 A 类指定为它的友元。友元的成员函数可以访问该类包括非公有成员在内的所有成员。

```cpp
class B
{ //A的成员访问B类的私有部分
	friend class A;
	//B类的剩余部分
};
```

- 要将某个成员函数作为友元，如将A类中的 clear 函数声明为B类的友元，使 clear 函数具有B类的访问权限，需按照以下方式设计程序：
    1. 首先定义A类，其中声明 clear 函数，但不能定义该函数。在 clear 使用B类的成员之前必须先声明B类
    2. 然后定义B，包括在B中对 clear 的友元声明。
    3. 最后定义 clear 函数，此时它才可以使用B的成员。

### 类的作用域

 在类中，如果成员使用了外层作用域中的某个名字，而且该名字代表一种类型，则类不能在之后重新定义该名字。

### 构造函数再探

成员初始化与赋值之间存在着差异：**const 成员**或是**引用**必须初始化；当成员属于某类类型且该类没有定义默认构造函数，也必须初始化。**初始化 const 或者引用类型数据成员的唯一机会就是通过构造函数初始值**（在函数形参列表之后函数体之前利用冒号形成构造函数初始值）。

```
💡 建议养成使用构造函数初始值的习惯。构造函数初始值的顺序最好与成员声明的顺序一致，避免使用某些成员初始化其他成员。
```

```cpp
class X{
	int i;
	int j;
public:
	X(int val) : j(val),i(j) {}  //实际上i首先被初始化，但试图使用未定义的j来初始化，编译器会警告！
};
//最好写成 X(int val) : i(val), j(val) {}
```

**C++11** 新标准使得可以定义**委托构造函数**（使用其所属的类的其他构造函数执行自己的初始化过程）。

```
💡 声明一个使用默认构造函数初始化的对象（不应保留对象名之后的括号）：
Sales_data  obj( );           //错误：声明的是一个函数而非对象

Sales_data  obj2;            //正确：obj2是一个对象而非函数
```



~~逐渐抽象了起来，我人傻了~~

### 类中的静态成员

在类中的成员声明前加上关键字 **static** 使其成为静态成员，可以是public或private的，类型可以是常量、引用、指针、类类型等。静态成员函数不包含 this 指针

```
💡 和类的所有成员一样，当我们指向类外部的静态成员时，必须指明成员所属的类名。 static 关键字只出现在类内部的声明语句中。当在类的外部定义静态成员时，不能重复关键字。
```

除了静态常量成员之外，其他的静态成员不能在类的内部初始化。

# IO库

### IO类

标准库中的继承机制可以让我们声明一个特定的类继承来自另一个类，通常可以将一个派生类（继承类）对象当作其基类（所继承的类）对象来使用。

不可以对IO对象拷贝或是赋值，不能将形参或返回类型设置为流类型，进行IO操作的函数通常以引用方式传递和返回流，传递和返回的引用不能是const。

# 顺序容器

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%205.png)

### 顺序容器的操作

调用push或insert成员函数时，将元素类型的对象传递给它们，将这些对象拷贝到容器中；

调用emplace成员函数时，将参数传递给元素类型的构造函数，emlpace 成员使用这些参数在容器管理的内存空间中直接构造元素。

调用emplace_back会在容器管理的内存空间直接创建对象；而调用push_back则会创建一个临时局部对象，再将其压容器中

```
💡 调用emlpace函数在容器中直接构造函数，传递给emplace函数的参数必须与元素类型的构造函数相匹配。
```

迭代器end指向的时容器**尾元素之后的（不存在的）**元素

使用front和back之前，必须确认容器是否为空

c[n] 和 c.at(n) 作用基本一致

使用auto变量保存函数的返回值，并希望使用该变量来改变元素的值，则将变量定义为引用类型

erase从容器中指定位置删除元素，并返回指向删除的元素之后位置的迭代器。

```cpp
//删除两个迭代器表示的范围内的元素
//返回指向最后一个被删元素之后位置的迭代器
elem1 = slist.erase(elem1, elem2) //调用后，elem1 == elem2

//其中,elem1指向要删除的第一个元素,elem2指向要删除的第二个元素

slist.clear();
slist.erase(slist.begin(), slist.end());//二者等效
```

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%206.png)

### 容器扩容

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%207.png)

只有当需要的内存空间超过当前容量时，reserve调用才改变vector的容量；如果reserve需求小于当前容量，不操作（不会退回内存空间）。

```
💡 reserve不会减少容器占用的内存空间；resize成员函数只改变容器中元素的数目，而不是容器的容量。
```

### 额外的string操作（详情 P.320）

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%208.png)

### 容器设配器

stack、queue、priority_queue

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%209.png)

# 泛型算法

```
💡 泛型算法不会进行执行容器的操作，只会运行于迭代器之上——算法可能改变容器中保存元素的值，也可能在容器中移动元素，但永远不会直接添加或删除元素。
```

### 泛型算法初识

**只读算法**

```cpp
💡 find
   count
    
   accumulate→
   int sum = accumulate(vec.cbegin(), vec.cend(), 0)
   string sum = accumulate(vec.begin(), vec.cend(), string(""))
   //accumulate的第三个参数类型决定了函数中使用哪种加法运算以及返回值的类型
    
   equal
```



**警惕** 向空容器调用fill_n（或类似的写元素的算法）



```
💡 向目的位置迭代器写入数据的算法假定目的位置足够大，能容纳要写入的元素
```



**back_inserter 插入迭代器**

```cpp
//赋值运算符调用push_back将一个具有给定值的元素添加到容器中
vector<int> vec;//创建空向量
auto it = back_inserter(vec);//通过该语句将元素添加到vec中
*it = 42;//vec中存在一个元素，值为42

//利用back_inserter创建迭代器，作为算法的目的位置来使用
vector<int> vec;
fill_n(back_inserter(vec), 10, 0);//添加10个元素到vec中
```

**拷贝算法**

```cpp
auto ret = copy(begin(a1), end(a1), a2);  //把a1的内容拷贝给a2
//copy返回的是其目的位置迭代器（递增后）的值，也即指向a2中拷贝元素之后的位置
```

**重排元素算法**

```cpp
sort(word.begin(), word.end());//按照字典排序word，以便查找重复元素
//unique重排输入范围，使每个单词只出现一次
auto end_unique = unique(word.begin(), word.end());//返回指向不重复区域之后一个位置的迭代器
word.erase(end_unique, word.end());//使用向量操作erase删除重复单词
```

### 定制操作

**向算法传递函数**

谓词

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2010.png)

**lambda表达式**~~（看不懂。。）~~

### 再谈迭代器

插入迭代器，流迭代器，反向迭代器，移动迭代器

各迭代器调用操作之间的差异

**iostream 迭代器**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2011.png)

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2012.png)

**反向迭代器**

通过调用rbegin、rend、crbegin、crend 成员函数来获得反向迭代器

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2013.png)



```
💡 递增一个反向迭代器会移动到前一个元素；递减一个迭代器会移动到下一个元素
```



![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2014.png)

普通迭代器和反向迭代器的关系反映了左闭合区间的特性。

### 泛型算法结构

……

### 特定容器算法

链表的特定版本与通用版本的重要区别时链表版本会改变底层的容器

# 关联容器



```
💡 关联容器中元素的位置是按关键字来保存和访问的；顺序容器中的元素的位置是按照它们在容器中的位置来保存和访问的
```



![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2015.png)

### 使用关联容器

```cpp
//使用map统计每个单词在输入中出现次数
map<string, size_t> word_count;
string word;
while (cin >> word)
	++word_count[word];
for (const auto& w : word_count)
	cout << w.first << " occurs " << w.second
	<< ((w.second > 1) ? " times" : " time") << endl;
```

```cpp
//使用set保存需要忽略的单词
map<string, size_t> word_count;
set<string> exclude = { "the","but","you","a","but" };
string word;
while (cin >> word)
	//只统计不在exclude中的单词
	if (exclude.find(word) == exclude.end())
		++word_count[word];//获取并递增word的计数器
```

### 关联容器概述

定义一个map时，必须指明关键字类型和值类型；而定义一个set时，只需指明关键字类型。

一个map或set中关键字是唯一的，对于一个给定的关键字，只能有一个元素的关键字等于它。

而multimap和multiset没有该限制，允许多个元素具有相同关键字。

**关键字类型要求**

**pair 一种标准库类型**

pair需要两个类型名，两个类型不要求一样

与其他标准库类型不同，pair的数据成员是public的，两个成员名分别为first和second

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2016.png)

### 关联容器操作

解引用一个关联容器迭代器，会得到一个类型为容器的value_type的值的引用。

对于map而言，value_type是一个pair类型，其first成员保存**const的关键字**，second成员保存值

```
💡 map的value_type是一个pair，可以改变pair的值，但不能改变关键字成员的值
```

map中元素是pair，其第一个成员是const的；set中的元素是const的

set的迭代器都是const的，关键字只能读取，不能修改

map和set都支持begin和end操作来遍历容器

**添加元素**

```cpp
//通过insert成员向容器中添加一个或一个范围内的元素
vector<int> ivec = {2,4,6,8,9,2,4,6};
set<int> set2;
set2.insert(ivec.cbegin(), ivec.cend());//接受迭代器的insert版本
set2.iinsert({1,3,5,7,9,2,3});//初始化器列表的insert版本
```

**向map添加元素**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2017.png)

**检测insert的返回值**

添加单一元素的insert或emplace版本返回一个pair，告知插入操作是否成功；

pair的first成员是一个迭代器，指向具有给定关键字的元素；second成员是一个bool值，指出元素是否插入成功；

如果关键字已在容器中，insert无操作，其返回值中的bool部分为false；如果不存在且插入成功，返回值中bool部分为true

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2018.png)

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2019.png)

**删除元素**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2020.png)

**map的下标操作**

map下标运算符接受一个索引（也即一个关键字），获取与该关键字相关联的值。但是，如果关键字不在map中，会创建一个元素并插入到map中，关联值将进行值初始化

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2021.png)



```

💡 对一个map进行下标操作时，会获得一个mapped_type对象；但当解引用一个map迭代器时，会得到一个value_type对象
   map的下标运算符返回的是一个左值，既可以读也可以写元素
```



**访问元素**

<img src="C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2022.png" alt="Untitled" style="zoom:50%;" />

<img src="C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2023.png" alt="Untitled" style="zoom:50%;" />

```
💡 在map中使用find代替下标操作，因为下标操作会在关键字不存在的情况下插入一个给定关键字的元素，而这种行为的正确与否完全取决于我们的预期。单词计数器就依赖于这样的特性：如果使用一个不存在的关键字作为下标，会插入一个新元素，新元素的关键字为给定关键字并设置其值为0。

但有时不需要改变map，只想检查元素是否存在，则使用find最佳
```



### 无序容器

```
💡 如果关键字类型固有就是无序的，或者性能测试发现问题可以用哈希技术解决，就可以使用无序容器.
```

无序容器在存储上组织为一组桶，每个桶保存零个或多个元素。无序容器利用哈希函数将元素映射到桶。

当一个桶保存多个元素时，首先计算元素的哈希值，根据计算所得哈希值在对应的桶中搜索。

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2024.png)

# 动态内存

除了静态内存和栈内存，每个程序还有一个内存池，被称为**自由空间**或**堆(heap)**

### 动态内存和智能指针

new，在动态内存中为对象分配空间并返回一个指向该对象的指针，可以选择是否初始化对象；

delete，接受一个动态对象的指针，销毁对象并释放与之相关的内存

**shared_ptr 指针类**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2025.png)

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2026.png)

使用make_shared标准库函数是最安全的分配和使用动态内存的方法，该函数在动态内存中分配一个对象并初始化它，返回指向此对象的shared_ptr

**直接管理内存**

```cpp
//使用new动态分配和初始化对象
int *pi = new int;
string *ps = new string;

int *pi = new int(1024);//pi指向的对象值为1024
string *ps = new string(10, '9');//*ps为"9999999999"
vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
//值初始化，加空括号即可
```

一个动态分配的const对象必须进行初始化，由于分配的对象是const的，new返回的指针是一个指向const的指针。

```cpp
const int *pci = new const int(1024);
const string *pcs = new const string;
```

若内存耗尽，new返回一个类型为bad_alloc 的异常

动态对象的生存期直至被释放为止，最后需要用delete释放动态内存

传递给delete的指针必须指向动态分配的内存，或者是一个空指针

如果对同一块内存释放多次，可能破坏自由空间

**shared_ptr 和new 结合使用**

```cpp
//不能将一个内置指针隐式转换为一个智能指针，必须用直接初始化形式
shared_ptr<int> p2(new int(1024));
```

不要混合使用普通指针和智能指针

也不要用get初始化另一个智能指针或为智能指针赋值

智能指针在程序异常时会自动释放内存，而普通指针需要自行delete


💡 **智能指针陷阱**：


- 不使用相同的内置指针初始化（或reset）多个智能指针
- 不delete get() 返回的指针
- 不使用get()初始化或reset另一个智能指针
- 若使用get()返回的指针，当最后一个对应的智能指针销毁后，该指针就变得无效
- 若使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器


### 动态数组

```cpp
//new分配要求数量的对象并返回指向第一个对象的指针
int *pia = new int[get_size()];//pia指向第一个int

//也可以用数组类型的类型别名
typedef int arrT[42];
int *p = new arrT;//分配一个42个int的数组
```

我们分配所得到的并不是一个数组类型，而是得到一个数组元素类型的指针

**所谓的动态数组并不是数组类型**

```cpp
delete [] pa; //释放动态数组，pa必须指向一个动态分配的数组或空
//数组中元素被逆序销毁，最后一个元素首先被销毁，然后是倒数第二个
```

**allocate类**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2027.png)



```
💡 当使用allocate分配内存时，必须记住内存是未构造的，为了使用原始内存，必须调用construct，在内存中构造一个对象。
```



# 拷贝控制

使用一个对象初始化同一类型的另一对象时，需要拷贝控制操作。故此，

在一个类中，必须定义对象拷贝、移动、赋值和销毁时做什么

### 拷贝、赋值和销毁

```cpp
class Foo{
public:
	Foo();//默认构造函数
	Foo(const Foo&);//拷贝构造函数
	...
	Foo& operator=(const Foo&);//赋值运算符
	...
	~Foo();//析构函数
```

**拷贝构造函数**

添加了explicit的构造函数，必须显式调用

初始化值时也就需要直接初始化构造，而不能拷贝初始化（用等号）

```cpp
vector<int> v1(10);//正确：直接初始化
vector<int> v2 = 10;//错误，接受大小参数的构造函数是explicit

void f(vector<int>);
f(10);//错误，不能用explicit构造函数拷贝一个实参
f(vector<int>(10));//正确，用int直接构造一个临时vector
```

**拷贝赋值运算符**

赋值运算符返回一个指向其左侧运算对象的引用

合成拷贝赋值运算符返回一个指向其左侧运算对象的引用

重载运算符 operator= ，在自定义的类中自定义相关运算操作

**析构函数**

当指向一个对象的引用或指针离开作用域时，析构函数不会执行。

```
💡 需要析构函数的类也需要拷贝和赋值操作

需要拷贝操作的类也需要赋值操作，反之亦然
```

将拷贝控制成员定义为 =default 来显示地要求编译器生成合成的版本，当我们在类内使用 =default 修饰成员声名时，合成的函数将隐式地声明为内联的

如果不希望是内联的，应该只对成员的类外定义使用 =default

**组织拷贝**

在函数的参数列表后加上 =delete 指出定义为删除的来阻止拷贝或赋值

```cpp
NoCopy(const NoCopy&) = delete;//阻止拷贝
NoCopy &operator=(const NoCopy&) = delete;//阻止赋值
```

### 拷贝控制和资源管理

编写赋值运算符的稳妥步骤（即使是将一个对象赋予它自身）：

- 先将右侧运算对象拷贝到一个临时对象中
- 拷贝完成，销毁左侧运算对象现有成员
- 将数据从临时对象拷贝至现有左侧运算对象

**定义行为像值的类**

```cpp
class HasPtr{
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0) { }
	//对于ps指向的string，每个HasPtr对象都有自己的拷贝
	HasPtr(const HasPtr &p):
		ps(new std::string(*p.ps)), i(p.i) { }
	HasPtr& operator=(const HasPtr &);
	~HasPtr() {delete ps;}
private:
	std::string *ps;
	int i;
}
```

**定义行为像指针的类**

类中创建引用计数，将计数器保存在动态内存中

```cpp
class HasPtr{
public:
	//构造函数分配新的string和新的计数器，将计数器置为1
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
	//拷贝函数拷贝所有三个数据成员，并递增计数器
	HasPtr(const HasPtr &p):
		ps(new std::string(*p.ps)), i(p.i), use(p.use) {++*use}
	HasPtr& operator=(const HasPtr &);
	~HasPtr();
private:
	std::string *ps;
	int i;
	std::size_t *use;//计数器，用来记录有多少个对象共享*ps的成员
};
```

### 交换操作

若使用类自定义的swap，应调用swap而不是std : : swap

**在赋值运算符中使用swap**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2028.png)

swap调用后，则rhs保存原来的左侧对象所存的指针，*this中的指针成员将指向新分配的string——右侧运算对象中string的一个副本，析构函数delete rhs 现在指向的内存

### 动态内存管理类

### 对象移动

在某些情况下，进行对象拷贝，拷贝完成后立即销毁，而此时用移动而非拷贝会大幅提升性能

**右值引用**

通过 && 来获得右值引用，且右值引用只能绑定到一个将要销毁的对象上

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2029.png)

返回左值引用的函数，连同赋值、下标、解引用和前置递增/递减运算符，都是返回左值的表达式的例子

返回非引用类型的函数，连同算数、关系、位以及后置递增/递减运算符，都生成右值，而且可以将一个const的左值引用或右值引用绑定到这类表达式上

利用标准库move函数，可以显示地将一个左值对应地转换为右值引用类型

```cpp
int &&rr3 = std::move(rr1);
//此后，除了对rr1赋值或销毁，将不能再使用它
```

**移动构造和移动拷贝**

**右值引用和成员函数**

```
💡 区分移动和拷贝的重载函数通常有一个版本接受一个 const T&，而另一个版本接受 T&&
```

```cpp
//为StrVec定义两个版本的push_back
calss Strvec {
public:
	void push_back(const std::string&);//拷贝元素
	void push_back(std::string&&);//移动元素
};

void StrVec::push_back(const string& s)
{
	chk_n_alloc();//确保有空间容纳新元素
	alloc.construct(first_free++, s);
}
void StrVec::push_back(string &&s)
{
	chk_n_alloc();//确保有空间容纳新元素
	alloc.construct(first_free++, std::move(s));
}

//实参类型决定是拷贝还是移动
StrVec vec;
string s="some string";
vec.push_back(s);//调用push_back(const string&)
vec.push_back("done");//调用push_back(string&&)
```

引用限定符

对于&限定的函数，只能用于左值；对于&&限定的函数，只能用于右值

同时使用const和引用限定符，引用限定符在const限定符之后

# 操作重载和类型转换

重载运算符：名字由关键字 operator 和其后要定义的运算符号共同组成，重载的运算符包含返回类型、参数列表以及函数体

```
💡 当一个重载的运算符是成员函数，它的第一个（左侧）运算对象绑定到隐式的this指针上。成员运算符函数的（显式）参数数量比运算对象的数量少一个
```



![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2030.png)

定义重载运算符之前，先确定声名为类的成员函数还是普通的非成员函数

```cpp
data += data2；  //基于“调用“的表达式
data1.operator+=（data2）；//等价调用
```

### 输入和输出

输出运算符的第一个形参是一个非常量ostream对象的引用，第二个形参是一个常量的引用，该常量是我们想要打印的类类型

```cpp
ostream &operator<<(ostream &os, const Sale_data &item)
    {
        os << item.isbn() << " " << item.unit_sold << " "
           << item.revenue << " " << item.avg_price();
        return os;
    }
```

输入运算符的第一个形参是运算符将要读取的流的引用，第二个形参是将要读到的（非常量）对象的引用

```cpp
istream &operator>>(ostream &is, const Sale_data &item)
    {
        double price;//不需要初始化，先将数据读到price，之后才使用它
        is >> item.bookNo >> item.unit_sold >> price;
        if (is)   //检查输入是否成功
            item.revenue = item.unit_sold * price;
        else
            item = Sale_data();  //输入失败：对象被赋予默认状态
        return is;
    }
```

```
💡 输入运算符需要检查可能失败，输出不需要
```

### 算数与关系运算符

```cpp
//使用复合赋值来定义算术运算符
Sale_date
operator+(const Sale_date &lhs, const Sale_data &rhs)
{
	Sale_data sum = lhs;
	sum += rhs;
	renturn sum;
}
```

**相等运算符**

相等运算符和不相等运算符应该把工作交给其中一个，一个负责实际比较工作，另一个则只是调用那个真正工作的运算符

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2031.png)

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2032.png)

### 赋值运算符

### 下标运算符

下标运算符必须是成员函数

### 递增与递减运算符

定义递增和递减运算符应该同时定义前置和后置版本

前置运算符应该返回递增或递减后对象的引用；后置运算符应该返回对象的原值

### 成员访问运算符

箭头运算符（- >)必须是类的成员，解引用运算符（*）通常也是类的成员，但并非强制

### 函数调用运算符

lambda

### 重载、类型转换与运算符

*。。。有空再看一遍这章吧* 

# 面向对象程序设计(OOP)

### 概述

面向对象程序设计的核心思想是**数据抽象、继承和动态绑定**

- 数据抽象——将类的接口与实现分离
- 继承——定义相似的类型并对其相似关系建模
- 动态绑定——可以在一定程度上忽略相似类型的区别，而以统一的方式使用它们的对象

**继承**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2033.png)

虚函数

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2034.png)

类派生列表

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2035.png)

**动态绑定**

函数可以被多个类调用，可以是基类也可以是派生类，运行时函数的运行版本由实参决定，所以动态绑定又叫做**运行时绑定**

### 定义基类和派生类

<aside>
💡 基类通常需要定义一个虚析构函数（virtual），即使该函数不执行任何操作

</aside>

**定义基类**

派生类的成员函数不一定有权访问从基类继承而来的成员

如果基类希望它的派生类有权访问某些成员，但禁止其他用户访问，可以用**受保护的（protected）**访问运算符说明这样的成员。

**定义派生类**

类派生列表形式中，冒号之后的基类前有三种访问说明符中之一：public、protected 或 private

C++11标准中 派生类显式注明它使用某个成员函数覆盖他继承的虚函数，在后面加关键字 **override**

**派生类到基类的**类型转换：

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2036.png)

<aside>
💡 每个类控制自己的成员初始化过程，即使派生类对象从基类继承成员，派生类也必须使用基类的构造函数来初始化它的基类部分

</aside>

派生类的**声名**中，包含类名但不包含它的派生列表

### 虚函数

对虚函数的调用可能在运行时才被解析

使用 override 关键字来说明派生类中的虚函数，覆盖基类中该虚函数

使用 final 关键字，则后续不允许任何覆盖该函数的操作

### 抽象基类

纯虚函数：一个纯虚函数无需定义，在函数体的位置（即在声明语句的分号之前）书写 =0 就可以将一个虚函数说明为纯虚函数。=0 只能出现在类内部的虚函数声明语句处

含有纯虚函数的类是抽象基类

<aside>
💡 不能直接创建一个抽象基类的对象（因为其中对于纯虚函数没有给出定义）

</aside>

### 访问控制与继承

三个规则：

- 和私有成员类似，受保护的成员对于类的用户是不可访问的
- 和公有成员类似，受保护的成员对于派生类的成员和友元是可以访问的
- **（protected）派生类的成员或友元只能通过派生类对象来访问基类的受保护成员。派生类对于一个基类对象中受保护成员没有任何访问特权**

<aside>
💡 友元关系不能继承；每个类各自控制自己成员的访问权限

</aside>

**继承中的类作用域**

派生类的作用域位于基类的作用域之内

派生类中成员与基类同名，则隐藏同名的基类成员（只是隐藏，不会重载），即使派生类成员与基类成员的形参列表不一样，基类成员也会被隐藏

### 构造函数与拷贝控制

**虚析构函数**

<aside>
💡 将基类的析构函数定义为虚函数，确保delete基类指针时将运行正确的析构函数

</aside>

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2037.png)

基类不需要遵循（如果一个类需要析构函数，那么它也同样需要拷贝和赋值操作）的原则，因为基类若将析构函数设为虚函数则令内容为空，不一定需要拷贝和赋值

**合成拷贝控制和继承**

### 容器与继承

basket类的编写

### 再探文本查询程序

# 模板与泛型编程

### 定义模板

**函数模板**

通用的函数模板：作为一种公式，可以用来生成针对特定版本的函数版本。

模板样式：以关键字 template 开始，后跟一个模板参数列表（template parameter list），用小于号和大于号包围起来

<aside>
💡 模板参数列表不能为空

</aside>

当使用模板时，（隐式或显式地）指定模板实参，将其绑定到模板参数上

`template <typename T>`

**实例化参数模板：**编译器在调用模板时，根据推断出来的模板参数来**实例化**一个特定版本的函数

模板**类型参数**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2038.png)

非类型**模板参数**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2039.png)

<aside>
💡 非类型模板参数实参必须是常量表达式

</aside>

inline 和 constexpr 的函数模板

`template <typename T> inline T min (const T&, const T&);`

函数模板直到实例化才会生成代码，也就是大多数的编译错误只在实例化期间才能发现

**类模板**

![Untitled](C++%20Primer%2034af589fd26a4e5ea9b90626174c8d3d/Untitled%2040.png)

实例化类模板时，需要提供元素类型

<aside>
💡 对于一个实例化了的类模板，其成员只有在使用时才被实例化

</aside>

# 补充内容

转型：

[C++ 四种转型方式](https://www.cnblogs.com/weiqubo/archive/2011/01/26/1945210.html)