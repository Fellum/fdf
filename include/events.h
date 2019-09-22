//
// Created by Jasper Leann on 22/09/2019.
//

#ifndef FDF_EVENTS_H
#define FDF_EVENTS_H

#include "params.h"

int draw_tick(t_gparams *param);
int	close_event(void *param);
int	key_release(int keycode, void *param);
int	key_press(int keycode, void *param);

#endif //FDF_EVENTS_H
