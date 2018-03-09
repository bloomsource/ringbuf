#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ringbuf.h"

#define RING_BUF_LEN 10
void print_ring_buf( void* buf )
{
    ring_buffer_head* head;
    char* data;
    
    data = buf + sizeof(ring_buffer_head );
    
    head = (ring_buffer_head*) buf;
    
    printf( "bufsize:%d , startpos:%d, datalen:%d\n", head->bufsize, head->startpos, head->datalen );
    
    
    
}

int main( int argc, char* argv[] )
{
    void* rb;
    int rc;
    char tmp[RING_BUF_LEN+1];
    int size;
    
    rb = malloc( RING_BUF_LEN + sizeof(ring_buffer_head) );
    
    rc = ring_buffer_init( rb, RING_BUF_LEN );
    
    size = RING_BUF_LEN;
    rc = ring_buffer_read( rb, tmp, &size );
    if( rc )
    {
        printf( "read failed, rc:%d\n", rc );
    }
    print_ring_buf( rb );
    
    size = 3;
    rc = ring_buffer_write( rb, "111", 3 );
    if( rc )
    {
        printf( "write failed, rc:%d\n", rc );
    }
    print_ring_buf( rb );
    
    size = 3;
    rc = ring_buffer_write( rb, "222", 3 );
    if( rc )
    {
        printf( "write failed, rc:%d\n", rc );
    }
    print_ring_buf( rb );
        


        
    size = 3;
    rc = ring_buffer_write( rb, "333", 3 );
    if( rc )
    {
        printf( "write failed, rc:%d\n", rc );
    }
    print_ring_buf( rb );
    
    
    memset( tmp, 0, sizeof(tmp) );
    size = RING_BUF_LEN;
    rc = ring_buffer_read( rb, tmp, &size );
    if( rc )
    {
        printf( "read failed, rc:%d\n", rc );
    }
    else
    {
        printf( "ring buffer read:%s\n", tmp );
        
    }
    print_ring_buf( rb );


    size = 3;
    rc = ring_buffer_write( rb, "444", 3 );
    if( rc )
    {
        printf( "write failed, rc:%d\n", rc );
    }
    print_ring_buf( rb );
    
    
    memset( tmp, 0, sizeof(tmp) );
    size = RING_BUF_LEN;
    rc = ring_buffer_read( rb, tmp, &size );
    if( rc )
    {
        printf( "read failed, rc:%d\n", rc );
    }
    else
    {
        printf( "ring buffer read:%s\n", tmp );
        
    }
    print_ring_buf( rb );
        
    
}

