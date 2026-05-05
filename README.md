# Dodoi-Engine WIP

---

## 1. Core Engine Foundation

- **[x] Context & Initialization**
  - SDL2, window, renderer, audio, image, font.
- **[x] Game Loop**
  - Main loop: handle input, update, render, timing.
- **[x] Scene Management**
  - SceneManager for switching between splash, title, gameplay, etc.

---

## 2. Game Object System

- **[x] Base GameObject**
  - Abstract class with position, size, update, render, collider.
- **[x] Collider System**
  - BoxCollider for AABB collision.
- **[ ] Object Pooling**
  - Pools for enemies, projectiles, etc. to avoid dynamic allocation.

---

## 3. Map & Path System

- **[ ] Map Representation**
  - 2D array/grid for tiles (buildable, path, blocked).
- **[ ] Pathfinding**
  - Predefined waypoints for enemy paths (simple for tower defense).
- **[ ] Tile Placement**
  - Logic for placing towers only on buildable tiles.

---

## 4. Game Entities

- **[ ] Enemy**
  - Moves along path, health, speed, damage on reaching end.
- **[ ] Tower**
  - Placed by player, fires at enemies in range, upgradeable.
- **[ ] Projectile**
  - Moves toward enemy, deals damage on hit.

---

## 5. Game Logic

- **[ ] Wave System**
  - Spawns enemies in waves, increases difficulty.
- **[ ] Player State**
  - Money, lives, score.
- **[ ] Tower Placement UI**
  - Simple cursor or menu for placing towers.

---

## 6. Rendering & Audio

- **[ ] Sprite Rendering**
  - Draw enemies, towers, projectiles, map tiles.
- **[ ] Simple Animations**
  - Frame-based or basic effects.
- **[ ] Sound Effects**
  - For shooting, enemy death, etc.

---

## 7. Input Handling

- **[ ] Controller Support**
  - GameCube controller input for menu, placement, etc.

---

## 8. Polish & Optimization

- **[ ] Performance Profiling**
  - Test on hardware, optimize bottlenecks.
- **[ ] Memory Management**
  - Ensure no leaks, efficient use of pools/arrays.
- **[ ] Save/Load System**
  - (Optional) For high scores or progress.

---

## Road Map

1. **Core Engine & Game Loop**
2. **GameObject & Collider System**
3. **Map/Grid & Path System**
4. **Enemy, Tower, Projectile Classes**
5. **Basic Rendering**
6. **Input Handling**
7. **Game Logic (waves, placement, win/lose)**
8. **Audio & Effects**
9. **Optimization & Polish**

---
