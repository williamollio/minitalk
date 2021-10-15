# 42 Minitalk
Summary:

The purpose of this project is to code a small data exchange program using UNIX signals.

Foreword:

The cis-3-Hexen-1-ol, also known as (Z)-3-hexen-1-ol and leaf alcohol, is a colorless oily liquid with an intense grassy-green odor of freshly cut green grass and leaves.
It is produced in small amounts by most plants and it acts as an attractant to many predatory insects. cis-3-Hexen-1-ol is a very important aroma compound that is used in fruit and vegetable flavors and in perfumes.
The yearly production is about 30 tonnes.

Links:

Wikipedia article about bitwise operation: https://en.wikipedia.org/wiki/Bitwise_operation

Wikipedia article about signals in C : https://en.wikipedia.org/wiki/C_signal_handling

Subject PDF: https://github.com/williamollio/minitalk/blob/master/subject/minitalk.pdf

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# Run
Go to created repository and run following command:
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
Finally, run to delete the outputs files and the librairy created :
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
Finally, run to delete the outputs files and the librairy created :
```
make fclean
```