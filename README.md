# Project Description 



Abdisa Haji (haji0051), Farahan Idris (idris034), Moyata Ebisso (ebiss001)
Team Number: 001-40

What is the project about: This project allows the user to control the behavior of drones picking up robots and basketballs and dropping them off at different locations. There are other vehicles in the simulation like a car and a helicopter, and you can add helicopters by pressing on the button. 

## How to run: 

1) SSH into a CSE Lab Machine using port forwarding for the UI (Note: If port 8081 is not available, choose a different port (e.g. 8082, 8083, etc...)
	ssh -L 8081:127.0.0.1:8081 x500@csel-xxxx.cselabs.umn.edu

2) Go to the project directory

**cd /path/to/repo/project**

3) Build the project:

make clean
make -j

4) Run the project:
**./build/bin/transit_service 8081 apps/transit_service/web/**

5) Navigate to http://127.0.0.1:8081 and you should see a visualization. (Must open links in order for robots to appear)

6) Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.

7) When the simulation starts, a basketball is spawned first before any robots so the drone moves toward the basketball first. Then the user must then schedule robots to be picked up and/or click the “Add Basketball” button to spawn basketballs. Then the simulation will work by itself.

## Docker Link: 

## Youtube Demo Link: https://www.youtube.com/watch?v=yMU_Me01C1s

## What does the simulation do: 
This simulation shows a city with buildings, roads, and hoops in the air and the user can schedule robots to be picked up in order. User chooses which route each drone uses to bring a robot to its destination, and each of these routes make the drone and robot do different celebrations. The user can also add basketballs to appear in the simulation at random locations, and these will be picked up after all robots are at their destinations. 

## New Feature: 
When a drone picks up a basketball, it drops it off at the nearest hoop. When multiple robots and basketballs are scheduled to be picked up, the drones first drops off all of the robots, and after that it picks up the nearest basketballs until there are none left. The feature is interesting for the user because the hoops and basketballs will spawn at random locations, making where the drone travels to pick up and drop off the basketballs unpredictable, and it also introduces a pastime or hobby for the drone to partake in, until new robots are scheduled and the drone has to go back to do its job. Our group added basketballs and hoops to the existing code that was given, and then we had to add the logic needed for the drone to move accordingly. When each basketball is dropped off, if you slow the simulation down all the way you can see that both the drone and basketball do a spin and jump celebration. The design pattern we chose to implement is the Sashimi process because we only had about 3-4 weeks for the project, so we wanted to be efficient with our time by being able to move to the next phase before the previous phase is fully finished. When the simulation starts, a basketball is spawned first before any robots so the drone moves toward the basketball first. Then the user must then slow the simulation down and schedule robots to be picked up by clicking on the map and choosing a pick up location and destination. Then click the “Add Basketball” button to spawn basketballs. After this, the user can schedule robots and add basketballs in any order while the simulation is running. 


## Sprint Retrospective: 
Our team used 3 Sprints during the course of creating this final project. The first sprint included basic plans like getting our idea checked off by a teacher assistant and scheduling a weekly time to meet up and discuss our progress and plans. The second sprint was about starting the coding aspect of the project by creating the header files first, and then creating the .cc files next. Then our last sprint had information about how we split up the work for Doxygen and code styling, and also finalizing our code.

## Note: 
For the code styling of SimulationModel.cc and SimulationModel.h, when we fix the rand() function to be rand_r() like we did in Basketball.cc and Hoop.cc, the simulation doesn't run at all so that's why we left the rand_r() functions in those files.



