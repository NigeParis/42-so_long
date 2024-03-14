###############################################################################
## ARGUMENTS

NAME= so_long
CFLAGS=  -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
HEAD=$(addprefix $(INCLUDE), $(HEADER))

CC=cc

###############################################################################
## SOURCES 

SRC_DIR=
OBJ_DIR=
INCLUDE= -I/usr/include -Imlx
SRC= ./src/main.c   ./src/player.c ./src/player_move.c ./src/get_next_line.c \
	 ./src/get_next_line_utils.c ./src/mapcheck_utils.c ./src/mapcheck.c \
	 ./src/map_render.c ./src/map_exit.c
HEADER= 
###############################################################################
## RULES
all: $(NAME)


$(NAME): $(OBJ)
	@echo "Creating FILE .......\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ./libft.a ./libftprintf.a $(MLX_FLAGS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@echo "COMPILE all c files to .o FILES .......\n"
	@$(CC) $(CFLAGS) -c $(SRCS)  $(HEAD)


	
clean:
	@rm -f $(OBJ)

fclean:clean
	@echo "FCLEAN all .o et .a files .......\n"
	@rm -f $(NAME)

re:fclean all
	@echo "All erased and re-compiled .......\n"

.PHONY: all clean fclean re bonus
