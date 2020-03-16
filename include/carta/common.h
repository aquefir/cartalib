/****************************************************************************\
 *                            Carta™ GUI Library                            *
 *                                                                          *
 *                         Copyright © 2020 Aquefir                         *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__CARTA_COMMON_H
#define INC_API__CARTA_COMMON_H

#include <uni/types/int.h>

#if defined( __cplusplus )
#define CARTA_API extern "C"
#else
#define CARTA_API
#endif /* defined( __cplusplus ) */

typedef u32 carta_hnd_t;

typedef u32 carta_col_t;

#define CARTA_COL_R( COL ) \
	(u8)((COL)>>24)
#define CARTA_COL_G( COL ) \
	(u8)(((COL)>>16)&0xFF)
#define CARTA_COL_B( COL ) \
	(u8)(((COL)>>8)&0xFF)
#define CARTA_COL_A( COL ) \
	(u8)((COL)&0xFF)

#endif /* INC_API__CARTA_COMMON_H */
