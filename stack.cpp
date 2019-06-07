#include "stack.h"

// Use this method for all your reallocations:

void stack::ensure_capacity( size_t c )
{
    
    if( current_capacity < c )
        {
        // New capacity will be the greater of c and
        // 2 * current_capacity.
        
        if( c < 2 * current_capacity )
        {
            c = 2 * current_capacity;
        }
        
        double* newdata = new double[ c ];
        
        for( size_t i = 0; i < current_size; ++ i )
        {
            newdata[i] = data[i];
        }
        
        current_capacity = c;
        delete[] data;
        data = newdata;
    }
}

stack::stack():
current_capacity{5},
current_size{0},
data{new double[5]}
{
}

stack::stack(const stack& s)
:current_size{s.current_size},
current_capacity{s.current_capacity}
{
    data = new double[current_capacity];
    
    for(size_t i = 0; i < current_size; ++ i )
    {
        data[i] = s.data[i];
    }
}

stack::~stack()
{
    delete[] data;
}

const stack& stack::operator = (const stack& s)
{
    ensure_capacity(s.size());
    current_size = s.current_size;
    
    for(size_t i = 0; i < current_size; ++i)
    {
        data[i] = s.data[i];
    }
    return s;
}

stack::stack( std::initializer_list<double> init )
:current_size{init.size()},
current_capacity{init.size()}
{
    data = new double[current_capacity];
    size_t i = 0;
    
    for( double z : init )
    {
        data[i] = z;
        i++;
    }
}

void stack::push(double d)
{
    ensure_capacity(current_size+1);
    current_size += 1;
    data[current_size-1] = d;
}

void stack::pop()
{
    if(current_size != 0)
    {
        current_size -= 1;
    }
}

void stack::clear()
{
    current_size = 0;
}

void stack::reset( size_t s )
{
    current_size = s;
}



double stack::peek() const
{
    return data[current_size-1];
}

size_t stack::size() const
{
    return current_size;
}

bool stack::empty() const
{
    if (current_size == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}


std::ostream& operator << ( std::ostream& print, const stack& s )
{
    print << "[ ";
 
    for (size_t i = 0; i != s.current_size; ++ i)
    {
        print << s.data[i] << " ";
    }
    
    print << "]"; // brackets for array elements
    
    return print;
}


