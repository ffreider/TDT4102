import matplotlib.pyplot as plt
import numpy as np
import sys


def runge_kutta4(func, r, t, h):
    k1 = h*func(r, t)
    k2 = h*func(r+0.5*k1, t+0.5*h)
    k3 = h*func(r+0.5*k2, t+0.5*h)
    k4 = h*func(r+k3, t+h)
    return (k1 + 2*k2 + 2*k3 + k4)/6
   



def vanderPolFunction(r, t):
    mu,omega = 3.0,1.0
    x = r[0]
    v = r[1]
    fx = v
    fv = -omega**2 * x  +  mu*(1 - x**2)*v
    return np.array([fx,fv], float)




# initialiton
nSteps = 10000
nArgs = len(sys.argv)
if 1 < nArgs < 3 :
    # get nSteps from command line
    nSteps = int(sys.argv[1])
elif nArgs > 1:
    print("\nBad command line input\n")
    sys.exit("Usage: "+sys.argv[0]+" <nSteps>"+"\n")


tMin,tMax = 0.0,20.0
tStep = (tMax-tMin)/nSteps

tPoints = np.arange(tMin, tMax, tStep)
xPoints,vPoints = [],[]

# set initial conditions on the state variables
x0,v0 = 1.0,0.0
r = np.array([x0,v0], float)

# solve for the time evolution
for t in tPoints:
    xPoints += [r[0]]
    vPoints += [r[1]]
    r += runge_kutta4(vanderPolFunction, r, t, tStep)

# plot displacement vs time    
fig1 = plt.figure(1)
plt.plot(tPoints, xPoints)
plt.xlabel("t")
plt.ylabel("x")
plt.title("The van der Pol oscillator")

# plot the phase space
fig2 = plt.figure(2)
plt.plot(xPoints, vPoints)
plt.xlabel("x")
plt.ylabel("dx/dt")
plt.title("Phase space for the van der Pol oscillator")


fig1.show()
fig2.show()
input("Enter [return] to exit")