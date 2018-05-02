import os
import time
import datetime
import glob
import MySQLdb
from time import strftime
 
 
host="tutorial-db-instance.cy5t8ba5c4ju.us-west-2.rds.amazonaws.com"
port=3306
dbname="meteo"
user="pti20"
password="pti20pti20"
my_db=src_mysql(dbname=dbname,host=host,port=port,user=user,password=password)

////////////////////////////
 
 
os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')
# Falta leer de serial Arduino (USB)
# temp_sensor = '/sys/bus/w1/devices/28-00000622fd44/w1_slave'
 
# Variables for MySQL
db = MySQLdb.connect(host="localhost", user="root", passwd="password", db="nombre_base_datos")
cur = db.cursor()
 
def tempRead():
    t = open(sensor, 'r')
    lines = t.readlines()
    t.close()
 
    temp_output = lines[1].find('t=')
    if temp_output != -1:
        temp_string = lines[1].strip()[temp_output+2:]
        temp_c = float(temp_string)/1000.0
    return round(temp_c,1)
 
while True:
    temp = tempRead()
    print temp
    datetimeWrite = (time.strftime("%Y-%m-%d ") + time.strftime("%H:%M:%S"))
    print datetimeWrite
    sql = ("""INSERT INTO NombreTabla (datetime,temperature) VALUES (%s,%s)""",(datetimeWrite,temp))
    try:
        print "Writing to database..."
        # Execute the SQL command
        cur.execute(*sql)
        # Commit your changes in the database
        db.commit()
        print "Write Complete"
 
    except:
        # Rollback in case there is any error
        db.rollback()
        print "Failed writing to database"
 
    cur.close()
    db.close()
    break
