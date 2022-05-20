NAME	=	libmlx.a

ifeq ($(OS),Darwin)
	#MacOS stuff
	MAKEDIR = ./macos/
else
	#Linux stuff
	MAKEDIR = ./linux/
endif

MAKECOM	=	make -C $(MAKEDIR)

all: $(NAME)

$(NAME):
		$(MAKECOM) all
		cp $(MAKEDIR)$(NAME) ./$(NAME)

clean:
		rm -rf $(NAME)
		$(MAKECOM) clean

re: clean all
