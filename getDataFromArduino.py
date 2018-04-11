
import serial

s = serial.Serial('/dev/ttyUSB0',9600)
serialData = []

while True:
    data = s.readline()   
    if data:                
        serialData.append(data)
    if len(serialData) == 4:        
        print s             
        s = []              
