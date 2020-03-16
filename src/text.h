/****************************************************************************\
 *                            Carta™ GUI Library                            *
 *                                                                          *
 *                         Copyright © 2020 Aquefir                         *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC__CARTA_TEXT_H
#define INC__CARTA_TEXT_H

#include <carta/common.h>
#include <uni/types/int.h>

enum
{
	/* XXX: these only work for ASCII (Latin) */
	TEXT_TFORM_NONE = 0, /* normal */
	TEXT_TFORM_LOWER = 1, /* all lowercase */
	TEXT_TFORM_UPPER = 2, /* all uppercase */
	TEXT_TFORM_SMCAPS = 3 /* small caps */
};

enum
{
	TEXT_WEIGHT_LIGHT = 0, /* 200 */
	TEXT_WEIGHT_NORMAL = 1, /* 500 */
	TEXT_WEIGHT_BOLD = 2, /* 700 */
	TEXT_WEIGHT_BLACK = 3 /* 900 */
};

struct carta_text
{
	carta_hnd_t partn;
	const char* data;
	ptri data_sz;
	u16 glyph_ht : 11;
	u16 weight : 2;
	u16 tform : 2;
	u16 italic : 1;
};

#endif /* INC__CARTA_TEXT_H */
