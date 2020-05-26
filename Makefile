main = app.cpp
main_o = app.o

src = Character.cpp Frame.cpp Screen.cpp gameloop.cpp $(main)
obj = Character.o Frame.o Screen.o gameloop.o $(main_o)

app: $(obj)
	g++ -o app $(obj) -lncurses

Character.o: Character.h
Frame.o: Frame.h 
Screen.o: Screen.h
gameloop.o: gameloop.h
$(main_o): Screen.h Frame.h Character.h gameloop.h

$(obj): $(src)
	g++ -std=c++11 -c $(src)

clean:
	rm $(obj) app
