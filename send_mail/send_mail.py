#!/usr/bin/env python
from email.mime.text import MIMEText
from email.mime.application import MIMEApplication
from email.mime.multipart import MIMEMultipart
from smtplib import SMTP
import smtplib
import sys
import datetime
import time

def send_mail(subject,image_file):
    recipients = ["einstein789@hotmail.com"]
    emaillist = [elem.strip().split(',') for elem in recipients]
    msg = MIMEMultipart()
    msg['Subject'] = subject;
    msg['From'] = 'flybird1987@gmail.com'
    #msg['Reply-to'] = 'abcxyz@gmail.com'
    
    msg.preamble = 'Multipart massage.\n'
    
    part = MIMEText("Hi, please find the attached file")
    msg.attach(part)
    
    part = MIMEApplication(open(image_file,"rb").read())
    part.add_header('Content-Disposition', 'attachment', filename=image_file)
    msg.attach(part)
    

    server = smtplib.SMTP("smtp.gmail.com:587")
    server.ehlo()
    server.starttls()
    server.login("flybird1987@gmail.com", "pass")
    
    server.sendmail(msg['From'], emaillist , msg.as_string())