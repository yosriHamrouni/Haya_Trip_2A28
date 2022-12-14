#include "arduino.h"
#include<QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
Arduino::Arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
   return serial;
}
int Arduino::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
           if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
               if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                       == arduino_uno_producy_id) {
                   arduino_is_available = true;
                   arduino_port_name=serial_port_info.portName();
               } } }
        qDebug() << "arduino_port_name is :" << arduino_port_name;
        if(arduino_is_available){ // configuration de la communication ( débit...)
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
                serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
                serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
                serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;
}

int Arduino::close_arduino()

{

    if(serial->isOpen()){
            serial->close();
            return 0;
        }
    return 1;


}


 QByteArray Arduino::read_from_arduino()
{
    if(serial->isReadable()){
         data=serial->readAll(); //récupérer les données reçues

         return data;
    }
 }


int Arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}
/*
#include "arduino.h"
#include<QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduino.h"

arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial = new QSerialPort;
}

int arduino::connect_arduino(){
    //les ports dispo
    foreach(const QSerialPortInfo& serial_port_info, QSerialPortInfo::availablePorts()){
            if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
                if((serial_port_info.vendorIdentifier()== arduino_uno_vendor_id )&&(serial_port_info.productIdentifier()==arduino_uno_prod_id)){
                qDebug()<<serial_port_info.vendorIdentifier();
                qDebug()<<serial_port_info.productIdentifier();
                    arduino_is_available=true;
                    arduino_port_name=serial_port_info.portName();
                }
            }
        }
        qDebug()<<arduino_is_available;
        qDebug() <<"arduino port name is : "<<arduino_port_name;
        //qDebug()<<"vendor id : "<<;

        if(arduino_is_available){
            //CONFIGURATION
            serial->setPortName(arduino_port_name);
            if(serial->open(QSerialPort::ReadWrite)){
                serial->setBaudRate(QSerialPort::Baud9600);
                serial->setDataBits(QSerialPort::Data8);
                serial->setParity(QSerialPort::NoParity);
                serial->setStopBits(QSerialPort::OneStop);
                serial->setFlowControl(QSerialPort::NoFlowControl);
                return 0;
            }
            return 1;
        }
        return -1;

}

QString arduino::getarduino_port_name(){
    return this->arduino_port_name;
}

QSerialPort* arduino::getserial(){
    return serial;
}
int arduino::close_arduino(){
    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;
}



QByteArray arduino::read_from_arduino(){
    if(serial->isReadable()){
        data=serial->readAll();
        return data;
    }else
    qDebug()<<"eerrooor";
    return 0;
}


int arduino::write_to_arduino(QByteArray msg)
{
    if (serial->isWritable())
    {
        serial->write(msg);
         qDebug()<<msg;
    }
    else
        qDebug() << "Couldn't write to serial!";
    return -1;
}

int arduino::writeStringToArduino(const char * msg)
{
    if (serial->isWritable())
    {
        serial->write(msg);
         qDebug()<<msg;
    }
    else
        qDebug() << "Couldn't write to serial!";
    return -1;
}
int arduino::write1_to_arduino(QByteArray d){
    if(serial->isWritable())
    {
        serial->write(d);//envoyer des donnees vers arduino
    }else
qDebug() << "error en ecriture";
}*/
