# Swarmly Cleaner — Swarm Robotics for Municipal Waste Collection

**R.U.T Team** · ARC4, 4th Annual Robot Competition — University Open Category, *"Robot in Service of
Municipalities"* (2018)

## Overview

Swarmly Cleaner is a swarm-robotics system for automating municipal waste collection. A fleet of
autonomous collector robots operates over a graph representation of a city's street network,
coordinating in real time through a central Raspberry Pi server and IoT-enabled smart bins, while a
companion Android app gives an operator continuous, live monitoring of the whole fleet.

## How It Works

- **City as a graph** — the municipality's street network is modeled as a weighted grid graph. Each
  robot determines its own candidate moves (edges) from its current coordinates and encodes/decodes
  them locally on the embedded controller.
- **Swarm-intelligence routing** — drawing on Swarm Intelligence and Ant Colony Optimization, each
  robot requests the weights of its candidate edges from the coordination server and greedily selects
  the highest-weighted route, splitting the routing computation between lightweight robots and a
  central engine.
- **Collision-free coordination** — an edge-locking protocol marks a chosen route "busy" (the server
  returns a negative weight for occupied edges) so no other robot enters the same street segment at
  once, releasing it again once the robot has passed.
- **Smart bins** — IoT-enabled bins report their fill weight; a robot requests a bin's weight and, if
  it has spare container capacity, collects it, asks the server to reset that bin's weight, and
  updates its onboard RGB status LED.
- **Return-to-base** — once a robot's container reaches capacity, it automatically routes back to the
  landfill/start point instead of continuing collection.
- **Live monitoring** — a companion Android app gives the operator real-time visibility into the
  swarm's status.

## Featured

![R.U.T Team presenting Swarmly Cleaner at the ARC4 open-category exhibition](<competition time.jpg>)

*R.U.T Team presenting Swarmly Cleaner at the ARC4 open-category exhibition, alongside a scale
city-block model used to demo the swarm's navigation.*

![Swarmly Cleaner robot — 3D design](<BOT Client 3D.png>)

*3D CAD design of a single Swarmly Cleaner collector unit — chassis, dual-wheel drive, and onboard
ultrasonic sensors.*

## Tech Stack

Arduino / ESP8266 (embedded C++), Raspberry Pi (coordination server), Android (fleet monitoring app),
serial/IoT communication protocol, Graph Theory, Swarm Intelligence / Ant Colony Optimization.

## Team

- Rama Alsous
- Mohammad Jaafar Murtada
- Mohammad Ali Harmalani
- Hadi Alshaar

Advisor: Eng. Abdulaziz Alnahhas

## Repository Structure

```
code/         Embedded C++ (Arduino) firmware for the collector robot
documents/    Project report, algorithm flowchart, and competition submission
```
