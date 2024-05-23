# Why there are bugged seeds?

For each usage, Balatro abbrivate the usage (like `certsl` for seal type from Certificate), concatenate by the seed, then take the hash value as the initial seed of this usage.

However, the hash function involves division, so there is a chance that division by zero happens, then the initial seed become `NaN`. In some sense, a seed has approximately $10^{-12}$ probability to cause this bug.

When the bug happens, the seed keeps `NaN` on every call, and on call for a random number between 0 and 1, it always returns a fixed number which is approximately $0.9924$.

## Why multiple mechanics are bugged at the same time?

The hash function process the given string from tail to head, and is highly related to length. So, if a certain seed make `NaN` happens before processing the usage part, every usage of the same length is bugged. For this, in the next section, seeds are ordered in this length.

## Where is `7LB2WVPK`?

On this seed, `NaN` happens at the usage part, so only erratic deck card generation is bugged. Seeds like this are less interesting and wastes much more time to search, so they are not listed here.

## Why is some effects ante related?

Some usage abbrivation includes current ante, like tag in ante 5 uses `Tag5`. When goes from ante 9 to ante 10, the length increase by 1, so bug status will change.

## What will happen if the bugged result is blocked?

The game resamples using `..._resample1`, then `..._resample2`, etc. In this case it behaves like a normal seed instead. Since blocking is rare, seeds bugging only resample is not important, so not listed here.

## What's never? I can make it always by Oops All 6s.

In cases the probability is affected by Oops All 6s, 'Never' is short for 'Unless you have enough Oops All 6s to make the probability at least 1'.

## Do mods affect these bugs?

A bug related to generating random planets can obviously change if your mod added a new planet card. Same logic applies to other object types. 

If the mod uses in-game RNG, it will be affected in the same logic.

Bug of vanilla objects obviously don't change with mods, unless the mods change their effects.

A special case is, if your mod add some more probability adjusting jokers, or have some jokers with strange probability, there may be something like `996 in 1000`, and in this case it is always instead of never, for $996/1000>0.9924$.

# Bugged seed list

## Length 3

I have found 2 seeds that bugs length 3: `T6MZ14AK`, `5KNXVDPO`.

### Ante unrelated

- Hex always select the last added joker to give polychrome.

### In ante 1~9

- You will always draw the same cards if you don't add or remove cards in deck, and won't differ much if you only add or remove one or two.

### In ante 10~99

None.

## Length 4

I have found 1 seed that bugs length 4: `WDLP9XTR`.

### Ante unrelated

- Amber Acorn shuffles your jokers in a fixed relative order to the order you get them.
- Aura always add polychrome.
- Boss blind is generated in reverse alphabetical order.
- The Hook always select cards added-to-deck most recently.

### In ante 1~9

- Ancient Joker cycles between Diamonds and Clubs.
- Castle always select your last added-to-deck card's suit.
- Shop only have the last type of cards available, in order Joker-Tarot-Planet-Playing-Spectral. In other words:
  - Only Spectral cards in Ghost Deck;
  - Only Playing cards in other decks with Magic Trick;
  - Only Planet cards in other decks without Magic Trick.
- All tags are Economy tags.

### In ante 10~99

- You will always draw the same cards if you don't add or remove cards in deck, and won't differ much if you only add or remove one or two.

## Length 5

I have found 3 seeds that bugs length 5: `N6MP5S61`, `J4N3VFA7`, `26H7PDMP`.

### Ante unrelated

- Ouija always convert cards to Queen.
- Sigil always convert cards to Diamonds.
- Space Joker never triggers.
- 8 Ball never triggers.
- Glass card never breaks.
- The Wheel (boss) never triggers.
- To Do List seems like being periodic in format ABAC, but I'm not sure.

### In ante 1~9

- Hallucination never triggers.
- Idol always select your last added-to-deck card's rank and suit.
- Mail-In Rebate always select your last added-to-deck card's rank.
- Jokers in shop are always rental (on gold stake).

### In ante 10~99

- Ancient Joker cycles between Diamonds and Clubs.
- Castle always select your last added-to-deck card's suit.
- Shop only have the last type of cards available, in order Joker-Tarot-Planet-Playing-Spectral. In other words:
  - Only Spectral cards in Ghost Deck;
  - Only Playing cards in other decks with Magic Trick;
  - Only Planet cards in other decks without Magic Trick.
