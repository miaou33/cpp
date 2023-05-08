
## const_cast<type> (expr)
> explicitly override const and/or volatile in a cast (to be set or removed)
> target type must be the same as the source type (except for the alteration of its const or volatile attributes)

## dynamic_cast<type> (expr)
> performs a runtime cast that verifies the validity of the cast
    > if the cast cannot be made, the cast fails and the expression evaluates to null
> a dynamic_cast performs casts on polymorphic types 
    > can cast a A* pointer into a B* pointer (only if the object being pointed to actually is a B object)

## reinterpret_cast<type> (expr)
> changes a pointer to any other type of pointer
> also allows casting from pointer to an integer type and vice versa.

## static_cast<type> (expr)
> performs a nonpolymorphic cast.
> for example, it can be used to cast a base class pointer into a derived class pointer.
> or to cast numeric values
