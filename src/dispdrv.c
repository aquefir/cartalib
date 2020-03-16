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
#include <tes/program.h>
#include <uni/option.h>
#include <uni/types/vec.h>

#define INITIAL_NOM_RES_W 640
#define INITIAL_NOM_RES_L 360

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
		phys_l = INITIAL_NOM_RES_L * 2;
		phys_w = INITIAL_NOM_RES_W * 2;
	}

	ret.val->win = SDL_CreateWindow( "dummy",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		phys_w,
		phys_l, (opts.start_fullscr ? SDL_WINDOW_FULLSCREEN : 0)
		| SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALLOW_HIGHDPI );

	if( ret.val->win == NULL )
	{
		free( ret.val );
		ret.val = NULL;

		return ret;
	}

	ret.val->ren = SDL_CreateRenderer( ret.val->win, -1,
		SDL_RENDERER_ACCELERATED );
	ret.val->hwaccel = 1;

	if(ret.val->ren == NULL && !opts.req_hwaccel )
	{
		ret.val->ren = SDL_CreateRenderer( ret.val->win, -1,
			SDL_RENDERER_SOFTWARE );
		ret.val->hwaccel = 0;
	}

	if(ret.val->ren == NULL)
	{
		SDL_DestroyWindow( ret.val->win );
		free( ret.val );
		ret.val = NULL;

		return ret;
	}

	ret.is = 1;

	return ret;
}

void carta_disp_fini( struct carta_disp* d )
{
	SDL_DestroyRenderer( d->ren );
	SDL_DestroyWindow( d->win );
	free( d );
}
