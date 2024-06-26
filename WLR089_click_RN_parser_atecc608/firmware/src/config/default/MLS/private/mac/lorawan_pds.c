/**
* \file  lorawan_pds.c
*
* \brief This file is for the PDS defs for LoraWAN Module
*
*
*/
/*******************************************************************************
Copyright (C) 2020-21 released Microchip Technology Inc. and its subsidiaries.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR
*******************************************************************************/



#include "pds_interface.h"
#include "lorawan.h"
#include "lorawan_private.h"
extern LoRa_t loRa;
#include "lorawan_pds.h"

/* PDS MAC Item declaration */

const ItemMap_t pds_mac_fid1_item_list[] = {
    DECLARE_ITEM(PDS_MAC_ISM_BAND_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 (uint8_t)PDS_MAC_ISM_BAND,
                 PDS_MAC_ISM_BAND_SIZE,
                 PDS_MAC_ISM_BAND_OFFSET),
    DECLARE_ITEM(PDS_MAC_ED_CLASS_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_ED_CLASS,
                 PDS_MAC_ED_CLASS_SIZE,
                 PDS_MAC_ED_CLASS_OFFSET),
    DECLARE_ITEM(PDS_MAC_PERIOD_FOR_LINK_CHK_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_PERIOD_FOR_LINK_CHK,
                 PDS_MAC_PERIOD_FOR_LINK_CHK_SIZE,
                 PDS_MAC_PERIOD_FOR_LINK_CHK_OFFSET),
    DECLARE_ITEM(PDS_MAC_SYNC_WORD_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_SYNC_WORD,
                 PDS_MAC_SYNC_WORD_SIZE,
                 PDS_MAC_SYNC_WORD_OFFSET),
    DECLARE_ITEM(PDS_MAC_EVENT_MASK_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_EVENT_MASK,
                 PDS_MAC_EVENT_MASK_SIZE,
                 PDS_MAC_EVENT_MASK_OFFSET),
    DECLARE_ITEM(PDS_MAC_MCAST_FCNT_DWN_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_MCAST_FCNT_DWN,
                 PDS_MAC_MCAST_FCNT_DWN_SIZE,
                 PDS_MAC_MCAST_FCNT_DWN_OFFSET),
    DECLARE_ITEM(PDS_MAC_MCAST_DEV_ADDR_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_MCAST_DEV_ADDR,
                 PDS_MAC_MCAST_DEV_ADDR_SIZE,
                 PDS_MAC_MCAST_DEV_ADDR_OFFSET),
    DECLARE_ITEM(PDS_MAC_MCAST_APP_SKEY_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_MCAST_APP_SKEY,
                 PDS_MAC_MCAST_APP_SKEY_SIZE,
                 PDS_MAC_MCAST_APP_SKEY_OFFSET),
    DECLARE_ITEM(PDS_MAC_MCAST_NWK_SKEY_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_MCAST_NWK_SKEY,
                 PDS_MAC_MCAST_NWK_SKEY_SIZE,
                 PDS_MAC_MCAST_NWK_SKEY_OFFSET),
    DECLARE_ITEM(PDS_MAC_MCAST_KEYS_ADDR,
                PDS_FILE_MAC_01_IDX,
                PDS_MAC_MCAST_KEYS,
                PDS_MAC_MCAST_KEYS_SIZE,
                PDS_MAC_MCAST_KEYS_OFFSET),
    DECLARE_ITEM(PDS_MAC_MCAST_GROUP_MASK_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_MCAST_GROUP_MASK,
                 PDS_MAC_MCAST_GROUP_MASK_SIZE,
                 PDS_MAC_MCAST_GROUP_MASK_OFFSET),
    DECLARE_ITEM(PDS_MAC_MCAST_SUPPORTED_GROUP_CNTR_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_MCAST_SUPPORTED_GROUP_CNTR,
                 PDS_MAC_MCAST_SUPPORTED_GROUP_CNTR_SIZE,
                 PDS_MAC_MCAST_SUPPORTED_GROUP_CNTR_OFFSET),
    DECLARE_ITEM(PDS_MAC_LBT_PARAMS_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_LBT_PARAMS,
                 PDS_MAC_LBT_PARAMS_SIZE,
                 PDS_MAC_LBT_PARAMS_OFFSET),
    DECLARE_ITEM(PDS_MAC_TX_POWER_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_PRESCALR,
                 PDS_MAC_TX_POWER_SIZE,
                 PDS_MAC_TX_POWER_OFFSET),
    DECLARE_ITEM(PDS_MAC_PRESCALR_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_TX_POWER,
                 PDS_MAC_PRESCALR_SIZE,
                 PDS_MAC_PRESCALR_OFFSET),
    DECLARE_ITEM(PDS_MAC_RX_DELAY_1_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_RX_DELAY_1,
                 PDS_MAC_RX_DELAY_1_SIZE,
                 PDS_MAC_RX_DELAY_1_OFFSET),
    DECLARE_ITEM(PDS_MAC_RX_DELAY_2_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_RX_DELAY_2,
                 PDS_MAC_RX_DELAY_2_SIZE,
                 PDS_MAC_RX_DELAY_2_OFFSET),
    DECLARE_ITEM(PDS_MAC_JOIN_ACCEPT_DELAY_1_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_JOIN_ACCEPT_DELAY_1,
                 PDS_MAC_JOIN_ACCEPT_DELAY_1_SIZE,
                 PDS_MAC_JOIN_ACCEPT_DELAY_1_OFFSET),
    DECLARE_ITEM(PDS_MAC_JOIN_ACCEPT_DELAY_2_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_JOIN_ACCEPT_DELAY_2,
                 PDS_MAC_JOIN_ACCEPT_DELAY_2_SIZE,
                 PDS_MAC_JOIN_ACCEPT_DELAY_2_OFFSET),
    DECLARE_ITEM(PDS_MAC_RETRANSMIT_TIMEOUT_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_RETRANSMIT_TIMEOUT,
                 PDS_MAC_RETRANSMIT_TIMEOUT_SIZE,
                 PDS_MAC_RETRANSMIT_TIMEOUT_OFFSET),
    DECLARE_ITEM(PDS_MAC_ADR_ACK_LIMIT_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_ADR_ACK_LIMIT,
                 PDS_MAC_ADR_ACK_LIMIT_SIZE,
                 PDS_MAC_ADR_ACK_LIMIT_OFFSET),
    DECLARE_ITEM(PDS_MAC_ADR_ACK_DELAY_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_ADR_ACK_DELAY,
                 PDS_MAC_ADR_ACK_DELAY_SIZE,
                 PDS_MAC_ADR_ACK_DELAY_OFFSET),
    DECLARE_ITEM(PDS_MAC_MAX_REP_CNF_UPLINK_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_MAX_REP_CNF_UPLINK,
                 PDS_MAC_MAX_REP_CNF_UPLINK_SIZE,
                 PDS_MAC_MAX_REP_CNF_UPLINK_OFFSET),
    DECLARE_ITEM(PDS_MAC_MAX_REP_UNCNF_UPLINK_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_MAX_REP_UNCNF_UPLINK,
                 PDS_MAC_MAX_REP_UNCNF_UPLINK_SIZE,
                 PDS_MAC_MAX_REP_UNCNF_UPLINK_OFFSET),
    DECLARE_ITEM(PDS_MAC_FCNT_UP_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_FCNT_UP,
                 PDS_MAC_FCNT_UP_SIZE,
                 PDS_MAC_FCNT_UP_OFFSET),
    DECLARE_ITEM(PDS_MAC_DEV_NONCE_ADDR,
                 PDS_FILE_MAC_01_IDX,
                 PDS_MAC_DEV_NONCE,
                 PDS_MAC_DEV_NONCE_SIZE,
                 PDS_MAC_DEV_NONCE_OFFSET)
};

