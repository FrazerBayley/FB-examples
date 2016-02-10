# Frazer Bayley 
# CIS 211
# Project #2; "Card.py"

"""
Card.py takes a numerical value from 0 through 51 to turn into a playing card
object. The first class [Card] takes the value and gives it a string 
representation of a standard playing card as well as giving that card a
point value. The second class [BlackjackCard] takes the same playing card 
object from the Card class and then assigns it to a different point value 
to the one used in Card. The function total takes a list of card objects and
determines their combined value using the class Card's point system or the 
class BlackjackCard's point system. 

**BONUS** 
I made an error statement for a value that is above 52.
"""

from random import sample

class Card:
	"""
	This class takes a numerical value and then assigns it to a string 
	representation of a playing card. The playing card can have a point 
	value of 0 - 4 depending on it's rank.
	"""
		
	def __init__(self, n):
		"""
		Creates the suit and rank value of the number inputed. As well
		as interrupting the program if the number is not from 0 to 51.
		"""
		self._id = n 
		self._suit, self._rank = divmod(n, 13)
		
		if self._suit <= -1 or self._suit >= 4:
			print("!!ERROR!! Choose a card from 0 to 51.")
			exit()
			
		return
		
		
	
	card_points = { 12 : 4, 11 : 3, 10 : 2, 9 : 1 }
				#	Ace		King	Queen	Jack

	
	card_rank = {0 : '2', 1 : '3', 2 : '4', 3 : '5', 4 : '6',
				 5 : '7', 6 : '8', 7: '9', 8 : '10', 9 : 'J',
				 10 : 'Q', 11 : 'K', 12 : 'A'}
	
	
	syms = {0 : '\u2663', 1 : '\u2666', 2 : '\u2665', 3 : '\u2660'}
		
		
		
	def __repr__(self):
		"""
		Returns the string value of the card, using utf-8 symbols
		for the suits and the rank for the rank of the card.
		"""
			
		return (Card.card_rank[self._rank] + Card.syms[self._suit])
		
	
	def rank(self):
		"""
		Returns the value of the rank of the playing card.
		"""
		
		return self._rank
		
	
	def suit(self):
		""" 
		Returns the value of the suit of the playing card.
		"""

		return self._suit


	def points(self):
		"""
		Returns the point value of the card. Ace = 4 pts,
		King = 3 pts, Queen = 2 pts, Jack = 1 pts and any 
		other card rank earns 0 pts.
		"""
	
		if self._rank >= 9 and self._rank <= 12:
			return Card.card_points[self._rank]
		return 0
	

	def __lt__(self, other):
		"""
		Determines if card x is less than card y, using their
		point value.
		"""
		return self._id < other._id 

	
	
class BlackjackCard(Card):
	"""
	Uses the objects from class Card and assigns them to a new
	point system.
	"""
	
	
	bj_card_points = {
		12:11, 11:10, 10:10, 9:10,
		8:10, 7:9, 6:8, 5:7, 4:6,
		3:5, 2:4, 1:3, 0:2
		}
		
		
	def points(self):
		"""
		Returns the point value of the card. Ace = 11 pts,
		King, Queen and Jack = 10 pts and all other cards equal
		their respective values.
		"""
		
		return BlackjackCard.bj_card_points[self._rank]
	
		
def total_card(h):
	"""
	Takes a list of cards and determines their combined value using their 
	respective point systems.
	"""
	
	amt = 0
	
	for i in h: 
		amt += i.points()
	
	return amt
		
	
if __name__ == '__main__':
	
	x = Card(51)
	print(x)
	y = Card(23)
	print(x < y)
	
	deck = [Card(i) for i in range(52)]
	hand = sample(deck, 5)
	print(hand)
	print(total_card(hand))
	
	print()
	
	bj_deck = [BlackjackCard(i) for i in range(52)]
	bj_hand = sample(bj_deck, 5)
	print(bj_hand)
	print(total_card(bj_hand))
	