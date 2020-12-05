import matplotlib.pyplot as plt
import numpy as np 

def main():

    a = np.array([21, 22, 19, 18, 17, 22, 20, 2000,])
    muy = np.mean(a)
    sigma = np.std(a)
    print(sigma, muy)

    currentTrend = 900
    zscore = (currentTrend - muy) / sigma
    print(zscore)
    pass 
main() 