const ItemMap_t pds_mac_fid2_item_list[] = {
    DECLARE_ITEM(PDS_MAC_RX2_PARAMS_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_RX2_PARAMS,
                PDS_MAC_RX2_PARAMS_SIZE,
                PDS_MAC_RX2_PARAMS_OFFSET),
    DECLARE_ITEM(PDS_MAC_RX1_OFFSET_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_RX1_OFFSET,
                PDS_MAC_RX1_OFFSET_SIZE,
                PDS_MAC_RX1_OFFSET_OFFSET),
    DECLARE_ITEM(PDS_MAC_ACTIVATION_TYPE_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_ACTIVATION_TYPE,
                PDS_MAC_ACTIVATION_TYPE_SIZE,
                PDS_MAC_ACTIVATION_TYPE_OFFSET),
    DECLARE_ITEM(PDS_MAC_DEV_ADDR_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_DEV_ADDR,
                PDS_MAC_DEV_ADDR_SIZE,
                PDS_MAC_DEV_ADDR_OFFSET),
    DECLARE_ITEM(PDS_MAC_NWK_SKEY_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_NWK_SKEY,
                PDS_MAC_NWK_SKEY_SIZE,
                PDS_MAC_NWK_SKEY_OFFSET),
    DECLARE_ITEM(PDS_MAC_APP_SKEY_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_APP_SKEY,
                PDS_MAC_APP_SKEY_SIZE,
                PDS_MAC_APP_SKEY_OFFSET),
    DECLARE_ITEM(PDS_MAC_APP_KEY_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_APP_KEY,
                PDS_MAC_APP_KEY_SIZE,
                PDS_MAC_APP_KEY_OFFSET),
    DECLARE_ITEM(PDS_MAC_JOIN_EUI_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_JOIN_EUI,
                PDS_MAC_JOIN_EUI_SIZE,
                PDS_MAC_APP_EUI_OFFSET),
    DECLARE_ITEM(PDS_MAC_DEV_EUI_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_DEV_EUI,
                PDS_MAC_DEV_EUI_SIZE,
                PDS_MAC_DEV_EUI_OFFSET),
    DECLARE_ITEM(PDS_MAC_LORAWAN_MAC_KEYS_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_LORAWAN_MAC_KEYS,
                PDS_MAC_LORAWAN_MAC_KEYS_SIZE,
                PDS_MAC_LORAWAN_MAC_KEYS_OFFSET),
    DECLARE_ITEM(PDS_MAC_FCNT_DOWN_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_FCNT_DOWN,
                PDS_MAC_FCNT_DOWN_SIZE,
                PDS_MAC_FCNT_DOWN_OFFSET),
    DECLARE_ITEM(PDS_MAC_LORAWAN_STATUS_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_LORAWAN_STATUS,
                PDS_MAC_LORAWAN_STATUS_SIZE,
                PDS_MAC_LORAWAN_STATUS_OFFSET),
    DECLARE_ITEM(PDS_MAC_CURR_DR_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_CURR_DR,
                PDS_MAC_CURR_DR_SIZE,
                PDS_MAC_CURR_DR_OFFSET),
    DECLARE_ITEM(PDS_MAC_MAX_FCNT_INC_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_MAX_FCNT_INC,
                PDS_MAC_MAX_FCNT_INC_SIZE,
                PDS_MAC_MAX_FCNT_INC_OFFSET),
    DECLARE_ITEM(PDS_MAC_CRYPTO_DEV_ENABLED_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_CRYPTO_DEV_ENABLED,
                PDS_MAC_CRYPTO_DEV_ENABLED_SIZE,
                PDS_MAC_CRYPTO_DEV_ENABLED_OFFSET),
    DECLARE_ITEM(PDS_MAC_JOIN_NONCE_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_JOIN_NONCE,
                PDS_MAC_JOIN_NONCE_SIZE,
                PDS_MAC_JOIN_NONCE_OFFSET),
    DECLARE_ITEM(PDS_MAC_RXC_PARAMS_ADDR,
                PDS_FILE_MAC_02_IDX,
                PDS_MAC_RXC_PARAMS,
                PDS_MAC_RXC_PARAMS_SIZE,
                PDS_MAC_RXC_PARAMS_OFFSET)
};

