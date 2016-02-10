CPP=g++

OBJS = app.o mainfram.o
LIBS = -lwx -lgtk -lgdk -lglib -lX11 -lXext -ldl
DEFS = -D__WXGTK__

all kreuzeln: $(OBJS) kreuzeln.cpp Makefile
	$(CPP) -o kreuzeln kreuzeln.cpp $(DEFS)  $(OBJS) $(LIBS)


%.o:
	$(CPP) $< -c $(DEFS)

app.o: app.cpp app.hpp mainfram.o
mainfram.o: mainfram.cpp mainfram.hpp 