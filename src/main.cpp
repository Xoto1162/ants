#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "Environment.h"
#include "Renderer.h"
#include <time.h>
#include "utils/Timer.h"
#include "agents/Food.h"
#include "agents/Anthill.h"
#include "agents/ants/SillyAnt.h"
#include "agents/ants/Ant.h"
#include "agents/ants/AntWithRules.h"
#include "AntFactory.h"

static unsigned int windowWidth() { return 1024; }
static unsigned int windowHeight() { return 700; }

/// <summary>
/// called each time a key is pressed.
/// </summary>
/// <param name="key">The key.</param>
/// <param name="environment">The environment.</param>
void onKeyPressed(char key, Environment * environment)
{
	if(key == 'f')
    {
	    new Food(environment, environment->randomPosition(), MathUtils::random(200, 2000));
    }
    if(key == 'a')
    {
        Anthill *a = new Anthill(environment, environment->randomPosition());
        for (int i(0); i < MathUtils::random(40, 60); ++i)
		{
        	new AntWithRules(environment, a);
		}
    }
	if(key == 'd')
    {
		if(!environment->getAllInstancesOf<Food>().empty())
		{
			Food *f = environment->getAllInstancesOf<Food>().front();
			f->collectFood(f->getFoodQuantity());
		}
    }
}

/// <summary>
/// Called at each time step.
/// </summary>
void onSimulate()
{
    Agent::simulate();
}

/// <summary>
/// The main program.
/// </summary>
/// <param name="argc">The number of arguments.</param>
/// <param name="argv">The arguments.</param>
/// <returns></returns>
int main(int /*argc*/, char ** /*argv*/)
{
	// 1 - Initialization of SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS/* | SDL_INIT_AUDIO*/) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	// 2 - Initialization of the renderer
	Renderer::initialize(windowWidth(), windowHeight());

	// 3 - Creation of an environment
	Environment environment(windowWidth(), windowHeight());

	AntFactory::initialize();

	// 4 - We change the seed of the random number generator
	srand((unsigned int)time(NULL));

	// The main event loop...
	SDL_Event event;
	bool exit = false;
	while (!exit)
	{
		// 1 - We handle events
		while (SDL_PollEvent(&event))
		{
			if ((event.type == SDL_QUIT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == 'q'))
			{
				::std::cout << "Exit signal detected" << ::std::endl;
				exit = true;
				break;
			}
			if (event.type == SDL_KEYDOWN)
			{
				onKeyPressed((char)event.key.keysym.sym, &environment);
			}
		}
		// 2 - We update the simulation
		Timer::update(0.5);
		onSimulate();
		// 3 - We render the scene
		Renderer::getInstance()->flush();
	}

	std::cout << "Shutting down renderer..." << std::endl;
	AntFactory::finalize();
	Renderer::finalize();

	std::cout << "Shutting down SDL" << std::endl;
	SDL_Quit();

	Agent::finalize();

	return 0;
}
