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

//! @brief Index of ::median_filter_5_uint16_s::data to read the maximum value
#define MEDIAN_FILTER_5_DATA_INDEX_MAX 4

//! @brief Index of ::median_filter_5_uint16_s::data to read the median value
#define MEDIAN_FILTER_5_DATA_INDEX_MEDIAN 2

//! @brief Index of ::median_filter_5_uint16_s::data to read the minimum value
#define MEDIAN_FILTER_5_DATA_INDEX_MIN 0


/*---------------------------------------------------------------------*
 *  public: typedefs
 *---------------------------------------------------------------------*/

//! @brief State of the median filter object
typedef enum median_filter_5_states_e
{
    MEDIAN_FILER_5_UNINIT = 0,//!< The object is not initialized
    MEDIAN_FILER_5_READY,     //!< State in which the values of the object can be evaluated
    MEDIAN_FILER_5_WORKING_1, //!< The first  value is read in, the object data is not valid
    MEDIAN_FILER_5_WORKING_2, //!< The second value is read in, the object data is not valid
    MEDIAN_FILER_5_WORKING_3, //!< The third  value is read in, the object data is not valid
    MEDIAN_FILER_5_WORKING_4, //!< The fourth value is read in, the object data is not valid
    MEDIAN_FILER_5_WORKING_5, //!< The fifth  value is read in, the object data is not valid

} median_filter_states_t;


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
typedef struct median_filter_5_uint16_s
{
    //! @brief Index of the ::median_filter_5_uint16_s::data array that will be filled next
    median_filter_states_t state;

    //! @brief Function that is called after the last value is stored. The current median
    //!  can be accessed via the array ::median_filter_5_uint16_s::data and index 2.
    median_filter_5_uint16_handler_t on_calculated;

    //! @brief Measured values in ascending order, ::median_filter_5_uint16_s::index shows
    //! which values belong to the current cycle.
    uint16_t data[5];

    //! @brief Optional pointer to user data, `NULL` is allowed
    void * user_data;

}median_filter_5_uint16_t;


//! @brief Represents a simplified form of a class
//!
//! @details The global variable ::median_filter_5_uint16 can be used to easily
//! access all matching functions with auto-completion.
struct median_filter_5_uint16_sc
{
    bool (*Add) (median_filter_5_uint16_t * object, uint16_t value); ///< @see ::median_filter_5_uint16_add()
    void (*Clear) (median_filter_5_uint16_t * object); ///< @see ::median_filter_5_uint16_clear()
    void (*GetData) (const median_filter_5_uint16_t * object, uint16_t * data); ///< @see ::median_filter_5_uint16_get_data()
    void (*Init) (median_filter_5_uint16_t * object); ///< @see ::median_filter_5_uint16_init()
    bool (*IsReady)(const median_filter_5_uint16_t * object); ///< @see ::median_filter_5_uint16_is_ready()
    uint16_t (*Max)(const median_filter_5_uint16_t * object); ///< @see ::median_filter_5_uint16_max()
    uint16_t (*Median)(const median_filter_5_uint16_t * object); ///< @see ::median_filter_5_uint16_median()
    uint16_t (*Min)(const median_filter_5_uint16_t * object); ///< @see ::median_filter_5_uint16_min()
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
//! Corresponds to ::median_filter_5_uint16_init(), but does not reset the handler or the user data
//!
//! @param[in,out] object The median object
void median_filter_5_uint16_clear(median_filter_5_uint16_t * object);

//! @brief Get the median array data
//!
//! @details Use ::median_filter_5_uint16_is_ready() to check whether it is safe to read the data
//!
//! @param[in] object The median object
//! @param[out] data The destination to which the data is copied
void median_filter_5_uint16_get_data(const median_filter_5_uint16_t * object, uint16_t * data);

//! @brief Inits the median filter
//!
//! @param[in,out] object The median object
void median_filter_5_uint16_init(median_filter_5_uint16_t * object);

//! @brief Checks whether the data can be read or is currently being changed
//!
//! @param[in] object The median object
//! @retval true  Data can be read
//! @retval false Data should not be read as the data is currently being updated
bool median_filter_5_uint16_is_ready(const median_filter_5_uint16_t * object);

//! @brief Reads the maximum value
//!
//! @details Use ::median_filter_5_uint16_is_ready() to check whether it is safe to read the data
//!
//! @param[in] object The median object
//! @return The maximum value
uint16_t median_filter_5_uint16_max(const median_filter_5_uint16_t * object);

//! @brief Reads the median value
//!
//! @details Use ::median_filter_5_uint16_is_ready() to check whether it is safe to read the data
//!
//! @param[in] object The median object
//! @return The median value
uint16_t median_filter_5_uint16_median(const median_filter_5_uint16_t * object);

//! @brief Reads the minimum value
//!
//! @details Use ::median_filter_5_uint16_is_ready() to check whether it is safe to read the data
//!
//! @param[in] object The minimum object
//! @return The minimum value
uint16_t median_filter_5_uint16_min(const median_filter_5_uint16_t * object);


/*---------------------------------------------------------------------*
 *  public: static inline functions
 *---------------------------------------------------------------------*/

//! @brief This macro initializes the median filter 5.
//!
#define MEDIAN_FILTER_5_UINT16_INIT()               \
{                                                   \
    /* .state         = */ (MEDIAN_FILER_5_UNINIT), \
    /* .on_calculated = */ (0),                     \
    /* .data          = */ {0,0,0,0,0},             \
    /* .user_data     = */ (NULL),                  \
} // ;


#ifdef __cplusplus
}
#endif

#endif /* INC_MEDIAN_FILTER_5_UINT16_H_ */

/*---------------------------------------------------------------------*
 *  eof
 *---------------------------------------------------------------------*/
