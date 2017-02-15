/*********************IMPORTANT DRAKVUF LICENSE TERMS***********************
 *                                                                         *
 * DRAKVUF (C) 2014-2017 Tamas K Lengyel.                                  *
 * Tamas K Lengyel is hereinafter referred to as the author.               *
 * This program is free software; you may redistribute and/or modify it    *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation; Version 2 ("GPL"), BUT ONLY WITH ALL OF THE   *
 * CLARIFICATIONS AND EXCEPTIONS DESCRIBED HEREIN.  This guarantees your   *
 * right to use, modify, and redistribute this software under certain      *
 * conditions.  If you wish to embed DRAKVUF technology into proprietary   *
 * software, alternative licenses can be aquired from the author.          *
 *                                                                         *
 * Note that the GPL places important restrictions on "derivative works",  *
 * yet it does not provide a detailed definition of that term.  To avoid   *
 * misunderstandings, we interpret that term as broadly as copyright law   *
 * allows.  For example, we consider an application to constitute a        *
 * derivative work for the purpose of this license if it does any of the   *
 * following with any software or content covered by this license          *
 * ("Covered Software"):                                                   *
 *                                                                         *
 * o Integrates source code from Covered Software.                         *
 *                                                                         *
 * o Reads or includes copyrighted data files.                             *
 *                                                                         *
 * o Is designed specifically to execute Covered Software and parse the    *
 * results (as opposed to typical shell or execution-menu apps, which will *
 * execute anything you tell them to).                                     *
 *                                                                         *
 * o Includes Covered Software in a proprietary executable installer.  The *
 * installers produced by InstallShield are an example of this.  Including *
 * DRAKVUF with other software in compressed or archival form does not     *
 * trigger this provision, provided appropriate open source decompression  *
 * or de-archiving software is widely available for no charge.  For the    *
 * purposes of this license, an installer is considered to include Covered *
 * Software even if it actually retrieves a copy of Covered Software from  *
 * another source during runtime (such as by downloading it from the       *
 * Internet).                                                              *
 *                                                                         *
 * o Links (statically or dynamically) to a library which does any of the  *
 * above.                                                                  *
 *                                                                         *
 * o Executes a helper program, module, or script to do any of the above.  *
 *                                                                         *
 * This list is not exclusive, but is meant to clarify our interpretation  *
 * of derived works with some common examples.  Other people may interpret *
 * the plain GPL differently, so we consider this a special exception to   *
 * the GPL that we apply to Covered Software.  Works which meet any of     *
 * these conditions must conform to all of the terms of this license,      *
 * particularly including the GPL Section 3 requirements of providing      *
 * source code and allowing free redistribution of the work as a whole.    *
 *                                                                         *
 * Any redistribution of Covered Software, including any derived works,    *
 * must obey and carry forward all of the terms of this license, including *
 * obeying all GPL rules and restrictions.  For example, source code of    *
 * the whole work must be provided and free redistribution must be         *
 * allowed.  All GPL references to "this License", are to be treated as    *
 * including the terms and conditions of this license text as well.        *
 *                                                                         *
 * Because this license imposes special exceptions to the GPL, Covered     *
 * Work may not be combined (even as part of a larger work) with plain GPL *
 * software.  The terms, conditions, and exceptions of this license must   *
 * be included as well.  This license is incompatible with some other open *
 * source licenses as well.  In some cases we can relicense portions of    *
 * DRAKVUF or grant special permissions to use it in other open source     *
 * software.  Please contact tamas.k.lengyel@gmail.com with any such       *
 * requests.  Similarly, we don't incorporate incompatible open source     *
 * software into Covered Software without special permission from the      *
 * copyright holders.                                                      *
 *                                                                         *
 * If you have any questions about the licensing restrictions on using     *
 * DRAKVUF in other works, are happy to help.  As mentioned above,         *
 * alternative license can be requested from the author to integrate       *
 * DRAKVUF into proprietary applications and appliances.  Please email     *
 * tamas.k.lengyel@gmail.com for further information.                      *
 *                                                                         *
 * If you have received a written license agreement or contract for        *
 * Covered Software stating terms other than these, you may choose to use  *
 * and redistribute Covered Software under those terms instead of these.   *
 *                                                                         *
 * Source is provided to this software because we believe users have a     *
 * right to know exactly what a program is going to do before they run it. *
 * This also allows you to audit the software for security holes.          *
 *                                                                         *
 * Source code also allows you to port DRAKVUF to new platforms, fix bugs, *
 * and add new features.  You are highly encouraged to submit your changes *
 * on https://github.com/tklengyel/drakvuf, or by other methods.           *
 * By sending these changes, it is understood (unless you specify          *
 * otherwise) that you are offering unlimited, non-exclusive right to      *
 * reuse, modify, and relicense the code.  DRAKVUF will always be          *
 * available Open Source, but this is important because the inability to   *
 * relicense code has caused devastating problems for other Free Software  *
 * projects (such as KDE and NASM).                                        *
 * To specify special license conditions of your contributions, just say   *
 * so when you send them.                                                  *
 *                                                                         *
 * This program is distributed in the hope that it will be useful, but     *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the DRAKVUF   *
 * license file for more details (it's in a COPYING file included with     *
 * DRAKVUF, and also available from                                        *
 * https://github.com/tklengyel/drakvuf/COPYING)                           *
 *                                                                         *
 ***************************************************************************/

