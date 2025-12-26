# Nom de l'executable final
TARGET = programaClara.exe

# Compilador i opcions
CXX = g++
CXXFLAGS = -std=c++11 -I. -I"C:/odb/include" -I"C:/boost/boost_1_90_0" -Wall -Wextra

# Llibreries ODB i MySQL
LIBS = -lodb -lodb-mysql -lodb-boost -lboost_date_time

# Fitxers font
SRC = \
    CapaDePresentacio.cxx \
    CtrlConsultaUsuari.cxx \
    CtrlModificaUsuari.cxx \
    CtrlRegistreUsuari.cxx \
    CtrlEsborraUsuari.cxx \
    DAOUsuari.cxx \
    DTOUsuari.cxx \
    usuari.cxx \
    mainClara.cc

# Fitxers objecte
OBJ = $(SRC:.cxx=.o)
OBJ := $(OBJ:.cpp=.o)

# Regla per compilar tot
all: $(TARGET)

# Compilació de l'executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Compilació de fitxers .cxx
%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilació de fitxers .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Neteja
clean:
	del /Q $(OBJ) 2>nul
	del /Q $(TARGET) 2>nul
