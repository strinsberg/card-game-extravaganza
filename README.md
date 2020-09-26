# Card Game Extravaganza - CPSC 3720 Software Extension Assignment (fall 2019)

A collection of 2 whole command line card games!

The professor provided code for the Old Maid card game and We were tasked with extending this code to add the game Rummy and to allow the user to play both.

# How to play Rummy
1. Start the extravaganza
2. Pick Rummy from the main menu
3. Enter your name
4. Pick 1-3 opponents (They will all be human controlled)

### Your turn
1. Choose to pickup from the deck or the discard pile. If the deck is empty you can choose to flip the discard back into the deck and take the top card.
2. Choose to play melds. Any set or run of 3 or more cards can be played on the table during this phase of your turn. You will enter the positions of the cards in your hand that make a single set or run. Pressing enter will remove these cards and play them on the table. When you no longer want to play any melds enter 0 to move on.
3. Choose cards to add onto the sets and runs on the table. Give the position of 1 card to play and if it can be added to a meld on the table it will be. This is done automatically and you will not have a choice of which meld to add it to (sorry). If there are no cards on the table you will not see this phase of your turn.
4. Choose the position of a card in your hand to discard. This card will be removed from your hand and placed face up on the discard pile.

### Winning
The winner is the player who gets rid of all their cards first. The other players will have their remaingin cards counted against them. Players remaining cards are totalled and counted against them. This would ideally be done so that more rounds could be played and point totals accumulate, but this is not possible for now.

# Acknowledgements
* The code in Rummy was written using the existing code for Old Maid (provided by the professor). This game would have taken longer to make if it were not for the pretty good code provided.
