# Ants

Ants is a student project in first year at the engineering school [ESIR](https://esir.univ-rennes1.fr/).

## Running Ants for the first time

I recommend using visual studio because the dependencies were built for the compiler of visual studio. If you want to use your own compiler, you need to rebuild the different dependencies : SDL2 and SDL2_gfx

- Clone the repository
- Open the project with visual studio `Ants.sln`
- In the menu bar click  `Build < Configuration Manager`, choose Release for the Active solution configuration and choose x86 for the active solution plateform
- In the menu bar click `Build < Build Solution`
- Move the file `lib/SDL2.dll` to the folder `Release`
- Now you can start the app

## Keys

- `F` to add a food spot to a random position
- `A` to add an anthill to a random position

Watch the simulation that take place

![](/screenshot.png)

