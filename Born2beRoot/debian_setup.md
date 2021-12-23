partitioning scheme
```sh
lsblk 
```
information about the system
```sh
cat /etc/os-release
```
required packages installation
```sh
apt-get install sudo ufw vim openssh-server libpam-pwquality apparmor cron
```

### SSH
open/close ports by editing `/etc/ssh/sshd_config` file
```sh
Port 4242 
PermitRootLogin no
```
to view SSH status
```sh
systemctl status ssh
```

### UFW
enable UFW
```sh
ufw enable
```
view status
```sh
ufw status
```
set default rules
```sh
ufw default deny incoming
ufw default allow outgoing
```
add new rule
```sh
ufw allow 4242
```
delete rule
```sh
ufw delete allow <port>
```

### PORT FORWARDING & CONNECTING USING SSH
Settings -> Network -> "Attached to NAT" -> Advanced -> Port Forwarding -> add 4242 port
to remotely connect to the server, run in your terminal
```sh
ssh <user>@<ip address> -p <port>
```

### HOSTNAME
view your hostname
```sh
hostname
```
to change it, edit `/etc/hostname` and `/etc/hosts` files and reboot 

### NEW USERS & GROUPS
add new user
```sh
sudo useradd <user> 
```
assign password for the user
```sh
sudo passwd <user>
```
add user to a group
```sh
usermod -aG <group> <user>
```
delete user from a group
```sh
gpasswd -d <user> <group>
```
delete user
```sh
deluser <user>
```

### SUDO PERMISSIONS & TTY
after creating a new user and assigning it to `sudo` group, add rules for `sudo` in `/etc/sudoers` file
```sh
<user> ALL=(ALL:ALL) ALL
Defaults badpass_message="Your phrase" 
Defaults passwd_tries=3
```
for logging `sudo`, create `/var/log/sudo` directory and `sudo.log` file there
edit `/etc/sudoers` file
```sh
Defaults logfile="/var/log/sudo/sudo.log" 
Defaults iolog_dir="/var/log/sudo"
Defaults log_input,log_output 
Defaults requiretty 
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
```

### SCRIPT & CRON
create a `monitoring.sh` file, change permission settings for it
```sh
chmod +x ./monitoring.sh
```
open `crontab -e` file from root and edit it
```sh
*/10 * * * * sh /usr/local/bin/monitoring.sh
```
to stop the cronjob, simply comment the line

### PASSWORD POLICY
edit `/etc/login.defs` file
```sh
PASS_MAX_DAYS 30 
PASS_MIN_DAYS 2 
PASS_WARN_AGE 7
```
edit `/etc/security/pwquality.conf` file
```sh
difok = 7 
minlen = 10 
dcredit = -1 
ucredit = -1 
maxrepeat = 3 
usercheck = 1 
enforce_for_root)
```