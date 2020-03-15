/****************************************************************************\
 *                            Carta™ GUI Library                            *
 *                                                                          *
 *                         Copyright © 2020 Aquefir                         *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC__CARTA_DISPDRV_H
#define INC__CARTA_DISPDRV_H

#include <carta/dispdrv.h>
#include <SDL2/SDL.h>
#include <uni/types/int.h>
#include <uni/types/vec.h>

struct carta_disp
{
	/* public (by accessor) */
	u16v2 scale;
	u32v2 nom_res;
	s32v2 xypos;
	u16 fullscr : 1;
	u16 hwaccel : 1;
	/* private */
	SDL_Window* win;
	SDL_Renderer* ren;
};

#endif /* INC__CARTA_DISPDRV_H */
