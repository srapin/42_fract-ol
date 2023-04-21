# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 22:16:42 by srapin            #+#    #+#              #
#    Updated: 2023/04/13 23:54:50 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

FILES = fractol\
		app\
		args_managment\
		check_arg\
		color\
		color_annex\
		complex_tools\
		convert\
		hooks_no_event\
		hooks\
		main\
		mlx_tools\
		print

SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))

OBJS_DIR = obj
OBJS = ${patsubst ${SRCS_DIR}/%.c, ${OBJS_DIR}/%.o, ${SRCS}}

LIBS_FOLDER = libs

LIBSR_DIR = libft
LIBSR = $(LIBS_FOLDER)/$(LIBSR_DIR)/libft.a

MLX_DIR = minilibx-linux/
MLX = ./$(LIBS_FOLDER)/$(MLX_DIR)/libmlx_Linux.a

LIBS = $(MLX) $(LIBSR)

INCLUDES_DIR = includes
INCLUDES_FILES = fractol.h
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(OBJS) $(LIBS) -lm -lXext -lX11 -g -o $@

bonus: $(NAME)

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c 
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean: cleanlibs
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all

$(LIBS):
	make -C $(LIBS_FOLDER)/$(MLX_DIR)
	make -C $(LIBS_FOLDER)/$(LIBSR_DIR)

cleanlibs:
	make fclean -C $(LIBS_FOLDER)/$(LIBSR_DIR)
	make clean -C $(LIBS_FOLDER)/$(MLX_DIR)

.PHONY: all clean fclean re makelib cleanlib
