# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:53:25 by arotondo          #+#    #+#              #
#    Updated: 2024/09/04 18:39:23 by arotondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
NAME_BONUS = fdf_bonus

SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj
INC_DIR = include
LIBFT_DIR = libft
MLX_DIR = minilibx_linux

SRC = fdf.c draw.c free.c hooks.c params.c read_file.c views.c
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

BONUS_SRC = fdf_bonus.c draw_bonus.c color_bonus.c free_bonus.c hooks_bonus.c \
			params_bonus.c read_file_bonus.c rotations_bonus.c views_bonus.c
BONUS_OBJ = $(BONUS_SRC:%.c=$(BONUS_OBJ_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)
OFLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/bin -lX11 -lXext -lm -lbsd
LIBS = -L $(LIBFT_DIR) -lft -L $(MLX_DIR)

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) $(OFLAGS)
	@echo "${GREEN}Compilation of $(NAME) done.${DEF_COLOR}"

bonus: $(NAME_BONUS)
$(NAME_BONUS): $(BONUS_OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBS) -o $(NAME_BONUS) $(OFLAGS)
	@echo "${GREEN}Compilation of $(NAME_BONUS) done.${DEF_COLOR}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fdf.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(INC_DIR)/fdf.h | $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	# @make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "${GREEN}Files clean up done.{DEF_COLOR}"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	# @make -C $(MLX_DIR) fclean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@echo "${GREEN}Clean up done.{DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re bonus