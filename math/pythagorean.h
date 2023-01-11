/*************************************************************************
    > File Name: pythagorean.h
    > Author: pjg
    > Mail: 
    > Created Time: 2022/11/7 11:31:10
 ************************************************************************/

#include <stdio.h>

namespace pythagorean {

/*
 * 分数抽象类
 * 分子，分母，符号位在分子部分
 */
struct Fraction
{
    using punit = unsigned;
    using unit = int;
    unit nume;
    punit deno;

    Fraction() : nume(1), deno(1) { }
    Fraction(unit n, punit d) : nume(n), deno(d) {}
    Fraction(const Fraction& f) : nume(f.nume), deno(f.deno) { }
    Fraction(unit n) : nume(n), deno(1) { }

    void minimize() {
        //to do ...    
    }
   
    float toFloat() const {
        return static_cast<float>(this->nume) / this->deno;
    }

    void negate() {
        this->nume = -this->nume;
    }

    void add(const Fraction& f) {
        this->nume = this->nume * f.deno + f.nume * this->deno;
        this->deno *= f.deno;
        minimize();
    }
    
    void subtract(const Fraction& f) {
        this->nume = this->nume * f.deno - f.nume * this->deno;
        this->deno *= f.deno;
        minimize();
    }

    void multiply(const Fraction& f) {
        this->nume *= f.nume;
        this->deno *= f.deno;
        minimize();
    }

    void divide(const Fraction& f) {
        this->nume *= f.deno;
        this->deno *= f.nume;
        minimize();
    }

    Fraction operator-() const {
        Fraction res(*this);
        res.negate();
        return res;
    }

    bool operator<(const Fraction& r) const {
        return this->nume * r.deno < this->deno * r.nume;
    }
    
    bool operator>(const Fraction& r) const {
        return this->nume * r.deno > this->deno * r.nume;
    }

    bool operator==(const Fraction& r) const {
        return this->nume * r.deno == this->deno * r.nume;
    }
    
    bool operator!=(const Fraction& r) const {
        return this->nume * r.deno != this->deno * r.nume;
    }

    Fraction operator+(const Fraction& r) const {
        Fraction res(*this);
        res.add(r);
        return res;
    }
    
    Fraction& operator+=(const Fraction& r) {
        this->add(r);
        return *this;
    }

    Fraction operator-(const Fraction& r) const {
        Fraction res(*this);
        res.subtract(r);
        return res;
    }
     
    Fraction& operator-=(const Fraction& r) {
        this->subtract(r);
        return *this;
    }

    Fraction operator*(const Fraction& r) const {
        Fraction res(*this);
        res.multiply(r);
        return res;
    }
     
    Fraction& operator*=(const Fraction& r) {
        this->multiply(r);
        return *this;
    }

    Fraction operator/(const Fraction& r) const {
        Fraction res(*this);
        res.divide(res);
        return res;
    }
 
    Fraction& operator/=(const Fraction& r) {
        this->divide(r);
        return *this;
    }
};

/*
 * 毕达哥拉斯音级抽象类
 */
struct Pitch
{
    Fraction value;

    Pitch() { }
    Pitch(const Fraction& f) : value(f) { }
    Pitch(const Pitch& r) : value(r.value) { }

    void nextUp() {
        this->value *= Fraction(3, 2);
        if (this->value > 2)
        {
            this->value /= 2;            
        }
    }
    void nextDown() {
        this->value *= Fraction(2, 3);
        if (this->value < 1)
        {
            this->value *= 2;
        }
    }
    Pitch getNextUp() const {
        Pitch res(*this);
        res.nextUp();
        return res;
    }
    Pitch getNextDown() const {
        Pitch res(*this);
        res.nextDown();
        return res;
    }
};

void printPitch(const Pitch& p);

}
