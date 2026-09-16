# **Affixle**
Affixle is a fast-paced daily word game that gives you either a prefix or a suffix along with a base word and you have to say whether or not the combined phrase given is an actual word in the scrabble dictionary or a made up word. It's a time attack game where you play until the time runs out and you are given your final score.

The game logic and dictionary lookups run in C++ compiled to WASM via Emscripten, exposed to a Svelte frontend.

> [!NOTE]
> This game used to be called "Prefix Processor" in development if you see that name around

# Gameplay Loop
1. You're shown something like un + happy or trans + bucket
2. Tap Yes if you think the prefix + base makes a real word, and no if you don't.
3. Correct answers add time to the clock, wrong answers deduct time.
4. The game ends when the timer hits zero
Try it out [here](https://thestarviper.github.io/Prefix-Processor/)!

# Backend (C++)
backend yap and stuff im getting bored of writing this readme

### Linkage
linking between the two

# Frontend (Svelte)
yap about front end here ok bye

# **Assets**
- [Scrabble Dictionary](https://github.com/zeisler/scrabble/blob/master/db/dictionary.csv)
  
# **Contributers**
- [![@ethmarks](https://github.com)](https://github.com/ethmarks) **Ethmarks (front-end designer in Svelte)**
- [![@TheStarViper](https://github.com)](https://github.com/TheStarViper) **TheStarViper/Andrew (back-end designer in C++)**
