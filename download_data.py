#!usr/bin/env python

# this downloads the orbital data of planets, moons, and asteroids
# from the Jet Propulsion Laboratory db, and saves them to a file

# Original author: Andrew Clemens
# Original repository: https://github.com/apclemens/SimSolarSystem.git
# 02.2017

import urllib2
import math

masses = {'none':0}
AU = 1.49597870700e11
G = 6.67408e-11
def arctan2(y,x):
    if x>0:
        return math.atan(y/x)
    if y>=0 and x<0:
        return math.atan(y/x)+math.pi
    if y<0 and x<0:
        return math.atan(y/x)-math.pi
    if y>0 and x==0:
        return math.pi/2
    if y<0 and x==0:
        return -math.pi/2
    return 0

class ObjectInSpace:

    def __init__(self, info):
        global masses
        splitInfo = info.split('\n')
        self.name = splitInfo[0]
        self.relativeTo = splitInfo[1]
        self.mass = eval(splitInfo[2])
        self.a = eval(splitInfo[3])*AU              # semi-major axis [m]
        self.e = eval(splitInfo[4])                 # eccentricity [rad]
        self.w = eval(splitInfo[5])*math.pi/180     # argument of periapsis [rad]
        self.omega = eval(splitInfo[6])*math.pi/180 # longitude of ascending node [rad]
        self.i = eval(splitInfo[7])*math.pi/180     # inclination [rad]
        self.M = eval(splitInfo[8])*math.pi/180     # mean anomaly [rad]
        self.mu = masses[self.relativeTo] * G
        print "%s -> %s" % (self.name, self.a)
    def __repr__(self):
        try:
            return self.name+'\n'+str(self.mass)+'\n'+'\n'.join([str(i) for i in self.position])+'\n'+'\n'.join([str(i) for i in self.velocity])
        except:
            self.getCartesian()
            return self.__repr__()

    # https://downloads.rene-schwarz.com/download/M001-Keplerian_Orbit_Elements_to_Cartesian_State_Vectors.pdf
    # Stale http://aa.usno.navy.mil/publications/reports/Luzumetal2011.pdf
    def getCartesian(self):
        if self.name == 'Sun':
            self.position = (0.0,0.0,0.0)
            self.velocity = (0.0,0.0,0.0)
            return
        # solve Kepler's Equation M=E-e*sin(E) for E
        E = self.M
        while abs(E-self.e*math.sin(E)-self.M) > .001:
            E = E - (E-self.e * math.sin(E)-self.M)/(1-self.e*math.cos(E))
        # obtain true anomaly
        v = 2*arctan2(math.sqrt(1+self.e)*math.sin(E/2),
                      math.sqrt(1-self.e)*math.cos(E/2))
        # use eccentric anomaly to get distance to central body
        r = self.a*(1-self.e*math.cos(E))
        # calculate orbital frame position and velocity
        orbFramePos = (r*math.cos(v),r*math.sin(v),0)
        o = math.sqrt(self.mu*self.a)/r  # orbital frame coefficient
        orbFrameVel = (-o*math.sin(E),o*math.sqrt(1-self.e**2)*math.cos(E),0.0)
        # calculate inertial frame position and velocity
        self.position = [orbFramePos[0]*(math.cos(self.w)*math.cos(self.omega)-math.sin(self.w)*math.cos(self.i)*math.sin(self.omega)) - orbFramePos[1]*(math.sin(self.w)*math.cos(self.omega)+math.cos(self.w)*math.cos(self.i)*math.sin(self.omega)),
                         orbFramePos[0]*(math.cos(self.w)*math.sin(self.omega)+math.sin(self.w)*math.cos(self.i)*math.cos(self.omega)) + orbFramePos[1]*(math.cos(self.w)*math.cos(self.i)*math.cos(self.omega)-math.sin(self.w)*math.sin(self.omega)),
                         orbFramePos[0]*(math.sin(self.w)*math.sin(self.i)) + orbFramePos[1]*(math.cos(self.w)*math.sin(self.i))]
        self.velocity = [orbFrameVel[0]*(math.cos(self.w)*math.cos(self.omega)-math.sin(self.w)*math.cos(self.i)*math.sin(self.omega)) - orbFrameVel[1]*(math.sin(self.w)*math.cos(self.omega)+math.cos(self.w)*math.cos(self.i)*math.sin(self.omega)),
                         orbFrameVel[0]*(math.cos(self.w)*math.sin(self.omega)+math.sin(self.w)*math.cos(self.i)*math.cos(self.omega)) + orbFrameVel[1]*(math.cos(self.w)*math.cos(self.i)*math.cos(self.omega)-math.sin(self.w)*math.sin(self.omega)),
                         orbFrameVel[0]*(math.sin(self.w)*math.sin(self.i)) + orbFrameVel[1]*(math.cos(self.w)*math.sin(self.i))]

    def correctCartesian(self, against):
        # we calculated the cartesian coordinates with respect to
        # the object it is orbiting.  We must add the coordinates for that
        # to get it with respect to the sun.
        for i in range(3):
            self.position[i] += against.position[i]
            self.velocity[i] += against.velocity[i]

def getAsteroidParam(html, paramName):
    for line in html:
        if '<param NAME="'+paramName+'" VALUE="' in line:
            break
    return '\n'+line.split(' VALUE="')[1].split('"')[0]

