/****************************************************
 *  MathFunctions.h                                         
 *  Created on: 25-mar-2017 02:06:28                      
 *  Implementation of the Class MathFunctions       
 *  Original author: szym                     
 ****************************************************/

#if !defined(EA_A67F320C_9926_47f2_A8C1_DC2A54D6AA7A__INCLUDED_)
#define EA_A67F320C_9926_47f2_A8C1_DC2A54D6AA7A__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

#include "Symulator.h"
#include "Collider.h"

Symulator *m_Symulator;
Collider *m_Collider;


void CalcNewPosition(Planet* Planet);
void EvalVelocity(Planet* A, Planet* B);


#ifdef __cplusplus
}
#endif


#endif /*!defined(EA_A67F320C_9926_47f2_A8C1_DC2A54D6AA7A__INCLUDED_)*/
 