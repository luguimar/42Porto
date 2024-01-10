
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "mlx_linux/mlx.h"

# include "./libft/libft/libft.h"

# define X_EVENT_KEY_PRESS		2
# define SIZE                   50
# define X_EVENT_KEY_EXIT		17
# define BUFFER_SIZE            42
# define SPRITE_H				64
# define SPRITE_W				64

# ifdef __linux__
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define ESC					65307
# elif __APPLE__
#  include "../mlx-macos/mlx.h"
#  define OS "macos"
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define ESC 					53
# endif

#endif