
import serial

s = serial.Serial('/dev/ttyACM0',9600)
serialData = []

while True:
    data = s.readline()
    print data
    if data:                
        serialData.append(data)
    if len(serialData) == 4:        
        print s             
        s = []              
