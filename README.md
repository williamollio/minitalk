# 42 Minitalk
Summary:

The purpose of this project is to code a small data exchange program using UNIX signals.

Foreword:

The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily liquid with an intense grassy-green odor of freshly cut green grass and leaves.
It is produced in small amounts by most plants and it acts as an attractant to many predatory insects. cis-3-Hexen-1-ol is a very important aroma compound that is used in fruit and vegetable flavors and in perfumes.
The yearly production is about 30 tonnes.

Wikipedia article about bitwise operation: https://en.wikipedia.org/wiki/Bitwise_operation

Wikipedia article about signals in C : https://en.wikipedia.org/wiki/C_signal_handling

[Subject PDF](https://github.com/williamollio/minitalk/blob/master/subject/minitalk.pdf)

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# Run
Go to the created repository and run following command:
```
make
```
To start run following command :
```
./server
```
After opening another terminal in the same folder, run the following command :
```
./client <client PID> <string to sent>
```
Finally, run this one to delete the outputs files and the librairy created :
```
make fclean
```
# Bonus
Run the followings commands :
```
make bonus
```
Then :
```
./server
```
And :
```
./client <client PID> <string to sent>
```
Finally, run this one to delete the outputs files and the librairy created :
```
make fclean
```
# Explanations

Each characters of the string are sent bits by bits thanks to bitwise operators. In C, a character has a size of one byte (8 bits). The bits are sent from the client to server by using the signals `SIGUSR1` and `SIGUSR2`, each standing for the 0 and 1 respectively.
In the bonus part, when the server will receive the null-terminator character from the client. It will send back a signal to client. Thanks to the bitwise operators, the programs support the unicode characters. Which was not possible with my initial implementation :
- Where I was first converting each characters into its binary value (in a string format).
- Then I was going through the created string and using the same signals when encountering either 0 or 1.

# Sigaction function

In order to send back a signal from the server to the client, I have used the sigaction function, with which I am able to get the pid of the sending process (in this case the client). Here is its structure :
```
struct sigaction {
	void     (*sa_handler)(int);
	void     (*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t   sa_mask;
	int        sa_flags;
	void     (*sa_restorer)(void);
};
```
