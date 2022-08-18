# runtime semantics
## 1. object construction and destruction
* pseudo code below
    > ```
    > {
    >   Point point;
    >   //point.Point::Point(); constructor insert this
    >   ...
    >   //point.Point::~Point(); destructor insert this
    > }
    > ```
    > if a scope has many exit, there are many inserted destructors.

* global objects
    > code below
    > ```
    > Matrix identity;
    > int main() {
    >   //identity must already created
    >   Matrix m1 = identity;
    >   ...
    >   return 0;
    > }
    > ```
    > the compiler guarantee before first use `identity` int `main()` the global objects have been constructed,  
    > and before the end of `main()`, the global objects have been destructed.
    > and the global object's defualt value is zero.

* local static objects
    > code below
    > ```
    > const Matrix& identity() {
    >   static Matrix mat_identity;
    >   //...
    >   return mat_identity;
    > }
    > ```
    > the compiler guarantee that :
    > 1. `mat_identity` constructor only be called once if need.
    > 2. `mat_identity` destructor only be called once if need.
    > 3. `mat_identity` construction only in need(if no call, no construction).

## 2. new and delete
* new
    > there are two steps in `new` operation
    > 1. allocate memory by system.
    > 2. construction

* delete
    > there are two steps in `delete` operation
    > 1. destruction
    > 2. free memory by system.

## 3. temporary objects
* conside code below
    > ```
    > Y yy;
    > X xx;
    > if (yy == xx.getValue()) ...
    > ```
    > after compiler transform
    > ```
    > {
    >     X temp1 = xx.getValue();
    >     Y temp2 = temp1.operator Y();
    >     int temp3  = yy.operator==(temp2);
    >
    >     if (temp3) ...
    >
    >     temp2.Y::~Y();
    >     temp1.X::~x();
    > }
    > ```

