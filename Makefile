###############################################################################
## ARGUMENTS

NAME= so_long
CFLAGS=  -Wall -Wextra -Werror -g3
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 
SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
HEAD=$(addprefix $(INCLUDE), $(HEADER))

CC=cc

###############################################################################
## SOURCES 

SRC_DIR=
OBJ_DIR=
INCLUDE= -I./usr/include -Imlx
SRC= ./src/main.c   ./src/player.c ./src/player_move.c ./src/get_next_line.c \
	 ./src/get_next_line_utils.c ./src/mapcheck_utils.c ./src/mapcheck.c \
	 ./src/map_render.c ./src/map_exit.c ./src/map_get.c ./src/map_get_utils.c\
	 ./src/map_path_check.c
LIBFT= ./libft/libft.a
FT_PRINTF=./ft_printf/libftprintf.a
HEADER=

###############################################################################
## RULES

all: $(NAME)


$(NAME): $(OBJ)
	@echo "Creating FILE .......\n"
	@make -C ./mlx/ all
	@make -C ./libft/ all
	@make -C ./ft_printf/ all

	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)  $(MLX_FLAGS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@echo "COMPILE all c files to .o FILES .......\n"

	@$(CC) $(CFLAGS) -c $(SRCS)  $(HEAD)

lib:
	@make -C ./ft_printf/ re
	@make -C ./libft/ re
	@make -C ./mlx/ re

libclean:
	@make -C ./ft_printf/ clean
	@make -C ./libft/ clean

libfclean:
	@make -C ./ft_printf/ fclean
	@make -C ./libft/ fclean
	@make -C ./mlx/ clean

clean: libclean
	@rm -f $(OBJ)

fclean:clean libfclean
	@echo "FCLEAN all .o et .a files .......\n"
	@rm -f $(NAME)

re: fclean libfclean lib all

	@echo "All erased and re-compiled .......\n"


.PHONY: all lib libclean clean fclean re bonus
