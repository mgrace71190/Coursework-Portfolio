# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    filename = sys.argv[1]
    # read csv
    with open(filename) as file:
        reader = csv.DictReader(file)
        # cycle through row values
        for row in reader:
            # identify rating
            team = row
            # convert rating to an int
            team["rating"] = int(team["rating"])
            # append team in the teams list
            teams.append(team)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    # regarding the sim, with x amount of teams
    for simulation in range(N):
        # the winner is whatever team comes out from the sim
        winner = simulate_tournament(teams)
        # if winner is in counts, add 1
        if winner in counts:
            counts[winner] += 1
        # otherwise 1
        else:
            counts[winner] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_match(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    # spits out the winner
    # 1. determine list length (no of matchs)
    matchs = len(teams)
    # 2. needs at least 2 teams
    if matchs >= 2:
        # 3. simulate the match
        teams = simulate_match(teams)
        # 4.return winner
        return simulate_tournament(teams)
    # otherwise if <2 team, the only team there wins
    else:
        winner = teams[0]["team"]
        return winner


if __name__ == "__main__":
    main()
