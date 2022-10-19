# RoboSoftEngr-WhereAmI

pgm_map_creator needs the following fixes given the way gazebo works today as opposed to how it did before:

At Line 35, change
```
node->Init(world->Name());
```
to
```
node->Init(world->GetName());
```
AND

At Line 91, change
```
gazebo::physics::PhysicsEnginePtr engine = world->Engine();
```
to
```
gazebo::physics::PhysicsEnginePtr engine = world->GetPhysicsEngine();
```

A demo of the project in action is provided below. Some comments about behavior:

- Provided VM is really buggy and some of the code (pgm map creator above) took forever to fix
- I have been working in my own Ubuntu VM till now because of that and I was not willing to import everything over to the other VM
- Teleop is not functional; I had to either keep sending navigation goals that do not interfer with the environment OR pub to the /cmd_vel topic from command line
- after some time and a lot of lag, the AMCL technique does manage to function as intended

https://user-images.githubusercontent.com/23568809/196527082-284d2636-c7b0-4e28-bd6e-067f94ff152f.mov


https://user-images.githubusercontent.com/23568809/196649976-e0ea7a90-7885-4369-8c1c-7dd6343e6a6e.mov



Screenshot of matching laser scans with the map after convergence

<img width="1440" alt="Screen Shot 2022-10-19 at 1 11 12 PM" src="https://user-images.githubusercontent.com/23568809/196649936-45672fb1-8120-4095-bd82-2f956bba6d2c.png">

