NAME = fdf
SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR = ./objs
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
INC_DIR	:= include
LIBFT_DIR = libft
LIBFT_INC_DIR = $(LIBFT_DIR)/include

MLX_LIB = -L /usr/local/lib/ -lmlx
MLX_HEAD = -I /usr/local/include
FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc -Wall -Werror -Wextra -I$(LIBFT_INC_DIR) -I$(INC_DIR) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR)
	@gcc -Wall -Werror -Wextra $(MLX_HEAD) -L $(LIBFT_DIR) -l ft -o $(NAME) $(OBJ) -I$(LIBFT_INC_DIR) -I$(INC_DIR) $(MLX_LIB) $(FRAMEWORK)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	@make -C $(LIBFT_DIR) fclean

re: fclean all