/****************************************************************************\
 *                            Carta™ GUI Library                            *
 *                                                                          *
 *                         Copyright © 2020 Aquefir                         *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC__CARTA_PICTURE_H
#define INC__CARTA_PICTURE_H

#include <carta/common.h>
#include <uni/types/int.h>
#include <uni/types/vec.h>

struct carta_picture
{
	carta_hnd_t partn;
	u16v2 lw;
	carta_col_t* px;
};

#endif /* INC__CARTA_PICTURE_H */
