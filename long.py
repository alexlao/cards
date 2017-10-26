def main():
    count = 6
    deck = []
    origDeck = []
    ans = 0

    # Generate deck and copy
    for j in range(0, count):
        deck.append(j)
        origDeck.append(j)

    # Run through one round

    print("starting")
    deck = round(deck)
    ans = ans + 1
    for i in deck:
        print(i)

    # Loop through until deck is life first
    while deck != origDeck:
        deck = round(deck)
        ans += 1

    print("total: " + str(ans))
def round(deck):
    table = []
    while len(deck) > 0:
        table.append(deck.pop(0))
        if len(deck) != 0:
            deck.append(deck.pop(0))
    table.reverse()
    return table
if __name__ == "__main__":
    main()