/* 
 * File:   AVG.h
 * Author: Mojtaba
 *
 * Created on July 28, 2021, 10:42 AM
 */

#ifndef AVG_H
#define	AVG_H

#ifdef	__cplusplus
extern "C" {
#endif
uint8_t N=30; //Number of Averages
static float sum;
static uint8_t index             = 0;
static float previousInputs[50] = {};
float AVG(float input) 
{
    sum -= previousInputs[index];
    sum += input;
    previousInputs[index] = input;
    if (++index == N)
        index = 0;
    return (sum ) / N;
}
    




#ifdef	__cplusplus
}
#endif

#endif	/* AVG_H */

