/*
 * SSD_prg.c
 *
 *  Created on: Jul 26, 2025
 *      Author: Merna Atef
 */


# include "../../LIB/STD_TYPES.h"
# include "../../LIB/BIT_MATH.h"
# include "../../MCAL/DIO/DIO_INT.h"

# include "SSD_int.h"
# include "SSD_Prv.h"
# include "SSD_cfg.h"
const u8 CGR_u8SsdNum[10] = {
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4
        0x6D, // 5
        0x7D, // 6
        0x07, // 7
        0x7F, // 8
        0x6F  // 9
    };

//Init
void HSSD_VInit(void)
{
	MDIO_voidSetPortDir(SSD_PORT,0xFF);
}
//Display
void HSSD_VDisplayNum(u8 A_u8Num){
	//common cathode
#if SSD_TYPE == COM_CATHODE
	MDIO_voidSetPortVal(SSD_PORT,CGR_u8SsdNum[A_u8Num]);
#elif SSD_TYPE == COM_ANODE
		MDIO_voidSetPortVal(SSD_PORT,~CGR_u8SsdNum[A_u8Num]);
#endif
}
void HSSD_VTurnOff(void) {
#if SSD_TYPE == COM_CATHODE
    MDIO_voidSetPortVal(SSD_PORT, 0x00);
#elif SSD_TYPE == COM_ANODE
    MDIO_voidSetPortVal(SSD_PORT, 0xFF);
#endif
}
