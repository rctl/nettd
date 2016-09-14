# nettd - A super simple TCP server

nettd is a really easy to use and lightweight TCP server that can be combined with other tools.

nettd simply receives data over TCP and prints it to stdout.

## Examples
Below are some examples of how to use nettd in your terminal.

**Receiving a simple message**

``$ nettd receive 1337``

The above command will start a TCP server listening on port 1337, to transmitt data to the server you can use:

``$ echo "My message" | telnet x.x.x.x 1337``

Replace *x.x.x.x* with the ip address running the nettd server.

**Transfering a file**

On recipient run:

``$ nettd receive 1337 > file.txt``

On sender run:

``$ cat file.txt | telnet x.x.x.x 1337``

Replace *x.x.x.x* with the ip address running the nettd server.

**Transfering a file with encryption**

On recipient run: 

``nettd receive 1337 | openssl enc -aes-256-cbc -d -a > file.txt``

You will be prompted to enter a password, select a secure password here.

On sender run:

``$ cat file.txt | openssl enc -aes-256-cbc -e -a | telnet x.x.x.x 1337``

Replace *x.x.x.x* with the ip address running the nettd server.
You will also be promted for a password here. Use the same password on sender and recipient.