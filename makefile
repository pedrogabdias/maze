##############################################################################
# Exemplo de makefile para um projeto C++ com OpenGL/freeglut
# Para simplificar, todos os arquivos estão em um mesmo diretório
##############################################################################
# Arquivo principal: labirinto.cpp
##############################################################################


# definição de variáveis auxiliares do makefile
MAIN = labirinto
OBJECTS	= $(MAIN).o
FLAGS = -Wall -Wextra -std=c++23 -pedantic-errors
DEBUG = -g
CC = g++

# Identificação do sistema operacional
ifeq ($(OS),Windows_NT)
    # Configurações para Windows
    OPENGL_FLAG = -lopengl32 -lglu32 -lfreeglut
    RM = rm
    EXE = .exe
else
    # Configurações para Linux (Ubuntu)
    OPENGL_FLAG = -lGL -lGLU -lglut
    MATH = -lm # pode ser necessário para uso das funções matemáticas (sin, cos, sqrt, etc.)
    RM = rm -rf
    EXE = .out
endif

# regra de compilação do projeto completo
all: $(MAIN)$(EXE)

# regra para geração do arquivo executavel
$(MAIN)$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(MAIN)$(EXE) $(FLAGS) $(OPENGL_FLAG) $(MATH)

# regra de compilação do objeto main.o
$(MAIN).o: $(MAIN).cpp
	$(CC) -c $(MAIN).cpp -o $(MAIN).o $(FLAGS)

# regra para limpeza do projeto (excluir arquivos .o e executáveis)
clean:
	$(RM) $(OBJECTS) $(MAIN)$(EXE)

# regra para compilar todo o projeto (se necessário) e, posteriormente, executar
run: all
	./$(MAIN)$(EXE)
