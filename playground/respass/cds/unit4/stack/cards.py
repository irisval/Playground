# Bergen County Academies 5-person division
# Contest #1
answer = input()

while (answer != ""):
	rank = ['A', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K']
	hand = answer.split(', ')
	# 5D 2D 6H 9D TD 6H
	leading = hand[0]
	suit = leading[1]
	hand.remove(hand[0])

	# condition: dealer must play same suite if possible
	if any(suit in card[1] for card in hand):
		hand = [card for card in hand if card[1] == suit]
		# condition: play lowest card of higher rank than opponent's card	
		highest_val = rank.index(leading[0])
		bigger = False
		for card in hand:
			if not bigger and rank.index(card[0]) > highest_val:
				highest_val = card
				bigger = True
			elif int(rank.index(card[0])) > int(rank.index(leading[0])) and int(rank.index(card[0])) < int(rank.index(highest_val[0])):
				highest_val = card
		# condition: if higher card does not exist
		if highest_val == rank.index(leading[0]):
			lowest_val = leading
			for card in hand:
				if int(rank.index(card[0])) < int(rank.index(lowest_val[0])):
					lowest_val = card
			print(lowest_val)
		else:
			print(highest_val)
	# condition: card in suit does not exist, play lowest suite
	else:
		lowest_val = hand[0]
		for card in hand:
			if int(rank.index(card[0])) < int(rank.index(lowest_val[0])):
				lowest_val = card
		print(lowest_val)

	answer = input()