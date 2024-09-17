#include "rtconfig.h"

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_common.h"

#include "fsl_gpio.h"

void BOARD_InitLcdPins(void);

void BOARD_InitBootPins(void)
{
    CLOCK_EnableClock(kCLOCK_Port0);
    CLOCK_EnableClock(kCLOCK_Port1);
    CLOCK_EnableClock(kCLOCK_Port2);
    CLOCK_EnableClock(kCLOCK_Port3);
    CLOCK_EnableClock(kCLOCK_Port4);

    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio1);
    CLOCK_EnableClock(kCLOCK_Gpio2);
    CLOCK_EnableClock(kCLOCK_Gpio3);
    CLOCK_EnableClock(kCLOCK_Gpio4);



    /* UART */
    PORT1->PCR[8]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_IBE(1);     /* FC4_P0 */
    PORT1->PCR[9]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_IBE(1);     /* FC4_P1 */

    /* Mikro Bus UART */
//	  PORT1->PCR[16]  = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_IBE(1);     /* FC5_P0 */
//	  PORT1->PCR[17]  = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_IBE(1);     /* FC5_P1 */

    PORT1->PCR[16]  = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC5_UART */
    PORT1->PCR[17]  = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC5_UART */

    /* DAC */
    // PORT4->PCR[2] = PORT_PCR_MUX(0) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(0); /* DAC0 */
    // PORT4->PCR[3] = PORT_PCR_MUX(0) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(0); /* DAC1 */

    /* MCX_RST UART */
    PORT4->PCR[2]  = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC2_UART */
    PORT4->PCR[3]  = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC2_UART */


    PORT0->PCR[6]   = PORT_PCR_MUX(12) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1) | PORT_PCR_SRE(0) | PORT_PCR_ODE(0);     /* CLKOUT */

#ifdef BSP_USING_I2C1
    PORT0->PCR[24]   = PORT_PCR_MUX(2) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1) | PORT_PCR_SRE(0) | PORT_PCR_ODE(0);     /* FC1 I2C_SDA */
    PORT0->PCR[25]   = PORT_PCR_MUX(2) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1) | PORT_PCR_SRE(0) | PORT_PCR_ODE(0);     /* FC1 I2C_SCL */
#endif

    PORT0->PCR[16]   = PORT_PCR_MUX(2) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1) | PORT_PCR_SRE(0) | PORT_PCR_ODE(0);     /* FC0 I2C_SDA */
    PORT0->PCR[17]   = PORT_PCR_MUX(2) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1) | PORT_PCR_SRE(0) | PORT_PCR_ODE(0);     /* FC0 I2C_SCL */


#ifdef BSP_USING_SPI1
    /* Arduino D11(P0_24), D12(P0_26), D13(P0_25) as SPI function, for RW007 MOSI, MISO, CLK  */
    PORT0->PCR[24]   = PORT_PCR_MUX(2) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* P0_24: FC1_0 */
    PORT0->PCR[26]   = PORT_PCR_MUX(2) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* P0_26: FC1_2 */
    PORT0->PCR[25]   = PORT_PCR_MUX(2) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* P0_25: FC1_1 */

    /* Arduino D8(P0_28), D9(P0_10), D10(P0_27) as GPIO function, for RW007 RST, INT, CS */
    /* drv_pin.c works well, follow lines just notice that pins we used as GPIO function */
    // PORT0->PCR[28]   = PORT_PCR_MUX(0) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* P0_28: P0_28 */
    // PORT0->PCR[10]   = PORT_PCR_MUX(0) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* P0_10: P0_27 */
    PORT0->PCR[27]   = PORT_PCR_MUX(0) | PORT_PCR_PS(1) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* P0_27: P0_27 */
#endif

    /* PMOD */
    PORT1->PCR[0]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC3_0 SDO/D[0], FC3_SPI_MOSI */
    PORT1->PCR[1]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC3_1 SCK, FC3_SPI_CLK */
    PORT1->PCR[2]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC3_2 SDI/D[1], FC3_SPI_MISO */
    PORT1->PCR[3]   = PORT_PCR_MUX(0) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* CS */
//    PORT1->PCR[3]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC3_3 CS0 */
//    PORT1->PCR[4]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC3_4 D[3] */
//    PORT1->PCR[5]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC3_5 D[2] */

    /* SPI */
    PORT3->PCR[8]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC7_P0, MOSI */
    PORT3->PCR[9]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC7_P2, MISO */
    PORT3->PCR[7]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC7_P1, CLK */
    PORT3->PCR[0]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC7_P1, CS */

    PORT1->PCR[8]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC4_UART */
    PORT1->PCR[9]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC4_UART */


    PORT1->PCR[10]   = PORT_PCR_MUX(11) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* CAN0_TX */
    PORT1->PCR[11]   = PORT_PCR_MUX(11) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* CAN0_RX */


    PORT1->PCR[12]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC3_0 SDO/D[0] */
    PORT1->PCR[13]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC3_1 SCK */
    PORT1->PCR[14]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC3_2 SDI/D[1] */
    PORT1->PCR[15]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC3_3 CS0 */
