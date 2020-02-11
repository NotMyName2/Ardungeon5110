# Ardungeon5110

A simple game where you kill enemies and collect loot (loot is yet to be implemented).

Heavily inspired by this game: https://play.google.com/store/apps/details?id=com.The717pixels.DungeonCards&hl=en_US
I do not plan to make money from this game, it exists for self-educational purposes. Please don't sue me.

The player can move on a 3X3 game field using buttons. If the player wants to move to a cell occupied by a weapon or loot, he automatically collects it(Not implemented yet). If the player wants to move to a cell occupied by an enemy, they fight. If the player has a weapon damage dealt to the enemy is subtracted from the weapon's durability. If the durability of the weapon reaches 0, the weapon is destroyed. If the player does not carry a weapon and attacks, both the player and the enemy lose the same amount of HP. Currently, this is the only way the player can die(not implemented yet).

The only code not written by me are the Adafruit libraries. You can find them here: https://github.com/adafruit/Adafruit-GFX-Library

The game runs on Arduino Nano(ATMega328p), 6 SPST buttons, some capacitors for debouncing and an old Nokia5110 84x48 monochrome LCD display.


Planned features:

  -Enemy class

  -Item class

  -implementing weapons

  -implementing loot, score and GUI

  -potions and status effects

  -ranged weapons

  -piercing weapons

  -improved generation

  -explosives

  -different GUI for different screens

  -tutorial

  -consider using interrupts for buttons instead of polling



yeet
