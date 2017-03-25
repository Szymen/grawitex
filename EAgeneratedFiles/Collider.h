/****************************************************
 *  Collider.h                                         
 *  Created on: 25-mar-2017 02:06:28                      
 *  Implementation of the Class Collider       
 *  Original author: szym                     
 ****************************************************/

#if !defined(EA_65462781_BEA1_40a0_A377_2DF9D1B58AB7__INCLUDED_)
#define EA_65462781_BEA1_40a0_A377_2DF9D1B58AB7__INCLUDED_


#ifdef __cplusplus
extern "C" {
#endif

void Bounce(Planet* PlanetA, Planet* PlanetB);
void CollideAndFracture(Planet* PlanetsTable, int PlanetAindex, int PlanetBindex);
void GlueUp(Planet* PlanetTable, int PlanetAindex, int PlanetBindex);


#ifdef __cplusplus
}
#endif


#endif /*!defined(EA_65462781_BEA1_40a0_A377_2DF9D1B58AB7__INCLUDED_)*/
 