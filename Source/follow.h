#ifndef __FOLLOW_H__
#define __FOLLOW_H__
#include "US_015.h"				// ³¬Éù²¨Í·ÎÄ¼þ


float distance_measure_2();
void KeepDistance(float cur_ave_distances, unsigned char* direction);
void Following(unsigned char *mode, unsigned char* direction);
#endif