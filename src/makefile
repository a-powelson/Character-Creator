COMPILER = g++

out.exe: MainMenu.cpp Character.o Pet.o Menu.o
	$(COMPILER) MainMenu.cpp Character.o Pet.o Menu.o -o out.exe

Menu.o: Menu.cpp Menu.h
	$(COMPILER) -c Menu.cpp

Pet.o: Pet.cpp Pet.h
	$(COMPILER) -c Pet.cpp

Character.o: Character.cpp Character.h
	$(COMPILER) -c Character.cpp

# Try del for Windows users
clean:
	-rm Character.o Pet.o Menu.o out.exe
	-del Character.o Pet.o Menu.o out.exe