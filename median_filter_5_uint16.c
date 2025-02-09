/*---------------------------------------------------------------------*
 *  private: include files
 *---------------------------------------------------------------------*/

#include "median_filter_5_uint16.h"

#include <string.h>


/*---------------------------------------------------------------------*
 *  private: definitions
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  private: typedefs
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  private: variables
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  public:  variables
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  private: function prototypes
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  private: functions
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  public:  functions
 *---------------------------------------------------------------------*/

void median_filter_5_uint16_clear(median_filter_5_uint16_t * object)
{
	object->old_median = 0;
	object->index = 0;

#if false
	object->length = 5;

	uint16_t * data = object->data;
	
	for(uint16_t i = 0; i < 5; i++)
	{
		*(data + i) = 0;
	}
#endif

}

bool median_filter_5_uint16_add(median_filter_5_uint16_t * object, uint16_t value)
{
	uint16_t * data0 = object->data;
	uint8_t * ptr_index = &object->index;
	uint8_t index = *ptr_index;
	bool overflow = false;

	switch(index)
	{
		case 0:
		{
			*data0 = value;
			*ptr_index = index + 1;
		} break;
		case 1:
		{
			uint16_t * data1 = data0 + 1;
			if(*data0 <= value)
			{
				*data1 = value;
			}
			else
			{
				*data1 = *data0;
				*data0 = value;
			}
			*ptr_index = index + 1;
		} break;
		case 2:
		{
			uint16_t * data1 = data0 + 1;
			uint16_t * data2 = data0 + 2;

			if(*data0 <= value)
			{
				if(*data1 <= value)
				{
					*data2 = value;
				}
				else
				{
					*data2 = *data1;
					*data1 = value;
				}
			}
			else
			{
				*data2 = *data1;
				*data1 = *data0;
				*data0 = value;
			}
			*ptr_index = index + 1;
		} break;
		case 3:
		{
			uint16_t * data1 = data0 + 1;
			uint16_t * data2 = data0 + 2;
			uint16_t * data3 = data0 + 3;

			if(*data0 <= value)
			{
				if(*data1 <= value)
				{
					if(*data2 <= value)
					{
						*data3 = value;
					}
					else
					{
						*data3 = *data2;
						*data2 = value;
					}
				}
				else
				{
					*data3 = *data2;
					*data2 = *data1;
					*data1 = value;
				}
			}
			else
			{
				*data3 = *data2;
				*data2 = *data1;
				*data1 = *data0;
				*data0 = value;
			}
			*ptr_index = index + 1;
		} break;
		case 4:
		{
			uint16_t * data1 = data0 + 1;
			uint16_t * data2 = data0 + 2;
			uint16_t * data3 = data0 + 3;
			uint16_t * data4 = data0 + 4;

			if(*data0 <= value)
			{
				if(*data1 <= value)
				{
					if(*data2 <= value)
					{
						if(*data3 <= value)
						{
							*data4 = value;
						}
						else
						{
							*data4 = *data3;
							*data3 = value;
						}
					}
					else
					{
						*data4 = *data3;
						*data3 = *data2;
						*data2 = value;
					}
				}
				else
				{
					*data4 = *data3;
					*data3 = *data2;
					*data2 = *data1;
					*data1 = value;
				}
			}
			else
			{
				*data4 = *data3;
				*data3 = *data2;
				*data2 = *data1;
				*data1 = *data0;
				*data0 = value;
			}
			*ptr_index = 0;
			median_filter_5_uint16_handler_t calculated =  object->calculated;
			if(NULL != calculated) { calculated(object); }
			object->old_median = *data2;
			overflow = true;

		} break;
	}
	return overflow;
}


/*---------------------------------------------------------------------*
 *  eof
 *---------------------------------------------------------------------*/
