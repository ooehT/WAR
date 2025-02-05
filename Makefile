# Nome do compilador
CXX = g++

# Flags do compilador
CXXFLAGS = -Wall -Wextra -std=c++17

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Nome do executável
TARGET = $(BIN_DIR)/war_game

# Arquivos fonte e objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Regra principal
all: criar_dirs $(TARGET)

# Compilação do executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilação dos arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar diretórios se não existirem (compatível com Windows e Linux)
criar_dirs:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Limpeza completa + arquivos temporários
cleanall: clean
	rm -f *~ src/*~ obj/*~ bin/*~
