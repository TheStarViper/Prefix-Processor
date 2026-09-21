# **Affixle**

Affixle is a fast-paced word game that gives you either a prefix or a suffix
along with a base word and you have to say whether or not the combined phrase
given is an actual word in the scrabble dictionary or a made up word. It's a
time attack game where you play until the time runs out and you are given your
final score.

The game logic and dictionary lookups run in C++ compiled to WASM via
Emscripten, exposed to a Svelte frontend.

> [!NOTE]
> This game used to be called "Prefix Processor" in development if you see that
> name around

# Gameplay Loop

1. You're shown something like un + happy or trans + bucket
2. Tap Yes if you think the prefix + base makes a real word, and No if you
   don't.
3. Correct answers add time to the clock, wrong answers deduct time.
4. The game ends when the timer hits zero

> **Play it at <https://thestarviper.github.io/Prefix-Processor/>!**

# Backend (C++)
<<<<<<< HEAD
    ok so basically how i went about developing the backend is just by creating a ton of helper functions to update and fetch the data in the backemd. The backend loads the dictionary of words and creates the questions and holds the past failures and successes so that the frontend can just run a function to fetch the data pre-calculated. the file in backend/src/exposed_functions.md has all the functions documented so that ethmarks knows how each function works, the parameters it takes, and what it returns.
=======

backend yap and stuff im getting bored of writing this readme

>>>>>>> 3ff87ae8ed2fa27af668b0c6cc3aee6989fa9d5d
### Linkage

linking between the two

# Frontend (Svelte)

yap about front end here ok bye

# **Assets**

- [Scrabble Dictionary](https://github.com/zeisler/scrabble/blob/master/db/dictionary.csv)

# **Contributers**

- Ethan ([@ethmarks](https://github.com/ethmarks)): Frontend in Svelte
- Andrew ([@TheStarViper](https://github.com/TheStarViper)): Backend in C++
