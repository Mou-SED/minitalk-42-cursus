# ******************************** Directories *********************************
INCLUDES_DIR	:= include
CSRCS_DIR		:= src/client
SSRCS_DIR		:= src/server
OBJS_DIR		:= obj

# *********************************** Files ************************************
HEADERS	:= $(shell ls $(INCLUDES_DIR))

CNAME	:= client
CMAIN	:= client.c
CSRCS	:= $(shell ls $(CSRCS_DIR))
COBJS	:= $(CSRCS:.c=.o)

SNAME	:= server
SMAIN	:= server.c
SSRCS	:= $(shell ls $(SSRCS_DIR))
SOBJS	:= $(SSRCS:.c=.o)

# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INCLUDES	:= -I $(INCLUDES_DIR)

# ******************************* Other commands *******************************
RM		:= rm -rf
MKDIR	:= mkdir -p

# ********************************** Targets ***********************************
all: $(CNAME) $(SNAME)

$(CNAME): $(addprefix $(OBJS_DIR)/, $(COBJS)) $(CMAIN) $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	$(CC) $(CFLAGS) $(INCLUDES) $(addprefix $(OBJS_DIR)/, $(COBJS)) $(CMAIN) -o $(CNAME)

$(SNAME): $(addprefix $(OBJS_DIR)/, $(SOBJS)) $(SMAIN) $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	$(CC) $(CFLAGS) $(INCLUDES) $(addprefix $(OBJS_DIR)/, $(SOBJS)) $(SMAIN) -o $(SNAME)

$(OBJS_DIR)/%.o: $(CSRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	@$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJS_DIR)/%.o: $(SSRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	@$(MKDIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(CNAME)
	$(RM) $(SNAME)

re: fclean all

.PHONY: all clean fclean re
