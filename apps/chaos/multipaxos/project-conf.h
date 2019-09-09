/*******************************************************************************
 * BSD 3-Clause License
 *
 * Copyright (c) 2017 Beshr Al Nahas and Olaf Landsiedel.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/
/**
 * \file
 *         A2-Synchrotron project config.
 * \author
 *         Beshr Al Nahas <beshr@chalmers.se>
 *         Olaf Landsiedel <olafl@chalmers.se>
 *
 */
#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

#undef COOJA
#define COOJA 1

#define ENABLE_MULTIPLE_INITIATORS 0
#define N_SOURCES 1

#define CC2420_FAST_TURNAROUND 0 //1: fast -- 8 symbols = 128us, else: 12 symbols = 192us --> 2 symbols in DCO 4MHz ticks = 32*10^(-6)/(2^(-22)) = 134.22

#define N_TX_COMPLETE 9
#define CHAOS_RESTART_MIN 4 // 4
#define CHAOS_RESTART_MAX 10 // 10

#if COOJA
#define MULTIPAXOS_ROUND_MAX_SLOTS   (254)
//join parameters
#define JOIN_ROUND_MAX_SLOTS   (254)
#define JOIN_ROUNDS_AFTER_BOOTUP (5)
//restart every 10
#define CHAOS_SYSTEM_STRESS_TEST (0)
#else
#define MULTIPAXOS_ROUND_MAX_SLOTS   (354)
//join parameters
#define JOIN_ROUND_MAX_SLOTS   (260)
#define JOIN_ROUNDS_AFTER_BOOTUP (20)
//restart every 60
#define CHAOS_SYSTEM_STRESS_TEST (0)
#endif

#undef LLSEC802154_CONF_SECURITY_LEVEL
#ifndef _param_sec
#define LLSEC802154_CONF_SECURITY_LEVEL 5
#else
#define LLSEC802154_CONF_SECURITY_LEVEL _param_sec //MIC
#endif

#undef JOIN_STRESS_TEST
#ifndef _param_join
#define JOIN_STRESS_TEST 0
#else
#define JOIN_STRESS_TEST (_param_join == 2)
#endif

//remember to disable logs
#undef WITH_CHAOS_LOG
#ifndef _param_log
#define WITH_CHAOS_LOG 0
#else
#define WITH_CHAOS_LOG _param_log
#endif
//don't disable PRINTF if logs are enabled ;)
#undef CHAOS_DEBUG_PRINTF
#ifndef _param_printf
#define CHAOS_DEBUG_PRINTF 1
#else
#define CHAOS_DEBUG_PRINTF _param_printf
#endif
//disable logging of flags since it takes a long time
#undef CHAOS_LOG_FLAGS
#ifndef _param_logflags
#define CHAOS_LOG_FLAGS 0
#else
#define CHAOS_LOG_FLAGS _param_logflags
#endif

#undef CHAOS_USE_SRC_ID
#ifdef _param_src
#define CHAOS_USE_SRC_ID 2
#else
#define CHAOS_USE_SRC_ID _param_src
#endif

#ifndef _param_dst
#undef CHAOS_USE_DST_ID
#define CHAOS_USE_DST_ID _param_dst
#endif

#ifdef _param_sync
#undef CHAOS_ENABLE_SFD_SYNC
#define CHAOS_ENABLE_SFD_SYNC _param_sync
#endif

#ifdef _param_rank
#undef CHAOS_USE_SRC_RANK
#define CHAOS_USE_SRC_RANK _param_rank
#endif

#ifdef _param_interval
/* Chaos timing */
#undef CHAOS_INTERVAL
#define CHAOS_INTERVAL   (_param_interval*(RTIMER_SECOND/10))
//(40*(RTIMER_SECOND/10))
#endif

#ifdef _param_cg
#undef CHAOS_RF_CHANNEL
#define CHAOS_RF_CHANNEL _param_ch
#endif

#ifdef _param_max_node_count
#undef MAX_NODE_COUNT
#define MAX_NODE_COUNT _param_max_node_count
#endif

#ifdef _param_mch
#undef CHAOS_MULTI_CHANNEL
#define CHAOS_MULTI_CHANNEL _param_mch
#endif

#ifdef _param_pch
#undef CHAOS_MULTI_CHANNEL_PARALLEL_SEQUENCES
#define CHAOS_MULTI_CHANNEL_PARALLEL_SEQUENCES _param_pch
#endif

