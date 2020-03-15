/****************************************************************************\
 *                            Carta™ GUI Library                            *
 *                                                                          *
 *                         Copyright © 2020 Aquefir                         *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#include "dispdrv.h"

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string.h>
#include <uni/option.h>
#include <uni/types/vec.h>

#define INITIAL_NOM_RES_W 640
#define INITIAL_NOM_RES_L 360

static u16 fl32tonormfx14( f32 n )
{
	u32 ret;

	ret = (u32)(n * 8191.0f);

	if((ret & 0x3FFF) < ret)
	{
		ret &= 0x3FFF;
	}

	return (u16)ret;
}

static f32 normfx14tofl32( u16 n )
{
	f32 ret;

	ret = (f32)n / 8191.0f;

	if(ret < -1.0f)
	{
		ret = -1.0f;
	}

	return ret;
}

UNI_OPTIONP( carta_disp ) carta_disp_init( struct carta_disp_initopts opts )
{
	UNI_OPTIONP( carta_disp ) ret;
	u32 phys_l, phys_w;

	/* allocate for the returned struct */
	ret.val = malloc( sizeof( *ret.val ) );
	ret.is = 0;

	if( ret.val == NULL )
	{
		return ret;
	}

	memset( ret.val, 0, sizeof( *ret.val ) );

	/* copy over simple values from the options struct */
	ret.val->scale = (u16v2){ opts.scale_num, opts.scale_den };
	ret.val->xypos = (s32v2){ 0, 0 };
	ret.val->fullscr = opts.start_fullscr == 0 ? 0 : 1;

	/* calculate the physical resolution */
	if( opts.start_fullscr )
	{
		SDL_Rect rect;

		/* physical resolution is simple */
		SDL_GetDisplayBounds( 0, &rect );

		phys_l = rect.h;
		phys_w = rect.w;

		/* now, work backwards to get the scale, using nominal res */
		if( (f32)phys_w / (f32)INITIAL_NOM_RES_W > 1.0f )
		{
			/* TODO: Dig out the bits of IEEE floating points to create a
			 * 14-bit fraction to store */
		}
	}
	else
	{
		/* Options for initial scale are honored here */
	}

	ret.val->win = SDL_CreateWindow( "dummy", 0, 0, ret.val->nom_res[0],
		ret.val->nom_res[1], (opts.start_fullscr ? SDL_WINDOW_FULLSCREEN : 0)
		| SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALLOW_HIGHDPI );

	if( ret.val->win == NULL )
	{
		return ret;
	}

	ret.val->ren = SDL_CreateRenderer( ret.val->win, -1,
		SDL_RENDERER_ACCELERATED );

	if(ret.val->ren == NULL && !opts.req_hwaccel )
	{
		ret.val->ren = SDL_CreateRenderer( ret.val->win, -1,
			SDL_RENDERER_SOFTWARE );
	}

	if(ret.val->ren == NULL)
	{
		return ret;
	}
}
