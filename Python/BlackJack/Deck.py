#Frazer Bayley
#CIS 211
#Project 3; "Deck.py"

from Card import *
from random import shuffle

class Deck(list):
	"""
	The class deck takes a list of 52 cards within itself. Then has the methods 
	shuffle(), deal(), and restore().
	"""
	
	def __init__(self):
		"""
		Takes a list of 52 cards and makes them part of the class.
		"""
		
		list.__init__(self, [BlackjackCard(i) for i in range(52)])
		
	
	def shuffle(self):
		"""
		Shuffles the current list
		"""
		return shuffle(self)
		
	
	def deal(self, n):
		"""
		Removes a hand of size n cards and returns them in a new list.
		"""
		hand = []
		
		for i in range(n):
			hand.append(self.pop(0))
		
		return hand
		
		
	def restore(self, a):
		"""
		Takes a list (a) and places it into the "bottom" of the deck.
		"""
	
		for i in range(len(a)):
			self.append(a.pop(0))
	

class PinochleDeck(Deck):
	"""
	Devises a deck of cards that has 2 of every card >= card rank of 9.
	"""
	
	def __init__(self):
		"""
		Iterates through a deck of 52 cards and selects the cards with
		a rank of 9 or greater, the appends the card twice to the new
		deck.
		"""
	
		for i in range(52):
			rank_op = i % 13
			if rank_op > 6:
				self.append(Card(i))
				self.append(Card(i))
				
				
				
if __name__ == '__main__':
	
	d = Deck()
	print(d)
	d.shuffle()
	print(d)
	h = d.deal(5)
	print(h)
	d.restore(h)
	d.sort()
	print(d)
