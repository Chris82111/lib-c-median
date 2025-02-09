//! @file

#ifndef INC_MEDIAN_FILTER_5_UINT16_H_
#define INC_MEDIAN_FILTER_5_UINT16_H_

#ifdef __cplusplus
extern "C" {
#endif


/*---------------------------------------------------------------------*
 *  public: include files
 *---------------------------------------------------------------------*/

#include <stdint.h>
#include <stdbool.h>


/*---------------------------------------------------------------------*
 *  public: define
 *---------------------------------------------------------------------*/

//! @brief This macro initializes the median filter 5.
//!
#define MEDIAN_FILTER_5_UINT16_INIT() \
{                                     \
    /* .old_median */ (0),            \
    /* .length     */ (5),            \
    /* .index      */ (0),            \
    /* .calculated */ (0),            \
    /* .data       */ {0,0,0,0,0},    \
}


/*---------------------------------------------------------------------*
 *  public: typedefs
 *---------------------------------------------------------------------*/

//! @brief Prototype of `median_filter_5_uint16_t`, for information see
//!        `median_filter_5_uint16_s`
//!
typedef struct median_filter_5_uint16_s median_filter_5_uint16_t;

//! @brief Function pointer as a handler that is called after the 5th value has
//!        been saved and the median value can be used, see `median_filter_5_uint16_t.calculated`
//! @param[in,out] object The median filter 5 uint16 object
//!
typedef void (*median_filter_5_uint16_handler_t)(median_filter_5_uint16_t * object);

//! @brief The object data of the median filter 5 uint16
//!
typedef struct median_filter_5_uint16_s {

	//! Last median value, is updated after `calculated` was called
	uint16_t old_median;

	//! Number of measured values, size of the `median_filter_5_uint16_t.data` array.
	//! The length is used to store the number of elements.
	uint8_t length;

	//! Index of the `median_filter_5_uint16_t.data` array that will be filled next.
	uint8_t index;

	//! Function that is called after the last value is stored
	median_filter_5_uint16_handler_t calculated;

	//! Measured values in ascending order, `median_filter_5_uint16_t.index` shows
	//! which values belong to the current cycle.
	uint16_t data[5];

}median_filter_5_uint16_t;


/*---------------------------------------------------------------------*
 *  public: extern variables
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  public: function prototypes
 *---------------------------------------------------------------------*/

void median_filter_5_uint16_clear(median_filter_5_uint16_t * object);
bool median_filter_5_uint16_add(median_filter_5_uint16_t * object, uint16_t value);


/*---------------------------------------------------------------------*
 *  public: static inline functions
 *---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*
 *  eof
 *---------------------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* INC_MEDIAN_FILTER_5_UINT16_H_ */
