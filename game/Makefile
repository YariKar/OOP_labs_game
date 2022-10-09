all: main.o controller.o view.o field.o cell.o player.o mediator.o blind_trap.o eat_energy.o recreate_field.o off_walls.o event_mediator.o
	g++ main.o controller.o view.o field.o cell.o player.o mediator.o blind_trap.o eat_energy.o recreate_field.o off_walls.o event_mediator.o -o game 
main.o: main.cpp
	g++ -c main.cpp 
controller.o: input/controller.cpp
	g++ -c input/controller.cpp
view.o: output/view.cpp
	g++ -c output/view.cpp
cell.o: field/cell.cpp
	g++ -c field/cell.cpp
field.o: field/field.cpp
	g++ -c field/field.cpp
player.o: player/player.cpp
	g++ -c player/player.cpp
mediator.o: different/mediator.cpp
	g++ -c different/mediator.cpp
blind_trap.o: events/blind_trap.cpp
	g++ -c events/blind_trap.cpp
eat_energy.o: events/eat_energy.cpp
	g++ -c events/eat_energy.cpp
recreate_field.o: events/recreate_field.cpp
	g++ -c events/recreate_field.cpp
off_walls.o: events/off_walls.cpp
	g++ -c events/off_walls.cpp
event_mediator.o: different/event_mediator.cpp
	g++ -c different/event_mediator.cpp
clean:
	rm -rf *.o
	clear