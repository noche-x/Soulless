#!/usr/bin/env python

from PIL import Image
import json

im = Image.open("assets/map.png")   

data = {}

with open('assets/properties.json') as json_file:
    data = json.load(json_file)

data['tileMap'] = []

count = 0

width, height = im.size
for y in range(width):
    for x in range(height): 
        r,g,b,a = im.getpixel((x,y))
        inner = None
        
        for z in range(x - 1, x + 2):
            if inner==False:
                break
            if z == -1:
                z += 1
            for q in range(y - 1, y + 2):
                if q >= height:
                    break

                if z >= height:
                    break
                ra,ga,ba,aa = im.getpixel((z,q))
                if 0==ra==ga==ba:
                    inner = True
                else:
                    inner = False
                    break
        if inner==True:
            data['tileMap'].append(2,)
            color = "inner"
        else:
            if 255==r==g==b:
                data['tileMap'].append(0,)
                color = "white"
            elif 0==r==g==b:
                data['tileMap'].append(1,)
                color = "black"
            else:
                data['tileMap'].append(0,)
                color = "else"
        print('x: {}    y: {}    c: {}   inner: {}'.format(x, y, color, inner))

with open('assets/map.json', 'w') as f:
    json.dump(data, f, indent=4)