- All tags are Economy tags.

## Length 6

I have found 1 seed that bugs length 6: `Y4LX2ZTW`.

### Ante unrelated

- Certificate always give cards with red seal.
- The Soul always creates the last Legendary if possible, which is Perkeo in vanilla.
- Perkeo always select the card at relative order 0.9924, which is always the last one before 130 cards.

### In ante 1~9

None.

### In ante 10~99

- Hallucination never triggers.
- Idol always select your last added-to-deck card's rank and suit.
- Mail-In Rebate always select your last added-to-deck card's rank.
- Jokers in shop are always rental (on gold stake).

## Length 7

I have found 1 seed that bugs length 7: `XEQH7CP9`.

### Ante unrelated

- Certificate always give 10 of Spades.
- Marble Joker always give 10 of Spades (you can see this after Vampire or re-enhance).
- Erratic Deck is initialized with all 10 of Spades.
- Madness always select the last added joker to destroy.
- Reserved Parking never triggers.

### In ante 1~9

- Jokers from all ways are always holographic, and become always polychrome if you have Hone.
- Cards in Standard Pack are always enhanced.

### In ante 10~99

None.

## Length 8

I have found 2 seeds that bugs length 8: `XNGD66S1`, `AR3PO8ZY`.

### Ante unrelated

- Familiar, Grim and Incantation always create lucky cards.
- If you have Illusion, playing cards in shop are always polychrome and enhanced.
- Business card never triggers.
- Misprint always give +23 Mult (maximum).

### In ante 1~9

- Cards in Standard Pack always have seal.
- Voucher from defeat the boss is always palette if possible.

### In ante 10~99

- Jokers from all ways are always holographic, and become always polychrome if you have Hone.
- Cards in Standard Pack are always enhanced.

## Length 9

I have found 1 seed that bugs length 9: `VOCX6LD7`.

### Ante unrelated

- Invisible Joker always select the last added joker to duplicate.
- Cavendish never extincts.
- Ectoplasm always select the last added joker to become negative.

### In ante 1~9

- Playing cards from shop or standard packs are always 10 of Spades.
- Jokers in Buffoon Pack are always rental.
- Tarot cards random generated are always The World if possible.

### In ante 10~99

- Cards in Standard Pack always have seal.
- Voucher from defeat the boss is always palette if possible.

## Length 10

I have found 1 seed that bugs length 10: `MIPK41M6`.

### Ante unrelated

- Bloodstone never triggers.
- With Omen Globe, every card in Arcana Pack is spectral card.
- Lucky card never trigger the mult effect.

### In ante 1~9

- Jokers in shop and buffoon pack are always eternal (on black stake or higher).
- When generate random joker from common/uncommon/rare rarity, always generate the last from each.
  - In vanilla, it's Shoot The Moon for common, Bootstraps for uncommon, and Burnt Joker for rare.
- Planet cards random generated are always Eris if possible.
- Packs in shop are always Jumbo Spectral Pack.
- When deciding a random joker's rarity, always select rare.
  - Random Joker from Judgement, Buffoon Pack and Shop first roll rarity then roll a joker from rarity.

### In ante 10~99

- Playing cards from shop or standard packs are always 10 of Spades.
- Jokers in Buffoon Pack are always rental.
- Tarot cards generated are always The World if possible.

## Length 11

Sadly, I have found 0 seed that bugs length 11.

