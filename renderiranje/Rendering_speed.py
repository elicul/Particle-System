# -*- coding: utf-8 -*-
"""
Created on Mon Aug 31 22:17:08 2015

@author: enzo
"""
from __future__ import unicode_literals
import numpy as np
import matplotlib.pyplot as plt

BrojCestica = np.loadtxt("Cestice.txt", delimiter=",", unpack=False)
FPS = np.loadtxt("FPS.txt", delimiter=",", unpack=False)

BrojCesticaT = np.loadtxt("CesticeTextura.txt", delimiter=",", unpack=False)
FPST = np.loadtxt("FPSTextura.txt", delimiter=",", unpack=False)

plt.title("Brzina renderiranja")
plt.xlabel("Broj Čestica")
plt.ylabel("Vrijeme renderiranja [s]")
plt.grid(b=True, which='major', color='black', linestyle='--')
plt.grid(b=True, which='minor', color='g', linestyle='-', alpha=0.3)
plt.minorticks_on()
plt.plot(BrojCestica, 1/FPS, color='r', linewidth=2.0, label="Čestice renderirane polygonima")
plt.plot(BrojCesticaT, 1/FPST, color='b', linewidth=2.0, label="Čestice renderirane texturama")
plt.legend(loc="upper left")
plt.show()

plt.title("Brzina renderiranja")
plt.xlabel("Broj Čestica")
plt.ylabel("FPS")
plt.grid(b=True, which='major', color='black', linestyle='--')
plt.grid(b=True, which='minor', color='g', linestyle='-', alpha=0.3)
plt.minorticks_on()
plt.plot(BrojCestica, FPS, color='r', linewidth=2.0, label="Čestice renderirane polygonima")
plt.plot(BrojCesticaT, FPST, color='b', linewidth=2.0, label="Čestice renderirane texturama")
plt.legend(loc="upper right")
plt.show()