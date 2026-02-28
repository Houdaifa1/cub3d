<div align="center">

# 🏰 cub3d

**A Wolfenstein-inspired 3D raycaster engine built in C. No OpenGL. Just math and MiniLibX.**

![C](https://img.shields.io/badge/language-C-blue?style=for-the-badge&logo=c)
![42](https://img.shields.io/badge/school-42-black?style=for-the-badge)
![Score](https://img.shields.io/badge/score-125%2F100-brightgreen?style=for-the-badge)

</div>

---

## 🧠 What is cub3d?

`cub3d` is a 42 graphics project inspired by the legendary **Wolfenstein 3D**. You build a first-person 3D perspective engine using a technique called **raycasting** — casting rays from the player's viewpoint and computing wall distances to render a pseudo-3D view. All from scratch. No game engines. No 3D APIs.

---

## 🎮 Features

- **3D raycasted rendering** — walls, floors, ceilings in pseudo-3D
- **Textured walls** — different textures for N/S/E/W wall faces
- **Configurable scene** — map loaded from a `.cub` file
- **Smooth movement** — WASD + left/right arrow keys
- **Mouse look** (bonus) — rotate camera with mouse
- **Minimap** (bonus) — top-down view overlay

---

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` `→` | Rotate camera |
| `ESC` | Quit |

---

## 🗺️ Map Format (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
        111111111011000001110000001
        100000000011000001110111111
        11110111111111011100000010
        11110111111111011101010010
        11000000110101011100110010
        10000000000000001100000010
        10000000000000001101010010
        11000001110101011111111111
        11110111 1110101101111010
        11111111 1111101111111111
```

---

## 🧮 How Raycasting Works

```
For each vertical column on screen:
  1. Cast a ray from player position at column's angle
  2. Step through the grid (DDA algorithm)
  3. Detect wall hit → compute distance
  4. Distance → wall height (inverse relationship)
  5. Sample correct texture pixel based on hit position
  6. Draw the column
```

---

## 🚀 Usage

```bash
git clone https://github.com/Houdaifa1/cub3d
cd cub3d
make
./cub3d maps/map.cub
```

---

## 🔧 Build

```bash
make        # Compile
make clean  # Remove objects
make fclean # Full cleanup
make re     # Rebuild
```

---

<div align="center">
<i>1992 called. It wants its engine back. You made it better.</i>
</div>
