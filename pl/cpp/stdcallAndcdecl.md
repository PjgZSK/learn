# __stdcall and __cdecl
## __stdcall
1. The fullname of *__stdcall* is standard call and it is the standard call in C++ language.  
2. The order of push stack is right to left.  
3. The return of function is *retn x* where it will pop stack with *x* number. It means  
that the return of function will automatically adjust stack so the function parameters  
is fixed when we call function.  
4. *__stdcall* uses *function name confusion*. It means that when compiling the function  
name will add some prefix and some postfix, usaully parameter type and return value type.  
It means that *__stdcall* supports *function overloading*.  
## __cdecl
1. The fullname of *__cdecl* is c declaration and it is the standard call in C language.  
2. The order of push stack is right to left.  
3. The return of function is *ret* where is just return without adjust stack. It means  
that the caller must manually adjust stack after function return so the function parameters  
is unfixed when we call function.  
4. *__cdecl* don't use *function name confusion*. The source name is same with the name after  
compiling. It means that *__cdecl* don't support *function overloading*.  
