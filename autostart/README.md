This directory contains launch shell scripts and .service files. They can be used to make your system start automatically.

## Setting up automatic ROV/AUV launch:
- copy rov_launch.sh to /home/ubuntu/launch.sh 
- copy rov_enbarr.service to /etc/systemd/user/enbarr.service
- run `sudo systemctl enable enbarr.service`

On your next start, the system should run automatically.

## Setting up automatic surface station launch:
As above, but surface
