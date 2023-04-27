# var args
## 1. ...
* use in c, eg. `printf`, `scanf`
## 2. var template
* format  
    ```
    template<typename T>
    ostream& print(ostream& os, const T& t)
    {
        return os << t;
    }

    template<typename T, typename... Args>//这里的省略号表示Args是一个参数包
    ostream& print(ostream& os, const T& t, const Args&... rest)//这里的省略号表示扩展,在模板实例化中会将参数包扩展为一个个的参数
    {
        os << t << ", ";
        return print(os, rest...);//这里的省略号表示扩展,在函数匹配中会将rest扩展为一个个的实参
    }
    ```
* sizeof... and expand(...)
    sizeof... : calculate the number of a var args  
    expand : convert a var args to a arg list 
