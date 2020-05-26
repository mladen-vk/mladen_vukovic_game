main = app.cpp
main_o = app.o

src = Character.cpp Frame.cpp Screen.cpp $(main)
obj = Character.o Frame.o Screen.o $(main_o)

rgame: $(obj)
	g++ -o app $(obj) -lncurses

Character.o: Character.h
Frame.o: Frame.h 
Screen.o: Screen.h
$(main_o): Screen.h Frame.h Character.h

$(obj): $(src)
	g++ -std=c++11 -c $(src)

clean:
	rm $(obj) app
