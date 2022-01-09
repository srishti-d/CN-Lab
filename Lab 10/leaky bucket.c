#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define NOF_PACKETS 5
/*
int rand (int a)
{
int rn = (random() % 10) % a;
return rn == 0 ? 1 : rn;
}
*/
/*
#include &lt;stdlib.h&gt;
long int random(void);

3

The random() function uses a nonlinear additive feedback random number
generator employing a default ta‐
ble of size 31 long integers to return successive pseudo-random numbers in the
range from 0 to RAND_MAX.
The period of this random number generator is very large, approximately 16 *
((2^31) - 1).
*/
int main()
{
int packet_sz[NOF_PACKETS], i, clk, b_size, o_rate, p_sz_rm=0, p_sz, p_time, op;
for(i = 0; i<NOF_PACKETS; ++i)
packet_sz[i] = random() % 100;
for(i = 0; i<NOF_PACKETS; ++i)
printf("\npacket[%d]:%d bytes\t", i, packet_sz[i]);
printf("\nEnter the Output rate:");
scanf("%d", &o_rate);
printf("Enter the Bucket Size:");
scanf("%d", &b_size);
for(i = 0; i<NOF_PACKETS; ++i)
{
if( (packet_sz[i] + p_sz_rm) > b_size)
if(packet_sz[i] > b_size)/*compare the packet siz with bucket size*/
printf("\n\nIncoming packet size (%dbytes) is Greater than bucket capacity (%dbytes)-PACKET REJECTED", packet_sz[i], b_size);
else
printf("\n\nBucket capacity exceeded-PACKETS REJECTED!!");
else
{
p_sz_rm += packet_sz[i];
printf("\n\nIncoming Packet size: %d", packet_sz[i]);
printf("\nBytes remaining to Transmit: %d", p_sz_rm);
//p_time = random() * 10;
//printf(&quot;\nTime left for transmission: %d units&quot;, p_time);
//for(clk = 10; clk &lt;= p_time; clk += 10)
while(p_sz_rm>0)
{
sleep(1);
if(p_sz_rm)
{
if(p_sz_rm <= o_rate)/*packet size remaining comparing with output rate*/
op = p_sz_rm, p_sz_rm = 0;
else
op = o_rate, p_sz_rm -= o_rate;
printf("\nPacket of size %d Transmitted", op);
printf("----Bytes Remaining to Transmit: %d", p_sz_rm);
}
else
{
printf("\nNo packets to transmit!!");
}
}
}
}
}