//    PORT1->PCR[16]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC3_4 D[3] */
//    PORT1->PCR[17]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC3_5 D[2] */

//    PORT1->PCR[8]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC5_4 D[3] */
//    PORT1->PCR[9]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC5_5 D[2] */
    PORT1->PCR[4]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC5_0 SDO/D[0] */
    PORT1->PCR[5]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC5_1 SCK */
    PORT1->PCR[6]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC5_2 SDI/D[1] */
    PORT1->PCR[7]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* FC5_3 CS0 */

    PORT2->PCR[2]   = PORT_PCR_MUX(3) | PORT_PCR_PE(0) | PORT_PCR_PS(0) | PORT_PCR_IBE(1);   /* SDHC0_D1 */
    PORT2->PCR[3]   = PORT_PCR_MUX(3) | PORT_PCR_PE(1) | PORT_PCR_PS(1) | PORT_PCR_IBE(1);   /* SDHC0_D0 */
    PORT2->PCR[4]   = PORT_PCR_MUX(3) | PORT_PCR_PE(0) | PORT_PCR_PS(0) | PORT_PCR_IBE(1);   /* SDHC0_CLK */
    PORT2->PCR[5]   = PORT_PCR_MUX(3) | PORT_PCR_PE(1) | PORT_PCR_PS(1) | PORT_PCR_IBE(1);   /* SDHC0_CMD */
    PORT2->PCR[6]   = PORT_PCR_MUX(3) | PORT_PCR_PE(1) | PORT_PCR_PS(1) | PORT_PCR_IBE(1);   /* SDHC0_D3 */
    PORT2->PCR[7]   = PORT_PCR_MUX(3) | PORT_PCR_PE(1) | PORT_PCR_PS(1) | PORT_PCR_IBE(1);   /* SDHC0_D2 */

    /* mikroBUS SPI6 */
    PORT3->PCR[20]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC6_P0 SDO/D[0], FC6_SPI_MOSI */
    PORT3->PCR[21]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC6_P1 SCK, FC6_SPI_CLK */
    PORT3->PCR[22]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC6_P2 SDI/D[1], FC3_SPI_MISO */
    PORT3->PCR[23]   = PORT_PCR_MUX(0) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* CS */


//    PORT1->PCR[20]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC4_0 */
//    PORT1->PCR[21]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC4_1 */
//    PORT1->PCR[22]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC4_2 */
//    PORT1->PCR[23]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC4_3 */
//    PORT1->PCR[0]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);      /* FC4_4 */
//    PORT1->PCR[1]   = PORT_PCR_MUX(3) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);      /* FC4_5 */

