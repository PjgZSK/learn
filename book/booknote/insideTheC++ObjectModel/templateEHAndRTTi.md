# template, exception handling and runtime type identification
## 1. template
* declaration
    > compiler do nothing when it see a template declaration.

* instantiation
    > instantiate when use
    > template class data members will instantiate immediately.  
    > template class function members will instantiate when called

* error report
    > syntax error will report at declaration state  
    > template type relative error will report at instantiation state

* member function instantiation
    > when instantiation ? compile or link  
    > how to find template definition ? all in .h or corresponding .c/.cpp  
    > how to only instantiate called member function ?  
    > how to prevent from multiple instantiation in multiple .o file ?

## 2. exception handling
* exception handling need data created by compiler and runtime exception library.

* three part
    > 1. `throw`, throw a exception, the exception can be build-in type or custom type.  
    > 2. `catch`, every catch expression is a exception handler, it prepare to handle some  
    > exception type, and provide handle code.  
    > 3. `try`, match single or multiple `catch`.

* terminate()
    > when a exception be throwed, and no matched `catch`, then terminate() will be called.  
    > when terminate() be called, every function call will be *popped up*, it be named  
    > *unwinding the stack*.  
    > before function be *popped up*, its local calss objects's destructor will be called.

* exception handling
    > processing exception steps  
    > 1. check function `throw` happen  
    > 2. if `throw` happen in `try` scope.  
    > 3. if yes, compare exception type with all `catch`
    > 4. if has match, corresponding `catch` take program in control  
    > 5. if no `try` or no matched `catch`, then system must  
    > destory all active local objects,  
    > "unwind" current function in stack,  
    > go to next function in stack and repeat 2 ~ 5

## 3. runtime type identification (RTTI)
* type-safe downcast
    > need know real type of pointer in **runtime**  
    > extra space for query real type of pointer  
    > extra time for query

* type-safe dynamic cast
    > `dynamic_cast` is safe.  
    > if downcast is safe, `dynamic_cast` will return transformed pointer;  
    > if downcast is not safe, `dynamic_cast` will return 0;

* references is different form pointers
    > in `dynamic_cast`, if downcast is not safe, it will throw a `bad_cast` exception.

* typeid operator
    > `typeid` return a const reference, type is `type_info`.
    > `type_info` defined like below  
    > ```
    > class type_info {
    > public:
    >   virtual ~type_info();
    >   bool operator==(const type_info&) const;
    >   bool operator!=(const type_info&) const;
    >   bool before(const type_info&) const;
    >   const char*  name() const;
    > private:
    >   type_info(const type_info&);
    >   type_info& operator=(const type_info&);
    >   // data members
    >   //...
    > };
    > ```

## 4. the shortage of C++ object model
* dynamic shared libraries
    > if shared library's class layout changed, the call component also need rebuild.[* need verify]

* shared memory
    > 
