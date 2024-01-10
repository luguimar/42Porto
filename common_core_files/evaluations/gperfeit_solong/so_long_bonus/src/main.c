/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:26:53 by gperfeit          #+#    #+#             */
/*   Updated: 2023/05/20 20:43:18 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	createmapdois(struct s_GameState *game_state)
{
	int	i;
	int	j;

	i = 0;
	game_state->maptwo = NULL;
	game_state->maptwo = malloc(sizeof(char *) * (game_state->rows + 1));
	while (i < game_state->rows)
	{
		j = 0;
		game_state->maptwo[i] = malloc(sizeof(char) * (game_state->cols + 1));
		while (j < game_state->cols)
		{
			game_state->maptwo[i][j] = game_state->map[i][j];
			j++;
		}
		i++;
	}
}

void	freemap2(struct s_GameState *game_state)
{
	int	i;

	i = 0;
	while (i < game_state->rows)
	{
		free(game_state->maptwo[i]);
		i++;
	}
	free(game_state->maptwo);
}

int	validate_args(int argc, char *argv[])
{
	char	*map_file;

	map_file = argv[1];
	if ((argc < 2))
	{
		ft_printf("Error\nProvide mapname.ber as an argument.\n");
		return (1);
	}
	if (strstr(map_file, ".ber") == NULL)
	{
		ft_printf("Error\nInvalid map file. Must end with .ber\n");
		return (1);
	}
	return (0);
}

void	free_map_memory(struct s_GameState *game_state)
{
	int	j;

	j = 0;
	while (j < game_state->rows)
	{
		free(game_state->map[j]);
		j++;
	}
	free(game_state->map);
}

int	main(int argc, char *argv[])
{
	struct s_GameState	game_state;

	initgamestate(&game_state);
	if (validate_args(argc, argv) != 0)
	{
		return (1);
	}
	game_state.map = read_map_file(argv[1], &game_state);
	createmapdois(&game_state);
	if (game_state.map == NULL)
	{
		return (1);
	}
	game_state.game_is_running = 1;
	initialize_game_data(&game_state);
	map_validator(&game_state);
	initialize_library(&game_state);
	ft_printf("Game over!\n");
	freemapstuff(&game_state);
	return (0);
}
