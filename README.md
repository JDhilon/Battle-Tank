# Battle-Tank
Open world head-to-head tank battle, with simple AI, terrain, and advanced control in UE4

## Controls

### Keyboard: 

* Movement with WASD

* Aim with Mouse

* Left Mouse Button to fire

* E to switch between first or third person camera

### Gamepad: 

* Move with Right Thumbstick

* Aim with Left Thumbstick

* Bottom Face Button to Fire

* Top Face Button to switch between first or third person camera


### TODO List for project

* Sort out public vs protected vs private for all member variables and function

* Initialize as many values for components in C++ as possible as Blueprint keeps experiencing glitches (Values such as Collisions Enabled, Dampings, Etc)

* Setup MainMenu Start button to spawn/possess a Tank instead of having Tank_BP be default pawn from start

* Add mortars into level that can attack either type of tank or both AI and Player

* Documents complex methods for reusability and understandability. Refactor where needed

* Creates a pause/end game menu

* Make a FFA game mode with various tanks, respawns, and scoreboard

* Create different type of projectiles

* Add a system to highlight where hit will occur on the world itself (Useful for different attack types)
