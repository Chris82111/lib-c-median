//! @file
//! @brief The median_filter_5_uint16 source file.


/*---------------------------------------------------------------------*
 *  private: include files
 *---------------------------------------------------------------------*/

#include "median_filter_5_uint16.h"


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

const struct median_filter_5_uint16_sc median_filter_5_uint16 =
{
    median_filter_5_uint16_add,
    median_filter_5_uint16_clear,
    median_filter_5_uint16_init,
};


/*---------------------------------------------------------------------*
 *  private: function prototypes
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  private: functions
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  public:  functions
 *---------------------------------------------------------------------*/

bool median_filter_5_uint16_add(median_filter_5_uint16_t * object, uint16_t value)
{
    uint16_t * data0 = object->data;
    uint8_t index = object->index;

    switch(index)
    {
        case 0:
        {
            *data0 = value;
            object->index = index + 1;
        }
        return false;

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
            object->index = index + 1;
        }
        return false;

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
            object->index = index + 1;
        }
        return false;

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
            object->index = index + 1;
        }
        return false;

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
            if(object->on_calculated) { object->on_calculated(object); }
            object->index = 0;
            object->old_median = *data2;
        }
        return true;

        default:
        return false;
    }
}

void median_filter_5_uint16_clear(median_filter_5_uint16_t * object)
{
    object->old_median = 0;
    object->index = 0;

#if false

    object->data[0] = 0;
    object->data[1] = 0;
    object->data[2] = 0;
    object->data[3] = 0;
    object->data[4] = 0;

#endif

}

void median_filter_5_uint16_init(median_filter_5_uint16_t * object)
{
    object->old_median = 0;
    object->index = 0;
    object->on_calculated = NULL;

    object->data[0] = 0;
    object->data[1] = 0;
    object->data[2] = 0;
    object->data[3] = 0;
    object->data[4] = 0;
}


/*---------------------------------------------------------------------*
 *  eof
 *---------------------------------------------------------------------*/
