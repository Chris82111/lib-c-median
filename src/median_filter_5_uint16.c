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
    median_filter_5_uint16_get_data,
    median_filter_5_uint16_init,
    median_filter_5_uint16_is_ready,
    median_filter_5_uint16_max,
    median_filter_5_uint16_median,
    median_filter_5_uint16_min,
    median_filter_5_uint16_set_data,
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

    switch(object->state)
    {
        case MEDIAN_FILER_5_UNINIT:
        case MEDIAN_FILER_5_READY:
        {
            object->state = MEDIAN_FILER_5_WORKING_1;

            *data0 = value;

            object->state = MEDIAN_FILER_5_WORKING_2;
        }
        return false;

        case MEDIAN_FILER_5_WORKING_2:
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

            object->state = MEDIAN_FILER_5_WORKING_3;
        }
        return false;

        case MEDIAN_FILER_5_WORKING_3:
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

            object->state = MEDIAN_FILER_5_WORKING_4;
        }
        return false;

        case MEDIAN_FILER_5_WORKING_4:
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

            object->state = MEDIAN_FILER_5_WORKING_5;
        }
        return false;

        case MEDIAN_FILER_5_WORKING_5:
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

            object->state = MEDIAN_FILER_5_READY;

            if(object->on_calculated) { object->on_calculated(object); }
        }
        return true;

        default:
        return false;
    }
}

void median_filter_5_uint16_clear(median_filter_5_uint16_t * object)
{
    object->state = MEDIAN_FILER_5_UNINIT;

#if false

    object->data[0] = 0;
    object->data[1] = 0;
    object->data[2] = 0;
    object->data[3] = 0;
    object->data[4] = 0;

#endif

}

void median_filter_5_uint16_get_data(const median_filter_5_uint16_t * object, uint16_t * data)
{
    data[0] = object->data[0];
    data[1] = object->data[1];
    data[2] = object->data[2];
    data[3] = object->data[3];
    data[4] = object->data[4];
}

void median_filter_5_uint16_init(median_filter_5_uint16_t * object)
{
    object->state = MEDIAN_FILER_5_UNINIT;
    object->on_calculated = NULL;
    object->user_data = NULL;

    object->data[0] = 0;
    object->data[1] = 0;
    object->data[2] = 0;
    object->data[3] = 0;
    object->data[4] = 0;
}

bool median_filter_5_uint16_is_ready(const median_filter_5_uint16_t * object)
{
    return (MEDIAN_FILER_5_READY == object->state);
}

uint16_t median_filter_5_uint16_max(const median_filter_5_uint16_t * object)
{
    return object->data[MEDIAN_FILTER_5_DATA_INDEX_MAX];
}

uint16_t median_filter_5_uint16_median(const median_filter_5_uint16_t * object)
{
    return object->data[MEDIAN_FILTER_5_DATA_INDEX_MEDIAN];
}

uint16_t median_filter_5_uint16_min(const median_filter_5_uint16_t * object)
{
    return object->data[MEDIAN_FILTER_5_DATA_INDEX_MIN];
}

bool median_filter_5_uint16_set_data(median_filter_5_uint16_t * object, uint16_t * data)
{
    median_filter_5_uint16_add(object, data[0]);
    median_filter_5_uint16_add(object, data[1]);
    median_filter_5_uint16_add(object, data[2]);
    median_filter_5_uint16_add(object, data[3]);
    median_filter_5_uint16_add(object, data[4]);
    return true;
}

/*---------------------------------------------------------------------*
 *  eof
 *---------------------------------------------------------------------*/