void Lorawan_Pds_fid1_CB(void)
{
    //loRa.mcastParams.activationParams.mcastFCntDown.value += MAX_FCNT_PDS_UPDATE_VALUE;
    //loRa.fCntUp.value += MAX_FCNT_PDS_UPDATE_VALUE;
}

void Lorawan_Pds_fid2_CB(void)
{
    SalStatus_t sal_status = SAL_SUCCESS;
    /* MAX Fcnt value is updated file 2. So both Up and Down counter is updated after that */
    /*if(0 != loRa.maxFcntPdsUpdateValue)
    {
        loRa.fCntUp.value += (1 << loRa.maxFcntPdsUpdateValue);
        PDS_STORE(PDS_MAC_FCNT_UP);
        loRa.fCntDown.value += (1 << loRa.maxFcntPdsUpdateValue);
        PDS_STORE(PDS_MAC_FCNT_DOWN);
        loRa.mcastParams.activationParams[0].mcastFCntDown.value += (1 << loRa.maxFcntPdsUpdateValue);
        PDS_STORE(PDS_MAC_MCAST_FCNT_DWN);
    }
*/

    {
        /* Clear MAC STATUS Bits which are transactional in nature */
        loRa.macStatus.macState = 0;
        loRa.macStatus.macPause = 0;
        loRa.macStatus.rxDone = 0;
    }

    if (loRa.cryptoDeviceEnabled == true)
    {   //m16946
        SAL_CRYPTO_Init() ;
		//-----
        sal_status = SAL_Read(SAL_JOIN_EUI, (uint8_t *)&loRa.activationParameters.joinEui.buffer);
        if (SAL_SUCCESS != sal_status)
        {
            loRa.macStatus.networkJoined = false; //Make the device to "Not Joined" state if APP_EUI from ECC608 read failed
        }

        if (loRa.macStatus.networkJoined == true)
        {
            if (loRa.activationParameters.activationType == LORAWAN_OTAA)
            {
                //Read the session keys from Cryptodevice
                SAL_Read(SAL_NWKS_KEY, loRa.activationParameters.networkSessionKeyRam);
                SAL_Read(SAL_APPS_KEY, loRa.activationParameters.applicationSessionKeyRam);
            }
            else
            {
                memcpy(loRa.activationParameters.applicationSessionKeyRam, loRa.activationParameters.applicationSessionKeyRom, 16);
                memcpy(loRa.activationParameters.networkSessionKeyRam, loRa.activationParameters.networkSessionKeyRom, 16);
            }
        }
    }
    else
    {
        memcpy(loRa.activationParameters.applicationSessionKeyRam, loRa.activationParameters.applicationSessionKeyRom, 16);
        memcpy(loRa.activationParameters.networkSessionKeyRam, loRa.activationParameters.networkSessionKeyRom, 16);
    }

}

/**
 End of File
*/