/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygomes-d <ygomes-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:14:56 by ygomes-d          #+#    #+#             */
/*   Updated: 2022/01/16 00:13:14 by ygomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long_bonus.h"

int	key_hook(int keycode, t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->player);
	mlx_clear_window(ptr->mlx, ptr->win);
	if (keycode == W_KEY)
		move_w(ptr);
	if (keycode == S_KEY)
		move_s(ptr);
	if (keycode == D_KEY)
		move_d(ptr);
	if (keycode == A_KEY)
		move_a(ptr);
	if (ptr->count_c == 0 && !ptr->the_end)
	{
		mlx_destroy_image(ptr->mlx, ptr->exit);
		ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "./imgs/exit_open.xpm",
				&ptr->img_w, &ptr->img_h);
	}
	ptr->player = mlx_xpm_file_to_image(ptr->mlx, ptr->path,
			&ptr->img_w, &ptr->img_h);
	map_draw(ptr);
	return (0);
}

int	key_press(int keycode, t_ptr *ptr)
{
	int	move;

	move = ptr->move_count;
	if (keycode == ESC)
		exit_game(ptr);
	else if (!ptr->the_end)
		key_hook(keycode, ptr);
	if (move != ptr->move_count)
		printf("Moves:%d\n", ptr->move_count);
	return (0);
}
