/****************************************************************************\
 *                            Carta™ GUI Library                            *
 *                                                                          *
 *                         Copyright © 2020 Aquefir                         *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC__CARTA_OVERLAY_H
#define INC__CARTA_OVERLAY_H

#include <uni/types/vec.h>

enum
{
	FILT_BLUR_TYPE_BOX = 0,
	FILT_BLUR_TYPE_GAUSS,
	FILT_BLUR_TYPE_RAD,
	FILT_BLUR_TYPE_MOTION
};

enum
{
	OVERLAY_TYPE_BLUR = 0
};

struct filt_blur
{
	u8 type;
	f32 blursz;
};

struct carta_overlay
{
	u16v2 lw;
	s16v2 xy;
	u8 invert : 1;
	u8 type : 7;
	union
	{
		struct filt_blur blur;
	};
};

#endif /* INC__CARTA_OVERLAY_H */
