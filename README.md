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
