import serial
import os

s = serial.Serial('/dev/ttyACM0',9600)
serialData = []

while True:
    data = s.readline()
    print data
    if data:                
        serialData.append(data)
    if len(serialData) == 1: # Luz
        os.system("php /home/claudia/Desktop/envio_luz.php %s"%(data))
    if len(serialData) == 2: # Humedad
        os.system("php /home/claudia/Desktop/envio_humedad.php %s"%(data))
    if len(serialData) == 3: # Temperatura
        os.system("php /home/claudia/Desktop/envio_temperatura.php %s"%(data))
    if len(serialData) == 4: # Indice de calor
        os.system("php /home/claudia/Desktop/envio_calor.php %s"%(data))
    if len(serialData) == 5:        
        os.system("php /home/claudia/Desktop/envio_lluvia.php %s"%(data))
        print s             
        serialData = [] 
