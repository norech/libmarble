/*
** EPITECH PROJECT, 2021
** marble by Alexis Cheron
** File description:
** Source code
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <marble/internal/util.h>

const int MRBL_BUFF_SIZE = 20;

int mrbl_handle_fd_buffer(mrbl_buffer_t *buffer)
{

}

void mrbl_read_new_chunk(mrbl_buffer_t *buffer)
{
    int old_size = buffer->stored_blocks * MRBL_BUFF_SIZE;
    mrbl_expand_string(&(buffer->payload), old_size + MRBL_BUFF_SIZE);
    buffer->stored_blocks++;
    buffer->payload_pos = buffer->payload + old_size;
    switch(buffer->type)
    {
        case MRBL_BUFFER_FD:
            mrbl_handle_fd_buffer(buffer);
            break;
    }
}

int mrbl_consume_char(mrbl_buffer_t *buffer)
{
    buffer->payload_pos++;
    if (buffer->payload_pos == '\0')
        mrbl_read_new_chunk(buffer);
    buffer->c = *(buffer->payload_pos);
}

void mrbl_shrink_buffer(mrbl_buffer_t *buffer)
{
    char *buff_payload = malloc(sizeof(char) * (MRBL_BUFF_SIZE + 1));
    int new_start_pos = (buffer->stored_blocks - 1) * MRBL_BUFF_SIZE;

    mrbl_strcpy(buff_payload, buffer->payload + new_start_pos);
    free(buffer->payload);
    buffer->payload = buff_payload;
}

mrbl_buffer_t *mrbl_create_fd_buffer(int fd)
{
    mrbl_buffer_t *buffer = malloc(sizeof(mrbl_buffer_t));
    buffer->type = MRBL_BUFFER_FD;
    buffer->stored_blocks = 0;
    mrbl_consume_char(buffer);
    return (buffer);
}

mrbl_buffer_t *mrbl_create_str_buffer(char *data)
{
    mrbl_buffer_t *buffer = malloc(sizeof(mrbl_buffer_t));
    buffer->type = MRBL_BUFFER_STR;
    mrbl_consume_char(buffer);
    return (buffer);
}