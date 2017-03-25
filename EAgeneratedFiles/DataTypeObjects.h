/****************************************************
 *  DataTypeObjects.h                                         
 *  Created on: 25-mar-2017 02:06:28                      
 *  Implementation of the Class DataTypeObjects       
 *  Original author: szym                     
 ****************************************************/

#if !defined(EA_3DE6F56B_F892_4fc0_9F04_029428B87D53__INCLUDED_)
#define EA_3DE6F56B_F892_4fc0_9F04_029428B87D53__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

#include "DataParser.h"
#include "Main.h"
#include "MathFunctions.h"

/**
 * typedef struct Place{
 * double x, y, z;
 * }
 * 
 * typedef struct Velocity{
 * double vx, vy, vz;
 * }
 * 
 * typedef struct Planet{
 * char* Name;
 * double mass;
 * place* coords;
 * velocity* velocity;
 * }
 */

float GravConst;
float TimeStep;
DataParser *m_DataParser;
Main *m_Main;
MathFunctions *m_MathFunctions;


#ifdef __cplusplus
}
#endif


#endif /*!defined(EA_3DE6F56B_F892_4fc0_9F04_029428B87D53__INCLUDED_)*/
 