def getAsteroid(n):
    url = 'http://ssd.jpl.nasa.gov/sbdb.cgi?orb=1;sstr='+str(n)
    page = urllib2.urlopen(url)
    html = page.read().split('\n')
    for line in html:
        if 'param NAME="Name" VALUE="' in line:
            break
    name = line.split('param NAME="Name" VALUE="')[1].split('"')[0]
    print name
    info = name+'\n'+'Sun'
    #mass is not on jpl for some reason, get off of wolframalpha
    info += '\n0'
    #semi major axis
    info += '\n'+str(eval(getAsteroidParam(html,'a')))
    #eccentricity
    info += getAsteroidParam(html,'e')
    #argument of periapsis
    info += getAsteroidParam(html,'Peri')
    #long of ascending node
    info += getAsteroidParam(html,'Node')
    #inclination
    info += getAsteroidParam(html,'Incl')
    #mean anomaly
    info += getAsteroidParam(html,'M')
    return info

def getPlanets():
    url = 'http://ssd.jpl.nasa.gov/txt/p_elem_t2.txt'
    page = urllib2.urlopen(url)
    html = page.read().split('\n')
    copy = False
    lines = []
    for line in html:
        if list(set(line)) == ['-']:
            if copy:
                break
            copy = True
        else:
            if copy and line[0] != ' ':
                lines.append(line)
    ret = ''
    for line in lines:
        #for some reason jpl lists Earth as "EM Bary"...
        newLine = line.replace('EM Bary','Earth')
        while '  ' in newLine:
            newLine = newLine.replace('  ',' ')
        info = newLine.split(' ')
        ret += info[0] + '\n' + 'Sun' + '\n' + str(getMass(info[0])) + '\n'
        ret += str(eval(info[1])) + '\n'
        ret += info[2] + '\n'
        ret += info[5] + '\n'
        ret += info[6] + '\n'
        ret += info[3] + '\n'
        ret += info[4] + '\n\n'
    return ret

def getMass(name):
    url = 'http://ssd.jpl.nasa.gov/?planet_phys_par'
    page = urllib2.urlopen(url)
    html = page.read().split('\n')
    for line in html:
        if '<td align="left">'+name in line:
            break
    return html[html.index(line)+20].split('>')[1].split('<')[0]+'e24'

def getMoons():
    planets = ['Earth','Mars','Jupiter','Saturn','Uranus','Neptune','Pluto']
    linesToFind = {}
    for plan in planets:
        linesToFind['<a name="'+plan.lower()+'"> </a>'] = plan
    url = 'http://ssd.jpl.nasa.gov/?sat_elem'
    page = urllib2.urlopen(url)
    htmlStr = page.read()
    htmlStr = htmlStr.replace('</TD>','</TD>\n').replace('\n\n','\n')
    html = htmlStr.split('\n')
    currentPlanet = ''
    info = []
    currInfo = []
    i = -1
    for line in html:
        if i >= 0:
            i += 1
            if i == 1:
				currInfo.append(str(6.685e-9*eval(line.split('>')[1].split('<')[0])))
            else:
                currInfo.append(line.split('>')[1].split('<')[0])
            if i == 6:
                i = -1
                info.append(currInfo)
                currInfo = []
        if line in linesToFind.keys():
            currentPlanet = linesToFind[line]
        if '<TR ALIGN=right><TD ALIGN=left>' in line:
            currentMoon = line.split('<TR ALIGN=right><TD ALIGN=left>')[1].split('<')[0]
            currInfo.append(currentMoon)
            currInfo.append(currentPlanet)
            currInfo.append('0')
            i = 0
    ret = ''
    for moon in info:
        ret += '\n'.join(moon[:6])
        ret += '\n'+moon[8]+'\n'+moon[7]+'\n'+moon[6]+'\n\n'
    return ret

def main():
    f = open('keplerian.txt', 'w')

    # first add header and the Sun
    f.write('/*\nName\nObject this orbits around\nMass\nSemi-major axis (a)\nEccentricity (e)\nArgument of periapsis (w)\nLongitude of ascending node (omega)\nInclination (i)\nMean anomaly (M)\n*/\n\nSun\nnone\n1.989e30\n0\n1\n0\n0\n0\n0\n\n')
    #then the planets
    f.write(getPlanets())
    #then moons
    f.write(getMoons())
    #then asteroids
    for i in range(1,21):
        f.write(getAsteroid(i))
        f.write('\n\n')
    #TODO: kuiper belt, halley's comet, other things
    f.close()

    global masses
    f = open('keplerian.txt', 'r')
    l = f.read().split('\n\n')
    f.close()
    l.pop(0)
    while '' in l:
        l.remove('')

    for objInfo in l:
        splitInfo = objInfo.split('\n')
        masses[splitInfo[0]] = eval(splitInfo[2])

    f = open('cartesian.txt', 'w')
    objects = {}
    for objInfo in l:
        name = objInfo.split('\n')[0]
        objects[name] = ObjectInSpace(objInfo)
        objects[name].getCartesian()
        if name != 'Sun':
            objects[name].correctCartesian(objects[objects[name].relativeTo])
        f.write(objects[name].__repr__())
        f.write('\n\n')
    f.close()

if __name__ == '__main__':
    main()
