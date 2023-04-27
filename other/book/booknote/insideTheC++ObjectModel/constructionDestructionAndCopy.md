# construction destruction and copy
## 1. construction
* with virtual function
    > constructor set `vptr` first.

* with inheritance
    > 1. call *virtual base class constructors*, set *virtual base class subobject* offset, if haven't, skip it.
    > 2. call *base calss constructors*, if haven't, skip it.
    > 3. set *vptr*, if haven't skip it.
    > 4. member initialization.

## 2. copy
* three choose
    > default
    > delete
    > explicit

## 3. destruction
    > call destructor
    > reset `vptr`, if haven't, skip it.
    > call base class destructors, if haven't, skip it.
    > call virtual base class destructors.
