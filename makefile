# Object files to either reference or create
# SOURCES=main.cpp FANode.cpp FARenderPass.cpp FAEngine.cpp FAScene.cpp FAModel.cpp FAMaterial.cpp FAMaterialComponent.cpp FAMesh.cpp FACamera.cpp FAShader.cpp Game.cpp testScene.cpp FAFont.cpp FAText.cpp FAHUDElement.cpp
SOURCESENGINE=$(wildcard src/FireArrowEngine/*.cpp)
SOURCEFILESENGINE = $(SOURCESENGINE:src/FireArrowEngine/%=%)

SOURCESGAME=$(wildcard src/*.cpp)
SOURCEFILESGAME = $(SOURCESGAME:src/%=%)

# The executable file that will be created
EXEC = main.exe
# The c++ flags to use for compilation
CXXFLAGS = -Wall
# The c++ compiler to use for compilation
CC = clang++

ENGINESDIR=src/FireArrowEngine/
GAMESDIR=src/
ODIR=build
ENGINEOBJECTS = $(addprefix $(ODIR)/, $(SOURCEFILESENGINE:.cpp=.o))
GAMEOBJECTS = $(addprefix $(ODIR)/, $(SOURCEFILESGAME:.cpp=.o))
lIBDIR=lib/
IDIR=include/

#LIB=-lglfw3 -lIL -ltiff -lpng16 -lz -ljasper -ljpeg -llzma -lfreetype -lbz2 -lmng -llcms
LIB=

#OSX frameworks
#FRAMEWORKS=-framework IOKit -framework Cocoa -framework OpenGL -framework CoreVideo
FRAMEWORKS=


# This section is called on 'make'
# Will call compile, and then call clean
all: $(GAMEOBJECTS) build/FireArrow.a
	$(CC) -L $(lIBDIR) -m32 -std=c++11 -o $(EXEC) $^ $(FRAMEWORKS) $(LIB)

build/FireArrow.a: $(ENGINEOBJECTS)
	ar rvs build/FireArrow.a $^

$(ODIR)/%.o: $(GAMESDIR)/%.cpp
	$(CC) -I $(IDIR) -m32 -std=c++11 -Wno-c++11-long-long -Wall -c -o $@ $<

$(ODIR)/%.o: $(ENGINESDIR)/%.cpp
	$(CC) -I $(IDIR) -m32 -std=c++11 -Wno-c++11-long-long -Wall -c -o $@ $<

clean:
	rm -f $(ODIR)/*.o
	rm -f $(ODIR)/*.a
	rm $(EXEC)
