#!/usr/bin/python3
import math
from collections import defaultdict as ddict


class IList(ddict):
    def __init__(self, **kwargs):
        super().__init__(lambda: 0)
        self.update(**kwargs)

    def __str__(self):
        return f'IList({", ".join(f"{k}: {v}" for k, v in self.items())})'


def craft_dust(needed, inventory):
    inventory["dust"] += 1
    if inventory["netherStar"] < 1:
        craft_nether_star(needed, inventory)
    inventory["netherStar"] -= 1


def craft_tiny_dust(needed, inventory):
    inventory["tinyDust"] += 9
    if inventory["dust"] < 1:
        craft_dust(needed, inventory)
    inventory["dust"] -= 1


def craft_null_catalyst(needed, inventory):
    if inventory["nullCatalyst"] < 1:
        raise Exception("Not enough Input")
    inventory["nullCatalyst"] += 2
    needed["magmaCream"] += 1
    needed["blazePowder"] += 1
    inventory["tinyDust"] -= 1
    if inventory["tinyDust"] < 0:
        craft_tiny_dust(needed, inventory)
    if inventory["nullCatalyst"] < 1:
        craft_null_catalyst(needed, inventory)


def craft_nether_star(amt, needed, inventory):
    if inventory["netherStar"] < amt:
        inventory["netherStar"] += 1
        if inventory["salisMundus"] < 16:
            needed["salisMundus"] += 16
        if inventory["nullCatalyst"] < 2:
            craft_null_catalyst(needed, inventory)
        inventory["nullCatalyst"] -= 1


def testing(num, needed=None, inventory=None):
    if num <= 0:
        return IList(), IList()
    if inventory is None:
        inventory = IList()
    if needed is None:
        needed = IList()
    number = 0
    while number < num:
        craft_nether_star(num, needed, inventory)
        number = inventory["netherStar"]
    return needed, inventory


def main():
    for i in range(1, 1024 + 1):
        r = IList()
        e = IList(nullCatalyst=1, tinyDust=1)
        req, extra = testing(i, r, e)
        print(req, extra)


if __name__ == "__main__":
    main()
