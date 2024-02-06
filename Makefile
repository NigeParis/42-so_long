###############################################################################
## ARGUMENTS

NAME= so_long
CFLAGS=  -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
SRCS=$(addprefix $(SRC_DIR), $(SRC))
OBJ=$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
HEAD=$(addprefix $(INCLUDE), $(HEADER))
BONUS_SRC=$(addprefix $(BONUS_DIR), $(BONUS))
BONUS_OBJ=$(addprefix $(BONUS_DIR), $(BONUS:.c=.o))
CC=cc

###############################################################################
## SOURCES 

SRC_DIR=
OBJ_DIR=
BONUS_DIR=
INCLUDE= -I/usr/include -Imlx
SRC= main.c

HEADER=
###############################################################################
## RULES
all: $(NAME)


$(NAME): $(OBJ)
	@echo "Creating FILE .......\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@echo "COMPILE all c files to .o FILES .......\n"
	@$(CC) $(CFLAGS) -c $(SRCS) $(HEAD)


	
clean:
	@rm -f $(SRC_OBJ) $(BONUS_OBJ)

fclean:clean
	@echo "FCLEAN all .o et .a files .......\n"
	@rm -f $(NAME)

re:fclean all
	@echo "All erased and re-compiled .......\n"

.PHONY: all clean fclean re bonus
