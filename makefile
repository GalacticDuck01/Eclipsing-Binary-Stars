
COMPILER = g++ -g

SOURCE_LIBS = -Ilib/ -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

OSX_OPT = -std=c++17

OSX_OUT = -o "bin/build_osx"

CFILES = src/*.cpp

build_osx:
	$(COMPILER) $(CFILES) $(SOURCE_LIBS) $(OSX_OUT) $(OSX_OPT) 

