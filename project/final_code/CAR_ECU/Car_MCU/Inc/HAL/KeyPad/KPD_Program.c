#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Bit_Math.h"


#include "../../MCAL/DIO/DIO_Interface.h"


#include "KPD_Interface.h"
#include "KPD_Config.h"
#include "KPD_Private.h"



u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	u8 Local_u8ColumnIdx, Local_u8RowIdx, Local_u8PinState = 0;
	static u8 Local_u8KPDArr[ROW_NUM][COLM_NUM] = KPD_ARR_VAL;
	static u8 Local_u8KPDColmArr[COLM_NUM] = {
			KPD_COLM_PIN0,
			KPD_COLM_PIN1,
			KPD_COLM_PIN2,
			KPD_COLM_PIN3
	};
	static u8 Local_u8KPDRowArr[ROW_NUM] = {
			KPD_ROW_PIN0,
			KPD_ROW_PIN1,
			KPD_ROW_PIN2,
			KPD_ROW_PIN3
	};

	for(Local_u8ColumnIdx = 0; Local_u8ColumnIdx < COLM_NUM; Local_u8ColumnIdx++)
	{
		// Activate current column
		DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColmArr[Local_u8ColumnIdx], DIO_u8PIN_LOW);

		for(Local_u8RowIdx = 0; Local_u8RowIdx < ROW_NUM; Local_u8RowIdx++)
		{
			// Get Current Row
			DIO_GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIdx], &Local_u8PinState);

			// Check pressed
			if( DIO_u8PIN_LOW == Local_u8PinState )
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				// Busy waiting until released
				while( DIO_u8PIN_LOW == Local_u8PinState )
				{
					DIO_GetPinValue(KPD_PORT, Local_u8KPDRowArr[Local_u8RowIdx], &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}

		}
		// Deactivate current Column
		DIO_u8SetPinValue(KPD_PORT, Local_u8KPDColmArr[Local_u8ColumnIdx], DIO_u8PIN_HIGH);

	}
	return Local_u8PressedKey;
}
