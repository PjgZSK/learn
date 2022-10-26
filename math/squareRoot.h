/*************************************************************************
    > File Name: squareRoot.h
    > Author: pjg
    > Mail: 
    > Created Time: 2022/10/21 9:02:23
 ************************************************************************/

typedef enum SquareRootImplemention
{
    eMidSearch,
    eNewton,
    eFastInverse,
}SRImplemention;

float squareRoot(float v, const SRImplemention& implemention);
float squareRootMid(float v);
float squareRootNewton(float v);
float squareRootFastInv(float v);