However, if you have the [Seed Unlocker](https://discord.com/channels/1116389027176787968/1229891707793969265) mod from MathIsFun\_, any character concatenate by a 12-bugged seed is a 11-bugged seed. This pattern is consistant, like `MIPK41M6` is 10-bugged seed, so `ANYMIPK41M6` is 7-bugged seed.

### Ante unrelated

- Ankh always select the last added joker to copy.
- Grim always creates Ace of Diamonds.
- Gros Michel never extincts.
- Lucky card never trigger the money effect.

### In ante 1~9

- Tarot cards never become The Soul.

### In ante 10~99

- Jokers in shop and buffoon pack are always eternal (on black stake or higher).
- When generate random joker from common/uncommon/rare rarity, always generate the last from each.
  - In vanilla, it's Shoot The Moon for common, Bootstraps for uncommon, and Burnt Joker for rare.
- Planet cards random generated are always Eris if possible.
- Packs in shop are always Jumbo Spectral Pack.
- When deciding a random joker's rarity, always select rare.
  - Random Joker from Judgement, Buffoon Pack and Shop first roll rarity then roll a joker from rarity.

## Length 12

I have found 1 seed that bugs length 12: `A2POBO78`.

### Ante unrelated

- In 'X-ray Vision' challenge, cards never become flipped.

### In ante 1~9

- Planet cards never become Black Hole.
- Spectral cards from Packs or Seance always select Black Hole then resample.
  - I think it's so stupid that The Soul and Black Hole is not removed from random pool but only labeled as unavailable, when generating a normal random spectral card.
- In Standard Pack:
  - If there is a seal, it must be red.
  - If there is an enhance, it must be lucky.
    - Also applies to playing cards in shop when having Illusion.

### In ante 10~99

- Tarot cards never become The Soul.

## Length 13

I have found 3 seeds that bugs length 13: `JJAEM9CP`, `K99F4X7M`, `1ZJ33G33`.

### Ante unrelated

- Cerulean Bell always select the last added-to-deck card.
- Crimson Heart alternate between the last added and second last.

### In ante 1~9

None.

### In ante 10~99

- Planet cards never become Black Hole.
- Spectral cards from Packs or Seance always select Black Hole then resample.
  - I think it's so stupid that The Soul and Black Hole is not removed from random pool but only labeled as unavailable, when generating a normal random spectral card.
- In Standard Pack:
  - If there is a seal, it must be red.
  - If there is an enhance, it must be lucky.
    - Also applies to playing cards in shop when having Illusion.

## Length 14

I have found 1 seed that bugs length 14: `VUR3SWYC`.

### Ante unrelated

None.

### In ante 1~9

- Spectral cards never become The Soul or Black Hole.
- Spectral cards from Sixth Sense always select Black Hole then resample.
  - I think it's so stupid that The Soul and Black Hole is not removed from random pool but only labeled as unavailable, when generating a normal random spectral card.

### In ante 10~99

None.

## Length 15

I have found 1 seed that bugs length 15: `9M63EB1H`.

### Ante unrelated

- Familiar always create Jack of Diamonds.
- Voucher from voucher tag is always Palette if possible.

### In ante 1~9

None.

### In ante 10~99

- Spectral cards never become The Soul or Black Hole.
- Spectral cards from Sixth Sense always select Black Hole then resample.
  - I think it's so stupid that The Soul and Black Hole is not removed from random pool but only labeled as unavailable, when generating a normal random spectral card.

## Length 16

I have found 2 seeds that bugs length 16: `QV1LTNYQ`, `FAJ8UPYL`.

### Ante unrelated

- The Wheel of Fortune never triggers.
  - THE TRUE WHEEL OF NOPE

### In ante 1~9

None.

### In ante 10~99

None.

## Length 17

I have found 2 seeds that bugs length 17: `5Y7KZDF7`, `KGHTNPEQ`.

### Ante unrelated

None.

### In ante 1~9

- Cards in Standard Pack are always Polychrome.

### In ante 10~99

None.

## Length 18

I have found 2 seeds that bugs length 18: `J1663VCL`, `9M1FF1NW`.

### Ante unrelated

- Incantation always create 2 of Diamonds.

### In ante 1~9

None.

### In ante 10~99

- Cards in Standard Pack are always Polychrome.

# Crash the game

Actually, the in-game RNG involves the hash value of the seed. If a seed has hash value `NaN`, every RNG is bugged, include resample ones. Then, the game will get stuck due to infinitely resampling (I guess it's setting ante 1 voucher, and always get unavailable Palette).

Sadly, there is no seed in vanilla did this.

If you have the [Seed Unlocker](https://discord.com/channels/1116389027176787968/1229891707793969265) mod from MathIsFun\_, a 0-bugged seed generated by adding $n$ characters before a $n$-bugged seed will do this job.

Actually, in the above seeds, process the seeds result in 0 and `NaN` will happen in the next digit whatever it is. So, to find crash seed, we need an 1-bugged seed of length no more than 7, and sadly doesn't exist.

There exists '0-bugged seed' in vanila which has hash value 0, but won't crash game and seems nothing special.