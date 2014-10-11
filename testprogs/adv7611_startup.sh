#!/bin/bash

# Test Script for initializing ADV7611

#use /dev/i2c1
I2C_BUS=1
#fixed ADV7611 Address
I2C_ADV7611=0x4c
#programmable I2C Addresses
I2C_CEC_MAP=0x40
I2C_INFOFRAME_MAP=0x38
I2C_DPLL_MAP=0x26
I2C_KSV_MAP=0x32
I2C_EDID_MAP=0x36
I2C_HDMI_MAP=0x34
I2C_CP_MAP=0x22

# enable reset pin
echo 14 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio14_pc24/direction
echo 0 > /sys/class/gpio/gpio14_pc24/value
sleep 1
echo 1 > /sys/class/gpio/gpio14_pc24/value

# Activate register addresses

WADDR=$I2C_CEC_MAP
let "WADDR<<=1"
i2cset -y $I2C_BUS $I2C_ADV7611 0xf4 $WADDR      # CEC Map I2C address
WADDR=$I2C_INFOFRAME_MAP
let "WADDR<<=1"
i2cset -y $I2C_BUS $I2C_ADV7611 0xf5 $WADDR      # INFOFRMAE Map I2C address
WADDR=$I2C_DPLL_MAP
let "WADDR<<=1"
i2cset -y $I2C_BUS $I2C_ADV7611 0xf8 $WADDR      # DPLL Map I2C address
WADDR=$I2C_KSV_MAP
let "WADDR<<=1"
i2cset -y $I2C_BUS $I2C_ADV7611 0xf9 $WADDR      # KSV Map I2C address
WADDR=$I2C_EDID_MAP
let "WADDR<<=1"
i2cset -y $I2C_BUS $I2C_ADV7611 0xfa $WADDR      # EDID Map I2C address 
WADDR=$I2C_HDMI_MAP
let "WADDR<<=1"
i2cset -y $I2C_BUS $I2C_ADV7611 0xfb $WADDR      # HDMI Map I2C address
WADDR=$I2C_CP_MAP
let "WADDR<<=1"
i2cset -y $I2C_BUS $I2C_ADV7611 0xfd $WADDR      # CP Map I2C  address

# startup routine
i2cset -y 1 0x4c 0x01 0x06	# V-FREQ = 60Hz 
			# Prim_Mode = HDMI-GR 
i2cset -y 1 0x4c 0x02 0xf2	# Auto CSC, RGB out 
			# Disable op_656 bit 
i2cset -y 1 0x4c 0x03 0x42	# 36 bit SDR 444 Mode 0 
i2cset -y 1 0x4c 0x05 0x28	# AV Codes Off 
i2cset -y 1 0x4c 0x0b 0x44	# Power up part 
i2cset -y 1 0x4c 0x0c 0x42	# Power up part 
i2cset -y 1 0x4c 0x14 0x7f	# Max Drive Strength 
i2cset -y 1 0x4c 0x15 0x80	# Disable Tristate of Pins 
			# (Audio output pins active) 
i2cset -y 1 0x4c 0x19 0x83	# LLC DLL phase 
i2cset -y 1 0x4c 0x33 0x40	# LLC DLL enable 

i2cset -y $I2C_BUS $I2C_CP_MAP 0xba 0x01 # Set HDMI FreeRun
i2cset -y $I2C_BUS $I2C_CP_MAP 0x3e 0x80 # Enable color adjustment

i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x9b 0x03 # ADI recommended setting
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x00 0x08 # Set HDMI Input Port A
                                           # (BG_MEAS_PORT_SEL = 001b)
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x02 0x03 # Enable Ports A & B in
                                           # background mode
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x6d 0x80 # Enable TDM mode
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x03 0x18 # I2C mode 24 bits
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x83 0xfc # Enable clock terminators
                                           # for port A & B
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x6f 0x0c # ADI recommended setting
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x85 0x1f # ADI recommended setting
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x87 0x70 # ADI recommended setting
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x8d 0x04 # LFG Port A
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x8e 0x1e # HFG Port A
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x1a 0x8a # unmute audio
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x57 0xda # ADI recommended setting
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x58 0x01 # ADI recommended setting
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x75 0x10 # DDC drive strength
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x90 0x04 # LFG Port B
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x91 0x1e # HFG Port B
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x04 0x03
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x14 0x00
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x15 0x00
i2cset -y $I2C_BUS $I2C_HDMI_MAP 0x16 0x00

i2cset -y $I2C_BUS $I2C_KSV_MAP 0x40 0x81 # Disable HDCP 1.1 features
i2cset -y $I2C_BUS $I2C_KSV_MAP 0x74 0x01 # Enable the Internal EDID
