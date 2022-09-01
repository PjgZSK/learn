# square root
## 1. the pencil-and-paper algorithm
* predefinition
    > z : Radicand  
    > q : square root  
    > s : Remainder  
    > z = q * q + s

* lemma
    > 1. if digit(z) = 2k, then digit(q) = k and digit(s) <= k + 1  
    > 2. max( digit(k) * digit(k) + digit(k + 1) ) >= max( digit(2k) )  
    > 3. max(digit(k - 1) * digit(k - 1) + digit(k) ) < min ( digit(2k) )

* algorithm
    > make  
    > d : base system of numeriation  
    > z : z[2k - 1] z[2k - 2] ... z[0]  
    > q : q[k - 1] q [k  -2] ... q[0]  
    > s : s[k] s[k - 1] ... s[0]

    > loop(desc)  
    > (q[k - 1 ... i]) ^ 2 <= z[2k - 1 ... 2i]  
    > make pre = q[k - 1 ... i - 1], val = z[2k - 1 ... 2i], x = q[i]  
    > (d * pre + x) ^ 2 <= val  
    > (2d * pre + x) * x <= val - (d * pre) ^ 2  
    > q[i] = max( x )

## ref
* [suqareRoot](https://zhuanlan.zhihu.com/p/358795190)
