NAME = inquirer

CXX := $(if $(DEFAULT_CXX),$(DEFAULT_CXX), $(CXX))
CXXFLAGS = -static

OBJ = main.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(LINK.cpp) $(OBJ) -o $(NAME)

clean:
	@rm -f $(NAME)
