/****************************************************************************\
 *                            Carta™ GUI Library                            *
 *                                                                          *
 *                         Copyright © 2020 Aquefir                         *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__CARTA_DISPDRV_H
#define INC_API__CARTA_DISPDRV_H

#include <uni/option.h>
#include <uni/types/int.h>

#include "common.h"

struct carta_disp;

UNI_DECL_OPT_SP( carta_disp );

struct carta_disp_initopts
{
	u16 scale_num;
	u16 scale_den;
	u16 start_fullscr : 1;
	u16 req_hwaccel : 1;
	u16 aspratio_num : 7;
	u16 aspratio_den : 7;
};

CARTA_API UNI_OPTIONP( carta_disp ) carta_disp_init(
	struct carta_disp_initopts );
CARTA_API void carta_disp_fini( struct carta_disp* );

CARTA_API int carta_is_scale_even( struct carta_disp* );
CARTA_API int carta_is_fullscr( struct carta_disp* );
CARTA_API int carta_is_hwaccel( struct carta_disp* );
CARTA_API u32 carta_get_nom_res_l( struct carta_disp* );
CARTA_API u32 carta_get_nom_res_w( struct carta_disp* );
CARTA_API u32 carta_get_phys_res_l( struct carta_disp* );
CARTA_API u32 carta_get_phys_res_w( struct carta_disp* );
CARTA_API s32 carta_get_win_x( struct carta_disp* );
CARTA_API s32 carta_get_win_y( struct carta_disp* );

#endif /* INC_API__CARTA_DISPDRV_H */
