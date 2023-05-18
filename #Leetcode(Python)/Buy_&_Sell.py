# Question:-
# Best Time to Buy and Sell Stock..

# You are given an array prices where prices[i] is the price of a given stock on the ith day.
# You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
# Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

# Solution:-

from typing import List

def max_profit(prices):
    if len(prices) < 2:
        return 0
        
    min_price = prices[0]
    max_profit = 0
    
    for i in range(1, len(prices)):
        if prices[i] < min_price:
            min_price = prices[i]
        else:
            max_profit = max(max_profit, prices[i] - min_price)
            
    return max_profit

t = int(input("Enter no. of test cases: "))
for i in range (0,t):
    prices = input("Enter prices separated by spaces: ")
    prices = list(map(int, prices.split()))

    print("Input prices:", prices)
    print("Maximum profit:", max_profit(prices))
