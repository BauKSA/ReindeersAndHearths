#include "Dependencies.h"
#include "Test.h"

#include "GlobalSystem.h"
#include "MemoryManager.h"
#include "Observer.h"
#include "Present.h"
#include "Igniter.h"
#include "LevelManager.h"
#include "IgniterSpawner.h"
#include "Garbage.h"

int main(int argc, char** argv) {
	AllegroManager* alManager = new AllegroManager;
	alManager->init();

	if (alManager->failed()) {
		delete alManager;
		return -1;
	}

	float last_frame_time = al_get_time();
	bool running = true;

	//------------
	//TESTING INIT
	//------------
	Player* test_player = initialize_test();
	InputSystem* test_input = initialize_input();
	test_input->start_listening();

	al_clear_to_color(al_map_rgb(255, 255, 255));
	test_player->draw();
	al_flip_display();

	std::vector<BaseActor*> bricks = initialize_bricks();
	std::vector<Hearth*> hearths = initialize_hearths();
	BaseActor* tree = initialize_tree();

	SpriteActor* title = initialize_title();

	Reindeer* reindeer = initialize_reindeer();
	//------------
	//TESTING  END
	//------------

	//TESTEO BACKGROUND
	AnimationPaths back;
	back.name = "defaukt";
	back.paths = {
		"./sprites/background/background-a.png",
		"./sprites/background/background-b.png",
		"./sprites/background/background-c.png",
		"./sprites/background/background-d.png"
	};

	AnimatedActor* background = new AnimatedActor("background", 0, 0, 0, IGNORE);
	background->initialize({ back });

	//Components
	GravityComponent* gravity = new GravityComponent();
	JumpComponent* jump = new JumpComponent();

	test_player->add_component(gravity);
	test_player->add_component(jump);

	//Systems
	TickSystem* tick_system = new TickSystem();
	tick_system->add_actor(background);

	for (size_t i = 0; i < hearths.size(); i++) {
		tick_system->add_actor(hearths.at(i));
	}


	tick_system->add_actor(reindeer);
	tick_system->add_actor(test_player);

	IgniterSpawner& spawner = IgniterSpawner::instance();

	CollisionSystem* collision_system = new CollisionSystem();
	collision_system->add_actor(test_player);
	collision_system->add_actor(tree);

	for (size_t i = 0; i < bricks.size(); i++) {
		collision_system->add_actor(bricks.at(i));
	}
	for (size_t i = 0; i < hearths.size(); i++) {
		collision_system->add_actor(hearths.at(i));
	}

	//Garbage TEST
	Garbage::instance();

	//Configuramos el MemoryManager
	MemoryManager::add_system(tick_system);
	MemoryManager::add_system(collision_system);

	ALLEGRO_BITMAP* screen = al_create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);

	GenericCommand* command{};
	InputHandler* handler = new InputHandler(test_player, &running);

	//Observer
	Observer& obs = Observer::instance();
	obs.configure(collision_system, tick_system);

	//LevelManager
	LevelManager& lvl_manager = LevelManager::instance();

	//Global
	GlobalSystem* global = new GlobalSystem(test_player);

	while (running) {
		al_set_target_bitmap(screen);
		al_clear_to_color(al_map_rgb(0, 0, 0));

		title->draw();

		float current_time = al_get_time();
		float delta_time = current_time - last_frame_time;

		// Debug: detectar fluctuaciones altas o bajas en delta_time
		if (delta_time > 0.1f) {
			std::cerr << "[WARNING] delta_time alto detectado: " << delta_time << " segundos. Posible lag." << std::endl;
		}
		else if (delta_time < 0.0001f) {
			std::cerr << "[WARNING] delta_time extremadamente bajo: " << delta_time << " segundos. Posible error de cálculo." << std::endl;
		}

		delta_time = std::min(delta_time, 0.066f);
		last_frame_time = current_time;

		command = test_input->listen();
		if (command) handler->check(command);

		tick_system->update(delta_time);
		IgniterSpawner::instance().tick(delta_time);
		collision_system->update();

		for (size_t i = 0; i < bricks.size(); i++) {
			bricks.at(i)->draw();
		}

		tree->draw();

		for (size_t i = 0; i < hearths.size(); i++) {
			if (hearths.at(i)->get_name() == "head-1" || hearths.at(i)->get_name() == "head-2") {
				hearths.at(i)->draw();
			}
		}


		global->draw();


		alManager->draw_to_display(screen);

		Garbage::instance().clean();

		// Asegurar que el frame rate no exceda un máximo (ejemplo: 60 FPS)
		float frame_time = al_get_time() - current_time;
		if (frame_time < (1.0f / 60.0f)) {
			al_rest((1.0f / 60.0f) - frame_time);  // Pausa para limitar a 60 FPS
		}
	}

	test_input->stop_listening();

	return 0;
}