#ifndef SOCKETMON_PRIVATE_H
#define SOCKETMON_PRIVATE_H

struct pool_header_x86 {
    union {
        struct {
            uint16_t previous_size :9;
            uint16_t pool_index :7;
            uint16_t block_size :9; // bits 0-9
            uint16_t pool_type :7; // bits 10-16
        };
        uint16_t flags;
    };
    uint32_t pool_tag;
}__attribute__ ((packed));

struct pool_header_x64 {
    union {
        struct {
            uint32_t previous_size :8;
            uint32_t pool_index :8;
            uint32_t block_size :8;
            uint32_t pool_type :8;
        };
        uint32_t flags;
    };
    uint32_t pool_tag;
    uint64_t process_billed; // _EPROCESS *
}__attribute__ ((packed));

/* TcpL */
struct tcp_listener_x86 {
    uint8_t _pad1[0x18];
    uint32_t owner;
    uint32_t _pad2;
    uint64_t createtime;
    uint8_t _pad3[0xc];
    uint32_t localaddr;
    uint32_t inetaf;
    uint8_t _pad4[0x2];
    uint16_t port;
}__attribute__ ((packed));

struct tcp_listener_x64 {
    uint8_t _pad1[0x20];
    uint64_t createtime;
    uint64_t owner;
    uint8_t _pad2[0x28];
    uint64_t localaddr;
    uint64_t inetaf;
    uint8_t _pad3[0x2];
    uint16_t port;
}__attribute__ ((packed));

/* TcpE */
enum tcp_state {
    CLOSED = 0,
    LISTENING = 1,
    SYN_SENT = 2,
    SYN_RCVD = 3,
    ESTABLISHED = 4,
    FIN_WAIT1 = 5,
    FIN_WAIT2 = 6,
    CLOSE_WAIT = 7,
    CLOSING = 8,
    LIST_ACK = 9,
    TIME_WAIT = 12,
    DELETE_TCB = 13,
    __TCP_STATE_MAX
};

static const char *tcp_state_str[] = {
    [CLOSED] = "closed",
    [LISTENING] = "listening",
    [SYN_SENT] = "syn_sent",
    [SYN_RCVD] = "syn_rcvd",
    [ESTABLISHED] = "established",
    [FIN_WAIT1] = "fin_wait1",
    [FIN_WAIT2] = "fin_wait2",
    [CLOSE_WAIT] = "close_wait",
    [CLOSING] = "closing",
    [LIST_ACK] = "list_ack",
    [TIME_WAIT] = "time_wait",
    [DELETE_TCB] = "delete_tcb",
    [10] = "__undefined__",
    [11] = "__undefined__"
};

struct tcp_endpoint_x86 {
    uint64_t createtime;
    uint32_t _pad1;
    uint32_t inetaf;
    uint32_t addrinfo;
    uint32_t listentry;
    uint8_t _pad2[0x1c];
    uint32_t state;
    uint16_t localport;
    uint16_t remoteport;
    uint8_t _pad3[0x138];
    uint32_t owner;
}__attribute__ ((packed));

struct tcp_endpoint_x64 {
    uint8_t _pad1[0x18];
    uint64_t inetaf;
    uint64_t addrinfo;
    uint64_t listentry;
    uint8_t _pad2[0x38];
    uint32_t state;
    uint16_t localport;
    uint16_t remoteport;
    uint8_t _pad3[0x1c8];
    uint64_t owner;
}__attribute__ ((packed));

struct addr_info_x86 {
    uint32_t local; // local_address
    uint32_t _pad;
    uint32_t remote; // ipv4/ipv6
} __attribute__ ((packed));

struct addr_info_x64 {
    uint64_t local;
    uint64_t _pad;
    uint64_t remote;
} __attribute__ ((packed));

struct local_address_x86 {
    uint8_t _pad[0xc];
    uint32_t pdata;
}__attribute__ ((packed));

struct local_address_x64 {
    uint8_t _pad[0x10];
    uint64_t pdata;
}__attribute__ ((packed));

#ifndef AF_INET
#define AF_INET     0x2
#endif
#ifndef AF_INET6
#define AF_INET6    0x17
#endif

struct inetaf_x86 {
    uint8_t _pad[0xc];
    uint8_t addressfamily;
}__attribute__ ((packed));

struct inetaf_x64 {
    uint8_t _pad[0x14];
    uint8_t addressfamily;
}__attribute__ ((packed));

/* UdpA */
struct udp_endpoint_x86 {
    uint8_t _pad1[0x14];
    uint32_t inetaf;
    uint32_t owner;
    uint8_t _pad2[0x14];
    uint64_t createtime;
    uint32_t localaddr;
    uint8_t _pad3[0xc];
    uint16_t port;
}__attribute__ ((packed));

struct udp_endpoint_x64 {
    uint8_t _pad1[0x20];
    uint64_t inetaf;
    uint64_t owner;
    uint8_t _pad2[0x28];
    uint64_t createtime;
    uint64_t localaddr;
    uint8_t _pad3[0x18];
    uint16_t port;
}__attribute__ ((packed));

#endif
