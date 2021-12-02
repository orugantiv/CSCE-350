'''
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application: Read Oruganti_averageExectionTime.txt and plots it onto a graph.
 * Copyright 2021 V.N. Anirudh Oruganti
 '''
import numpy as np
import matplotlib.pyplot as plt

file = open('Oruganti_V.N.Anirudh_averageExecutionTime.txt', 'r')
fig, ax = plt.subplots()
labels = file.readline()
labels = labels.split('\t')
dataInput_Range = []
dataInput_Val = []
dataTime = []

while(1):
    line = file.readline().replace("\n", '')
    if line == '':
        break
    else:
        line = line.split('\t')
        dataInput_Range.append((range(1,len(line[0]))))
        dataInput_Val.append(line[0])
        dataTime.append(float(line[1]).__round__(4))

x_val = dataInput_Range.pop();

plt.plot(x_val, dataTime, marker='o')
plt.xticks(x_val,dataInput_Val)

for i, j in zip(x_val, dataTime):
   plt.text(i-.5, j+1, '({}, {})'.format(dataInput_Val[i-1], j))

plt.xlabel("Input Size")
plt.ylabel("Avg. Execution Time (ms)")
plt.grid(True)

plt.savefig('Oruganti_V.N.Anirudh_plotAverageExecutionTime.jpg')
