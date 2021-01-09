#ifndef _LU_THREAD_H
#define _LU_THREAD_H
#include <thread>
#include <memory>

namespace lu
{

/**
 *
 */
class LU_Runable
{
public:
    virtual ~LU_Runable(){};
    virtual void run() = 0;
};

/**
 * @brief 线程基类. 
 * 线程基类，所有自定义线程继承于该类，同时实现run接口即可, 
 *  
 */
class LU_Thread : public LU_Runable
{
public:

    LU_Thread();
    virtual ~LU_Thread();
    LU_Thread* start();
    std::shared_ptr<std::thread> getThreadControl();
    bool isAlive() const;
protected:
    static void threadEntry(LU_Thread *pThread);
    virtual void run() = 0;

protected:
    bool is_running_;
	std::shared_ptr<std::thread> thread_;
};

}

#endif