//    PORT4->PCR[0]   = PORT_PCR_MUX(0) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ANA_0, ADC0_A0 */
//    PORT4->PCR[1]   = PORT_PCR_MUX(0) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ANA_1, ADC0_B0 */

    PORT4->PCR[0]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC2_P0 I2C_SDA */
    PORT4->PCR[1]   = PORT_PCR_MUX(2) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* FC2_P1 I2C_SCL */

    /* FLEXIO */
    PORT0->PCR[ 9] = PORT_PCR_MUX(6) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK; /* FLEXIO WR */
    PORT0->PCR[ 8] = PORT_PCR_MUX(6) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK; /* FLEXIO RD */
    PORT0->PCR[12] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK; /* FLEXIO CS */
    PORT0->PCR[ 7] = PORT_PCR_MUX(0) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK; /* FLEXIO RS */

    PORT2->PCR[ 8]   = PORT_PCR_MUX(FLEXIO_DATA0_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D0 */
    PORT2->PCR[ 9]   = PORT_PCR_MUX(FLEXIO_DATA1_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D1 */
    PORT2->PCR[10]   = PORT_PCR_MUX(FLEXIO_DATA2_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D2 */
    PORT2->PCR[11]   = PORT_PCR_MUX(FLEXIO_DATA3_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D3 */
    PORT4->PCR[12]   = PORT_PCR_MUX(FLEXIO_DATA4_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D4 */
    PORT4->PCR[13]   = PORT_PCR_MUX(FLEXIO_DATA5_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D5 */
    PORT4->PCR[14]   = PORT_PCR_MUX(FLEXIO_DATA6_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D6 */
    PORT4->PCR[15]   = PORT_PCR_MUX(FLEXIO_DATA7_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D7 */
    PORT4->PCR[16] = PORT_PCR_MUX(FLEXIO_DATA8_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);         /* FXIO0_D8  */


//    PORT4->PCR[15]   = PORT_PCR_MUX(11) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* CAN1 */
//    PORT4->PCR[16]   = PORT_PCR_MUX(11) | PORT_PCR_PS(0) | PORT_PCR_PE(1) | PORT_PCR_IBE(1);     /* CAN */


    PORT4->PCR[17] = PORT_PCR_MUX(FLEXIO_DATA9_MUX)  | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D9  */
    PORT4->PCR[18] = PORT_PCR_MUX(FLEXIO_DATA10_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D10 */
    PORT4->PCR[19] = PORT_PCR_MUX(FLEXIO_DATA11_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D11 */
    PORT4->PCR[20] = PORT_PCR_MUX(FLEXIO_DATA12_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D12 */
    PORT4->PCR[21] = PORT_PCR_MUX(FLEXIO_DATA13_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D13 */
    PORT4->PCR[22] = PORT_PCR_MUX(FLEXIO_DATA14_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D14 */
    PORT4->PCR[23] = PORT_PCR_MUX(FLEXIO_DATA15_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS(0);       /* FXIO0_D15 */


    /* ENET */
    PORT1->PCR[13]   = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_RXDV */
    PORT1->PCR[14]   = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_RXD0 */
    PORT1->PCR[15]   = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_RXD1 */
    PORT1->PCR[20]   = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_MDC */
    PORT1->PCR[21]   = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_MDIO */
    PORT1->PCR[4]    = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_TX_CLK */
    PORT1->PCR[5]    = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_TXEN */
    PORT1->PCR[6]    = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_TXD0 */
    PORT1->PCR[7]    = PORT_PCR_MUX(9) | PORT_PCR_PS(0) | PORT_PCR_PE(0) | PORT_PCR_IBE(1);     /* ENET0_TXD1 */

    BOARD_InitLcdPins();
}



/* Configure port mux of FlexIO data pins */
void FLEXIO_8080_Config_Data_Pin(void)
{

}


/* Configure FLEXIO_WR pin as FlexIO function */
void FLEXIO_8080_Config_WR_FlexIO(void)
{
   // FLEXIO_WR_PORT->PCR[FLEXIO_WR_PIN] = PORT_PCR_MUX(FLEXIO_WR_PIN_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Configure FLEXIO_WR pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_WR_GPIO(void)
{

}

/* Configure FLEXIO_RD pin as FlexIO function */
void FLEXIO_8080_Config_RD_FlexIO(void)
{
  //  FLEXIO_RD_PORT->PCR[FLEXIO_RD_PIN] = PORT_PCR_MUX(FLEXIO_RD_PIN_MUX) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Configure FLEXIO_RD pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_RD_GPIO(void)
{
//    FLEXIO_RD_GPIO->PSOR |= 1U << FLEXIO_RD_PIN;
//    FLEXIO_RD_GPIO->PDDR |= 1U << FLEXIO_RD_PIN;
//    FLEXIO_RD_PORT->PCR[FLEXIO_RD_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Configure FLEXIO_CS pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_CS_GPIO(void)
{
    FLEXIO_CS_GPIO->PSOR |= 1U << FLEXIO_CS_PIN;
    FLEXIO_CS_GPIO->PDDR |= 1U << FLEXIO_CS_PIN;
//    FLEXIO_CS_PORT->PCR[FLEXIO_CS_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Set FLEXIO_CS pin's level */
void FLEXIO_8080_Set_CS_Pin(bool level)
{
    if(level)
    {
        FLEXIO_CS_GPIO->PSOR |= 1U << FLEXIO_CS_PIN;
    }
    else
    {
        FLEXIO_CS_GPIO->PCOR |= 1U << FLEXIO_CS_PIN;
    }
}

/* Configure RS pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_RS_GPIO(void)
{
    FLEXIO_RS_GPIO->PSOR |= 1U << FLEXIO_RS_PIN;
    FLEXIO_RS_GPIO->PDDR |= 1U << FLEXIO_RS_PIN;
//    FLEXIO_RS_PORT->PCR[FLEXIO_RS_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Set RS pin's level */
void FLEXIO_8080_Set_RS_Pin(bool level)
{
    if(level)
    {
        FLEXIO_RS_GPIO->PSOR |= 1U << FLEXIO_RS_PIN;
    }
    else
    {
        FLEXIO_RS_GPIO->PCOR |= 1U << FLEXIO_RS_PIN;
    }
}

/* Configure ReSet pin as GPIO function and outputting high level */
void FLEXIO_8080_Config_ReSet_GPIO(void)
{
    FLEXIO_ReSet_GPIO->PSOR |= 1U << FLEXIO_ReSet_PIN;
    FLEXIO_ReSet_GPIO->PDDR |= 1U << FLEXIO_ReSet_PIN;
    FLEXIO_ReSet_PORT->PCR[FLEXIO_ReSet_PIN] = PORT_PCR_MUX(0U) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

/* Set ReSet pin's level */
void FLEXIO_8080_Set_ReSet_Pin(bool level)
{
    if(level)
    {
        FLEXIO_ReSet_GPIO->PSOR |= 1U << FLEXIO_ReSet_PIN;
    }
    else
    {
        FLEXIO_ReSet_GPIO->PCOR |= 1U << FLEXIO_ReSet_PIN;
    }
}

#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

void BOARD_InitPins(void)
{
    /* Enables the clock for PORT1: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port1);

    const port_pin_config_t port1_8_pinA1_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as FC4_P0 */
                                                    kPORT_MuxAlt2,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT1_8 (pin A1) is configured as FC4_P0 */
    PORT_SetPinConfig(PORT1, 8U, &port1_8_pinA1_config);

    const port_pin_config_t port1_9_pinB1_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as FC4_P1 */
                                                    kPORT_MuxAlt2,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT1_9 (pin B1) is configured as FC4_P1 */
    PORT_SetPinConfig(PORT1, 9U, &port1_9_pinB1_config);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLcdPins:
- options: {callFromInitBoot: 'true', coreID: cm33_core0, enableClock: 'true'}
- pin_list:
  - {pin_num: T4, peripheral: GPIO4, signal: 'GPIO, 7', pin_signal: PIO4_7/CT_INP19, direction: OUTPUT, slew_rate: fast, open_drain: disable, drive_strength: low,
    pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: C13, peripheral: GPIO0, signal: 'GPIO, 7', pin_signal: PIO0_7/WUU0_IN1/FC0_P3/CT_INP3/CMP2_IN1, direction: OUTPUT, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: D11, peripheral: GPIO0, signal: 'GPIO, 12', pin_signal: PIO0_12/FC1_P4/FC0_P0/CT0_MAT2/FLEXIO0_D4/ADC0_B12, direction: OUTPUT, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: A12, peripheral: FLEXIO0, signal: 'D, 1', pin_signal: PIO0_9/FC0_P5/CT_INP1/FLEXIO0_D1/ADC0_B9, slew_rate: fast, open_drain: disable, drive_strength: low,
    pull_select: up, pull_enable: enable, input_buffer: enable, invert_input: normal}
  - {pin_num: C12, peripheral: FLEXIO0, signal: 'D, 0', pin_signal: PIO0_8/FC0_P4/CT_INP0/FLEXIO0_D0/ADC0_B8, slew_rate: fast, open_drain: disable, drive_strength: low,
    pull_select: up, pull_enable: enable, input_buffer: enable, invert_input: normal}
  - {pin_num: M2, peripheral: FLEXIO0, signal: 'D, 16', pin_signal: PIO2_8/TRACE_DATA0/SDHC0_D7/SCT0_IN2/PWM1_X0/FLEXIO0_D16/FLEXSPI0_B_DATA4/SINC0_MCLK3/SAI1_TXD0,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: M1, peripheral: FLEXIO0, signal: 'D, 17', pin_signal: PIO2_9/TRACE_DATA1/SDHC0_D6/SCT0_IN3/PWM1_X1/FLEXIO0_D17/FLEXSPI0_B_DATA5/SINC0_MBIT3/SAI1_RXD0,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: M3, peripheral: FLEXIO0, signal: 'D, 18', pin_signal: PIO2_10/TRACE_DATA2/SCT0_IN4/PWM1_X2/FLEXIO0_D18/FLEXSPI0_B_DATA6/SINC0_MCLK4/SAI1_RXD1, slew_rate: fast,
    open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: N4, peripheral: FLEXIO0, signal: 'D, 19', pin_signal: PIO2_11/TRACE_DATA3/SCT0_IN5/PWM1_X3/FLEXIO0_D19/FLEXSPI0_B_DATA7/SINC0_MBIT4/SAI1_TXD1, slew_rate: fast,
    open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: T6, peripheral: FLEXIO0, signal: 'D, 20', pin_signal: PIO4_12/WUU0_IN20/USB0_VBUS_DET/FC2_P0/CT4_MAT0/FLEXIO0_D20/PLU_OUT0/SINC0_MCLK0/CAN0_RXD/OPAMP0_INP0/ADC0_A5/ADC1_A5,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: T7, peripheral: FLEXIO0, signal: 'D, 21', pin_signal: PIO4_13/TRIG_IN8/FC2_P1/USB1_ID/CT4_MAT1/FLEXIO0_D21/PLU_OUT1/SINC0_MBIT0/CAN0_TXD/OPAMP0_INP1/ADC0_B5/ADC1_B5,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: N8, peripheral: FLEXIO0, signal: 'D, 22', pin_signal: PIO4_14/CT4_MAT2/FLEXIO0_D22/PLU_OUT2, slew_rate: fast, open_drain: disable, drive_strength: low,
    pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: T8, peripheral: FLEXIO0, signal: 'D, 23', pin_signal: PIO4_15/WUU0_IN21/TRIG_OUT4/USB1_VBUS_DIG/CT4_MAT3/FLEXIO0_D23/PLU_OUT3/SINC0_MCLK_OUT0/CAN1_RXD/OPAMP0_OUT/ADC0_A1/CMP0_IN4P,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: R8, peripheral: FLEXIO0, signal: 'D, 24', pin_signal: PIO4_16/FC2_P2/USB1_OTG_PWR/CT3_MAT0/FLEXIO0_D24/PLU_OUT4/SINC0_MCLK1/CAN1_TXD/OPAMP1_INP0/ADC0_A6,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: R9, peripheral: FLEXIO0, signal: 'D, 25', pin_signal: PIO4_17/TRIG_IN9/FC2_P3/USB1_OTG_OC/CT3_MAT1/FLEXIO0_D25/PLU_OUT5/SINC0_MBIT1/OPAMP1_INP1/ADC0_B6,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: N10, peripheral: FLEXIO0, signal: 'D, 26', pin_signal: PIO4_18/CT3_MAT2/FLEXIO0_D26/PLU_OUT6, slew_rate: fast, open_drain: disable, drive_strength: low,
    pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: R10, peripheral: FLEXIO0, signal: 'D, 27', pin_signal: PIO4_19/TRIG_OUT5/CT3_MAT3/FLEXIO0_D27/PLU_OUT7/SINC0_MCLK_OUT1/OPAMP1_OUT/ADC0_B1/CMP1_IN4P,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: T10, peripheral: FLEXIO0, signal: 'D, 28', pin_signal: PIO4_20/TRIG_IN8/FC2_P4/CT2_MAT0/FLEXIO0_D28/SINC0_MCLK2/OPAMP2_INP0/ADC1_A6, slew_rate: fast,
    open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: T11, peripheral: FLEXIO0, signal: 'D, 29', pin_signal: PIO4_21/TRIG_IN9/FC2_P5/CT2_MAT1/FLEXIO0_D29/SINC0_MBIT2/OPAMP2_INP1/ADC1_B6, slew_rate: fast,
    open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: T12, peripheral: FLEXIO0, signal: 'D, 30', pin_signal: PIO4_22/CT2_MAT2/FLEXIO0_D30, slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down,
    pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: U12, peripheral: FLEXIO0, signal: 'D, 31', pin_signal: PIO4_23/TRIG_OUT5/FC2_P6/CT2_MAT3/FLEXIO0_D31/SINC0_MCLK_OUT2/OPAMP2_OUT/ADC0_A2/ADC0_B2/ADC1_B3/CMP2_IN4P,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: N7, peripheral: GPIO4, signal: 'GPIO, 6', pin_signal: PIO4_6/TRIG_OUT4/FC2_P6/CT_INP18/PLU_CLK, direction: INPUT, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: P1, peripheral: LP_FLEXCOMM2, signal: LPFLEXCOMM_P0, pin_signal: PIO4_0/WUU0_IN18/TRIG_IN6/FC2_P0/CT_INP16/PLU_IN0/SINC0_MCLK3, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: up, pull_enable: enable, input_buffer: enable, invert_input: normal}
  - {pin_num: P2, peripheral: LP_FLEXCOMM2, signal: LPFLEXCOMM_P1, pin_signal: PIO4_1/TRIG_IN7/FC2_P1/CT_INP17/PLU_IN1, slew_rate: fast, open_drain: disable, drive_strength: low,
    pull_select: up, pull_enable: enable, input_buffer: enable, invert_input: normal}
  - {pin_num: F12, peripheral: GPIO0, signal: 'GPIO, 13', pin_signal: PIO0_13/FC1_P5/FC0_P1/CT0_MAT3/FLEXIO0_D5/ADC0_B13, direction: INPUT, slew_rate: fast, open_drain: disable,
    drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLcdPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitLcdPins(void)
{
    /* Enables the clock for GPIO0: Enables clock */
    CLOCK_EnableClock(kCLOCK_Gpio0);
    /* Enables the clock for GPIO4: Enables clock */
    CLOCK_EnableClock(kCLOCK_Gpio4);
    /* Enables the clock for PORT0 controller: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port0);
    /* Enables the clock for PORT2: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port2);
    /* Enables the clock for PORT4: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port4);

    gpio_pin_config_t gpio0_pinC13_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_7 (pin C13)  */
    GPIO_PinInit(GPIO0, 7U, &gpio0_pinC13_config);

    gpio_pin_config_t gpio0_pinD11_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_12 (pin D11)  */
    GPIO_PinInit(GPIO0, 12U, &gpio0_pinD11_config);

    gpio_pin_config_t gpio0_pinF12_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_13 (pin F12)  */
    GPIO_PinInit(GPIO0, 13U, &gpio0_pinF12_config);

    gpio_pin_config_t gpio4_pinN7_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO4_6 (pin N7)  */
    GPIO_PinInit(GPIO4, 6U, &gpio4_pinN7_config);

    gpio_pin_config_t gpio4_pinT4_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO4_7 (pin T4)  */
    GPIO_PinInit(GPIO4, 7U, &gpio4_pinT4_config);

    const port_pin_config_t port0_12_pinD11_config = {/* Internal pull-up/down resistor is disabled */
                                                      kPORT_PullDisable,
                                                      /* Low internal pull resistor value is selected. */
                                                      kPORT_LowPullResistor,
                                                      /* Fast slew rate is configured */
                                                      kPORT_FastSlewRate,
                                                      /* Passive input filter is disabled */
                                                      kPORT_PassiveFilterDisable,
                                                      /* Open drain output is disabled */
                                                      kPORT_OpenDrainDisable,
                                                      /* Low drive strength is configured */
                                                      kPORT_LowDriveStrength,
                                                      /* Pin is configured as PIO0_12 */
                                                      kPORT_MuxAlt0,
                                                      /* Digital input enabled */
                                                      kPORT_InputBufferEnable,
                                                      /* Digital input is not inverted */
                                                      kPORT_InputNormal,
                                                      /* Pin Control Register fields [15:0] are not locked */
                                                      kPORT_UnlockRegister};
    /* PORT0_12 (pin D11) is configured as PIO0_12 */
    PORT_SetPinConfig(PORT0, 12U, &port0_12_pinD11_config);

    const port_pin_config_t port0_13_pinF12_config = {/* Internal pull-up/down resistor is disabled */
                                                      kPORT_PullDisable,
                                                      /* Low internal pull resistor value is selected. */
                                                      kPORT_LowPullResistor,
                                                      /* Fast slew rate is configured */
                                                      kPORT_FastSlewRate,
                                                      /* Passive input filter is disabled */
                                                      kPORT_PassiveFilterDisable,
                                                      /* Open drain output is disabled */
                                                      kPORT_OpenDrainDisable,
                                                      /* Low drive strength is configured */
                                                      kPORT_LowDriveStrength,
                                                      /* Pin is configured as PIO0_13 */
                                                      kPORT_MuxAlt0,
                                                      /* Digital input enabled */
                                                      kPORT_InputBufferEnable,
                                                      /* Digital input is not inverted */
                                                      kPORT_InputNormal,
                                                      /* Pin Control Register fields [15:0] are not locked */
                                                      kPORT_UnlockRegister};
    /* PORT0_13 (pin F12) is configured as PIO0_13 */
    PORT_SetPinConfig(PORT0, 13U, &port0_13_pinF12_config);

    const port_pin_config_t port0_7_pinC13_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as PIO0_7 */
                                                     kPORT_MuxAlt0,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT0_7 (pin C13) is configured as PIO0_7 */
    PORT_SetPinConfig(PORT0, 7U, &port0_7_pinC13_config);

    const port_pin_config_t port0_8_pinC12_config = {/* Internal pull-up resistor is enabled */
                                                     kPORT_PullUp,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D0 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT0_8 (pin C12) is configured as FLEXIO0_D0 */
    PORT_SetPinConfig(PORT0, 8U, &port0_8_pinC12_config);

    const port_pin_config_t port0_9_pinA12_config = {/* Internal pull-up resistor is enabled */
                                                     kPORT_PullUp,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D1 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT0_9 (pin A12) is configured as FLEXIO0_D1 */
    PORT_SetPinConfig(PORT0, 9U, &port0_9_pinA12_config);

    const port_pin_config_t port2_10_pinM3_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D18 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT2_10 (pin M3) is configured as FLEXIO0_D18 */
    PORT_SetPinConfig(PORT2, 10U, &port2_10_pinM3_config);

    const port_pin_config_t port2_11_pinN4_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D19 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT2_11 (pin N4) is configured as FLEXIO0_D19 */
    PORT_SetPinConfig(PORT2, 11U, &port2_11_pinN4_config);

    const port_pin_config_t port2_8_pinM2_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as FLEXIO0_D16 */
                                                    kPORT_MuxAlt6,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT2_8 (pin M2) is configured as FLEXIO0_D16 */
    PORT_SetPinConfig(PORT2, 8U, &port2_8_pinM2_config);

    const port_pin_config_t port2_9_pinM1_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as FLEXIO0_D17 */
                                                    kPORT_MuxAlt6,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT2_9 (pin M1) is configured as FLEXIO0_D17 */
    PORT_SetPinConfig(PORT2, 9U, &port2_9_pinM1_config);

    const port_pin_config_t port4_0_pinP1_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as FC2_P0 */
                                                    kPORT_MuxAlt2,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT4_0 (pin P1) is configured as FC2_P0 */
    PORT_SetPinConfig(PORT4, 0U, &port4_0_pinP1_config);

    const port_pin_config_t port4_1_pinP2_config = {/* Internal pull-up resistor is enabled */
                                                    kPORT_PullUp,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as FC2_P1 */
                                                    kPORT_MuxAlt2,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT4_1 (pin P2) is configured as FC2_P1 */
    PORT_SetPinConfig(PORT4, 1U, &port4_1_pinP2_config);

    const port_pin_config_t port4_12_pinT6_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D20 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_12 (pin T6) is configured as FLEXIO0_D20 */
    PORT_SetPinConfig(PORT4, 12U, &port4_12_pinT6_config);

    const port_pin_config_t port4_13_pinT7_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D21 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_13 (pin T7) is configured as FLEXIO0_D21 */
    PORT_SetPinConfig(PORT4, 13U, &port4_13_pinT7_config);

    const port_pin_config_t port4_14_pinN8_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D22 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_14 (pin N8) is configured as FLEXIO0_D22 */
    PORT_SetPinConfig(PORT4, 14U, &port4_14_pinN8_config);

    const port_pin_config_t port4_15_pinT8_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D23 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_15 (pin T8) is configured as FLEXIO0_D23 */
    PORT_SetPinConfig(PORT4, 15U, &port4_15_pinT8_config);

    const port_pin_config_t port4_16_pinR8_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D24 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_16 (pin R8) is configured as FLEXIO0_D24 */
    PORT_SetPinConfig(PORT4, 16U, &port4_16_pinR8_config);

    const port_pin_config_t port4_17_pinR9_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as FLEXIO0_D25 */
                                                     kPORT_MuxAlt6,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_17 (pin R9) is configured as FLEXIO0_D25 */
    PORT_SetPinConfig(PORT4, 17U, &port4_17_pinR9_config);

    const port_pin_config_t port4_18_pinN10_config = {/* Internal pull-up/down resistor is disabled */
                                                      kPORT_PullDisable,
                                                      /* Low internal pull resistor value is selected. */
                                                      kPORT_LowPullResistor,
                                                      /* Fast slew rate is configured */
                                                      kPORT_FastSlewRate,
                                                      /* Passive input filter is disabled */
                                                      kPORT_PassiveFilterDisable,
                                                      /* Open drain output is disabled */
                                                      kPORT_OpenDrainDisable,
                                                      /* Low drive strength is configured */
                                                      kPORT_LowDriveStrength,
                                                      /* Pin is configured as FLEXIO0_D26 */
                                                      kPORT_MuxAlt6,
                                                      /* Digital input enabled */
                                                      kPORT_InputBufferEnable,
                                                      /* Digital input is not inverted */
                                                      kPORT_InputNormal,
                                                      /* Pin Control Register fields [15:0] are not locked */
                                                      kPORT_UnlockRegister};
    /* PORT4_18 (pin N10) is configured as FLEXIO0_D26 */
    PORT_SetPinConfig(PORT4, 18U, &port4_18_pinN10_config);

    const port_pin_config_t port4_19_pinR10_config = {/* Internal pull-up/down resistor is disabled */
                                                      kPORT_PullDisable,
                                                      /* Low internal pull resistor value is selected. */
                                                      kPORT_LowPullResistor,
                                                      /* Fast slew rate is configured */
                                                      kPORT_FastSlewRate,
                                                      /* Passive input filter is disabled */
                                                      kPORT_PassiveFilterDisable,
                                                      /* Open drain output is disabled */
                                                      kPORT_OpenDrainDisable,
                                                      /* Low drive strength is configured */
                                                      kPORT_LowDriveStrength,
                                                      /* Pin is configured as FLEXIO0_D27 */
                                                      kPORT_MuxAlt6,
                                                      /* Digital input enabled */
                                                      kPORT_InputBufferEnable,
                                                      /* Digital input is not inverted */
                                                      kPORT_InputNormal,
                                                      /* Pin Control Register fields [15:0] are not locked */
                                                      kPORT_UnlockRegister};
    /* PORT4_19 (pin R10) is configured as FLEXIO0_D27 */
    PORT_SetPinConfig(PORT4, 19U, &port4_19_pinR10_config);

    const port_pin_config_t port4_20_pinT10_config = {/* Internal pull-up/down resistor is disabled */
                                                      kPORT_PullDisable,
                                                      /* Low internal pull resistor value is selected. */
                                                      kPORT_LowPullResistor,
                                                      /* Fast slew rate is configured */
                                                      kPORT_FastSlewRate,
                                                      /* Passive input filter is disabled */
                                                      kPORT_PassiveFilterDisable,
                                                      /* Open drain output is disabled */
                                                      kPORT_OpenDrainDisable,
                                                      /* Low drive strength is configured */
                                                      kPORT_LowDriveStrength,
                                                      /* Pin is configured as FLEXIO0_D28 */
                                                      kPORT_MuxAlt6,
                                                      /* Digital input enabled */
                                                      kPORT_InputBufferEnable,
                                                      /* Digital input is not inverted */
                                                      kPORT_InputNormal,
                                                      /* Pin Control Register fields [15:0] are not locked */
                                                      kPORT_UnlockRegister};
    /* PORT4_20 (pin T10) is configured as FLEXIO0_D28 */
    PORT_SetPinConfig(PORT4, 20U, &port4_20_pinT10_config);

    const port_pin_config_t port4_21_pinT11_config = {/* Internal pull-up/down resistor is disabled */
                                                      kPORT_PullDisable,
                                                      /* Low internal pull resistor value is selected. */
                                                      kPORT_LowPullResistor,
                                                      /* Fast slew rate is configured */
                                                      kPORT_FastSlewRate,
                                                      /* Passive input filter is disabled */
                                                      kPORT_PassiveFilterDisable,
                                                      /* Open drain output is disabled */
                                                      kPORT_OpenDrainDisable,
                                                      /* Low drive strength is configured */
                                                      kPORT_LowDriveStrength,
                                                      /* Pin is configured as FLEXIO0_D29 */
                                                      kPORT_MuxAlt6,
                                                      /* Digital input enabled */
                                                      kPORT_InputBufferEnable,
                                                      /* Digital input is not inverted */
                                                      kPORT_InputNormal,
                                                      /* Pin Control Register fields [15:0] are not locked */
                                                      kPORT_UnlockRegister};
    /* PORT4_21 (pin T11) is configured as FLEXIO0_D29 */
    PORT_SetPinConfig(PORT4, 21U, &port4_21_pinT11_config);

    const port_pin_config_t port4_22_pinT12_config = {/* Internal pull-up/down resistor is disabled */
                                                      kPORT_PullDisable,
                                                      /* Low internal pull resistor value is selected. */
                                                      kPORT_LowPullResistor,
                                                      /* Fast slew rate is configured */
                                                      kPORT_FastSlewRate,
                                                      /* Passive input filter is disabled */
                                                      kPORT_PassiveFilterDisable,
                                                      /* Open drain output is disabled */
                                                      kPORT_OpenDrainDisable,
                                                      /* Low drive strength is configured */
                                                      kPORT_LowDriveStrength,
                                                      /* Pin is configured as FLEXIO0_D30 */
                                                      kPORT_MuxAlt6,
                                                      /* Digital input enabled */
                                                      kPORT_InputBufferEnable,
                                                      /* Digital input is not inverted */
                                                      kPORT_InputNormal,
                                                      /* Pin Control Register fields [15:0] are not locked */
                                                      kPORT_UnlockRegister};
    /* PORT4_22 (pin T12) is configured as FLEXIO0_D30 */
    PORT_SetPinConfig(PORT4, 22U, &port4_22_pinT12_config);

    const port_pin_config_t port4_23_pinU12_config = {/* Internal pull-up/down resistor is disabled */
                                                      kPORT_PullDisable,
                                                      /* Low internal pull resistor value is selected. */
                                                      kPORT_LowPullResistor,
                                                      /* Fast slew rate is configured */
                                                      kPORT_FastSlewRate,
                                                      /* Passive input filter is disabled */
                                                      kPORT_PassiveFilterDisable,
                                                      /* Open drain output is disabled */
                                                      kPORT_OpenDrainDisable,
                                                      /* Low drive strength is configured */
                                                      kPORT_LowDriveStrength,
                                                      /* Pin is configured as FLEXIO0_D31 */
                                                      kPORT_MuxAlt6,
                                                      /* Digital input enabled */
                                                      kPORT_InputBufferEnable,
                                                      /* Digital input is not inverted */
                                                      kPORT_InputNormal,
                                                      /* Pin Control Register fields [15:0] are not locked */
                                                      kPORT_UnlockRegister};
    /* PORT4_23 (pin U12) is configured as FLEXIO0_D31 */
    PORT_SetPinConfig(PORT4, 23U, &port4_23_pinU12_config);

    const port_pin_config_t port4_6_pinN7_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as PIO4_6 */
                                                    kPORT_MuxAlt0,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT4_6 (pin N7) is configured as PIO4_6 */
    PORT_SetPinConfig(PORT4, 6U, &port4_6_pinN7_config);

    const port_pin_config_t port4_7_pinT4_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as PIO4_7 */
                                                    kPORT_MuxAlt0,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT4_7 (pin T4) is configured as PIO4_7 */
    PORT_SetPinConfig(PORT4, 7U, &port4_7_pinT4_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
