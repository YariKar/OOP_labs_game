all: main.o game.o controller.o view.o field.o cell.o player.o mediator.o blind_trap.o eat_energy.o recreate_field.o off_walls.o event_mediator.o tracked_object.o observer.o message.o log_file.o log_console.o direct_transform.o menu_view.o file_reader.o level_one.o level_two.o caretaker.o file_saver.o field_memento.o player_memento.o file_load_exeption.o game_load_exeption.o
	g++ object_files/main.o object_files/game.o object_files/controller.o object_files/view.o object_files/field.o object_files/cell.o object_files/player.o object_files/mediator.o object_files/blind_trap.o object_files/eat_energy.o object_files/recreate_field.o object_files/off_walls.o object_files/event_mediator.o object_files/tracked_object.o object_files/observer.o  object_files/message.o object_files/log_file.o object_files/log_console.o object_files/direct_transform.o object_files/menu_view.o object_files/file_reader.o object_files/level_one.o object_files/level_two.o object_files/caretaker.o object_files/file_saver.o object_files/field_memento.o object_files/player_memento.o object_files/file_load_exeption.o object_files/game_load_exeption.o -o game 
ready:
	g++ object_files/main.o object_files/game.o object_files/controller.o object_files/view.o object_files/field.o object_files/cell.o object_files/player.o object_files/mediator.o object_files/blind_trap.o object_files/eat_energy.o object_files/recreate_field.o object_files/off_walls.o object_files/event_mediator.o object_files/tracked_object.o object_files/observer.o  object_files/message.o object_files/log_file.o object_files/log_console.o object_files/direct_transform.o object_files/menu_view.o object_files/file_reader.o object_files/level_one.o object_files/level_two.o object_files/caretaker.o object_files/file_saver.o object_files/field_memento.o object_files/player_memento.o object_files/file_load_exeption.o object_files/game_load_exeption.o -o game 
main.o: main.cpp
	g++ -c main.cpp -o object_files/main.o
controller.o: input/controller.cpp 
	g++ -c input/controller.cpp -o object_files/controller.o
view.o: output/view.cpp 
	g++ -c output/view.cpp -o object_files/view.o
cell.o: field/cell.cpp
	g++ -c field/cell.cpp -o object_files/cell.o
field.o: field/field.cpp
	g++ -c field/field.cpp -o object_files/field.o
player.o: player/player.cpp
	g++ -c player/player.cpp -o object_files/player.o
mediator.o: different/mediator.cpp
	g++ -c different/mediator.cpp -o object_files/mediator.o
blind_trap.o: events/blind_trap.cpp
	g++ -c events/blind_trap.cpp -o object_files/blind_trap.o
eat_energy.o: events/eat_energy.cpp
	g++ -c events/eat_energy.cpp -o object_files/eat_energy.o
recreate_field.o: events/recreate_field.cpp
	g++ -c events/recreate_field.cpp -o object_files/recreate_field.o
off_walls.o: events/off_walls.cpp
	g++ -c events/off_walls.cpp -o object_files/off_walls.o
event_mediator.o: different/event_mediator.cpp
	g++ -c different/event_mediator.cpp -o object_files/event_mediator.o
tracked_object.o: logging/tracked_object.cpp
	g++ -c logging/tracked_object.cpp -o object_files/tracked_object.o
observer.o: logging/observer.cpp
	g++ -c logging/observer.cpp -o object_files/observer.o
game.o: game.cpp
	g++ -c game.cpp -o object_files/game.o
message.o: logging/message.cpp
	g++ -c logging/message.cpp -o object_files/message.o
log_file.o: logging/concrete_logs/log_file.cpp
	g++ -c logging/concrete_logs/log_file.cpp -o object_files/log_file.o
log_console.o: logging/concrete_logs/log_console.cpp
	g++ -c logging/concrete_logs/log_console.cpp -o object_files/log_console.o
direct_transform.o: directorate/direct_transform.cpp
	g++ -c directorate/direct_transform.cpp -o object_files/direct_transform.o
menu_view.o: output/menu_view.cpp
	g++ -c output/menu_view.cpp -o object_files/menu_view.o
file_reader.o: directorate/file_reader.cpp
	g++ -c directorate/file_reader.cpp -o object_files/file_reader.o
level_one.o: generate/levels/level_one.cpp
	g++ -c generate/levels/level_one.cpp -o object_files/level_one.o
level_two.o: generate/levels/level_two.cpp
	g++ -c generate/levels/level_two.cpp -o object_files/level_two.o
caretaker.o: saving/caretaker/caretaker.cpp
	g++ -c saving/caretaker/caretaker.cpp -o object_files/caretaker.o
file_saver.o: saving/caretaker/file_saver.cpp
	g++ -c saving/caretaker/file_saver.cpp -o object_files/file_saver.o
field_memento.o: saving/memento/field_memento.cpp
	g++ -c saving/memento/field_memento.cpp -o object_files/field_memento.o 
player_memento.o: saving/memento/player_memento.cpp
	g++ -c saving/memento/player_memento.cpp -o object_files/player_memento.o
file_load_exeption.o: exeptions/file_load_exeption.cpp
	g++ -c exeptions/file_load_exeption.cpp -o object_files/file_load_exeption.o
game_load_exeption.o: exeptions/game_load_exeption.cpp
	g++ -c exeptions/game_load_exeption.cpp -o object_files/game_load_exeption.o
clean:
	rm -rf object_files/*.o
	clear