/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:20:32 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/13 22:45:41 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_game_volume_dois(struct s_GameState *game_state)
{
	int	i;
	int	j;

	i = 0;
	while (i < game_state->rows)
	{
		j = 0;
		while (j < game_state->cols)
		{
			if (game_state->map[i][j] == '1')
				mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
					game_state->wallimg, j * 100, i * 100);
			if (game_state->map[i][j] == 'C')
				mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
					game_state->coin1img, j * 100, i * 100);
			if (game_state->map[i][j] == 'E')
				mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
					game_state->exitimg, j * 100, i * 100);
			j++;
		}
		i++;
	}
}

int	render_game(struct s_GameState *game_state)
{
	static int	frames = 0;

	if (++frames < 9000)
		return (0);
	frames = 0;
	mlx_clear_window(game_state->mlx, game_state->mlx_win);
	render_game_volume_dois(game_state);
	mlx_put_image_to_window(game_state->mlx, game_state->mlx_win,
		game_state->player1img, game_state->player_x * 100,
		game_state->player_y * 100);
	return (0);
}

void	initialize_library(struct s_GameState *game_state)
{
	int	size;

	size = 100;
	game_state->mlx = mlx_init();
	game_state->mlx_win = mlx_new_window(game_state->mlx,
			game_state->cols * size, game_state->rows * size, "so_long");
	load_game_images(game_state);
	mlx_hook(game_state->mlx_win, 2, 1L << 0, key_press, game_state);
	mlx_hook(game_state->mlx_win, 17, 1L << 17, deinitialize_library,
		game_state);
	mlx_loop_hook(game_state->mlx, render_game, game_state);
	mlx_loop(game_state->mlx);
}
