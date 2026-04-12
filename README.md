# 🚗 UE5 Driving Prototype (C++)

A small driving gameplay prototype built in Unreal Engine 5 using C++, featuring custom vehicle movement and a checkpoint-based progression system.

---

## 🎯 Overview

This project demonstrates a basic driving gameplay loop implemented entirely in C++.

Implemented systems:
- Custom car movement (acceleration and steering)
- Pawn / Controller / GameMode architecture
- Checkpoint progression system
- Basic race flow logic

---

## 🎮️ Gameplay




https://github.com/user-attachments/assets/e181e5bd-d2ac-4a46-b17f-ca9c4cb09cc6




---

## 🧠 Architecture

The project follows Unreal Engine gameplay framework principles.

### Core Classes

ACarPawn  
Represents the player-controlled vehicle.  
Responsible for visual setup (mesh, camera) and forwarding input to movement logic.

UCarMovementComponent  
Custom movement component that handles:
- throttle (forward movement)
- steering (rotation)
- per-frame updates

ACarPlayerController  
Controls gameplay flow:
- binds player input
- tracks current checkpoint
- manages progression between gates

ACheckpointGate  
Represents a checkpoint:
- uses overlap detection
- links to the next checkpoint

ACarGameMode  
Initializes gameplay:
- finds and stores all checkpoints
- sets starting conditions

---

## ⚙️ Features

- Custom C++ movement system (no built-in vehicle system)
- Checkpoint progression using linked gates
- Dynamic checkpoint switching
- Modular gameplay architecture

---

## 🛠️ Technologies

- Unreal Engine 5
- C++
- Unreal Gameplay Framework

---

## 🚀 How to Run

1. Clone the repository:
   git clone https://github.com/Uncorv/UE5_Driving.git

2. Open the .uproject file in Unreal Engine 5

3. Build the project (if required)

4. Run the level in the editor

---

## 🧩 Possible Improvements

- Enhanced Input system integration
- Race states (start / finish / restart)
- Lap system and timers
- Save/load best time
- UI (HUD with speed, time, checkpoints)
- AI opponents or ghost replay
- Data-driven configuration (Data Assets)
- More realistic vehicle physics (Chaos Vehicles)

---

## 📌 Notes

This is a learning project focused on gameplay programming and system design, not a full production-ready game.

---
