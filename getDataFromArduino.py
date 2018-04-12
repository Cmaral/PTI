
import serial

s = serial.Serial('/dev/ttyACM0',9600)
serialData = []

while True:
    data = s.readline()   
    if data:                
        serialData.append(da
    if len(serialData) == 4:        
        print s             
        s = []              
