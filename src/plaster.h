/****************************************************************************\
 *                            Carta™ GUI Library                            *
 *                                                                          *
 *                         Copyright © 2020 Aquefir                         *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC__CARTA_PLASTER_H
#define INC__CARTA_PLASTER_H

#include <carta/common.h>
#include <uni/types/int.h>

enum
{
	PLASTER_TYPE_COL = 0,
	MAX_PLASTER_TYPE
};

struct carta_plaster_col
{
	carta_col_t c;
};

struct carta_plaster
{
	carta_hnd_t partn;
	u8 type;
	union
	{
		struct carta_plaster_col col;
	};
};

#endif /* INC__CARTA_PLASTER_H */
