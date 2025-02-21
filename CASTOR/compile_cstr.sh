#!/bin/bash

# Compile CASToR.
unzip castor_v3.2.1.zip

cd castor_v3.2

export CASTOR_CONFIG=/home/vgate/MSFMC/CASTOR/castor_v3.2/config/
export CASTOR_ROOT=1

make

echo 'export PATH=$PATH:/home/vgate/MSFMC/CASTOR/castor_v3.2/bin' >> /home/vgate/.bashrc