#define TXPW0 31 //max
#define TXPW1 27
#define TXPW2 23
#define TXPW3 19
#define TXPW4 15
#define TXPW5 11
#define TXPW6 7
#define TXPW7 3 //min

#ifdef _param_txpw
#undef CHAOS_TX_POWER
#define CHAOS_TX_POWER _param_txpw
#endif
//TX_POWER
//  {  0, 31 }, /* 0xff */
//  { -1, 27 }, /* 0xfb */
//  { -3, 23 }, /* 0xf7 */
//  { -5, 19 }, /* 0xf3 */
//  { -7, 15 }, /* 0xef */
//  {-10, 11 }, /* 0xeb */
//  {-15,  7 }, /* 0xe7 */
//  {-25,  3 }, /* 0xe3 */

////how many rounds are considered association rounds? (thus, have shorter restart threshold)
//#define ASSOCIATE_ROUND_NUMBER ( 20 )
//#define ASSOCIATE_ROUND_RESTART_THRESHOLD ( 2 )


/* no need to touch these */
#undef RTIMER_CONF_SECOND
#define RTIMER_CONF_SECOND (4096U*4)

/* how many failed rounds to allow before associating again? */
#undef CHAOS_FAILED_ROUNDS_RESYNC_THRESHOLD
#define CHAOS_FAILED_ROUNDS_RESYNC_THRESHOLD (10)

//no need for the led :)
//for SKY
#undef PRINT_STACK_ON_REBOOT
#define PRINT_STACK_ON_REBOOT 0

//#undef ENABLE_COOJA_DEBUG
//#define ENABLE_COOJA_DEBUG 1

#define EWSN_LEDS_AFTER_ROUND 0

#if WITH_CHAOS_LOG && !CHAOS_DEBUG_PRINTF
#error "Fix me: PRINTF disabled and CHAOS_LOG enabled!"
#endif

//
///* a big number used only in the association phase */
//#define EWSN_ROUND_MAX_SLOTS   (MIN(CHAOS_INTERVAL/EWSN_SLOT_LEN - 10,200))
///* the actual limit that is enforced after the association rounds!! */
//#define EWSN_ROUND_MAX_APP_SLOTS   (100)

//lower tick rate
//#undef CLOCK_CONF_SECOND
//#define CLOCK_CONF_SECOND 1UL



//#define SKY_DISABLE_WDT 1

#undef QUEUEBUF_CONF_NUM
#define QUEUEBUF_CONF_NUM                0

#undef CC2420_CONF_AUTOACK
#define CC2420_CONF_AUTOACK              0

#undef CC2420_FAST_TURNAROUND
#define CC2420_FAST_TURNAROUND 1 //1: fast -- 8 symbols = 128us, else: 12 symbols = 192us --> 2 symbols in DCO 4MHz ticks = 32*10^(-6)/(2^(-22)) = 134.22
#undef CC2420_CORR_THR
#define CC2420_CORR_THR (20)
#undef CC2420_continuously_update_frequency_offset_filter
#define CC2420_continuously_update_frequency_offset_filter (0)
#undef CC2420_PREAMBLE_LENGTH
#define CC2420_PREAMBLE_LENGTH 2 // 2 is default -- compatible with 802.15.4. It should be between 0-15 --> 1-16 zero leading bytes

#undef DCOSYNCH_CONF_ENABLED
#define DCOSYNCH_CONF_ENABLED            0

/* we have to disable DMA in order to save power and enable LPM3 for the CPU */
#undef UART1_CONF_RX_WITH_DMA
#define UART1_CONF_RX_WITH_DMA           0

#undef UART1_CONF_TX_WITH_DMA
#define UART1_CONF_TX_WITH_DMA           0

#undef UART0_CONF_RX_WITH_DMA
#define UART0_CONF_RX_WITH_DMA           0

#undef UART0_CONF_TX_WITH_DMA
#define UART0_CONF_TX_WITH_DMA           1

//remove processes names to avoid printing them
#undef PROCESS_CONF_NO_PROCESS_NAMES
#define PROCESS_CONF_NO_PROCESS_NAMES 0

#undef LOG_CONF_ENABLED
#define LOG_CONF_ENABLED 0

#undef ENERGEST_CONF_ON
#define ENERGEST_CONF_ON 0


#endif /* PROJECT_CONF_H_ */

