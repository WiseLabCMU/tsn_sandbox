/**
 * Author: Reese Grimsley
 * Created on 10/29/21
 * 
 */ 
#ifndef __ETH_HELPERS__
#define __ETH_HELPERS__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <linux/if_packet.h>
#include <linux/sockios.h>
#include <linux/net_tstamp.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <errno.h>
#include <pthread.h>

#include "constants.h"

int configure_hw_timestamping(int sock_fd);
int get_hw_timestamp_from_msg(struct msghdr* msg, struct timespec* ts);



#endif