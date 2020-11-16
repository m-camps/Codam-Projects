/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_function.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mcamps <mcamps@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 17:06:10 by mcamps        #+#    #+#                 */
/*   Updated: 2020/10/08 19:01:50 by mcamps        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define ESC 53
#define FRW 13
#define BCKW 1
#define LEFT 0
#define RIGHT 2
#define ROT_L 123
#define ROT_R 124

int		exit_hook(t_meta_data *meta)
{
	ft_putstr("Closing program...\n");
	exit(0);
	meta->map.res_y = 1;
	return (0);
}

int		keypress_hook(int keycode, t_meta_data *meta)
{
	if (keycode == ESC)
		exit_hook(meta);
	if (keycode == FRW && meta->move.backward != 1)
		meta->move.forward = 1;
	if (keycode == BCKW && meta->move.forward != 1)
		meta->move.backward = 1;
	if (keycode == LEFT && meta->move.right != 1)
		meta->move.left = 1;
	if (keycode == RIGHT && meta->move.left != 1)
		meta->move.right = 1;
	if (keycode == ROT_L && meta->move.rot_r != 1)
		meta->move.rot_l = 1;
	if (keycode == ROT_R && meta->move.rot_l != 1)
		meta->move.rot_r = 1;
	return (0);
}

int		keyrelease_hook(int keycode, t_meta_data *meta)
{
	if (keycode == FRW)
		meta->move.forward = 0;
	if (keycode == BCKW)
		meta->move.backward = 0;
	if (keycode == LEFT)
		meta->move.left = 0;
	if (keycode == RIGHT)
		meta->move.right = 0;
	if (keycode == ROT_L)
		meta->move.rot_l = 0;
	if (keycode == ROT_R)
		meta->move.rot_r = 0;
	return (0);
}
