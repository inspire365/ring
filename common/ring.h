#ifndef CAN_COMMON_RING_BASE_H_
#define CAN_COMMON_RING_BASE_H_

namespace can { namespace common { namespace datastructure {

/*! \class Ring
    \brief A Ring template class
 *
 * Class Ring is designed to find and locate the key-value
 * data efficiently, it's suggested to use it cooperated with
 * STL map. In this case, STL map is used to find the key-value
 * firstly, then class Ring is used to locate the value quickly.
 * It's also called the curiously recurring template pattern (CRTP)
 *
 *  !!!!!!!!!!!!!!!! CAUTION !!!!!!!!!!!!!!!!!!
 *  Please use this template cautiously.
 *  Don't do any assignment or copy constructor operation
 *  with this template, for these operations will cause the
 *  internal pointers wrong!
 */
template<typename T>
class Ring
{
public:

  /**
   * Ring template constructor.
   */
  Ring()
  {          // Initialize this node
    this->previous_ = (T*)this;
    this->next_     = (T*)this;
  }

  /**
   * Insert a node to the previous of this node
   * @param node  The node wanted to insert into
   */
  inline void Insert(T* node)
  {
    if(!node)
      return ;
    node->next_ = (T*)this;
    node->previous_ = this->previous_;
    this->previous_->next_ = node;
    this->previous_ = node;
  }

  /**
   * Insert a node to the next of this node
   * @param node  The node wanted to insert into
   */
  inline void Append(T* node)
  {
    if(!node)
      return;
    node->previous_ = (T*)this;
    node->next_ = this->next_;
    this->next_->previous_ = node;
    this->next_ = node;
  }

  /**
   * Remove this node itself from the ring
   * @return true to indicate successful, otherwise failure
   */
  inline bool Remove()
  {
    if( this->next_ == (T*)this ) 
      return false;  // only one element
    this->next_->previous_ = this->previous_;
    this->previous_->next_ = this->next_;
    this->previous_ = (T*)this;
    this->next_ = (T*)this;
    return true;
  }

  /**
   * Get the next node of the current node
   * @return  return the next node of current node
   */
  inline T* next()
  {
    return this->next_;
  }

  /**
   * Get the previousious node of the current node
   * @return  return the previous node of current node
   */
  inline T* previous()
  {
    return this->previous_;
  }

private:

  Ring(const Ring&);
  Ring& operator = (const Ring& rhs);

protected:

  T* previous_;  ///< the previous node of current node
  T* next_;      ///< the next node of the current node

};

}}} // ::can::common::datastructure

#endif // CAN_COMMON_RING_BASE_H_

