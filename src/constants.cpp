#include "constants.h"
#include "complex.h"
#include "functions.h"
#include "mul.h"
#include "add.h"
#include "pow.h"

namespace CSymPy {

RCP<const Integer> zero = rcp(new Integer(0));
RCP<const Integer> one = rcp(new Integer(1));
RCP<const Integer> minus_one = rcp(new Integer(-1));
RCP<const Number> I = Complex::from_two_nums(*zero, *one);

RCP<const Symbol> pi = rcp(new Symbol("pi"));
RCP<const Symbol> E = rcp(new Symbol("E"));

// Global variables declared in functions.cpp
// Look over https://github.com/sympy/csympy/issues/272
// for further details
RCP<const Basic> i2 = rcp(new Integer(2));

RCP<const Basic> sqrt_(const RCP<const Basic>& arg)
{
    return pow(arg, div(one, i2));
}


RCP<const Basic> i3 = rcp(new Integer(3));
RCP<const Basic> i5 = rcp(new Integer(5));
RCP<const Basic> im2 = rcp(new Integer(-2));
RCP<const Basic> im3 = rcp(new Integer(-3));
RCP<const Basic> im5 = rcp(new Integer(-5));

RCP<const Basic> sq3 = sqrt_(i3);
RCP<const Basic> sq2 = sqrt_(i2);
RCP<const Basic> sq5 = sqrt_(i5);

RCP<const Basic> C0 = div(sub(sq3, one), mul(i2, sq2));
RCP<const Basic> C1 = div(one, i2);
RCP<const Basic> C2 = div(sq2, i2);
RCP<const Basic> C3 = div(sq3, i2);
RCP<const Basic> C4 = div(add(sq3, one), mul(i2, sq2));
RCP<const Basic> C5 = div(sqrt_(sub(i5, sqrt_(i5))), integer(8));
RCP<const Basic> C6 = div(sub(sqrt_(i5), one), integer(4));

RCP<const Basic> mC0 = mul(minus_one, C0);
RCP<const Basic> mC1 = mul(minus_one, C1);
RCP<const Basic> mC2 = mul(minus_one, C2);
RCP<const Basic> mC3 = mul(minus_one, C3);
RCP<const Basic> mC4 = mul(minus_one, C4);
RCP<const Basic> mC5 = mul(minus_one, C5);
RCP<const Basic> mC6 = mul(minus_one, C6);

// sin_table[n] represents the value of sin(2*pi*n/24) for n = 0..23
RCP<const Basic> sin_table[] = {
        zero, C0, C1, C2, C3, C4, one, C4, C3, C2, C1, C0,
        zero, mC0, mC1, mC2, mC3, mC4, minus_one, mC4, mC3, mC2, mC1, mC0
    };

umap_basic_basic inverse_cst = {
    {C3, i3},
    {mC3, im3},
    {C2, mul(i2, i2)},
    {mC2, mul(im2, i2)},
    {C4, integer(12)},
    {mC4, integer(-12)},
    {C5, i5},
    {mC5, im5},
    {C6, integer(10)},
    {mC6, integer(-10)},
    {div(one, i2), integer(6)},
    {div(minus_one, i2), integer(-6)},
};

umap_basic_basic inverse_tct = {
    {div(one, sq3), mul(i2, i3)},
    {div(minus_one, sq3), mul(im2, i3)},
    {sq3, i3},
    {mul(minus_one, sq3), im3},
    {add(one, sq2), div(pow(i2, i3), i3)},
    {mul(minus_one, add(one, sq2)), div(pow(i2, i3), im3)},
    {sub(sq2, one), pow(i2, i3)},
    {sub(one, sq2), pow(im2, i3)},
    {sub(i2, sq3), mul(mul(i2,i2), i3)},
    {sub(sq3, i2), mul(mul(im2,i2), i3)},
    {sqrt(add(i5, mul(i2, sqrt(i5)))), div(i5, i2)},
    {mul(minus_one, sqrt(add(i5, mul(i2, sqrt(i5))))), div(im5, i2)},
    {one, pow(i2, i2)},
    {minus_one, mul(minus_one, pow(i2, i2))},
};

}
