#!/usr/bin/env python3

soldiers = []
num_soldiers = int(input("How many soldiers? > "))
print("Enter soldier's names:")
for i in range(num_soldiers):
    soldier = input("> ")
    soldiers.append(soldier)

print('\n')
for soldier in soldiers:
    print(soldier)