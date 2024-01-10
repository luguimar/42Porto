/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphicshelper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:20:37 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/20 20:42:46 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	deinitialize_library(struct s_GameState *game_state)
{
	mlx_destroy_image(game_state->mlx, game_state->player1img);
	mlx_destroy_image(game_state->mlx, game_state->wallimg);
	mlx_destroy_image(game_state->mlx, game_state->coin1img);
	mlx_destroy_image(game_state->mlx, game_state->exitimg);
	mlx_destroy_window(game_state->mlx, game_state->mlx_win);
	mlx_destroy_display(game_state->mlx);
	free(game_state->mlx);
	freemapstuff(game_state);
	return (0);
}

void	freemapstuff(struct s_GameState *game_state)
{
	free_map_memory(game_state);
	freemap2(game_state);
	exit(0);
}

int	load_game_images(struct s_GameState *game_state)
{
	int	size;

	size = 100;
	game_state->player1img = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/player.xpm", &size, &size);
	game_state->wallimg = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/img_1.xpm", &size, &size);
	game_state->coin1img = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/img_C.xpm", &size, &size);
	game_state->exitimg = mlx_xpm_file_to_image(game_state->mlx,
			"assets/imgs/img_E.xpm", &size, &size);
	return (0);
}

void	initgamestate(struct s_GameState *game_state)
{
	game_state->mlx = NULL;
	game_state->mlx_win = NULL;
	game_state->col_col = 0;
	game_state->total_collectibles = 0;
	game_state->movements = 0;
	game_state->player_x = -1;
	game_state->player_y = -1;
	game_state->game_is_running = 0;
	game_state->map = NULL;
	game_state->rows = 0;
	game_state->cols = 0;
	game_state->player1img = NULL;
	game_state->wallimg = NULL;
	game_state->coin1img = NULL;
	game_state->exitimg = NULL;
	game_state->maptwo = NULL;
	game_state->lastmappos = NULL;
	game_state->lastx = 0;
	game_state->lasty = 0;
	game_state->valid = 0;
	game_state->pcount = 0;
}
