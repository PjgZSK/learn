# float (IEEE 754)
## 1. float value
* Value
    > value = sign * exponent * fraction  

* IEEE 754 format
    > sign : MSB(Most Significant Byte)  
    > exponent
    > fraction : integer part has a default value and is not included

## 2. normalization
* exponnet
    > shift code, shift value : 2 ^ (e - 1) - 1  
    > memery value = true value + shift value  
    > range : 1 - 2 ^ (e - 1) - 2  
    > 0 : 0 or not normal  
    > 2 ^ (e - 1) - 1 : NaN or infinite  

* fraction
    > msb is 1  

* default integer
    > 1

## 3. not normalization
* exponnet
    > 0  

* fraction
    > not 0

* default integer
    > 0

## 4. special value
* 0(+0 and -0)
    > exponent : 0  
    > fraction : 0

* not normal
    > exponent : 0  
    > fraction : not 0

* infinite
    > exponnet : 2 ^ (e - 1) - 1  
    > fraction : 0

* NaN
    > exponent : 2 ^ (e - 1) - 1  
    > fraction : not 0
