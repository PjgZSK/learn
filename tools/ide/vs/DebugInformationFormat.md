## visual studio debug info format
### 定义
* 决定debug信息存储的格式以及存放在object file（obj）还是program database（pdb）里。
### 语法
* ```
    /Z{7|i|I}
    ```
### 选项
* None  
    不产生debug信息，编译速度最快
* /Z7  
    debug信息存放在obj里面，不生成pdb文件
* /Zi  
    生成pdb文件，且将debug信息存储在pdb文件里
* /ZI  
    生成pdb文件，且debug信息以一种支持编辑和持续的格式存储在pdb文件里  
    不支持arm处理器  

### 参考链接
* https://learn.microsoft.com/en-us/previous-versions/958x11bc(v=vs.140)?redirectedfrom=MSDN

