"""
Frazer Bayley 
CIS 211
blackjack.py

This is a blackjack game simulator with with a dealer and a player. The display 
begins with 12 blank labels (6 dealer cards, 6 player cards) and 3 buttons (deal,
hit, and pass). These relate to functions deal(), hit() and pass_f(). The functions 
produce tkinter messageboxes when they total up the players and dealers scores to
determine the winner.
"""

from tkinter import *
from Card import * 
from Deck import *
from tkinter.messagebox import showinfo
from CardLabel import * 

deck = Deck()	#creates a deck using the BlackjackCard class in class.py 
deck.shuffle()	#shuffles the newly created deck	

deal_click = 0
hit_click = 0
pass_click = 0
player_total = 0
dealer_score = 0
player_cards = [] 
dealer_cards = []


def deal():
	"""
	The deal() function adds to the global lists player and dealer as well
	as displaying the start of a blackjack game. Dealer deals four cards, two
	to the player and two to themselves. Dealers cards are one face up and one 
	facedown to protect the integrity of the game. Calls the function total() to 
	add the current scores of the dealer and the player. If the deal button is 
	hit more than once it stops functioning.
	"""
	
	global deck, deal_click, player_cards, dealer_cards , dealer, dealer_score
	
	if deal_click == 0:
		deal_click += 1
	
		dealer = deck.deal(2)
		player = deck.deal(2)
		
		Dcard[0].display('front', dealer[0]._id)
		Dcard[1].display('back', dealer[1]._id)
		
		Pcard[0].display('front', player[0]._id)
		Pcard[1].display('front', player[1]._id)
		
		player_cards.extend(player)
		dealer_cards.extend(dealer)
		
		total()
	else:		#stops the player changing the hand they are dealt
		pass

	
def total():
	"""
	Adds the point values of all the cards currently dealt, for the dealer and the 
	player. The output of the function comes out in player_total and dealer_score.
	This function also changes the value of an ace for the dealer and the player
	based on their circumstances.
	"""
	
	global player_total, player_cards, dealer_cards, dealer_score
	
	points = 0
	aces = 0
	for x in player_cards:
		points += x.points()
		player_total = points
		if x.rank() == 12:
			aces += 1
	while player_total > 21 and aces > 0:
		points -= 10
		player_total = points
		aces -= 1
			
	points = 0
	aces = 0
	for y in dealer_cards:
		points += y.points()
		dealer_score = points
		if y.rank() == 12:
			aces += 1
	while dealer_score > 21 and aces > 0:
		points -= 10
		dealer_score = points
		aces -= 1
	
	
def hit():
	"""
	The hit function is the players option to ask for more cards until they
	believe they have the highest valued hand of cards they can possibly receive.
	It adds to the players_cards, checks the total() as well as displays a message
	when the player busts.
	"""
	global deck, deal_click, hit_click, player_cards
	
	total()
	
	if deal_click == 1:
		if hit_click <= 3:
			card = deck.deal(1)
			player_cards.extend(card)
			Pcard[hit_click + 2].display('front', card[0]._id)
			hit_click += 1 
			total()
			if player_total <= 21:
				pass
			else:
				Dcard[1].display('front', dealer[1]._id)
				showinfo("Game Over", "Dealer Wins!")
	total()
	
	
def pass_f():
	"""
	This function is the dealer playing their turn. If the dealer has less than
	17 points worth of cards it has no choice but to hit, then it check again and 
	proceeds as before. The cards are added to dealer_cards as well as the display.
	At this time the display reveals the cards that the dealer had facedown. This 
	is where the main win, lose or tie for the player come out.
	"""
	global pass_click, dealer_score
	
	Dcard[1].display('front', dealer[1]._id)

	total()
	
	while dealer_score < 17:
		total()
		card = deck.deal(1)
		dealer_cards.extend(card)
		Dcard[pass_click + 2].display('front', card[0]._id)
		pass_click += 1
		total()
	if dealer_score > player_total and dealer_score <= 21:
		showinfo('Game Over', "Dealer Wins!") 
	elif dealer_score < player_total or dealer_score > 21:
		showinfo("Game Over", "Player 1 Wins!")
	else:
		showinfo("Game Over", "Its a Tie!")
	total()


"""
This next section is filled with display info for the tkinter. The card labels are
made with [Cardlabel(root) for i in range(6)] for better usability.
"""

root = Tk()
CardLabel.load_images()	  

Dcard = [CardLabel(root) for i in range(6)]

Pcard = [CardLabel(root) for i in range(6)]

dealerpos = 0
for x in Dcard:
	x.grid(row=0, column = dealerpos)
	x.display(side = 'blank') 
	dealerpos += 1
			
playerpos = 0
for y in Pcard:
	y.grid(row=1, column = playerpos)
	y.display(side = 'blank')
	playerpos += 1
	
#buttons for Deal, Hit and Pass
deal_b = Button(root, text = 'Deal', command = deal)
deal_b.grid(row = 3, column = 1)

hit_b = Button(root, text = 'Hit', command = hit)
hit_b.grid(row = 3, column = 2)

pass_b = Button(root, text = 'Pass', command = pass_f)
pass_b.grid(row = 3, column = 3)



if __name__ == '__main__':

	print("***TEST CASES***")
	print("****************")
	print("Should produce a deck pf 52 card objects that are shuffled")
	print("print(deck) >>>")
	print(deck)
	print("****************")
	print("Should produce the length of the original deck which is (52)")
	print("print(len(deck)) >>>")
	print(len(deck))
	print("****************")
	print("NOW RUNNING BLACKJACK SIMULATOR...")
	print("CLOSE tkinter WINDOW TO EXIT SIMULATOR")
	root.mainloop()
	print("EXITING SIMULATOR...")
	print("****************")
	print("Should produce list of cards that were dealt to the dealer")
	print("print(dealer_cards) >>>")
	print(dealer_cards)
	print("****************")
	print("Should produce the total points accumalated by the dealer")
	print("print(dealer_score) >>>")
	print(dealer_score)
	print("****************")
	print("Should produce list of cards that were dealt to the player")
	print("print(player_cards) >>>")
	print(player_cards) 
	print("****************")
	print("Should produce the total points accumalated by the player")
	print("print(player_total) >>>")
	print(player_total)
	print("****************")
	print("Should produce the original shuffled deck minus the dealer and players cards")
	print("print(deck) >>>")
	print(deck)
	print("****************")
	print("Should produce the new length of the original deck")
	print("print(len(deck)) >>>")
	print(len(deck))
	print("****************")
	print("***FINISHED TESTS***")
	