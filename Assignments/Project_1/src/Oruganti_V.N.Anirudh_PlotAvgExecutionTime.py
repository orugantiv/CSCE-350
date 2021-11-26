'''
 * Programmer Name: V.N. Anriudh Oruganti
 * Class: CSCE 350
 * Application: Read and Writes Floats to Files from and to Vector
 * Excution:
 * Copyright 2021 V.N. Anirudh Oruganti
 '''
import numpy as np
import matplotlib.pyplot as plt

file = open('Oruganti_V.N.Anirudh_averageExecutionTime.txt', 'r')
fig, ax = plt.subplots()
labels = file.readline()
labels = labels.split('\t')
dataInput = []
dataTime = []
while(1):
    line = file.readline().replace("\n", '')
    if line == '':
        break
    else:
        line = line.split('\t')
        dataInput.append(float(line[0]))
        dataTime.append(float(line[1]))

ax.plot(dataInput, dataTime, marker="o")
ax.set_title(labels[0]+' v. '+labels[1])
ax.set_xlabel(labels[0])
ax.set_ylabel(labels[1])
plt.savefig('Oruganti_V.N.Anirudh_plotAverageExecutionTime.jpg')
