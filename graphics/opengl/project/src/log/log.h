/*************************************************************************
    > File Name: log.h
    > Author: pjg
    > Mail: 
    > Created Time: 2023/5/12 17:41:56
 ************************************************************************/

#ifndef __LOG_H__
#define __LOG_H__


static const int MAX_LOG_LENGTH = 16*1024;

/**
 @brief Output Debug message.
 */
void log(const char * format, ...);


#endif /*__LOG_H__*/
