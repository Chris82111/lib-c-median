//! @file
//! @brief The median_filter_5_uint16 header file.
//!
//! @details The module can be used in C and C++.


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
#define MEDIAN_FILTER_5_UINT16_INIT()   \
{                                       \
    /* .old_median    = */ (0),         \
    /* .index         = */ (0),         \
    /* .on_calculated = */ (0),         \
    /* .data          = */ {0,0,0,0,0}, \
} // ;


/*---------------------------------------------------------------------*
 *  public: typedefs
 *---------------------------------------------------------------------*/

//! @brief Forward declaration
struct median_filter_5_uint16_s;

//! @brief Forward typedef, for information see ::median_filter_5_uint16_s
typedef struct median_filter_5_uint16_s median_filter_5_uint16_t;

//! @brief Function pointer as a handler that is called after the 5th value has
//! been saved and the median value can be used, see ::median_filter_5_uint16_s::on_calculated
//!
//! @param[in,out] object The median filter 5 uint16 object
typedef void (*median_filter_5_uint16_handler_t)(median_filter_5_uint16_t * object);

//! @brief The object data of the median filter with 5 values of type `uint16_t`
typedef struct median_filter_5_uint16_s {

    //! @brief Last median value, is updated after ::median_filter_5_uint16_s::on_calculated was called
    uint16_t old_median;

    //! Index of the ::median_filter_5_uint16_s::data array that will be filled next
    uint8_t index;

    //! Function that is called after the last value is stored.
    //! In the call-back, the previous median value can be accessed via ::median_filter_5_uint16_s::old_median.
    //! The current median can be accessed via the array ::median_filter_5_uint16_s::data and index 2.
    median_filter_5_uint16_handler_t on_calculated;

    //! Measured values in ascending order, ::median_filter_5_uint16_s::index shows
    //! which values belong to the current cycle.
    uint16_t data[5];

}median_filter_5_uint16_t;


//! @brief Represents a simplified form of a class
//!
//! @details The global variable ::median_filter_5_uint16 can be used to easily
//! access all matching functions with auto-completion.
struct median_filter_5_uint16_sc
{
    bool (*Add) (median_filter_5_uint16_t * object, uint16_t value);
    void (*Clear) (median_filter_5_uint16_t * object);
    void (*Init) (median_filter_5_uint16_t * object);
};


/*---------------------------------------------------------------------*
 *  public: extern variables
 *---------------------------------------------------------------------*/

//! @brief To access all member functions working with type ::median_filter_5_uint16_s
//!
//! @details Allows a simplified class to easily access all member functions
//! working with type ::median_filter_5_uint16_s. The auto-completion function helps you
//! to select all suitable functions via ::median_filter_5_uint16_sc struct.
extern const struct median_filter_5_uint16_sc median_filter_5_uint16;


/*---------------------------------------------------------------------*
 *  public: function prototypes
 *---------------------------------------------------------------------*/

//! @brief Adds a new element to the median filter
//!
//! @param[in,out] object The median object
//! @param value
//! @retval true  if all elements have been read
//! @retval false if elements must be read
bool median_filter_5_uint16_add(median_filter_5_uint16_t * object, uint16_t value);

//! @brief Clears the median filter
//!
//! Corresponds to ::median_filter_5_uint16_init(), but does not reset the handler
//!
//! @param[in,out] object The median object
void median_filter_5_uint16_clear(median_filter_5_uint16_t * object);

//! @brief Inits the median filter
//!
//! @param[in,out] object The median object
void median_filter_5_uint16_init(median_filter_5_uint16_t * object);


/*---------------------------------------------------------------------*
 *  public: static inline functions
 *---------------------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif /* INC_MEDIAN_FILTER_5_UINT16_H_ */

/*---------------------------------------------------------------------*
 *  eof
 *---------------------------------------------------------------------*/
