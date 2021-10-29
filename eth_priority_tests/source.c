/**
 * 
 * The source will inject data into the ethernet interface; we want to see what the latency (distribution)
 *      is when a jammer is running on the same network (through a TSN switch -- Hirschman BRS8TX).
 * The network traffic from the sink should be prioritized and sent through a VLAN to be given preference over the 
 *      generic traffic from the jammer
 * 
 * Assumed platform: Ubuntu 20.04 LTS, Intel Nuc (series 11), NIC i225
 *     Must be run as SUDO!
 * 
 * Author: Reese Grimsley
 * Created: 10/29/21
 *
 * Raw sockets references:
 *  https://www.binarytides.com/raw-sockets-c-code-linux/
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>

#include "constants.h"

struct timespec wait_duration = {.tv_sec = 0, .tv_nsec = 500000000};


int main(int argc, char* argv[])
{

    //configure the socket
    int send_sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_TSN));
    if( send_sock == -1)
    {
        printf("Send socket returned err: [%d]\n", errno);
        exit(errno);
    }   

    struct sockaddr_ll addr;
    struct ifreq ifr;

    memset(addr, 0, sizeof(addr));

    int eth_interface_index = get_eth_index_num(&ifr);
    if (eth_interface_index < 0)
    {
        printf("did not find a valid ethernet interface named %s", ETH_INTERFACE_I225);
        return eth_interface_index;
    }
    

    addr.sll_family = AF_PACKET;
    addr.sll_procotol = htons(ETH_P_TSN);
    addr.sll_ifindex = eth_interface_index;
    addr.sll_halen = ETH_MAC_ADDR_LEN;
    addr.sll_pkttype = PACKET_OTHERHOST;

    //send packets

    struct ether_tsn tsn_ethernet;

    while(1)
    {
        break;   

        wait(wait_duration);
    }



}

